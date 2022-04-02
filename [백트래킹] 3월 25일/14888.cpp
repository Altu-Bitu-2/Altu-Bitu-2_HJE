#include <iostream> //입출력을 위한 헤더파일
#include <vector> // 배열 사용을 위한 헤더파일

using namespace std; // 자주 사용하는 이름공간 미리 선언
const int INF_MAX = 1e9; // 최댓값 상수 선언
const int SIZE = 11; // 수의 최대 개수 상수 선언

int n; // 수의 개수 선언
vector<int> num(SIZE + 1); // 숫자 배열 선언
vector<int> expression(4); //0: +, 1: -, 2: *, 3: / 사칙 연산 배열 선언
int max_value = -INF_MAX, min_value = INF_MAX; //최댓값, 최솟값 초기화

void backtracking(int cnt, int sum) { //cnt: 수 인덱스, sum: 연산 결과
    if (cnt == n - 1) { //연산 모두 완료했다면 (기저조건)
        max_value = max(max_value, sum); //최댓값 저장
        min_value = min(min_value, sum); //최솟값 저장
        return;
    }
    for (int i = 0; i < 4; i++) { //연산자 검사
        if (expression[i]) { //연산자가 있으면 실행
            expression[i]--; //연산자 횟수 차감
            int new_sum = 0;
            switch (i) { //연산자 종류에 따라
                case 0:
                    new_sum = sum + num[cnt + 1]; //덧셈
                    break;
                case 1:
                    new_sum = sum - num[cnt + 1]; //뺄셈
                    break;
                case 2:
                    new_sum = sum * num[cnt + 1]; //곱셈
                    break;
                case 3:
                    new_sum = sum / num[cnt + 1]; //나눗셈
                    break;
            }
            backtracking(cnt + 1, new_sum); //백트래킹 재귀 함수
            expression[i]++; //연산자 횟수 초기화
        }
    }
}

/**
 * 연산자 모두 돌려보면서 배치한 후, 각 연산자에 따른 값 계산
 */

int main() {
    //입력
    cin >> n;
    for (int i = 0; i < n; i++) { // n개 만큼
        cin >> num[i]; // 숫자 입력
    }
    for (int i = 0; i < 4; i++) { //사칙 연산의
        cin >> expression[i]; //각각 개수 입력
    }

    //연산
    backtracking(0, num[0]);

    //출력
    cout << max_value << '\n' << min_value;
    return 0;
}