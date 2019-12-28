#include <iostream>
#include <ctime>
#include <cstdlib>
#include <unistd.h>
#include <conio.h>
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
		int ReturnStamina(){
			return Stamina;
		}
		int ReturnHealth(){
			return Health;
		}
		int ReturnDistance(){
			return StartdistancefromCamp;
		}
		int ReturnTents(){
   			return StartTents;
		}
		int randVal(int min,int max){
   			return (rand() % (max - min + 1) + min);
   		}
   	private:
		int const Name = randVal(0,4);
		int const lastName = randVal(0,3);
		int const Stamina = 10;
		int const Health = 100;
		int const StartdistancefromCamp=500;
		int const StartTents = 1;
};

//NOTES: set stamina and health static

int main(){
	srand(time(NULL));
	PlayerClass obj;
	int distancefromCamp = obj.ReturnDistance();
	int playerHealth=obj.ReturnHealth();
	int StaminaTemp = obj.ReturnStamina();
	int PlayerDecision;
	int MobSelect = obj.randVal(0,2);
	int TentsRemain = obj.ReturnTents();
	
	int DeathClawAttack,RadRoachAttack,RaiderAttack;
	
	string FirstNameArray[]={"Joe","John","Jack","Jerry","Tomas","Mike"};
	string LastNameArray[]={"Smith","White","Drum","Austin"};
	string MobList[]={"A DeathClaw","A Rad Roach","A Raider"};
	
	cout<<"  Name: "<<FirstNameArray[obj.ReturnName()]<<" "<<LastNameArray[obj.ReturnLastName()]<<endl;
	cout<<"  Health: "<<obj.ReturnHealth()<<endl<<endl;
	
	cout<<"  You have found out about a Military encampment. \n"<<
	"  You must get there before the Bombing on the city begins! \n"<<
	"  Remember... if you need to replenish your health; sleep for a little while. \n \n";
	
		cout<<"  Press 1 to head out (don't forget to press enter!) \n";
		cin>>PlayerDecision;
		
		while(PlayerDecision == 1 && playerHealth > 0){
			while(StaminaTemp > 0){
				if(distancefromCamp <= 0){
					cout<<"  Congrats! You made it to the camp in time! \n";
					sleep(5);
				}
				cout<<"  Walking... \n";
				--distancefromCamp;
				cout<<"  distance to go: "<<distancefromCamp<<endl<<endl;
				--StaminaTemp;
				sleep(2);
				int MobChance = obj.randVal(0,100);
				int MobSelect = obj.randVal(0,2);
				int discoverChance = obj.randVal(0,100);
				if(MobChance >= 80){
					StaminaTemp = 0;
					cout<<"  encountered "<<MobList[MobSelect]<<endl;
					switch (MobSelect){
						case 0:
							DeathClawAttack=obj.randVal(35,75);
							playerHealth -= DeathClawAttack;
							cout<<"  it attacked for "<<DeathClawAttack<<endl;
							if(playerHealth < 0){
								cout<<"  You Died \n";
								sleep(3);
								return 0;
							}
							cout<<"  Health Remaining: "<<playerHealth<<endl<<endl;
							break;
						case 1:
							RadRoachAttack=obj.randVal(5,15);
							playerHealth -= RadRoachAttack;
							cout<<"  it attacked for "<<RadRoachAttack<<endl;
							if(playerHealth < 0){
								cout<<"  You Died \n";
								sleep(3);
								return 0;
							}
							cout<<"  Health Remaining: "<<playerHealth<<endl<<endl;
							break;
						case 2:
							RaiderAttack=obj.randVal(15,35);
							playerHealth -= RaiderAttack;
							cout<<"  it attacked for "<<RaiderAttack<<endl;
							if(playerHealth < 0){
								cout<<"  You Died \n";
								sleep(3);
								return 0;
							}
							cout<<"  Health Remaining: "<<playerHealth<<endl<<endl;
							break;
					}
				}
				if(discoverChance > 49 && discoverChance < 70){
					int discoverSelect = obj.randVal(1,2);
					switch (discoverSelect){
						case 1:
							cout<<"  You found an extra tent \n";
							++TentsRemain;
							cout<<"  Tents remaining: "<<TentsRemain<<endl;
							break;
						case 2:
							int CarDistance = obj.randVal(5,100);
							cout<<"  You found a car with some gas and drove for "<<CarDistance<<" miles \n";
							distancefromCamp -= CarDistance;
							break;
					}
				}
			}
			cout<<"  continue (1) or stop and camp for the night? (2) \n";
			cin>>PlayerDecision;
			StaminaTemp = obj.ReturnStamina();
			
			if(PlayerDecision == 2){
				if(TentsRemain <= 0){
				cout<<"  Geuss you will have to sleep out in the open! \n";
				sleep(3);
				cout<<"  You got attacked by "<<MobList[MobSelect]<<" in your sleep! \n"<<"  THE END!!! \n";
				sleep(5);
				return 0;
			}
			--TentsRemain;
			cout<<"  Tents remaining: "<<TentsRemain<<endl;
			playerHealth = obj.ReturnHealth();
			cout<<"  Nighty Night \n";
			sleep(3);
			cout<<"  Health Refilled \n";
			sleep(3);
			cout<<"  Rise and shine! \n";
			sleep(3);
			PlayerDecision = 1;
		}
	}
	
	if(distancefromCamp == 0){
		cout<<"  Congrats! You made it to the camp in time! \n";
		sleep(5);
	}
	
	return 0;
}
