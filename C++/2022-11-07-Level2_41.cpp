#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// �Ҽ����� �Ǻ�
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

    // n�� k������ ��ȯ
    string strNum = "0";    // ������ '0' ó���� ���� �߰�
    while (n / k > 0)
    {
        strNum += (n % k + '0');
        n /= k;
    }
    strNum += n + '0';
    reverse(strNum.begin(), strNum.end());

    // �Ҽ� Ž��
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