#include <iostream>
using namespace std;

class TesterCla{
	public:
		int ReturnXer(){
			return x;
		}
	private:
		int x = 4;
};

int main(){
	TesterCla obj;
	cout<<obj.ReturnXer();
	obj.ReturnXer() = 2;
	cout<<obj.ReturnXer();
}
