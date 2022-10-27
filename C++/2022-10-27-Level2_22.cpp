#include <iostream>
#include <string>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// ��� �ҹ��ڷ� ��ȯ
string getLowerString(string city)
{
    string temp = "";
    for (char& c : city) { temp += tolower(c); }
    return temp;
}

int solution(int cacheSize, vector<string> cities)
{
    // miss �϶� push (������ ��쵵 ���),
    // hit �϶� idx�� ã�� ������ �ٽ� push,
    // ������ LRU�� vector�� ���� �ʿ�.
    vector<string> caching;
    int answer = 0;

    if (cacheSize == 0) { return cities.size() * 5; }

    for (int i = 0; i < cities.size(); ++i)
    {
        // �ҹ��ڷ� �̸� ���� ��Ű��
        string unity = getLowerString(cities[i]);

        // caching�� city�� �ִ��� Ȯ��
        auto it = find(caching.begin(), caching.end(), unity);

        // hit �� ��� - ������ �ٽ� �ֱ�
        if (it != caching.end())
        {
            answer += 1;
            caching.erase(it);
            caching.push_back(unity);
        }
        // miss �� ���
        else
        {
            answer += 5;

            // caching�� �������ִٸ� �� ��(���� ������ ������) ����
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