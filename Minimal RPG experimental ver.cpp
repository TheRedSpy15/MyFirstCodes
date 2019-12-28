#include <iostream>
#include <ctime>
#include <cstdlib>
#include <unistd.h>
#include <fstream>
using namespace std;

class PlayerClass{
	public:
		int ReturnName(){
			return Name;
		}
		int ReturnLastName(){
			return lastName;
		}
		int ReturnHealth(){
			return Health;
		}
		int ReturnGold(){
			return StartGold;
		}
		int ReturnSword(){
			return StartSword;
		}
		int ReturnShield(){
			return StartShield;
		}
		int randVal(int min,int max){
   			return (rand() % (max - min + 1) + min);
   		}
   	private:
		int const Name = randVal(0,4);
		int const lastName = randVal(0,3);
		int const Health = 100;
		int const StartGold = 50;
		int const StartSword = 20;
		int const StartShield = 5;
};

	int main(){
		
		srand(time(NULL));
		PlayerClass obj;
		
		fstream SaveStats("RPGstats.txt");
		ifstream LoadStats("RPGstats.txt");
		
		if(SaveStats.is_open()){//CHECK IF SAVE FILE IS OPEN
			cout<<"Saved stat file open! \n \n";
		}else{
			cout<<"Saved stat file NOT open!! \n \n";
		}
		
		int GetHealth=obj.ReturnHealth();
		int GetName=obj.ReturnName();
		int GetLastName=obj.ReturnLastName();
		int GetGold=obj.ReturnGold();
		int PlayerInput;
		int GetSword=obj.ReturnSword();
		int GetShield=obj.ReturnShield();
		int StoreInput;
		int AppleInventory;
		int UseApple;
		
		cout<<"continue where you left off? 1(yes)/0(no) \n";
		int SaveInput;
		cin>>SaveInput;
		if(SaveInput==1){
			cout<<"loading 'em up! \n \n \n";//LOAD SAVE
			LoadStats>>GetHealth>>GetName>>GetLastName>>GetGold>>GetSword>>GetShield>>AppleInventory;//NOTE: DO NOT USE SPACES WHEN READING!! WONT COMPILE!!
			LoadStats.close();
		}
		
		string FirstNameArray[]={"Joe","John","Jack","Jerry","Tomas","Mike"};
		string LastNameArray[]={"Smith","White","Drum","Austin"};
		string PeopleArray[]={"Billy the Shop keeper","Marcus the cowboy"};
		string PeopleInteractions[]={"who seemed to be in a rush","was very kind"};
		
		cout<<"  Name: "<<FirstNameArray[obj.ReturnName()]<<" "<<LastNameArray[obj.ReturnLastName()]<<endl;
		cout<<"  Health: "<<obj.ReturnHealth()<<endl;
		
		for(int DaysAlive=1; true; DaysAlive++){
			cout<<endl;
			
			cout<<"  Days alive: "<<DaysAlive<<endl<<"  Health: "<<GetHealth<<endl;
			cout<<"  Do you want to: \n"<<"  (1) Store (2) Set Out (3) Stats (4) Manual (5) Save \n";
			
			try{
			cin>>PlayerInput;
			if(PlayerInput<1 || PlayerInput>5){
				throw 101;
			}
		}catch(int x){
			cout<<"  ERROR - 101 : !INVALID INPUT! \n";
			--DaysAlive;
		}
			if(PlayerInput==1){//STORE
				cout<<"  ------------------------------------------------------------------------ \n";
				cout<<"  Purchase: (1) Apple (2) Sword Upgrade (3) Shield Upgrade (4) Exit Store \n";
				cout<<"  Gold: "<<GetGold<<endl;
				cin>>StoreInput;
				switch (StoreInput){
					case 1:
						if(GetGold>=20){
							++AppleInventory;
							GetGold-=20;
							cout<<"  Purchased: Apple \n"<<"  Apples: "<<AppleInventory<<endl;
						}else{
							cout<<"  Sorry... You don't have enough gold \n";
						}
						break;
					case 2:
						if(GetGold>=50){
							GetSword+=5;
							GetGold-=50;
							cout<<"  Purchased: Sword Upgrade \n"<<"  Sword Damage: "<<GetSword<<endl;
						}else{
							cout<<"  Sorry... You don't have enough gold \n";
						}
						break;
					case 3:
						if(GetGold>=50){
							GetShield+=5;
							GetGold-=50;
							cout<<"  Purchased: Shield Upgrade \n"<<"  Shield stat: "<<GetShield<<endl;
						}else{
							cout<<"  Sorry... You don't have enough gold \n";
						}
						break;
				}
				--DaysAlive;
				cout<<"  --------------- \n";
			}
			if(PlayerInput==2){//SET OUT
				cout<<"  --------------- \n";
				for(int PlayerActions=0;PlayerActions < 10;PlayerActions++){
					
					int MonsterChance;
					int FindChance;
					
					if(true){
						int MonsterChance=obj.randVal(0,10);
						int FindChance=obj.randVal(0,15);
					
						cout<<"  Walking... "<<endl;
						sleep(1);
						if(MonsterChance>=8){
							cout<<MonsterChance<<endl;
							int MonsterSelection=obj.randVal(1,3);
							int BanditAttack=obj.randVal(10,40);
							int OrcAttack=obj.randVal(35,75);
							int BearAttack=obj.randVal(15,30);
							
							switch(MonsterSelection){
								case 1://Orc
									cout<<"  You were attacked by an Orc! \n";
									if(GetSword>OrcAttack){
										cout<<"  You managed to beat him... due to your superior sword! \n";
									}
									else if(GetSword<OrcAttack){
										OrcAttack-=GetShield;
										GetHealth-=OrcAttack;
										if(GetHealth<=0){
											cout<<"  You were Killed by the Orc... \n";
											sleep(4);
											return 0;
										}
										cout<<"  Your Health is: "<<GetHealth<<endl<<endl;
										PlayerActions=10;
										sleep(2);
									}
									break;
								case 2://Bandit
									cout<<"  You were attacked by a Bandit \n";
									if(GetSword>BanditAttack){
										cout<<"  You managed to beat him... due to your superior sword! \n";
									}
									else if(GetSword<OrcAttack){
										BanditAttack-=GetShield;
										GetHealth-=BanditAttack;
										if(GetHealth<=0){
											cout<<"  You were Killed by the Bandit... \n";
											sleep(4);
											return 0;
										}
										cout<<"  Your Health is: "<<GetHealth<<endl<<endl;
										PlayerActions=10;
										sleep(2);
									}
									break;
								case 3://Bear
									cout<<"  You were attacked by a Bear! \n";
									OrcAttack-=GetShield;
									GetHealth-=OrcAttack;
									if(GetHealth<=0){
										cout<<"  You were Killed by the Bear... \n";
										sleep(4);
										return 0;
									}
									cout<<"  You got away with "<<GetHealth<<" Health left"<<endl<<endl;
									PlayerActions=10;
									sleep(2);
									break;
							}
							break;
						}
						if(FindChance==15){//Finds
							cout<<FindChance<<endl;
							int FindSelect=obj.randVal(0,2);
							int PeopleSelect=obj.randVal(0,1);
							int PeopleInteractSelect=obj.randVal(0,1);
							int GoldFindAmount=obj.randVal(5,50);
							
							switch (FindSelect){
								case 0:
									cout<<"  You found an apple \n";
									++AppleInventory;
									break;
								case 1:
									cout<<"  You found "<<GoldFindAmount<<" Gold! \n";
									GetGold+=GoldFindAmount;
									break;
								case 2:
									cout<<"  You encountered "<<PeopleArray[PeopleSelect]<<" Who "<<PeopleInteractions[PeopleInteractSelect]<<endl;
									break;
							}
						}
						sleep(2);
					}
			}
		}
			if(PlayerInput==3){//VIEW STATS
				cout<<"  ----------------------------- \n";
				cout<<"    STATS: \n";
				cout<<"  Name: "<<FirstNameArray[obj.ReturnName()]<<" "<<LastNameArray[obj.ReturnLastName()]<<endl;
				cout<<"  Health: "<<GetHealth<<endl;
				cout<<"  Gold: "<<GetGold<<endl;
				cout<<"  Days Lived: "<<DaysAlive<<endl;
				cout<<"  Sword Damage: "<<GetSword<<endl;
				cout<<"  Shield damage block: "<<GetShield<<endl;
				cout<<"  Appeles: "<<AppleInventory<<endl<<endl;
				cout<<"  Do you want to use an apple and replenish 50 Health? 1(yes)/0(no) \n";
				
				try{
					cin>>UseApple;//USE APPLE
					if(UseApple>1||UseApple<0){
						throw 102;
					}
				}catch(int x){
					cout<<"  ERROR - 102 : !INVALID INPUT! \n";
				}
				if(UseApple==1){
					if(AppleInventory<=0){
						cout<<"  Sorry... You don't have any apples \n";
					}
				}
				if(UseApple==0){
					cout<<"  Ok then... \n";
				}
				cout<<endl;
				--DaysAlive;
				cout<<"  ------------ \n";
			}
			if(PlayerInput==4){
				cout<<"  ---MANUAL--- \n";
				cout<<"  Sword: If your sword is more powerful then the attacker's \n"<<"  then you kill them without getting hurt. \n"<<"  NOTE: only applies to enemies that use swords, unlike a Bear! \n \n";
				cout<<"  Shield: If your sword isn't powerful enough... \n"<<"  then your sheild will shave off the attacker's damaged. \n \n";
				cout<<"  Apple: When used, they give you 50 health. \n \n";
				cout<<"  ------------ \n";
				--DaysAlive;
			}
			if(PlayerInput==5){//SAVE GAME
				SaveStats<<GetHealth<<" "<<GetName<<" "<<GetLastName<<" "<<GetGold<<" "<<GetSword<<" "<<GetShield<<" "<<AppleInventory;
				SaveStats.close();//VERY IMPORTANT TO CLOSE A FILE OR IT WONT SAVE AT ALL!!!
				cout<<"saved! \n \n"<<"  ------------ \n";
			}
		}
		return 0;
	}
