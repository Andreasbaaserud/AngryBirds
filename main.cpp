#include <iostream>
#include <curses.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <sstream>
//#include "Game.h"
#include "FysikkMotor.h"

using namespace std;

int main()
{

    initscr();

    int row, col, toprow, topcol, btmrow, btmcol;
    noecho();
    keypad(stdscr, TRUE);
    start_color();

    char st[] = "Dette er en test!";
    string logo1 =  "    ______  __  __  ____    ____    __   __   \n";
           logo1 += "   /\\  _  \\/\\ \\/\\ \\/\\  _`\\ /\\  _`\\ /\\ \\ /\\ \\ \n";
           logo1 += "   \\ \\ \\L\\ \\ \\ `\\\\ \\ \\ \\L\\_\\ \\ \\L\\ \\`\\`\\\\/'/  \n";
           logo1 += "    \\ \\  __ \\ \\ , ` \\ \\ \\L_L\\ \\ ,  /`\\ `\\ /'   \n";
           logo1 += "     \\ \\ \\/\\ \\ \\ \\`\\ \\ \\ \\/, \\ \\ \\\ \\  `\\ \\ \\   \n";
           logo1 += "      \\ \\_\\ \\_\\ \\_\\ \\_\\ \\____/\\ \\_\\ \\_\\ \\ \\_\\  \n";
           logo1 += "       \\/_/\\/_/\\/_/\\/_/\\/___/  \\/_/\\/_/  \\/_/  \n";
    string logo2 = "         ____    ______   ____    ____    ____        \n";
           logo2 += "        /\\  _`\\ /\\__  _\\ /\\  _`\\ /\\  _`\\ /\\  _`\\      \n";
           logo2 += "        \\ \\ \\L\\ \\/_\/\\ \\/ \\ \\ \\L\\ \\ \\ \\/\\ \\ \\,\\L\\_\\    \n";
           logo2 += "         \\ \\  _ <' \\ \\ \\  \\ \\ ,  /\\ \\ \\ \\ \\/_\\__ \\    \n";
           logo2 += "          \\ \\ \\L\\ \\ \\_\\ \\__\\ \\ \\\\ \\\\ \\ \\_\\ \\/\\ \\L\\ \\  \n";
           logo2 += "           \\ \\____/ /\\_____\\\\ \\_\\ \\_\\ \\____/\\ `\\____\\ \n";
           logo2 += "            \\/___/  \\/_____/ \\/_/\\/ /\\/___/  \\/_____/ \n\n";

    string meny =  "1. Start spillet \n";
           meny += " 2. Endre noe \n";
           meny += " 3. Avslutt";


    getmaxyx(stdscr, row, col);

    toprow = (row*3)/4;
    btmrow = ((row*1)/4)-1;
    btmcol = ((row*3)/4)+1;

    WINDOW * top = newwin(toprow, col, 0, 0);
    WINDOW * btm = newwin(btmrow, col, btmcol, 0);

    refresh();

    init_pair(1, COLOR_RED, COLOR_BLACK);
    init_pair(2, COLOR_BLUE, COLOR_WHITE);
    init_pair(3, COLOR_GREEN, COLOR_BLUE);
    init_pair(4, COLOR_YELLOW, COLOR_BLACK);
    init_pair(5, COLOR_MAGENTA, COLOR_WHITE);
    init_pair(6, COLOR_WHITE, COLOR_BLACK);

    attron(COLOR_PAIR(6));


//    for(int i=0; i < 40; i++)
//    {
//        if(i%2 == 0) attron(A_BOLD | COLOR_PAIR(i%5));
//        mvwaddstr(top, i, i, row);
//        attroff(A_BOLD | COLOR_PAIR(i%5));
//        //getch();
//        sleep(1);
//        wrefresh(top);
//        //clear();
//    }


    //mvprintw(row/2, col, " rows and %d cols",row,col);
    mvwaddstr(top, 0, 0, st);
    box(top, 0, 0);

    wattron(top, A_BOLD | COLOR_PAIR(1));
    mvwaddstr(top,1,0,logo1.c_str());
    wattron(top, A_BOLD | COLOR_PAIR(4));
    mvwaddstr(top,10,0,logo2.c_str());
    wattroff(top, A_BOLD);

    mvwaddstr(btm, 0, 0, st);
    box(btm, 0, 0);
    mvwaddstr(btm,0,1,"Meny");
    mvwaddstr(btm,1,1, meny.c_str());

    stringstream ss;
    ss << row << " - " << col;
    string as = ss.str();
    mvwaddstr(btm,4,1,as.c_str());

    wrefresh(top);
    wrefresh(btm);

    getch();

    delwin(top);
    delwin(btm);

    endwin();

    FysikkMotor fysikk(20,30,1);

    int row, col;
    noecho();

    initscr();
    char st[] = "Dette er en test!";
    getmaxyx(stdscr, row, col);
    WINDOW * top = newwin((row*2)/3, col, 0, 0);
    WINDOW * btm = newwin(((row*1)/3)-1, col, ((row*2)/3)+1 , 0);

    refresh();
    start_color();

    init_pair(1, COLOR_RED, COLOR_BLACK);
    init_pair(2, COLOR_BLUE, COLOR_WHITE);
    init_pair(3, COLOR_GREEN, COLOR_BLUE);
    init_pair(4, COLOR_YELLOW, COLOR_BLACK);
    init_pair(5, COLOR_MAGENTA, COLOR_WHITE);


//    for(int i=0; i < 40; i++)
//    {
//        if(i%2 == 0) attron(A_BOLD | COLOR_PAIR(i%5));
//        mvwaddstr(top, i, i, row);
//        attroff(A_BOLD | COLOR_PAIR(i%5));
//        //getch();
//        sleep(1);
//        wrefresh(top);
//        //clear();
//    }

    for(int i = 0; i < fysikk.vectorX.capacity(); i++){
        mvwaddstr(top,fysikk.vectorY.back()+7,fysikk.vectorX.back()+5, "X");
        fysikk.vectorY.pop_back();
        fysikk.vectorX.pop_back();
        wrefresh(top);
//        sleep(1);
    }


    //mvprintw(row/2, col, " rows and %d cols",row,col);
    mvwaddstr(top, 0, 0, st);
    box(top, 0, 0);
    mvwaddstr(btm, 0, 0, st);
    box(btm, 0, 0);
    mvwaddstr(btm,1,1,"Dette er en test, mohaha");
    stringstream ss;
    ss << row << " - " << col;
    string as = ss.str();
    mvwaddstr(btm,2,1,as.c_str());

    wrefresh(top);
    wrefresh(btm);

    getch();

    delwin(top);
    delwin(btm);

    endwin();
    return 0;
}
