#pragma once

#include <string>

// #include "Guesser.hpp"
#include "calculate.hpp"
// #include "SmartGuesser.hpp"

using namespace std;
// using namespace bullpgia;

namespace bullpgia{
	class Chooser{
	public:

		virtual string choose(uint length) = 0;
	};
}