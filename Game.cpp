#include <iostream>
#include <conio.h>

using namespace std;
//Functions Used
bool CheckValid(int);
void DrawBoard();
void TakeInput();
bool CheckValid(int);
void CheckWinner();
void SetGame();
void PlayAgain();
void Intro();

//Global Variables
bool play=false;
char Key[9]={};
int turn=0,moveno;
char Symbol[2];
string Player[2];
bool wincheck=false;
string winner;

//Function to draw the board
void DrawBoard(){
    system("cls");
    cout << "\n";
    cout << '\t' << Key[0] << "\t|\t" << Key[1] << "\t|\t" << Key[2];
    cout << "\n   -------------------------------------------\n";
    cout << '\t' << Key[3] << "\t|\t" << Key[4] << "\t|\t" << Key[5];
    cout << "\n   -------------------------------------------\n";
    cout << '\t' << Key[6] << "\t|\t" << Key[7] << "\t|\t" << Key[8];
    cout << "\n\n";
}

//Function to take move input from the players
void TakeInput(){
int move;
bool check=false;
do{
cout << Player[turn] << "'s Turn\nEnter Your Move: ";
cin >> move;
check=CheckValid(move);
}
while(check==false);
}

//Function to check if the move is valid or not
bool CheckValid(int move){
    if(Key[move-1]==Symbol[0] || Key[move-1]==Symbol[1]){
        cout << "Invalid Move: Space Already Occupied\n\n";
        return false;
    }
    if(move<=0 || move>9){
        cout << "Invalid Move: Out of Board (Enter between 1-9)\n\n";
        return false;
    }
    else{
    Key[move-1]=Symbol[turn];
    return true;
    }
}

//Function to decide the winner
void CheckWinner(){
    if(Key[0]==Symbol[turn] && Key[1]==Symbol[turn] && Key[2]==Symbol[turn] )winner=Player[turn];
    else if(Key[3]==Symbol[turn] && Key[4]==Symbol[turn] && Key[5]==Symbol[turn] )winner=Player[turn];
    else if(Key[6]==Symbol[turn] && Key[7]==Symbol[turn] && Key[8]==Symbol[turn] )winner=Player[turn];
    else if(Key[0]==Symbol[turn] && Key[3]==Symbol[turn] && Key[6]==Symbol[turn] )winner=Player[turn];
    else if(Key[1]==Symbol[turn] && Key[4]==Symbol[turn] && Key[7]==Symbol[turn] )winner=Player[turn];
    else if(Key[2]==Symbol[turn] && Key[5]==Symbol[turn] && Key[8]==Symbol[turn] )winner=Player[turn];
    else if(Key[0]==Symbol[turn] && Key[4]==Symbol[turn] && Key[8]==Symbol[turn] )winner=Player[turn];
    else if(Key[2]==Symbol[turn] && Key[4]==Symbol[turn] && Key[6]==Symbol[turn] )winner=Player[turn];
    else {
        if(turn==0)turn=1;
        else turn=0;
        moveno++;
        return;
    }
    wincheck=true;
    cout << Player[turn] << " Won! Good Game Guys\n\n";
}

//Function to set player names and other stuff
void SetGame(){
    system("cls");
    moveno=0;
    wincheck=false;
    for(int i=0;i<9;i++)
        Key[i]=' ';
    string name;
    cout << "Enter Player 1's Name:";
    cin >> name;
    Player[0]=name;
    cout << "\nEnter Player 2's Name:";
    cin >> name;
    Player[1]=name;
    Symbol[0]='O';
    Symbol[1]='X';
}

//Function to ask user for another game
void PlayAgain(){
    play=false;
    cout << "\n\nDo You Want To Play Again? (Press Y to play again)";
    char c;
    c=getch();
    if(c=='Y' || c=='y')play=true;
    else cout << "\nThank You for Playing!\n\n";
    
}

//Function to display on start of the game
void Intro(){
    system("cls");
    cout << "\n\t\t\t\tThe Classic Tic-Tac-Toe\n\n";
    cout << "Press any key to Start";
    getch();
}

//Function to run the whole game
void Run(){
    Intro();
    do{
        SetGame();
        DrawBoard();
    do{
        TakeInput();
        DrawBoard();
        CheckWinner();
        if(moveno==9){
        cout << "Game Drawn!\n";
        break;
        }
    }
    while(wincheck==false);
    PlayAgain();
    }
    while(play==true);
}

int main(){
    Run();
    cout << "Press any key to Exit!";
    getch();
}