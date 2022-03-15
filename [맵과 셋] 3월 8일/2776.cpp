// 튜터님 코멘트를 바탕으로 3월 15일에 수정했습니다
// 시간 복잡도 개념에 관해 잘 이해가 되지 않았는데 이번 문제에 관한 코멘트와 수정을 통해
// 다른 문제를 풀 때 어떻게 접근해야하는지 조금은 자신감이 생긴 것 같습니다! 정말 감사합니다!!

#include <iostream>
#include <unordered_set>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {

        int n, m, input;
        unordered_set<int> one;

        cin >> n;
        while (n--) {
            cin >> input;
            one.insert(input);
        }

        cin >> m;
        while(m--){
            cin >> input;
            auto iter = one.find(input);
            if (iter == one.end()){
                cout << 0 << '\n';
            } else {
                cout << 1 << '\n';
            }
        }
    }

    return 0;
}
