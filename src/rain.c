#include "../inc/header.h"

void mx_rain(int lang) {
    init_pair(1, COLOR_WHITE, COLOR_BLACK);
    init_pair(2, COLOR_GREEN, COLOR_BLACK);
    init_pair(3, COLOR_YELLOW, COLOR_BLACK);
    init_pair(4, COLOR_BLUE, COLOR_BLACK);
    init_pair(5, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(6, COLOR_CYAN, COLOR_BLACK);
    init_pair(7, COLOR_RED, COLOR_BLACK);

    int yMax = 0;
    int xMax = 0;
    getmaxyx(stdscr, yMax, xMax);
    wchar_t beggin[xMax];
    wchar_t lenght[xMax];
    wchar_t arr[xMax];

    for (int i = 0; i < xMax; i++) {
        beggin[i] = -1 * rand() % 80;
        arr[i] = beggin[i];
        lenght[i] = rand() % 50 - 1;
    }

    long long speedWagon = 52500;
    int colour = 2;
    wchar_t randCh;
    for(;;) {
        for (int i = 0; i < xMax; i++) {
            if (lang == 0) {
                randCh = (rand() % 93 + 33);
            } else if (lang == 1){
                randCh = mx_get_random_jp();
            } else {
                randCh = mx_get_random_russ();
            }
            if (i % 2 == 0) {
                randCh = ' ';
            }
            attron(COLOR_PAIR(1));
            mvprintw(arr[i] + 1, i, "%lc", randCh);
            attroff(COLOR_PAIR(1));
            attron(COLOR_PAIR(colour));
            mvprintw(arr[i], i, "%lc",randCh);
            attroff(COLOR_PAIR(colour));
            attron(COLOR_PAIR(colour));
            mvprintw(arr[i] - lenght[i], i, "%c" ,' ');
            attroff(COLOR_PAIR(colour));
            if (arr[i] - lenght[i] > yMax) {
                arr[i] = beggin[i];
                arr[i]++;
            }
            arr[i]++;
        }
        usleep(speedWagon);
        nodelay(stdscr,TRUE);
        char ch = getch();
        if (ch == 'q')
        {
            clear();
            break;
        }
        switch(ch) {
            case '1':
                colour = 1;
                break;
            case '2':
                colour = 2;
                break;
            case '3':
                colour = 3;
                break;
            case '4':
                colour = 4;
                break;
            case '5':
                colour = 5;
                break;
            case '6':
                colour = 6;
                break;
            case '7':
                colour = 7;
                break;
            case '+':
                speedWagon /= 2;
                break;
            case '-':
                speedWagon *= 2;
                break;
        }
        refresh();
    }
}



