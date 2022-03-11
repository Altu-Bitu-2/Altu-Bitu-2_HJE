//pair 클래스 사용법 복습하기

#include <iostream> //입출력을 위한 헤더파일
#include <vector> //배열 사용을 위한 헤더파일
#include <algorithm> //sort 함수 사용을 위한 헤더파일

using namespace std; //계속 사용하는 namespace 미리 선언

typedef pair<int, int> ci; // pair 클래스 선언(두 가지 데이터를 동시에 다룰 때 사용)

bool cmp(const ci &a, const ci &b) { //비교함수 선언
    if (a.second != b.second) { //1. y좌표가 증가하는 순서
        return a.second < b.second;
    }
    return a.first < b.first; //2. (y좌표가 같으면) x좌표가 증가하는 순서
}

int main() {
    int n, a, b; //점의 개수....a와 b는 어디에 쓰나요...?

    //입력
    cin >> n; // 점의 개수 입력
    vector<ci> arr(n, {0, 0}); //점의 개수 만큼 좌표값 넣을 배열 선언
    for (int i = 0; i < n; i++) { //점의 개수만큼 반복
        cin >> arr[i].first >> arr[i].second; //배열에 좌표값 입력
    }
    //연산
    sort(arr.begin(), arr.end(), cmp); //정렬

    //출력
    for (int i = 0; i < n; i++) {
        cout << arr[i].first << ' ' << arr[i].second << '\n'; //출력
    }
    return 0;
}