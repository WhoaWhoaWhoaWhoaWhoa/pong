#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void ball_move(int ball_pos_X, int ball_pos_Y, int ball_direction, int *new_ball_pos_X, int *new_ball_pos_Y, int *new_ball_direction, int racket1_pos, int racket2_pos);
void print_field(int ball_pos_X, int ball_pos_Y, int racket1_pos, int racket2_pos);
void racket1_move(int *racket1_pos);
void racket2_move(int *racket2_pos);

int main()
{
    int ball_pos_X = 39;
    int ball_pos_Y = 20;
    int ball_direction = 2;
    int new_ball_pos_X, new_ball_pos_Y, new_ball_direction;

    int racket1_pos = 12;
    int racket2_pos = 12;

    print_field(ball_pos_X, ball_pos_Y, racket1_pos, racket2_pos);
    for (int i = 0; i < 50; i++)
    {
        racket1_move(&racket1_pos);
        ball_move(ball_pos_X, ball_pos_Y, ball_direction, &new_ball_pos_X, &new_ball_pos_Y, &new_ball_direction, racket1_pos, racket2_pos);
        print_field(ball_pos_X, ball_pos_Y, racket1_pos, racket2_pos);

        ball_pos_X = new_ball_pos_X;
        ball_pos_Y = new_ball_pos_Y;
        ball_direction = new_ball_direction;

        // racket2_move(&racket2_pos);
        // ball_move(ball_pos_X, ball_pos_Y, ball_direction, &new_ball_pos_X, &new_ball_pos_Y, &new_ball_direction);
        // print_field(ball_pos_X, ball_pos_Y, racket1_pos, racket2_pos);

        // ball_pos_X = new_ball_pos_X;
        // ball_pos_Y = new_ball_pos_Y;
        // ball_direction = new_ball_direction;
    }
}

void racket1_move(int *racket1_pos)
{
    printf("player 1 turn:");
    char command = getchar(); 
    if (command == NULL)
    {
        return;
    }
    
    scanf(" %c", &command);
    if (command == 'a')
    {
        *racket1_pos = *racket1_pos - 3;
    }
    if (command == 'z')
    {
        *racket1_pos = *racket1_pos + 3;
    }
}

void racket2_move(int *racket2_pos)
{
    printf("player 2 turn: ");
    char command;
    scanf(" %c", &command);
    if (command == 'k')
    {
        *racket2_pos = *racket2_pos - 3;
    }
    if (command == 'm')
    {
        *racket2_pos = *racket2_pos + 3;
    }
    printf("\n");
}

void print_field(int ball_pos_X, int ball_pos_Y, int racket1_pos, int racket2_pos)
{
    for (int y = 0; y <= 27; y++)
    {
        for (int x = 0; x <= 82; x++)
        {
            if (x == ball_pos_X && y == ball_pos_Y)
                printf("%c", 'O');
            else if ((x == 1 && (racket1_pos == y || racket1_pos + 1 == y || racket1_pos + 2 == y)) ||
                     (x == 81 && (racket2_pos == y || racket2_pos + 1 == y || racket2_pos + 2 == y)))
                printf("%c", 'H');
            else if (y == 0 || y == 27 || x == 0 || x == 82)
                printf("%c", '*');
            else
                printf("%c", ' ');
        }
        printf("\n");
    }

    printf("\n");
}

void ball_move(int ball_pos_X, int ball_pos_Y, int ball_direction, int *new_ball_pos_X, int *new_ball_pos_Y, int *new_ball_direction, int racket1_pos, int racket2_pos)
{
    if (ball_direction == 0)
    {
        *new_ball_pos_X = ball_pos_X + 4;
        *new_ball_pos_Y = ball_pos_Y - 3;

        if (*new_ball_pos_X >= 81)
        {
            *new_ball_direction = 3;
            *new_ball_pos_X = 81 - (*new_ball_pos_X - 81);
            return;
        }
        if (*new_ball_pos_Y <= 1)
        {
            *new_ball_direction = 1;
            *new_ball_pos_Y = 1 - (abs(*new_ball_pos_Y) - 1);
            return;
        }
        else
        {
            *new_ball_direction = ball_direction;
        }
    }
    if (ball_direction == 1)
    {
        *new_ball_pos_X = ball_pos_X + 4;
        *new_ball_pos_Y = ball_pos_Y + 3;

        if (*new_ball_pos_X >= 81)
        {
            *new_ball_direction = 2;
            *new_ball_pos_X = 81 - (*new_ball_pos_X - 81);
            return;
        }
        if (*new_ball_pos_Y >= 26)
        {
            *new_ball_direction = 0;
            *new_ball_pos_Y = 26 - (*new_ball_pos_Y - 26);
            return;
        }
        else
        {
            *new_ball_direction = ball_direction;
        }
    }
    if (ball_direction == 2)
    {
        *new_ball_pos_X = ball_pos_X - 4;
        *new_ball_pos_Y = ball_pos_Y + 3;

        if (*new_ball_pos_X <= 2 && (racket1_pos == *new_ball_pos_Y || racket1_pos+1 == *new_ball_pos_Y || racket1_pos+2 == *new_ball_pos_Y))
        {
            *new_ball_direction = 1;
            *new_ball_pos_X = 2 + (abs(*new_ball_pos_X));
            return;
        }
        if (*new_ball_pos_Y >= 26)
        {
            *new_ball_direction = 3;
            *new_ball_pos_Y = 26 - (*new_ball_pos_Y - 26);
            return;
        }
        else
        {
            *new_ball_direction = ball_direction;
        }
    }
    if (ball_direction == 3)
    {
        *new_ball_pos_X = ball_pos_X - 4;
        *new_ball_pos_Y = ball_pos_Y - 3;

        if (*new_ball_pos_X <= 2 && (racket1_pos == *new_ball_pos_Y || racket1_pos+1 == *new_ball_pos_Y || racket1_pos+2 == *new_ball_pos_Y))
        {
            *new_ball_direction = 0;
            *new_ball_pos_X = 2 + (abs(*new_ball_pos_X));
            return;
        }
        if (*new_ball_pos_Y <= 1)
        {
            *new_ball_direction = 2;
            *new_ball_pos_Y = 1 - (abs(*new_ball_pos_Y) - 1);
            return;
        }
        else
        {
            *new_ball_direction = ball_direction;
        }
    }
}