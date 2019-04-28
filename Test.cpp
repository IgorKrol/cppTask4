/**
 * A demo program for bull-pgia.
 * 
 * @author Erel Segal-Halevi
 * @since  2019-04
 */


#include <iostream>
using namespace std;

#include "play.hpp"
#include "DummyChoosers.hpp"
#include "DummyGuessers.hpp"
#include "SmartGuesser.hpp"
#include "badkan.hpp"
#define COMMA ,

using namespace bullpgia;

int main() {

	badkan::TestCase testcase;
	int grade=0;
	int signal = setjmp(badkan::longjmp_buffer);
	if (signal == 0) {

		// BASIC TESTS - DO NOT CHANGE
		ConstantChooser c1234{"1234"}, c12345{"12345"}, c9999{"9999"};
		ConstantGuesser g1234{"1234"}, g12345{"12345"}, g9999{"9999"};

		testcase.setname("Calculate bull and pgia")
		.CHECK_OUTPUT(calculateBullAndPgia("1234","1234"), "4,0")      // 4 bull, 0 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("1234","4321"), "0,4")      // 0 bull, 4 pgia
		;

		testcase.setname("Play with dummy choosers and guessers")
		.CHECK_EQUAL(play(c1234, g1234, 4, 100), 1)      // guesser wins in one turn.
		.CHECK_EQUAL(play(c1234, g9999, 4, 100), 101)    // guesser loses by running out of turns 
		.CHECK_EQUAL(play(c1234, g12345, 4, 100), 101)   // guesser loses technically by making an illegal guess (too long).
		.CHECK_EQUAL(play(c12345, g1234, 4, 100), 0)     // chooser loses technically by choosing an illegal number (too long).
		;

		testcase.setname("Play with smart guesser");
		RandomChooser randy;
		SmartGuesser smarty;
		for (uint i=0; i<100; ++i) {
			testcase.CHECK_EQUAL(play(randy, smarty, 4, 100)<=10, true);  // smarty should always win in at most 10 turns!
		}

		/////////////////////////// MY TESTS ///////////////////////////
		ConstantChooser c{""};
		ConstantChooser cA{"a"};
		ConstantChooser c1111{"1111"};
		ConstantChooser cSpace{"123 45"};
		ConstantChooser cLetterNum{"123c45"};
		ConstantChooser cNegative123{"-123"};

		ConstantGuesser g{""};
		ConstantGuesser g1{"1"};
		ConstantGuesser gA{"a"};
		ConstantGuesser g1111{"1111"};
		ConstantGuesser gSpace{"123 45"};
		ConstantGuesser g123{"123"};
		ConstantGuesser gNegative123{"-123"};
		ConstantGuesser gLetterNum{"123c45"};

		testcase.setname("Constructor tests")
		.CHECK_EQUAL(c1234.choose(4), 1234)
		.CHECK_EQUAL(g1234.choose(4), 1234)
		.CHECK_EQUAL(c1234.choose(4), g1234.guess())
		;

		testcase.setname("calculateBullAndPgia tests")
		// SHORT NUMBERS
		.CHECK_OUTPUT(calculateBullAndPgia("1234","1243"), "2,2")      // 2 bull, 2 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("1234","1423"), "1,3")      // 1 bull, 3 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("1234","1253"), "2,1")      // 2 bull, 1 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("1234","1235"), "3,0")      // 3 bull, 0 pgia
		// MEDIUM LENGTH NUMBER
		.CHECK_OUTPUT(calculateBullAndPgia("1234567","1235476"), "3,4")      // 3 bull, 4 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("1234567","1230000"), "3,0")      // 3 bull, 0 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("1234567","9999979"), "0,1")      // 0 bull, 1 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("1000000","1247689"), "1,0")      // 1 bull, 0 pgia
		// LONG NUMBERS
		.CHECK_OUTPUT(calculateBullAndPgia("191919199","191919199"), "9,0")      // 9 bull, 0 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("123456777","765432111"), "0,7")      // 0 bull, 7 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("000000000","010203040"), "5,0")      // 5 bull, 0 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("104000099","124768950"), "2,2")      // 2 bull, 2 pgia

		.CHECK_OUTPUT(calculateBullAndPgia("1234","5326"), "0,2")      // 0 bull, 2 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("1234","5678"), "0,0")      // 0 bull, 0 pgia

		.CHECK_OUTPUT(calculateBullAndPgia("1234","1111"), "0,0")      // bull and pgia together?
		.CHECK_OUTPUT(calculateBullAndPgia("2134","1111"), "0,0")      // bull and pgia together?
		.CHECK_OUTPUT(calculateBullAndPgia("1111","1111"), "4,0")      // bull and pgia together?

		.CHECK_OUTPUT(calculateBullAndPgia(c12345.choose(5),g12345.guess()), "0,0")      // 0 bull, 0 pgia, using choose method
		;

		testcase.setname("Playing with Dummy choosers and guessers tests")
		.CHECK_OUTPUT(play(c1234, g1234, 4,1), 1)      // simple check
		.CHECK_OUTPUT(play(c1234, g1234, 4,5), 1)      // simple check with more than 1 turn using dummy chooser&guesser
		.CHECK_OUTPUT(play(c1234, g1111, 4,10), 11)      // simple check with wrong guesser
		.CHECK_OUTPUT(play(c1111, g1111, 4,1), 1)      // same number with repitition
		;

		testcase.setname("Playing with smart choosers tests")
		RandomChooser Igor;
		SmartGuesser Amit;
		for (uint i=0; i<100; ++i) {
			testcase.CHECK_EQUAL(play(Igor, Amit, 4, 100)<=10, true);  // smarty should always win in at most 10 turns!
		}

		for (uint i=0; i<100; ++i) {
			testcase.CHECK_EQUAL(play(c1234, Amit, 4, 100)<=10, true);  // smarty should always win in at most 10 turns!
		}
		;

		testcase.setname("Checking for Exceptions")
		.CHECK_THROWS(play(cA, g1, 1, 1))			// letters instead of numbers
		.CHECK_THROWS(play(cA, gA, 1, 1))			// letters instead of numbers

		.CHECK_THROWS(play(c, g1, 1, 1))			// empty string
		.CHECK_THROWS(play(c, g, 1, 1))				// empty string with empty string

		.CHECK_THROWS(play(cSpace, g12345, 6, 1))			// space between the code's numbers
		.CHECK_THROWS(play(cSpace, gSpace, 6, 1))			// space between the code's numbers, both on chooser and guesser

		.CHECK_THROWS(play(cNegative123, g123, 4, 1))					// negative number
		.CHECK_THROWS(play(cNegative123, gNegative123, 4, 1))			// negative number with the "correct" guesser

		.CHECK_THROWS(play(cLetterNum, gLetterNum, 4, 1))				// letter between both chooser and guesser

		.CHECK_THROWS(play(c1234, g1234, 5, 10))			// wrong length of code (5 instead of 4)
		;




    grade = testcase.grade();
	} else {
		testcase.print_signal(signal);
		grade = 0;
	}
	cout << "Your grade is: "  << grade << endl;
	return 0;
}

