#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

int main() {
    srand(time(0));

    // player input selection
    string inputStr;
    cout << "Input your option (rock/paper/scissors): ";
    std::cin >> inputStr;
    int input;
    if (inputStr == "rock" || inputStr == "r") {
        input = 0;
    }
    if (inputStr == "paper" || inputStr == "p") {
        input = 1;
    }
    if(inputStr == "scissors" || inputStr == "s") {
        input = 2;
    }
    if (inputStr != "paper" && inputStr != "p" && inputStr != "scissors" && inputStr != "s" && inputStr != "rock" && inputStr != "r") {
        input = 4;
    }

    // enemy input selection
    int enemyInput;
    enemyInput = rand() % 3;

    // comparing
    switch(input) {
        case 0:
            switch(enemyInput) {
                case 0:
                    cout << "rock vs rock, tie!";
                    break;
                case 1:
                    cout << "rock vs paper, you lose!";
                    break;
                case 2:
                    cout << "rock vs scissors, you win!";
                    break;
                default:
                    break;
            }
            break;
        case 1:
            switch(enemyInput) {
                case 0:
                    cout << "paper vs rock, you win!";
                    break;
                case 1:
                    cout << "paper vs paper, tie!";
                    break;
                case 2:
                    cout << "paper vs scissors, you lose!";
                    break;
                default:
                    break;
            }
            break;
        case 2:
            switch(enemyInput) {
                case 0:
                    cout << "scissors vs rock, you lose!";
                    break;
                case 1:
                    cout << "scissors vs paper, you win!";
                    break;
                case 2:
                    cout << "scissors vs scissors, tie!";
                    break;
                default:
                    break;
            }
            break;
        default:
            cout << "That is not a valid input.";
            break;
    }
    return 0;
}
