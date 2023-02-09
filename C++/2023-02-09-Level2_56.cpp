#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 반례 조건들을 모두 충족 불가
bool myCompare_fail(const string& a, const string& b)
{
    int idx = 0;

    while (true)
    {
        if (idx < a.size() && idx < b.size())
        {
            // 일의자리 숫자 비교
            if (a[idx] == b[idx]) { ++idx; }
            else { return a[idx] > b[idx]; }        }
        else
        {
            // 사이즈가 작은 쪽의 idx-1의 값 과 다른 쪽의 마지막 값을 비교
            if (idx >= a.size()) { return a[idx - 1] > b[b.size()-1]; }
            else if (idx >= b.size()) { return a[a.size()-1] > b[idx - 1]; }
        }
    }
}

// 그냥.. 두 string을 자리 바꿔보며 비교해서 큰 수로 정렬하면 된다...
bool myCompare(const string& a, const string& b)
{
    return a + b > b + a;
}

string solution(vector<int> numbers)
{
    string answer = "";
    vector<string> strNums;

    // string으로 바꾸기
    for (int i = 0; i < numbers.size(); ++i)
    {
        strNums.push_back(to_string(numbers[i]));
    }

    // 내림차순(+ 예외 처리) 정렬
    sort(strNums.begin(), strNums.end(), myCompare);

    // answer에 순서대로 합하기
    for (int i = 0; i < strNums.size(); ++i) { answer += strNums[i]; }

    // 0에 대한 예외처리
    if ( answer[0] == '0') { return "0"; }

    return answer;
}

int main()
{
    vector<int> numbers = { 0, 0, 0 };

    string answer = solution(numbers);

    for (char c : answer)
    {
        cout << c;
    }

    return 0;
}