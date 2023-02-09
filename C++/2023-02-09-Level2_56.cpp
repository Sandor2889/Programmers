#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// �ݷ� ���ǵ��� ��� ���� �Ұ�
bool myCompare_fail(const string& a, const string& b)
{
    int idx = 0;

    while (true)
    {
        if (idx < a.size() && idx < b.size())
        {
            // �����ڸ� ���� ��
            if (a[idx] == b[idx]) { ++idx; }
            else { return a[idx] > b[idx]; }        }
        else
        {
            // ����� ���� ���� idx-1�� �� �� �ٸ� ���� ������ ���� ��
            if (idx >= a.size()) { return a[idx - 1] > b[b.size()-1]; }
            else if (idx >= b.size()) { return a[a.size()-1] > b[idx - 1]; }
        }
    }
}

// �׳�.. �� string�� �ڸ� �ٲ㺸�� ���ؼ� ū ���� �����ϸ� �ȴ�...
bool myCompare(const string& a, const string& b)
{
    return a + b > b + a;
}

string solution(vector<int> numbers)
{
    string answer = "";
    vector<string> strNums;

    // string���� �ٲٱ�
    for (int i = 0; i < numbers.size(); ++i)
    {
        strNums.push_back(to_string(numbers[i]));
    }

    // ��������(+ ���� ó��) ����
    sort(strNums.begin(), strNums.end(), myCompare);

    // answer�� ������� ���ϱ�
    for (int i = 0; i < strNums.size(); ++i) { answer += strNums[i]; }

    // 0�� ���� ����ó��
    if ( answer[0] == '0') { return "0"; }

    return answer;
}

int main()
{
    vector<int> numbers = { 0, 0, 0 };

    string answer = solution(numbers);

    for (char c : answer)
    {
        cout << c;
    }

    return 0;
}