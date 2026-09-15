#include <iostream>
using namespace std;
int main() {
    int score;
    cout << "Please input a score: ";
    cin >> score;
    cout << "The score is: " << score << endl;
    if (score >= 600) {
        cout << "恭喜考上一本大学." << endl;
        if (score >= 650) {
            cout << "恭喜考上985/211大学." << endl;
        }
        else {
            cout << "恭喜考上普通一本大学." << endl;
        }   
    }
    else if (score >= 500) {
        cout << "恭喜考上二本大学." << endl;
    }
    else if (score >= 400) {
        cout << "恭喜考上三本大学." << endl;
    }
    else {
        cout << "很遗憾没有考上大学." << endl;
    }
    return 0;
}