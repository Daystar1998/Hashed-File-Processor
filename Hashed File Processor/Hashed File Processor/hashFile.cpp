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
#include <vector>

using namespace std;

const string PINS_AND_KEYS_FILE = "pinsAndKeys.dat";
const string PINS_FILE = "pins.txt";
const string OUTPUT_FILE = "hashReport.txt";

const char NOT_FOUND_CHAR = '*';
const int NULL_TOP = -1;

const int PIN_SIZE = 3;
const int KEY_SIZE = 5;

struct HashRecord {

	char pin[PIN_SIZE];
	char key[KEY_SIZE];
	int top;
};

struct KeyAndAccesses {

	string pin;
	string key;
	int accessCount;
};

int recordSize = 0;
int recordCount = 0;
int nextAvailableOverflowRecord = 0;

/******************************************************************************
		Name: findKey

		Des:
			Finds the associated key and number of accesses required for the pin

		Params:
			hashIn - type ifstream &, the name of the hashed file
			pin - type string &, the pin

		Return:
			type KeyAndAccesses, the key and access count

******************************************************************************/
KeyAndAccesses findKey(ifstream &hashIn, string &pin) {

	KeyAndAccesses result;

	result.pin = pin;

	for (int i = 0; i < KEY_SIZE; i++) {

		result.key[i] = NOT_FOUND_CHAR;
	}

	result.accessCount = 0;

	int headerLength = sizeof(int) * 3;

	int pinHash = 0;

	for (int i = 0; i < PIN_SIZE; i++) {

		pinHash += pin[i];
	}

	pinHash %= recordCount;

	hashIn.seekg((streampos)(headerLength + pinHash * recordSize));

	HashRecord record;

	do {

		hashIn.read((char *)&record, sizeof(HashRecord));

		result.accessCount++;;

		if (record.pin == pin) {

			result.key = record.key;
			break;
		} else if (record.pin[0] == NOT_FOUND_CHAR || record.top == NULL_TOP) {

			break;
		} else {

			int recordLocation = headerLength + recordCount * recordSize + record.top * recordSize;

			hashIn.seekg((streampos)recordLocation);
		}
	} while (true);

	return result;
}

int main() {

	ifstream hashIn(PINS_AND_KEYS_FILE, ios::in | ios::binary);

	hashIn.read((char *)recordSize, sizeof(int));
	hashIn.read((char *)recordCount, sizeof(int));
	hashIn.read((char *)nextAvailableOverflowRecord, sizeof(int));
}