#include "termio.h"
#include "Hanoi.h"
#include "sstream"
#include "climits"
// Do not delete the following line
char Termio::buffer[Termio::CANVAS_HEIGHT][Termio::CANVAS_WIDTH + 1];
/* 
void write_hi() {
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
}
 */
class game {
public:
    void run() {  
        while (true) {
            begin();
            move();
        }
    }
private:
    Hanoi hanoi;
    int sum;
    int getbegin() {
        int cmd;
        char *CMD;
        char q;
        CMD = new char;
        while (true) {
            cout << "How many disks do you want? (1 ~ 5)\n";
            cin >> CMD;
            stringstream ss1(CMD);
            ss1 >> q;
            if (q == 'Q') {
                exit(0);
            }
            stringstream ss2(CMD);
            ss2 >> sum;
            if(ss2.eof() && sum >= 1 && sum <= 5) {
                break; 
            }  
        }
        return sum;
    }
    bool judge() {
        if (hanoi.get(0).length == 0 && hanoi.get(1).length == 0 && hanoi.get(2).length == sum) {
            cout << "Congratulations! You win!\n";
            return true;
        }
    }
    void begin() {
        sum = getbegin();
        for (int i = sum; i >= 1 ; i--) {
            hanoi.get(0).push(Disk(1));
        }
        hanoi.print();
    }
    void move() {
        char *cmd;
            int rod1, rod2;
        cmd = new char;
        while (true) {
            cout << "Move a disk. Format: x y\n";
            cin.getline(cmd, INT_MAX);
            stringstream ss(cmd);
            ss >> rod1 >> rod2;
            if (rod1 >3 || rod1 < 1 || rod2 >3 || rod2 < 1)
                continue;
            if (ss.good()) {
                if (hanoi.get(rod1).getTop().size > hanoi.get(rod2).getTop().size)
                    continue;
                else {
                    Disk disk = hanoi.get(rod1 - 1).pop();
                    hanoi.get(rod2 - 1).push(disk);
                    hanoi.print();
                }
            }
            if (judge())
                break;
        }
    }
};
int main() {
    game my;
    my.run();

/* 
    // ---- Example: how to use termio.h ----
    // clear screen
    Termio::Clear();
    // reset buffer
    Termio::ResetBuffer();
    write_hi();
    Termio::Draw();
    // ----------- End of example -----------
    // Your code here

    // some output hints that you should use.
    std::cout << "How many disks do you want? (1 ~ 5)" << std::endl;
    std::cout << "Move a disk. Format: x y" << std::endl;
    std::cout << "Auto moving:1->2" << std::endl;
    std::cout << "Congratulations! You win!" << std::endl;
 */
    //write_hi();
    //Hanoi a;
    //a.print();
    //Termio::Draw();
    return 0;

}
