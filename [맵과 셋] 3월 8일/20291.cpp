#include <iostream> //입출력을 위한 헤더파일
#include <map> //map 사용을 위한 헤더파일
#include <string> // 문자열 사용을 위한 헤더파일

using namespace std; //자주 사용하는 namespace 미리 선언

/**
 * 중복없이 정렬이 필요한 경우
 * key(확장자)-value(파일 개수) 쌍이 필요하므로 map 사용
 */

int main() {
    int n; //파일의 개수 입력 받을 정수형 변수 선언
    string input; //파일의 이름 받을 문자열 선언
    map<string, int> extension; //key: 확장자, value: 확장자 파일 개수

    //입력 & 연산
    cin >> n;
    while (n--) {
        cin >> input; //파일 이름 입력 받기
        //string.substr(pos, len): 첫 번째 문자의 위치(pos)부터 pos + len 까지의 부분 문자열
        //pos + len 이 문자열보다 길다면 문자열 마지막 문자까지만 리턴하도록 처리
        string ext = input.substr(input.find('.') + 1, input.length()); //.뒤의 부분 문자열 추출
        extension[ext]++; //확장자 개수 추가
    }
    //출력
    for (auto iter = extension.begin(); iter != extension.end(); iter++) { //반복자 선언, map extension의 처음부터 끝까지 반복
        cout << iter->first << ' ' << iter->second << '\n'; // map의 key와 value 출력
    }
    return 0;
}