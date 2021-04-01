#include <iostream>
#include <conio.h>
#include <Windows.h>
using namespace std;
bool gameover;
const int width = 20;
const int height = 20;
int x, y, fruitx, fruity, score;
int tailx[100], taily[100];
int ntail;
enum edirection { stop = 0, LEFT, RIGHT, UP, DOWN };
edirection dir;
void setup() {

    gameover = false;
    dir = stop;
    x = width / 2;
    y = height / 2;
    fruitx = rand() % width;
    fruity = rand() % height;
    score = 0;

}

void draw() {

    system("cls");
    for (int i = 0; i < width+2; i++) {

        cout << "#";

    }

    cout << endl;

    for (int i = 0; i < height; i++) {

        for (int j = 0; j < width; j++) {

            if (j == 0) {

                cout << "#";

            }
            if (i == y && j == x) {

                cout << "O";

            }

            else if (i == fruity && j == fruitx) {

                cout << "F";

            }
            else {

                bool print = false;

                for (int k = 0; k < ntail; k++) {

                    if (tailx[k] == j && taily[k] == i) {

                        cout << "o";

                        print = true;

                    }

                }

                if (!print) {

                    cout << " ";

                }

            }

            if (j == width - 1) {

                cout << "#";

            }

        }

        cout << endl;

    }

    for (int i = 0; i < width+2; i++) {

        cout << "#";

    }

    cout << endl;

    cout << "Score:" << score << endl;

}

void input() {

    if (_kbhit()) {

        switch (_getch()) {

        case 'a':
            dir = UP;
            break;
        case 'd':
            dir = DOWN;
            break;
        case 's':
            dir = LEFT;
            break;
        case 'w':
            dir = RIGHT;
            break;

        case 'x':
            gameover = true;
            break;
        }

    }

}

void logic() {

    int prievx = tailx[0];
    int prievy = taily[0];
    int priev2x, priev2y;
    tailx[0] = x;
    taily[0] = y;

    for (int i = 1; i < ntail; i++) {

        priev2x = tailx[i];
        priev2y = taily[i];

        tailx[i] = prievx;
        taily[i] = prievy;

        prievx = priev2x;
        prievy = priev2y;
    }

    switch (dir) {
    case LEFT:
        x--;
        break;
    case RIGHT:
        x++;
        break;
    case UP:
        y--;
        break;
    case DOWN:
        y++;
        break;

    }


    if (x >= width) {

        x = 0;

    }

    else if (x < 0) {

        x = width - 1;

    }

    if (y >= height) {

        y = 0;

    }

    else if (y < 0) {

        y = height - 1;

    }

    for (int i = 0; i < ntail; i++) {

        if (tailx[i] == x && taily[i] == y) {

            gameover = true;

        }

    }

    if (x == fruitx && y == fruity) {

        score = score + 10;

        fruitx = rand() % width;
        fruity = rand() % height;

        ntail++;

    }
}

int main()
{
    int a;

    cout << "1)start game" << endl;
    cout << "2)exit" << endl;

    cin >> a;

    if (a == 1) {

        setup();

        while (!gameover) {

            draw();
            input();
            logic();
            Sleep(10);
        }

        if (gameover == true) {

            system("cls");

            cout << "game over" << endl;

            system("pause");

            exit;

        }

    }

    if (a == 2) {

        exit;

    }

    return 0;
}


