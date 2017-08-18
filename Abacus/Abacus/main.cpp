//
//  main.cpp
//  Abacus
//
//  Created by Anton Velikodnyy on 8/9/17.
//  Copyright © 2017 Anton Velikodnyy. All rights reserved.
//
/** Problem Statement
 *	An abacus can be used to do arithmetic. The version that we have has 6 horizontal threads, each with nine beads on it. The beads on each thread are always arranged with just one gap, possibly at one of the ends. However many beads are adjacent and at the right end of the thread is the digit value of the thread. The value on the abacus is read by taking the digits in order from top thread to bottom thread and arranging them from left to right (so the top thread is the one that contains the most significant digit).
 *	Create a class Abacus that contains a method add that is given a String[] original and a number val and that returns a String[] showing the abacus after val has been added to the original abacus.
 *
 *	Both in original and in the return, the String[] will contain exactly 6 elements representing the 6 threads in order from top thread to bottom thread. Each element will contain a lowercase 'o' to represent each bead and three consecutive hyphens '-' to indicate the empty part of the thread. Each element will thus contain exactly 12 characters.
 *
 *	Definition
 *	Class: Abacus
 *	Method: add
 *	Parameters: vector <string>, int
 *	Returns: vector <string>
 *	Method signature: vector <string> add(vector <string> original, int val)
 *	(be sure your method is public)
 *	Limits
 *	Time limit (s): 840.000
 *	Memory limit (MB): 64
 *	Constraints
 *	- original will contain exactly 6 elements.
 *	- Each element of original will contain exactly 12 characters, 9 lowercase 'o's and 3 consecutive '-'s.
 *	- val will be between 0 and 999,999 inclusive.
 *	- val added to the original abacus will result in a value that can be shown on the abacus.
 *	Examples
 *	0)
 *	{"ooo---oooooo", "---ooooooooo", "---ooooooooo", "---ooooooooo", "oo---ooooooo", "---ooooooooo"}
 *	5
 *	Returns: {"ooo---oooooo", "---ooooooooo", "---ooooooooo", "---ooooooooo", "o---oooooooo", "ooooo---oooo" }
 *	When we add 5 to the original, it is necessary to "carry" 1 to the next thread up. This shows the arithmetic 699979 + 5 = 699984
 *	1)
 *	{"ooo---oooooo", "---ooooooooo", "---ooooooooo", "---ooooooooo", "oo---ooooooo", "---ooooooooo"}
 *	21
 *	Returns: {"oo---ooooooo", "ooooooooo---", "ooooooooo---", "ooooooooo---", "ooooooooo---", "ooooooooo---" }
 *	This shows 699979 + 21 = 700000
 *	2)
 *	{"ooooooooo---", "---ooooooooo", "ooooooooo---", "---ooooooooo", "oo---ooooooo", "---ooooooooo"}
 *	100000
 *	Returns: {"oooooooo---o", "---ooooooooo", "ooooooooo---", "---ooooooooo", "oo---ooooooo", "---ooooooooo" }
 *	3)
 *	{"o---oooooooo", "---ooooooooo", "---ooooooooo", "---ooooooooo", "---ooooooooo", "---ooooooooo" }
 *	1
 *	Returns: {"---ooooooooo", "ooooooooo---", "ooooooooo---", "ooooooooo---", "ooooooooo---", "ooooooooo---" }
 *	This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.
 */

#include <iostream>
#include <vector>
#include <string>

class Abacus
{
public:
	Abacus()
	{};
	std::vector <std::string> add(std::vector <std::string> original, int val);
};


std::vector <std::string> Abacus::add(std::vector <std::string> original, int val)
{
	bool carry = false;
	int place, new_place;
	std::string val_str;
	for (int i = (int)original.size()- 1; i >= 0; --i)  {
		val_str = std::to_string(val);
		place = (int)(original[0].size() - (original[i].find("---") + 3));
		int digit = val % 10;
		new_place = place + digit + carry;
		if (new_place > 9)  {
			new_place -= 10;
			carry = true;
		}
		else  {
			carry = false;
		}
		for (int d = 0; d < 3; ++d)  {
			std::swap(original[i][original[0].size() - (new_place + 3) + d],original[i][original[0].size() - (place + 3) + d] );
		}
		if (val < 10)  {
			if (carry) val = 0;
			else break;
		}
		else
			val /= 10;
		
		
	}
	return original;
}

int main(int argc, const char * argv[]) {
	// insert code here...
	std::cout << "Hello, World!\n";
	std::vector<std::string> device;
	device.push_back("ooo---oooooo");
	device.push_back("---ooooooooo");
	device.push_back("---ooooooooo");
	device.push_back("---ooooooooo");
	device.push_back("o---oooooooo");
	device.push_back("ooooo---oooo");
	Abacus* abb = new Abacus();
	auto device2 = abb->add(device, 21);
	for ( auto const& i : device2)
		std::cout<<i<<"\n";
	
	return 0;
}
