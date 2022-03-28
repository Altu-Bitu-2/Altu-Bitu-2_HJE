//stack 선언과 사용,map switch 사용, getline 함수

#include <iostream>
#include <stack>
#include <map>

using namespace std;

bool isBalanced(string &s){
    stack<char> st;
    map<char, char> m;
    m[']'] = '[';
    m[')'] = '(';
    for (int i = 0; i < s.length(); i++){
        switch (s[i]){
            case '(': case '[' :
                st.push(s[i]);
                break;
            case ')' : case ']' :
                if (st.empty() || st.top() != m[s[i]]){
                    return false;
                }
                st.pop();
                break;
        }
    }
    return st.empty();
}

int main(){
    string s;
    while(getline(cin, s){
        if (s == "."){
            break;
        }
        if(isBalanced(s)){
            cout << "yes\n";
        } else {
            cout << "no\n";
        }
    }
    return 0;
}