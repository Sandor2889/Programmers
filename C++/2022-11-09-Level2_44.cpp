#include <iostream>
#include <string>
#include <vector>

using namespace std;

#include <string>
#include <vector>

using namespace std;

int myTurn(int cnt, int m)
{
    return cnt % m;
}

string solution(int n, int t, int m, int p)
{
    string answer = "";

    int num = 0;
    int cnt = 0;

    while (answer.size() < t)
    {
        int temp = num;

        // n���� ��ȯ
        string strNum = "";
        if (temp == 0) { strNum = "0"; }
        while (temp != 0)
        {
            int cal = temp % n;
            char res;
            if (cal == 10) { res = 'A'; }
            else if (cal == 11) { res = 'B'; }
            else if (cal == 12) { res = 'C'; }
            else if (cal == 13) { res = 'D'; }
            else if (cal == 14) { res = 'E'; }
            else if (cal == 15) { res = 'F'; }
            else { res = cal + '0'; }

            strNum += res;
            temp /= n;
        }

        // ���� �ϳ��� ����
        while (strNum.size() > 0)
        {
            // �� ���� ��� answer�� �ֱ�
            if (myTurn(cnt, m) == p - 1)
            {
                answer.push_back(strNum.back());

                // t��ŭ ä������ ����
                if (answer.size() >= t) { return answer; }
            }

            strNum.pop_back();
            ++cnt;
        }

        ++num;
    }

    return answer;
}

int main()
{
    string answer = solution(2, 4, 2, 1);
    cout << answer.c_str();

    return 0;
}