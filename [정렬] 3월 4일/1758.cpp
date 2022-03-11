//
// Created by ATIV on 2022-03-10.
//

//3월 11일 수정

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    long long M = 0;
    cin >> n;
    vector<long long> tip(n);

    //팁 입력
    for (int i = 0; i < n; i++) {
        cin >> tip[i];
    }

    //내림차순 정렬
    sort(tip.begin(), tip.end(), greater<>());

    //최댓값 계산
    for (int i = 0; i < n; i++) {
        if (tip[i] - i < 0) {
            continue;
        }
        M += (tip[i] - i);
    }

    //출력
    cout << M;
    return 0;
}