//
// Created by ATIV on 2022-03-10.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, max=0;
    cin >> n;
    vector<int> tip(n);

    //팁 입력
    for (int i; i < n; i++) {
        cin >> tip[i];
    }

    //내림차순 정렬
    sort(tip.begin(), tip.end(), greater<>());

    //최댓값 계산
    for (int i; i < n; i++) {
        if (tip[i] - i < 0){
            continue;
        }
        max += (tip[i] - i);
    }

    //출력
    cout << max;
    return 0;
}