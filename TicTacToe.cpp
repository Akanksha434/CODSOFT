#include <iostream>
using namespace std;
char A[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
char turn= 'X';
int row,column;
bool draw = false;
void display_A()
{
  cout << "       ***  Tick Tac Toe Game  *** " << endl;
  cout << "           Play with your partner" << endl;
  cout << "              Relax and Enjoy \n" << endl;
  cout << "\tPlayer1 [X] \n\tPlayer2[0]\n\n" << endl;
  cout << "\t\t   |   |   \n";
  cout << "\t\t " << A[0][0] << " | " << A[0][1] << " | " << A[0][2] << " \n";
  cout << "\t\t___|___|___\n";
  cout << "\t\t   |   |   \n";
  cout << "\t\t " << A[1][0] << " | " << A[1][1] << " | " << A[1][2] << " \n";
  cout << "\t\t___|___|___\n";
  cout << "\t\t   |   |   \n";
  cout << "\t\t " << A[2][0] << " | " << A[2][1] << " | " << A[2][2] << " \n";
  cout << "\t\t   |   |   \n";
}
void player_turn(){
  int choice;

  if(turn == 'X')
  cout << "\n\tPlayer1 [X] turn:";

  if(turn == 'O')
    cout << "\n\tPlayer2 [O] turn:";
  cin >> choice;
  switch (choice) {
    case 1: row =0; column =0; break;
    case 2: row =0; column =1; break;
    case 3: row =0; column =2; break;
    case 4: row =1; column =0; break;
    case 5: row =1; column =1; break;
    case 6: row =1; column =2; break;
    case 7: row =2; column =0; break;
    case 8: row =2; column =1; break;
    case 9: row =2; column =2; break;

    default:
      cout<< "Invalid choice\n";
      break;
  }
  if(turn == 'X' && A[row][column]!='X' && A[row][column]!='O')
  {
    A[row][column] = 'X';
    turn = 'O';
  }
  else if(turn == 'O' && A[row][column]!='X' && A[row][column]!='O')
  {
    A[row][column] = 'O';
    turn = 'X';
  }
  else
  {
    cout << "Box already filled!\nPlease choose another!!\n";
    player_turn();
  }
  display_A();
}
bool gameover()
{
   //check win
  for(int i=0; i<3; i++)
    if(A[i][0] == A[i][1] && A[i][0] == A[i][2] || A[0][i] == A[1][i] && A[0][i] == A[2][i])
    return false;
  //check diagonal win
    if(A[0][0] == A[1][1] && A[0][0] == A[2][2] || A[0][2] == A[1][1] && A[0][0] == A[2][0])
    return false;
  //there is any box not filled
  for(int i=0; i<3; i++)
  for(int j=0; j<3; j++)
    if(A[i][j] != 'X' && A[i][j] != 'O')
      return true;
    //draw
      draw = true;
      return false;
}
int main() {
  
  
  while(gameover())
{
  display_A();
  player_turn();
  gameover();
}

  if(turn == 'X' && draw == false)
    cout << "\n\tPlayer2 [O] Wins!!\n";
  else if(turn == 'O' && draw == false)
    cout << "\n\tPlayer1 [X] Wins!!\n";
  else
    cout << "\n\tGame Draw!!\n";
  return 0;
}