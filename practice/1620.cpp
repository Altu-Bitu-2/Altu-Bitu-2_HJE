// map 선언과 사용, isdigit, stoi

#include <iostream>
#include <map>

using namespace std;

int main(){
    int n, m;
    string input;
    map<string, int> pocket_name;
    map<int, string> pocket_num;
    cin >> n >> m;
    for (int i = 0; i < n; i++){
        cin >> input;
        pocket_name[input] = i;
        pocket_num[i] = input;
    }
    while(m--){
        cin >> input;
        if (isdigit(input[0])){ //문자열의 첫 번째 글자 확인
            cout << pocket_num[stoi(input)] << '\n'; //문자열을 int로 바꿀 때
        } else {
            cout << pocket_name[input] << '\n';
        }
    }
    return 0;
}