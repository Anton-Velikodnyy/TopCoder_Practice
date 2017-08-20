//
//  main.cpp
//  AcademicJournal
//
//  Created by Anton Velikodnyy on 8/18/17.
//  Copyright © 2017 Anton Velikodnyy. All rights reserved.
//

#include <iostream>
#include <sstream>

#include <algorithm>
#include <memory.h>
#include <stdio.h>
#include <vector>
#include <string>

class pair {
public:
	pair (std::string paper): name(paper) {};
	std::string name;
	int current = 0;
	bool operator < (const pair& p)const
	{	return current > p.current; }
};

class AcademicJournal {
public:
	AcademicJournal()
		{  };
	
	std::vector <std::string> rankByImpact(std::vector <std::string> papers);
	std::vector<pair> p;
	bool map [100][100];
	
	
private:
	void step1 (const std::vector<std::string>&);
	void step2 ();
	std::vector <std::string> step3 ();
	
	
	
};

std::vector<std::string> AcademicJournal::rankByImpact(std::vector <std::string> papers)
{
	memset(map, false, sizeof(map));
	//std::generate(name.begin(), name.end(), [&]{ SequenceGen(0); return papers[a.value()].substr()(0,papers[a.value()].find('.'))});
	step1(papers);
	//std::sort(papers.begin(), papers.end(), [&]( long i1, long i2) { return value[i1] < value[i2]; } );
	step2();
	sort(p.begin(),p.end());
	return step3();
}

void AcademicJournal::step1 (const std::vector<std::string>& papers)
{
	for (int i = 0; i < papers.size(); ++i)  {
		
		auto index = papers[i].find_first_of('.');
		std::string temp = papers[i].substr(0,index);
		int x = 0;
		for (; x < p.size(); ++x)  {
			if ( !p[x].name.compare(temp)) {
				
				break;
			}
		}
		int j = x;
		if (x == p.size())
			p.push_back(temp);
			
			
		
		std::string str = papers[i].substr(index+1);
		
		std::istringstream iss(str);
		int y;
		while (iss >> y) {
			map [j][y] = true;
		}
		
		
	}
	
};

void AcademicJournal::step2()
{
	for (int i = 0; i < 5; ++i)  {
		for (int j = 0; j < 5; ++j)  {
			if ( i != j && map[i][j])
				p[j].current++;
		}
	}
}

std::vector <std::string> AcademicJournal::step3 ()
{
	std::vector<std::string> result;
	for (auto& e : p)
		result.push_back(e.name);
		
	return result;
}



int main(int argc, const char * argv[]) {
	// insert code here...
	std::cout << "Hello.\n";
	
	AcademicJournal journal;
	auto result = journal.rankByImpact({"A.", "B. 0", "C. 1 0 3", "C. 2"});
	for (auto const& e : result)
		std::cout<<e<<", ";
	
	std::cout<<"\n";
	
	
	
	return 0;
}
