#pragma once

// #include "Chooser.hpp"
#include "Guesser.hpp"
#include "string.h"
// #include "calculate.hpp"

using namespace bullpgia;

namespace bullpgia{
	class SmartGuesser : public Guesser{

		string myGuess;
		int index;
		int lastBull;
		bool flag;
		
	public:
		SmartGuesser():index(0),lastBull(0),flag(true){};

		virtual string guess() override;
		virtual void startNewGame(uint) override;
		virtual void learn(string) override;

	};


}
