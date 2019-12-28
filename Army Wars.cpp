#include <iostream>
#include <ctime>
#include <cstdlib>
#include <unistd.h>
#include <fstream>
using namespace std;	

class StartClass{
	public:
		int ReturnSoldierCount(){
			return SoldierCount;
		}
	private:
		int SoldierCount=500;
};

class BattleClass{
	public:
		int Battle(int PlayerTeam,int NpcTeam){
			for(int PlayerTeam=500,int NpcTeam=500;true;PlayerTeam-=PlayerDeath&&NpcTeam-=NpcDeath){
				
				int PlayerDeath=randVal(0,100);
				int NpcDeath=randVal(0,100);
				
				PlayerTeam-=PlayerDeath;
				NpcTeam-=NpcDeath;
				
				cout<<"  Player's team population: "<<PlayerTeam<<endl;
				cout<<"  Npc's team population: "<<NpcTeam<<endl;
				
				if(PlayerTeam<0){
					cout<<"  Your army has been defeated... \n";
					sleep(3);
					return 1;
				}else if(NpcTeam<0){
					cout<<"  Your army is victorious! \n";
					sleep(3);
					return 2;
				}
				sleep(2);
				return 3;
			}
		}
		int randVal(int min,int max){
   			return (rand() % (max - min + 1) + min);
   		}
};

int main(){
	srand(time(NULL));
	StartClass Sobj;
	BattleClass Bobj;
	int PlayerTeam=Sobj.ReturnSoldierCount();
	int NpcTeam=Sobj.ReturnSoldierCount();
	int BattleTime=3;
	
	cout<<"  Player's team population: 500 \n";
	cout<<"  Npc's team population: 500 \n";
	
	sleep(2);
	
	while(BattleTime = 3){
		BattleTime=Bobj.Battle(PlayerTeam,NpcTeam);
	}
	return 0;
}
