#include <iostream>
#include <string>
#include <vector>

using namespace std;

string correctBabbling[4] = { "aya", "ye", "woo", "ma" };
int babblingSize[4] = { 3, 2, 3, 2 };

int solution(vector<string> babbling)
{
    int answer = 0;

    for (int i = 0; i < babbling.size(); ++i)
    {
        string temp = babbling[i];
        string prevStr = "";

        for (int j = 0; j < 4; ++j)
        {
            // 찾으면 해당 범위의 string 제거
            auto it = temp.find(correctBabbling[j]);

            if (temp == "" || prevStr[0] == temp[0]) { break; }
            else if (temp[0] != correctBabbling[j][0]) { continue; }

            if (temp.find(correctBabbling[j]) != string::npos)
            {
                temp.erase(it, it + babblingSize[j]);
                prevStr = correctBabbling[j];
                j = -1;
            }
        }

        if (temp == "") { answer += 1; }
    }

    return answer;
}

int main()
{
    vector<string> babbling = { "ayaye", "ayayeaya", "yeayaye"};
    int answer = solution(babbling);
    cout << answer;

    return 0;
}