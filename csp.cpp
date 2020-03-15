#include <stdio.h> // for NULL
#include <stdlib.h> // for srand and rand
#include <ctime> // for time
#include <vector>
#include "csp.h"
#include <iostream>

CSP::CSP() {
	srand(time(NULL));

	int row = (rand() % 25);
	placeQueen(0, row);

	for (int i = 1; i < 25; ++i) {
		int row = getMinConflict(i);
		placeQueen(i, row);
	}

	/*
	   for (int i = 0; i < 25; ++i) {
	   std::cout << board[i] << " ";
	   }
	   std::cout << "\n";
	   */

	/*
	   for (int i = 0; i < 25; ++i) {
	   for (int j = 0; j < 25; ++j) {
	   if( board[i] == j) {
	   std::cout << "X" ;
	   } else {
	   std::cout << '_';
	   }
	   }
	   std::cout << '\n';
	   }
	   */
}

int CSP::getMinConflict(const int column) {
	int min = conflicts[column][0].size();
	//	std::cout << "Coloum " << column << " min 0 " << min << std::endl;
	std::vector<int> choices;

	for (int i = 1; i < 25; ++i) {
		if (min > conflicts[column][i].size()) {
			min = conflicts[column][i].size();
		}
	}

	for (int i = 0; i < 25; ++i) {
		if (conflicts[column][ i].size() == min) {
			choices.push_back(i);
		}
	}

	int choice = choices.at(rand() % choices.size());
	//std::cout << "Coloum " << column << " min index  " << choice << std::endl;
	return choice;
}


void CSP::placeQueen(const int column, const int row) {
	board[column] = row;

	// track horizontal
	for (int i=0; i < column; ++i) {
		conflicts[i][row].insert(column);
	}
	for (int i=column+1; i < 25; ++i) {
		conflicts[i][row].insert(column);
	}


	// track diagonal
	int x = column - 1;
	int y = row - 1;
	while(x >= 0 && y >= 0) {
		conflicts[x][y].insert(column);
		--x;
		--y;
	}

	x = column + 1;
	y = row + 1;
	while(x < 25 && y < 25) {
		conflicts[x][y].insert(column);
		++x;
		++y;
	}

	x = column - 1;
	y = row + 1;
	while(x >= 0 && y < 25) {
		conflicts[x][y].insert(column);
		--x;
		++y;
	}

	x = column + 1;
	y = row - 1;
	while(x < 25 && y >= 0) {
		conflicts[x][y].insert(column);
		++x;
		--y;
	}

}

void CSP::removeQueen(const int column) {
	// track horizontal
	const int row = board[column];

	for (int i=0; i < column; ++i) {
		conflicts[i][row].erase(column);
	}
	for (int i=column+1; i < 25; ++i) {
		conflicts[i][row].erase(column);
	}


	// track diagonal
	int x = column - 1;
	int y = row - 1;
	while(x >= 0 && y >= 0) {
		conflicts[x][y].erase(column);
		--x;
		--y;
	}

	x = column + 1;
	y = row + 1;
	while(x < 25 && y < 25) {
		conflicts[x][y].erase(column);
		++x;
		++y;
	}

	x = column - 1;
	y = row + 1;
	while(x >= 0 && y < 25) {
		conflicts[x][y].erase(column);
		--x;
		++y;
	}

	x = column + 1;
	y = row - 1;
	while(x < 25 && y >= 0) {
		conflicts[x][y].erase(column);
		++x;
		--y;
	}


}

bool CSP::isSolution() {
	for (int i =0; i < 25; ++i) {
		if (conflicts[i][board[i]].size() > 0) {
			return false;
		}

	}
	return true;
}

void CSP::minimize(const int column) {
	const int row = getMinConflict(column);
	removeQueen(column);
	placeQueen(column, row);
}
