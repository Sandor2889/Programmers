#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> v = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
string answer;

int solution(string s) {

    string temp = "";
    for (int i = 0; i < s.size(); i++)
    {
        temp += s[i];

        for (int j = 0; j < v.size(); j++)
        {
            if (temp == v[j])
            {
                answer += j + '0';
                temp = "";
                break;
            }
            else if (temp >= "0" && temp <= "9")
            {
                answer += temp;
                temp = "";
                break;
            }
        }
    }

    return stoi(answer);
}

int main()
{
    string s;
    cin >> s;

    cout << solution(s);

    return 0;
}