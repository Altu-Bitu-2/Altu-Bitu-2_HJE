//
// Created by ATIV on 2022-03-08.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> arr;

void sorted(int a, int b){
    while(a<b){
        swap(arr[a++], arr[b--]);
    }
}

int main(){
    int a, b;
    arr.assign(20, 0);
    for (int i; i<20; i++){
        arr[i] = i+1;
    }
    for (int i; i<10; i++) {
        cin >> a >> b;
        sorted(a-1, b-1);
    }
    for (int i=0; i<20; i++){
        cout << arr[i] << " ";
    }
    return 0;
}