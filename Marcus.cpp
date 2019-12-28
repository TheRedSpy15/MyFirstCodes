#include <iostream>
#include <ctime>
#include <cstdlib>
#include <unistd.h>
using namespace std;

	int randVal(int min,int max){
	  		return (rand() % (max - min + 1) + min);
	}

class AI{
	
	string UserInput;
	
	string AIConversation[4][5]={ {"It worked!"}, {"Hello!","Hi","Hi there","Sup!"}, {"Goodbye!","Have a good one!","Cya later!","Later!","Bye"} ,{"I am an AI. CodeName: Marcus"
		,"My name is Marcus. I'm an advanced AI. Currently, I'm still in development but am planned to be skynet"} };
	
	public:
		void AIFunction(){
			
			cin>>UserInput;
			
			if(UserInput=="test"||"Test"){
				
				cout<<UserInput<<endl;
				cout<<AIConversation[1][0]<<endl;
			}
			
			if(UserInput=="hello"||"Hello!"||"Hello"||"Hi"||"Hi there!"||"hi"||"hi there"){
				
				cout<<UserInput<<endl;
				cout<<AIConversation[2][randVal(0,3)]<<endl;
			}
			
			if(UserInput=="Goodbye"||"goodbye"||"bye"||"cya"||"later"||"Bye"||"Cya"||"Latter"){
				
				cout<<UserInput<<endl;
				cout<<AIConversation[3][randVal(0,4)]<<endl;
			}
			
			if(UserInput=="who are you?"||"what are you?"||"who are you"||"what are you"){
				
				cout<<UserInput<<endl;
				cout<<AIConversation[4][randVal(0,1)]<<endl;
			}
		}
};

int main(){
	
	srand(time(NULL));
	
	AI obj;
	
	obj.AIFunction();
	
	return 0;
}
