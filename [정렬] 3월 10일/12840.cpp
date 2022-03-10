//
// Created by ATIV on 2022-03-09.
//

#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int h, m, s, n, tm = 0, t, c;
    cin >> h >> m >> s >> n;
    tm = h * 3600 + m * 60 + s; //계산하기 쉽도록 '초'로 변환

    for (int i; i < n; i++) {
        cin >> t; //쿼리 입력
        if (t == 1) {
            cin >> c;
            tm = tm + c;
            tm = tm % (24 * 3600); //24시간이 넘어가는 것 방지
        }
        else if (t == 2) {
            cin >> c;
            tm = tm - c;
            tm = tm % (24 * 3600); //24시간이 넘어가는 것 방지
        }
        else {
            if (tm < 0) {
                tm += 24 * 3600;
            }
            h = tm / 3600;
            m = tm / 3600 / 60;
            s = tm % 3600 % 60;
            cout << h << " " << m << " " << s;
        }
    }

    return 0;
}
