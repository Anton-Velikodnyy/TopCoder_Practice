//
//  main.cpp
//  AcademicJournal
//
//  Created by Anton Velikodnyy on 8/18/17.
//  Copyright © 2017 Anton Velikodnyy. All rights reserved.
//
/* Problem Statement
 *	
 *	In any field of research, there are many journals to which one can submit an article for publication. One criterion that is commonly used to choose between journals is the impact factor, a measure of the importance of a journal and the papers that are published there. The impact factor of a journal is defined as the average number of citations each paper in that journal receives from papers in other journals. Citations from papers in the same journal are not counted in order to prevent its editors from inflating their impact factor by preferentially accepting papers that cite other papers in their journal. Although impact factors are not a fair way to judge the quality of research, they do provide a quantitative method for comparing journals to each other.
 *	
 *	Write a class AcademicJournal with a method rankByImpact that takes a String[] papers, a collection of published papers from which to calculate impact factors, and returns a String[] with the journal names sorted in decreasing order by impact factor. Each element of papers contains the information for a single paper, and is formatted with the name of the paper's journal (consisting of only uppercase English characters and spaces), followed by a period, followed by zero or more integers specifying the zero-based indices of the papers it cites. The citation indices contain no extra leading zeroes, and are separated from each other and from the period character by single spaces. If there is a tie in the impact factors, the journal with more papers comes first in the return value. If there is still a tie, the journal with the lexicographically earlier name comes first.
 *	
 *	
 *	Definition
 *	
 *	Class:	AcademicJournal
 *	Method:	rankByImpact
 *	Parameters:	String[]
 *	Returns:	String[]
 *	Method signature:	String[] rankByImpact(String[] papers)
 *	(be sure your method is public)
 *	
 *	
 *	Notes
 *	-	Although it is not supposed to happen, it is possible for two papers to reference each other due to delays in the editing and publishing process.
 *	-	A sloppy author or editor of a paper might accidentally include multiple citations to another paper. In your calculation of the impact factors, count citations from one paper to another only once.
 *	
 *	Constraints
 *	-	papers will contain between 1 and 50 elements, inclusive.
 *	-	Each element of papers will contain between 2 and 50 characters, inclusive.
 *	-	Each element of papers will be formatted as described in the problem statement.
 *	-	Each index will be between 0 and the number of papers - 1, inclusive.
 *	-	A paper will not contain a reference to itself.
 *	
 *	Examples
 *	0)
 *	
 *	{"A.", "B. 0", "C. 1 0 3", "C. 2"}
 *	Returns: {"A", "B", "C" }
 *	The one paper in journal A is cited two times, so A's impact factor is 2/1. The one paper in journal B is cited once, so B's impact factor is 1/1. The two papers in journal C only receive citations from each other. Since citations from a paper in the same journal do not count, C's impact factor is 0/2.
 *	1)
 *	
 *	{"RESPECTED JOURNAL.", "MEDIOCRE JOURNAL. 0", "LOUSY JOURNAL. 0 1",
 *	"RESPECTED JOURNAL.", "MEDIOCRE JOURNAL. 3", "LOUSY JOURNAL. 4 3 3 4",
 *	"RESPECTED SPECIFIC JOURNAL.", "MEDIOCRE SPECIFIC JOURNAL. 6", "LOUSY SPECIFIC JOURNAL. 6 7"}
 *	Returns:
 *	{"RESPECTED JOURNAL",
 *	"RESPECTED SPECIFIC JOURNAL",
 *	"MEDIOCRE JOURNAL",
 *	"MEDIOCRE SPECIFIC JOURNAL",
 *	"LOUSY JOURNAL",
 *	"LOUSY SPECIFIC JOURNAL" }
 *	There is an impact factor tie between the SPECIFIC and non-specific versions of each tier of journal. Since the non-specific ones have more papers, they win the tiebreaker.
 *	2)
 *	
 *	{"NO CITATIONS.", "COMPLETELY ORIGINAL."}
 *	Returns: {"COMPLETELY ORIGINAL", "NO CITATIONS" }
 *	If there is a tie in impact factor and number of papers, the journal with the lexicographically earlier name comes first.
 *	3)
 *	
 *	{"CONTEMPORARY PHYSICS. 5 4 6 8 7 1 9",
 *	"EUROPHYSICS LETTERS. 9",
 *	"J PHYS CHEM REF D. 5 4 6 8 7 1 9",
 *	"J PHYS SOC JAPAN. 5 4 6 8 7 1 9",
 *	"PHYSICAL REVIEW LETTERS. 5 6 8 7 1 9",
 *	"PHYSICS LETTERS B. 6 8 7 1 9",
 *	"PHYSICS REPORTS. 8 7 1 9",
 *	"PHYSICS TODAY. 1 9",
 *	"REP PROGRESS PHYSICS. 7 1 9",
 *	"REV MODERN PHYSICS."}
 *	Returns:
 *	{"REV MODERN PHYSICS",
 *	"EUROPHYSICS LETTERS",
 *	"PHYSICS TODAY",
 *	"REP PROGRESS PHYSICS",
 *	"PHYSICS REPORTS",
 *	"PHYSICS LETTERS B",
 *	"PHYSICAL REVIEW LETTERS",
 *	"CONTEMPORARY PHYSICS",
 *	"J PHYS CHEM REF D",
 *	"J PHYS SOC JAPAN" }
 *	This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2010, TopCoder, Inc. All rights reserved.
 */
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
