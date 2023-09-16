#include <iostream>
#include <ctime>

std::string playername;
int playeract;
char again;
bool start = false;

int scorep = 0;
int scorec = 0;

void resultText(std::string rcomp, std::string rplayer, std::string winner);
void startSec();
void result();
void playAgain();

int main() {

    do {

    startSec();
    result();
    playAgain(); 

        if (again == 'n' || again == 'N'){
            std::cout << "# COMP'S SCORE: " << scorec << '\n' << "# " << playername << "'S SCORE: " << scorep;
            std::cout << "\n-----------------------------------------\n";
        }

    } while (again == 'y' || again == 'Y');

    return 0;
}

void result(){
    srand(time(NULL));
    int cmove = (rand() % 3) + 1;

    switch(cmove){
        case 1: 
        std::cout << "-----------------------------------------\n";
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
        std::cout << "-----------------------------------------\n";
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
        std::cout << "-----------------------------------------\n";
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
    std::cout << "\n*****************************************";  
}
void startSec(){
    if ( start == false ){
    std::cout << "********** ROCK-PAPER-SCISSORS **********\n";
    std::cout << "NAME: ";
    getline (std::cin >> std::ws, playername);
    start = true;
    }
    std::cout << "| 1. ROCK" << "\n| 2. PAPER" << "\n| 3. SCISSORS\n";
    std::cout << "Choose your weapon: ";
    std::cin >> playeract;

    std::cin.clear();
    fflush(stdin);

        if ( playeract !=1 && playeract !=2 && playeract !=3) {
        std::cout << "@@ Invalid Weapon!\n";
        main();
    }
}
void resultText(std::string rcomp, std::string rplayer, std::string winner){
    std::cout << "COMP: " << rcomp << '\n' << playername << ": " << rplayer << '\n' << "# " << winner << " WON";
}
void playAgain(){
        std::cout << "\nPLAY AGAIN? y/n: ";
        std::cin >> again;
        while ( again != 'y' && again != 'n' && again != 'Y' && again != 'N'){
            std::cout << "Invalid answer. Play again? y/n: ";
            std::cin >> again;

            std::cin.clear();
            fflush(stdin);
        }    
}
