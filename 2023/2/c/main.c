// https://adventofcode.com/2023/day/2

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_BUFF_LENGTH 256

int part1(char buff[MAX_BUFF_LENGTH], FILE *fp)
{
    unsigned int res = 0;
    int lineNumber = 1;

    while (fgets(buff, MAX_BUFF_LENGTH, fp) != NULL)
    {
        int buf_len = strlen(buff);
        bool isStart = false;
        int score = 0;
        int scoreDigits = 0;
        for (int i = 6; i < buf_len; i++)
        {
            if (!isStart && buff[i] != ':')
            {
                continue;
            }
            if (!isStart)
            {
                isStart = true;
                i += 2;
            }
            if (buff[i] >= '0' && buff[i] <= '9')
            {
                if (scoreDigits > 0)
                {
                    score *= 10;
                }
                score += buff[i] - '0';
                scoreDigits++;
                continue;
            }

            if (buff[i] == 'r')
            {
                if (score > 12)
                {
                    break;
                }
                i += 2;
            }
            else if (buff[i] == 'g')
            {
                if (score > 13)
                {
                    break;
                }
                i += 4;
            }
            else if (buff[i] == 'b')
            {
                if (score > 14)
                {
                    break;
                }
                i += 3;
            }
            if (i == (buf_len - 1))
            {
                res += lineNumber;
                break;
            }

            // reset score and scoreDigits
            if (buff[i] == ',' || buff[i] == ';')
            {
                score = 0;
                scoreDigits = 0;
            }
        }
        lineNumber++;
        memset(buff, 0, MAX_BUFF_LENGTH);
    }
    return res;
}

int part2(char buff[MAX_BUFF_LENGTH], FILE *fp)
{
    fseek(fp, 0, SEEK_SET);
    unsigned int res = 0;

    while (fgets(buff, MAX_BUFF_LENGTH, fp))
    {
        int buf_len = strlen(buff);
        bool isStart = false;
        int score = 0;
        int scoreDigits = 0;
        int minRed = 0;
        int minGreen = 0;
        int minBlue = 0;

        for (int i = 6; i < buf_len; i++)
        {
            if (!isStart && buff[i] != ':')
            {
                continue;
            }
            if (!isStart)
            {
                isStart = true;
                i += 2;
            }
            if (buff[i] >= '0' && buff[i] <= '9')
            {
                if (scoreDigits > 0)
                {
                    score *= 10;
                }
                score += buff[i] - '0';
                scoreDigits++;
                continue;
            }

            if (buff[i] == 'r')
            {
                if (score > minRed)
                {
                    minRed = score;
                }
                i += 2;
            }
            else if (buff[i] == 'g')
            {
                if (score > minGreen)
                {
                    minGreen = score;
                }
                i += 4;
            }
            else if (buff[i] == 'b')
            {
                if (score > minBlue)
                {
                    minBlue = score;
                }
                i += 3;
            }
            if (i == (buf_len - 1))
            {
                res += (minRed * minGreen * minBlue);
                break;
            }

            // reset score and scoreDigits
            if (buff[i] == ',' || buff[i] == ';')
            {
                score = 0;
                scoreDigits = 0;
            }
        }
        memset(buff, 0, MAX_BUFF_LENGTH);
    }
    return res;
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

    sum1 = part1(buff, fp);
    sum2 = part2(buff, fp);
    fclose(fp);

    printf("Result 1: %d\n", sum1);
    printf("Result 2: %d\n", sum2);
    return 0;
}