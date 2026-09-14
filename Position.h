#pragma once
#include <iostream>

using namespace std;

struct Position {
	char _A;
	int _1;

	void readPosition(istream & in) {
		int row;
		char col;
		in >> col >> row;
		if (!(col >= 'A' && col <= 'H')) {
			cout << "Wrong column, try again" << endl;
			this->readPosition(in);
		}
		else if (!(row >= 1 && row <= 8)) {
			cout << "Wrong row, try again" << endl;
			this->readPosition(in);
		}
		_A = col;
		_1 = row;
	}
	void readRow(istream & in) {
		int row;
		in >> row;
		 if (!(row >= 1 && row <= 8)) {
			cout << "Wrong row, try again" << endl;
			this->readPosition(in);
		}
		_1 = row;
	}
	void readColumn(istream & in) {
		char col;
		in >> col;
		if (!(col >= 'A' && col <= 'H')) {
			cout << "Wrong column, try again" << endl;
			this->readPosition(in);
		}
		_A = col;
	}
	bool operator== (const Position& right)const {
		return (this->_A == right._A && this->_1 == right._1);
	}
	void printPosition(ostream & out)const {
		out << _A << _1 << endl;
	}
};

struct boolPosition {
	Position pose;
	bool inDanger;
};