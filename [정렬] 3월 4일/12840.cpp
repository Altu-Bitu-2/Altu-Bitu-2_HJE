//
// Created by ATIV on 2022-03-09.
//

//3월 11일 수정

#include <iostream>

using namespace std;
const int HOUR = 3600;
const int MIN = 60;
const int DAY = 24 * 3600;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int h, m, s, n, tm = 0, t, c;
    cin >> h >> m >> s >> n;
    tm = h * HOUR + m * MIN + s; //계산하기 쉽도록 '초'로 변환

    for (int i = 0; i < n; i++) {
        cin >> t;
        //쿼리 입력
        if (t == 1) {
            cin >> c;
            tm = tm + c;
            tm = tm % DAY; //24시간이 넘어가는 것 방지
        } else if (t == 2) {
            cin >> c;
            tm = tm - c;
            tm = tm % DAY; //24시간이 넘어가는 것 방지
        } else {
            if (tm < 0) {
                tm += DAY;
            }
            h = tm / HOUR;
            m = tm % 3600 / 60;
            s = tm % 3600 % 60;
            cout << h << " " << m << " " << s << "\n";
        }
    }

    return 0;
}
