#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

bool solution(vector<string> phone_book)
{
    bool answer = true;

    // ���̰� ū ��ȣ�� ���� ��ȣ�� ���ξ �� �� ����. (string ������ ����)
    sort(phone_book.begin(), phone_book.end());

    // ���� ��ȣ i�� i+1�� size��ŭ ��
    for (int i = 0; i < phone_book.size() - 1; ++i)
    {
        string temp = phone_book[i+1].substr(0, phone_book[i].size());

        if (phone_book[i] == temp) { return false; }
    }

    return answer;
}

// --------------------------------- ȿ���� 3,4 ���� -------------------------------------
bool solutionFail(vector<string> phone_book)
{
    bool answer = true;

    // ���̰� ū ��ȣ�� ���� ��ȣ�� ���ξ �� �� ����. (size�� ���� �������� ����)
    sort(phone_book.begin(), phone_book.end());

    // ���� ��ȣ i�� i�� size��ŭ j�� ���� ��
    for (int i = 0; i < phone_book.size() - 1; ++i)
    {
        for (int j = i + 1; j < phone_book.size(); ++j)
        {
            string temp = phone_book[j].substr(0, phone_book[i].size());

            if (phone_book[i] == temp) { return false; }
        }
    }

    return answer;
}
// ----------------------------------------------------------------------------------------

int main()
{
    vector<string> phone_book = 
    { 
        "119",
        "97674223",
        "1195524421"
    };
    bool answer = solution(phone_book);
    cout << answer;

    return 0;
}