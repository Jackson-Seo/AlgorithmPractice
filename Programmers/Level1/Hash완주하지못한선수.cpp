#include <string>
#include <vector>

using namespace std;

int hashfunction(string name)
{
    return int(name.at(0)) - 97;
}

class slot
{
public:
    slot();
    string name;
    slot* next;
};

slot::slot()
{
    name = "";
    next = NULL;
}


string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    vector<slot*> hashtable;
    hashtable.assign(26, NULL);

    int key = 0;
    for (int i = 0; i < participant.size(); i++)
    {
        key = hashfunction(participant[i]);
        if (hashtable[key] == NULL)
        {
            hashtable[key] = new slot;
            hashtable[key]->name = participant[i];
            hashtable[key]->next = NULL;
        }

        else
        {
            if (hashtable[key]->next == NULL)
            {
                hashtable[key]->next = new slot;
                hashtable[key]->next->name = participant[i];
                hashtable[key]->next->next = NULL;
            }

            else
            {
                slot* tmp = new slot;
                tmp->name = participant[i];
                tmp->next = hashtable[key]->next;
                hashtable[key]->next = tmp;
            }
        }
    }

    slot* iter;
    for (int j = 0; j < completion.size(); j++)
    {
        key = hashfunction(completion[j]);
        iter = hashtable[key];
        do
        {
            if (iter == NULL)
                break;

            if (iter->name == completion[j])
            {
                iter->name = "Complete";
                break;
            }

            iter = iter->next;
        } while (iter != NULL);
    }

    iter = NULL;
    for (int k = 0; k < hashtable.size(); k++)
    {
        iter = hashtable[k];
        do
        {
            if (iter == NULL)
                break;
            if (iter->name != "Complete")
            {
                answer = iter->name;
                return answer;
            }
            iter = iter->next;
        } while (iter != NULL);
    }

    return answer;
}