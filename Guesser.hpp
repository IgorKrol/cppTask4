#pragma once

#include <string>

using namespace std;

namespace bullpgia{

	class Guesser{

	protected:
		uint length;

	public:

		virtual string guess() = 0;
		virtual void startNewGame(uint){}
		virtual void learn(string){}
	};
}