#include <stdio.h>
int win(int shet_1, int shet_2);
int pole(int rocket_1_Y, int rocket_2_Y, int shet_1, int shet_2, int 
flag1, int flag2, int ball_x,
         int ball_y);
int main() {
    int HEIGHT_SCRING_Y = 26;
    int rocket_1_Y = 12, rocket_2_Y = 12, ball_x = 40, ball_y = 12;
    char temp;
    int flag1 = 0, flag2 = 0;
    int speed_x = 1, speed_y = 1;
    int shet_1 = 0, shet_2 = 0;

    while (shet_1 <= 21 && shet_2 <= 21) {
        scanf("%c", &temp);
        switch (temp) {
            case 'a':
                ((rocket_1_Y - 2) != 0) ? (rocket_1_Y -= 1) : rocket_1_Y;
                break;
            case 'z':
                ((rocket_1_Y + 3) != HEIGHT_SCRING_Y) ? (rocket_1_Y += 1) : rocket_1_Y;
                break;
            case 'k':
                ((rocket_2_Y - 2) != 0) ? (rocket_2_Y -= 1) : rocket_2_Y;
                break;
            case 'm':
                ((rocket_2_Y + 3) != HEIGHT_SCRING_Y) ? (rocket_2_Y += 1) : rocket_2_Y;
                break;
            case ' ':
                break;
            case '\n':
                continue;;
        }
        printf("\n");
        printf("\033[0d\033[2J");

        if (ball_y == 2 || ball_y == 25) speed_y = (-1) * speed_y;
        if (ball_x == 4 && (ball_y == rocket_1_Y || ball_y == rocket_1_Y + 1 || ball_y == rocket_1_Y + 2))
            speed_x = -speed_x;
        else if (ball_x == 77 &&
                 (ball_y == rocket_2_Y || ball_y == rocket_2_Y + 1 || ball_y == rocket_2_Y + 2))
            speed_x = -speed_x;
        else if (ball_x == 1) {
            ball_x = 40;
            ball_y = 12;
            shet_2 += 1;
        } else if (ball_x == 80) {
            ball_x = 40;
            ball_y = 12;
            shet_1 += 1;
        }
        ball_x += speed_x;
        ball_y += speed_y;
        pole(rocket_1_Y, rocket_2_Y, shet_1, shet_2, flag1, flag2, ball_x, ball_y);
    }
    win(shet_1, shet_2);
    return 0;
}

int pole(int rocket_1_Y, int rocket_2_Y, int shet_1, int shet_2, int 
flag1, int flag2, int ball_x,
         int ball_y) {
    for (int y = 0; y < 27; y++) {
        for (int x = 1; x < 80; x++) {
            flag1 = flag2 = 0;
            if (x == 2 && (y == rocket_1_Y || y == rocket_1_Y + 1 || y == rocket_1_Y + 2)) flag1 = 1;
            if (x == 78 && (y == rocket_2_Y || y == rocket_2_Y + 1 || y == rocket_2_Y + 2)) flag2 = 1;

            if (flag1 == 1 && y != 0)
                printf("|");
            else if (flag2 == 1 && y != 0)
                printf("|");
            else if (y == ball_y && x == ball_x)
                printf("o");
            else if (y == 1 || y == 26)
                printf("-");
            else if ((x == 1 || x == 79 || x == 41 || x == 40) && y != 0)
                printf("|");
            else if (y == 0 && x == 3)
                printf("score: %d                                                         score: %d", shet_1,shet_2);
            else
                printf(" ");
        }

        printf("\n");
        
    }

    return 0;
}
int win(int shet_1, int shet_2) {
    if (shet_1 >= 21) {
        for (int y = 0; y < 100; y++) {
            for (int x = 0; x < 100; x++) {
                printf(" ");
            }
        }
        printf("\033[0d\033[2J");
        printf("\n█▀█ █   ▄▀█ █▄█ █▀▀ █▀█   ▄█   █░█░█ █ █▄░█ █\n█▀▀ █▄▄ █▀█ ░█░ ██▄ █▀▄   ░█   ▀▄▀▄▀ █ █░▀█ ▄");
    }
    if (shet_2 >= 21) {
        for (int y = 0; y < 100; y++) {
            for (int x = 0; x < 100; x++) {
                printf(" "); 
            }
        }
        printf("\033[0d\033[2J");
        printf("\n█▀█ █   ▄▀█ █▄█ █▀▀ █▀█   ▀█   █░█░█ █ █▄░█ █\n█▀▀ █▄▄ █▀█ ░█░ ██▄ █▀▄   █▄   ▀▄▀▄▀ █ █░▀█ ▄");
    }
    return 0;
}

