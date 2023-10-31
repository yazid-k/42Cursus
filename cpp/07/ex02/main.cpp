#include "Array.hpp"

int main()
{
	try
	{
		// Create an empty array
		Array<int> emptyArray;
		std::cout << "Empty Array Size: " << emptyArray.size() << std::endl;

		// Create an array with 5 elements
		Array<int> intArray(5);

		// Initialize the elements with values
		for (unsigned int i = 0; i < intArray.size(); ++i)
		{
			intArray[i] = i * 10;
		}

		// Display the elements
		std::cout << "Array Size: " << intArray.size() << std::endl;
		std::cout << "Array Elements:" << std::endl;
		for (unsigned int i = 0; i < intArray.size(); ++i)
		{
			std::cout << intArray[i] << " ";
		}
		std::cout << std::endl;

		// Create a copy of the array
		Array<int> copyArray;
		copyArray = intArray;

		// Modify the original array
		intArray[2] = 42;

		// Display the copy array
		std::cout << "Copy Array Size: " << copyArray.size() << std::endl;
		std::cout << "Copy Array Elements:" << std::endl;
		for (unsigned int i = 0; i < copyArray.size(); ++i)
		{
			std::cout << copyArray[i] << " ";
		}
		std::cout << std::endl;
		// Attempt to access an out-of-bounds element
		std::cout << copyArray[56] << std::endl;
	}
	catch (const std::exception &ex)
	{
		std::cerr << "Exception: " << ex.what() << std::endl;
	}

	return 0;
}
