#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// 소수인지 판별
bool isPrimeNum(long long num)
{
    if (num == 1) { return false; }

    for (long long i = 2; i * i <= num; ++i)
    {
        if (num % i == 0) { return false; }
    }

    return true;
}

int solution(int n, int k)
{
    int answer = 0;

    // n을 k진수로 변환
    string strNum = "0";    // 마지막 '0' 처리를 위해 추가
    while (n / k > 0)
    {
        strNum += (n % k + '0');
        n /= k;
    }
    strNum += n + '0';
    reverse(strNum.begin(), strNum.end());

    // 소수 탐색
    string primeNum;
    for (int i = 0; i < strNum.size(); ++i)
    {
        if (strNum[i] != '0') { primeNum += strNum[i]; }
        else
        {
            if (primeNum == "") { continue; }

            if (isPrimeNum(stoll(primeNum))) { ++answer; };
            primeNum = "";
        }
    }

    return answer;
}

int main()
{
    int answer = solution(437674, 3);
    cout << answer;

    return 0;
}