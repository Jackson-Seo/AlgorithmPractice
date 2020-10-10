#include <string>
#include <vector>

const int MAX = 8;
using namespace std;


int solution(int N, int number) {
    vector<vector<int>> answer;
    vector<int> v1, v2;
    v1.push_back(N);
    v2.push_back(0);
    v2.push_back(1);
    v2.push_back(N + N);
    v2.push_back(N * N);
    v2.push_back(N * 10 + N);
    answer.push_back(v1);
    answer.push_back(v2);

    if (N == number)
        return 1;

    for (int b = 0; b < answer[1].size(); b++)
    {
        if (answer[1][b] == number)
            return 2;
    }

    int len = 3;
    while (len <= MAX)
    {
        vector<int> v;
        int tmpMax = N;
        int total = N;
        for (int t = 1; t < len; t++)
        {
            tmpMax *= 10;
            total += tmpMax;
        }
        v.push_back(total);
        for (int p = 1; p < len / 2 + 1; p++)
        {
            for (int i = 0; i < answer[p - 1].size(); i++)
            {
                for (int j = 0; j < answer[len - p - 1].size(); j++)
                {
                    int tmp[4];
                    tmp[0] = answer[p - 1][i] + answer[len - p - 1][j];
                    tmp[1] = answer[p - 1][i] - answer[len - p - 1][j];
                    tmp[2] = answer[p - 1][i] * answer[len - p - 1][j];
                    if (answer[len - p - 1][j] != 0 && answer[p - 1][i] != 0)
                    {
                        if (answer[p - 1][i] > answer[len - p - 1][j])
                            tmp[3] = answer[p - 1][i] / answer[len - p - 1][j];
                        else
                            tmp[3] = answer[len - p - 1][j] / answer[p - 1][i];
                    }


                    for (int k = 0; k < 4; k++)
                    {
                        if (tmp[k] > 0)
                        {
                            if (tmp[k] == number)
                                return len;
                            else
                                v.push_back(tmp[k]);
                        }

                    }

                }


            }

        }
        answer.push_back(v);
        len++;
    }
    return -1;
}