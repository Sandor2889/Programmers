#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// answer의 순서는 가장 많이 나오는 숫자순 이다.
vector<int> solution(string s)
{
    vector<int> answer;
    vector<int> nums(100001);

    // 1. '{' : 무시
    // 2. '}' : (마지막 제외) 반드시 숫자 뒤에 오기 때문에 temp 처리
    // 3. ',' : temp가 비어있을땐 무시, '}' 같은 기능
    string temp = "";
    for (int i = 0; i < s.size()-1; ++i)
    {
        if (s[i] == '{') { continue; }
        else if (s[i] == '}' || s[i] == ',')   // temp에 채워진 숫자로 nums[temp] 값 증가 
        {
            if (temp.empty()) { continue; }

            int num = stoi(temp);   // 형변환
            ++nums[num];
            temp = "";
        }
        else { temp += s[i]; }
    }

    // 최대 값을 가진 숫자를 answer에 push하고 0으로 초기화
    while (true)
    {
       auto it = max_element(nums.begin(), nums.end()) - nums.begin();

       if (it == 0) { break; } // 모든 값이 0이 되면 종료

       answer.push_back(it);
       nums[it] = 0;
    }

    return answer;
}

int main() 
{
    string s = { "{{2},{2,1},{2,1,3},{2,1,3,4}}" };
    vector<int> answer = solution(s);

    return 0;
}