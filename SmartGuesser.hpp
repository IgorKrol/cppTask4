#pragma once

// #include "Chooser.hpp"
#include "Guesser.hpp"
// #include "calculate.hpp"

using namespace bullpgia;

namespace bullpgia{
	class SmartGuesser : public Guesser{
	public:
		// SmartGuesser();

		string guess() override;
	};
}
