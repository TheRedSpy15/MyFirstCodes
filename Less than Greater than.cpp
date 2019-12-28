//loads libraries 
#include <iostream>
#include <cstdlib>
#include <ctime> 

//uploaded March 3 2017
//updated to version 1.03 on March 5 2017 
//created by TheRedSpy

//input a number and try to get above the first number
//but lower than the second number 

using namespace std;

//creates randVal function with rand 
int randVal(int min,int max){
   return (rand() % (max - min + 1) + min);
}

 //creates main function 
 int main()
 {
    //declares int
    int playerinput;
    
    //outputs and then asks for value of int
    cout << "input a dang number less than x, \n" <<  "but higher than y \n";
    cin >> playerinput;
    
    //makes random value for int x by calling randVal function 
    srand(time(NULL));
    int x = randVal(5,16);
    
    //same but with int y
    int y = randVal(10,22);
    
    //if and then else then if then 
    if(playerinput >= x && playerinput <= y){
        cout << "good job \n";
    }
    else{
        cout << "you suck \n";
        if(x > y){
           cout << "you got screwed! \n";
        }
    }
    //outputs message and values of int x and y
    cout << "it was " << x << " and " << y << " you scrub! \n";
    
    return 0;
 }
