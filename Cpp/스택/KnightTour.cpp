#include "KnightTour.h"
#include "MyStackTemplate.h"
class Position
{
public:
	Position(int x = 0, int y = 0) { row = x; col = y; }
	int getRow() const { return row; }
	int getCol() const { return col; }
	int getDir() const { return dir; }
	void setPos(int r, int c) { row = r; col = c; }
	void setPos(Position &p) { row = p.row; col = p.col; }
	void setDir(int d) { dir = d; }
private:
	int row;
	int col;
	int dir;
};
const static int direction[8][2] = { { 1, -2 },{ 2, -1 },{ 2, 1 },{ 1, 2 },{ -1, 2 },{ -2, 1 },{ -2, -1 },{ -1, -2 } };
KnightTour::KnightTour()
{
	sizeRow = sizeCol = 8; // default size of Chessboard
}
KnightTour::KnightTour(int sRow, int sCol)
{
	if (sRow >= 2 && sRow <= MAX_SIZE)
		sizeRow = sRow;
	else
		sizeRow = 8; // set to default size
	if (sCol >= 2 && sCol <= MAX_SIZE)
		sizeCol = sCol;
	else
		sizeCol = 8; // set to default size
}
void KnightTour::printBoard()
{
	for (int r = 0; r < sizeRow; r++)
	{
		for (int c = 0; c < sizeCol; c++)
			cout << board[r][c] << " ";
		cout << endl;
	} // for r
}
bool KnightTour::buildKnightTour(int startRow, int startCol)
{
	for (int r = 0; r<sizeRow; r++)
		for (int c = 0; c<sizeCol; c++)
			board[r][c] = 0;
	if (startRow <= 0 || startRow > sizeRow)
		startRow = 0;
	if (startCol <= 0 || startCol > sizeCol)
		startCol = 0;
	board[startRow - 1][startCol - 1] = 1;
	return nonrecurKnightTour(startRow - 1, startCol - 1, 1);
}
bool KnightTour::nonrecurKnightTour(int row, int col, int move)
{
	MyStack<Position> s;
	Position pos, nextPos;
	int dir = 0;
	pos.setPos(row, col);
	pos.setDir(0);
	s.push(pos);
	while (move < sizeRow*sizeCol)
	{
		s.peek(pos);
		row = pos.getRow();
		col = pos.getCol();
		dir = pos.getDir();

		row += direction[dir][0];
		col += direction[dir][1];
		nextPos.setPos(row, col);
		if (isValidMove(row, col)) {
			nextPos.setDir(0);
			s.push(nextPos);
			board[row][col] = ++move;
			continue;
		}
		else {
			while (1) {
				s.peek(pos);
				if (pos.getDir() == 7) {
					board[pos.getRow()][pos.getCol()] = 0;
					--move;
					s.pop(pos);
					if (s.isEmpty()) {
						return false;
					}
				}
				else {
					break;
				}
			}
			s.peek(pos);
			dir = pos.getDir();
			pos.setDir(dir + 1);
			s.pop(nextPos);
			s.push(pos);
		}
	}
	return true;
}
bool KnightTour::isValidMove(int row, int col)
{
	if (row >= sizeRow || row<0)
		return false;
	if (col >= sizeCol || col<0)
		return false;
	if (board[row][col] != 0)
		return false;
	else
		return true;
}