#include <stdio.h>

int policeThief(char city[4][4], int k){
    int count = 0;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (city[i][j] == 'P')
            {
                city[i][j] = 'F';
                for (int x = j - k; x <= j + k; x++)
                {
                    if (x >= 0 && x < 4 && city[i][x] == 'T')
                    {
                        city[i][x] = 'X';
                        count++;
                        break;
                    }
                }

                for (int y = i - k; y <= i; y++)
                {
                    if (y >= 0 && y < 4 && city[y][j] == 'T')
                    {
                        city[y][j] = 'X';
                        count++;
                        break;
                    }
                }
            }
        }
    }
    
    return count;
}

int main()
{
    char city[4][4] = {{'T', 'P', 'T', 'T'},
                       {'T', 'P', 'T', 'P'},
                       {'P', 'P', 'P', 'T'},
                       {'T', 'T', 'T', 'T'}};

    int k = 2;
    int ret = policeThief(city, k);
    
    printf("\n Number of thieves caught in horizontal and upward direction are:->%d \n", ret);


}

