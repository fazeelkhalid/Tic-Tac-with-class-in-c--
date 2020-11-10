//#include<iostream>
//#include<conio.h> // getch
//#include<fstream> // input in file and output from file;
//#include"TicTac.h" // class header file
//#include"mygraphic.h" // hide cursore
//using namespace std;
//
//void ArrangBoard(int size, char participant) { // form board by arranging input from user or by file and display it
//	bool operation;
//	char decideWinner;
//	system("CLS");
//	for (int i = 0; i < 30; i++) cout << char(177); // draw top border
//	cout << "\n"<<char(254)<<" 1 : Load preveious Game";
//	cout << "\n"<<char(254)<<" Else 0\n";
//	cin >> operation;
//	if (operation) { // use to get size from file
//		ifstream fin;
//		fin.open("input.txt");
//		fin >> size;
//		fin.close();
//	}
//	if (!operation) {
//		cout <<char(254)<<"  Enter size of board : ";
//		cin >> size;
//		while (size < 3) { // execute untill user enter size greter then or equal to 3
//			if (size < 3) {
//				cout << "Enter size greater then or equal to 3 \n";
//			}
//			cout << "Enter size of board :";
//			cin >> size;
//		}
//	}
//	for (int i = 0; i < 30; i++) cout << char(177); // draw bottom boarder
//	getch();
//
//	int tableBox; // get tableBox from user
//	bool isGamequit = false; // if true then program will terminate
//	bool loseGame = false;  // tell which player won
//	ticTac game(size); // creat an object
//
//	if (operation) { // load game from file
//		game.putLoad(participant);
//	}
//	game.help(); // display necessary instructions
//	getch();
//	participant = game.tosse();//choose which player will start game
//	while (!isGamequit) { // loop will terminate when isGameQuit = true
//		if (participant == 'x') { // it will alternate participent
//			participant = 'o';
//		}
//		else {
//			participant = 'x';
//		}
//		system("CLS");
//		game.print(0,0); // print board wher x = 0 and y = 0
//		cout << "\nparticipant " << participant << " : ";
//		cin >> tableBox;
//		
//		if (tableBox == -1) {
//			cout << "Game quit\n";
//			game.getSave(participant); // game will save when user quite the game
//			isGamequit = true;
//		}
//		game.moves(tableBox, participant); // check move is it possible or not
//		decideWinner = game.whoWon(participant, loseGame); // check which player won or loose
//		game.isDraw(loseGame); // check is game draw or not after each move
//		if (decideWinner == 'x') {
//			cout << "won Participant : x";
//			cout << "\nPress any key";
//			getch();
//			isGamequit = true;
//		}
//		else if (decideWinner == 'o') {
//			cout << "won Participant : o";
//			cout << "\nPress any key";
//			getch();
//			isGamequit = true;
//		}
//		else if (loseGame) {
//			cout << "GAme Draw!";
//			cout << "\nPress any key";
//			getch();
//			isGamequit = true;
//		}
//	}
//}
//int main() {
//	showConsoleCursor(false); // it will not display cursor on screen
//	{	ticTac game(3);
//		game.downloadScreen();
//	}
//	char participant = 'o'; 
//	int size = 0; // store board size
//	ArrangBoard(size, participant);
//	system("pause");
//	return 0;
//	system("PAUSE");
//	return 0;
//}
