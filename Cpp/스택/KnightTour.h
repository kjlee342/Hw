#ifndef _KNIGHT_TOUR_H_
#define _KNIGHT_TOUR_H_
#include <iostream>
using namespace std;
const int MAX_SIZE = 9;
class KnightTour
{
public:
	KnightTour();
	KnightTour(int sizeRow, int sizeCol);
	bool buildKnightTour(int startRow, int startCol);
	void printBoard();
private:
	typedef int boardType[MAX_SIZE][MAX_SIZE];
	bool nonrecurKnightTour(int startRow, int startCol, int move);
	bool isValidMove(int row, int col);
	int sizeRow, sizeCol;
	boardType board;
};
#endif // _KNIGHT_TOUR_H_