#include<iostream>
#include<conio.h>
using namespace std;
char board[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
char t='x';
int row,col;
bool draw = true;
void display(){
    system("cls");
    cout<<"\n\n\t\t\tTIC TAC TOE Game";
    cout<<"\n\n\t-------------------------------------------------";
    cout<<"\n\t|\t\t|\t\t|\t\t|";
    cout<<"\n\t|\t"<<board[0][0]<<"\t|\t"<<board[0][1]<<"\t|\t"<<board[0][2]<<"\t|";
    cout<<"\n\t|\t\t|\t\t|\t\t|";
    cout<<"\n\t-------------------------------------------------";
    cout<<"\n\t|\t\t|\t\t|\t\t|";
    cout<<"\n\t|\t"<<board[1][0]<<"\t|\t"<<board[1][1]<<"\t|\t"<<board[1][2]<<"\t|";
    cout<<"\n\t|\t\t|\t\t|\t\t|";
    cout<<"\n\t-------------------------------------------------";
    cout<<"\n\t|\t\t|\t\t|\t\t|";
    cout<<"\n\t|\t"<<board[2][0]<<"\t|\t"<<board[2][1]<<"\t|\t"<<board[2][2]<<"\t|";
    cout<<"\n\t|\t\t|\t\t|\t\t|";
    cout<<"\n\t-------------------------------------------------";

}
bool play(){
    for(int i=0;i<3;i++){
        if((board[i][0] == board[i][1] && board[i][0] == board[i][2]) || (board[0][i]==board[1][i] && board[0][i] == board[2][0])){
            draw = false;
            return false;
        }
        if((board[0][0]==board[1][1] && board[0][0]==board[2][2]) || (board[0][3]==board[1][1] && board[0][3]==board[2][0])){
            draw = false;
            return false;
        }
    }
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(board[i][j] != 'x' && board[i][j] != 'y'){
                return true;
            }
        }
    }
    draw = true;
    return false;
}

void game()
{
    int choice;
    p:
    if(t=='x'){
        cout<<"\n\n\n\t Player 1 [x] Turn :";
    }
    else{
        cout<<"\n\n\n\t Player 2 [y] Turn :";
    }
    cin>>choice;
    switch (choice)
    {
    case 1:row=0;col=0;
        break;
    case 2:row=0;col=1;
        break;
    case 3:row=0;col=2;
        break;
    case 4:row=1;col=0;
        break;
    case 5:row=1;col=1;
        break;                
    case 6:row=1;col=2;
        break;
    case 7:row=2;col=0;
        break;
    case 8:row=2;col=1;
        break;
    case 9:row=2;col=2;
        break;                
    default: cout<<"\n\n\n\t Invalid Key..Please Try Again...";
    getch();
    goto p;
        break;
    }

    if(t=='x' && board[row][col] != 'x' && board[row][col] != 'y'){
        board[row][col] = 'x';
        t='y';
    }
    else if(t=='y' && board[row][col] != 'x' && board[row][col] != 'y'){
        board[row][col] = 'y';
        t='x';
    }
    else{
        cout<<"\n\n\n\t Index is already Filled...Please Try Again..";
        getch();
    }
    display();
}
main(){
    while (play())
    {
        display();
        game();
    }
    if(t=='x' && draw==false){
        cout<<"\n\n\n\tPlayer 2 [y] is winner congratulation...";
    }
    else if(t=='y' && draw==false){
        cout<<"\n\n\n\t Player 1 [x] is winner congratulation...";
    }
    else{
        cout<<"\n\n\n\t Game is Drawn..";
    }
    getch();
    return 0;
}