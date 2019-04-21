#pragma once

#include <string>

#include "calculate.hpp"

using namespace std;

namespace bullpgia{

	class Guesser{

	protected:
		uint length;

	public:
		Guesser(){}
		virtual string guess() = 0;
		virtual void startNewGame(uint){}
		virtual void learn(string){}
	};
}