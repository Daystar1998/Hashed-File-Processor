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
#include <string>

using namespace std;

const string PINS_AND_KEYS_FILE = "pinsAndKeys.dat";
const string PINS_FILE = "pins.txt";
const string OUTPUT_FILE = "hashReport.txt";

const int PIN_SIZE = 3;
const int KEY_SIZE = 5;

struct HashRecord {

	char pin[PIN_SIZE];
	char key[KEY_SIZE];
	int top;
};

int main() {

	fstream hashIn(PINS_AND_KEYS_FILE, ios::in, ios::binary);

	int recordSize = 0;
	int recordCount = 0;
	int nextAvailableOverflowRecord = 0;

	hashIn.read((char *)recordSize, sizeof(int));
	hashIn.read((char *)recordCount, sizeof(int));
	hashIn.read((char *)nextAvailableOverflowRecord, sizeof(int));
}