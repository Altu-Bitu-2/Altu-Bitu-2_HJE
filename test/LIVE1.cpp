//
// Created by ATIV on 2022-03-08.
//

#include <iostream>
#include <vector>

using namespace std;

vector<int> arr;

void bubbleSortAdv(int n){
    for(int i=0; i<n-1; i++){
        bool isSwap = false;
        for(int j=0; j<n-1-i; j++){
            if(arr[j] > arr[j+1]){
                isSwap = true;
                swap(arr[j], arr[j+1]);
            }
        }
        if(!isSwap) {
            return;
        }
    }
}

int main() {
    int n;

    cin >> n;
    arr.assign(n, 0);
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    bubbleSortAdv(n);
    for (int i; i<n; i++) {
        cout << arr[i] << '\n';
    }
    return 0;

}