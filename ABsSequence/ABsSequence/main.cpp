//
//  main.cpp
//  AbsSequence
//
//  Created by Anton Velikodnyy on 8/11/17.
//  Copyright © 2017 Anton Velikodnyy. All rights reserved.
//

/** Problem Statement
 *	Let's consider an infinite sequence S of non-negative integers defined as follows:
 *
 *	S0 = first;
 *	S1 = second;
 *	Si = |Si-2 - Si-1| for all i >= 2.
 *
 *	You will be given s first and second, representing the 0-th and the 1-st elements of the sequence S, and a indices, each element of which represents a non-negative integer without extra leading zeros. Return a containing as many elements as indices, where the i-th element is equal to the indices[i]-th element of the sequence S (index is 0-based). No element of the return should contain extra leading zeros.
 *
 *	Definition
 *	Class: AbsSequence
 *	Method: getElements
 *	Parameters: string, string, vector <string>
 *	Returns: vector <string>
 *	Method signature: vector <string> getElements(string first, string second, vector <string> indices)
 *	(be sure your method is public)
 *	Limits
 *	Time limit (s): 840.000
 *	Memory limit (MB): 64
 *	Constraints
 *	- first will represent an integer between 0 and 10^18, inclusive, with no extra leading zeros.
 *	- second will represent an integer between 0 and 10^18, inclusive, with no extra leading zeros.
 *	- indices will contain between 1 and 50 elements, inclusive.
 *	- Each element of indices will represent an integer between 0 and 10^18, inclusive, with no extra leading zeros.
 *	Examples
 *	0)
 *	"21"
 *	"12"
 *	{"0", "1", "2", "3", "4"}
 *	Returns: {"21", "12", "9", "3", "6" }
 *	Here S0=21 and S1=12. The next three sequence elements are S2 = |21 - 12| = 9, S3 = |12 - 9| = 3 and S4 = |9 - 3| = 6.
 *	1)
 *	"0"
 *	"0"
 *	{"1000000000000000000"}
 *	Returns: {"0" }
 *	Here we get the sequence consisting of only zeros.
 *	2)
 *	"823"
 *	"470"
 *	{"3","1","31","0","8","29","57","75","8","77"}
 *	Returns: {"117", "470", "2", "823", "115", "87", "49", "25", "115", "23" }
 *	3)
 *	"710370"
 *	"177300"
 *	{"5","95","164721","418","3387","710","0","1197","19507","5848"}
 *	Returns: {"178470", "108270", "90", "0", "90", "90", "710370", "90", "0", "0" }
 *	This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.
 *
 */
#include <iostream>
#include <vector>
#include <string>

class AbsSequence
{
public:
	std::vector <std::string> getElements(std::string first, std::string second, std::vector <std::string> indices);
private:
	std::vector <std::string> n_elements;
	std::string equation (const std::string& first, const std::string& second);
};

std::vector <std::string> AbsSequence::getElements(std::string first, std::string second, std::vector <std::string> indices)
{
	if (first.compare(second) == 0) {
		n_elements.push_back("0");
		return n_elements;
	}
	n_elements.push_back(first);
	n_elements.push_back(second);
	for (auto& e : indices) {
		auto index = std::stoll (e);
		std::cout<<index<<" = index";
		for (auto i = n_elements.size(); i < index + 1; ++i)  {
			std::cout<<i<<" = i";
			n_elements.push_back(equation(n_elements[i-2], n_elements[i-1]));
		}
		e = n_elements[index];
	}
	std::cout<<std::endl;
	std::cout<<std::endl;
	for ( int i = 0; i < n_elements.size(); ++i)  {
		std::cout<<"vector["<< i << "] = "	<< n_elements[i] << "\n";
	}
	
	return indices;
}

std::string AbsSequence::equation (const std::string& first, const std::string& second)
{
	auto x = stoi( first );
	auto y = stoi( second );
	auto diff = x > y ? x - y : y - x;
	return std::to_string(diff);
}

int main(int argc, const char * argv[]) {
	// insert code here...
	std::cout << "Hello, World!\n";
	auto seq = new AbsSequence();
	std::vector<std::string> temp;
	temp.push_back("3");
	temp.push_back("1");
	temp.push_back("31");
	temp.push_back("0");
	temp.push_back("8");
	temp.push_back("29");
	temp.push_back("57");
	temp.push_back("75");
	temp.push_back("8");
	temp.push_back("77");
	auto result = seq->getElements("823", "470", temp);
	for (auto const& e : result)
		std::cout<<e<<"\n";
	
	return 0;
}
