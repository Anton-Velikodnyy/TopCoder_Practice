//
//  main.cpp
//  BearEats
//
//  Created by Anton Velikodnyy on 8/19/17.
//  Copyright © 2017 Anton Velikodnyy. All rights reserved.
//

#include <iostream>
#include <memory.h>
#include <cstring>
#include <vector>

auto MAX = 1000*1000*1000+7;
class BearEats
{
public:
	long long getDifference(int N, int R, int C, int D, int A_MAX, int B_MAX);
private:
	
	long long diff;
	long long* A;
	long long* B;
	std::vector<int> choice;
	std::vector<int> choice_final;
	int index = 0;
	int size;
	void bake_cookies (int N, int R, int C, int D, int A_MAX, int B_MAX);
	void L_pick ( long long L, long long E, bool* plate, int Ncookies, int size);
	void E_pick ( long long L, long long E, bool* plate, int Ncookies, int size);
};

long long BearEats::getDifference(int N, int R, int C, int D, int A_MAX, int B_MAX)
{
	size = N;
	diff = -1*(A_MAX - 1);
	for (int i = 0; i< N; i++)
		choice.push_back(0);
	A = new long long[size];
	B = new long long[size];
	auto plate = new bool[size];
	std::memset(plate, false, size);
	bake_cookies(N, R, C, D, A_MAX, B_MAX);
	L_pick(0, 0, plate, 0, size);
	
	return diff;
};

void BearEats::bake_cookies (int N, int R, int C, int D, int A_MAX, int B_MAX)
{
	for (int i = 0; i < N; ++i)  {
		R = ((long long)C * R + D) % MAX;
		A[i] = R % A_MAX;
		R = ((long long)C * R + D) % MAX;
		B[i] = R % B_MAX;
	}
};

void BearEats::L_pick ( long long L, long long E, bool* plate, int Ncookies, int size)
{
	if ( Ncookies == size) {
		long long new_diff = L - E;
		
		if ( diff < new_diff ) {
			diff = new_diff;
			choice_final = choice;
			
		}
		return;
	}
		
	for (int i = 0; i < size; ++i)  {
		if (!plate[i])  {
			plate[i] = true;
			choice[index] = i;
			index++;
			E_pick(L+A[i], E, plate, Ncookies + 1, size);
			index--;
			choice[index] = -1;
			plate[i] = false;
		}
	}
	
	
};

void BearEats::E_pick ( long long L, long long E, bool* plate, int Ncookies, int size)
{
	if ( Ncookies == size) {
		long long new_diff = L - E;
		if ( diff < new_diff ) {
			diff = new_diff;
			choice_final = choice;
		}
		
		return;
	}
	int pick = -1;
	long long E_value= 0;
	long long L_value= 0;
	for (int i = 0; i < size; ++i)  {
		if (!plate[i] )  {
			if (E_value < B[i]) {
				pick = i;
				E_value = B[i];
				L_value = A[i];
			}
			else if (E_value == B[i] && L_value < A[i])  {
				pick = i;
				E_value = B[i];
				L_value = A[i];
			}
			
		}
		
	}
	plate[pick] = true;
	choice[index] = pick;
	index++;
	L_pick(L, E + E_value, plate, Ncookies + 1, size);
	index--;
	choice[index] = -1;
	plate[pick]	= false;
};


int main(int argc, const char * argv[]) {
	// insert code here...
	std::cout << "Hello, World!\n";
	
	BearEats test;
	auto result = test.getDifference(
																	 200000,
																	 999998741,
																	 999997411,
																	 64592149,
																	 57,
																	 75
																	 );
	std::cout<<result<<"\n";
    return 0;
}
