# CODSOFT
repository of guessing number 
#include<iostream>
#include<cstdlib>//for rand() and srand()
#include<ctime>
using namespace std;
int main(){
            srand(time(0));
    int Number=rand()%100+1;
    int guess=0;
        cout<<"Welcome to the number guessing game!"<<endl;
             while(guess!=Number){
                cout<<"guess a number between 1 to 100"<<endl;
                cin>>guess;
                if(guess>Number){
                    cout<<"Try again"<<endl;
                    cout<<"Too high "<<endl;
                }
                else if(guess<Number){
                    cout<<"Oops!you lose"<<endl;
                    cout<<"Too low"<<endl;

                }
                else{
                    cout<<"Congratulations!you won"<<endl;
                }

             }
             return 0;
}


