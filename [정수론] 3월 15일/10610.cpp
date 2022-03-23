#include <iostream> //입출력을 위한 헤더파일
#include <algorithm> // sort 함수 사용을 위한 헤더파일

using namespace std; // 자주 사용하는 네임스페이스 미리 선언

string findNumber(string s) {
    bool isTen = false; //0이 존재하는지 확인
    int sum = 0; //3의 배수인지 확인하기 위해 수 더함

    //돌면서 3의 배수와 10의 배수인지 확인
    for (int i = 0; i < s.length(); i++) {
        sum += (s[i] - '0'); //3의 배수인지 확인하기 위해 수를 더하는 과정
        if (s[i] == '0') { // 0이 존재하는지 확인 (10의 배수를 구하기 위해)
            isTen = true;
        }
    }

    if (sum % 3 != 0 || !isTen) { //3의 배수가 아니거나, 10의 배수가 아니라면
        return "-1";
    }

    //가장 큰 수 만들기 위해 내림차순 정렬
    sort(s.begin(), s.end(), greater<>());
    return s;
}

/**
 * [30]
 * 30의 배수 = 10의 배수 && 3의 배수
 * 1. 10의 배수 -> 입력된 수에 0이 포함되어 있는지 확인
 * 2. 3의 배수 -> 모든 자리수의 합이 3의 배수인지 확인
 *
 * 30의 배수임이 확인 되었으면,
 * 가장 큰 수를 만들기 위해 9부터 0까지 역순으로 나열한다.
 */

int main() {
    string s; //문자열 선언

    //입력
    cin >> s;

    //연산 & 출력
    cout << findNumber(s);
    return 0;
}