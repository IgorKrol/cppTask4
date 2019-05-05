#pragma once

#include <string>

using namespace std;

namespace bullpgia{

	class Chooser{
	public:
		virtual string choose(uint length) = 0;
	};
}