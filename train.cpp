#include "train.h"
#include <QtCore>
#include <pthread.h>
#include <semaphore.h>

#define N 7

sem_t s[N];

//Construtor
Train::Train(int ID, int x, int y) {
    for (int i = 0; i < N; i++)
        sem_init(&s[i], 0, i == 5 ? 1 : 0);

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
void Train::run() {while(true) {
        if (!stopped) {
            switch(ID) {
                case 1: // Train 1
                    if (y == 50 && x < 365) {
                        if (x == 345)
                            sem_wait(&s[0]);

                        x += size_movement;
                    } else if (x == 365 && y < 180) {
                        if (y == 160)
                            sem_wait(&s[2]);

                        y += size_movement;
                    } else if (x > 95 && y == 180) {
                        if (x == 215)
                            sem_post(&s[2]);

                        if (x == 355)
                            sem_post(&s[0]);

                        x -= size_movement;
                    } else
                        y -= size_movement;

                    emit updateGUI(ID, x, y);

                    break;
                case 2: // Train 2
                    if (y == 50 && x < 635) {
                        if (x == 615)
                            sem_wait(&s[1]);

                        if (x == 375)
                            sem_post(&s[0]);

                        x += size_movement;
                    } else if (x == 635 && y < 180) {
                        if (y == 160) {
                            sem_wait(&s[3]);
                            sem_wait(&s[4]);
                        }

                        y += size_movement;
                    } else if (x > 365 && y == 180) {
                        if (x == 385)
                            sem_wait(&s[0]);

                        if (x == 625)
                            sem_post(&s[1]);

                        if (x == 485)
                            sem_post(&s[4]);

                        x -= size_movement;
                    } else {
                        if (y == 170)
                            sem_post(&s[3]);

                        y -= size_movement;
                    }

                    emit updateGUI(ID, x, y);

                    break;
                case 3: // Train 3
                    if (y == 50 && x < 905) {
                        if (x == 645)
                            sem_post(&s[1]);

                        x += size_movement;
                    } else if (x == 905 && y < 180)
                        y += size_movement;
                    else if (x > 635 && y == 180) {
                        if (x == 795) {
                            sem_wait(&s[1]);
                            sem_wait(&s[5]);
                        }

                        x -= size_movement;
                    } else {
                        if (y == 170)
                            sem_post(&s[5]);

                        y -= size_movement;
                    }

                    emit updateGUI(ID, x, y);

                    break;
                case 4: // Train 4
                    if (y == 180 && x < 500) {
                        if (x == 380)
                            sem_post(&s[2]);

                        if (x == 480)
                            sem_wait(&s[6]);

                        x += size_movement;
                    } else if (x == 500 && y < 310) {
                        if (y == 190)
                            sem_post(&s[3]);

                        y += size_movement;
                    } else if (x > 230 && y == 310) {
                        if (x == 490)
                            sem_post(&s[6]);

                        x -= size_movement;
                    } else {
                        if (y == 200) {
                            sem_wait(&s[3]);
                            sem_wait(&s[2]);
                        }

                        y -= size_movement;
                    }

                    emit updateGUI(ID, x, y);

                    break;
                case 5: // Train 5
                    if (y == 180 && x < 770) {
                        if (x == 650)
                            sem_post(&s[4]);

                        if (x == 510)
                            sem_post(&s[6]);

                        if (x == 610)
                            sem_wait(&s[5]);

                        x += size_movement;
                    } else if (x == 770 && y < 310) {
                        if (y == 190)
                            sem_post(&s[5]);

                        y += size_movement;
                    } else if (x > 500 && y == 310) {
                        if (x == 520)
                            sem_wait(&s[6]);

                        x -= size_movement;
                    }
                    else {
                        if (y == 200)
                            sem_wait(&s[4]);

                        y -= size_movement;
                    }

                    emit updateGUI(ID, x, y);

                    break;
                default:
                    break;
            }

            msleep(sleep);
        }
    }
}
