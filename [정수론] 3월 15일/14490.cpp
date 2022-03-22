// stoi 함수 복습하기, 유클리드 호제법 통해 재귀 함수 이해하기

#include <iostream> //입출력을 위한 헤더파일

using namespace std; // 자주 사용하는 네임스페이스 미리 선언

// 유클리드 호제법
int gcdRecursion(int a, int b) {
    // a > b 일 때, a와 b의 최대공약수를 리턴
    if (b == 0) {
        return a; //b가 0일 때 a 리턴
    }
    return gcdRecursion(b, a % b); //재귀함수로 최대 공약수를 리턴할 때까지 반복
}

int main() {
    string s; //문자열 선언

    //입력
    cin >> s;

    //연산(입력으로부터 n, m 추출하기)
    int index = s.find(':'); //':' 위치 찾기
    int n = stoi(s.substr(0, index)); //: 이전의 문자를 숫자로 변경
    int m = stoi(s.substr(index + 1, s.length())); //: 이후 문자를 숫자로 변경

    //최대공약수 구하기
    int g = gcdRecursion(max(n, m), min(n, m));

    //출력
    cout << n / g << ':' << m / g << '\n';

    return 0;
}