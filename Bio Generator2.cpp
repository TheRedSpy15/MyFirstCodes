#include <iostream>
#include <ctime>
#include <cstdlib>
#include <unistd.h>
using namespace std;

    int randValA(int min,int max){
   return (rand() % (max - min + 1) + min);
}

    int randValH(int min,int max){
   return (rand() % (max - min + 1) + min);
}

    int randValAT(int min,int max){
   return (rand() % (max - min + 1) + min);
}

int main(){
	srand(time(NULL));
	string uName;
	cin>>uName;
	cout<<"----------------------- \n \n";
	int hh,at;
	int uAge = randValA(9,99);
	string uHeight[] = {"midget","Catie height","average","tall","super tall","Nick height!!!"};
	string uAttributes[] = {"worksout (you wish)","plays video games","writes code","lazy","eats nonstop!","Just flatout cool!"};
	hh = randValH(0,5);
	at = randValAT(0,5);
	cout<<"Name: "<<uName<<endl<<"Age: "<<uAge<<endl<<"Height: "<<uHeight[hh]<<endl<<"Characteristics: "<<uAttributes[at];
	sleep(5);
}
