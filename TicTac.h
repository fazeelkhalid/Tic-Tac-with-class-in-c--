#ifndef TicTac_H
#define TicTac_H

class ticTac{
	private:
		int **table; // 2d pointer that form 2d array
		int size;
		int delaay(int number_of_seconds);
		bool CheckRows(char & wonParticipant);
		bool CheckColoum(char& wonParticipant);
		bool ChechDigonallyRight(char& wonParticipant);
		bool CheckDigonallyLeft(char& wonParticipant);

	public:
		ticTac();
		ticTac(int size);
		ticTac(const ticTac &game);
		void downloadScreen();
		void putValues();
		void print(int x, int y);
		void getSave(int participant);
		void setxy(int x, int y);
		void putLoad(char & participant);
		void moves(int &num, char participant);
		void help();
		int getTable(int  arr[3][3]);
		char whoWon(char Player, bool &GameOver);
		char tosse();
		bool isDraw(bool &GameOver);
		~ticTac();
};
#endif
