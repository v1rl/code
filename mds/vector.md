多维度vector值清空

**每次循环的维度大小不一致，但你想保留所有层级的内存容量** 你需要保留内层的 `capacity`，应该**从内向外**清理，或者仅调整 `size`：

```cpp
// 仅重置最内层的 size，保留所有维度的 capacity 不被释放
for (auto& mat : vec3d) {
    for (auto& row : mat) {
        row.clear(); // 清空内层数据，但保留内层 capacity
    }
    mat.clear(); // 清空中层数据，保留中层 capacity
}
vec3d.clear(); // 最后清空外层
```



## 多维度vector动态扩容

针对多维 `vector`（例如三维 `vector<vector<vector<int>>>`），对最外层进行扩充，本质上就是**往最外层追加一个“次外层”类型的元素**。例如，三维 `vector` 的最外层元素是一个二维 `vector`。

根据你的具体应用场景（是动态按需生长，还是已知大小），有以下几种最高效的扩充方式：

------

### 方法一：直接 `emplace_back()` 插入空层（最简写法）

如果你只是想先在外层开辟一个新的槽位，后续再往里面填入具体数据，可以直接插入一个空的次级容器。推荐使用 `emplace_back`，它比 `push_back` 减少了一次临时对象的拷贝/移动构造。

C++

```
#include <vector>

int main() {
    // 定义一个三维 vector
    std::vector<std::vector<std::vector<int>>> vec3d;

    // 往最外层扩充一个空的二维 vector
    vec3d.emplace_back(); 

    // 此时 vec3d.size() 变为 1
    // 你可以继续对刚刚新加的这层进行操作：
    vec3d.back().emplace_back(); // 往刚加的二维层里加一个一维层
    vec3d.back().back().push_back(42); // 往一维层里加具体数据
}
```

------

### 方法二：组装好内层后 `push_back` + `std::move`（推荐，性能最佳）

结合我们之前讨论的内存开销问题，如果你**已经知道新加的这一层应该有多大**（比如固定大小的网格面），强烈建议先在局部构建好带有 `大小(size)` 或 `容量(capacity)` 的次层，然后通过**移动语义**推入最外层。这样可以最大程度减少后续的内存重分配。

C++

```
#include <vector>

int main() {
    int rows = 10;
    int cols = 20;
    std::vector<std::vector<std::vector<int>>> vec3d;

    // 1. 先构建好一个完全初始化好的二维层 (rows x cols，初始值为 0)
    std::vector<std::vector<int>> new_matrix(rows, std::vector<int>(cols, 0));

    // 2. 使用 std::move 将其“搬移”到最外层
    // 注意：move 之后，new_matrix 的内存所有权转移给了 vec3d，自身变为空
    vec3d.push_back(std::move(new_matrix)); 
}
```

**💡 性能优势**：这种做法只需分配一次完整的二维内存块，然后仅转移指针，开销极低。

------

### 方法三：使用 `resize()` 批量扩充最外层

如果你不是加一个，而是想**一次性在最外层增加多个**结构，千万不要用循环 `push_back`，直接用 `resize()`。

C++

```
std::vector<std::vector<std::vector<int>>> vec3d;

// 假设原来外层 size 是 5，现在想扩充到 10
// 新增加的 5 个元素会自动默认构造为“空的二维 vector”
vec3d.resize(10); 

// 如果你想让新扩充的层自带初始维度，可以传入第二个参数（默认范本）
int rows = 5, cols = 5;
std::vector<std::vector<int>> default_mat(rows, std::vector<int>(cols, 0));

// 假设原来外层是 0，一次性扩充 3 个长宽为 5x5 的全零矩阵
vec3d.resize(3, default_mat); 
```

------

### ⚠️ 高维扩充的核心避坑指南

1. **提前 `reserve()` 外层容量**：如果你知道最外层大概会 `push_back` 多少次，一定要先调用 `vec3d.reserve(N);`。因为外层一旦触发扩容（重新分配内存），它会带着里面所有的二维、一维数据一起做大搬家，开销极其恐怖。
2. **警惕拷贝开销**：当往最外层 `push_back` 一个现成的多维变量时，务必加上 `std::move()`（如方法二所示），否则会触发深拷贝，把成千上万个内层整型全部复制一遍。