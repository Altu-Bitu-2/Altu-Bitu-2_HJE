//
// Created by ATIV on 2022-03-09.
//

//과제를 실행시켰을 때 입력과 출력이 정상적으로 되지 않아
// 어디서 풀이가 잘못 되었는지 수정하기가 어려웠습니다...전체적으로 난장판이에요ㅠㅠㅠㅠㅠ
// 입력과 출력이 정상적으로 되지 않는 이유는 뭘까요ㅠㅠㅠㅠ...

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> arr;

//역순 정렬
void sorted(int a, int b){
    while(a<b){
        swap(arr[a++], arr[b--]);
    }
}

int main(){
    int a, b;
    arr.assign(20, 0);

    //20까지 입력
    for (int i; i<20; i++){
        arr[i] = i+1;
    }

    //구간 입력 후 배열
    for (int i; i<10; i++) {
        cin >> a >> b;
        sorted(a-1, b-1);
    }

    //출력
    for (int i=0; i<20; i++){
        cout << arr[i] << " ";
    }
    return 0;
}
