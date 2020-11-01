#include "termio.h"
#include "Hanoi.h"
#include <sstream>
#include <climits>
char Termio::buffer[Termio::CANVAS_HEIGHT][Termio::CANVAS_WIDTH + 1];

class game {
public:
    void run() {  
        while (true) {
            begin();
            move();
            reset();
        }
    }
private:
    Hanoi my_hanoi;
    int sum = 0;
    cmd command;
    void reset() {
        for (int i = 0; i < 3; i++) {
            int k = my_hanoi.get(i)->length;
            for (int j = 0; j < k ; j++) {
                my_hanoi.get(i)->pop();
            }
        }
        command.resetstack();
    }
    void getbegin() {
        int cmd;
        char *CMD;
        char q;
        CMD = new char;
        while (true) {
            cout << "How many disks do you want? (1 ~ 5)\n";
            Termio::ResetBuffer();
            cin >> CMD;
            Termio::Clear();
            stringstream ss1(CMD);
            ss1 >> q;
            if (q == 'Q') exit(0);
            stringstream ss2(CMD);
            ss2 >> cmd;
            if(cmd >= 1 && cmd <= 5) {  
                sum = cmd;
                break; 
            }
        }
    }
    bool judge() {
        if (my_hanoi.get(0)->length == 0 && my_hanoi.get(2)->length == 0) {
            cout << "Congratulations! You win!\n";
            return true;
        }
        else return false;
    }
    void begin() {
        getbegin();
        for (int i = sum; i >= 1 ; i--) {
            my_hanoi.get(0)->push(Disk(i));
        }
        my_hanoi.upset();
        my_hanoi.firstPrint();
        my_hanoi.print();
    }
    void move() {
        char *cmd;
        int rod1, rod2;
        cmd = new char;
        while (true) {
            cout << "Move a disk. Format: x y\n";
            cin.getline(cmd, INT_MAX);
            my_hanoi.print();
            char *cmd1;
            cmd1 = new char;
            stringstream ss(cmd);
            ss >> rod1 >> rod2;
            if (rod2 == rod1 && rod2 == 0) autosolve();
            else if (rod1 > 3 || rod1 < 1 || rod2 >3 || rod2 < 1) continue;
                else if (my_hanoi.get(rod1 - 1)->getTopSize() > my_hanoi.get(rod2 - 1)->getTopSize()) continue; 
                    else {
                        Disk disk = my_hanoi.get(rod1 - 1)->pop();
                        my_hanoi.get(rod2 - 1)->push(disk);
                        int *c;
                        c = new int[2];
                        c[0] = rod1;
                        c[1] = rod2;
                        command.push(c);
                        my_hanoi.print(); 
                        }
            if (judge()) break;
        }
    }
    void autoMove() {
        while (command.length != 0) {
            int *c = command.pop();
            int rod1 = c[1];
            int rod2 = c[0];
            Disk disk = my_hanoi.get(rod1 - 1)->pop();
            my_hanoi.get(rod2 - 1)->push(disk);
            cout << "Auto moving:" << rod1 << "->" << rod2 << endl;
            my_hanoi.autoMove_print();
        }
    }
    void recursion(int n, int rod1, int rod2, int rod3) {
        if(n > 1) recursion(n - 1, rod1, rod3, rod2);

        Disk disk = my_hanoi.get(rod1 - 1)->pop();
        my_hanoi.get(rod2 - 1)->push(disk);
        cout << "Auto moving:" << rod1 << "->" << rod2 << endl;
        my_hanoi.autoMove_print();

        if(n > 1) recursion(n - 1, rod3, rod2, rod1);
    }
    void autosolve () {
        Termio::Clear();
        autoMove();
        recursion(sum, 1, 2, 3);
    }
};
int main() {
    game my;
    my.run();
    return 0;

}
