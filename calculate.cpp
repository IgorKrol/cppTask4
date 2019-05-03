
#include <string.h>

#include "calculate.hpp"
using namespace std;
string bullpgia::calculateBullAndPgia(string codeMaker, string codeBreaker){
	
	uint bull=0,pgia=0;
	////// CALC PGIA //////
	string pgiaMaker="",pgiaBreaker="";
	
	////// ERRORS: different length, illegal chars //////
	if (codeMaker!=codeBreaker){throw string("ERROR: NOT SAME LENGTH!");}
	if (codeMaker.find_first_not_of("0123456789")==string::npos){throw string("ERROR: CHOSEN STRING MUST CONTAIN DIGITS ONLY!");}
	if (codeBreaker.find_first_not_of("0123456789")==string::npos){throw string("ERROR: GUESSER STRING MUST CONTAIN DIGITS ONLY!");}
	

	for (int i = 0; i < codeMaker.length(); i++)
	{
		if (codeMaker[i] == codeBreaker[i]){
				bull++;
		}
		else{
			pgiaMaker+=codeMaker[i];
			pgiaBreaker+=codeBreaker[i];
		}
	}
	for (int i = 0; i < pgiaMaker.length(); i++)
	{
		for (int j = 0; j < pgiaBreaker.length(); j++)
		{
			if(pgiaMaker[i]==pgiaBreaker[j]){
				pgia++;
				break;
			}
		}
	}
	string res = to_string(bull)+","+to_string(pgia);
	return res;
}
