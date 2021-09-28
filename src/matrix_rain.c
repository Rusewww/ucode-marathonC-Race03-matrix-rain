#include "../inc/header.h"

int main(int argc, char *argv[]) {
    setlocale(LC_ALL, "");

    if (argc > 3){
        mx_printerr("usage: ./matrix_rain [-s] [-j/-r]\n");
        exit (0);
    }

    int lang = 0;

    if(argc == 3){
        if (argv[2][0] == '-' && argv[2][1] == 'j' && argv[2][2] == '\0'){
            lang = 1;
        } else if (argv[2][0] == '-' && argv[2][1] == 'r' && argv[2][2] == '\0') {
            lang = 2;
        } else {
            mx_printerr("usage: ./matrix_rain [-s] [-j/-r]\n");
            exit (0);
        }
    }

    if (argc == 1){
        initscr();
        noecho();
        WINDOW *win = newwin(LINES, COLS, 0, 0);
        init_pair(1, COLOR_GREEN, COLOR_BLACK);
        start_color();
        wbkgd(win, COLOR_PAIR(1));
        attron(COLOR_PAIR(1));
        curs_set(0);
        refresh();
        start_color();
        intro();
        mx_rain(lang);
        delwin(win);
        endwin();
    } else if (argv[1][0] == '-' && argv[1][1] == 's' && argv[1][2] == '\0'){
        initscr();
        noecho();
        WINDOW *win = newwin(LINES, COLS, 0, 0);
        init_pair(1, COLOR_GREEN, COLOR_BLACK);
        start_color();
        wbkgd(win, COLOR_PAIR(1));
        attron(COLOR_PAIR(1));
        curs_set(0);
        refresh();
        start_color();
        mx_rain(lang);
        char ch = getch();
        if(ch == 'q')
        {
            clear();
            exit(0);
        }
        delwin(win);
        endwin();
    } else {
        mx_printerr("usage: ./matrix_rain [-s] [-j/-r]\n");
        exit (0);
    }
    // char *message1 = "Wake up Neo...";
}

