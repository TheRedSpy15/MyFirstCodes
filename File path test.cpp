#include <iostream>
#include <fstream>
using namespace std;
int main(){
	fstream FileObject("C:\\Users\\Hunter\\Documents\\FileTextFolder\\testtext.txt");
	if(FileObject.is_open()){
		cout<<"good to go";
		FileObject<<"it worked!";
		FileObject.close();
	}else{
		cout<<"failed";
	}
	return 0;
}
