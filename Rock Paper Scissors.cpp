#include <iostream>
#include <ctime>
#include <cstdlib>
#include <unistd.h>
using namespace std;

    int randVal(int min,int max){
   return (rand() % (max - min + 1) + min);
}

//BY HUNTER DRUM

int main() {
	
	int Player1 = 0;
	int Player2 = 0;
	int Player1Input;
	
	srand(time(NULL));
	
	cout<<"   -------------------------------- \n"<<"   Rock (1), Paper (2), Scissors (3) \n"<<"   -------------------------------- \n";
	
	for(int rps = 0; rps < 3; rps++){
	
    int BotInput;
    BotInput = randVal(1,3);
    cin>>Player1Input;
    switch (Player1Input) {
    	case 1:
    		cout<<"you picked rock \n";
    		break;
    	case 2:
    		cout<<"you picked paper \n";
    		break;
    	case 3:
    		cout<<"you picked scissors \n";
    		break;
    	default:
    		cout<<"INVALID INPUT!!! READ THE TOP!!! \n";
    		++++++rps;
	}
    
    if(Player1Input == 1 && BotInput == 3){
        cout<<"you won, they picked scissors"<<endl;
        ++Player1;
    }
    
    if(Player1Input == BotInput){
        cout<<"draw! "<<"you both picked the same thing"<<endl;
        --rps;
    }
    
    if(Player1Input == 1 && BotInput == 2){
        cout<<"you lost, they picked paper"<<endl;
        ++Player2;
    }
    
    if(Player1Input == 2 && BotInput == 1){
        cout<<"you won, they picked rock"<<endl;
        ++Player1;
    }
    
    if(Player1Input == 3 && BotInput == 1){
        cout<<"you lost, they picked rock"<<endl;
        ++Player2;
    }
    
    if(Player1Input == 2 && BotInput == 3){
       cout<<"you lost, they picked scissors"<<endl;
       ++Player2;
    }
    
    if(Player1Input == 3 && BotInput == 2){
       cout<<"you won, they picked paper"<<endl;
       ++Player1;
    }
    
    cout<<"your score is "<<Player1<<endl;
    cout<<"their score is "<<Player2<<endl;
}
	if(Player1 > Player2){
		cout<<endl<<"------------------- \n"
		<<"!!!!YOU WIN!!!! \n \n"<<"scores"<<endl;
		cout<<Player1<<" to "<<Player2<<endl;
	}
	else if(Player1 < Player2){
		cout<<endl<<"------------------- \n"
		<<"....you lose.... \n \n"<<"scores"<<endl;
		cout<<Player2<<" to "<<Player1<<endl;
	}
	else if(Player1 == Player2){
		cout<<endl<<"------------------- \n"
		<<"!DRAW! \n \n"<<"scores:"<<endl;
		cout<<Player1<<" and "<<Player2<<endl;
	}
	sleep(5);
	
    return 0;
}
