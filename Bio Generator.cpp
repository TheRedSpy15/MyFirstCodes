#include <iostream>
#include <ctime>
#include <cstdlib>
#include <unistd.h>
using namespace std;

    int randValA(int min,int max){
   return (rand() % (max - min + 1) + min);
}

    int randValB(int min,int max){
   return (rand() % (max - min + 1) + min);
}

    int randValC(int min,int max){
   return (rand() % (max - min + 1) + min);
}

    int randValD(int min,int max){
   return (rand() % (max - min + 1) + min);
}

    int randValE(int min,int max){
   return (rand() % (max - min + 1) + min);
}

    int randValF(int min,int max){
   return (rand() % (max - min + 1) + min);
}

    int main() {

    string nameA[] = {"bob marb","justin stiker","Hunter Drum","Donald Trump"};
    string ageF[] = {"9 years old.","21 years old.","14 years old.","18 years old.","70 years old."};
    string heightB[] = {"short","very tall","a midget"};
    string famlyD[] = {"You have no siblinga","You are an only child","You have a sister","You have a brother","You have 20 sisters!! GOD HAVE MERCY ON YOUR SOUL!!!"};
    string parntsE[] = {"your parents died when you were young.","you only have your mother.","you only have your father.","you have the best parents in the world!","your parents are looong dead."};
    string persnsC[] = {"into c++, the greatest language of them all","stupid...","THE GREATEST CODER EVER","GOING TO MAKE CODING GREAT AGAIN!!","a LEGEND!!","really dang strange...","a weirdo.","a lonely coder..."};

	srand(time(NULL));
    int aa = randValA(0,3);
    int bb = randValB(0,2);
    int cc = randValC(0,7);
    int dd = randValD(0,4);
    int ee = randValE(0,4);
    int ff = randValF(0,4);
    
    cout<<"You are "<<nameA[aa]<<" and you are "<<heightB[bb]<<endl;
    cout<<"at the age of "<<ageF[ff]<<endl;
    cout<<famlyD[dd]<<" and "<<parntsE[ee]<<endl;
    cout<<"lastly..."<<endl;
    cout<<"You are "<<persnsC[cc];

	sleep(6);
	
    return 0;
}
