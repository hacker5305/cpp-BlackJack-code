#include <iostream>
using namespace std;
#include <ctime>
#define nmax 53


int main() {
  int scelta,chiama;
  int giocatore[nmax], dealer[nmax];
  int g=0,d=0;
  srand(time(NULL));
  do{
    cout<<"Distribuisco le carte...."<<endl;
    for(int i=0; i<20;i++){
     giocatore[i]=rand()%10+1;
     dealer[i]=rand()%10+1;
    }
    cout<<"Le tue carte: "<<endl;
    cout<<giocatore[0]<<" "<<giocatore[1]<<endl;
    cout<<"Le carte del banco: "<<endl;
    cout<<dealer[0]<<" "<<"*"<<endl;
    g=giocatore[1]+giocatore[0];
    cout<<"------------------------------------------------"<<endl;
    int i=2;
    do{
      cout<<"Chiamare carta? (1 per chiamare)"<<endl;
      cin>>chiama;
      if(chiama==1){
      giocatore[i]=rand()%10+1;
      g=g+giocatore[i];
      } 
      cout<<"La somma delle tue carte è: "<<g<<endl;
      i++;
      if(g>21){
        cout<<"------------------------------------------------"<<endl;
        cout<<"Hai sballato"<<endl;
        return 0;
      }
    }while(chiama==1&&g<21);
    cout<<"------------------------------------------------"<<endl;
    cout<<"Il banco scopre le sue carte: "<<endl;
    cout<<dealer[0]<<" "<<dealer[1]<<endl;
    d=dealer[0]+dealer[1];
    i=2;
    do{
      cout<<"La somma delle carte del dealer è: "<<d<<endl;
      dealer[i]=rand()%10+1;
      d=d+dealer[i];
      i++;
      if(d>21){
        cout<<"La somma delle carte del dealer è: "<<d<<endl;
        cout<<"------------------------------------------------"<<endl;
        cout<<"Il banco ha sballato"<<endl;
        return 0;
      }
    }while(d<=17);
    cout<<"La somma delle carte del dealer è: "<<d<<endl;
    if(g>d){
      cout<<"------------------------------------------------"<<endl;
      cout<<"Hai vinto"<<endl;
    }
    else if(d==g){
      cout<<"------------------------------------------------"<<endl;
      cout<<"Pareggio"<<endl;
    }
    else{
      cout<<"------------------------------------------------"<<endl;
      cout<<"Hai perso"<<endl;
    }
  }while(scelta!=0);
}
