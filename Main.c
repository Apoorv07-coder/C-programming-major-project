// #include <stdio.h>
// #include <stdlib.h>
// #include<time.h>

// #define WIDTH 20
// #define HEIGHT 10 

// //Game field dimensions defined and can be changed by user jo man kare
// int left_p_y = HEIGHT / 2;
// int right_p_y = HEIGHT / 2;
// int ball_x = WIDTH / 2;
// int ball_y = HEIGHT / 2;
// int ball_dx = 1;//Direction variables
// int ball_dy = 1;//Direction Variables
// void delay(int milliseconds) {
//     clock_t start = clock();
//     while (clock() < start + milliseconds * (CLOCKS_PER_SEC / 1000));
// }
// // Draw the game field and represents it completely for one frame and then it changes
// void draw_field() {
//     int x, y;
    
//     #ifdef _WIN32
//     system("cls"); // cls is to clear per frame 
//     #endif

//     for (y = 0; y < HEIGHT; y++) {
//         for (x = 0; x < WIDTH; x++) {
//             // Top and bottom borders
//             if (y == 0 || y == HEIGHT - 1)
//             {
//                 putchar('-');
//             } 
//             // Right and left borders
//             else if (x == 0 || x == WIDTH - 1) 
//             {
//                 putchar('|');
//             } 
//             // Left paddle dimesions drawn (hitbox)
//             else if (x == 1 && (y == left_p_y || y == left_p_y - 1 || y == left_p_y + 1)) 
//             {
//                 putchar('|');
//             } 
//             // Right paddle dimensions drawn (hitbox)
//             else if (x == WIDTH - 2 && (y == right_p_y || y == right_p_y - 1 || y == right_p_y + 1)) 
//             {
//                 putchar('|');
//             }
//             // Draw ball 
//             else if (x == ball_x && y == ball_y) 
//             {
//                 putchar('O');
//             } 
//             // Beech ke area ka khali space
//             else 
//             {
//                 putchar(' ');
//             }
//         }
//         putchar('\n');
//     }
// }

// // Update ball position and handle collisions
// void update_ball() 
//     {
//     int next_x = ball_x + ball_dx;
//     int next_y = ball_y + ball_dy;

//     // Bounce off top/bottom walls
//     if (next_y == 0 || next_y == HEIGHT - 1) {
//         ball_dy = -ball_dy;// Reverse direction
//         next_y = ball_y + ball_dy;
//     }

//     // Bounce off left paddle
//     if (next_x == 2) {
//         if (next_y >= left_p_y - 1 && next_y <= left_p_y + 1) 
//         {
//             ball_dx = -ball_dx;
//             next_x = ball_x + ball_dx;
//         }
//         else 
//         {
//             printf("Right player scores!\n");
//             exit(0);
//         }
//     }

//     // Bounce off right paddle
//     if (next_x == WIDTH - 3) 
//     {
//         if (next_y >= right_p_y - 1 && next_y <= right_p_y + 1) 
//         {
//             ball_dx = -ball_dx;
//             next_x = ball_x + ball_dx;
//         }
//         else 
//         {
//             printf("Left player scores!\n");
//             exit(0);
//         }
//     }

//     ball_x = next_x;
//     ball_y = next_y;
// }

// // Handle left input (Player 1)
// void move_left_p(char input) 
//     {
//     if ((input == 'w' || input == 'W') && left_p_y > 1) 
//     {
//         left_p_y--;
//     }
//     else if ((input == 's' || input == 'S') && left_p_y < HEIGHT - 2) 
//     {
//         left_p_y++;
//     }
// }

// // Handle right input (Player 2)
// void move_right_p(char input) 
// {
//     if ((input == 'i' || input == 'I') && right_p_y > 1) 
//     {
//         right_p_y--;
//     } 
//     else if ((input == 'k' || input == 'K') && right_p_y < HEIGHT - 2) {
//         right_p_y++;
//     }
// }

// int main() {
//     char input_left, input_right;

//     while (1) {
//         draw_field();

//         printf("Left Paddle (Player 1): 'w' (up), 's' (down), 'q' to quit\n");
//         printf("Right Paddle (Player 2): 'o' (up), 'k' (down), 'q' to quit\n");

//         printf("Player 1 move: ");
//         input_left = getchar();
//         while (getchar() != '\n');//getchar() not equal removes the extra character

//         if (input_left == 'q' || input_left == 'Q') 
//         {
//             printf("Game quit.\n");
//             break;
//         }
//         move_left_p(input_left);

//         printf("Player 2 move: ");
//         input_right = getchar();
//         while (getchar() != '\n'); //getchar() not equal removes the character to get smooth input

//         move_right_p(input_right);

//         update_ball();
//         delay(100);
//     }

//     return 0;
// }


// #include <stdio.h>
// #include <stdlib.h>
// #include <time.h>

// #define WIDTH 20
// #define HEIGHT 10
// #define WIN_SCORE 3

// // Paddle properties
// int left_p_x = 1, left_p_y = HEIGHT / 2;
// int right_p_x = WIDTH - 2, right_p_y = HEIGHT / 2;
// int ball_x = WIDTH / 2, ball_y = HEIGHT / 2;
// int ball_dx = 1, ball_dy = 1;

// int left_score = 0, right_score = 0;

// // Delay in milliseconds
// void delay(int milliseconds) {
//     clock_t start = clock();
//     while (clock() < start + milliseconds * (CLOCKS_PER_SEC / 1000));
// }

// void reset_ball() {
//     ball_x = WIDTH / 2;
//     ball_y = HEIGHT / 2;
//     ball_dx = (ball_dx > 0) ? -1 : 1;
//     ball_dy = (ball_dy > 0) ? -1 : 1;
// }

// void draw_field() {
//     int x, y;

//     #ifdef _WIN32
//     system("cls");
//     #endif

//     // Scoreboard
//     printf("Score: Player 1 [%d] - [%d] Player 2\n", left_score, right_score);

//     for (y = 0; y < HEIGHT; y++) {
//         for (x = 0; x < WIDTH; x++) {
//             if (y == 0 || y == HEIGHT - 1)
//                 putchar('-');
//             else if (x == 0 || x == WIDTH - 1)
//                 putchar('|');
//             // Left paddle (3 vertical, 3 horizontal blocks)
//             else if (((x == left_p_x && (y == left_p_y || y == left_p_y - 1 || y == left_p_y + 1)) ||
//                       (y == left_p_y && (x == left_p_x - 1 || x == left_p_x + 1))))
//                 putchar('#');
//             // Right paddle (3 vertical, 3 horizontal blocks)
//             else if (((x == right_p_x && (y == right_p_y || y == right_p_y - 1 || y == right_p_y + 1)) ||
//                       (y == right_p_y && (x == right_p_x - 1 || x == right_p_x + 1))))
//                 putchar('#');
//             else if (x == ball_x && y == ball_y)
//                 putchar('O');
//             else
//                 putchar(' ');
//         }
//         putchar('\n');
//     }
// }

// void update_ball() {
//     int next_x = ball_x + ball_dx;
//     int next_y = ball_y + ball_dy;

//     // Bounce off top/bottom walls
//     if (next_y == 0 || next_y == HEIGHT - 1) {
//         ball_dy = -ball_dy;
//         next_y = ball_y + ball_dy;
//     }

//     // Left paddle collision
//     if ((next_x == left_p_x && next_y >= left_p_y - 1 && next_y <= left_p_y + 1) ||
//         (next_y == left_p_y && next_x >= left_p_x - 1 && next_x <= left_p_x + 1)) {
//         ball_dx = -ball_dx;
//         next_x = ball_x + ball_dx;
//     } else if (next_x == 0) {
//         right_score++;
//         reset_ball();
//         return;
//     }

//     // Right paddle collision
//     if ((next_x == right_p_x && next_y >= right_p_y - 1 && next_y <= right_p_y + 1) ||
//         (next_y == right_p_y && next_x >= right_p_x - 1 && next_x <= right_p_x + 1)) {
//         ball_dx = -ball_dx;
//         next_x = ball_x + ball_dx;
//     } else if (next_x == WIDTH - 1) {
//         left_score++;
//         reset_ball();
//         return;
//     }

//     ball_x = next_x;
//     ball_y = next_y;
// }

// // Player 1 moves: 'w'/'s' (up/down), 'a'/'d' (left/right)
// void move_left_p(char input) {
//     if ((input == 'w' || input == 'W') && left_p_y > 1)
//         left_p_y--;
//     else if ((input == 's' || input == 'S') && left_p_y < HEIGHT - 2)
//         left_p_y++;
//     else if ((input == 'a' || input == 'A') && left_p_x > 1)
//         left_p_x--;
//     else if ((input == 'd' || input == 'D') && left_p_x < (WIDTH / 2 - 1))
//         left_p_x++;
// }

// // Player 2 moves: 'i'/'k' (up/down), 'j'/'l' (left/right)
// void move_right_p(char input) {
//     if ((input == 'i' || input == 'I') && right_p_y > 1)
//         right_p_y--;
//     else if ((input == 'k' || input == 'K') && right_p_y < HEIGHT - 2)
//         right_p_y++;
//     else if ((input == 'j' || input == 'J') && right_p_x > (WIDTH / 2 + 1))
//         right_p_x--;
//     else if ((input == 'l' || input == 'L') && right_p_x < WIDTH - 2)
//         right_p_x++;
// }

// int main() {
//     char input_left, input_right;

//     while (left_score < WIN_SCORE && right_score < WIN_SCORE) {
//         draw_field();

//         printf("Left Paddle (P1): w/s/a/d, q to quit.   Right Paddle (P2): i/k/j/l, q to quit\n");

//         printf("Player 1 move: ");
//         input_left = getchar();
//         while (getchar() != '\n');
//         if (input_left == 'q' || input_left == 'Q') {
//             printf("Game quit.\n");
//             break;
//         }
//         move_left_p(input_left);

//         printf("Player 2 move: ");
//         input_right = getchar();
//         while (getchar() != '\n');
//         if (input_right == 'q' || input_right == 'Q') {
//             printf("Game quit.\n");
//             break;
//         }
//         move_right_p(input_right);

//         update_ball();
//         delay(100);
//     }

//     draw_field();
//     printf("Final Score: Player 1 [%d] - [%d] Player 2\n", left_score, right_score);
//     if (left_score >= WIN_SCORE)
//         printf("Left Player (P1) wins the match!\n");
//     else if (right_score >= WIN_SCORE)
//         printf("Right Player (P2) wins the match!\n");
//     return 0;
// }

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define WIDTH 20
#define HEIGHT 10
#define WIN_SCORE 3
#define NAME_LEN 32

// //Game field dimensions defined above can be changed according to user 
int left_p_x = 1;
int left_p_y = HEIGHT / 2;
int right_p_x = WIDTH - 2;
int right_p_y = HEIGHT / 2;
int ball_x = WIDTH / 2;
int ball_y = HEIGHT / 2;
int ball_dx = 1;//Direction variables
int ball_dy = 1;//Direction variables

int left_score = 0, right_score = 0;
char left_name[NAME_LEN], right_name[NAME_LEN];

void delay(int milliseconds) {                  //Used for adding animation kind of effects as this will help refresh frame by frame
    clock_t start = clock();
    while (clock() < start + milliseconds * (CLOCKS_PER_SEC / 1000));
}

void reset_ball() {             //reset ball after scoring a point back to the initial middle position
    ball_x = WIDTH / 2;
    ball_y = HEIGHT / 2;
    ball_dx = (ball_dx > 0) ? -1 : 1;
    ball_dy = (ball_dy > 0) ? -1 : 1;
}

void draw_scoreboard() {        // Scoreboard in a tabular format for better understanding and visual effects
    printf("\n+--------------------+-------------------+\n");
    printf("|  %-16s  |  %-16s |\n", left_name, right_name);
    printf("+--------------------+-------------------+\n");
    printf("|        %2d          |         %2d        |\n", left_score, right_score);
    printf("+--------------------+-------------------+\n\n");
}

void draw_field() {
    int x, y;

    #ifdef _WIN32
    system("cls");
    #endif

    draw_scoreboard();

        for (y = 0; y < HEIGHT; y++) {
        for (x = 0; x < WIDTH; x++) {
            if (y == 0 || y == HEIGHT - 1)
                putchar('-');
            else if (x == 0 || x == WIDTH - 1)
                putchar('|');
            // Left paddle with angled slashes to make it more accurate to the in real life reference
            else if (x == left_p_x && y == left_p_y)
                putchar('|');
            else if (x == left_p_x - 1 && y == left_p_y - 1)
                putchar('\\');
            else if (x == left_p_x - 1 && y == left_p_y + 1)
                putchar('/');
            // Right paddle with angled slashes (mirrored) to make it more accurate to the in real life reference
            else if (x == right_p_x && y == right_p_y)
                putchar('|');
            else if (x == right_p_x + 1 && y == right_p_y - 1)
                putchar('/');
            else if (x == right_p_x + 1 && y == right_p_y + 1)
                putchar('\\');
            else if (x == ball_x && y == ball_y)       // Ball is represented by O here and defined by its x and y variables
                putchar('O');
            else
                putchar(' ');                   // For the remaining space in the game field
        }
        putchar('\n');
    }
}

void update_ball() {                
    int next_x = ball_x + ball_dx;
    int next_y = ball_y + ball_dy;

    //To make collision effects like bouncing from top and bottom walls
    if (next_y == 0 || next_y == HEIGHT - 1) {
        ball_dy = -ball_dy;
        next_y = ball_y + ball_dy;
    }

    //Left paddle coll
    if ((next_x == left_p_x && next_y >= left_p_y - 1 && next_y <= left_p_y + 1) ||
        (next_y == left_p_y && next_x >= left_p_x - 1 && next_x <= left_p_x + 1)) 
    {
        ball_dx = -ball_dx;
        next_x = ball_x + ball_dx;
    } 
    else if (next_x == 0) 
    {
        right_score++;
        reset_ball();
        return;
    }
    if ((next_x == right_p_x && next_y >= right_p_y - 1 && next_y <= right_p_y + 1) ||
        (next_y == right_p_y && next_x >= right_p_x - 1 && next_x <= right_p_x + 1)) 
        {
        ball_dx = -ball_dx;
        next_x = ball_x + ball_dx;
    }
    else if (next_x == WIDTH - 1) 
    {
        left_score++;
        reset_ball();
        return;
    }

    ball_x = next_x;
    ball_y = next_y;
}

void move_left_p(char input) {
    if ((input == 'w' || input == 'W') && left_p_y > 1)
        left_p_y--;
    else if ((input == 's' || input == 'S') && left_p_y < HEIGHT - 2)
        left_p_y++;
    else if ((input == 'a' || input == 'A') && left_p_x > 1)
        left_p_x--;
    else if ((input == 'd' || input == 'D') && left_p_x < (WIDTH / 2 - 1))
        left_p_x++;
}

void move_right_p(char input) {
    if ((input == 'i' || input == 'I') && right_p_y > 1)
        right_p_y--;
    else if ((input == 'k' || input == 'K') && right_p_y < HEIGHT - 2)
        right_p_y++;
    else if ((input == 'j' || input == 'J') && right_p_x > (WIDTH / 2 + 1))
        right_p_x--;
    else if ((input == 'l' || input == 'L') && right_p_x < WIDTH - 2)
        right_p_x++;
}

int main() {
    char input_left, input_right;

    printf("Enter Player 1 name: ");
    fgets(left_name, NAME_LEN, stdin);
    left_name[strcspn(left_name, "\n")] = '\0';

    printf("Enter Player 2 name: ");
    fgets(right_name, NAME_LEN, stdin);
    right_name[strcspn(right_name, "\n")] = '\0';

    while (left_score < WIN_SCORE && right_score < WIN_SCORE) {
        draw_field();

        printf("%s (P1): w/s/a/d, q to quit.   %s (P2): i/k/j/l, q to quit\n", left_name, right_name);

        printf("%s move: ", left_name);
        input_left = getchar();
        while (getchar() != '\n');
        if (input_left == 'q' || input_left == 'Q') {
            printf("Game quit.\n");
            break;
        }
        move_left_p(input_left);

        printf("%s move: ", right_name);
        input_right = getchar();
        while (getchar() != '\n');
        if (input_right == 'q' || input_right == 'Q') {
            printf("Game quit.\n");
            break;
        }
        move_right_p(input_right);

        update_ball();
        delay(100);
    }

    draw_field();
    if (left_score >= WIN_SCORE)
        printf("%s (P1) wins the match!\n", left_name);
    else if (right_score >= WIN_SCORE)
        printf("%s (P2) wins the match!\n", right_name);
    return 0;
}

