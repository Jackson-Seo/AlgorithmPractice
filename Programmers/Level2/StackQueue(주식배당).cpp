#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices) {

    vector<int> answer;
    answer.reserve(prices.size() - 1);
    for (int i = 0; i < prices.size(); i++)
    {
        int j = i;
        int tmp;
        while (j < prices.size())
        {
            if (prices[j] - prices[i] < 0)
            {
                break;
            }
            else
            {
                j++;
            }

        }

        if (j == prices.size())
            answer.push_back(j - i - 1);

        else
            answer.push_back(j - i);

    }

    return answer;

}