// https://adventofcode.com/2023/day/1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFF_LENGTH 128

int part1(char buff[MAX_BUFF_LENGTH])
{
    char firstDigit = -1;
    char secondDigit = -1;

    for (int i = 0; i < strlen(buff) - 1; i++)
    {
        if (buff[i] < '0' || buff[i] > '9')
            continue;

        if (firstDigit == -1)
        {
            firstDigit = buff[i] - '0';
        }
        secondDigit = buff[i] - '0';
    }

    return firstDigit * 10 + secondDigit;
}

int part2(char buff[MAX_BUFF_LENGTH])
{
    const char *digitLetters[] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    char firstDigit = -1;
    char secondDigit = -1;

    for (int i = 0; i < strlen(buff) - 1; i++)
    {
        if (buff[i] >= '0' && buff[i] <= '9')
        {
            if (firstDigit == -1)
            {
                firstDigit = buff[i] - '0';
            }
            secondDigit = buff[i] - '0';
            continue;
        }

        for (int j = 0; j < 9; j++)
        {
            int len = strlen(digitLetters[j]);
            int k = 0; // char counter
            while (k < len)
            {
                if (buff[i + k] != digitLetters[j][k])
                {
                    break;
                }
                k++;
            }
            if (k != len)
            {
                continue;
            }
            if (firstDigit == -1)
            {
                firstDigit = j + 1;
            }
            secondDigit = j + 1;
        }
    }
    // printf("\n%s first: %i, second: %i\n", buff, firstDigit, secondDigit);

    return firstDigit * 10 + secondDigit;
}

int main()
{
    char buff[MAX_BUFF_LENGTH];
    unsigned int sum1 = 0;
    unsigned int sum2 = 0;

    FILE *fp = fopen("../input.txt", "r");
    if (fp == NULL)
    {
        return -1;
    }

    while (fgets(buff, MAX_BUFF_LENGTH, fp) != NULL)
    {
        sum1 += part1(buff);
        sum2 += part2(buff);
        memset(buff, 0, sizeof(buff));
    }
    fclose(fp);

    printf("Result 1: %d\n", sum1);
    printf("Result 2: %d\n", sum2);
    return 0;
}