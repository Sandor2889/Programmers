#include <iostream>
#include <string>
#include <vector>

using namespace std;


string solution(vector<string> seoul) 
{
    string answer = "";
    string who = "Kim";

    for (int i = 0; i < seoul.size(); i++)
    {
        if (seoul[i] == who)
        {
            answer = "김서방은 " + to_string(i) + "에 있다";
            break;
        }
    }
    return answer;
}
int main()
{
    
    vector<string> temp;
    int people = 2; // 입력 수

    // 입력
    for (int i = 0; i < people; i++)
    {
        string name;
        cin >> name;
        temp.push_back(name);
    }

    // 결과 출력
    cout << solution(temp);

    return 0;
}