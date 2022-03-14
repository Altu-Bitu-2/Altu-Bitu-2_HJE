#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() {
    int t, n, m, input;
    set<int> one;

    cin >> t >> n;
    while (n--) {
        cin >> input;
        one.insert(input);
    }
    cin >> m;
    vector<int> two(m, 0);
    for (int i = 0; i < m; i++) {
        cin >> two[i];
    }

    for (int i = 0; i < m; i++) {
        for (auto iter = one.begin(); iter != one.end(); iter++) {
            if (two[i] == *iter) {
                cout << 1 << '\n';
                break;
            }
        }

        cout << 0 << '\n';
    }

    return 0;
}
