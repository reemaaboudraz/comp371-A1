/**
 * Aboudraz, Reema - 40253549
 *      
 *
 * Assignment 1, COMP 371 
 * Summer 2026
 * Professor Nagi Basha
 */


#include <iostream>
#include <limits>
#include <new>


int* createArray(const int size)
{
    if (size <= 0)
    {
        return nullptr;
    }

    try
    {
        return new int[size];
    }
    catch (const std::bad_alloc&)
    {
        return nullptr;
    }
}

/**
 * Initializes an array with values from 0 to size - 1.
 *
 * @param array Pointer to the array.
 * @param size Number of elements in the array.
 */
void initializeArray(int* const array, const int size)
{
    if (array == nullptr || size <= 0)
    {
        return;
    }

    for (int index = 0; index < size; ++index)
    {
        array[index] = index;
    }
}

/**
 * Prints all elements of an array.
 *
 * @param array Pointer to the array.
 * @param size Number of elements in the array.
 */
void printArray(const int* const array, const int size)
{
    if (array == nullptr || size <= 0)
    {
        std::cout << "The array is empty.\n";
        return;
    }

    std::cout << "Array elements: [";

    for (int index = 0; index < size; ++index)
    {
        std::cout << array[index];

        if (index < size - 1)
        {
            std::cout << ", ";
        }
    }

    std::cout << "]\n";
}

/**
 * Deallocates a dynamically allocated array.
 *
 * The pointer is passed by reference so it can be set to nullptr after
 * deletion, preventing accidental reuse of a dangling pointer.
 *
 * @param array Reference to the pointer that owns the array.
 */
void deleteArray(int*& array)
{
    delete[] array;
    array = nullptr;
}

/**
 * Reads and validates a positive array size from the user.
 *
 * @return A positive integer representing the requested array size.
 */
int readArraySize()
{
    int size = 0;

    while (true)
    {
        std::cout << "Enter the size of the array: ";

        if (std::cin >> size && size > 0)
        {
            return size;
        }

        std::cout << "Invalid input. Please enter a positive integer.\n";

        std::cin.clear();
        std::cin.ignore(
            std::numeric_limits<std::streamsize>::max(),
            '\n'
        );
    }
}

int main()
{
    const int size = readArraySize();

    int* array = createArray(size);

    if (array == nullptr)
    {
        std::cerr << "Error: unable to allocate memory for the array.\n";
        return 1;
    }

    initializeArray(array, size);
    printArray(array, size);
    deleteArray(array);

    std::cout << "The dynamically allocated memory was successfully released.\n";

    return 0;
}
