#include "termio.h"
#include "Hanoi.h"
#include "sstream"
#include "climits"
#include <Windows.h>
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
    cmd command;
    void getbegin() {
        int cmd;
        char *CMD;
        char q;
        CMD = new char;
        while (true) {
            Termio::Clear();
            cout << "How many disks do you want? (1 ~ 5)\n";
            cin >> CMD;
            stringstream ss1(CMD);
            ss1 >> q;
            if (q == 'Q') {
                exit(0);
            }
            stringstream ss2(CMD);
            ss2 >> cmd;
            if(cmd >= 1 && cmd <= 5) {  
                sum = cmd;
                break; 
            }
        }
    }
    bool judge() {
        if (hanoi.get(0)->length == 0 && hanoi.get(2)->length == 0 && hanoi.get(1)->length == sum) {
            cout << "Congratulations! You win!\n";
            cin.get();
            return true;
        }
        else return false;
    }
    void begin() {
        getbegin();
        for (int i = sum; i >= 1 ; i--) {
            hanoi.get(0)->push(Disk(i));
        }
        hanoi.upset();

        hanoi.firstPrint();
        hanoi.print();
        //cout << hanoi.get(0)->length << hanoi.get(1)->length << hanoi.get(2)->length; 
    }
    void move() {
        char *cmd;
        int rod1, rod2;
        cmd = new char;
        while (true) {/* 
            cin.sync(); */
            cout << "Move a disk. Format: x y\n";
            cin.getline(cmd, INT_MAX);
            hanoi.print();
            char *cmd1;
            cmd1 = new char;
            stringstream ss(cmd);
            ss >> rod1 >> rod2;/* 
            cout << 123; */
            if (rod2 == rod1 && rod2 == 0)
                autoMove();
            /* Sleep(3000); */
            if (rod1 > 3 || rod1 < 1 || rod2 >3 || rod2 < 1) {
                /* cout << 123; */
                continue;
                }
            if (hanoi.get(rod1 - 1)->getTopSize() > hanoi.get(rod2 - 1)->getTopSize()) {
                /* cout << 123; */
                continue;
            }  
            else {/* 
                cout << "nice"; */
                Disk disk = hanoi.get(rod1 - 1)->pop();
                hanoi.get(rod2 - 1)->push(disk);
                int *c;
                c = new int[2];
                c[0] = rod1;
                c[1] = rod2;
                /* Sleep(3000); */
                command.push(c);
                 /* for (int i = 0; i < 1; i++) {
                    cout << command.getTop()[0] <<command.getTop()[1];
                    command.pop();/* cout <<1234; 
                }  */
                //cout << command.length;
                /* Sleep(3000);  */
                /* cout << hanoi.get(rod2 - 1)->length; */
                hanoi.print(); 
                /*cout << hanoi.get(1)->get(0).size; */
            }
            if (judge())
                break;
        }
    }
    void autoMove() {
        while (command.length != 0) {
            int *c = command.pop();
            /* cout << command.length; */
            /* Sleep(3000); */
            /* cout << c[1] << c[0];*/
            /* Disk disk = hanoi.get(c[1] - 1)->pop();
            hanoi.get(c[0] - 1)->push(disk); */
            int rod1 = c[1];
            int rod2 = c[0];
            delete []c;
            Disk disk = hanoi.get(rod1 - 1)->pop();
            hanoi.get(rod2 - 1)->push(disk);
            cin.get();
            hanoi.print();
            cout << "Auto moving:" << rod1 << "->" << rod2 << endl;
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
