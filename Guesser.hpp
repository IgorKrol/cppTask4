#pragma once

#include <string>

#include "calculate.hpp"

using namespace std;

namespace bullpgia{

	class Guesser{

	private:
		string guess;	

	protected:
		uint length;

	public:
		Guesser(){
			guess = "";
		}
		Guesser(const string& str){
			guess = str;
		}
		
		virtual string guess() = 0;
		virtual void startNewGame(uint){}
		virtual void learn(string){}
	};
}