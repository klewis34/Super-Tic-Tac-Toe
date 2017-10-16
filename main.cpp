#include<iostream>
//#include "AI.cpp"
using namespace std;

char box[9]={'0','1','2','3','4','5','6','7','8'};

void playMove(char player,int choice){
   if(choice==0 && box[0]=='0')
     box[0]=player;
   else if(choice==1 && box[1]=='1')
     box[1]=player;
   else if(choice==2 && box[2]=='2')
     box[2]=player;
   else if(choice==3 && box[3]=='3')
     box[3]=player;
   else if(choice==4 && box[4]=='4')
     box[4]=player;
   else if(choice==5 && box[5]=='5')
     box[5]=player;
   else if(choice==6 && box[6]=='6')
     box[6]=player;
   else if(choice==7 && box[7]=='7')
     box[7]=player;
   else if(choice==8 && box[8]=='8')
     box[8]=player;
   else{
   cout<<"Please enter the valid move."<<endl;
   }

}
void board(){
  cout << "Tic Tac Toe";
  cout << "Player  (X)  -  AI (O)" << endl << endl;
  cout << endl;

  cout << "     |     |     " << endl;
  cout << "  " << box[0] << "  |  " << box[1] << "  |  " << box[2] << endl;

  cout << "_____|_____|_____" << endl;
  cout << "     |     |     " << endl;

  cout << "  " << box[3] << "  |  " << box[4] << "  |  " << box[5] << endl;

  cout << "_____|_____|_____" << endl;
  cout << "     |     |     " << endl;

  cout << "  " << box[6] << "  |  " << box[7] << "  |  " << box[8] << endl;

  cout << "     |     |     " << endl << endl;

}
int gameStatus(){
  if( (box[0]==box[1] && box[1]==box[2]) || (box[3]==box[4] && box[4]==box[5]) || (box[6]==box[7] && box[7]==box[8]) ||
  (box[0]==box[4] && box[4]== box[8]) || (box[2]==box[4] && box[4]== box[6]) || (box[0]==box[3] && box[3]==box[6]) ||
  (box[1]==box[4] && box[4]==box[7]) || (box[2]==box[5] && box[5]== box[7]) ){
    return 1;
  }
  else if(box[0]!='0' && box[1]!='1' && box[2]!='2' && box[3]!='3' && box[4]!='4' && box[5]!='5' && box[6]!='6' && box[7] !='7' && box[8]!='8'){
    return 0;
  }
  else{
    return -1;
  }
}
void playAI(char sign){
    for(int i=0; i<9; i++){
      if(box[i]=='X'){
        if(i!=4 && box[4]!='O'){
          playMove(sign,4 );
        }
        else if((i ==0 &&  i == 1) || (i==0 && i == 2) || (i==1 && i==2)){
          if(box[0] =='0')playMove(sign, 0);
          if(box[1] =='1')playMove(sign, 1);
          if(box[2] =='2')playMove(sign, 2);
        }
        else if( (i==0 && i == 3)  || (i==3 && i ==6) || (i==0 && i ==6)){
          if(box[0] =='0')playMove(sign, 0);
          if(box[3] =='3')playMove(sign, 3);
          if(box[6] =='6')playMove(sign, 6);;
        }
        else if( (i==6 && i == 7)  || (i==7 && i ==8) || (i==6 && i ==8)){
          if(box[6] =='6')playMove(sign, 6);
          if(box[7] =='7')playMove(sign, 7);
          if(box[6] =='8')playMove(sign, 8);;
        }
        else if( (i==2 && i == 5)  || (i==5 && i ==8) || (i==2 && i ==8)){
          if(box[2] =='2')playMove(sign, 2);
          if(box[5] =='5')playMove(sign, 5);
          if(box[8] =='8')playMove(sign, 8);;
        }

      }
    }
}
int main(){
  int  player =1;
  char sign;
  int status, choice, mode;
  char mark;
  int drawCount=0;
  cout<<"Please enter 1 for USER VS AI and 2 for AI VS AI."<<endl;
  cin>>mode;
  if(mode==1){
    do{
      player=(player%2)?1:2;
      sign=(player == 1) ? 'X' : 'O';
      board();
      cout<<"Please enter a move for User"<<endl;
      cin>>choice;
      playMove(sign, choice);
      status=gameStatus();
      board();
      player--;
      sign=(player==1)?'X' :'O';
      playAI(sign);
      board();
      status=gameStatus();
      player++;
  }
    while(status==-1);
    if(status==1){
      cout<<"Player"<< sign <<"won"<<endl;
    }
    else if(status==0){
      cout<<"Game Draw."<<endl;
      drawCount++;
    }
  }
  else{
    cout<<"AI VS AI mode."<<endl;
  }
    return 0;
}


