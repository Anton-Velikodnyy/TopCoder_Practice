//
//  main.cpp
//  AdjacentSwaps
//
//  Created by Anton Velikodnyy on 8/21/17.
//  Copyright © 2017 Anton Velikodnyy. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cstring>

template <class T>
void swap (T& x, T& y)
{
	x = x + y;
	y = x - y;
	x = x - y;
}
class AdjacentSwaps
{
public:
	int theCount(std::vector <int> p);
private:
	int result;
	long a;
	int size;
	std::vector<int> initial;
	
	void attempt (std::vector<int>& p, bool* rabbits, int count);
	void attempt2 (std::vector<int>& p);
	bool test (const std::vector<int>& p, int i, int j);
	bool right_size (int index, int num, bool* rabbits);
	bool left_size (int index, int num, bool* rabbits);
};

int AdjacentSwaps::theCount(std::vector <int> p)
{
	result = 0;
	a = 0;
	size = (int)p.size() - 1;
	
	for (int i = 0; i < size + 1; ++i)
		initial.push_back(i);
	
	bool* rabbit;
	rabbit	= new bool [size];
	memset(rabbit, false, size);
	
	attempt2(p);
	
	
	return result;
}


void AdjacentSwaps::attempt (std::vector<int>& p, bool* rabbits, int count)
{
	
	if (count == (size) ) {
		if (p == initial)  {
  		std::cout<<"correct\n\n";
  		++result;
  		return;
		}
		std::cout<<result<<"::"<<++a<<"\n";
	}
	for (int i = 0; i < size;	++i)  {
		
		//std::cout<<result<<":"<<i<< "\n";
		/*for (auto const& e: p)
			std::cout<< e<< " ";
			std::cout<< ":";
		for (auto const& e: initial)
			std::cout<< e<< " ";
			std::cout<< "\n";
		 */
		if (!rabbits[i] && right_size(i, p[i], rabbits) && left_size(i + 1, p[i + 1], rabbits))  {
		//	std::cout<< "true\n";
			rabbits[i] = true;
			swap ( p[i], p[i+1]);
			//attempt(p, rabbits, count+1);
			rabbits[i] = false;
			swap ( p[i], p[i+1]);
		}
	}
	return;
};


bool AdjacentSwaps::right_size (int index, int num, bool* rabbits)
{
	//std::cout<< "right side\n";
	if ( index > num )
		return false;
	for (int i = index + 1 ; i < index ; ++i)  {
		if (rabbits[i])  {
			return false;
		}
	}
	return true;
};
bool AdjacentSwaps::left_size (int index, int num, bool* rabbits)
{
//	std::cout<< "left side\n";
	if ( index < num )
		return false;
	for (int i = index - 1 ; i > index; --i)  {
		if (rabbits[i])  {
			return false;
		}
	}
	return true;
};


void AdjacentSwaps::attempt2 (std::vector<int>& p)
{
	int x;
	for (auto const& e : p)
		std::cout<<e<< " ";
		std::cout<< "\n";
	for (int i = 0; i < size + 1; ++i)  {
		if (p[i] > i)  {
			x = p[i] - i;
		}
		else  {
			x = i - p[i];
		}
		std::cout<<p[i]<<":"<<x<<"\n";
		result += x/2;
	}
	result;
	
}

bool AdjacentSwaps::test (const std::vector<int>& p, int i, int j)
{
	for ( int pos = 0; pos < i; ++pos)  {
		if (p[pos] == j)
			return false;
	}
	return true;
}


int main(int argc, const char * argv[]) {
	// insert code here...
	std::cout << "Hello, World!\n";
	
	AdjacentSwaps test;
	std::cout<<std::endl;
	auto result0 = test.theCount({1, 2, 0});
	auto result1 = test.theCount({0, 1});
	auto result2 = test.theCount({2, 0, 3, 1});
	auto result3 = test.theCount({1, 0, 3, 2});
	auto result4 = test.theCount({1, 3, 0, 5, 2, 7, 4, 8, 10, 6, 12, 9, 14, 11, 16, 13, 18, 15, 19, 17});
	std::cout<<std::endl;
	std::cout<<result0<<std::endl;
	std::cout<<result1<<std::endl;
	std::cout<<result2<<std::endl;
	std::cout<<result3<<std::endl;
	std::cout<<result4<<std::endl;
	return 0;
}
