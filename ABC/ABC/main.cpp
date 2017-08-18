//
//  main.cpp
//  ABC
//
//  Created by Anton Velikodnyy on 8/12/17.
//  Copyright © 2017 Anton Velikodnyy. All rights reserved.
//

/** Problem Statement
 *	You are given two s: N and K. Lun the dog is interested in strings that satisfy the following conditions:
 *	The string has exactly N characters, each of which is either 'A', 'B' or 'C'.
 *	The string s has exactly K pairs (i, j) (0 <= i < j <= N-1) such that s[i] < s[j].
 *	If there exists a string that satisfies the conditions, find and return any such string. Otherwise, return an empty string.
 *
 *	Definition
 *	Class: ABC
 *	Method: createString
 *	Parameters: int, int
 *	Returns: string
 *	Method signature: string createString(int N, int K)
 *	(be sure your method is public)
 *	Limits
 *	Time limit (s): 2.000
 *	Memory limit (MB): 256
 *	Constraints
 *	- N will be between 3 and 30, inclusive.
 *	- K will be between 0 and N(N-1)/2, inclusive.
 *	Examples
 *	0)
 *	3
 *	3
 *	Returns: "ABC"
 *	This string has exactly three pairs (i, j) mentioned in the statement: (0, 1), (0, 2) and (1, 2).
 *	1)
 *	3
 *	0
 *	Returns: "CBA"
 *	Please note that there are valid test cases with K = 0.
 *	2)
 *	5
 *	10
 *	Returns: ""
 *	Five characters is too short for this value of K.
 *	3)
 *	15
 *	36
 *	Returns: "CABBACCBAABCBBB"
 *	Please note that this is an example of a solution; other valid solutions will also be accepted.
 *	This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.
 */

#include <iostream>
#include <string>

class ABC
{
public:
	ABC() {};
	std::string createString(int N, int K);
private:
	int nn, kk;
	std::string answer;
	bool generateString(std::string, int a, int b, int c, int pairs);
	
};

std::string ABC::createString(int N, int K)
{
	nn = N;
	kk = K;
	answer = "";
	if (generateString(answer, 0, 0, 0, 0))
	{
		for (int leftover = nn - (int)answer.size(); leftover > 0; --leftover)
			answer.append("A");
		return answer;
	}
	else return "";
}

bool ABC::generateString(std::string temp, int a, int b, int c, int pairs)
{
	std::cout<<pairs<<" pairs >> "<< kk<< " kk\n";
	std::cout<<temp<<" = temp\n";
	std::cout<<temp.size()<<" size >> "<< nn<< " nn\n";
	if (pairs > kk || temp.size() > nn)
		return false;
	else if (pairs == kk ) {
		answer = temp;
		return true;
	}
	else {
		if (generateString(temp + "A", a+1, b, c, pairs))
			return true;
		else if (generateString( temp + "B", a, b+1, c, pairs + a))
			return true;
		else if	(generateString(temp + "C", a, b, c+1, pairs + a + b))
			return true;
		else return false;
	}
}


int main(int argc, const char * argv[]) {
	// insert code here...
	std::cout << "Hello, World!\n";
	auto result = new ABC();
	std::cout<<result->createString(3, 0);
	return 0;
}
