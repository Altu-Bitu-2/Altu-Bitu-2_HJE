#include <iostream> //입출력을 위한 헤더파일
#include <vector> // 배열 사용을 위한 헤더파일

using namespace std; // 자주 사용하는 이름 공간 미리 선언
const int INF = 1e8; // 상수 선언(행렬의 성분 최댓값)

vector<bool> visited; //방문 검사 배열
vector<vector<int>> matrix; //비용 행렬
int n, ans = INF; //최소 비용 저장 위해 미리 최댓값으로 초기화

/**
 * !생각해보기! 함수의 각 인자는 각각 어떤 역할을 하고 있나요?
 * cnt : 종료 조건(모든 도시 순회)
 * cur_city : 현재 도시 탐색
 * cost : 비용 저장
 */
void backtracking(int cnt, int cur_city, int cost) {
    if (cost >= ans) { //생각해보기 : 이 조건문이 없으면 어떻게 될까요? cnt != n 일 경우 무한 반복...?
        return;
    }
    if (cnt == n) { //종료 조건 : n개의 도시를 순회했음
        //출발 도시(0)로 다시 돌아올 수 있는지 확인
        if (matrix[cur_city][0] != 0) { // 현재 도시가 출발 도시가 아닌 경우
            ans = min(ans, cost + matrix[cur_city][0]); //비용의 최솟값 저장
        }
        return;
    }
    for (int i = 0; i < n; i++) { //cur_city에서 도시 i로 이동
        if (matrix[cur_city][i] && !visited[i]) { //길이 있고, 아직 방문하지 않은 도시
            visited[i] = true; // 중복 방지를 위해 true 변경
            backtracking(cnt + 1, i, cost + matrix[cur_city][i]); // 백트래킹 재귀 함수
            visited[i] = false; // 돌아오는 길을 위해 false 변경
        }
    }
}

/**
 * 백트래킹 풀이 (4ms)
 *
 * 한 사이클을 만들면, 어느 도시에서 시작하든 값은 같으므로 0번 도시부터 시작하는 경우만 검사하면 된다.
 */

int main() {
    //입력
    cin >> n; //도시의 수 입력
    visited.assign(n, false); // 방문 했는지 확인하기 위해 false 로 초기화된 배열
    matrix.assign(n, vector<int>(n, 0)); //비용 행렬 초기화
    for (int i = 0; i < n; i++) { //도시 i에서
        for (int j = 0; j < n; j++) { //도시 j로 가기 위한
            cin >> matrix[i][j]; // 비용 행렬 입력
        }
    }

    //연산
    visited[0] = true; // 방문했으면 true
    backtracking(1, 0, 0); //백트래킹 연산

    //출력
    cout << ans;
    return 0;
}