#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k)
{
    vector<int> answer(id_list.size());
    unordered_map<string, unordered_set<string>> reportMap;
    unordered_map<string, unordered_set<string>> resultMap;

    // 신고 건수 만큼 반복
    for (int i = 0; i < report.size(); i++)
    {
        // 공백 찾기
        int splitIdx = 0;
        for (int j = 0; j < report[i].size(); j++)
        {
            if (report[i][j] == ' ')
            {
                splitIdx = j;
            }
        }

        // 신고자와 대상 분리
        string reporter = "";
        string reported = "";
        for (int j = 0; j < splitIdx; j++) { reporter += report[i][j]; }
        for (int j = splitIdx + 1; j < report[i].size(); j++) { reported += report[i][j]; }

        // 신고 map 채우기
        reportMap[reporter].insert(reported);
        resultMap[reported].insert(reporter);
    }

    // 신고 결과 카운트
    for (int i = 0; i < id_list.size(); i++)
    {
        auto it = reportMap.find(id_list[i]);
        if (it == reportMap.end()) { continue; }

        for (string target : it->second)
        {
            if (resultMap[target].size() >= k)
            {
                answer[i]++;
            }
        }
    }

    return answer;
}
int main()
{
    vector<string> id_list = { "muzi", "frodo", "apeach", "neo" };
    vector<string> report = { "muzi frodo", "apeach frodo", "frodo neo", "muzi neo", "apeach muzi" };
    int k = 2;

    vector<int> result = solution(id_list, report, k);
    for (int i = 0; i < result.size(); i++) 
    {
        cout << result[i] << '\n';
    }

    return 0;
}