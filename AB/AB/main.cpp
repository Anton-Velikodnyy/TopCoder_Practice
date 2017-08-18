/** Problem Statement
 *	You are given two s: N and K. Lun the dog is interested in strings that satisfy the following conditions:
 *
 *	The string has exactly N characters, each of which is either 'A' or 'B'.
 *	The string s has exactly K pairs (i, j) (0 <= i < j <= N-1) such that s[i] = 'A' and s[j] = 'B'.
 *	If there exists a string that satisfies the conditions, find and return any such string. Otherwise, return an empty string.
 *
 *	Definition
 *	Class: AB
 *	Method: createString
 *	Parameters: int, int
 *	Returns: string
 *	Method signature: string createString(int N, int K)
 *	(be sure your method is public)
 *	Limits
 *	Time limit (s): 2.000
 *	Memory limit (MB): 256
 *	Constraints
 *	- N will be between 2 and 50, inclusive.
 *	- K will be between 0 and N(N-1)/2, inclusive.
 *	Examples
 *	0)
 *	3
 *	2
 *	Returns: "ABB"
 *	This string has exactly two pairs (i, j) mentioned in the statement: (0, 1) and (0, 2).
 *	1)
 *	2
 *	0
 *	Returns: "BA"
 *	Please note that there are valid test cases with K = 0.
 *	2)
 *	5
 *	8
 *	Returns: ""
 *	Five characters is too short for this value of K.
 *	3)
 *	10
 *	12
 *	Returns: "BAABBABAAB"
 *	Please note that this is an example of a solution; other valid solutions will also be accepted.
 *	This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.
 */

#include <iostream>
#include <string>
class AB  {
public:
	AB ()
	{};
	int N;
	int K;
	int score = 0;
	std::string createString(int N, int K) {
		int first = 0;
		int last = N;
		this->N = N;
		std::string test = "";
		for (int i = N; i >= N/2; --i)
		{
			first = 0;
			last = i;
			while (first < last)  {
			if ( first*last == K)
				return generateString (first, last);
			else  {
				++first;
				--last;
			}
		}
			
		}
		return test;
	}
	std::string generateString ( int first, int last)  {
		std::string temp = "";
		for (int i = 0; i < first; ++i)
			temp.append("A");
		for (int i = 0; i < last; ++i)
			temp.append("B");
		std::cout<<last<<","<<N<<std::endl;
		if (last < N)  {
			for (int i = 0; i < N - (first + last); ++i)
				temp.append("A");
		}
		return temp;
	}
	
};
int main(int argc, const char * argv[]) {
	// insert code here...
	std::cout << "Hello, World!\n";
	std::unique_ptr<AB> ab = std::make_unique<AB> ();
	std::cout<<"answer = "<<ab->createString(10, 12)<<std::endl;
    return 0;
}
