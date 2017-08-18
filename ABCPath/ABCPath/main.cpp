//
//  main.cpp
//  ABCPath
//
//  Created by Anton Velikodnyy on 8/13/17.
//  Copyright © 2017 Anton Velikodnyy. All rights reserved.
//

/**	Problem Statement
 *	You will be given a 2-dimensional grid of letters. Write a method to find the length of the longest path of consecutive letters, starting at 'A'. Paths can step from one letter in the grid to any adjacent letter (horizontally, vertically, or diagonally).
 *
 *	For example, in the following grid, there are several paths from 'A' to 'D', but none from 'A' to 'E':
 *
 *	{ "ABE",
 *	"CFG",
 *	"BDH",
 *	"ABC" }
 *	One such path is:
 *
 *	A B .
 *	C . .
 *	. D .
 *	. . .
 *	(spaces are for clarity only)
 *	so, for this grid, your method should return 4.
 *
 *	Definition
 *	Class: ABCPath
 *	Method: length
 *	Parameters: vector <string>
 *	Returns: int
 *	Method signature: int length(vector <string> grid)
 *	(be sure your method is public)
 *	Limits
 *	Time limit (s): 840.000
 *	Memory limit (MB): 64
 *	Notes
 *	- The longest path may start at any 'A' character in the input.
 *	Constraints
 *	- grid will contain between 1 and 50 elements, inclusive.
 *	- Each element of grid will be between 1 and 50 characters long, inclusive.
 *	- Each element of grid will have the same length.
 *	- grid will contain only uppercase letters ('A'-'Z').
 *	Examples
 *	0)
 *	{ "ABE", "CFG", "BDH", "ABC" }
 *	Returns: 4
 *	This is the example from the problem statement.
 *	1)
 *	{ "A" }
 *	Returns: 1
 *	2)
 *	{ "BCDEFGHIJKLMNOPQRSTUVWXYZ" }
 *	Returns: 0
 *	Paths must start with an 'A'.
 *	3)
 *	{ "C", "D", "B", "A" }
 *	Returns: 2
 *	4)
 *	{ "KCBVNRXSPVEGUEUFCODMOAXZYWEEWNYAAXRBKGACSLKYRVRKIO", "DIMCZDMFLAKUUEPMPGRKXSUUDFYETKYQGQHNFFEXFPXNYEFYEX", "DMFRPZCBOWGGHYAPRMXKZPYCSLMWVGMINAVRYUHJKBBRONQEXX", "ORGCBHXWMTIKYNLFHYBVHLZFYRPOLLAMBOPMNODWZUBLSQSDZQ", "QQXUAIPSCEXZTTINEOFTJDAOBVLXZJLYOQREADUWWSRSSJXDBV", "PEDHBZOVMFQQDUCOWVXZELSEBAMBRIKBTJSVMLCAABHAQGBWRP", "FUSMGCSCDLYQNIXTSTPJGZKDIAZGHXIOVGAZHYTMIWAIKPMHTJ", "QMUEDLXSREWNSMEWWRAUBFANSTOOJGFECBIROYCQTVEYGWPMTU", "FFATSKGRQJRIQXGAPLTSXELIHXOPUXIDWZHWNYUMXQEOJIAJDH", "LPUTCFHYQIWIYCVOEYHGQGAYRBTRZINKBOJULGYCULRMEOAOFP", "YOBMTVIKVJOSGRLKTBHEJPKVYNLJQEWNWARPRMZLDPTAVFIDTE", "OOBFZFOXIOZFWNIMLKOTFHGKQAXFCRZHPMPKGZIDFNBGMEAXIJ", "VQQFYCNJDQGJPYBVGESDIAJOBOLFPAOVXKPOVODGPFIYGEWITS", "AGVBSRLBUYOULWGFOFFYAAONJTLUWRGTYWDIXDXTMDTUYESDPK", "AAJOYGCBYTMXQSYSPTBWCSVUMNPRGPOEAVVBGMNHBXCVIQQINJ", "SPEDOAHYIDYUJXGLWGVEBGQSNKCURWYDPNXBZCDKVNRVEMRRXC", "DVESXKXPJBPSJFSZTGTWGAGCXINUXTICUCWLIBCVYDYUPBUKTS", "LPOWAPFNDRJLBUZTHYVFHVUIPOMMPUZFYTVUVDQREFKVWBPQFS", "QEASCLDOHJFTWMUODRKVCOTMUJUNNUYXZEPRHYOPUIKNGXYGBF", "XQUPBSNYOXBPTLOYUJIHFUICVQNAWFMZAQZLTXKBPIAKXGBHXX" }
 *	Returns: 19
 *	5)
 *	{ "EDCCBA", "EDCCBA" }
 *	Returns: 3
 *	6)
 *	{ "AMNOPA", "ALEFQR", "KDABGS", "AJCHUT", "AAIWVA", "AZYXAA" }
 *	Returns: 26
 *	This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.
 */

#include <iostream>
#include <ctime>
#include <chrono>


#include <vector>
#include <string>

class ABCPath
{
public:
	ABCPath(){};
	int length(std::vector <std::string> grid);
private:
	int path_len;
	void path (const std::vector <std::string>& grid, long x, long y, char l, int length);
	
};


int ABCPath::length(std::vector <std::string> grid)
{
	path_len = 0;
	
	for (int y = 0; y < grid.size(); ++y) {
		auto x = grid[y].find('A');
		while (x != std::string::npos) {
			path ( grid, x, y, 'B', 1);//found A
			x = grid[y].find('A', x+1);
		}
	}
	
	
	
	return path_len;
};

void ABCPath::path (const std::vector <std::string>& grid, long x, long y, char l, int length)
{
	auto xmax = x + 2;
	auto ymax = y + 2;
	auto xmin = x - 1;
	auto ymin = y - 1;
	
	if ( x + 2 > grid[0].size())
		xmax = grid[0].size();
	if ( y + 2 > grid.size())
		ymax = grid.size();
	if (x - 1 < 0) {
		xmin = 0;
	}
	if (y - 1 < 0) {
		ymin = 0;
	}
	for (auto i = xmin; i < xmax; ++i)  {
		for (auto j = ymin; j < ymax; ++j)  {
			if (grid[j][i] == l)  {
				path(grid, i, j, l+1, length + 1);
			}
			else  {
				if (length >path_len)
					path_len = length;
			}
			
		}
	}
}

int main(int argc, const char * argv[]) {
	// insert code here...
	std::cout << "Hello, World!\n";
	auto test = new ABCPath();
	typedef std::chrono::steady_clock Time;
	typedef std::chrono::microseconds ms;
	typedef std::chrono::duration<float> fsec;
	const int COUNT = 1000;
	auto t0 = Time::now();
	auto t1 = t0;
	fsec fs;
	ms d;
	int result = 0;
	for (int i = 0; i < COUNT; ++i) {
		t0 = Time::now();
		std::cout<<test->length({ "AMNOPA", "ALEFQR", "KDABGS", "AJCHUT", "AAIWVA", "AZYXAA" })<<"\n";
		t1 = Time::now();
		fs = t1 - t0;
		d  = std::chrono::duration_cast<ms>(fs);
		result += d.count();
		
		
	}
	result/= COUNT;
	std::cout << "average = "<< result << "us\n";
	return 0;
}
