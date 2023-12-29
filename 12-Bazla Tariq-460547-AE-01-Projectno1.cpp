#include <iostream>
using namespace std;

char space[3][3]={{'1', '2', '3'},{'4','5','6'},{'7', '8', '9'}};
int row;
int column;
char token = 'x';
bool tie = false;
string p1 = "";
string p2 = "";

void functionone() {
    cout << "      |      |          " << endl;
    cout << " "<<space[0][0]<< "    | "<<space[0][1]<<"    | "<<space[0][2]<<endl;
    cout << "______|______|______"<<endl;
    cout << "      |      |          " << endl;
    cout << " "<<space[1][0]<< "    | "<<space[1][1]<<"    | "<<space[1][2]<<endl;
    cout << "______|______|______"<<endl;
    cout << "      |      |          " << endl;
    cout << " "<<space[2][0]<< "    | "<<space[2][1]<<"    | "<<space[2][2]<<endl;
    cout << "      |      |          " << endl;
}

void function2() {
    int digit;
    if (token == 'x') {
        cout << p1 << " Please enter: ";
        cin >> digit;
    }
    else if (token == '0') {
        cout << p2 << " Please enter: ";
        cin >> digit;
    }
    else {
        cout << "Invalid" << endl;
        return;
    }
    
    if (digit >= 1 && digit <= 9) {
        digit -= 1;
        row = digit / 3;
        column = digit % 3;
        
        if (space[row][column] != 'x' && space[row][column] != '0') {
            if (token == 'x') {
                space[row][column] = 'x';
                token = '0';
            }
            else if (token == '0') {
                space[row][column] = '0';
                token = 'x';
            }
        }
        else {
            cout << "There is no empty space" << endl;
            function2();
        }
    }
    else {
        cout << "Invalid" << endl;
        function2();
    }
}

bool functionthree() {
    for (int i = 0; i < 3; i++) {
        if (space[i][0] == space[i][1] && space[i][0] == space[i][2] || space[0][i] == space[1][i] && space[0][i] == space[2][i]) {
            return true;
        }
    }
    if (space[0][0] == space[1][1] && space[0][0] == space[2][2] || space[0][2] == space[1][1] && space[1][1] == space[2][0]) {
        return true;
    }
    
    bool isBoardFull = true;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (space[i][j] != 'x' && space[i][j] != '0') {
                isBoardFull = false;
                break;
            }
        }
        if (!isBoardFull) {
            break;
        }
    }
    
    if (isBoardFull) {
        tie = true;
        return true;
    }
    
    return false;
}

int main() {
    cout << "Enter the name of the first player: " << endl;
    cin >> p1;
    cout << "Enter the name of the second player: " << endl;
    cin >> p2;
    cout << p1 << " is player 1, so he/she will play first" << endl;
    cout << p2 << " is player 2, so he/she will play second" << endl;
    
    while (!functionthree()) {
        functionone();
        function2();
    }
    
    functionone(); 
    
    if (token == 'x' && !tie) {
        cout << p2 << " wins!!" << endl;
    }
    else if (token == '0' && !tie) {
        cout << p1 << " Wins!!" << endl;
    }
    else {
        cout << "It's a draw!!!" << endl;
    }
  
    return 0; 
}
