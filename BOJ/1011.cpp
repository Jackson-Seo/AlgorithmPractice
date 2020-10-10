#include <iostream>
using namespace std;

int main(void)
{
    int T;
    cin >> T;

    for (int i = 0; i < T; i++)
    {
        unsigned int x;
        unsigned int y;
        cin >> x >> y;
        unsigned int distance = y - x;

        if (distance < 4)
        {
            cout << distance << "\n";
            continue;
        }

        int MovementMax = 1;
        while ((MovementMax * MovementMax) <= distance)
        {
            MovementMax++;
        }

        MovementMax -= 1;

        if (MovementMax * MovementMax == distance)
            cout << 2 * MovementMax - 1 << "\n";
        else if (MovementMax * MovementMax + MovementMax < distance)
            cout << 2 * MovementMax + 1 << "\n";
        else
            cout << 2 * MovementMax << "\n";

    }

    return 0;
}