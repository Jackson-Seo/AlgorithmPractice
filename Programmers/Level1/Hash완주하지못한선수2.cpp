#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    vector<string> v1(participant);
    vector<string> v2(completion);
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    string answer = "";

    for (int i = 0; i < v2.size(); i++)
    {
        if (v1[i] != v2[i])
        {
            answer = v1[i];
            return answer;
        }
    }
}