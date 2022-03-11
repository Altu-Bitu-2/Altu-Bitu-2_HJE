//
// Created by ATIV on 2022-03-10.
//

//3월 11일 수정

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//함수 S 계산 후 출력
void printS(int n, vector<int> a, vector<int> b) {
    int s = 0;
    for (int i; i < n; i++) {
        s += a[i] * b[i];
    }
    cout << s;
}

int main() {
    int n;
    vector<int> a, b;

    cin >> n;
    a.assign(n, 0);
    b.assign(n, 0);

    //a배열 입력
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    //b배열 입력
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    //b 최댓값에 a 최솟값이 할당되도록 정렬 => a와 b 모두 재배열로 정정
    sort(a.begin(), a.end());
    sort(b.begin(), b.end(), greater<>());

    //출력
    printS(n, a, b);
    return 0;
}