// BITSTUFFING PROGRAM
// By Daniele Pãolo Grech Pereira, 2020

#include <iostream>
#include <vector>

// Main program
///////////////

int main() {

	// VARS
	///////

	int sum = 0;						// 1s counter.
	int a[8] = { 0,1,1,1,1,1,1,0 };		// Framing digits.
	int loopSize = 0;					// For setting loop size.


	// VECTOR CREATION
	//////////////////

	std::vector<int> newVector;		// Vector to hold initial values:
	std::vector<int> outPut;		// Vector for output of bitstuffing:
	std::vector<int> framedVector;	// Vector to be framed:


	// VECTOR SETUP
	///////////////

	// Set vector with initial values:
	newVector = {0,1,1,1,1,1,1,0,1,1,1,1,1,1,0};
	
	// Frontload framedVector:
	framedVector.insert(framedVector.end(), a, a + (sizeof(a) / sizeof(a[0])));


	// STUFFING & FRAMING
	/////////////////////
	
	// Build vectors with loop:
	loopSize = newVector.size();	// Set loop size.
	for (int i = 0; i < loopSize; i++)
	{
		// Check if current index is a 1 or 0:
		if (newVector[i] == 1)
		{
			sum += 1;					// If 1, increment 1s counter.

			// Build vectors:
			outPut.push_back(1);		// Push 1 value into output vector.
			framedVector.push_back(1);	// Push 1 value into framed vector.

			// If 1s counter is at 5, add a zero to array:
			if (sum == 5)
			{
				// Build vectors:
				outPut.push_back(0);		// Push 0 value into output vector.
				framedVector.push_back(0);	// Push 0 value into framed vector.

				sum = 0;	// Reset 1s counter:
			}

		}
		else
		{
			// If value at index i is 0:
			sum = 0;	// Reset 1s counter.

			// Build vectors:
			outPut.push_back(0);		// Push 0 value into ouput vector.
			framedVector.push_back(0);	// Push 0 value into framed vector.
		}
	};

	
	// Backload framedVector:
	framedVector.insert(framedVector.end(), a, a+(sizeof(a)/sizeof(a[0])));

	// Vectors completed.

	
	// PROGRAM OUTPUT
	/////////////////

	// Before stuffing:
	std::cout << "Before stuffing: ";
	
	// Print original vector:
	loopSize = newVector.size();
	for (int i = 0; i < loopSize; i++)
	{
		std::cout << newVector[i];
	};

	std::cout << " -- " << newVector.size() << " characters" << "\n";

	
	// After stuffing:
	std::cout << "After stuffing:  ";
	
	// Print stuffed vector:
	loopSize = outPut.size();
	for (int i = 0; i < loopSize; i++)
	{
		std::cout << outPut[i];
	};

	std::cout << " -- " << outPut.size() << " characters" << "\n";

	
	// After framing:
	std::cout << "After framing:   ";

	// Print bitstuffed framed vector:
	loopSize = framedVector.size();
	for (int i = 0; i < loopSize; i++)
	{
		std::cout << framedVector[i];
	};

	std::cout << " -- " << framedVector.size() << " characters" << "\n";

	
	// Exit program:
	return 0;
};