//문자열 사용에 익숙해지도록 연습할 것, bool 자료형 사용에 익숙해지기

#include <iostream> //입출력을 위한 헤더파일
#include <vector> // 배열 사용을 위한 헤더파일

using namespace std; // 자주 사용하는 네임스페이스 미리 선언

bool isGroup(string str) { //그룹 문자 판별 함수
    char cur = NULL; //현재의 문자
    vector<bool> alphabet(26, false); //각 알파벳의 등장 여부를 체크

    for (int i = 0; i < str.size(); i++) { //문자열 크기 만큼
        if (str[i] == cur) { //연속해서 나타난 문자
            continue; //반복 후 모두 continue 일 때 true 리턴
        }
        //이전의 문자와 다른 문자가 나타났을 때
        if (alphabet[str[i] - 'a']) { //이전에 등장했던 문자면 떨어져서 나타난 것
            return false; //문자열이 떨어져서 나타나면 false 리턴
        }
        cur = str[i]; //현재 문자 입력
        alphabet[str[i] - 'a'] = true; //알파벳을 숫자로 변환 후 bool 자료형 이용해서 존재 확인
    }
    return true; //그룹 문자일 경우 true 리턴
}

/**
 * [그룹 단어 체커] - 단순 구현 문제
 * - 이미 등장한 알파벳을 배열의 인덱스(알파벳)를 활용해서 정보 true/false로 저장
 * - set으로 체크할 수도 있겠지만 검색, 삽입 시마다 O(logN)의 시간복잡도가 걸리므로 인덱스 접근이 가능한 배열이 효율적
 * - 처음 등장하는 알파벳은 배열 정보 업데이트 하고, 무리에서 떨어졌는데 이미 등장한 알파벳이면 그룹 단어가 아니다.
 */

int main() {
    int n, result = 0; // 개수와 결과값 초기화

    //입력
    cin >> n;
    while (n--) { // 개수만큼 반복
        string word; //단어 초기화
        cin >> word; //단어 입력

        //연산
        if (isGroup(word)) { //그룹 단어인지 확인
            result++; //그룹 단어일 경우 result 값 증가
        }
    }

    //출력
    cout << result;
    return 0;
}