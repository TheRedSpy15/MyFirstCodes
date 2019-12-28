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
		int ReturnSwordLevel(){
			return StartSwordLevel;
		}
		int ReturnShieldLevel(){
			return StartShieldLevel;
		}
		int ReturnDaysAlive(){
			return StartDays;
		}
		int ReturnApples(){
			return StartApples;
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
		int const StartSwordLevel = 1;
		int const StartShieldLevel = 1;
		int const StartDays = 1;
		int const StartApples = 0;
};

	int main(){
		system("Color A");//Set Color
		
		srand(time(NULL));//Plant rand() seed
		PlayerClass obj;//bring in the playerclass with an object
		
		//Create objects to open read and write to the file
		fstream SaveStats;//Saves
		ifstream LoadStats("RPGstats.txt");//loads
		
		if(SaveStats.is_open()&&LoadStats.is_open()){//CHECK IF SAVE FILE IS OPEN
			cout<<"Saved stat file open! \n \n";
		}else{
			system("Color C");
			cout<<"Saved stat file NOT open!! \n \n";
		}
		
		system("Color A");
		
		int GetHealth=obj.ReturnHealth();
		int GetName=obj.ReturnName();
		int GetLastName=obj.ReturnLastName();
		int GetGold=obj.ReturnGold();
		int PlayerInput;
		int GetSword=obj.ReturnSword();
		int GetShield=obj.ReturnShield();
		int StoreInput;
		int AppleInventory=obj.ReturnApples();
		int UseApple;
		int SwordLevel=obj.ReturnSwordLevel();
		int ShieldLevel=obj.ReturnShieldLevel();
		int PlayerNpcInteractInput;
		int DaysAlive=obj.ReturnDaysAlive();
		int ThiefDecision;
		
		cout<<"continue where you left off? !WARNING VERY GLITCHY!  1(yes)/0(no) \n";
		int SaveInput;
		cin>>SaveInput;
		if(SaveInput==1){
			cout<<"loading 'em up! \n \n \n";//LOAD SAVE
			LoadStats>>GetHealth>>GetName>>GetLastName>>GetGold>>GetSword>>GetShield>>AppleInventory>>SwordLevel>>ShieldLevel>>DaysAlive;//NOTE: DO NOT USE SPACES (" ") WHEN READING!! WONT COMPILE!!
			LoadStats.close();
		}else{
			cout<<"ok then... \n \n \n";
		}
		
		string FirstNameArray[]={"Joe","John","Jack","Jerry","Tomas","Mike"};
		string LastNameArray[]={"Smith","White","Drum","Austin"};
		string PeopleArray[]={"Billy the Shop keeper","Marcus the cowboy","Shelly your neighbor","Your friend Adam","A stranger"};
		string PeopleInteractions[]={"who seemed to be in a rush","was very kind","was really rude!","was running away from something...","needs an apple!"};
		
		cout<<"  Name: "<<FirstNameArray[GetName]<<" "<<LastNameArray[GetLastName]<<endl;
		cout<<"  Health: "<<GetHealth<<endl;
		
		for(;true; DaysAlive++){
			cout<<endl;
			
			cout<<"  Days alive: "<<DaysAlive<<endl<<"  Health: "<<GetHealth<<endl;
			cout<<"  Do you want to: \n"<<"  (1) Store (2) Set Out (3) Stats (4) Manual (5) Save \n";
			
			try{//error catching (exceptions)
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
				cout<<"  Purchase: (1) Apple: $20 (2) Sword Upgrade: $50 (3) Shield Upgrade: $50 (4) Exit Store \n";
				cout<<"  Gold: "<<GetGold<<endl;
				cin>>StoreInput;
				switch (StoreInput){
					case 1:
						if(GetGold>=20){
							++AppleInventory;
							GetGold-=20;
							cout<<"  Purchased: Apple \n"<<"  Apples: "<<AppleInventory<<endl;
						}else{
							cout<<"  Sorry... You don't have enough gold \n \n";
						}
						break;
					case 2:
						if(GetGold>=50&&SwordLevel<5){
							GetSword+=5;
							SwordLevel++;
							GetGold-=50;
							cout<<"  Purchased: Sword Upgrade \n"<<"  Sword Damage: "<<GetSword<<endl;
							cout<<"  Sword Level: "<<SwordLevel<<"   Max Level: 5 \n \n";
						}else if(GetGold<50){
							cout<<"  Sorry... You don't have enough gold \n \n";
						}else if(SwordLevel>=5){
							cout<<"  Sorry... Your sword is at max level \n \n";
						}
						break;
					case 3:
						if(GetGold>=50&&ShieldLevel<5){
							GetShield+=5;
							ShieldLevel++;
							GetGold-=50;
							cout<<"  Purchased: Shield Upgrade \n"<<"  Shield stat: "<<GetShield<<endl;
							cout<<"  Shield Level: "<<ShieldLevel<<"    Max Level: 5 \n \n";
						}else if(GetGold<50){
							cout<<"  Sorry... You don't have enough gold \n";
						}else if(SwordLevel>=5){
							cout<<"  Sorry... Your shield is at max level \n \n";
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
					
					if(true){//to make truely random
						int MonsterChance=obj.randVal(0,10);
						int FindChance=obj.randVal(0,20);
					
						cout<<"  Walking... "<<endl;
						sleep(1);
						if(MonsterChance>=8){
							int MonsterSelection=obj.randVal(1,5);
							int BanditAttack=obj.randVal(10,40);
							int OrcAttack=obj.randVal(35,75);
							int BearAttack=obj.randVal(15,30);
							int ThiefStealChance=obj.randVal(0,100);
							int ThiefStealSelect=obj.randVal(1,2);
							int ThiefThankfulChance=obj.randVal(0,1);
							
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
										PlayerActions=10;
										sleep(2);
									}
									break;
								case 2://Bandit
									cout<<"  You were attacked by a Bandit \n";
									if(GetSword>BanditAttack){
										cout<<"  You managed to beat him... due to your superior sword! \n";
									}
									else if(GetSword<BanditAttack){
										BanditAttack-=GetShield;
										GetHealth-=BanditAttack;
										if(GetHealth<=0){
											cout<<"  You were Killed by the Bandit... \n";
											sleep(4);
											return 0;
										}
										PlayerActions=10;
										sleep(2);
									}
									break;
								case 3://Bear
									cout<<"  You were attacked by a Bear! \n";
									OrcAttack-=GetShield;
									GetHealth-=BearAttack;
									if(GetHealth<=0){
										cout<<"  You were Killed by the Bear... \n";
										sleep(4);
										return 0;
									}
									cout<<"  You managed to get away with some Health left"<<endl;
									PlayerActions=10;
									sleep(2);
									break;
								case 4://Thief
									cout<<"  You encountered a thief!! \n";
									if(ThiefStealChance>=50){
										if(ThiefStealSelect==1&&AppleInventory>0){
											cout<<"  He stole an apple!! \n";
											--AppleInventory;
										}else if(ThiefStealSelect==2&&GetGold>0){
											cout<<"  He stole all your gold!! \n";
											GetGold=0;
										}
									}else if(ThiefStealChance<50){
										cout<<"  You caught him! What will you do with him? (1) kill him (2) let him go \n";
										cin>>ThiefDecision;
										if(ThiefDecision==1){
											cout<<"  the deed is done... \n";
										}else if(ThiefDecision==2){
											if(ThiefThankfulChance==1){
												cout<<"  He gave you ";
												if(ThiefStealSelect==1){
													cout<<"  an apple for letting him free \n";
													++AppleInventory;
												}else{
													cout<<"  50 gold for letting him free \n";
													GetGold+=50;
												}
											}else if(ThiefThankfulChance==0){
												cout<<"  you let him go \n";
											}
										}
									}
									break;
								case 5://Bandit 2 (to increase the chance of a bandit)
									cout<<"  You were attacked by a Bandit \n";
									if(GetSword>BanditAttack){
										cout<<"  You managed to beat him... due to your superior sword! \n";
									}
									else if(GetSword<BanditAttack){
										BanditAttack-=GetShield;
										GetHealth-=BanditAttack;
										if(GetHealth<=0){
											cout<<"  You were Killed by the Bandit... \n";
											sleep(4);
											return 0;
										}
										PlayerActions=10;
										sleep(2);
									}
									break;
							}
						}
						if(FindChance>=10){//Finds
							int FindSelect=obj.randVal(0,3);
							int PeopleSelect=obj.randVal(0,4);
							int PeopleInteractSelect=obj.randVal(0,4);
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
									if(PeopleInteractSelect==4){
										cout<<"  Do you want to give them an apple? 1(yes)/0(no) \n";
										cin>>PlayerNpcInteractInput;
										if(PlayerNpcInteractInput==1){
											if(AppleInventory>0){
												cout<<"  You gave them an apple \n"<<"  In return, they gave you "<<GoldFindAmount<<" gold! \n";
												GetGold+=GoldFindAmount;
												--AppleInventory;
											}else{
												cout<<"  Unfortunatly... you don't have any apples \n";
											}
										}
									}
									break;
							}
						}
						sleep(2);
					}
			}
		}
			if(PlayerInput==3){//VIEW STATS
				cout<<"  ----------------------------- \n";
				cout<<"           STATS: \n";
				cout<<"  Name                : "<<FirstNameArray[GetName]<<" "<<LastNameArray[GetLastName]<<endl;
				cout<<"  Health              : "<<GetHealth<<endl;
				cout<<"  Gold                : "<<GetGold<<endl;
				cout<<"  Days Lived          : "<<DaysAlive<<endl;
				cout<<"  Sword Damage        : "<<GetSword<<endl;
				cout<<"  Sword Level         : "<<SwordLevel<<endl;
				cout<<"  Shield damage block : "<<GetShield<<endl;
				cout<<"  Shield Level        : "<<ShieldLevel<<endl;
				cout<<"  Apples              : "<<AppleInventory<<endl<<endl;
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
					GetHealth+=50;
					if(GetHealth>100){
						GetHealth=100;
					}
					cout<<"  Health Added! \n";
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
				SaveStats.open("RPGstats.txt");
				SaveStats<<GetHealth<<" "<<GetName<<" "<<GetLastName<<" "<<GetGold<<" "<<GetSword<<" "<<GetShield<<" "<<AppleInventory<<" "<<SwordLevel<<" "<<ShieldLevel<<" "<<DaysAlive<<" ";
				SaveStats.close();//VERY IMPORTANT TO CLOSE A FILE OR IT WONT SAVE AT ALL!!!
				cout<<"saved! \n \n"<<"  ------------ \n";
				--DaysAlive;
			}
		}
		return 0;
	}
