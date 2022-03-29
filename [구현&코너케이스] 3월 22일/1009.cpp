//2차원 벡터 공부하기

#include <iostream> //입출력을 위한 헤더파일
#include <vector> // 배열 사용을 위한 헤더파일

using namespace std; //자주 사용하는 네임스페이스 미리 선언

vector<int> findPattern(int num) { //패턴 저장된 배열 반환하는 함수 선언
    vector<int> pattern = {num}; //배열 초기화

    int temp = num; //임시 저장소에 num 저장
    while (num != (temp * num) % 10) { //같은 패턴이 나오기 전까지 반복
        temp *= num; //패턴 구하기 위한 계산
        temp %= 10; //일의 자리 저장
        pattern.push_back(temp); //벡터의 마지막에 요소 추가
    }
    return pattern; //배열 반환
}

/**
 * [분산처리]
 *
 * - a^b의 일의 자리를 구하는 문제
 * - 일의 자리는 0 ~ 9 중 하나 이므로, 어떤 수를 계속 곱해 나가면 일의 자리는 패턴을 가지게 되어 있음
 *     ex) 2 -> 4 -> 8 -> 6 -> 2 ...
 * - 0 ~ 9까지 일의 자리 패턴을 미리 구한 후, a의 일의 자리에 대한 (b - 1 % 패턴의 길이)번째 수를 출력하면 된다.
 * - 0이 나올 경우 10번 컴퓨터가 처리하므로, 0이 출력되지 않도록 예외처리
 */

int main() {
    int t, a, b; //입력값 선언

    //0 ~ 9까지 일의 자리 패턴 미리 구하기
    vector<vector<int>> last_digit(10, vector<int>(0)); //a는 100까지이지만 1의 자리 패턴은 반복이므로 패턴 저장한 배열을 저장하는 배열...을 10개 선언
    vector<int> pattern_size(10, 1); //패턴 사이즈 저장하는 배열 선언
    for (int i = 0; i < 10; i++) {
        last_digit[i] = findPattern(i); //패턴 저장
        pattern_size[i] = last_digit[i].size(); //패턴 사이즈 저장
    }

    //입력
    cin >> t;
    while (t--) { //테스트 개수만큼 반복
        cin >> a >> b; //a 와 b 입력
        a %= 10; // a의 일의 자리

        if (a == 0) { //a가 0이면
            cout << "10\n"; // 10번째 컴퓨터가 수행하므로 10 출력
            continue;
        }
        //인덱스가 0부터 시작하므로 (b - 1)로 계산해야 함을 주의
        cout << last_digit[a][(b - 1) % pattern_size[a]] << '\n'; //패턴 % 패턴 개수 출력
    }
    return 0;
}