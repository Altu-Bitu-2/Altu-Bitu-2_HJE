#include <iostream> //입출력을 위한 헤더파일
#include <algorithm> // sort 함수 사용을 위한 헤더파일
#include <vector> // 배열 사용을 위한 헤더파일
#include <map> // map 사용을 위한 헤더파일

using namespace std; // 자주 사용하는 namespace 미리 선언

/**
 * [영단어 우선순위]
 * 1. 자주 나오는 단어일수록 앞에 배치
 * 2. 해당 단어의 길이가 길수록 앞에 배치
 * 3. 알파벳 사전 순으로 앞에 있는 단어일수록 앞에 배치
 */

map<string, int> word_cnt; // 단어와 빈도수 매핑

bool cmp(const string &a, const string &b) {
    if (word_cnt[a] != word_cnt[b]) { //자주 나오는 단어일수록 앞에 배치
        return word_cnt[a] > word_cnt[b]; // a가 b 보다 작을 경우 0 return, swap
    }
    if (a.length() != b.length()) { //해당 단어의 길이가 길수록 앞에 배치
        return a.length() > b.length(); // a가 b 보다 작을 경우 0 return, swap
    }
    return a < b; //알파벳 사전 순서로 배치
}

int main() {
    //입출력 속도 향상
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    vector<string> words; //단어장 배열 선언 (sort 정렬 후 출력하기 위해서)
    string word; // 입력 받을 문자열 선언
    int n, m; // 단어의 개수와 길이 선언

    //입력
    cin >> n >> m;

    //입력 + 영단어 횟수 저장
    while (n--) {
        cin >> word; // 단어 입력 받기
        if (word.length() < m) { //길이가 m 미만이면 영단어장에 들어가지 않음
            continue;
        }
        //map의 key가 존재하는지 논리 부정 연산자로 어떻게 판단이 가능할까요? 피피티의 "이것도 알아보세요"를 참고해도 좋아요!
        // => word 가 존재한다면, key 에 맞는 value를 반환할 것이고 그것에 부정 연산자를 씌우면 0이 되기 때문에 map의 key가 존재하는지 판단이 가능한 것 같습니다.
        if (!word_cnt[word]) { //중복 영단어 들어가는 것 방지
            words.push_back(word); // if문 조건이 참이면 요소 추가
        }
        word_cnt[word]++; //word 단어 빈도수 증가
    }

    //조건에 맞게 정렬
    sort(words.begin(), words.end(), cmp);

    //출력
    for (int i = 0; i < words.size(); i++) {
        cout << words[i] << '\n';
    }
    return 0;
}