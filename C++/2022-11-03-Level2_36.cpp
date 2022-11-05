#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

bool solution(vector<string> phone_book)
{
    bool answer = true;

    // 길이가 큰 번호가 작은 번호의 접두어가 될 수 없다. (string 사전순 정렬)
    sort(phone_book.begin(), phone_book.end());

    // 작은 번호 i와 i+1의 size만큼 비교
    for (int i = 0; i < phone_book.size() - 1; ++i)
    {
        string temp = phone_book[i+1].substr(0, phone_book[i].size());

        if (phone_book[i] == temp) { return false; }
    }

    return answer;
}

// --------------------------------- 효율성 3,4 실패 -------------------------------------
bool solutionFail(vector<string> phone_book)
{
    bool answer = true;

    // 길이가 큰 번호가 작은 번호의 접두어가 될 수 없다. (size에 대한 오름차순 정렬)
    sort(phone_book.begin(), phone_book.end());

    // 작은 번호 i와 i의 size만큼 j에 대해 비교
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