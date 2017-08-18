//
//  main.cpp
//  ABoardGame
//
//  Created by Anton Velikodnyy on 8/7/17.
//  Copyright © 2017 Anton Velikodnyy. All rights reserved.
//
/** Problem Statement
 *	Your friends Alice and Bob are playing a board game. They have asked you to help them to determine the winner. The game is played on a square board with 2N rows and 2N columns. The exact rules of the game itself are not important for this problem. Once the game is over, each cell of the board is either empty or contains a single piece that belongs to either Alice or Bob. You are given board, where the j-th character in i-th element (0-based indices) describes the contents of the cell in row i, column j: '.' represents an empty cell, 'A' a cell with Alice's piece and 'B' a cell with Bob's piece.
 *
 *	The entire board is divided into N regions. Region 1 occupies the 4 central cells of the board. Each next region contains all cells that are horizontally, vertically or diagonally adjacent to cells of the immediately previous region and do not belong to any of the previous regions. For example, when N = 4, here is how the regions look:
 *	44444444
 *	43333334
 *	43222234
 *	43211234
 *	43211234
 *	43222234
 *	43333334
 *	44444444
 *	The winner is determined as follows. Consider the lowest numbered region that contains a different number of Alice's and Bob's pieces. The player who has more pieces in this region is the winner. If all regions contain the same number of Alice's and Bob's pieces, the game ends in a draw.
 *
 *	Return "Alice" if Alice wins the given game, "Bob" if Bob wins and "Draw" if the game ends in a draw. Note that return values are case-sensitive.
 *	Definition
 *	Class: ABoardGame
 *	Method: whoWins
 *	Parameters: vector <string>
 *	Returns: string
 *	Method signature: string whoWins(vector <string> board)
 *	(be sure your method is public)
 *	Limits
 *	Time limit (s): 2.000
 *	Memory limit (MB): 256
 *	Constraints
 *	- board will contain between 2 and 50 elements, inclusive.
 *	- The number of elements in board will be even.
 *	- Each element of board will contain the same number of characters as the number of elements in board.
 *	- Each character in board will be 'A', 'B' or '.'.
 *	Examples
 *	0)
 *	{".....A", "......", "..A...", "...B..", "......", "......"}
 *	Returns: "Alice"
 *	Both Alice and Bob have 1 piece in region 1, so they are tied there. In region 2, they have no pieces at all, so a tie again. Finally, in region 3 Alice has 1 piece, while Bob has none. So Alice is the winner of this game.
 *	1)
 *	{"AAAA", "A.BA", "A..A", "AAAA"}
 *	Returns: "Bob"
 *	Even though Alice has 12 pieces and Bob just one, this one piece is enough for him to win.
 *	2)
 *	{"..", ".."}
 *	Returns: "Draw"
 *	The board can be entirely empty.
 *	3)
 *	{"BBB..BAB...B.B", ".AAAAAAAAAAAA.", "AA.AA.AB..A.AB", "..........B.AB", ".A..BBAB.A.BAB", ".AB.B.......A.", ".A..A.AB.A..AB", ".ABAA.BA...BA.", "BAAAB.....ABA.", ".A....B..A..B.", "B...B....B..A.", "BA.B..A.ABA.A.", "BAAAA.AAAAA.A.", "B.B.B.BB.B...."}
 *	Returns: "Alice"
 *	4)
 *	{"..A..AAA..AA", "ABABB..AAAAA", "ABBBBBBBBBA.", "AABBBABABBAA", "...BABABABBA", "B.BA..A.BBA.", "AA.A..B.AB.B", "..BA.B.AABAA", "..ABABBBABA.", ".ABB.BBBBBAA", "ABAAA.AA.A.A", "A..AAA.AAA.A"}
 *	Returns: "Bob"
 *	5)
 *	{"B..ABAABBB", "B.........", "A..A.AA..B", "A.BBBAA..A", "B.AAAAB...", "A..BBBBB.A", "B..ABAABBA", "A......B.B", "B......A.A", "BA.AABBB.A"}
 *	Returns: "Draw"
 *	This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.
 */

#include <iostream>
#include <vector>
#include <string>
#include <time.h>

class ABoardGame
{
public:
	std::string whoWins(const std::vector <std::string>& board);
private:
	int Bob, Alice;
	void itter_row (const std::vector<std::string>& board, int row, int col1, int col2);
	void itter_col (const std::vector<std::string>& board, int row1, int row2, int col);
	int judge ();
};


std::string ABoardGame::whoWins(const std::vector<std::string>& board)
{
	int row1, row2;
	int col1, col2;
	for (int i = 0; i < board.size()/2; i++) {
		Bob = 0, Alice = 0;
		row1 = board.size()/2 - i - 1;
		row2 = board.size()/2 + i;
		col1 = board[0].size()/2 - i - 1;
		col2 = board[0].size()/2 + i;
		itter_col(board, row1, row2, col1);
		itter_row(board, row1, col1+1, col2-1);
		itter_col(board, row1, row2, col2);
		itter_row(board, row2, col1+1, col2-1);
		if (judge() == 1)
			return "Alice";
		else if (judge() == -1)
			return "Bob";
	}
	return "Draw";
}

void ABoardGame::itter_row(const std::vector<std::string>& board, int row, int col1, int col2)
{
	for (;col1<=col2;++col1)  {
		if ( board[row][col1] == 'A')
			++Alice;
		else if ( board[row][col1] == 'B')
			++Bob;
	}
}

void ABoardGame::itter_col(const std::vector<std::string>& board, int row1, int row2, int col1)
{
	for (;row1<=row2;++row1)  {
		if ( board[row1][col1] == 'A')
			++Alice;
		else if ( board[row1][col1] == 'B')
			++Bob;
	}
}

int ABoardGame::judge()
{
	if (Alice > Bob)
		return 1;
	else if (Alice < Bob)
		return -1;
	else return 0;
}

int main(int argc, const char * argv[]) {
	// insert code here...
	std::cout << "Hello, World!\n";
	std::vector<std::string> board;
	board.push_back("BBB..BAB...B.B");
	board.push_back(".AAAAAAAAAAAA.");
	board.push_back("AA.AA.AB..A.AB");
	board.push_back("..........B.AB");
	board.push_back(".A..BBAB.A.BAB");
	board.push_back(".AB.B.......A.");
	board.push_back(".A..A.AB.A..AB");
	board.push_back(".ABAA.BA...BA.");
	board.push_back("BAAAB.....ABA.");
	board.push_back(".A....B..A..B.");
	board.push_back("B...B....B..A.");
	board.push_back("BA.B..A.ABA.A.");
	board.push_back("BAAAA.AAAAA.A.");
	board.push_back("B.B.B.BB.B....");
	auto manager = std::make_shared<ABoardGame>();
	std::string result = "";
	int n_test = 1000;
	int time[n_test];
	int total = 0;
	clock_t start, end;
	for ( int t = 0; t < n_test; ++t)  {
  	start = clock();
  	manager->whoWins(board);
  	end = clock();
		time [t] =end-start;
		total += time[t];
  	result += std::to_string(time[t]) + "\n";
	}
	total /= n_test;
	
	std::cout<<result<<std::endl<<total<<std::endl;
    return 0;
}
