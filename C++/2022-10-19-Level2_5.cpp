#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes)
{
    unordered_map<string, int> kinds;
    int answer = 1;

    // 의상의 종류별로 몇개인지 넣기
    for (int i = 0; i < clothes.size(); i++)
    {
        // key가 없다면 추가
        if (kinds.find(clothes[i][1]) == kinds.end())
        {
            kinds.insert({ clothes[i][1], 1 });
        }
        // key가 이미 있다면 수량 증가 
        else
        {
            kinds[clothes[i][1]]++;
        }
    }

    // 옷 종류에 따른 수식 (x + a)(x + b)(x + n)... - 1
    // -1 은 (의상 종류인 x의 승수에 대한 값이 무의미 하기 때문)
    for (auto it = kinds.begin(); it != kinds.end(); it++)
    {
        answer *= (1 + it->second);
    }

    return answer - 1;
}

int main()
{ 
    vector<vector<string>> clothes
    {
        { "yellow_hat", "headgear"},
        { "blue_sunglasses", "eyewear"},
        { "green_turban", "headgear"}
    };

    int answer = solution(clothes);
    cout << answer;

    return 0;
}