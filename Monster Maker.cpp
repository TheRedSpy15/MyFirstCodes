//LIBRARIES
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <unistd.h>
#include <conio.h>
#include <fstream>
//NAMESPACE
using namespace std;

//EXTRA NOTE: ALL LINES BESIDE THE ONES THAT END IN { REQUIRE A ; AT THE END

//RANDOM FUNCTION
//EXAMPLE: VARIABLE = randVal(MIN RANDOM NUMBER,MAX RANDOM NUMBER)
    int randVal(int min,int max){
   return (rand() % (max - min + 1) + min);
}
//MAIN() FUNCTION IS REQUIRED FOR ALL C++ PROGRAMS
int main(){
	//PLANTS SEED FOR RANDOM VALUE OTHERWISE RAND() WOULD BE THE SAME NUMBER EVERYTIME
	srand(time(NULL));
	
	//VARIABLES
	//NOTE: IT IS A GOOD HABIT TO SET VARIABLES TO A VALUE UPON CREATION
	//NOTE: INT ARE INTEGER DATA TYPES FOR VARIABLES WHILE CHAR IS A SINGLE LETTER AND STRING IS A STRING OF LETTERS
	int BodyTM1=0,BodyMM1=0,BodyBM1=0,HeadM1=0,ArmourM1=0,HealthM1=0,LevelM1=0,TypeM1=0,NameM1=0,AttackM1=0,ArmourPlusM1=0,AttackPlusM1=0; //variables for monster one
	int BodyTM2=0,BodyMM2=0,BodyBM2=0,HeadM2=0,ArmourM2=0,HealthM2=0,LevelM2=0,TypeM2=0,NameM2=0,AttackM2=0,ArmourPlusM2=0,AttackPlusM2=0; //variables for monster two
	char RunGame,LoadMonster,saveInput,saveInputConfirm;
	int SelectSave,SelectLoad,RareBossChance=0;
	//STATS FOR MONSTER 1
	LevelM1 = randVal(1,100);
	NameM1 = randVal(0,52);
	//SAVED MONSTER OBJECT
	//FSTREAM IS WRITE AND IFSTREAM IS READ
	//SAVEMOBJ AND READMOBJ ARE THE OBJECT NAMES WHICH WORK LIKE VARIABLES
	//IN THE (PARAMETERS) IS THE FILE YOU WANT TO USE
	fstream saveMobj("Monsters.txt");
	fstream saveMobj2("Monsters2.txt");
	fstream saveMobj3("Monsters3.txt");
	ifstream readMobj("Monsters.txt");
	ifstream readMobj2("Monsters2.txt");
	ifstream readMobj3("Monsters3.txt");
	//TEST IF TEXT FILES ARE OPEN AND READY FOR USE THEN OUTPUTING TO CONSOLE RESULTS 
	//NOTE: ENDL and \N USED TO ENDLINE AND MOVE TO NEXT LINE
	if(saveMobj.is_open()){
		cout<<"Saved Monster loaded! (FILE 1) \n \n";
	}else{
		cout<<"Saved Monster FAILED to load!! (FILE 1) \n \n";
	}
	if(saveMobj2.is_open()){
		cout<<"Saved Monster loaded! (FILE 2) \n \n";
	}else{
		cout<<"Saved Monster FAILED to load!! (FILE 2) \n \n";
	}
	if(saveMobj3.is_open()){
		cout<<"Saved Monster loaded! (FILE 3) \n \n";
	}else{
		cout<<"Saved Monster FAILED to load!! (FILE 3) \n \n";
	}
	//ARRAYS CONTAINING VALUES
	string Mhead[] = {"( O ^ O )","| O * O |","( =^_^= )","( > _ < )","(<@>-<@>)","( >@ @< )","*|-O-O-|*","  ^_^_^_^","O-^v^-O"};
	string Mbody1[] = {"|#####|","[[[-]]]","$--|--$","| ^|^ |","(--|--)","^    I  ","   |   "};
	string Mbody2[] = {"|#####|","[[[-]]]","$--|--$","|  |  |","(--|--)","|    I  ","_-<|>-_"};
	string Mbody3[] = {"!#####!","[]---[]","|     |"," _/|_  ","(--|--)","----->  ","!!---!!"};
	string Mname[] = {"Abra","Aipom","Amaura","Arbok","Archen","Aron","Bagon","Beedrill","Beldum","Bayleef","baltoy","Cacnea","Cascoon","Delphox","CHARIZARD",
	"Deino","Deerling","Ditto","Dragonair","Drampa","Drowzee","Dustox","Electrabuzz","Emboar","Fearow","Golem","Grimer","Guzzlord","Hypno","Inkay","Invysaur",
	"Jolteon","Jynx","Koffinf","Lapras","Latias","Latios","Charmander","Mew","Nidioking","Nidoqueen","Onix","Pichu","Pikachu","Smokespawn","Moldpaw","Dinderman",
	"Dreadman","Canine Brute","Pain sulker","Melterspawn","Spectral Rat","Mammoth","BOSS: Skull Crusher","RARE BOSS: Slither","LEGENDARY BOSS: Ratchet"}; //Current names in use: 0-52 (53-55 are boss)	in array: 56
	string Mtype[] = {"Fire","Water","Rock","Air","Magic","Titanium","BOSS"};
	//DO WHILE LOOP WHICH RUNS THE CODE ATLEAST ONCE
	do{
	
	//DO YOU WANT TO LOAD MONSTER 1
	cout<<"do you want to use your saved Monsters?? y/n \n";
	cin>>LoadMonster;
	if(LoadMonster == 'n'){
	
	//CUSTOMISING MONSTER 1
	cout<<"  input for head, and don't forget to press enter... \n";
	cout<<"  (0) - ( O ^ O ) Type: Fire \n";
	cout<<"  (1) - | O * O | Type: Titanium \n";
	cout<<"  (2) - ( =^_^= ) Type: Water \n";
	cout<<"  (3) - ( > _ < ) Type: Rock \n";
	cout<<"  (4) - (<@>-<@>) Type: Air \n";
	cout<<"  (5) - ( >@ @< ) Type: Magic \n";
	//ASKS FOR VALUE OF HEADM1
	cin>>HeadM1;
	//IF HEADM1 IS LESS THAN ZERO OR GREATER THAN FIVE THEN
	if(HeadM1 < 0 || HeadM1 > 5){
		cout<<"  Donchu try pulling that!! re-enter \n";
		cin>>HeadM1;
		if(HeadM1 < 0 || HeadM1 > 5){
			cout<<"  really...";
			//PAUSES THE CODE
			sleep(3);
			return 0;
		}
	}
	cout<<"  Now, input... \n"<<"  Light, has higher attacking power. Heavy, has higher armour and health \n";
	cout<<"  (0) - 1#####1 Type: Heavy \n";
	cout<<"  (1) - [[[-]]] Type: Heavy \n";
	cout<<"  (2) - $--|--$ Type: Light \n";
	cout<<"  (3) - | ^|^ | Type: Light \n";
	cin>>BodyTM1;
	if(BodyTM1 < 0 || BodyTM1 > 3){
		cout<<"  Donchu try pulling that!! re-enter \n";
		cin>>BodyTM1;
		if(BodyTM1 < 0 || BodyTM1 > 3){
			cout<<"  really...";
			sleep(3);
			return 0;
		}
	}
	cout<<"  Now for the next layer (Again)..... \n";
	cout<<"  (0) - 1#####1 Type: Heavy \n";
	cout<<"  (1) - [[[-]]] Type: Heavy \n";
	cout<<"  (2) - $--|--$ Type: Light \n";
	cout<<"  (3) - |  |  | Type: Light \n";
	cin>>BodyMM1;
	if(BodyMM1 < 0 || BodyMM1 > 3){
		cout<<"  Donchu try pulling that!! re-enter \n";
		cin>>BodyMM1;
		if(BodyMM1 < 0 || BodyMM1 > 3){
			cout<<"really...";
			sleep(3);
			return 0;
		}
	}
	cout<<"  once more... \n";
	cout<<"  (0) - 1#####1 Type: Heavy \n";
	cout<<"  (1) - []---[] Type: Heavy \n";
	cout<<"  (2) - |     | Type: Light \n";
	cout<<"  (3) -  _/|_   Type: Light \n";
	cin>>BodyBM1;
	if(BodyBM1 < 0 || BodyBM1 > 3){
		cout<<"  Donchu try pulling that!! re-enter \n";
		cin>>BodyBM1;
		if(BodyBM1 < 0 || BodyBM1 > 3){
			cout<<  "really...";
			sleep(3);
			return 0;
		}
	}
	
	//HEADS - HeadM1
	//IF HEAM1 EQUAL TO THEN TYPE IS
	//IMPORTANT NOTE: VARIABLES USE = AND IN THINGS LIKE IF(VARIABLE ...) UES ==
	if(HeadM1 == 0){
		TypeM1 = 0;
	}
	if(HeadM1 == 1){
		TypeM1 = 5;
	}
	if(HeadM1 == 2){
		TypeM1 = 1;
	}
	if(HeadM1 == 3){
		TypeM1 = 2;
	}
	if(HeadM1 == 4){
		TypeM1 = 3;
	}
	if(HeadM1 == 5){
		TypeM1 = 4;
	}
	
	//BODY
	//HEALTH - BodyTM1
	//HEAVY
	if(BodyTM1 == 0 || BodyTM1 == 1){
		HealthM1 = randVal(1,1650);
	}
	//LIGHT
	if(BodyTM1 == 2 || BodyTM1 == 3){
		HealthM1 = randVal(1,1450);
		AttackPlusM1 = randVal(0,150);
	}
	//ARMOUR - BodyMM1 && BodyBM1
	//light
	if(BodyMM1 == 2 || BodyMM1 == 3){
		ArmourM1 = randVal(0,400);
	}
	//HEAVY
	if(BodyMM1 == 0 || BodyMM1 == 1){
		ArmourM1 = randVal(0,500);
	}
	//ARMOUR BOUNUS
	//HEAVY
	if(BodyBM1 == 0 || BodyBM1 == 1){
		ArmourPlusM1 = randVal(0,100);
		ArmourM1 += ArmourPlusM1;
	}
	//LIGHT
	if(BodyBM1 == 2 || BodyBM1 == 3){
		ArmourPlusM1 = randVal(0,55);
		ArmourM1 += ArmourPlusM1;
	}
	//ATTACK - AT
	//HEAVY
	if(BodyBM1 == 0 || BodyBM1 == 1){
		AttackM1 = randVal(1,200);
	}
	//LIGHT
	if(BodyBM1 == 2 || BodyBM1 == 3){
		AttackM1 = randVal(1,250);
		AttackM1 += AttackPlusM1;
	}
	
	//Special Types
	if(TypeM1 == 4){
		HealthM1 /= 2;
		AttackM1 *= 2;
	}
	if(TypeM1 == 5){
		HealthM1 *= 2;
		AttackM1 /= 2;
	}
}
	
	//LOADING YOUR MONSTER
	//IF THE READ FROM FILE AFTER CHOSING WHICH ONE OF THE THREE
	if(LoadMonster == 'y'){
		cout<<"which one? 1,2, or 3? \n";
		cin>>SelectLoad;
		if(SelectLoad == 1){
			cout<<"Loading 'em up! \n";
			readMobj>>HeadM1>>BodyTM1>>BodyMM1>>BodyBM1>>NameM1>>LevelM1>>TypeM1>>HealthM1>>ArmourM1>>AttackM1;
			readMobj.close();
		}
		if(SelectLoad == 2){
			cout<<"Loading 'em up! \n";
			readMobj2>>HeadM1>>BodyTM1>>BodyMM1>>BodyBM1>>NameM1>>LevelM1>>TypeM1>>HealthM1>>ArmourM1>>AttackM1;
			readMobj2.close();
		}
		else if(SelectLoad == 3){
			cout<<"Loading 'em up! \n";
			readMobj3>>HeadM1>>BodyTM1>>BodyMM1>>BodyBM1>>NameM1>>LevelM1>>TypeM1>>HealthM1>>ArmourM1>>AttackM1;
			readMobj.close();
		}
	}
	
	//FINALIZING MONSTER 1
	cout<<"-------------------- \n";
	cout<<"  YOUR MONSTER \n \n";
	//USES VARIABLES TO INPUT INTO THE ARRAYS FOR OUTPUTING TO CONSOLE
	cout<<Mhead[HeadM1]<<endl;
	cout<<Mbody1[BodyTM1]<<endl<<Mbody2[BodyMM1]<<endl<<Mbody3[BodyBM1]<<endl<<endl;
	
	cout<<"  Name: "<<Mname[NameM1]<<endl;
	cout<<"  Level: "<<LevelM1<<endl;
	cout<<"  Type: "<<Mtype[TypeM1]<<endl;
	cout<<"  Health: "<<HealthM1<<endl;
	cout<<"  Armour: "<<ArmourM1<<endl;
	cout<<"  Attack: "<<AttackM1<<endl;
	
	
	//SAVING YOUR MONSTER
	if(LoadMonster == 'n'){

	cout<<endl<<"  do you want to save your monster? y/n \n";
	cin>>saveInput;
	if(saveInput == 'y'){
		cout<<"  save to which file? 1,2, or 3? \n";
		cin>>SelectSave;
		//OUTPUTING TO FILES
		if(SelectSave == 1){
		saveMobj<<HeadM1<<" "<<BodyTM1<<" "<<BodyMM1<<" "<<BodyBM1<<" "<<NameM1<<" "<<LevelM1<<" "<<TypeM1<<" "<<HealthM1<<" "<<ArmourM1<<" "<<AttackM1;
		saveMobj.close();
		cout<<"saved! \n";
		}
		if(SelectSave == 2){
			saveMobj2<<HeadM1<<" "<<BodyTM1<<" "<<BodyMM1<<" "<<BodyBM1<<" "<<NameM1<<" "<<LevelM1<<" "<<TypeM1<<" "<<HealthM1<<" "<<ArmourM1<<" "<<AttackM1;
			saveMobj2.close();
			cout<<"saved! \n";
		}
		else if(SelectSave == 3){
			saveMobj3<<HeadM1<<" "<<BodyTM1<<" "<<BodyMM1<<" "<<BodyBM1<<" "<<NameM1<<" "<<LevelM1<<" "<<TypeM1<<" "<<HealthM1<<" "<<ArmourM1<<" "<<AttackM1;
			saveMobj3.close();
			cout<<"saved! \n";
		}
	}
	if(saveInput == 'n'){
		cout<<"  you sure?? \n";
		cin>>saveInputConfirm;
		if(saveInputConfirm == 'y'){
			cout<<"  ok then... \n";
		}
		if(saveInputConfirm == 'n'){
			cout<<"  save to which file? 1,2, or 3? \n";
			cin>>SelectSave;
			if(SelectSave == 1){
				saveMobj<<HeadM1<<" "<<BodyTM1<<" "<<BodyMM1<<" "<<BodyBM1<<" "<<NameM1<<" "<<LevelM1<<" "<<TypeM1<<" "<<HealthM1<<" "<<ArmourM1<<" "<<AttackM1<<endl;
				saveMobj.close();
				cout<<"saved! \n";
			}
				if(SelectSave == 2){
				saveMobj2<<HeadM1<<" "<<BodyTM1<<" "<<BodyMM1<<" "<<BodyBM1<<" "<<NameM1<<" "<<LevelM1<<" "<<TypeM1<<" "<<HealthM1<<" "<<ArmourM1<<" "<<AttackM1<<endl;
				saveMobj2.close();
				cout<<"saved! \n";
			}
			else if(SelectSave == 3){
				saveMobj3<<HeadM1<<" "<<BodyTM1<<" "<<BodyMM1<<" "<<BodyBM1<<" "<<NameM1<<" "<<LevelM1<<" "<<TypeM1<<" "<<HealthM1<<" "<<ArmourM1<<" "<<AttackM1<<endl;
				saveMobj3.close();
				cout<<"saved! \n";
			}
		}
	}
}
	sleep(2);
	
	//SETTING UP MONSTER 2
	cout<<"-------------------- \n";
	cout<<"  HOSTILE MONSTER \n \n";
	
	LevelM2 = randVal(1,100);
	BodyTM2 = randVal(0,3);
	BodyMM2 = randVal(0,3);
	BodyBM2 = randVal(0,3);
	HeadM2 = randVal(0,5);
	NameM2 = randVal(0,52);
	RareBossChance = randVal(0,100);
	
	//HEADS - HeadM2
	if(HeadM2 == 0){
		TypeM2 = 0;
	}
	if(HeadM2 == 1){
		TypeM2 = 5;
	}
	if(HeadM2 == 2){
		TypeM2 = 1;
	}
	if(HeadM2 == 3){
		TypeM2 = 2;
	}
	if(HeadM2 == 4){
		TypeM2 = 3;
	}
	if(HeadM2 == 5){
		TypeM2 = 4;
	}
	
	//BODY
	//HEALTH - BodyTM2
	//HEAVY
	if(BodyTM2 == 0 || BodyTM2 == 1){
		HealthM2 = randVal(1,1650);
	}
	//LIGHT
	if(BodyTM2 == 2 || BodyTM2 == 3){
		HealthM2 = randVal(1,1450);
		AttackPlusM2 = randVal(0,150);
	}
	//ARMOUR - BodyMM2 && BodyBM2
	//light
	if(BodyMM2 == 2 || BodyMM2 == 3){
		ArmourM2 = randVal(0,400);
	}
	//HEAVY
	if(BodyMM2 == 0 || BodyMM2 == 1){
		ArmourM2 = randVal(0,500);
	}
	//ARMOUR BOUNUS
	//HEAVY
	if(BodyBM2 == 0 || BodyBM2 == 1){
		ArmourPlusM2 = randVal(0,100);
		ArmourM2 += ArmourPlusM2;
	}
	//LIGHT
	if(BodyBM2 == 2 || BodyBM2 == 3){
		ArmourPlusM2 = randVal(0,55);
		ArmourM2 += ArmourPlusM1;
	}
	//ATTACK - AT
	//HEAVY
	if(BodyBM2 == 0 || BodyBM2 == 1){
		AttackM2 = randVal(1,200);
	}
	//LIGHT
	if(BodyBM2 == 2 || BodyBM2 == 3){
		AttackM2 = randVal(1,250);
		AttackM2 += AttackPlusM2;
	}
	
	//Special Types
	if(TypeM2 == 4){
		HealthM2 /= 2;
		AttackM2 *= 2;
	}
	if(TypeM2 == 5){
		HealthM1 *= 2;
		AttackM1 /= 2;
	}
	
	//RARE BOSS SETUP
	if(RareBossChance <= 97 && RareBossChance >= 70){
		NameM2 = 53;
		TypeM2 = 6;
		LevelM2 = 100;
		BodyTM2 = 4;
		BodyMM2 = 4;
		BodyBM2 = 4;
		HeadM2 = 6;
		AttackM2 = 215;
		HealthM2 = 1000;
		ArmourM2 = 500;
	}
	if(RareBossChance == 98 || RareBossChance == 99){
		NameM2 = 54;
		TypeM2 = 6;
		LevelM2 = 100;
		BodyTM2 = 5;
		BodyMM2 = 5;
		BodyBM2 = 5;
		HeadM2 = 7;
		AttackM2 = 900;
		HealthM2 = 50;
		ArmourM2 = 300;
	}
	if(RareBossChance == 100){
		NameM2 = 55;
		TypeM2 = 6;
		LevelM2 = 100;
		BodyTM2 = 6;
		BodyMM2 = 6;
		BodyBM2 = 6;
		HeadM2 = 8;
		AttackM2 = 550;
		HealthM2 =300;
		ArmourM2 = 350;
	}
	
	//DISPLAYING MONSTER 2
	cout<<Mhead[HeadM2]<<endl;
	cout<<Mbody1[BodyTM2]<<endl<<Mbody2[BodyMM2]<<endl<<Mbody3[BodyBM2]<<endl<<endl;
	cout<<"  Name: "<<Mname[NameM2]<<endl;
	cout<<"  Level: "<<LevelM2<<endl;
	cout<<"  Type: "<<Mtype[TypeM2]<<endl;
	cout<<"  Health: "<<HealthM2<<endl;
	cout<<"  Armour: "<<ArmourM2<<endl;
	cout<<"  Attack: "<<AttackM2<<endl;
	
	sleep(4);
	
	//DISPLAYING BOTH MONSTERS
	cout<<"-------------------- \n";
	cout<<"     !!!FIGHT!!! \n";
	cout<<Mhead[HeadM1]<<"      "<<Mhead[HeadM2]<<endl;
	cout<<Mbody1[BodyTM1]<<"         "<<Mbody1[BodyTM2]<<endl;
	cout<<Mbody2[BodyMM1]<<"   vs    "<<Mbody2[BodyMM2]<<endl;
	cout<<Mbody3[BodyBM1]<<"         "<<Mbody3[BodyBM2]<<endl;
	
	//SETTING UP FIGHT
	HealthM1 += ArmourM1;
	HealthM2 += ArmourM2;

	//BOUNUS FOR NORMAL TYPES
	//IF AND
	if(TypeM1 == 1 && TypeM2 == 3){
		AttackM2 *= 1.2;
	}
	if(TypeM1 == 1 && TypeM2 == 0){
		AttackM1 *= 1.2;
	}
	if(TypeM1 == 0 && TypeM2 == 1){
		AttackM2 *= 1.2;
	}
	if(TypeM1 == 0 && TypeM2 == 2){
		AttackM1 *= 1.2;
	}
	if(TypeM1 == 2 && TypeM2 == 0){
		AttackM2 *= 1.2;
	}
	if(TypeM1 == 2 && TypeM2 == 1){
		AttackM2 *= 1.2;
	}
	if(TypeM1 == 2 && TypeM2 == 3){
		AttackM1 *= 1.2;
	}
	if(TypeM1 == 3 && TypeM2 == 1){
		AttackM1 *= 1.2;
	}
	if(TypeM1 == 3 && TypeM2 == 2){
		AttackM2 *= 1.2;
	}
	cout<<endl;
	sleep(2);
	
	//FIGHT!!
	do{
		cout<<"  You used "<<Mtype[TypeM1]<<" attack for "<<AttackM1<<endl;
		HealthM2 -= AttackM1;
		cout<<"  Their health is "<<HealthM2<<endl;
		sleep(1);
		cout<<"  They used "<<Mtype[TypeM2]<<" attack for "<<AttackM2<<endl;
		HealthM1 -= AttackM2;
		cout<<"  Your health is "<<HealthM1<<endl<<endl;;
		sleep(2);
	//CONDITION TO CONTINUE DO WHILE LOOP
	}while(HealthM1 > 0 && HealthM2 > 0);
	
	cout<<endl;
	if(HealthM1 < 0 && HealthM2 > 0){
		cout<<"  YOUR MONSTER LOST \n";
		cout<<"  Their health is "<<HealthM2<<endl;
	}
	else if(HealthM2 < 0 && HealthM1 > 0){
		cout<<"  YOUR MONSTER WON!!!! \n";
		cout<<"  Your health is "<<HealthM1<<endl;
	}
	else{
		cout<<"!DRAW! \n";
	}
	
	//PLAY AGAIN?
	cout<<"Do you want to play again? \n"<<"y/n"<<endl;
	cin>>RunGame;
	cout<<endl<<endl;
}while(RunGame == 'y');
	//ENDS PROGRAM
	return 0;
}
