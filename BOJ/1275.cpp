#include <iostream>

int main(void)
{
    int N, Q;
    int Qindex = 0;
    std::cin >> N >> Q;
    long* arr = new long[N + Q];
    for (int index = 0; index < N; index++)
    {
        std::cin >> arr[index];
    }

    std::cin.get();

    int x, y;
    int a;
    long b;
    int i, j;

    while (Q > Qindex)
    {
        arr[N + Qindex] = 0;

        std::cin >> x >> y;
        if (x <= y)
        {
            for (i = x - 1; i < y; i++)
            {
                arr[N + Qindex] += arr[i];
            }
        }

        else
        {
            for (j = y - 1; j < x; j++)
            {
                arr[N + Qindex] += arr[j];
            }
        }

        std::cin >> a >> b;
        arr[a - 1] = b;
        Qindex++;
    }

    for (int k = N; k < N + Q; k++)
    {
        std::cout << arr[k] << "\n";
    }

    delete[] arr;

    return 0;
}