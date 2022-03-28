#include <iostream>

using namespace std;

int gcdRecurison(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcdRecurison(b, a % b);
}

int main() {
    int n1, n2;
    cin >> n1 >> n2;
    int g = gcdRecurison(max(n1, n2), min(n1, n2));
    int l = n1 * n2 / g;
    cout << g << '\n' << l << '\n';
    return 0;
}