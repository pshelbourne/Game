//Beat the school
//By Paul Shelbourne
//Aim of the game is 3 levels , trying to beat the school without getting caught.
//Getting caught will be game over

#include <iostream>
#include <string> // gives you string functions
#include <windows.h> //sleep timer from what i gathered so far.
#include <MMsystem.h> // for music
#include <fstream>
#include <stdio.h>

//-static-libgcc
//these are linkers to compiler options...
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
bool UserFirstKey;

// Level two variables
//************************************************
int LevelTwoUserInput;
int TwoRightPath;
int HelpBillysFriend;
int KeyAnswer;

// Level three variables
//************************************************
int MazeFirst;
int MazeSecond;





//functions
//************************************************


//functions used through out
//************************************************
int Detention();
void StickMan();
void StickManDetention();
void BgMusic();
int SaveGame();
int LoadGameF();


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
void ClassroomBreach();

//Level two functions
//************************************************
int LevelTwo();
int LevelTwoRightPath();
int LevelTwoLeftPath();
int HalfLevelTwo();
int MobilePhonePuzzle();

// level three function
//************************************************
int LevelThree();
int LevelThreeStart();
int MazeLeftTurn();
int MazeGate();
int EndGame();





void gotoxy(int x, int y)       //This is used with the gotoxy used below in the main function
{
  static HANDLE h = NULL;  
  if(!h)
    h = GetStdHandle(STD_OUTPUT_HANDLE);
  COORD c = { x, y };  
  SetConsoleCursorPosition(h,c);
}

//Function to manage colors
void color(int x)   
{
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, x);
}

// int main, will simply have a welcome screen, then calling the main menu function.

int main(){
	
	/*
	*within the main function i have simply got a title of the game in ascii
	*
	*it then displays text and then callls in a function near the bottom of a ascii man wiping the text clear
	
	*through out this game i have used gotoxy() which places the text in certain positions
	*
	*i have alose used the likesof a sleep timer and system pauses and clear screen's
	*/
	
	system ("color 1e"); //system color of blue background and yellow writing used throughout
	

	gotoxy(5,0); // go to xy is used throughout
	Sleep(0400); // sleeps the text before the next line is display this will be 400th of a second
	cout << "__________               __      __  .__                           .__                  .__   " << endl;
	gotoxy(5,1);  
	Sleep(0400);
	cout << "\\______   \\ ____ _____ _/  |_  _/  |_|  |__   ____     ______ ____ |  |__   ____   ____ |  |  " << endl;  
	gotoxy(5,2);
	Sleep(0400);
	cout << " |    |  _// __ \\\\__  \\\\   __\\ \\   __\\  |  \\_/ __ \\   /  ___// ___\\|  |  \\ /  _ \\ /  _ \\|  |  " << endl; // ascii writing, where there is a \ i have to add another one to escape the first one
	gotoxy(5,3); 
	Sleep(0400);
	cout << " |    |   \\  ___/ / __ \\|  |    |  | |   Y  \\  ___/   \\___ \\  \\\\___ |   Y  (  <_> |  <_> )  |__" << endl;  
	gotoxy(5,4);
	Sleep(0400);
	cout << " |______  /\\___  >____  /__|    |__| |___|  /\\___  > /____  >\\___  >___|  /\\____/ \\____/|____/ " << endl; 
	gotoxy(5,5);
	Sleep(0400);
	cout << "        \\/     \\/     \\/                  \\/     \\/       \\/     \\/     \\/                     " << endl; 
	
	
	// after the ascii title appears this appears below it using the gotoxy function then displays lets get read to run word by word
	
	
 	Sleep(0400);
	gotoxy(40,8);
	cout<< "Created & developed by Paul Shelbourne"<< endl;
	
	gotoxy(47,10);
	Sleep(0400);
	cout << "Let's";
	gotoxy(53,10);
	Sleep(0400);
	cout << "Get";
	gotoxy(57,10);
	Sleep(0400);
	cout << "Ready";
	gotoxy(63,10);
	Sleep(0400);
	cout << "To";
	gotoxy(66,10);
	Sleep(0400);
	cout << "Run" << endl;
	gotoxy(68,10);
	Sleep(1000); // sleeps for 1 second before calling in the stickman function which is a stickman ascii running across screen
	StickMan();
	gotoxy(40,10);
	system("pause"); // pauses the screen and waits for the user to hit any key
	system("cls"); // clears screen before displaying the main menu function
	
	MainMenu(); // calls main menu

}

/*Main menu functions
*
*within the main menu the user is given a few options in which the need to input a number corrisponding
*to the menu, which then calls a function
*
*/

int MainMenu(){
	
	system ("color 1e"); // same colour used thorugh out, sure i can call this globally
	
	gotoxy(40,9);
	cout<< "*MAIN MENU*"<< endl; // title of main menu
	gotoxy(40,11);
	cout<< "It is advised you read the instructions first!" << endl;
	gotoxy(40,13);
	cout<< "Please choose from the menu" << endl;
	gotoxy(40,15);
	cout << "1. Start new game " << endl; // gives the user some choices
	gotoxy(40,17);
	cout << "2. Load game" << endl;  
	gotoxy(40,19);
	cout << "3. Instructions" << endl;
	gotoxy(40,21); 
	cout << "4. Exit" << endl;
	gotoxy(40,23);
	cin>> MainMenuSelection; // waits for the user input, and stores it as MainMenuSelection
	
	while(MainMenuSelection){//While loop, loops the question until the user chooses the correct out come!
	
	// switch statement, gets the user choice(MainMenuSelection) and depending on user choice will go to the specifc case
		switch(MainMenuSelection){
			case 1:
				system("cls"); // clears screen before going to next function
				StartNewGame();
				break;
			case 2:
				system("cls"); // clears screen before going to next function
				LoadGame();
				break;	
			case 3:
				system("cls"); // clears screen before going to next function
				Instructions();
				break;
			case 4:
				system("cls"); // clears screen before going to next function
				exit(0);
				break;
			default:
				gotoxy(40,24);
				cout << "Sorry! Please enter a correct number!" << endl; // if the user does not select 1-4 ot prompts them with this message
				gotoxy(40,25);
				cin >> MainMenuSelection; // allows the user to input there choice again
		}
	}
	system("pause");
	system("cls");
}


// if the user chooses start new game from the menu

int StartNewGame(){
	
	/*
	* start new game starts with ascii writing saying level 1
	*then calls in a function of a schoolboard with the level 1 title in it (classroom breach)
	* 
	*
	*/
	
	system ("color 1e");
	gotoxy(5,0);
	Sleep(0400);
	cout <<".__                         .__     ____ " << endl;
	gotoxy(5,1);
	Sleep(0400);
	cout <<"|  |    ____ ___  __  ____  |  |   /_   |" << endl;
	gotoxy(5,2);
	Sleep(0400);
	cout <<"|  |  _/ __ \\\\  \\/ /_/ __ \\ |  |    |   |" << endl;
	gotoxy(5,3);
	Sleep(0400);
	cout <<"|  |__\\  ___/ \\   / \\  ___/ |  |__  |   |" << endl;
	gotoxy(5,4);
	Sleep(0400);
	cout <<"|____/ \\___  > \\_/   \\___  >|____/  |___|" << endl;
	gotoxy(5,5);
	Sleep(0400);
	cout <<"           \\/            \\/              " << endl;
	Sleep(1200);
	StickMan(); // stick man function called, wipes level 1 text
	ClassroomBreach(); // a new function called displays this function
	gotoxy(40,9);
	cout << "Welcome!" << endl;
	gotoxy(40,11);
	cout << "First things first! What is your name student?" << endl; // asks for the user name
	gotoxy(40,13);
	cin >>  StudentName; // user inputs name, and is stored as StudentName
	gotoxy(40,15);
	cout << "Welcome " << StudentName << " Are you ready to beat the school?" << endl; // displays text and grabs what is stored as StudentName and displays it interaction with the user
	gotoxy(40,17);
	system("pause"); // pauses the screen and waiting for the user to press any key to continue
	system("cls"); // clears the screen of the text and starts a fresh screen
	gotoxy(40,8); // after every clear screen i start the gotoxy again so every start of screen it starts from roughly thesame point
	cout << "Monday morning!"<< endl;
	gotoxy(40,10);
	cout << "you enter the classroom and sit down next to your best mate Billy" << endl;
	gotoxy(40,11);
	cout << "Miss waters address's the class, Good morning students! We have a test today!" << endl;
	gotoxy(40,13);
	cout << "Billy: " << StudentName << " I am breaking out of school! Are you with me ?Press:"<< endl; //gets the stored students name again and used for interaction
	gotoxy(40,15);
	cout << "1)Yes" << endl; // gives the user 2 choices
	gotoxy(40,17);
	cout << "2)No" << endl;
	gotoxy(40,19);
	cin >> StudentFirstInput; // asks for the user input and is stored within StudentFirstInput
	
	
	while(StudentFirstInput){ //While loop, loops the question until the user chooses the correct out come!
	
		switch(StudentFirstInput){
			case 1:
				system("cls");  // of the user selects option one it will clear screen and call in level one function
				LevelOne();
				break;
			case 2:
				system("cls"); // if the user selects option 2 it will clear screen, display text and go to detention function 
				gotoxy(40,8);
				cout << "you decided to stay and take the test!" << endl;
				gotoxy(40,10);
				cout << "you did not revise, and are caught copying another student!" << endl;
				gotoxy(40,12);
				cout << " miss water's: I will have no cheating in my classroom " << StudentName << " go see the headteacher!!!" << endl;
				gotoxy(40,16);
				cout << "you got sent to detention"<< endl;
				gotoxy(40,18);
				system("pause");
				system("cls");
				Detention();
				break;
			default:
				gotoxy(40,10);
				cout << "Sorry, please choose 1)yes or 2)no" << endl; // if the user picks anytihng else it will display this and ask for the user choice again.
				gotoxy(40,12);
				cin >> StudentFirstInput; 
		}
	}
}

// if the user chooses load game from the main menu

int LoadGame(){
	gotoxy(40,10);
	cout << "Let's Load a game save !!!!" << endl;
	//SaveGame();
}

// instructions to the game (aim of game)

int Instructions(){
	system ("color 1e");
	gotoxy(40,10);
	cout << "Welcome to beat the school!" << endl;
	Sleep(2000);
	gotoxy(40,12);
	cout << "The instructions are simple, Don't get caught!" << endl;
	Sleep(2000);
	gotoxy(40,14);
	cout << "You will battle it with teachers" << endl;
	gotoxy(40,16);
	cout << "Using your stealth and knowledge to break free!" << endl;
	Sleep(2000);
	gotoxy(40,18);
	cout << "If you fail to do so, you will be sent to the headteachers office" << endl;
	gotoxy(40,20);
	cout << "Where it is GAME OVER!" << endl;
	Sleep(2000); // the use of sleep timers through out instructions fso they are not hit with aload of text all at once
	gotoxy(40,22);
	system("pause");
	system("cls");
	gotoxy(40,10);
	cout << "The aim of the game is to break free from school without being caught" << endl;
	Sleep(2000);
	gotoxy(40,12);
	cout << "You will have to use your knowledge and answer questions" << endl;
	Sleep(2000);
	gotoxy(40,14);
	cout << "If you get caught by the headteacher, Or end up in detention" << endl;
	Sleep(2000);
	gotoxy(40,16);
	cout << "Good luck student, see you on the outside!" << endl;
	Sleep(2000);
	gotoxy(40,18);
	system("pause");
	system("cls");
	MainMenu(); // after intructions are printed out it will wait for user to press any key then clear screen and return to the main menu function
	
}

// if the user decides to exit from the main menu this function will be called and will exit the game.

int Exit (){
	exit(0);
}



//Level one function

/*Within level 1 the user is asked a series of question to break free fom the classroom
* each question has a path 
*
* choose the wrong path, they get caught and go to dentetion where it is game over
*
* there is a set off for or 5 questions before complwting level 1 and progressing to level 2
*
*/

int LevelOne(){
	gotoxy(40,10);
	cout << "Good choice! billy crawls along the floor and manages to escape!!" << endl;
	gotoxy(40,11);
	cout << "He leaves the door open for you!" << endl;
	gotoxy(40,13);
	cout << "The teacher is alerted now so the option to crawl is not avaliable!!" << endl;
	gotoxy(40,15);
	cout<< "You now have to think of another way!" << endl;
	gotoxy(40,17);
	system("pause");
	system("cls");
	gotoxy(40,10);
	cout << "You now have a choice:" << endl;
	gotoxy(40,12);
	cout << "1)Ask the teacher to go to the toilet. "<< endl;
	gotoxy(40,14);
	cout << "2)Ask James on the desk infront if he will swap seats" << endl;
	gotoxy(40,16);
	cin >> StudentSecondInput;
	
	while(StudentSecondInput){ //While loop, loops the question until the user chooses the correct out come!
	
		switch(StudentSecondInput){
			case 1:
				system("cls");
				gotoxy(40,10);
				cout << "Miss Water's: Sorry " << StudentName << endl;
				gotoxy(40,12);
				cout <<" The test is about to begin, it will have to wait!" << endl;
				gotoxy(40,14);
				cout << "that choice failed!" << endl;
				gotoxy(40,16);
				cout << "please choose another option" << endl;
				gotoxy(40,18);
				cin >> StudentSecondInput;
				break;
			case 2:
				system("cls");
				gotoxy(40,10);
				cout << "Pssst! James... Can we swap seats?" << endl;
				gotoxy(40,12);
				cout << "James: Yeah! Only if you answer this question!!" << endl;
				gotoxy(40,14);
				cout << "What is 12x12?" << endl;
				gotoxy(40,16);
				cin >> SumAnswerInput;
				
	
				if (SumAnswerInput == 144){
						system("cls");
						gotoxy(40,10);
						cout << "Correct! James moves places with you..." << endl;
						gotoxy(40,12);
						system("pause");
						gotoxy(40,14);
						cout << "Your one step closer to the door, the teacher is none the wiser" << endl;
						gotoxy(40,16);
						system("pause");
						system("cls");
						gotoxy(40,10);
						cout << "The girl next to you Sally, has heard what your plan is" << endl;
						gotoxy(40,12);
						cout << "She offers you a chance to move forward!" << endl;
						gotoxy(40,14);
						cout << "Sally: Can you help me with my homework?" << endl;
						gotoxy(40,16);
						system("pause");
						system("cls");
						gotoxy(40,10);
						cout << "You read her homework and the question is: What is the capital of Spain?" << endl;
						gotoxy(40,12);
						cout <<"1)London" << endl;
						gotoxy(40,14);
						cout << "2)Paris" << endl;
						gotoxy(40,16);
						cout << "3)Madrid" << endl;
						gotoxy(40,18);
						cout << "4)Amsterdam" << endl;
						gotoxy(40,20);
						cin >> CapitalSpain;
						
						while(CapitalSpain){
							switch(CapitalSpain){
							case 1:
								system("cls");
								gotoxy(40,10);
								cout << "Maybe your best staying in school!" << endl;
								gotoxy(40,12);
								cout << "Sally: your rubbish! i'll do it myself, you have to find another way to move seats now" << endl;
								gotoxy(40,14);
								cout << "You see a chance to run, but you get caught! GAMEOVER!" << endl;
								gotoxy(40,16);
								system ("pause");
								system ("cls");
								MainMenu(); 
								break;
							case 2:
								system("cls");
								gotoxy(40,10);
								cout << "Sally: Even i know it's not that answer!!" << endl;
								gotoxy(40,12);
								cout << "Sally: I am telling the teacher!\nSally tells the teacher and you are put in detention" << endl;
								gotoxy(40,14);
								cout << "You are now in detention and have to solve a puzzle to get out!" << endl;
								gotoxy(40,16);
								system ("pause");
								system ("cls");
								Detention();
								break;
							case 3:
								system("cls");
								gotoxy(40,10);
								cout << "Correct! Well done!" << endl;
								gotoxy(40,12);
								cout << "Sally: Thank you for the help, i found this on my way in!" << endl;
								gotoxy(40,13);
								cout << "You can have it if you want?" << endl;
								gotoxy(40,16);
								system ("pause");
								system ("cls");
								EndOfLevelOne();
								break;
							case 4:
								system("cls");
								gotoxy(40,10);
								cout << "Bad news! its the wrong answer" << endl;
								gotoxy(40,12);
								cout << "Sally: I'll do it myself " << StudentName << endl;
								gotoxy(40,14);
								cout << " Thanks for nothing!You now have to find another way out the class!" << endl;
								gotoxy(40,16);
								cout << "You see Miss Water's back turned, you try make a run for it and trip over!" << endl;
								gotoxy(40,17);
								cout << "the teacher is furious with you, and earned yourself detention!" << endl;
								gotoxy(40,19);
								system ("pause");
								system ("cls");
								Detention();
								break;
							default:
								system("cls");
								gotoxy(40,10);
								cout << "Duhh! there are only 4 possible answers! Please try again!" << endl;
								gotoxy(40,12);
								cin >> CapitalSpain;
								break;
						}
						}
				
								
					}else
						system("cls");
						gotoxy(40,10);
						cout << "Wrong answer, James tells the teacher your talking to him" << endl;
						gotoxy(40,12);
						cout << "Miss water's asks you to sit in detention while she call's your parents" << endl;
						gotoxy(40,14);
						cout << "Your sent to detention!" << endl;
						gotoxy(40,16);
						system("pause");
						system("cls");
						Detention();
						
					break;
				
			default:
			system("cls");
			gotoxy(40,10);
			cout << "I think you need to stay in school, please choose a correct option!" << endl;
			gotoxy(40,12);
			cin >> StudentSecondInput; 
			break;
		}
	}
}

// function for the end of level one

int EndOfLevelOne(){
	
	gotoxy(40,10);
	cout << "Sally offers you a rusty key, Do you want to keep it or throw it away?" << endl;
	gotoxy(40,12);
	cout << "1)Yes" << endl;
	gotoxy(40,14);
	cout << "2)No" << endl;
	gotoxy(40,16);
	cin >> UserFirstKey;
		
	
		if (UserFirstKey == 1){
			UserFirstKey == true;
			system("cls");
			gotoxy(40,10);
			cout << "You place the key in your pocket, the teacher is speaking to another student!" << endl;
			gotoxy(40,12);
			cout << StudentName << " makes a run for it!!!" << endl;
			gotoxy(40,14);
			Sleep(1000);
			cout << "..." << endl;
			gotoxy(40,16);
			Sleep(1000);
			gotoxy(40,18);
			cout << "You made it !!!" << endl;
			gotoxy(40,20);
			cout << "You have entered the corridor and the first level is complete!!!" << endl;
			gotoxy(40,22);
			system("pause");
			system("cls");
			LevelTwo();	
		}else {
			system("cls");
			gotoxy(40,10);
			cout << "You don't take the key, the teacher is speaking to another student!" << endl;
			gotoxy(40,12);
			cout << StudentName << " makes a run for it!!!" << endl;
			gotoxy(40,14);
			Sleep(1000);
			cout << "..." << endl;
			gotoxy(40,16);
			cout << "You made it !!!" << endl;
			gotoxy(40,18);
			cout << "You have entered the corridor and the first level is complete!!!" << endl;
			gotoxy(40,20);
			system("pause");
			system("cls");
			LevelTwo();	
		}
	
}

// Detention function
/*
* detention function will display in big ascii writing detention
* the screen will also change from blue to read as a warning
* 
* once in detention it is game over and the user then has to return to the main menu
*
*/


int Detention(){
	system("color 47");
	gotoxy(5,0);
	Sleep(0400);
	cout << "________            __                    __   .__                ._.._.._." << endl;
	gotoxy(5,1);
	Sleep(0400);
	cout << "\\______ \\    ____ _/  |_   ____    ____ _/  |_ |__|  ____    ____ | || || |" << endl;
	gotoxy(5,2);
	Sleep(0400);
	cout << " |    |  \\ _/ __ \\\\   __\\_/ __ \\  /    \\\\   __\\|  | /  _ \\  /    \\| || || |" << endl;
	gotoxy(5,3);
	Sleep(0400);
	cout << " |    `   \\\\  ___/ |  |  \\  ___/ |   |  \\|  |  |  |(  <_> )|   |  \\\\| \\| \\|" << endl;
	gotoxy(5,4);
	Sleep(0400);
	cout << "/_______  / \\___  >|__|   \\___  >|___|  /|__|  |__| \\____/ |___|  /__ __ __" << endl;
	gotoxy(5,5);
	Sleep(0400);
	cout << "        \\/      \\/            \\/      \\/                        \\/ \\/ \\/ \\/" << endl;
	Sleep(1200);
	StickManDetention();
	gotoxy(40,10);
	system("pause");
	system("cls");
	MainMenu();
}

//Level two functions

/*
*Within level 2 the user must get through the canteen without being seen, the user first decides on what path to go
* 
*the user is then asked a set of questions which they must figure out in order to complete level 2
*
* choose the wrong path, they get caught and go to dentetion where it is game over
*
* once completing level 2 its then onto the final level.. level 3
*
*/


int LevelTwo(){
	
	gotoxy(5,0);
	Sleep(0400);
	cout <<".____                          .__    ________" << endl;
	gotoxy(5,1);
	Sleep(0400);  
	cout <<"|    |     ____ ___  __  ____  |  |   \\_____  \\ " << endl;
	gotoxy(5,2);
	Sleep(0400);
	cout <<"|    |   _/ __ \\\\  \\/ /_/ __ \\ |  |    /  ____/ " << endl;
	gotoxy(5,3);
	Sleep(0400);
	cout <<"|    |___\\  ___/ \\   / \\  ___/ |  |__ /       \\ " << endl;
	gotoxy(5,4);
	Sleep(0400);
	cout <<"|_______ \\\\___  > \\_/   \\___  >|____/ \\_______ \\ " << endl;
	gotoxy(5,5);
	Sleep(0400);
	cout <<"        \\/    \\/            \\/                \\/" << endl;
	Sleep(1200);
	StickMan();
	gotoxy(40,10);
	cout << "Reaching the corridor, you start walking to the school yard" << endl;
	gotoxy(40,12);
	cout << "The student hall monitors are in the distance" << endl;
	gotoxy(40,14);
	cout << "You have to sneak in to the nearest door." << endl;
	gotoxy(40,16);
	system("pause");
	gotoxy(40,18);
	system("cls");
	gotoxy(40,10);
	cout << "the door you sneak into is the canteen!" << endl;
	gotoxy(40,12);
	cout << "its almost dinner and the dinner ladies are preparing for the rush!" << endl;
	gotoxy(40,14);
	system ("pause");
	system ("cls");
	gotoxy(40,10);
	cout << "You have to get through without being seen!" << endl;
	gotoxy(40,12);
	cout << "Firstly, do you want to take option left or right?" << endl;
	gotoxy(40,14);
	cout << "1)Left" << endl;
	gotoxy(40,16);
	cout << "2)Right" << endl;
	gotoxy(40,18);
	cin >> LevelTwoUserInput;
	
	while(LevelTwoUserInput){
		switch(LevelTwoUserInput){
			case 1:
				system("cls");
				gotoxy(40,10);
				cout << "You have choosen the path to the left!" << endl;
				gotoxy(40,12);
				cout << "This has brought you closer to the dinner ladies" << endl;
				gotoxy(40,14);
				cout << "Get caught by them and it's straight into detention!" << endl;
				gotoxy(40,16);
				system("pause");
				LevelTwoLeftPath();
				break;
			case 2:
				system("cls");
				gotoxy(40,10);
				cout << "You have choosen the path to the right!" << endl;
				gotoxy(40,12);
				cout << "Good choice, your now more hidden from the dinner ladies!" << endl;
				gotoxy(40,14);
				system("pause");
				LevelTwoRightPath();
				break;
			default:
				gotoxy(40,10);
				cout << "Pssst, your supposed to click either 1 or 2 !!!" << endl;
				gotoxy(40,12);
				cin >> LevelTwoUserInput;
				break;
		}
	}

}


// function for half way through level two

int HalfLevelTwo(){
	system("cls");
	gotoxy(40,10);
	cout << "Billy: That was a close one " << StudentName << ".. What took you so long?" << endl;
	gotoxy(40,12);
	cout << "Never mind, you got out! Well done, Now we have to get through the canteen!" << endl;
	gotoxy(40,14);
	cout << "I know the way if you follow me" << endl;
	gotoxy(40,16);
	cout << "You decide your only option is to follow Billy !"<< endl;
	gotoxy(40,18);
	system("pause");
	system("cls");
	gotoxy(40,10);
	cout << "Billy: Follow me!! but be quiet!" << endl;
	gotoxy(40,12);
	cout << "You follow billy as you crawl under the tables!" << endl;
	gotoxy(40,14);
	system("pause");
	system ("cls");
	gotoxy(40,10);
	cout << "You reach the end of the canteen! The door is open but the teacher is on gaurd!" << endl;
	gotoxy(40,12);
	cout << "You throw a bottle, it attracts the teacher to go inspect!" << endl;
	gotoxy(40,14);
	cout << "Billy see's the chance to run, he grabs you and you make it!" << endl;
	gotoxy(40,18);
	cout << "Level 2 is complete!!!"<< endl;
	gotoxy(40,20);
	system("pause");
	system("cls");
	LevelThree();
	
	
	
}

// level two if the user chooses the right path 

int LevelTwoRightPath(){
	gotoxy(40,10);
	cout << "This path has lead you away from the dinner ladies, good choice!" << endl;
	gotoxy(40,12);
	cout << "The school bully is standing in your way and asks for your lunch money!" << endl;
	gotoxy(40,14);
	cout << "Your only options is to hand over your money or stand up to him!" << endl;
	gotoxy(40,16);
	cout << "1)Hand money over" << endl;
	gotoxy(40,18);
	cout << "2)Stand up to the school bully" << endl;
	gotoxy(40,20);
	cin >> TwoRightPath;
	
	while (TwoRightPath){
		switch(TwoRightPath){
		case 1:
			system("cls");
			gotoxy(40,10);
			cout << "You have choosen to hand the money over!" << endl;
			gotoxy(40,12);
			cout << "He laughs and pushes you over, it causes a comotion! " << endl;
			gotoxy(40,14);
			cout << "All the pupils crowd around and the diner ladies are alerted, you make a run for it" << endl;
			gotoxy(40,16);
			cout << StudentName << " ran out into the corridor, where two teachers are talking!" << endl;
			gotoxy(40,18);
			cout << "You been caught out off class, your sent to detention!" << endl;
			gotoxy(40,22);
			system("pause");
			system("cls");
			Detention();
			break;
		case 2:
			system("cls");
			gotoxy(40,10);
			cout << "You have chosen to stand up to the bully!" << endl;
			gotoxy(40,12);
			cout << "The bully doesnt like that you stood up to him and tries to pick a fight with you!" << endl;
			gotoxy(40,14);
			system("pause");
			gotoxy(40,16);
			cout << StudentName << " PUSHES  the bully!!" << endl;
			Sleep(1000);
			gotoxy(40,18);
			cout << "The bully tries to grab you, you manage to dodge but trip over a chair!" << endl;
			gotoxy(40,20);
			cout << "The bully see's the teacher's walking into the canteen and he makes a dart for it" << endl;
			gotoxy(40,22);
			system("pause");
			system("cls");
			gotoxy(40,10);
			cout << "Bully: See you on playground " << StudentName << endl;
			gotoxy(40,12);
			cout << " I'll be waiting for you" << endl;
			gotoxy(40,14);
			cout << "Before the teacher's see you lying on the floor..." << endl; 
			gotoxy(40,16);
			cout << "Billy grabs you and hides you under the desk with him" << endl;
			gotoxy(40,18);
			system("pause");
			system("cls");
			HalfLevelTwo();
			break;
		default:
			gotoxy(40,10);
			cout << "You didnt choose a correct option!"<< endl;
			gotoxy(40,12);
			cout << "1)Hand money over" << endl;
			gotoxy(40,14);
			cout << "2)Stand up to the school bully" << endl;
			gotoxy(40,16);
			cin >> TwoRightPath;
			break;
		}
	}
}
// level two if they choose the left path
int LevelTwoLeftPath(){
	gotoxy(40,10);
	system("pause");
	system("cls");
	gotoxy(40,10);
	cout << " As your running under the counter's the cleaner spots you and offers to get you out!" << endl;
	cout << "you sneak through the remaininding canteen with the cleaner!!" << endl;
	gotoxy(40,12);
	cout << "You make it to the canteen door!" << endl;
	gotoxy(40,14);
	system("pause");
	system("cls");
	gotoxy(40,10);
	cout << "Cleaner: Don't suppose you have found a rusty key along your way?" << endl;
	gotoxy(40,12);
	cout <<"Checking for key..." << endl;
	gotoxy(40,16);
	system("pause");
	system("cls");
		
		if (UserFirstKey == true){
			gotoxy(40,10);
			cout << "Brillant! I have been looking for that all day! " << endl;
			gotoxy(40,12);
			cout << "Here take this!" << endl;
			gotoxy(40,14);
			cout << StudentName << " Has recieved the master key!!!!" << endl;
			gotoxy(40,16);
			cout << "You try the key in the canteen door" << endl;
			Sleep(1000);
			gotoxy(40,18);
			cout << "..." << endl;
			Sleep(1000);
			gotoxy(40,20);
			cout << "..." << endl;
			gotoxy(40,22);
			cout << "Perfect fit! you get thorugh level 2!" << endl;
			gotoxy(40,24);
			system("pause");
			LevelThree();
		}else {
			gotoxy(40,10);
			cout << "oh! i was hoping you had it!, never mind, ill get thorugh the door!" << endl;
			gotoxy(40,12);
			cout << "the cleaner now starts to smash thorugh the door! " << endl;
			gotoxy(40,14);
			cout << "He is causing alot of noise!" << endl;
			gotoxy(40,16);
			cout << "The dinner laides are alerted and call for security" << endl;
			gotoxy(40,18);
			cout << "Security come and your taken to the head teachers office!" << endl;
			gotoxy(40,20);
			cout << "Game over!" << endl;
			gotoxy(40,22);
			system("pause");
			system("cls");
			MainMenu();
		}
	
		
		
	
}




//Level three

int LevelThree(){
	system("cls");
	
	gotoxy(5,0);
	Sleep(0400);
	cout <<".____                          .__    ________  " << endl;
	gotoxy(5,1);
	Sleep(0400);
	cout <<"|    |     ____ ___  __  ____  |  |   \\_____  \\ " << endl;
	gotoxy(5,2);
	Sleep(0400);
	cout <<"|    |   _/ __ \\\\  \\/ /_/ __ \\ |  |     _(__  < " << endl;
	gotoxy(5,3);
	Sleep(0400);
	cout <<"|    |___\\  ___/ \\   / \\  ___/ |  |__  /       \\ " << endl;
	gotoxy(5,4);
	Sleep(0400);
	cout <<"|_______ \\\\___  > \\_/   \\___  >|____/ /______  /" << endl;
	gotoxy(5,5);
	Sleep(0400);
	cout <<"        \\/    \\/            \\/               \\/ " << endl;
	Sleep(1200);
	StickMan();
	gotoxy(40,10);
	system("pause");
	system("cls");
	gotoxy(40,10);
	cout << StudentName << "This will be the toughest level as the headteacher is on yard duty today!" << endl;
	gotoxy(40,12);
	cout << "You will have to answer multiple answers and choose your path!" << endl;
	gotoxy(40,14);
	cout << "Get them wrong and the teacher moves closer to you!" << endl;
	gotoxy(40,16);
	system("pause");
	system("cls");
	gotoxy(40,10);
	cout << "Your task is to tackle thorugh a maze and reach the gate!" << endl;
	gotoxy(40,12);
	system("pause");
	system("cls");
	LevelThreeStart(); // goes to the next function
	
}

int LevelThreeStart(){

	cout << "Left direction\t\tRight direction\n" << endl;
	cout << "\t\t.--.--.--.  .--.--." << endl;
	cout << "\t\t|     |   *    |  |" << endl;
	cout << "\t\t:  :--:  :  :  :  :" << endl;
	cout << "\t\t|  |     |  |     |" << endl;
	cout << "\t\t:  :  :  :--:--:--:" << endl;
	cout << "\t\t|  |  |           |" << endl;
	cout << "\t\t:  :  :--:--:--:  :" << endl;
	cout << "\t\t|  |        |  |  |" << endl;
	cout << "\t\t:  :--:--:  :  :  :" << endl;
	cout << "\t\t|     |     |  |  |" << endl;
	cout << "\t\t:--:  :  :--:  :  :" << endl;
	cout << "\t\t|        |        |" << endl;
	cout << "\t\t:  :--:--:--:--:--:" << endl;
	gotoxy(40,10);
	system("pause");
	
	gotoxy(40,12);
	cout << "Welcome to Level Three" << endl;
	gotoxy(40,14);
	cout << "You are the * and you must get through the maze, choosing left or right path!" << endl;
	gotoxy(40,16);
	system("pause");
	system("cls");
	
	cout << "Left direction\t\tRight direction\n" << endl;
	cout << "\t\t.--.--.--.  .--.--." << endl;
	cout << "\t\t|     |   *    |  |" << endl;
	cout << "\t\t:  :--:  :  :  :  :" << endl;
	cout << "\t\t|  |     |  |     |" << endl;
	cout << "\t\t:  :  :  :--:--:--:" << endl;
	cout << "\t\t|  |  |           |" << endl;
	cout << "\t\t:  :  :--:--:--:  :" << endl;
	cout << "\t\t|  |        |  |  |" << endl;
	cout << "\t\t:  :--:--:  :  :  :" << endl;
	cout << "\t\t|     |     |  |  |" << endl;
	cout << "\t\t:--:  :  :--:  :  :" << endl;
	cout << "\t\t|        |        |" << endl;
	cout << "\t\t:  :--:--:--:--:--:" << endl;
	
	gotoxy(40,10);
	cout << "Firstly do you want to go:" << endl;
	gotoxy(40,12);
	cout << "1)Left" << endl;
	gotoxy(40,14);
	cout << "2)Right" << endl;
	gotoxy(40,16);
	cin >> MazeFirst; // now asks the user for a choice, left or right and is stored within this variable here ( mazeFirst)

while(MazeFirst) { // loops the question incase the do not correctly choose left or right
	
	switch(MazeFirst) {
		case 1:
			system("cls");
			cout << "Left direction\t\tRight direction\n" << endl;
			cout << "\t\t.--.--.--.  .--.--." << endl;
			cout << "\t\t|     |        |  |" << endl;
			cout << "\t\t:  :--:  :  :  :  :" << endl;
			cout << "\t\t|  |  *  |  |     |" << endl;
			cout << "\t\t:  :  :  :--:--:--:" << endl;
			cout << "\t\t|  |  |           |" << endl;
			cout << "\t\t:  :  :--:--:--:  :" << endl;
			cout << "\t\t|  |        |  |  |" << endl;
			cout << "\t\t:  :--:--:  :  :  :" << endl;
			cout << "\t\t|     |     |  |  |" << endl;
			cout << "\t\t:--:  :  :--:  :  :" << endl;
			cout << "\t\t|        |        |" << endl;
			cout << "\t\t:  :--:--:--:--:--:" << endl;
			gotoxy(40,10);
			
			
			gotoxy(40,12);
			cout << "You have choosen the Left path!, it places you to a new destination" << endl;
			MazeLeftTurn(); // if they decide to go left on user choice it will display the newmap with the new postion then go to this next function
			break;
		case 2:
			system("cls");
			cout << "Left direction\t\tRight direction\n" << endl;
			cout << "\t\t.--.--.--.  .--.--." << endl;
			cout << "\t\t|     |        |* |" << endl;
			cout << "\t\t:  :--:  :  :  :  :" << endl;
			cout << "\t\t|  |     |  |     |" << endl;
			cout << "\t\t:  :  :  :--:--:--:" << endl;
			cout << "\t\t|  |  |           |" << endl;
			cout << "\t\t:  :  :--:--:--:  :" << endl;
			cout << "\t\t|  |        |  |  |" << endl;
			cout << "\t\t:  :--:--:  :  :  :" << endl;
			cout << "\t\t|     |     |  |  |" << endl;
			cout << "\t\t:--:  :  :--:  :  :" << endl;
			cout << "\t\t|        |        |" << endl;
			cout << "\t\t:  :--:--:--:--:--:" << endl;
			gotoxy(40,10);
			system("pause");
			
			gotoxy(40,12);
			cout << "You have choosen the right path!, it places you to a new destination" << endl;
			gotoxy(40,14);
			cout << "you hit a dead end!, you make a run back and brings you to the start again!" << endl;
			gotoxy(40,16);
			system("pause");
			system("cls");
			cout << "Left direction\t\tRight direction\n" << endl;
			cout << "\t\t.--.--.--.  .--.--." << endl;
			cout << "\t\t|     |   *    |  |" << endl;
			cout << "\t\t:  :--:  :  :  :  :" << endl;
			cout << "\t\t|  |     |  |     |" << endl;
			cout << "\t\t:  :  :  :--:--:--:" << endl;
			cout << "\t\t|  |  |           |" << endl;
			cout << "\t\t:  :  :--:--:--:  :" << endl;
			cout << "\t\t|  |        |  |  |" << endl;
			cout << "\t\t:  :--:--:  :  :  :" << endl;
			cout << "\t\t|     |     |  |  |" << endl;
			cout << "\t\t:--:  :  :--:  :  :" << endl;
			cout << "\t\t|        |        |" << endl;
			cout << "\t\t:  :--:--:--:--:--:" << endl;
			gotoxy(40,10);
			system("pause");
			
			gotoxy(40,12);
			cout << "Your back at the start! Lucky you was'nt caught!" << endl;
			gotoxy(40,14);
			cout << "What route would you like to take?" << endl;
			gotoxy(40,16);
			cout << "1)Left" << endl;
			gotoxy(40,18);
			cout << "2)Right" << endl;
			gotoxy(40,20);
			cin >> MazeFirst;
			break;
	default:
		system("cls");
		gotoxy(40,12);
		cout << "Please choose a correct option" << endl;
		gotoxy(40,14);
		cout << "1)Left" << endl;
		gotoxy(40,16);
		cout << "2)Right" << endl;
		gotoxy(40,18);
		cin >> MazeFirst;
		break;
}
}

}

int MazeLeftTurn(){
	system("cls");
	cout << "Left direction\t\tRight direction\n" << endl;
	cout << "\t\t.--.--.--.  .--.--." << endl;
	cout << "\t\t|     |        |  |" << endl;
	cout << "\t\t:  :--:  :  :  :  :" << endl;
	cout << "\t\t|  |  *  |  |     |" << endl;
	cout << "\t\t:  :  :  :--:--:--:" << endl;
	cout << "\t\t|  |  |           |" << endl;
	cout << "\t\t:  :  :--:--:--:  :" << endl;
	cout << "\t\t|  |        |  |  |" << endl;
	cout << "\t\t:  :--:--:  :  :  :" << endl;
	cout << "\t\t|     |     |  |  |" << endl;
	cout << "\t\t:--:  :  :--:  :  :" << endl;
	cout << "\t\t|        |        |" << endl;
	cout << "\t\t:  :--:--:--:--:--:" << endl;
	gotoxy(40,10);
	system("pause");
		
	gotoxy(40,12);
	cout << "Billy run's off to the Left! Do you want to follow or go right?" << endl;
	gotoxy(40,14);
	cout << "1)Go right" << endl;
	gotoxy(40,16);
	cout << "2)Stay left" << endl;
	gotoxy(40,18);
	cin >> MazeSecond;
		
	while(MazeSecond) {
		
		if(MazeSecond == 1) {
		system("cls");
		cout << "Left direction\t\tRight direction\n" << endl;
		cout << "\t\t.--.--.--.  .--.--." << endl;
		cout << "\t\t|     |        |  |" << endl;
		cout << "\t\t:  :--:  :  :  :  :" << endl;
		cout << "\t\t|  |     |  |     |" << endl;
		cout << "\t\t:  :  :  :--:--:--:" << endl;
		cout << "\t\t|  |  |           |" << endl;
		cout << "\t\t:  :  :--:--:--:  :" << endl;
		cout << "\t\t|  |        |  |  |" << endl;
		cout << "\t\t:  :--:--:  :  :  :" << endl;
		cout << "\t\t|     |     |  |  |" << endl;
		cout << "\t\t:--:  :  :--:  :  :" << endl;
		cout << "\t\t|        |   *    |" << endl;
		cout << "\t\t:  :--:--:--:--:--:" << endl;
		gotoxy(40,10);
		system("pause");
		
		gotoxy(40,12);
		cout << "Your new destination is here, but the teacher is walking towards you..." << endl;
		gotoxy(40,14);
		cout << "There is no place to hide!" << endl;
		gotoxy(40,16);
		cout << "What are you doing on the yard this early" << endl;
		gotoxy(40,18);
		cout << "get to the headteachers office now!!!" << endl;
		gotoxy(40,20);
		system("pause");
		LevelThree();
		//returns to level 3
		
		
	}else if(MazeSecond == 2){
	system("cls");
	cout << "Left direction\t\tRight direction\n" << endl;
	cout << "\t\t.--.--.--.  .--.--." << endl;
	cout << "\t\t|     |        |  |" << endl;
	cout << "\t\t:  :--:  :  :  :  :" << endl;
	cout << "\t\t|  |     |  |     |" << endl;
	cout << "\t\t:  :  :  :--:--:--:" << endl;
	cout << "\t\t|  |  |           |" << endl;
	cout << "\t\t:  :  :--:--:--:  :" << endl;
	cout << "\t\t|  |        |  |  |" << endl;
	cout << "\t\t:  :--:--:  :  :  :" << endl;
	cout << "\t\t|     |     |  |  |" << endl;
	cout << "\t\t:--:  :  :--:  :  :" << endl;
	cout << "\t\t|    *   |        |" << endl;
	cout << "\t\t:  :--:--:--:--:--:" << endl;
	gotoxy(40,10);
	system("pause");
		
	gotoxy(40,12);
	cout << "You have chosen to stay left you make a run for it!" << endl;
	gotoxy(40,14);
	cout << "It's brought you closer to the gate!" << endl;
	gotoxy(40,16);
	cout << "You see the gate!...Billy is waiting to give you a lift over it!"<< endl;
	gotoxy(40,18);
	cout << "You get over the gate and you have BEAT THE SCHOOL!" << endl;
	gotoxy(40,20);
	system("pause");
	MazeGate();
	
	}else{
		gotoxy(40,20);
		cout <<"Please choose 1 or 2..." << endl;
		cin >> MazeSecond;
	}	
}	
}

int MazeGate(){
	system ("cls");
	gotoxy(40,10);
	cout << "You reach the gate!" << endl;
	gotoxy(40,12);
	cout << "Billy: Well done " << StudentName << " you have made it without being caught!" << endl;
	gotoxy(40,14);
	cout << "You have beaten the school!" << endl;
	EndGame();
	
}

int EndGame(){
	system("cls");
	
	gotoxy(5,0);
	Sleep(0400);
	cout << " __      __         .__   .__        .___                      ._." << endl;
	gotoxy(5,1);
	Sleep(0400);
	cout << "/  \\    /  \\  ____  |  |  |  |     __| _/ ____    ____    ____ | |" << endl;
	gotoxy(5,2);
	Sleep(0400);
	cout << "\\   \\/\\/   /_/ __ \\ |  |  |  |    / __ | /  _ \\  /    \\ _/ __ \\| |" << endl;
	gotoxy(5,3);
	Sleep(0400);
	cout << " \\        / \\  ___/ |  |__|  |__ / /_/ |(  <_> )|   |  \\\\  ___/ \\|" << endl;
	gotoxy(5,4);
	Sleep(0400);
	cout << "  \\__/\\  /   \\___  >|____/|____/ \\____ | \\____/ |___|  / \\___  >__" << endl;
	gotoxy(5,5);
	Sleep(0400);
	cout << "       \\/        \\/                   \\/             \\/      \\/ \\/" << endl;
	Sleep(1200);
	StickMan();
	gotoxy(40,10);
	system("pause");
	system("cls");
	
	
	
}


void StickMan(){
	 	
	PlaySound(TEXT("heartbeat1.WAV"),NULL, SND_ASYNC);

	for(int a = 0; a < 100; a = a + 1){
	
	
	gotoxy(0+a,0);
	 cout <<"             \\\\\\\\ " << endl;
	 gotoxy(0+a,1);
	 cout <<"             \\c .( " << endl;
	 gotoxy(0+a,2);
	 cout <<"              \\ _/ " << endl;
	 gotoxy(0+a,3);
	 cout <<"          ___/(  /( " << endl;
	 gotoxy(0+a,4);
	 cout <<"          /--/ \\\\// " << endl;
	 gotoxy(0+a,5);
	 cout <<"      __ )/ /\\/ \\/ " << endl;
	 gotoxy(0+a,6);
	 cout <<"     `-.\\  //\\\\ " << endl;
	 gotoxy(0+a,7);
	 cout <<"        \\\\//  \\\\ " << endl;
	 gotoxy(0+a,8);
	 cout <<"         \\/    \\\\ " << endl;
	 gotoxy(0+a,9);
	 cout <<"                \\\\ " << endl;
	 gotoxy(0+a,10);
	 cout <<"                '--` " << endl;
	Sleep(0050);
	
	
                                                                                               
}
system("cls");
}

void StickManDetention(){
	
	PlaySound(TEXT("heartbeat1.WAV"),NULL, SND_ASYNC);
	
	for(int a = 0; a < 100; a = a + 1){

	
	gotoxy(100-a,0);
	 cout <<"             \\\\\\\\ " << endl;
	 gotoxy(100-a,1);
	 cout <<"             \\c .( " << endl;
	 gotoxy(100-a,2);
	 cout <<"              \\ _/ " << endl;
	 gotoxy(100-a,3);
	 cout <<"          ___/(  /( " << endl;
	 gotoxy(100-a,4);
	 cout <<"          /--/ \\\\// " << endl;
	 gotoxy(100-a,5);
	 cout <<"      __ )/ /\\/ \\/ " << endl;
	 gotoxy(100-a,6);
	 cout <<"     `-.\\  //\\\\ " << endl;
	 gotoxy(100-a,7);
	 cout <<"        \\\\//  \\\\ " << endl;
	 gotoxy(100-a,8);
	 cout <<"         \\/    \\\\ " << endl;
	 gotoxy(100-a,9);
	 cout <<"                \\\\ " << endl;
	 gotoxy(100-a,10);
	 cout <<"                '--` " << endl;
	Sleep(0050);
	
	
                                                                                               
}
system("cls");

}

void BgMusic(){
	PlaySound(TEXT("bgMusic.mp3"),NULL, SND_ASYNC);
}

void ClassroomBreach(){
	
	gotoxy(5,0);
	
	cout << "   |.==================================,| " << endl;
    cout << "	||   I WILL LISTEN TO THE TEACHER.  || " << endl;
    cout << "	||   I WILL LISTEN TO THE TEACHER.  || " << endl;
    cout << "	||   I WILL LISTEN TO THE TEACHER.  || " << endl;
    cout << "	||   I .----;ISTEN ,                || " << endl;
    cout << "	|| /`\\/      \\/`\\ /                 || " << endl;
    cout << "	|| )_/|      |\\_(/\\                 || " << endl;
    cout << "	||    \\______/  /\\/     CLASSROOM   || " << endl;
    cout << "	||    _(____)__/ /      BREACH      || " << endl;
    cout << "	||___/ ,_ _  ___/___________________|| " << endl;
    
    cout << "	'====\\___\\_) |=======================' " << endl;
    cout << "	      |______| " << endl;
    cout << "	      /______\\ " << endl;
    cout << "	       |_||_| " << endl;
    cout << "	      (__)(__) " << endl;
    Sleep(2000);
    system("cls");
}


SaveGame(){
	
	ofstream file_ptr;		//declare file pointer
	char filename [100];
	
	cout << "\nEnter the filename to be stored:";
	gets (filename);
	
	//file_ptr.open("info.dat",ios::out);
	file_ptr.open(filename,ios::out);
						//open file called info.dat for output
	
	
	char name[30];
	int count;
	
	if(!file_ptr)				//check file open ok
	  cout<<"Error opening file info.dat";
	else
	{
		for(count=1;count<=5;count++)
		{
			cout<<"\n Please enter a name: ";
			gets(name);
			file_ptr<<count<<" "<<name<<"\n";
		}
	}
	file_ptr.close();			//close file
	
	system("pause");
	system("cls");
}


LoadGameF(){
		ifstream file_ptr;			//declare file pointer
	char filename [100];
	
	cout << "\nEnter the filename to be read:";
	gets (filename);
	
	//file_ptr.open("info.dat",ios::in);
	file_ptr.open(filename,ios::in);
									  //open file called info.dat for input
	
	
	char in_char;				 //temp variable for file data
	
	if(!file_ptr)				 //check file opened ok
	   cout<<"Error...File does not exist";
	else
	{
		while(!file_ptr.eof())   //while not end of file
		{
			file_ptr.get(in_char);	//get character from file
			cout<<in_char;				//print latest character
			
		}
		cin.get();
	}
	file_ptr.close();					//close file
	
	system("pause");
	system("cls");
}
