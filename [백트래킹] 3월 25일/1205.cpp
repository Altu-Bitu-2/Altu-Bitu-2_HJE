#include <iostream> //입출력을 위한 헤더파일
#include <vector> // 배열 사용을 위한 헤더파일

using namespace std; //자주 사용하는 이름공간 미리 선언

int findRanking(int n, int new_score, int p, vector<int> &ranking) { //랭킹 찾는 함수 선언
    int idx = 1; //인덱스 값 초기화
    int ans = 1; //정답 값 초기화
    //새로운 점수를 어느 위치에 넣을지 탐색
    while (idx <= n) { //n이 0이면 시작하지 않음
        if (new_score > ranking[idx]) { //새 점수가 랭킹 리스트 값보다 크다면
            break; //break 이후 정답 반환
        }
        if (new_score < ranking[idx]) { //새 점수가 랭킹 리스트 값보다 작다면
            ans = idx + 1; //정답 인덱스값 증가
        }
        idx++; //인덱스값 증가
    }
    if (idx == p + 1) { //랭킹 리스트에 들어가지 못하는 경우
        return -1; // -1 반환
    }
    return ans; // 정답 반환
}

/**
 * [등수 구하기]
 *
 * 1. n = 0일 때, 고려
 * 2. 등수는 p보다 작지만, 점수가 더 좋을 때만 랭킹이 갱신되므로 랭킹 리스트에 들어가지 못하는 경우 고려 (동점)
 *
 * 현재 랭킹에 올라간 n까지 등수와 새로운 점수를 비교하며 새로운 점수 몇 등인지 계산
 * 새로운 점수가 현재 탐색 등수의 점수보다 작다면 -> 현재 탐색 등수 + 1
 * 동점일 경우 -> 그 전 등수 그대로 사용 -> 아무 처리도 하지 않음!
 */

int main() {
    int n, new_score, p; //점수 개수, 새 점수, 랭크 리스트 개수 선언

    //입력
    cin >> n >> new_score >> p; //점수 개수, 새 점수, 랭크 리스트 개수 입력
    vector<int> ranking(p + 1, 0); // 랭크 배열 선언
    for (int i = 1; i <= n; i++) {
        cin >> ranking[i]; // 배열에 랭킹된 점수 입력
    }

    //연산 & 출력
    cout << findRanking(n, new_score, p, ranking);
    return 0;
}