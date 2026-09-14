#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "Figure.h"
#include "Chessboard.h"
#include "Queen.h"
#include "King.h"
#include "Bishop.h"
#include "Castle.h"
#include "Pawn.h" 
#include "RoleFactory.h"

int main(int argc, char * argv[]) {

	Chessboard cb;
	do {
		cout << endl;
		cout << "_______Main menu_______" << endl;
		cout << endl;
		cout << "Enter 1 to read chessboard from file" << endl;
		cout << "Enter 2 to check Your Chessboard" << endl;
		cout << "Enter 3 to check situations of white king(s)" << endl;
		cout << "Enter 4 to print Your Chessboard to the file" << endl;
		cout << "Enter 0 to exit" << endl;
		cout << endl;
		int commandLev1;
		cin >> commandLev1;
		switch (commandLev1) {
		case 0: return 0; 
		case 1:
			if (argc > 1) {
				ifstream fin(argv[1]);
				fin >> cb;
				fin.close();
			} 
			break;
		case 2:
			cout << "Your Chessboard: " << endl;
			cout << cb << endl;
			cout << endl;
			cb.ChangeChessboard();
			break;
		case 3: 
			cb.CheckMatePat(); 
			break;
		case 4:
			if (argc > 2) {
				ofstream fout(argv[2]);
				fout << cb << endl;
				fout.close();
			} break;
		}
	} while (1);
}