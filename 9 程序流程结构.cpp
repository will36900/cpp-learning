 #include <iostream>
using namespace std;
int main(){
    int score;
    cout <<"Please input a score: ";
    cin >> score;
    cout <<"The score is: " << score << endl;
    if (score >= 600){
        cout << "Congratulations! You have entered the university." << endl;
    }
    else{
        cout << "Sorry! You have not entered the university." << endl;
    }
    return 0;
}

