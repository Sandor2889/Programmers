#include <iostream>
#include <string>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// 모두 소문자로 변환
string getLowerString(string city)
{
    string temp = "";
    for (char& c : city) { temp += tolower(c); }
    return temp;
}

int solution(int cacheSize, vector<string> cities)
{
    // miss 일때 push (가득찬 경우도 고려),
    // hit 일때 idx를 찾아 제거후 다시 push,
    // 때문에 LRU를 vector로 구현 필요.
    vector<string> caching;
    int answer = 0;

    if (cacheSize == 0) { return cities.size() * 5; }

    for (int i = 0; i < cities.size(); ++i)
    {
        // 소문자로 이름 통일 시키기
        string unity = getLowerString(cities[i]);

        // caching에 city가 있는지 확인
        auto it = find(caching.begin(), caching.end(), unity);

        // hit 일 경우 - 제거후 다시 넣기
        if (it != caching.end())
        {
            answer += 1;
            caching.erase(it);
            caching.push_back(unity);
        }
        // miss 일 경우
        else
        {
            answer += 5;

            // caching이 가득차있다면 맨 앞(가장 오래된 데이터) 제거
            if (caching.size() == cacheSize) { caching.erase(caching.begin()); }
            caching.push_back(unity);
        }
    }

    return answer;
}

int main()
{
    vector<string> cities = 
    { 
        "Jeju", "Pangyo", "Seoul", "NewYork", "LA",
        "SanFrancisco", "Seoul", "Rome", "Paris", "Jeju", "NewYork", "Rome" 
    };
    int cacheSize = 5;
    int answer = solution(cacheSize, cities);

    cout << answer;
}