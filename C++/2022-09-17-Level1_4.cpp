#include <iostream>
#include <string>

using namespace std;

string solution(int num) 
{
    string answer = "";
    int temp = num % 2;

    if (temp == 0)
    {
        answer = "Even";
    }
    else
    {
        answer = "Odd";
    }

    return answer;
}

int main()
{
    // 입력
    int input;
    cin >> input;

    // 결과 출력
    cout << solution(input);

    return 0;
}