#include <iostream>
#include <ctime>
#include <cstdlib>
#include <unistd.h>
using namespace std;

	int randVal(int min,int max){
  		return (rand() % (max - min + 1) + min);
  	}

class ShipCreation{
	public:
		
		void CarrierPlayer(){
			ShipClassSelect=1;
			cout<<"  Level 1: (1) 12x AA Guns (2) 4x 78MM AT Guns (3) \n";
			cin>>Level1Select;
			cout<<"  Flight Deck: (1) 60x Fighters (2) 60x torpedo Bombers \n";
			cin>>Level2Select;
		}
		void BattleShipPlayer(){
			ShipClassSelect=2;
			cout<<"  Level 1: (1) 2x 204 MM Cannons (2) 10x AA Guns \n";
			cin>>Level1Select;
			cout<<"  Level 2: (1) 4x 106 MM Cannons (2) 6x AA Guns \n";
			cin>>Level2Select;
		}
		void ShipAssemble(){
			if(ShipClassSelect==1){
				
				ShipHealth=1000;
				ShipLookLevel1=LevelOne[0];
				ShipLookLevel2=LevelTwo[0];
				
				cout<<"   YOUR SHIP \n \n";
				cout<<ShipLookLevel2<<endl<<ShipLookLevel1<<endl;
				
			}
			if(ShipClassSelect==2){
				
				ShipHealth=1500;
				ShipLookLevel1=LevelOne[0];
				
				if(Level1Select==1){
					
					ShipLookLevel2=LevelTwo[1];
				}
				if(Level1Select==2){
					
					ShipLookLevel2=LevelTwo[2];
				}
				
				cout<<"   YOUR SHIP \n \n";
				cout<<ShipLookLevel2<<endl<<ShipLookLevel1<<endl;
			}
		}
		
		int Level1Select,Level2Select;
		int ShipClassSelect;
		int ShipHealth;
		string ShipLookLevel1,ShipLookLevel2;
		
		string LevelOne[1]={"|:::::::::::::::::::/"};
		string LevelTwo[3]={"_____|----|__________","   ===[---]    [---]===","  \\\\  \\\\    // //"};
		
		int PlayerAAGuns=0,PlayerATGuns=0,PlayerFighters=0,PlayerTorpedo=0;//Carrier Guns
		int MM204CannonsPlayer=0,MM106CannonsPlayer=0,x6AAGunsPlayer=0,x10AAGunsPlayer=0;//BattleShip Guns
		
		//NPC SHIP
		int NpcShipClass=randVal(1,2);
		int NpcLevel1=randVal(1,2);
		int NpcLevel2=randVal(1,2);
		int NpcShipHealth=0;
		
		int NpcAAGuns=0,NpcATGuns=0,NpcFighters=0,NpcTorpedo=0;//Carrier Guns
		int MM204CannonsNpc=0,MM106CannonsNpc=0,x6AAGunsNpc=0,x10AAGunsNpc=0;//BattleShip Guns
};

class GameFunctions : public ShipCreation{
	
	int PortCoolDown=0;
	int Fuel=100;
	int Score=0;
	
	public:
		
		void Encounters(){
			
			int EncounterSelect=randVal(1,3);
			int SmallFuelFind=randVal(5,45);
			
			switch(EncounterSelect){
				case 1:
					cout<<"  You found a Fuel Depot!! \n";
					Fuel=100;
					break;
				case 2:
					cout<<"  We hit a mine!! -150 Health \n";
					ShipHealth-=150;
					break;
				case 3:
					cout<<"  You found a small amount of Fuel \n";
					Fuel+=SmallFuelFind;
					break;
				case 4:
					if(ShipHealth<900){
						
						cout<<"  We found some supplies to repair some of the ship \n";
						ShipHealth+=100;
					}
					break;
			}
		}
		
		void ShipAttackSetup(){
			
			if(ShipClassSelect==1){//Carrier
			
				if(Level1Select==1){
					
					PlayerAAGuns=randVal(15,100);
				}
				if(Level1Select==2){
					
					PlayerATGuns=randVal(50,200);
				}
				
				if(Level2Select==1){
					
					PlayerFighters=250;
				}
				if(Level2Select==2){
					
					PlayerTorpedo=250;
				}
			}
			if(ShipClassSelect==2){//BattleShip
				
				if(Level1Select==1){
					
					MM204CannonsPlayer=randVal(100,200);
				}
				if(Level1Select==2){
					
					x10AAGunsPlayer=randVal(30,100);
				}
				
				if(Level2Select==1){
					
					MM106CannonsPlayer=randVal(25,100);
				}
				if(Level2Select==2){
					
					x6AAGunsPlayer=randVal(10,100);
				}
			}
			
			//------------------NPC----------------------------------
			
			if(NpcShipClass==1){//Carrier
				NpcShipHealth=1000;
			
				if(NpcLevel1==1){
					
					NpcAAGuns=randVal(15,100);
				}
				if(NpcLevel1==2){
					
					NpcATGuns=randVal(50,200);
				}
				
				if(NpcLevel2==1){
					
					NpcFighters=100;
				}
				if(NpcLevel2==2){
					
					NpcTorpedo==100;
				}
			}
			if(NpcShipClass==2){//BattleShip
				NpcShipHealth=1500;
				
				if(NpcLevel1==1){
					
					MM204CannonsNpc=randVal(100,200);
				}
				if(NpcLevel1==2){
					
					x10AAGunsNpc=randVal(30,100);
				}
				
				if(NpcLevel2==1){
					
					MM106CannonsNpc=randVal(25,100);
				}
				if(NpcLevel2==2){
					
					x6AAGunsNpc=randVal(10,100);
				}
			}
		}
		
		void Battle(){
			
			cout<<"  !!!ENTERED BATTLE PHASE!!! \n";
			
			do{
				
				cout<<endl;
				
				if(ShipClassSelect==1){
					
					if(PlayerTorpedo>0&&Level2Select==2){
				
						cout<<"  Our Aircraft are going in! \n";
						sleep(3);
						PlayerTorpedo-=x10AAGunsNpc;
						PlayerTorpedo-=x6AAGunsNpc;
						PlayerTorpedo-=NpcAAGuns;
						PlayerTorpedo-=NpcFighters;
					}
					if(PlayerFighters>0&&Level2Select==1){
						PlayerFighters-=x10AAGunsNpc;
						PlayerFighters-=x6AAGunsNpc;
						PlayerFighters-=NpcAAGuns;
						PlayerFighters-=NpcFighters;
					}
						if(PlayerTorpedo<0||PlayerFighters<0){
						
							cout<<"  All aircraft are down!! \n";
						}else{
							
							cout<<"  Fighters Remaining:"<<PlayerFighters<<endl<<"  Torpedo Bombers Remaining: "<<PlayerTorpedo<<endl;
						}
						
						NpcShipHealth-=PlayerFighters;
						NpcShipHealth-=PlayerTorpedo;
						sleep(3);
					}
				
				sleep(3);
				
				cout<<"  Prepare to fire! \n";
				sleep(3);
				cout<<"  FIRE!!!! \n";
				sleep(3);
				
				NpcShipHealth-=MM106CannonsPlayer;
				NpcShipHealth-=PlayerATGuns;
				NpcShipHealth-=MM204CannonsPlayer;
				
				cout<<"  HIT!! \n"<<"  THEY'RE PREPARING TO FIRE!!! \n";
				sleep(3);
				
				ShipHealth-=MM106CannonsNpc;
				ShipHealth-=MM204CannonsNpc;
				ShipHealth-=NpcATGuns;
				
				cout<<"  THEY HIT US!!! \n";
				sleep(3);
				
				if(NpcShipClass==1){
					
					if(NpcTorpedo>0){
						
						cout<<"  They're sending in their aircaft!! \n";
						
						NpcTorpedo-=PlayerAAGuns+x10AAGunsPlayer+x6AAGunsPlayer+PlayerFighters;
					}
					if(NpcFighters>0){
						
						cout<<"  They're sending in their aircaft!! \n";
						
						NpcFighters-=PlayerAAGuns+x10AAGunsPlayer+x6AAGunsPlayer+PlayerFighters;
						
						if(NpcFighters<0||NpcTorpedo<0){
							
							cout<<"  We shot down all their aircraft! \n";
						}
						
						ShipHealth-=NpcFighters;
						ShipHealth-=NpcTorpedo;
						sleep(3);
					}
				}
				
				if(ShipHealth<=0){
					
					cout<<"  Abandon ship!! \n";
					cout<<"  Your Final score is: "<<Score<<endl;
				}
				if(NpcShipHealth<=0){
					
					cout<<"  We sunk the Hostile Ship!! \n";
					Score+=100;
				}
				
				if(ShipHealth<0){
					
					ShipHealth=0;
				}else if(NpcShipHealth<0){
					
					NpcShipHealth=0;
				}
				
				cout<<"  Our health is: "<<ShipHealth<<" | Their Health is: "<<NpcShipHealth<<endl<<endl;
				
			}while(NpcShipHealth>0&&ShipHealth>0);
			cout<<"  BATTLE PAHSE HAS ENDED \n";
		}
		
		void Explore(){
			
			for(;Fuel>0;Fuel--,PortCoolDown++){
				
				while(ShipHealth>0){
					
					int PlayerDecision;
					cout<<"  Do you want to: (1) Set Sail (2) Head into port (3) View Ship \n \n";
					cin>>PlayerDecision;
					
					if(PlayerDecision==1){//Explore
						
						for(int MovesPerTurn=10;MovesPerTurn>0;MovesPerTurn--){
							
							PortCoolDown++;
							Score+=10;
							
							if(PortCoolDown>10){
								
								PortCoolDown=10;
							}
							
							int HostileChance=randVal(0,100);
							int EncounterChance=randVal(0,100);
							
							cout<<"  Traveling \n";
							
							if(HostileChance>=80){
								
								cout<<"  Hostile ship encounterd!! \n";
								sleep(1);
								Battle();
								MovesPerTurn=0;
							}else if(EncounterChance>=80){
								
								Encounters();
							}
							
							sleep(2);
							
							if(PortCoolDown>3){
								
								PortCoolDown=3;
							}
						}
					}
					if(PlayerDecision==2){//Head into port
						
						if(PortCoolDown==3){
							
							cout<<"  Heading in to port for repairs! \n";
							sleep(3);
							Fuel+=25;
							cout<<"  Repaired & Resupplied! \n";
							
							if(ShipClassSelect==1){
								
								ShipHealth=1000;
								
								if(Level2Select==1){
									
									PlayerFighters=100;
								}
								if(Level2Select==2){
									
									PlayerTorpedo=100;
								}
							}
							if(ShipClassSelect==2){
								
								ShipHealth=1500;
							}
						}else{
							
							cout<<"  We were just at the port! \n";
						}
					}
					if(PlayerDecision==3){//View Ship
						
						cout<<"   YOUR SHIP \n \n";
						cout<<ShipLookLevel2<<endl<<ShipLookLevel1<<endl<<endl;
						
						cout<<"  Health     	  : "<<ShipHealth<<endl;
						cout<<"  Fuel            : "<<Fuel<<endl;
						
						if(ShipClassSelect==1){
							cout<<endl<<"    Air Strength \n \n";
							cout<<"  Fighters        : "<<PlayerFighters<<endl;
							cout<<"  Torpedo Bombers : "<<PlayerTorpedo<<endl<<endl;
						}
						
						cout<<"  Level 1 : ";
						if(Level1Select==1&&ShipClassSelect==1){
							
							cout<<"12x AA Guns \n";
						}
						if(Level1Select==1&&ShipClassSelect==2){
							
							cout<<"2x 204 MM Cannons \n";
						}
						if(Level1Select==2&&ShipClassSelect==1){
							
							cout<<"4x 78MM AT Guns \n";
						}
						if(Level1Select==2&&ShipClassSelect==2){
							
							cout<<"10x AA Guns \n";
						}
						
						cout<<"  Level 2 : ";
						
						if(Level2Select==1&&ShipClassSelect==1){
							
							cout<<"60x Fighters \n";
						}
						if(Level2Select==1&&ShipClassSelect==2){
							
							cout<<"4x 106 MM Cannons \n";
						}
						if(Level2Select==2&&ShipClassSelect==1){
							
							cout<<"60x torpedo Bombers \n";
						}
						if(Level2Select==2&&ShipClassSelect==2){
							
							cout<<"6x AA Guns \n";
						}
					}
				}
			}
		}
};

int main(){
	
	system("Color A");//Set Color
	srand(time(NULL));

	GameFunctions Gobj;
	
	int ShipSelect;
	
	cout<<"  Do you want a (1) Carrier (2) or a Battleship? \n";
	cin>>ShipSelect;
	
	if(ShipSelect==1){
		Gobj.CarrierPlayer();
		Gobj.ShipAssemble();
	}else if(ShipSelect==2){
		Gobj.BattleShipPlayer();
		Gobj.ShipAssemble();
	}
	
	sleep(1);
	cout<<endl;
	
	Gobj.ShipAttackSetup();
	Gobj.Explore();
	
	sleep(6);
	
	return 0;
}
