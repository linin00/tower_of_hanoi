#include "Stack.h"
#include "termio.h"
class Hanoi {
public:
    Hanoi() {
        for (int i = 0; i < 3; i++) {
        hanoi[i] = rod(i);
    }
    }
    rod get(int i) {
        return hanoi[i];
    }
    void print();
private:
    rod hanoi[3];
};

void Hanoi::print() {
    Termio::Clear();
    Termio::ResetBuffer();
    for (int i = 1; i < 40; i++) {
        Termio::buffer[10][i] = '-';
    }
    for (int i = 0; i < 11; i++) {
        Termio::buffer[i][5] = '|';
        Termio::buffer[i][20] = '|';
        Termio::buffer[i][35] = '|';
    }
    if (!hanoi[0].length) {
        for (int i = 9; i >= (9 - hanoi[0].length * 2); i -= 2) {
            for (int k = 0; k < hanoi[0].length; k++){
                for (int j = 5; j - 5 <= hanoi[0].get(k).size/2; j++) {
                    Termio::buffer[i][j] = '*';
                    Termio::buffer[i][10 -j] = '*';
                }
            }
        }
    }
    if (!hanoi[1].length) {
        for (int i = 9; i >= (9 - hanoi[1].length * 2); i -= 2) {
            for (int k = 0; k < hanoi[0].length; k++){
                for (int j = 20; j - 20 <= hanoi[0].get(k).size/2; j++) {
                    Termio::buffer[i][j] = '*';
                    Termio::buffer[i][40 -j] = '*';
                }
            }
        }
    }
    if (!hanoi[2].length) {
        for (int i = 9; i >= (9 - hanoi[2].length * 2); i -= 2) {
            for (int k = 0; k < hanoi[0].length; k++){
                for (int j = 35; j - 35 <= hanoi[0].get(k).size/2; j++) {
                    Termio::buffer[i][j] = '*';
                    Termio::buffer[i][70 -j] = '*';
                }
            }
        }
    }
    Termio::Draw();
}