#ifndef CSP_H
#define CSP_H

#include <unordered_map>
#include <unordered_set>

class CSP {
	private:
		int board[25]; // where index is column and value is row
		std::unordered_map<int, std::unordered_set<int> > conflicts [25]; // map to other queens currently conflicted

	void removeQueen(const int column);

	public:
		CSP();

		// returns index to row from a given column
		// ties are broken at random
		int getMinConflict(const int column);

		void placeQueen(const int column, const int row);

		bool isSolution();

		void minimize(const int column);
};

#endif
