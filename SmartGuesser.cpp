
#include "SmartGuesser.hpp"
#include <iostream>
#include <string.h>

using namespace bullpgia;

string SmartGuesser::guess(){
	return this->myGuess;
}

void SmartGuesser::startNewGame(uint len){
	this->myGuess="";
	for(int i =0; i < len; i++){
		this->myGuess += '0';
	}
	this->index=0;
	this->lastBull=0;
	this->flag=true;
}	

void SmartGuesser::learn(string str){

	// int splitIndex = str.find(',');
	int bulls = stoi(str);
	if (flag){
		flag=!flag;
		lastBull=bulls;
	}
	else
	 if(bulls == lastBull){				// current bulls count are the same as before
		this->myGuess[this->index] += 1;
	}
	else if(this->lastBull > bulls){		// last change lowered us 1 bull
		this->myGuess[this->index] -= 1;
	}
	else{									// we found 1 bull
		this->index++;
	}
	// cout<<lastBull<<"  "<<myGuess<<"  "<<bulls<<endl;
	lastBull=bulls;
	// cout<<myGuess<<endl;
};