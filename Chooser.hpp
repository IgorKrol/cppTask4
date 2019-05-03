#pragma once

#include <string>

#include "calculate.hpp"

using namespace std;

namespace bullpgia{

	class Chooser{

	private:
		string choice;

	public:
		Chooser(){
			choice = "";
		}

		Chooser(const string& str){
			choice = str;
		}

		virtual string choose(uint length) = 0;
	};
}