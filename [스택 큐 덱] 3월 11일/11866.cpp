// 큐 활용 연습하기

#include <iostream> //입출력
#include <queue> // 큐 사용
#include <vector> // 배열 사용

using namespace std; // 자주 사용하는 이름공간 미리 선언

vector<int> simulation(int k, queue<int> &q) { //요세푸스 순열 리턴하는 함수 선언
    vector<int> result; //요세푸스 순열
    int cnt = 0; //카운트 변수

    while (!q.empty()) { //큐가 비워질 때까지
        int x = q.front(); //x는 큐의 첫번째 값
        q.pop(); // 맨 앞의 값 삭제
        cnt++; //횟수 추가
        if (cnt == k) { //k번째 pop하는 원소라면
            result.push_back(x); //요세푸스 순열에 x값 추가
            cnt = 0; //카운트 초기화
            continue;
        }
        q.push(x); //pop한 원소 다시 push
    }
    return result; // 요세푸스 순열 리턴
}

/**
 * 1. 큐에 1 ~ N까지 값 초기화
 * 2. 이후 k 번째 사람 찾기 위해 pop, push 반복
 * 3. k번째 pop 일 경우 요세푸스 순열에 저장, 이후 원소 제거 (다시 push 하지 않음!)
 */

int main() {
    int n, k; // 개수와 출력할 순서 선언
    queue<int> q; //큐 선언

    //입력
    cin >> n >> k;
    for (int i = 1; i <= n; i++) { //큐 초기화
        q.push(i);
    }
    //연산
    vector<int> result = simulation(k, q);
    //출력
    cout << '<'; // 백준 출력 형태에 맞추기
    for (int i = 0; i < result.size() - 1; i++) {
        cout << result[i] << ", "; //배열이 끝날 때까지 요세푸스 순열 출력
    }
    cout << result[result.size() - 1] << '>'; // 백준 출력 형태에 맞추기
    return 0;
}