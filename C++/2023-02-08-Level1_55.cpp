#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

vector<int> solution(string today, vector<string> terms, vector<string> privacies)
{
    vector<int> answer;
    map<char, int> terms_map; // (��� ����, �� ��)

    const int month = 12;
    const int day = 28;

    // Key�� ��� ����, Value�� �� ���� map�� ���� 
    for (int i = 0; i < terms.size(); ++i)
    {
        char alpha = terms[i][0];
        string monthStr = terms[i].substr(2, terms[i].size());
        int days = stoi(monthStr) * day;

        terms_map.insert({ alpha, days });
    }

    // ���� ��¥�� �� �� �� ���ϱ�
    int today_year = stoi(today.substr(1, 3));
    int today_month = stoi(today.substr(5, 6));
    int today_day = stoi(today.substr(8, 9));
    int today_total = (today_year * month * day) + ((today_month-1) * day) + today_day;

    for (int i = 0; i < privacies.size(); ++i)
    {
        // ���� ���� ���� ������ �� �� �� ���ϱ�
        int privacies_year = stoi(privacies[i].substr(1, 3));
        int privacies_month = stoi(privacies[i].substr(5, 6));
        int privacies_day = stoi(privacies[i].substr(8, 9));
        int privacies_total = (privacies_year * month * day) + ((privacies_month-1) * day) + privacies_day;

        char privacies_alpha = privacies[i][11];

        int deadLine = privacies_total + terms_map[privacies_alpha];

        // ������ �� ���������� ��ǥ�Ⱓ üũ
        if (today_total >= deadLine) { answer.push_back(i+1); }
    }

    return answer;
}

int main()
{
    string today = "2022.05.19";
    vector<string> terms = { "A 6", "B 12", "C 3" };
    vector<string> privacies = { "2021.05.02 A", "2021.07.01 B", "2022.02.19 C", "2022.02.20 C" };

    vector<int> answer = solution(today, terms, privacies);

    return 0;
}