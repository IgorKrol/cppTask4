#pragma once

// #include "Chooser.hpp"
#include "Guesser.hpp"
// #include "calculate.hpp"

using namespace bullpgia;

namespace bullpgia{
	class SmartGuesser : public Guesser{

		string myGuess = "";
		// int currentBull = 0;
		int index = 0;
		int lastBull = 0;

	public:
		SmartGuesser(){};

		virtual string guess() override;
		virtual void startNewGame(uint) override;
		virtual void learn(string) override;

	};


}
