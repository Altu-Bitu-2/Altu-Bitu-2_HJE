#include <iostream> //입출력을 위한 헤더파일
#include <algorithm> //sort 함수 사용을 위한 헤더파일
#include <vector> //배열 사용을 위한 헤더파일

using namespace std; // 자주 사용하는 namespace 미리 선언

const int SIZE = 8; //배열 크기

int n, m; //입력 받을 n과 m 선언
vector<int> num(SIZE); // 숫자 입력 받을 배열 선언
vector<int> ans(SIZE); // 정렬될 배열 선언
vector<bool> check(SIZE); // 중복 확인을 위한 배열 선언

void backtracking(int cnt) {
    if (cnt == m) { //길이 m 이라면 (기저조건)
        for (int i = 0; i < m; i++) {
            cout << ans[i] << ' '; //길이가 m일 때 수열 출력
        }
        cout << '\n'; // 줄 바꿈
        return; // 함수 탈출
    }
    int prev = 0; //이전에 선택한 값
    for (int i = 0; i < n; i++) {
        if (!check[i] && prev != num[i]) { //수 위치 중복 체크 && 이전에 탐색한 값이 아니라면
            prev = num[i]; //이전에 선택한 값
            ans[cnt] = num[i]; // 출력하게 될 배열에 값 삽입
            check[i] = true; // 중복 확인
            backtracking(cnt + 1); // 백트래킹을 위한 재귀함수
            check[i] = false; // 다시 false 로 바꿔두기
        }
    }
}

/**
 * 1. 우선 수열을 사전 순으로 증가하는 순서로 출력해야 하므로 주어진 수열을 오름차순 정렬
 * 2. 이 상태에서 우선, 같은 위치의 수를 또 선택하지 않도록 중복제거 (check 배열 사용)를 해줌
 * 3. 그 후, 중복되는 "수열"을 거르는 방법은 이전에 선택한 값을 변수에 저장해서, 수열을 만들다 다시 루트 노드로 돌아왔을 때
 *    이전에 선택한 값과 같은 값이면 넘어가면 됨! -> 어차피 같은 수이므로 같은 과정 반복해서 똑같은 수열이 나올 것
 */

int main() {
    //입력
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> num[i]; //배열에 숫자 입력
    }

    //연산
    sort(num.begin(), num.begin() + n);

    //백트래킹 & 출력
    backtracking(0);
    return 0;
}