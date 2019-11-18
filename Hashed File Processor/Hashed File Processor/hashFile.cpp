/******************************************************************************
	Name: hashFile.cpp

	Des:
		This program will read a hashed file ("pinsAndKeys.dat") and a pin file
		("pins.txt"). It will output to "hashReport.txt." The output will
		include the pin, the key, and the number of accesses required to find
		the key or determine it does not exist. It will also output the average
		number of accesses for the pin.

	Author: Matthew Day

	Due Date: 12/5/2019
******************************************************************************/

#include <fstream>

using namespace std;

const int PIN_SIZE = 3;
const int KEY_SIZE = 5;

struct HashRecord {

	char pin[PIN_SIZE];
	char key[KEY_SIZE];
	int top;
};

int main() {


}