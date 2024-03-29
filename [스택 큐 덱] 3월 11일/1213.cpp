// 팰린드롬 만드는 방법 복습(고민해보기)해서 함수 다시 구현해보기, 문자를 인덱스로 바꾸는 것 연습


#include <iostream> //입출력을 위한 헤더파일
#include <vector> // 배열 사용을 위한 헤더파일
#include <algorithm> // 알고리즘 헤더파일

using namespace std; //자주 사용하는 namespace 미리 선언

const int SIZE = 26;    // 알파벳의 수

vector<int> countAlphabet(string text) {
    // text에 있는 각 알파벳의 개수를 세어 리턴하는 함수
    vector<int> count(SIZE, 0); // A-Z까지 문자의 개수를 저장할 리스트
    for (int i = 0; i < text.size(); i++) {
        // 각 문자를 인덱스로 바꿔주기 위해 'A'의 인덱스를 빼줌
        count[text[i] - 'A']++;
    }
    return count; //문자의 개수를 저장한 배열 반환
}

string makePalindrome(vector<int> &count) {
    // 팰린드롬을 만들어 리턴하는 함수.
    string part1 = "", part2 = "", part3 = ""; //문자열 p1 p2 p3 초기화 선언

    for (int i = 0; i < SIZE; i++) { //알파벳(배열의 크기만큼) 반복
        // 만약 알파벳의 수가 홀수라면
        if (count[i] % 2 == 1) {
            // 이미 가운데 글자가 찼다면 더 이상 불가능
            if (part2.size() == 1) { //즉 알파벳 개수가 홀수인 게 2개 이상이면 불가능
                return "I'm Sorry Hansoo"; // 팰린드롬 불가능 할 때 값 리턴
            }
            // 가운데 글자가 비어있다면 할당
            part2 = (char) (i + 'A'); //알파벳으로 바뀜
        }
        // 남은 수의 절반을 나누어 part1과 part3에 이어 붙인다
        for (int j = 0; j < count[i] / 2; j++) {  //남은 수의 절반까지 반복
            part1 += (char) (i + 'A'); //part1 에 알파벳을 추가하는 과정
            part3 = (char) (i + 'A') + part3; // part1과 대칭으로 알파벳 추가
        }
    }

    return part1 + part2 + part3; //팰린드롬 리턴
}

/*
 * [팰린드롬 만들기] - 단순 구현 문제
 * 팰린드롬 문자열은 part1(part3의 대칭) + part2(최대 1글자) + part3(part1의 대칭)으로 이루어진다.
 * 1. 팰린드롬 문자열을 만들기 위해, 각 알파벳이 몇 개씩 존재하는지 벡터에 저장한다.
 * 2. 사전순으로 앞선 팰린드롬 수를 만들어야 하므로, 'A'부터 시작해서 part1과 part3를 문자의 개수에 맞춰 더해나간다.
 * 3. 만약 알파벳의 개수가 홀수인 경우, part2에 할당하고, 이미 part2에 문자가 있는 경우엔 팰린드롬을 만들 수 없다.
 */


int main() {
    // 입력
    string input; // 문자열 선언
    cin >> input; // 문자열 입력

    // 연산 + 출력
    vector<int> count = countAlphabet(input); // 알파벳 배열 리턴
    cout << makePalindrome(count); //팰린드롬 출력

    return 0;
}