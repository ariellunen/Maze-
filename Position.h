#pragma once

#include <iostream>

class Position {

private:

	int _row;

	int _column;

public:

	Position(int row, int column) : _row(row), _column(column) { }

	Position() {
		_row = _column = -1;
	}

	int row() const {
		return this->_row;
	}

	void setrow(int row) {
		_row = row;
	}


	void setcol(int col) {
		_column = col;
	}

	int column() const {
		return this->_column;
	}

	bool operator==(const Position& pos) {
		return this->_row == pos.row() && this->_column == pos.column();
	}

	bool operator!=(const Position& pos) {
		return !(*this == pos);
	}
};


std::ostream& operator<<(std::ostream& out, const Position& pos) {
	out << '(' << pos.row() << ", " << pos.column() << ')';
	return out;
}
