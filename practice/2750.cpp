//배열 할당 복습, 불 변수 사용하기, swap

#include <iostream>
#include <vector>

using namespace std;

vector<int> num;

int main() {
    int n, tmp = 0;
    num.assign(n, 0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }

    for (int i = 0; i < n - 1; i++) {
        //bool isSwap = false; 무슨 뜻인지 다시 생각해보기
        for (int j = 0; j < n - i; i++) { // 왜 j가 필요한지 다시 생각해보기
            if (num[i] > num[i + 1]) {
                //isSwap = true;
                tmp = num[i];
                num[i] = num[i + 1];
                num[i + 1] = tmp; //swap(arr[j), arr[j+1]);
            }
            //if (!isSwap){break;}
        }
    }

    for (int i = 0; i < n; i++){
        cout << num[i] << "\n";
    }

    return 0;
}
