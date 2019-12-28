#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int main(){
	ofstream FileObj;
	for(int x=0;x>5;x++){	
		const char y = "a";
		FileObj.open(y);
		cout<<"created "<<x<<endl;
	}
}
