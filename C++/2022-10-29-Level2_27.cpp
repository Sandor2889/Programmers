#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// answer�� ������ ���� ���� ������ ���ڼ� �̴�.
vector<int> solution(string s)
{
    vector<int> answer;
    vector<int> nums(100001);

    // 1. '{' : ����
    // 2. '}' : (������ ����) �ݵ�� ���� �ڿ� ���� ������ temp ó��
    // 3. ',' : temp�� ��������� ����, '}' ���� ���
    string temp = "";
    for (int i = 0; i < s.size()-1; ++i)
    {
        if (s[i] == '{') { continue; }
        else if (s[i] == '}' || s[i] == ',')   // temp�� ä���� ���ڷ� nums[temp] �� ���� 
        {
            if (temp.empty()) { continue; }

            int num = stoi(temp);   // ����ȯ
            ++nums[num];
            temp = "";
        }
        else { temp += s[i]; }
    }

    // �ִ� ���� ���� ���ڸ� answer�� push�ϰ� 0���� �ʱ�ȭ
    while (true)
    {
       auto it = max_element(nums.begin(), nums.end()) - nums.begin();

       if (it == 0) { break; } // ��� ���� 0�� �Ǹ� ����

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