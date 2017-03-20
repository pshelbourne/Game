//Beat the school
//By Paul Shelbourne
//Aim of the game is 3 levels , trying to beat the school without getting caught.
//Getting caught will be game over

#include <iostream>
#include <string.h> // gives you string functions
#include <windows.h> //sleep timer from what i gathered so far.


using namespace std;

//variables
//************************************************
// Variables used through out

int MainMenuSelection; 
string StudentName; 

//Level one variables
//************************************************
int StudentFirstInput;
int StudentSecondInput;
int SumAnswerInput;
int CapitalSpain;
int UserFirstKey;

// Level two variables
//************************************************
int LevelTwoUserInput;
int TwoRightPath;
int HelpBillysFriend;
int KeyAnswer;


//functions
//************************************************

//functions used through out
//************************************************
int Detention();

// main menu functions
//************************************************
int MainMenu();
int StartNewGame();
int Instructions();
int LoadGame();
int Exit();

//Level one functions
//************************************************
int LevelOne();
int EndOfLevelOne();

//Level two functions
//************************************************
int LevelTwo();
int LevelTwoRightPath();
int HalfLevelTwo();
int MobilePhonePuzzle();

// level three function
//************************************************
int LevelThree();

// Since we declared our functions at the top , we can now have main at the top and the functions below the main.


// int main, will simply have a welcome screen, then calling the main menu function.

int main(){
	cout<< "Welcome to beat the school!" << endl;
	cout<< "\n" << endl;
	cout<< "Created & developed by Paul Shelbourne"<< endl;
	cout<< "\n" << endl;
	
	
	system("pause");
	system("cls");
	
	MainMenu();

}

//Main menu functions

int MainMenu(){
		
	cout<< "\n*MAIN MENU*"<< endl;
	cout<< "\n" << endl;
	cout<< "It is advised you read the instructions first!" << endl;
	cout<< "\n\n" << endl;
	cout<< "Please choose from the menu \n 1. Start new game \n 2. Load game  \n 3. Instructions \n 4. Exit" << endl;
	cin>> MainMenuSelection;
	
	
	switch(MainMenuSelection){
		case 1:
			system("cls");
			StartNewGame();
			break;
		case 2:
			system("cls");
			LoadGame();
			break;
			
		case 3:
			system("cls");
			Instructions();
			break;
		case 4:
			system("cls");
			exit(0);
			break;
		default:
			cout << "Sorry! Please enter a correct number!" << endl;
	}
	
	system("pause");
	system("cls");
}


// if the user chooses start new game from the menu

int StartNewGame(){
	Sleep(2000);
	cout << "Loading";
	Sleep(1000);
	cout << ".";
	Sleep(1000);
	cout << ".";
	Sleep(1000);
	cout << ".";
	system("cls");
	cout << "Welcome!" << endl;
	cout << "\nFirst things first! What is your name student?" << endl;
	cin >> StudentName;
	cout << "Welcome " << StudentName << " Are you ready to beat the school?" << endl;
	system("cls");
	cout << "Level 1" << endl;
	cout << "\n\n" << endl;
	cout << "Classroom Breach" << endl;
	system("pause");
	system("cls");
	cout << "Monday morning! you enter the classroom and sit down next to your best mate Billy\n" << endl;
	cout << "\nMiss waters address's the class, Good morning students! We have a test today!\n" << endl;
	cout << "Billy: " << StudentName << " I am breaking out of school! Are you with me ?\n Press:\n 1)Yes\n 2)No" << endl;
	cin >> StudentFirstInput;
	
	switch(StudentFirstInput){
		case 1:
			system("cls"); 
			LevelOne();
			break;
		case 2:
			system("cls");
			cout << "you decided to stay and take the test!" << endl;
			cout << "you did not revise, and are caught copying another student!" << endl;
			cout << " miss water's: I will have no cheating in my classroom" << StudentName << " go see the headteacher!!!" << endl;
			cout << "you got sent to the headteacher's office and it is "<< endl;
			cout << "\n\n\n" << endl;
			cout << "GAME OVER!" << endl;
			break;
		default:
			cout << "Sorry, please choose yes or no..." << endl;
			cin >> StudentFirstInput; 
	}
}

// if the user chooses load game from the main menu

int LoadGame(){
	cout << "Let's Load a game save !!!!" << endl;
}

// instructions to the game (aim of game)

int Instructions(){
	cout << "Welcome to beat the school!" << endl;
	Sleep(2000);
	cout << "The instructions are simple, Don't get caught!" << endl;
	cout << "\n\n" << endl;
	Sleep(2000);
	cout << "You will battle it with teachers" << endl;
	cout << "Using your stealth and knowledge to break free!" << endl;
	Sleep(2000);
	cout << "\n" << endl;
	cout << "If you fail to do so, you will be sent to the headteachers office" << endl;
	cout << "Where it is GAME OVER!" << endl;
	Sleep(2000);
	cout << "\n" << endl;
	cout << "Your best friend billy wants to break out of school, you will see him at certain parts of the game" << endl;
	Sleep(2000);
	cout << "\n" << endl;
	system("pause");
	system("cls");
	cout << "The aim of the game\n is to break free from school without being caught" << endl;
	Sleep(2000);
	cout << "\n" << endl;
	cout << "You will have to use your knowledge and answer questions, if you get caught by a teacher you lose points" << endl;
	Sleep(2000);
	cout << "\n" << endl;
	cout << "Lose all your points or get caught by the headteacher, it is GAME OVER" << endl;
	Sleep(2000);
	cout << "\n" << endl;
	cout << "Good luck student, see you on the outside!" << endl;
	Sleep(2000);
	cout << "\n" << endl;
	cout << "Clue: I am on a ring, either alone or as a set! if you find 3 of me, open gates is what you'll get!'" << endl;
	system("cls");
	int MainMenu();
	
}

// if the user decides to exit from the main menu this function will be called and will exit the game.

int Exit (){
	return 0;
}



//Level one functions


int LevelOne(){
	cout << "Good choice! billy crawls along the floor and manages to escape, he leaves the door open for you!\n" << endl;
	cout << "The teacher is alerted now so the option to crawl is not avaliable, you now have to think of another way!\n\n" << endl;
	cout << "You now have a choice:\n1)Ask the teacher to go to the toilet.\n2)Ask James on the desk infront if he will swap seats" << endl;
	cin >> StudentSecondInput;
	
	switch(StudentSecondInput){
		case 1:
			system("cls");
			cout << "Miss Water's: Sorry " << StudentName << " The test is about to begin, it will have to wait!" << endl;
			cout << "that choice failed!" << endl;
			cout << "please choose another option" << endl;
			cin >> StudentSecondInput;
			break;
		case 2:
			system("cls");
			cout << "Pssst! James... Can we swap seats?" << endl;
			cout << "James: Yeah! Only if you answer this question!!" << endl;
			cout << "What is 12x12?" << endl;
			cin >> SumAnswerInput;
			
				if (SumAnswerInput == 144){
					cout << "Correct! James moves places with you , your one step closer to the door!" << endl;
					system("pause");
					cout << "Your one step closer to the door, the teacher is none the wiser\n" << endl;
					system("cls");
					cout << "The girl next to you Sally, has heard what your plan is and offers you a chance to move forward!\n" << endl;
					cout << "\nSally: Can you help me with my homework?\n\n" << endl;
					cout << "\nYou read her homework and the question is: What is the capital of Spain?\n1)London\n2)Paris\n3)Madrid\n4)Amsterdam" << endl;
					cin >> CapitalSpain;
					
					switch(CapitalSpain){
						case 1:
							cout << "\n\n\n" << endl;
							cout << "Maybe your best staying in school!" << endl;
							cout << "Sally: your rubbish! ill' do it myself, you have to find another way to move seats now" << endl;
							cout << "You see a chance to run, but you get caught! GAMEOVER!" << endl;
							int MainMenu(); // want to go back to main menu
			
							break;
						case 2:
							cout << "\n\n\n" << endl;
							cout << "Sally: Even i know it's not that answer!!" << endl;
							cout << "Sally: I am telling the teacher!\nSally tells the teacher and you are put in detention" << endl;
							cout << "You are now in detention and have to solve a puzzle to get out!" << endl;
							Detention();
							break;
						case 3:
							cout << "\n\n\n" << endl;
							cout << "Correct! Well done!" << endl;
							cout << "Sally: Thank you for the help, i found this on my way in, you can have it if you want:" << endl;
							EndOfLevelOne();
							break;
						case 4:
							cout << "\n\n\n" << endl;
							cout << "Bad news! its the wrong answer" << endl;
							cout << "Sally: Ill do it myself " << StudentName << " Thanks for nothing!You now have to find another way out the class!" << endl;
							cout << "You see Miss Water's back turned, you try make a run for it and trip over!\n the teacher is furious with you, you get sent to the head teachers office" << endl;
							cout << "GAME OVER" << endl;
							system ("pause");
							int MainMenu();
							break;
						default:
							cout << "\n\n\n" << endl;
							cout << "Duhh! there are only 4 possible answers! Please try again!" << endl;
							break;
							
				}}else
					cout << "Wrong answer, James tells the teacher your talking to him, the teacher gives you a warning!" << endl;
					cout << "The head teacher see's miss waters giving you a warning and asks to speak to you and calls your parents" << endl;
					cout << "your sent home for the day for cheating....GAME OVER!!" << endl;
					int MainMenu();
			break;
		default:
			cout << "I think you need to stay in school, please choose a correect option!" << endl;
			StudentSecondInput; // doesnt work want it go back to asking the question, loop?
			break;
	}
}

// function for the end of level one

int EndOfLevelOne(){
	system("cls");
	cout << "Sally offers you a rusty key, Do you want to keep it or throw it away? answer 1)Yes or 2) No" << endl;
	cin >> UserFirstKey;
		if (UserFirstKey == 1){
			cout << "\n\n\n";
			cout << "You place the key in your pocket, the teacher is speaking to another student!" << endl;
			cout << StudentName << " makes a run for it!!!" << endl;
			Sleep(1000);
			cout << "..." << endl;
			Sleep(1000);
			cout << "..." << endl;
			cout << "You made it !!!" << endl;
			cout << "You have entered the corridor and the first level is complete!!!" << endl;
			system("pause");
			system("cls");
			LevelTwo();	
		}else {
			cout << "\n\n\n";
			cout << "You don't take the key, the teacher is speaking to another student!" << endl;
			cout << StudentName << " makes a run for it!!!" << endl;
			Sleep(1000);
			cout << "..." << endl;
			Sleep(1000);
			cout << "..." << endl;
			cout << "You made it !!!" << endl;
			cout << "You have entered the corridor and the first level is complete!!!" << endl;
			system("cls");
			LevelTwo();	
		}
	
}

// Detention function, will have osme sort of puzzle/game in order to get out of detention

int Detention(){
	cout << "Welcome to detention!" << endl;
	cout << "You can escape! But first you must play the puzzle!" << endl;
}

//Level two functions

int LevelTwo(){
	Sleep(2000);
	cout << "Loading";
	Sleep(1000);
	cout << ".";
	Sleep(1000);
	cout << ".";
	Sleep(1000);
	cout << ".";
	system("cls");
	cout << "Level Two" << endl;
	cout << "\n\n" << endl;
	cout << "Canteen Carnage!" << endl;
	cout << "Reaching the corridor, you start walking to the school yard\n the student hall monitors are in the distance\n\n you hve to sneak in to the nearest door." << endl;
	cout << "the door you sneak into is the canteen! its almost dinner and the dinner ladies are preparing for the rush!\n" << endl;
	system ("pause");
	cout << "You have to get through without being seen!" << endl;
	cout << "Firstly, do you want to take option left or right? \n1)Left\n2)Right" << endl;
	cin >> LevelTwoUserInput;
	
	switch(LevelTwoUserInput){
		case 1:
			system("cls");
			cout << "You have choosen the path to the left!" << endl;
			cout << "This has brought you closer to the dinner laides, get caught by them and it's straight into detention!" << endl;
			int LevelTwoLeftPath();
			break;
		case 2:
			system("cls");
			cout << "You have choosen the path to the right!" << endl;
			cout << "Good choice, your now more hidden from the dinner ladies!" << endl;
			int LevelTwoRightPath();
			break;
		default:
			cout << "Pssst, your supposed to click either 1 or 2 !!!" << endl;
			break;
	}
	
	
}

// function for half way through level two

int HalfLevelTwo(){
	cout << "Billy: Follow me!! but be quiet!" << endl;
	cout << "You follow billy as you crawl under the tables!" << endl;
	cout << "\nyou stop by Billy's friend as hes talking to him, his friend asks:" << endl;
	cout << "Are you good with puzzles? if so can you help me and you will be rewarded!" << endl;
	cout << "\nDo you wish to help Billy's friend?\nChoose an option:\n1)Yes\2)No" << endl;
	cin >> HelpBillysFriend;
	
	switch (HelpBillysFriend){
		
		case 1:
			cout <<"Thanks , on my phone i have this game where i have to guess the word, but am stuck on what it is!!!" << endl;
			cout << "Have a go and see if you can guess it, the game only allows 3 guess's, \n so get if you get it wrong then you don't get your prize!" << endl;
			MobilePhonePuzzle();
			break;
		case 2:
			cout << "Don't help me then! i don't need tyour help and tyour not having this key i found on the head teachers desk! HA!" << endl;
			cout << "Billy: You should of played that game, its cool " << StudentName << ". Never mind, let's get out the canteen!" << endl;
			cout << "You and Billy progress under the tables and reach the orther side off the canteen " << endl;
			system("pause");
			system("cls");
			int EndOfLevelTwo();
			break;
		default:
			cout <<"That's not an answer! your drawing attention to yourself, wasting time!\n quickly choose another option!" << endl;
			break;
	}
	
}

// level two if the user chooses the right path 

int LevelTwoRightPath(){
	system("pause");
	cout << "your now on the right path" << endl;
	cout << "This path has lead you away from the dinner ladies, good choice!\n" << endl;
	cout << "...";
	cout << "The school bully is standing in your way and asks for your lunch money!" << endl;
	cout << "Your only options is to hand over your money or stand up to him!" << endl;
	cout << "..." << endl;
	cout << "1)Hand money over\n2)Stand up to the school bully" << endl;
	cin >> TwoRightPath;
	
	switch(TwoRightPath){
		case 1:
			system("cls");
			cout << "\n\nYou have choosen to hand the money over!" << endl;
			cout << "\nHe laughs and pushes you over, it causes a comotion!, all the pupils crowd around and the diner ladies are alerted, you make a run for it" << endl;
			cout << "..." << endl;
			cout << "..." << endl;
			cout << StudentName << " ran out into the corridor, where two teachers are talking, they see your worried and take you to the head teachers office" << endl;
			cout << "Unfortunatly it's GAME OVER!!!" << endl;
			system("pause");
			int MainMenu();
			break;
		case 2:
			system("cls");
			cout << "\n\nYou have choosen to stand up to the bully!" << endl;
			cout << "The bully doesnt like that you stood up to him and tries to pick a fight with you!" << endl;
			system("pause");
			cout << StudentName << " PUSHES  the bully!!" << endl;
			Sleep(1000);
			cout << "\nThe bully tries to grab you, you manage to dodge but trip over a chair!" << endl;
			cout << "the bully see's the teacher's walking into the canteen and he makes a dart for it" << endl;
			cout << "Bully: See you on playground " << StudentName << " i'll be waiting for you" << endl;
			cout << "\n Before the teacher's see you lying on the floor, Billy grabs you and hides you under the desk with him" << endl;
			system("pause");
			system("cls");
			cout << "Billy: That was a close one " << StudentName << ".. What took you so long?" << endl;
			cout << "\nNever mind, you got out! Well done, Now we have to get through the canteen,\n i know the way if you follow me, i just have to talk to my friend first! Are you with me ?" << endl;
			cout << "\nYou decide your only option is to follow Billy !";
			int HalfLevelTwo();
			break;
		default:
			cout << "You didnt choose a coreect option! the bully takes your money and beats you up, you have to attend the nurse and it is game over!";
			int MainMenu();
			break;
		}
}
// level two if they choose the left path
int LevelTwoLeftPath(){
	system("pause");
	system("cls");
	cout << "Your now on the left path" << endl;
	cout << "This path leads you closer to the dinner ladies, you now start to sneak under counter's" << endl;
	cout << " As your running under the counter's the cleaner spots you and offers to get you out!" << endl;
	cout << "you sneak through the remaininding canteen with the cleaner!!" << endl;
	cout << "\n\n" << endl;
	cout << "You make it to the canteen door!" << endl;
	system("pause");
	system("cls");
	cout << "Cleaner: Don't suppose you have found a rusty key along your way?" << endl;
	cin >> KeyAnswer;
	
		if (KeyAnswer == 1){
			system("cls");
			cout << "Brillant! I have been looking for that all day!\nHere take this!" << endl;
			cout << "\n\n" << endl;
			cout << StudentName << " Has recieved the master key!!!!" << endl;
			cout << "\nYou try the key in the canteen door" << endl;
			Sleep(1000);
			cout << "..." << endl;
			Sleep(1000);
			cout << "..." << endl;
			cout << "Perfect fit! you get thorugh level 2!" << endl;
			LevelThree();
		}else {
			cout << "oh! i was hoping you had it!, never mind, ill get thorugh the door!" << endl;
			cout << "the cleaner now starts to smash thorugh the door! He is causing alot of noise!" << endl;
			cout << "The dinner laides are alerted and call for security" << endl;
			cout << "Security come and your taken to the head teachers office!" << endl;
			cout << "Game over!" << endl;
		}
		
	
}

//function to billy's mates question, will be a game
int MobilePhonePuzzle(){
	
}

// end of level two function
int EndOfLevelTwo(){
	
}

int LevelThree(){
	
}




