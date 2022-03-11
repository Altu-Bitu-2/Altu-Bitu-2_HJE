
//샘플 코드에 주석 달기 (기존 풀이는 주석으로 전환) ==> 리버스 함수 복습, 배열 인덱스 조정(전역 변수 사용법)

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int SIZE = 20;

vector<int> arr(SIZE + 1); //1번 인덱스부터 시작하기 위해 크기를 (SIZE + 1)로 선언

//역순 정렬
/* void sorted(int a, int b) {
    while (a < b) {
        swap(arr[a++], arr[b--]);
    }
}*/

//a ~ b를 역순으로 배치하는 함수, reverse 함수 직접 구현
void reverseAtoB(int a, int b) {
    //더하고 빼는 변화값을 증가변수로 줘서 사용, 절반까지만
    for (int i = 0; i <= (b - a) / 2; i++) {
        swap(arr[a + i], arr[b - i]);
    }
}

/**
 * 단순 구현 문제.
 * 1. 직접 구현: 카드를 역순으로 두기 = 수열을 반으로 접었다 생각할 때, 마주보는 원소끼리 swap!
 * 2. 함수 활용: <algorithm> 헤더에 있는 "reverse" 함수 사용 -> reverse(시작 반복자, 종료 반복자): 시작 ~ 종료전까지 원소들을 뒤집음
 */

int main() {
    int a, b;

    //카드 초기화
    for (int i = 1; i < SIZE; i++) {
        arr[i] = i;
    }

    //입력 & 연산
    //입력이 10개로 한정되므로 for문으로 10번 입력받는 것도 가능!
    while (cin >> a >> b){
        //헤더 함수 사용
        reverse(arr.begin() + a, arr.begin() + b + 1);

        //직접 구현
        //reverseAtoB(a, b);

        //기존 구현
        /* for (int i = 0; i < 10; i++) {
        cin >> a >> b;
        sorted(a - 1, b - 1); }
}       */
    }

    //출력
    for (int i = 1; i < SIZE; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}
