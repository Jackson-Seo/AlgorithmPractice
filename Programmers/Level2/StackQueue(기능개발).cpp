/*
(100 - 진행률)%속도==0 이면 (100-진행률)/속도 후에 배포가능
(100 - 진행률)%속도!=0 이면 (100-진행률)/속도 + 1 후에 배포가능
이전 작업이 완료되어야 뒤에 오는 작업이 배포 가능
progresses : n개의 작업
*/


#include <string>
#include <vector>
#include <stack>

using namespace std;

//각 배포마다 몇 개의 기능이 배포되는가
vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    stack<int> stk;

    int Dday = 0;
    int resultDday = 1;
    for (int i = 0; i < progresses.size(); i++)
    {
        Dday = (100 - progresses[i]) % speeds[i] ? ((100 - progresses[i]) / speeds[i]) + 1 : (100 - progresses[i]) / speeds[i];
        if (stk.empty())
            stk.push(Dday);

        else
        {
            if (stk.top() >= Dday)
            {
                resultDday++;
            }

            else
            {
                answer.push_back(resultDday);
                resultDday = 1;
                stk.pop();
                stk.push(Dday);
            }

        }


    }

    answer.push_back(resultDday);

    return answer;
}