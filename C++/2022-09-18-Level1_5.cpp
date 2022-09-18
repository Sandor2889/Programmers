#include <iostream>

using namespace std;
int solution(int n)
{
    int answer = 0;

    while (n > 0)
    {
        answer += n % 10;
        n /= 10;
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