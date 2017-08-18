//
//  main.cpp
//  AToughGame
//
//  Created by Anton Velikodnyy on 8/15/17.
//  Copyright © 2017 Anton Velikodnyy. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stdlib.h>


class AToughGame
{
public:
	AToughGame(){};
	
	double expectedGain(std::vector <int> prob, const std::vector <int>& value);
	
private:
	double A_gold = 0;
	double D_gold = 0;
	int		 D_level= -1;
	bool death = false;
	bool play ( int prob);
	double A_total = 0;
	
	
};

double AToughGame::expectedGain(std::vector <int> prob, const std::vector <int>& value)
{
	A_total = 0;
	for (int x = 0; x < 1000; ++x)  {
  	A_gold = 0;
  	D_gold = 0;
  	D_level= -1;
  	for (int i = 0; i < prob.size(); ++i)  {
  		
  		if (play(prob[i])) {//wins level
  			A_gold += value[i];
  			if ( D_level == i) {
    			A_gold += D_gold;
    			D_gold = 0;
    		}
  			
  		}
  		else { //dies
  			if (i != 0) {
  				D_gold = A_gold;
  				D_level= i - 1;
  			}
  			A_gold = 0;
  			i = -1;
  		}
  		
  		//call level
  	}
		A_total += A_gold;
	}
	return A_total/1000;
}


bool AToughGame::play ( int prob )
{
	auto attemt = rand() % 1000;
	if (attemt < prob) {
		return true;
	}
	else return false;
}

int main(int argc, const char * argv[]) {
	// insert code here...
	std::cout << "Hello, World!\n";
	
	auto game = new AToughGame();
	for (int i = 0; i < 1000; i++)
		std::cout<<game->expectedGain({1000,1},{3,4})<<std::endl;
    return 0;
}
