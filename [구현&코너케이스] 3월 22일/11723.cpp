#include <iostream>
#include <vector>

using namespace std;

void add(vector<int> s) {
    int x;
    cin >> x;
    if (s[x] != 0) {
        s[x] = 1;
    }
}

void remove(vector<int> s) {
    int x;
    cin >> x;
    if (s[x] == 1) {
        s[x] = 0;
    }
}

void check(vector<int> s) {
    int x;
    cin >> x;
    if (s[x] != 0) {
        cout << 1 << '\n';
    } else{
        cout << 0 << '\n';
    }
}

void toggle(vector<int> s) {
    int x;
    cin >> x;
    if (s[x] != 0) {
        s[x] = 0;
    } else {
        s[x] = 1;
    }
}

void all(vector<int> s) {
    for (int i = 0; i < 20; i++){
        s[i] = 1;
    }
}

void empty(vector<int> s) {
    for (int i = 0; i < 20; i++){
        s[i] = 0;
    }
}

int main() {
    int m;
    string input;
    cin >> m;
    vector<int> s(20, 0);
    while (m--) {
        cin >> input;
        if (input == "add")
                add(s);
        if (input == "remove")
                remove(s);
        if (input == "check")
                check(s);
        if(input == "toggle")
                toggle(s);
        if(input == "all")
                all(s);
        if(input == "empty")
                empty(s);
    }
    return 0;
}