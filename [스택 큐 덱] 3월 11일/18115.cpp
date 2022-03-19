// 데큐 활용 연습하기 - 다시 구현해볼 것!

#include <iostream> //입출력
#include <deque> //데큐 사용
#include <vector> //배열 사용
#include <algorithm> //reverse 연산 사용

using namespace std; //자주 사용하는 네임스페이스 선언

deque<int> cardGame(int n, vector<int> &cmd) { //데큐 반환하는 함수
    deque<int> dq; //데큐 선언

    for (int i = 1; i <= n; i++) { //놓여 있는 위의 카드부터 검사 1, ..., n
        switch (cmd[i]) {
            case 1:
                dq.push_front(i); //내려놓은 1번째 카드를 제일 위에 올린다.
                break;
            case 2: { //!주의! c++에서 switch-case 문에 변수 선언 시 {} 필수!
                int x = dq.front(); //첫 번째 카드의 값 입력
                dq.pop_front(); // 첫 번째 값 삭제
                dq.push_front(i); // i를 제일 위에 올린다. (두 번째 값)
                dq.push_front(x); // x를 제일 위로 올린다. (첫 번째 값)
                break;
            }
            case 3:
                dq.push_back(i); //i를 맨뒤로 보낸다.
                break;
        }
    }
}

/**
 * 결과값을 보고 처음 도출 -> 기술을 모두 반대로 쓰자!
 * 1. 제일 위의 카드 바닥에 내려놓기 ->
 *    바닥에 내려놓은 카드를 다시 위에 ->
 *    제일 위의 카드 앞에 넣기
 * 2. 위에서 두 번째 카드 바닥에 내려놓기 ->
 *    바닥에 내려놓은 카드 위에서 두 번째에 넣기 ->
 *    제일 위의 카드 앞에서 두번째에 넣기
 * 3. 제일 밑에 있는 카드 바닥에 내려놓기 ->
 *    바닥에 내려놓은 카드 밑에 넣기 ->
 *    제일 위의 카드 뒤에 넣기
 */

int main() {
    int n; // 카드 개수 선언

    //입력
    cin >> n;
    vector<int> cmd(n + 1, 0); // 카드 배치 선언
    for (int i = 1; i <= n; i++) { //입력
        cin >> cmd[i]; // 카드 배치 입력
    }

    //연산
    reverse(cmd.begin() + 1, cmd.end()); //가장 위의 카드부터 검사하기 위해 기술 순서도 반대로
    deque<int> dq = cardGame(n, cmd); // 카드 게임 전 카드 배치를 구하는 함수를 데큐에 입력

    //출력
    while (!dq.empty()) { //데큐가 비워질 때까지
        cout << dq.front() << ' '; //출력
        dq.pop_front(); //맨 앞의 값부터 삭제
    }
    return 0;
}