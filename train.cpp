#include "train.h"
#include <QtCore>

//Construtor
Train::Train(int ID, int x, int y) {
    this->ID = ID;
    this->x = x;
    this->y = y;
    sleep = 99;
    stopped = true;
}

void Train::setSleep(int value) {
    this->sleep = value;
}

void Train::setStopped(bool value) {
    this->stopped = value;
}

//Função a ser executada após executar Train->START
void Train::run() {
    while(true) {
        if (!stopped) {
            switch(ID) {
                case 1: // Train 1
                    if (y == 50 && x < 365)
                        x+=10;
                    else if (x == 365 && y < 180)
                        y+=10;
                    else if (x > 95 && y == 180)
                        x-=10;
                    else
                        y-=10;
                    emit updateGUI(ID, x,y);    //Emite um sinal
                    break;
                case 2: // Train 2
                    if (y == 50 && x < 635)
                        x+=10;
                    else if (x == 635 && y < 180)
                        y+=10;
                    else if (x > 365 && y == 180)
                        x-=10;
                    else
                        y-=10;
                    emit updateGUI(ID, x,y);    //Emite um sinal
                    break;
                case 3: // Train 3
                    if (y == 50 && x < 905)
                        x+=10;
                    else if (x == 905 && y < 180)
                        y+=10;
                    else if (x > 635 && y == 180)
                        x-=10;
                    else
                        y-=10;
                    emit updateGUI(ID, x,y);    //Emite um sinal
                    break;
                case 4: // Train 4
                    if (y == 180 && x < 500)
                        x+=10;
                    else if (x == 500 && y < 310)
                        y+=10;
                    else if (x > 230 && y == 310)
                        x-=10;
                    else
                        y-=10;
                    emit updateGUI(ID, x,y);    //Emite um sinal
                    break;
                case 5: // Train 5
                    if (y == 180 && x < 770)
                        x+=10;
                    else if (x == 770 && y < 310)
                        y+=10;
                    else if (x > 500 && y == 310)
                        x-=10;
                    else
                        y-=10;
                    emit updateGUI(ID, x,y);    //Emite um sinal
                    break;
                default:
                    break;
            }

            msleep(sleep);
        }
    }
}




