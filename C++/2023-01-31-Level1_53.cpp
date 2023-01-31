#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 시간초과
int solution_TimeOver(string s)
{
    int answer = 0;
    
    // 문자열이 공백이 되거나 1이하로 남을때까지 반복
    while (!s.empty() && s.size() > 1)
    {
        char first = s[0];
        int firstCnt = 1;
        int secondCnt = 0;

        for (int i = 1; i < s.size(); ++i)
        {
            // 첫 문자와 같으면 firstCnt 증가 다르면 secondCnt 증가
            if (first == s[i]) { ++firstCnt; }
            else { ++secondCnt; }

            // 두 문자의 수가 같으면 문자열 잘라내기
            if (firstCnt == secondCnt)
            {
                s = s.substr(i + 1, s.size() - 1);
                ++answer;
                break;
            }
        }
    }

    // 마지막 문자열이 문자 한 개 남아있을 경우
    if (!s.empty()) { ++answer; }

    return answer;
}

// ----------------------------------------------------------
// 정답
int solution(string s)
{
    int answer = 0;

    int firstIdx = 0; // 기준 문자
    char first = s[firstIdx];
    int firstCnt = 1;
    int secondCnt = 0;

    for (int i = 1; i < s.size(); ++i)
    {
        // 첫 문자와 같으면 firstCnt 증가 다르면 secondCnt 증가
        if (first == s[i]) { ++firstCnt; }
        else { ++secondCnt; }

        // 두 문자의 수가 같을때
        if (firstCnt == secondCnt)
        {
            // idx 증가 
            ++i;
            firstIdx = i;

            //변수 초기화
            first = s[firstIdx];
            firstCnt = 1;
            secondCnt = 0;

            // 문자열 수 증가
            ++answer;
        }
    }

    // 예외 처리
    if (firstIdx != s.size()) { ++answer; }

    return answer;
}

int main()
{
    string s = "abracadabra";
    int answer = solution(s);
    cout << answer;

    return 0;
}