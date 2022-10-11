#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string new_id) 
{
    string answer = "";
    string temp;
    temp = new_id;
    char prev = '0';

    // 7단계 진행
    int phase = 1;
    int size = temp.size();
    while (phase < 8)
    {
        switch (phase)
        {
        case 1: // 대문자를 소문자로 치환
            for (int i = 0; i < size; i++)
            {
                if (isupper(temp[i]))
                {
                    temp[i] += 32;
                }
            }
            break;
        case 2: // 숫자, 소문자, 대문자 '-', '_', '.'를 제외한 나머지 제거
            for (int i = 0; i < size; i++)
            {
                if ((temp[i] >= '0' && temp[i] <= '9') || isalpha(temp[i]) ||
                    temp[i] == '-' || temp[i] == '_' || temp[i] == '.')
                {
                    continue;
                }
                else
                {
                    // 제거 후 인덱스 한 칸씩 당기기
                    for (int k = i; k < size; k++)
                    {
                        temp[k] = temp[k + 1];
                    }
                    size--;
                    i--;
                }
            }
            break;
        case 3: // 연속된 마침표'.'를 하나로 치환
            for (int i = 0; i < size; i++)
            {
                if (prev == '.' && temp[i] == '.')
                {
                    // 제거 후 인덱스 한 칸씩 당기기
                    for (int k = i; k < size; k++)
                    {
                        temp[k] = temp[k + 1];
                    }
                    size--;
                    i--;
                }

                prev = temp[i];
            }
            break;
        case 4: // 처음과 끝이 '.'이라면 제거
            // 처음에 있으면
            if (temp[0] == '.')
            {
                // 제거 후 인덱스 한 칸씩 당기기
                for (int k = 0; k < size; k++)
                {
                    temp[k] = temp[k + 1];
                }
                size--;
            }
            // 마지막에 있으면
            if (temp[size - 1] == '.') { size--; }
            break;
        case 5: // 빈 문자열이면 'a' 대입
            if (size == 0) { temp[0] = 'a'; size++; }
            break;
        case 6: // 길이 16자 이상 제한
            if (size > 15) { size = 15; }
            // 사이즈 제한 후 마지막이 '.' 이라면 제거
            if (temp[size - 1] == '.') { size--; }
            break;
        case 7:
            if (size <= 2)
            {
                for (int i = size; i < 3; i++)
                {
                    temp[i] = temp[size - 1];
                    size++;
                }
            }
            break;
        }

        phase++;
    }

    // 쓰레기값을 제외한 나머지를 answer에 옮기기
    for (int i = 0; i < size; i++)
    {
        answer += temp[i];
    }
    return answer;
}

int main()
{
    string st = "...!@BaT#*..y.abcdefghijklm";

    st = solution(st);

    for (int i = 0; i < st.size(); i++)
    {
        cout << st[i];
    }

    return 0;
}