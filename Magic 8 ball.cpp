#include <iostream>
#include <ctime>
#include <cstdlib>
#include <unistd.h>
using namespace std;

int randVal(int min,int max){
   return (rand() % (max - min + 1) + min);
}

int main(){
srand(time(NULL));
int plerq,xx;
cin>>plerq;
string ball8[] = {"ask again later","I don't care","sure, whatever","VERY MUCH SO!!","not a chance!","heck no!","indeed","what do I look like, a magic 8 ball??","why are you wasting time talking to a ball?","I don't have ears or a mout"};
xx= randVal(0,9);
cout<<"Magic 8 Ball says: "<<ball8[xx];
sleep(5);
return 0;
}
