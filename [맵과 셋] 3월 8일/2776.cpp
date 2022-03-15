

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
