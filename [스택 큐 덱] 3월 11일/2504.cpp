// 스택 활용 연습하기

#include <iostream> //입출력
#include <vector> //배열 사용
#include <stack> // stack 사용
#include <map> //map 사용

using namespace std; //자주 사용하는 이름공간 선언

int calc(string s) { //계산 함수 선언
    stack<char> st; //문자 스택 선언
    map<char, int> num; //괄호 값
    map<char, char> bracket; //괄호 쌍

    //괄호 쌍과 값 저장
    bracket[')'] = '(';
    bracket[']'] = '[';
    num['('] = 2;
    num['['] = 3;

    int ans = 0, temp = 1; //
    for (int i = 0; i < s.length(); i++) { //문자열 길이만큼 반복
        switch (s[i]) {
            case '(': case '[': //여는 괄호일 경우
                st.push(s[i]); //스택에 괄호 넣기
                temp *= num[s[i]]; //temp에 괄호의 값 곱하기
                break;
            case ')': case ']': //닫는 괄호일 경우
                if (st.empty() || st.top() != bracket[s[i]]) { //스택이 비었거나 괄호 짝이 맞지 않으면
                    return 0; // 0 리턴
                }
                if (s[i - 1] == bracket[s[i]]) { //괄호의 짝이 맞으면
                    ans += temp; //temp의 값을 더함
                }
                temp /= num[bracket[s[i]]]; //이미 값을 더한 경우이므로 나누기
                st.pop(); //스택 제일 위에 값 제거
                break;
        }
    }
    if (st.empty()) { //올바른 괄호라면
        return ans; //결과값 리턴
    }
    return 0;
}

/**
 * "분배법칙"을 활용!
 * ex. ([]([])): 2 x (3 + 2 x 3) == 2 x 3 + 2 x 2 x 3
 * =>                               (   [ ]     (   [   ]   )   )
 * =>                   임시변수값:  2   6 2     4  12   4   2   1
 * =>                        정답:        +6           +12        = 18
 *
 * 따라서, 우선 여는 괄호가 나오면 괄호의 값을 곱해줌
 * 닫는 괄호는, 이전 문자가 여는 괄호일 경우 지금까지 곱한 값을 더해줌 (값이 중복으로 더해지는 것을 방지하기 위해 이전 문자가 여는 괄호인지 꼭 체크!)
 *            한 괄호에 대한 연산이 끝났으므로 (곱하기 연산) 다시 괄호 값을 나눠줘서 연산 진행
 */

int main() {
    string s; //문자열 선언

    //입력
    cin >> s;
    //연산 & 출력
    cout << calc(s);
    return 0;
} 