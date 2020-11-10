#include<iostream>
#include<conio.h> // for getting single character by using getch function
#include<Windows.h> // set cursor position
#include<time.h>	// use for dellay + in srand function
#include<fstream> // file handelling
#include <stdlib.h>  // for random number
#include"TicTac.h"

using namespace std;

ticTac::ticTac() { // allocate memory when user use default table
	size = 3;
	table = new int* [size];
	for (int i = 0; i < size; i++) {
		table[i] = new int[size];
	}
	putValues();

}

ticTac::ticTac(int size) {
	this->size = size;
	table = new int* [size];
	for (int i = 0; i < size; i++) {
		table[i] = new int[size];
	}
	putValues();

}

ticTac::ticTac(const ticTac& game) {
	this->size = game.size;
	table = new int* [size];
	for (int i = 0; i < size; i++) {
		table[i] = new int[size];
	}
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			this->table[i][j] = game.table[i][j];
		}
	}
}
void ticTac::putValues() { //initialize 2d pointer
	int n = 1; // use to initialize data member of class
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			table[i][j] = n;
			n++;
		}
	}
}

char ticTac::tosse() { // stelect which player will play first
	srand(time(0)); // clean rand buffer;
	int temp = rand() % 2; // give just 0 &1
	if (temp) {
		return 'x';
	}
	else {
		return 'o';
	}
}

void ticTac::setxy(int x, int y) {// this will set cursor position
	COORD c = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

int ticTac::delaay(int number_of_seconds) {
	int milli_seconds = 50 * number_of_seconds; // Converting time into milli_seconds  
	clock_t start_time = clock();     // Stroing start time 
	while (clock() < start_time + milli_seconds); // looping till required time is not acheived 
	return clock();
}

void ticTac::getSave(int participant) { // enter data in a file
	ofstream fout;
	fout.open("input.txt");
	if (fout.is_open()) {
		fout << size << "\n";
		fout << "participant : " << (char)participant << "\n"; // enter data in file of particepent
		for (int i = 0; i < size; i++) { // control row
			for (int j = 0; j < size; j++) { // control coloum
				fout << table[i][j] << "\t"; // enter data in file from data member of class
			}
			fout << "\n";
		}
	}
	fout.close();
	cout << "\nGAME SAVE SUCCESSFULLY";
}
void ticTac::putLoad(char& participant) { // get data from file
	ifstream fin;
	fin.open("input.txt");
	if (fin.is_open()) {
		{
			fin >> this->size; // read size from file and store  it in size variable
			char ctemp = 'i';
			while (!(ctemp == 'x' || ctemp == 'o')) { // untill ctemp not equal to participants
				fin >> ctemp;
				participant = ctemp;
			}
		}
		for (int i = 0; i < size; i++) { // control rows
			for (int j = 0; j < size; j++) { // control coloum
				fin >> table[i][j]; // enter data in mamber data of class from file
			}
		}
	}
	else {
		cout << "\nFile not open";
	}
	fin.close();
}


int ticTac::getTable(int arr[3][3]) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < 3; j++) {
			arr[i][j] = table[i][j];
		}
	}
	return 0;
}

void ticTac::downloadScreen() {
	int loadingSpeed = 0;

	for (int i = 1; i <= 50; i++) { // for printing of horizontal line
		system("CLS");
		setxy(30, 9); // set cursore position
		for (int j = 0; j < 60; j++) cout << char(177);
		for (int j = 0; j < 10; j++) {
			setxy(30, 10 + j); cout << char(177); setxy(89, 10 + j); cout << char(177);
		}
		setxy(30, 20);
		for (int j = 0; j < 60; j++) cout << char(177);
		setxy(55, 12);
		cout << "Loading ";
		for (int j = 1; j <= i; j++) {
			loadingSpeed = 10;
			setxy(33 + j, 14);
			cout << char(219);
		}
		cout << 2 * i << "%";
		if (i >= 1 && i <= 20) { //display message when i between 1 to 20
			loadingSpeed = 8;
			setxy(45, 16);
			cout << "Creating Temporary files";
		}
		else if (i >= 20 && i <= 40) { // display message when i between 20 to 40
			setxy(45, 16);
			loadingSpeed = 5;
			cout << "Accessing Main Memory";
		}
		else if (i >= 40 && i <= 48) { // display message when i between 40 to 48
			loadingSpeed = 4;
			setxy(45, 16);
			cout << "Accessing Cache";
		}
		else {
			setxy(55, 16);
			loadingSpeed = 1;
			cout << "Complete. ";
		}
		delaay(loadingSpeed);
	}
	delaay(10);
}

void ticTac:: help(){ // provide necessary inforamtion to the user
	system("CLS");
	setxy(40,10); // ste cursor position on counsole
	for(int i = 0; i < 49; i++){ // print top line
		cout<<char(177); // print a character by its ascii value
	}
	setxy(40,11);
	cout<<char(177)<<" "<< char(254) <<" You can quit game by pressing \"-1\"\t\t"<<char(177);
	setxy(40,12);
	cout<<char(177)<<" " << char(254) << " There are two participent \"x\" & \"o\"\t\t"<<char(177);
	setxy(40,13);
	cout<<char(177) << " " << char(254) << " You can choose 1 to "<<size * size<<" any box\t\t"<<char(177);
	setxy(40, 14);
	cout << char(177) << " " << char(254) << " BeCarefull in selection of boxes or table   " << char(177);
	setxy(40, 15);
	cout << char(177) << " " << char(254) << " Your game automatically save when you exist " << char(177);
	setxy(40, 16);
	cout << char(177) << "   but not applicable on ultra Tic Tac Toe     "<<char(177);
	setxy(40, 17);
	cout << char(177) << " " << char(254) << " Now press any key to continue\t\t" << char(177);
	setxy(40, 18);
	for (int i = 0; i < 49; i++) { // print bottom line
		cout << char(177);
	}
	cout << "\n";
}

/*table PRINT
   in following format
	 _ _ _ _
	|_|_|_|_|
	|_|_|_|_|
	|_|_|_|_|
   */
void ticTac:: print(int x, int y) {
	int line = (12 * size); // control top and bottom boarder
	int sideBorder = size + (size + 1);
	setxy(x , y);
	for (int i = 0; i < line; i++) { //print top bottom
		cout << char(177);
	}
	for (int i = 0; i < sideBorder; i++) { // print left side boarder
		setxy(x , y+i);
		cout << char(177);
	}
	for (int i = 0; i < 6; i++) {
		setxy(x+line, y + i);
		cout << char(177);
	}
	int coloum = 1;
	for (int i = 0; i < size; i++) {
		int rows =6;
		for (int j = 0; j < size; j++) {
			if (table[i][j] == -1) {
				setxy(x + rows, y + coloum);
				cout << "x";
				rows += 6;
				setxy(x + rows, y + coloum);
				cout<< char(177);
				rows += 6;
			}
			else if (table[i][j] == -2) {
				setxy(x + rows, y + coloum);
				cout << "o";
				rows += 6;
				setxy(x + rows, y + coloum);
				cout << char(177);
				rows += 6;
			}
			else if (table[i][j] == -3) {
				setxy(x + rows, y + coloum);
				cout << "d";
				rows += 6;
				setxy(x + rows, y + coloum);
				cout << char(177);
				rows += 6;
			}
			else{
				setxy(x + rows, y + coloum);
				cout << table[i][j];
				rows += 6;
				setxy(x + rows, y + coloum);
				cout << char(177);
				rows += 6;
			}
			setxy(x, y + coloum+1);
			for (int i = 0; i < line + 1; i++) {
				cout << char(177);
			}
		}
		coloum += 2;
	}
}

void ticTac:: moves(int &num, char participant) { //Control moves
	int i = 0;
	int j = 0;
	bool WrongMove = true; //If true, participant played a wrong 
	for( i = 0; i < size; i++ ) {
		for( j = 0; j < size; j++ ) { //Mark square with X or O if WrongMove is not true
			if(table[i][j] == num) {
				if (participant == 'x') {
					table[i][j] = -1; //Assigns the space with the X or O, depending on the table.
				}
				else if(participant == 'o') {
					table[i][j] = -2;
				}
				else if(participant == 'd'){
					table[i][j] = -3;
				}
				WrongMove = false;
				j = size; // terminate inner loop;
				i = size; // terminate outer loop;
			}
		}
	}
	if(WrongMove && num != -1){ 
		cout << "\nNot Valid";
		cout << "\nparticipant :" << participant;
		cout << "\nEnter box # : ";
		cin >> num;
		moves( num, participant);
	}
}

bool ticTac:: CheckRows(char &wonParticipant){ // check only row wise
	int count = 0; // count number + character in each row
	int row;
	int coloum;
	bool isEqual = false; // isEqual true if any row consist of same character
	for (int i = 0; i < size; i++) {//control row
		for (int j = 0; j < size - 1; j++) { // increment j to check whole row by changing coloum wise
			if (table[i][j] == table[i][j + 1]) { // if two consective character same
				isEqual = true;
				row = i;
				coloum = j;
				count++; // count always less then size - 1 of board 
				if (count == size - 1) {
					i = size;
				}
			}
			else {
				isEqual = false;
				j = size - 1;
			}
		}
		count = 0;
	}
	if (isEqual) { // check if pattern found then number form pattern
		if (table[row][coloum] == -1) {
			wonParticipant = 'x';
		}
		else if (table[row][coloum]  == -2) {
			wonParticipant = 'o';
		}
		else if (table[row][coloum] == -3) {
			wonParticipant = 'd';
		}
	}
	return isEqual;
}
bool ticTac:: CheckColoum(char& wonParticipant){ // check only coloum
	int count = 0; // count number + character in each row
	bool isEqual = false; // isEqual true if any coloum consist of same character
	int row;
	int coloum;
	for(int j = 0; j < size ; j++) {//Increment i to check coloum
		for(int i = 0; i < size - 1; i++) {
			if(table[i][j] == table[i + 1][j]) {
				isEqual = true;
				row = i;
				coloum = j;
				count++; // count always less then size - 1 of board 
				if(count == size-1){ 
					j = size; // use to terminate inner loop
				}
			}
			else{
				isEqual  = false;
				i = size;	// terminate outer loop
			}
		}
		count = 0;
	}
	if (isEqual) {// check if pattern found then number form pattern
		if (table[row][coloum] == -1) {
			wonParticipant = 'x';
		}
		else if (table[row][coloum] == -2) {
			wonParticipant = 'o';
		}
		else if (table[row][coloum] == -3) {
			wonParticipant = 'd';
		}
	}
	return isEqual ;	
}
bool ticTac:: ChechDigonallyRight(char& wonParticipant){
	
	/*Checking the Diagonals right downward
	 for example
    	o x o
    	x o x
    	x x o
    */
	int count = 0; // count number + character in each row
	bool isEqual = false; // isEqual true if digonally consist of same character
	int row;
	int coloum;
	for(int i = 0; i < size-1; i++) {	// control rows
		for(int j = 0; j < size-1; j++){ // control coloum
			if(i == j){
				if(table[i][j] == table[i + 1][j + 1]) {
					isEqual = true;
					row = i;
					coloum = j;
					count++; // count always less then size - 1 of board 
					if(count == size-1){ 
						i = size; // terminate oyter loop
					}
				}
				else{
					isEqual = false;
					i = size; // terminate outer loop
				}
			}
		}
	}
	if (isEqual) {// check if pattern found then number form pattern
		if (table[row][coloum] == -1) {
			wonParticipant = 'x';
		}
		else if (table[row][coloum] == -2) {
			wonParticipant = 'o';
		}
		else if (table[row][coloum] == -3) {
			wonParticipant = 'd';
		}
	}
	
	return isEqual;
}

bool ticTac:: CheckDigonallyLeft(char& wonParticipant){
    /*Checking the Diagonals left downward
	 for example
    	x x o
    	x o x
    	o x x
    */
	bool isEqual = false; // isEqual true if digonally consist of same character
	int row;
	int coloum;
    for(int i = 0; i < size-1; i++) { // control rows
    	for(int j = size - 1; j >= 0 ; j--) { // control coloum
			if(i+j == size-1) {
				if(table[i][j] == table[i + 1][j - 1]) {
					isEqual = true;
					row = i;
					coloum = j;
					j = - 1; // terminater inner loop
				}
				else {
					isEqual = false;
					i = size; // terminate outer loop
					j = -1;	// terminate inner loop
				}
			}
		} 
	}
	if (isEqual) {// check if pattern found then number form pattern
		if (table[row][coloum] == -1) {
			wonParticipant = 'x';
		}
		else if (table[row][coloum] == -2) {
			wonParticipant = 'o';
		}
		else if (table[row][coloum] == -3) {
			wonParticipant = 'd';
		}
	}
	return isEqual;	
}

//Check the board for a winner after the move
char ticTac:: whoWon(char participant, bool &loseGame) { // check which player won
	char wonParticipant = 'a';
	loseGame = CheckRows(wonParticipant);
	if(!loseGame){
		loseGame = CheckColoum(wonParticipant);
	}
	if(!loseGame){
		loseGame = ChechDigonallyRight(wonParticipant);
	}
	if(!loseGame){
		loseGame = CheckDigonallyLeft(wonParticipant);
	}
	if(loseGame) {
		return wonParticipant;
	}
	return '0';
} 

bool ticTac:: isDraw(bool &loseGame) {//Check the board to see if the match has come to a draw
	int counter = 0; // count all x, o and d in 2d array	
	for(int i = 0; i < size; i++ ) { // control row
		for(int j = 0; j < size; j++ ) { // control coloum
			if((char)table[i][j] == -1 || (char)table[i][j] ==  -2|| (char)table[i][j]== -3) { //Check is full or not
				counter++;
			}
		}
	}
	if( counter == size*size && !loseGame ) {
		loseGame = true; // tells game draw or not
	}
	return loseGame;
}

ticTac :: ~ticTac() { // destructor
	for(int i = 0; i < size; i++){
		if(table[i] != NULL) {
			delete []table[i];
		}
	}
	delete []table;
	table = NULL;
}
