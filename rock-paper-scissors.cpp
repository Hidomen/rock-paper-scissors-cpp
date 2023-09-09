#include <iostream>
#include <ctime>

using namespace std;

string playername;
int playeract;
char again;
bool start = false;

int scorep = 0;
int scorec = 0;

void resultText(string rcomp, string rplayer, string winner);
void startSec();
void result();
void playAgain();

int main() {

    do {

    startSec();
    result();
    playAgain(); 

        if (again == 'n'){
            cout << "# COMP'S SCORE: " << scorec << endl << "# " << playername << "'S SCORE: " << scorep;
            cout << "\n-----------------------------------------\n";
        }

    } while (again == 'y' || again == 'Y');

    return 0;
}

void result(){
    srand(time(NULL));
    int cmove = (rand() % 3) + 1;

    switch(cmove){
        case 1: 
        cout << "-----------------------------------------\n";
            if( playeract == 1 ){
                resultText("ROCK", "ROCK", "NOBODY");
            } else if ( playeract == 2 ){
                resultText("ROCK", "PAPER", "COMP");
                scorec++;
            } else if ( playeract == 3 ){
                resultText("ROCK", "SCISSORS", playername);
                scorep++;
            }
            break;
        case 2: 
        cout << "-----------------------------------------\n";
            if( playeract == 1 ){
                resultText("PAPER", "ROCK", "COMP");
                scorec++;
            } else if ( playeract == 2 ){
                resultText("PAPER", "PAPER", "NOBODY");
            } else if ( playeract == 3 ){
                resultText("PAPER", "SCISSORS", playername);
                scorep++;
            }
            break;
        case 3: 
        cout << "-----------------------------------------\n";
            if( playeract == 1 ){
                resultText("SCISSORS", "ROCK", playername);
                scorep++;
            } else if ( playeract == 2 ){
                resultText("SCISSORS", "PAPER", "COMP");
                scorec++;
            } else if ( playeract == 3 ){
                resultText("SCISSORS", "SCISSOR", "NOBODY");
            }
            break;
    }
    cout << "\n*****************************************";  
}
void startSec(){
    if ( start == false ){
    cout << "********** ROCK-PAPER-SCISSORS **********\n";
    cout << "NAME: ";
    getline (cin >> ws, playername);
    start = true;
    }
    cout << "| 1. ROCK" << "\n| 2. PAPER" << "\n| 3. SCISSORS" << endl;
    cout << "Choose your weapon: ";
    cin >> playeract;

    cin.clear();
    fflush(stdin);

        if ( playeract !=1 && playeract !=2 && playeract !=3) {
        cout << "@@ Invalid Weapon!" << endl;
        main();
    }
}
void resultText(string rcomp, string rplayer, string winner){
    cout << "COMP: " << rcomp << endl << playername << ": " << rplayer << endl << "# " << winner << " WON";
}
void playAgain(){
        cout << "\nPLAY AGAIN? y/n: ";
        cin >> again;
        while ( again != 'y' && again != 'n' && again != 'Y' && again != 'N'){
            cout << "Invalid answer. Play again? y/n: ";
            cin >> again;

            cin.clear();
            fflush(stdin);
        }    
}