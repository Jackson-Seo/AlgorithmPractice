#include <iostream>

int CheckMine(bool** MineCraft, int i, int j, int size);

int main(void)
{
    int R, C;
    int MaxSize = 0;
    bool checkNoDiamond = true;
    bool overFlowUpperBound = true;
    bool overFlowRowBound = true;

    std::cin >> R >> C;

    int RowLen = C + 1;
    char* MineRow = new char[RowLen];
    bool** MineCraft = new bool* [R];
    for (int i = 0; i < R; i++)
    {
        MineCraft[i] = new bool[C];
        std::cin >> MineRow;
        std::cin.get();

        for (int j = 0; j < C; j++)
        {
            if (MineRow[j] == '0')
                MineCraft[i][j] = 0;
            else
                MineCraft[i][j] = 1;

            if (checkNoDiamond && (MineCraft[i][j] == 1))
            {
                ++MaxSize;
                checkNoDiamond = false;
            }
        }
    }

    int upperBoundSize = 0;
    int columnBoundSize = 0;
    for (int i = 0; i < R; i++)
    {
        overFlowRowBound = true;
        columnBoundSize = 0;
        if (overFlowUpperBound)
        {
            upperBoundSize++;
            if (overFlowUpperBound && (upperBoundSize > R - upperBoundSize))
            {
                upperBoundSize = R - upperBoundSize;
                overFlowUpperBound = false;
            }

            for (int j = 0; j < C; j++)
            {
                if (overFlowRowBound && (columnBoundSize > C - columnBoundSize))
                {
                    columnBoundSize = C - columnBoundSize;
                    overFlowRowBound = false;
                }

                else
                {
                    if (overFlowRowBound)
                    {
                        if ((upperBoundSize < MaxSize) || (columnBoundSize < MaxSize))
                        {
                            columnBoundSize++;
                            continue;
                        }


                        else
                        {
                            int index = MaxSize;
                            if (upperBoundSize > columnBoundSize)
                            {
                                while (index <= columnBoundSize)
                                {
                                    if (CheckMine(MineCraft, i, j, index))
                                    {
                                        if (MaxSize < index)
                                            MaxSize = index;

                                    }

                                    index++;
                                }
                                columnBoundSize++;
                            }

                            else
                            {
                                while (index <= upperBoundSize)
                                {
                                    if (CheckMine(MineCraft, i, j, index))
                                    {
                                        if (MaxSize < index)
                                            MaxSize = index;

                                    }

                                    index++;
                                }
                                columnBoundSize++;
                            }

                        }

                    }

                    else
                    {
                        if ((upperBoundSize < MaxSize) || (columnBoundSize < MaxSize))
                        {
                            columnBoundSize--;
                            continue;
                        }


                        else
                        {
                            int index = MaxSize;
                            if (upperBoundSize > columnBoundSize)
                            {
                                while (index <= columnBoundSize)
                                {
                                    if (CheckMine(MineCraft, i, j, index))
                                    {
                                        if (MaxSize < index)
                                            MaxSize = index;

                                    }

                                    index++;
                                }
                                columnBoundSize--;
                            }

                            else
                            {
                                while (index <= upperBoundSize)
                                {
                                    if (CheckMine(MineCraft, i, j, index))
                                    {
                                        if (MaxSize < index)
                                            MaxSize = index;

                                    }

                                    index++;
                                }
                                columnBoundSize--;
                            }

                        }
                    }

                }

            }

        }

        else
        {
            upperBoundSize--;
            for (int j = 0; j < C; j++)
            {
                if (overFlowRowBound && (columnBoundSize > C - columnBoundSize))
                {
                    columnBoundSize = C - columnBoundSize;
                    overFlowRowBound = false;
                }

                else
                {
                    if (overFlowRowBound)
                    {

                        if ((upperBoundSize < MaxSize) || (columnBoundSize < MaxSize))
                        {
                            columnBoundSize++;
                            continue;
                        }


                        else
                        {
                            int index = MaxSize;
                            if (upperBoundSize > columnBoundSize)
                            {
                                while (index <= columnBoundSize)
                                {
                                    if (CheckMine(MineCraft, i, j, index))
                                    {
                                        if (MaxSize < index)
                                            MaxSize = index;

                                    }

                                    index++;
                                }
                                columnBoundSize++;
                            }

                            else
                            {
                                while (index <= upperBoundSize)
                                {
                                    if (CheckMine(MineCraft, i, j, index))
                                    {
                                        if (MaxSize < index)
                                            MaxSize = index;

                                    }
                                    index++;
                                }
                                columnBoundSize++;
                            }

                        }

                    }

                    else
                    {

                        if ((upperBoundSize < MaxSize) || (columnBoundSize < MaxSize))
                        {
                            columnBoundSize--;
                            continue;
                        }


                        int index = MaxSize;
                        if (upperBoundSize > columnBoundSize)
                        {
                            while (index <= columnBoundSize)
                            {
                                if (CheckMine(MineCraft, i, j, index))
                                {
                                    if (MaxSize < index)
                                        MaxSize = index;

                                }
                            }
                            columnBoundSize--;
                        }

                        else
                        {
                            while (index <= upperBoundSize)
                            {
                                if (CheckMine(MineCraft, i, j, index))
                                {
                                    if (MaxSize < index)
                                        MaxSize = index;

                                }
                            }
                            columnBoundSize--;
                        }
                    }

                }

            }
        }


    }

    if (MaxSize != 0)
        std::cout << MaxSize + 1;
    else
        std::cout << MaxSize;

    return 0;
}

int CheckMine(bool** MineCraft, int i, int j, int size)
{
    if (size == 1)
    {
        if (MineCraft[i][j] == 1)
            return 1;
        else
            return 0;
    }

    int halfLenMine = size;

    if (MineCraft[i - halfLenMine][j] & MineCraft[i + halfLenMine][j])
    {
        if (CheckMine(MineCraft, i, j - 1, size - 1))
            CheckMine(MineCraft, i, j + 1, size - 1);
        else
            return 0;
    }

    else
    {
        return 0;
    }
}