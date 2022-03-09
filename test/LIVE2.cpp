//
// Created by ATIV on 2022-03-08.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> arr, sorted;

void merge(int left, int mid, int right){
    int p1 = left;
    int p2 = mid+1;
    int index = left;
    while(p1 <= mid && p2 <= right){
        if(arr[p1] < arr[p2]){
            sorted[index++] = arr[p1++];
        }
        else{
            sorted[index++] = arr[p2++];
        }
    }
    //검산
    while(p1 <= mid){
        sorted[index++] = arr[p1++];
    }
    while (p2 <= right){
        sorted[index++] = arr[p2++];
    }
    for(int i=left; i <= right; i++){
        arr[i] = sorted[i];
    }
}

void divide(int left, int right){
    if(left < right){
        int mid = (left + right) / 2;
        divide(left, mid);
        divide( mid+1, right);
        merge(left, mid, right);
    }
}

int main() {
    int n;
    cin >> n;
    arr.assign(n, 0);
    sorted.assign(n, 0);
    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }

   sort(arr.begin, arr.end())

    for(int i=0; i<n; i++){
        cout << arr[i] << '\n';
    }

    return 0;
}
