#include Game.cpp
#include AI.cpp
#include<iostream>
using namespace std;

int main(){
int mode;
cout<<"Please choose the mode"<<endl;
cout<<"Enter 1 for USER VS AI and 2 for AI VS AI."<<endl;
cin>>mode;
if(mode==1){

  //GAME FOR USER VS AI.
}
else if(mode==2){

  //GAME FOR AI VS AI.
}
else{
cout<<"INVALID INPUT !!!"<<endl;
cout<<"Please enter 1 for USER VS AI and 2 for AI VS AI."<<endl;
cin>>mode;
}


return 0;
}
