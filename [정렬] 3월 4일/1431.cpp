//str.size(), isdigit, 비교함수 만드는 법, 문자열을 정수로 만드는 법 복습하기

#include <iostream> //입출력을 위한 헤더 파일
#include <vector> // 배열 사용을 위한 헤더 파일
#include <algorithm> //sort 함수 사용을 위한 헤더파일

using namespace std; // 효율을 위한 namespace std 미리 선언해주기

//문자열의 모든 자릿수 합을 구하는 함수
int sumNum(string str) { //숫자 합 구하는 함수 선언
    int sum = 0; // return 값 초기화
    for (int i = 0; i < str.size(); i++) { //시리얼 넘버의 길이만큼 반복
        if (isdigit(str[i])) { //문자(char)에 대해 숫자인지 판별하는 함수
            sum += str[i] - '0'; //char -> int로 바꾸는 방법 (아스키 코드에 대해 알아보세요), 숫자만 합산
        }
    }
    return sum; //sum 값 return
}

//비교함수
bool cmp(const string &s1, const string &s2) { //비교 함수 선언
    if (s1.size() != s2.size()) { //두 문자열의 길이가 다르다면 짧은 문자열이 먼저 오도록
        return s1.size() < s2.size(); // s1 의 길이가 길 경우 false 값이 return 되어 순서 바뀜
    }
    if (sumNum(s1) != sumNum(s2)) { //두 문자열의 숫자 합이 다르다면 합이 작은 문자열이 먼저 오도록
        return sumNum(s1) < sumNum(s2); // s1 의 합이 클 경우 false 값이 return 되어 순서 바뀜
    }
    return s1 < s2; //사전순
}

int main() {
    int n; //시리얼 넘버 개수 선언
    vector <string> serial_num; //시리얼 넘버를 받을 배열 선언

    //입력
    cin >> n; //시리얼 넘버 개수 입력
    serial_num.assign(n, ""); //시리얼 넘버 개수만큼 할당
    for (int i = 0; i < n; i++) { //시리얼 넘버 개수만큼 반복
        cin >> serial_num[i]; //배열에 시리얼 넘버 입력
    }

    //연산
    sort(serial_num.begin(), serial_num.end(), cmp); //비교함수 따라 조건에 맞추어 정렬

    //출력
    for (int i = 0; i < n; i++) {
        cout << serial_num[i] << '\n'; // 정렬된 배열 출력
    }
    return 0;
}