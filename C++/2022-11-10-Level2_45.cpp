#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// head가 같으면 number의 작은 것부터
bool myCompare(pair<pair<string, string>, int> a, 
    pair<pair<string, string>, int> b)
{
    if (a.first.first == b.first.first) 
    { 
        return stoi(a.first.second) < stoi(b.first.second); 
    }
    else  { return a < b; }
}

vector<string> solution(vector<string> files)
{
    vector<pair<pair<string, string>, int>> data; // (head, number, order)
    vector<string> answer(files.size());

    for (int i = 0; i < files.size(); ++i)
    {
        pair<pair<string, string>, int> temp;
        string current = "";
        int trigger = 0; // head와 number 구분
        temp.second = i;

        for (int j = 0; j < files[i].size(); ++j)
        {
            if (trigger == 0)   // head
            {
                if (files[i][j] >= '0' && files[i][j] <= '9')
                {
                    temp.first.first = current;
                    current = "";
                    ++trigger;
                }
            }
            else if (trigger == 1)  // number
            {
                if (files[i][j] < '0' || files[i][j] > '9')
                {
                    temp.first.second = current;
                    current = "";
                    ++trigger;
                    break;
                }
            }
            current += toupper(files[i][j]);    // 대문자 통일
        }
        if (trigger == 1) { temp.first.second = current; }  // 끝에 도달시
        
        data.push_back(temp);
    }

    // 기존의 순서 보장하는 정렬
    stable_sort(data.begin(), data.end(), myCompare);

    // answer의 인덱스에 data.second의 값에 맞게 대입하기
    for (int i = 0; i < data.size(); ++i)
    {
        answer[i] = files[data[i].second];
    }

    return answer;
}

int main()
{
    vector<string> files = { "img12.png", "img10.png", "img02.png", "img1.png", "IMG01.GIF", "img2.JPG" };
    vector<string> answer = solution(files);

    for (string i : answer)
    {
        cout << i.c_str() << ' ';
    }

    return 0;
}
