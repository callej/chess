#include <stdio.h>

#define SHOW_COORDINATES 1

#define BG_WHITE "\x1b[30;47m"
#define BG_BLACK "\x1b[30;100m"
#define NORMAL "\x1b[m"

#define HEIGHT 5
#define WIDTH 11
#define COLS 8
#define ROWS 8

void showFiles()
{
    if (SHOW_COORDINATES)
    {
        printf("\n     ");
        for (int col = 1; col <= COLS; col++)
        {
            for (int w = 1; w <= WIDTH; w++)
            {
                if (w == WIDTH / 2 + 1)
                {
                    printf("%c", 'a' + col - 1);
                }
                else
                {
                    printf(" ");
                }
            }
        }
    }
}

int showRank(int h, int row)
{
    if (SHOW_COORDINATES)
    {
        if (h == HEIGHT / 2)
        {
            if (ROWS - row + 1 < 10)
            {
                printf("\n  %d  ", ROWS - row + 1);
            }
            else
            {
                printf("\n %d  ", ROWS - row + 1);
            }
        }
        else if (h == HEIGHT / 2 + 1)
        {
            if (ROWS - row + 1 < 10)
            {
                printf("  %d\n     ", ROWS - row + 1);
            }
            else
            {
                printf(" %d\n     ", ROWS - row + 1);
            }
        }
        else
        {
            return(0);
        }
    }
    else
    {
        return(0);
    }
    return(1);
}

void drawBoard()
{
    showFiles();
    printf("\n\n     ");
    for (int row = 1; row <= ROWS; row++)
    {
        for (int h = 1; h <= HEIGHT; h++)
        {
            for (int col = 1; col <= COLS; col++)
            {
                for (int w = 1; w <= WIDTH; w++)
                {
                    if ((row + col) % 2 == 0)
                    {
                        printf("%s %s", BG_WHITE, NORMAL);
                    }
                    else
                    {
                        printf("%s %s", BG_BLACK, NORMAL);
                    }
                }
            }
            if (!showRank(h, row))
            {
                printf("\n     ");
            }
        }
    }
    showFiles();
    puts("\n");
}

int main()
{
    drawBoard();
}