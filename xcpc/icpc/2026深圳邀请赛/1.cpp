#include <iostream>
#include <string>
#include <vector>
#include <cctype>

using namespace std;

int num = 0, cnum = 0, snum = 0, fnum = 0;

bool check(const string& str) {
    if (str.empty() || !isalpha(str[0])) return false;
    for (int i = 1; i < str.length(); ++i) {
        if (!isalnum(str[i]) && str[i] != '_') return false;
    }
    return true;
}

void parseDeclaration(const string& decl) {
    size_t pos = decl.find('=');
    if (pos == string::npos) return;
    
    string name = decl.substr(0, pos);
    string value = decl.substr(pos + 1);
    
    if (!check(name)) {
        cout << name << "(Wrong! It is not a identifier!)" << endl;
        return;
    }

    if (value.front() == '\'' && value.back() == '\'') {
        if (value.length() == 3) {
            cout << name << "(char, " << value << ")" << endl;
            cnum++;
        } else {
            cout << name << "(Wrong! There are more than one char in ''.)" << endl;
        }
        return;
    }

    if (value.front() == '\"' && value.back() == '\"') {
        cout << name << "(string, " << value << ")" << endl;
        snum++;
        return;
    }

    bool iF = false;
    bool iV = true;
    int idx = 0;
    
    if (value[0] == '+' || value[0] == '-') idx = 1;
    
    if (value.length() > idx + 1 && value[idx] == '0' && value[idx+1] != '.') {
        cout << name << "(Wrong! The integer can't be started with '0'.)" << endl;
        return;
    }

    for (int i = idx; i < value.length(); ++i) {
        if (value[i] == '.') {
            if (iF) iV = false;
            iF = true;
        } else if (!isdigit(value[i])) {
            iV = false;
        }
    }

    if (iV) {
        if (iF) {
            cout << name << "(float, " << value << ")" << endl;
            fnum++;
        } else {
            cout << name << "(integer, " << value << ")" << endl;
            num++;
        }
    } else {
        cout << name << "(Wrong! Unknown value format!)" << endl;
    }
}