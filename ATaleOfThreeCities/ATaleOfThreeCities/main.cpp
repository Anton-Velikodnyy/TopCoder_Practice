//
//  main.cpp
//  ATaleOfThreeCities
//
//  Created by Anton Velikodnyy on 8/8/17.
//  Copyright © 2017 Anton Velikodnyy. All rights reserved.
//

/*
 *	Problem Statement
 *	As a result of ever increasing traffic jams, subway transportation in big cities has become a must. A train can actually take you from your home to your office faster than a car can. But what happens if you have your office in another city? In this problem we consider three different cities: A, B and C. Each of these cities has its own subway transportation system and you can go from a station to any other in the same city without having to leave the underground. A big project is now underway, and the goal is to merge the subway lines such that transportation between these cities becomes available soon. In order to achieve this, it was decided that two tunnels would be constructed, each of them connecting two subway stations in two different cities. This has to be done at a minimal cost, so it is important which subway stations are chosen. Also consider that the only factor in determining the cost is the distance between the two subway stations connected by a tunnel.
 *
 *	You will be given a int[] ax, a int[] ay, a int[] bx, a int[] by, a int[] cx and a int[] cy with the following signification:
 *	ax and ay represent the coordinates of the subway stations in city A i.e (ax[i],ay[i]) is the point denoting the place of the i-th station
 *	bx and by represent the coordinates of the subway stations in city B i.e (bx[i],by[i]) is the point denoting the place of the i-th station
 *	cx and cy represent the coordinates of the subway stations in city C i.e (cx[i],cy[i]) is the point denoting the place of the i-th station
 *
 *	Return the minimal added distance of the two tunnels such that all three cities become connected.
 *	Definition
 *	Class: ATaleOfThreeCities
 *	Method: connect
 *	Parameters: vector <int>, vector <int>, vector <int>, vector <int>, vector <int>, vector <int>
 *	Returns: double
 *	Method signature: double connect(vector <int> ax, vector <int> ay, vector <int> bx, vector <int> by, vector <int> cx, vector <int> cy)
 *	(be sure your method is public)
 *	Limits
 *	Time limit (s): 840.000
 *	Memory limit (MB): 64
 *	Notes
 *	- Your return value must have an absolute or relative error less than 1e-9.
 *	Constraints
 *	- ax, ay, bx, by, cx, and cy will each contain between 2 and 50 elements, inclusive.
 *	- Each element of ax, ay, bx, by, cx, and cy is between -100 and 100, inclusive.
 *	- The number of elements in ax is equal to the number of elements in ay.
 *	- The number of elements in bx is equal to the number of elements in by.
 *	- The number of elements in cx is equal to the number of elements in cy.
 *	- There are no subway stations with identical coordinates.
 *	Examples
 *	0)
 *	{0,0,0}
 *	{0,1,2}
 *	{2,3}
 *	{1,1}
 *	{1,5}
 *	{3,28}
 *	Returns: 3.414213562373095
 *	The tunnel connecting the subway station in city A at (0,2) with the subway station in city C at (1,3) has a length of about 1.41 and the tunnel connecting the subway station in city A at (0,1) with the subway station in city B at (2,1) has a length of 2.
 *	1)
 *	{-2,-1,0,1,2}
 *	{0,0,0,0,0}
 *	{-2,-1,0,1,2}
 *	{1,1,1,1,1}
 *	{-2,-1,0,1,2}
 *	{2,2,2,2,2}
 *	Returns: 2.0
 *	2)
 *	{4,5,11,21,8,10,3,9,5,6}
 *	{12,8,9,12,2,3,5,7,10,13}
 *	{34,35,36,41,32,39,41,37,39,50}
 *	{51,33,41,45,48,22,33,51,41,40}
 *	{86,75,78,81,89,77,83,88,99,77}
 *	{10,20,30,40,50,60,70,80,90,100}
 *	Returns: 50.323397776611024
 *	This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.
 */

#include <iostream>
#include <string>

#include <vector>
#include <math.h>

class ATaleOfThreeCities
{
public:
	double connect (const std::vector <int>& ax, const std::vector <int>& ay,
									const std::vector <int>& bx, const std::vector <int>& by,
									const std::vector <int>& cx, const std::vector <int>& cy);

private:
	double pythagorean (int ix, int iy, int jx, int jy);
	double shortest_connection (const std::vector <int>& ix, const std::vector <int>& iy,
													 const std::vector <int>& jx, const std::vector <int>& jy);
};

double ATaleOfThreeCities::connect (const std::vector <int>& ax, const std::vector <int>& ay,
																	  const std::vector <int>& bx, const std::vector <int>& by,
																	  const std::vector <int>& cx, const std::vector <int>& cy)
{
	double a_to_b = shortest_connection(ax, ay, bx, by);
	double b_to_c = shortest_connection(bx, by, cx, cy);
	double c_to_a = shortest_connection(cx, cy, ax, ay);
	
	double result = a_to_b + b_to_c;
	double temp = b_to_c + c_to_a;
	
	if (result > temp)
		result = temp;
	
	temp = a_to_b + c_to_a;
	
	if (result > temp)
		result = temp;
	
	return result;
}

double ATaleOfThreeCities::pythagorean(int ix, int iy, int jx, int jy)
{
	return hypot(abs(ix - jx), abs(iy - jy));
}

double ATaleOfThreeCities::shortest_connection (const std::vector <int>& ix, const std::vector <int>& iy,
																						 const std::vector <int>& jx, const std::vector <int>& jy)
{
	double i_to_j = 10000000;
	
	for (int i = 0; i < ix.size(); ++i)  {
		for (int j = 0; j <jx.size(); ++j)  {
			double temp = pythagorean(ix[i], iy[i], jx[j], jy[j]);
			if (i_to_j > temp)
				i_to_j = temp;
		}
	}
	return i_to_j;
}

int main(int argc, const char * argv[]) {
	// insert code here...
	std::cout << "Hello, World!\n";
	auto metro = std::make_shared<ATaleOfThreeCities>();
	std::vector<int> ax;
	ax.push_back(0);
	ax.push_back(0);
	ax.push_back(0);
	std::vector<int> ay;
	ay.push_back(0);
	ay.push_back(1);
	ay.push_back(2);
	std::vector<int> bx;
	bx.push_back(2);
	bx.push_back(3);
	std::vector<int> by;
	by.push_back(1);
	by.push_back(1);
	std::vector<int> cx;
	cx.push_back(1);
	cx.push_back(5);
	std::vector<int> cy;
	cy.push_back(3);
	cy.push_back(28);
	std::cout<<std::to_string(metro->connect(ax, ay, bx, by, cx, cy));
	
    return 0;
}
