#include<bits/stdc++.h>
using namespace std;

struct Production {
    char left;
    string right;
};

vector<Production> rules = {
    {'S', "AT"},   // 0
    {'A', "BU"},   // 1
    {'T', "+AT"},  // 2
    {'T', "$"},    // 3
    {'U', "*BU"},  // 4
    {'U', "$"},    // 5
    {'B', "(S)"},  // 6
    {'B', "m"}     // 7
};

int M[128][128];

void initParsingTable() {
    for (int i = 0; i < 128; ++i)
        for (int j = 0; j < 128; ++j)
            M[i][j] = -1;

    M['S']['m'] = 0; M['S']['('] = 0;
    M['A']['m'] = 1; M['A']['('] = 1;
    M['T']['+'] = 2; M['T'][')'] = 3; M['T']['#'] = 3;
    M['U']['+'] = 5; M['U']['*'] = 4; M['U'][')'] = 5; M['U']['#'] = 5;
    M['B']['m'] = 7; M['B']['('] = 6;
}

string getStackString(stack<char> s) {
    string str = "";
    vector<char> temp;
    while (!s.empty()) {
        temp.push_back(s.top());
        s.pop();
    }
    for (int i = temp.size() - 1; i >= 0; --i)
        str += temp[i];
    return str;
}

void parse(string input) {
    stack<char> stk;
    stk.push('#');
    stk.push('S');
    int ip = 0;
    int step = 1;  

    cout << left << setw(6) << "步骤" 
         << setw(15) << "分析栈" 
         << right << setw(15) << "剩余输入串" 
         << "   " << left << "所用产生式/动作" << endl;
    cout << string(60, '-') << endl;

    while (true) {
        char X = stk.top();
        char a = input[ip];

        string stackStr = getStackString(stk);
        string inputStr = input.substr(ip);

        cout << left << setw(6) << step++ 
             << setw(15) << stackStr 
             << right << setw(15) << inputStr << "   ";

        if (X == '#' && a == '#') {
            cout << "接受 (分析成功)" << endl;
            break;
        }

        if (X == '+' || X == '*' || X == '(' || X == ')' || X == 'm' || X == '#') {
            if (X == a) {
                cout << "匹配终结符 '" << a << "'" << endl;
                stk.pop();
                ip++; 
            } else {
                cout << "语法错误：栈顶符号 '" << X << "' 与当前输入 '" << a << "' 不匹配" << endl;
                break;
            }
        } else {
            int ruleIdx = M[X][a];
            if (ruleIdx != -1) {
                Production p = rules[ruleIdx];
                cout << p.left << "->" << p.right << endl;
                stk.pop(); 

                if (p.right != "$") {
                    for (int i = p.right.length() - 1; i >= 0; --i) {
                        stk.push(p.right[i]);
                    }
                }
            } else {
                cout << "语法错误：M[" << X << "][" << a << "] 为空，该位置无备选产生式" << endl;
                break;
            }
        }
    }
}

int main() {
    initParsingTable();
    string input = "m+m*m#";
    cout << "待分析输入串: " << input << "\n\n";
    parse(input);
    return 0;
}