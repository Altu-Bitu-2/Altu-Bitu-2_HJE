//
// Created by ATIV on 2022-03-10.
//

//백준 풀이 제출 시 런타임 에러가 뜹니다...ㅠㅠㅠㅠ....

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//함수 S 계산 후 출력
void printS(int n, vector<int> a, vector<int> b){
    int s=0;
    for (int i; i<n; i++){
        s += a[i] * b[i];
    }
    cout << s;
}

int main(){
    int n;
    vector<int> a, b;
    cin >> n;

    //a배열 입력
    for (int i; i<n; i++){
        cin >> a[i];
    }

    //b배열 입력
    for (int i; i<n; i++){
        cin >> b[i];
    }

    //b 최댓값에 a 최솟값이 할당되도록 정렬
    for (int i; i<n; i++){
        for (int j; j<n; j++){
            if (b[i] < b[j] && a[i] < a[j])
                swap(a[i], a[j]);
            else if (b[i] > b[j] && a[i] > a[j])
                swap(a[i], a[j]);
        }
    }

    //출력
    printS(n, a, b);
    return 0;
}