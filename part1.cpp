/**
 * Reema Aboudraz - 40253549
 * Wissem Oumsalem - 40291712  
 * Omar El Akrae   - 40252799
 * Assignment 1, COMP 371 
 * Summer 2026
 * Professor Nagi Basha
 */


#include <iostream>
#include <limits>
#include <new>
#include <string>

namespace
{
    constexpr int SUCCESS = 0;
    constexpr int FAILURE = 1;

    void printSeparator()
    {
        std::cout << "============================================================\n";
    }

    void displayProjectHeader()
    {
        printSeparator();
        std::cout << "                 COMP 371 - COMPUTER GRAPHICS\n";
        std::cout << "                       ASSIGNMENT 1\n";
        std::cout << "                         PART 1\n";
        printSeparator();

        std::cout << "Submitted by:\n";
        std::cout << "  1. Aboudraz, Reema      - 40253549\n";
        std::cout << "  2. Wissem Oumsalem      - 40291712\n";
        std::cout << "  3. Omar El Akrae        - 40252799\n";

        printSeparator();
        std::cout << "Dynamic Array Creation and Memory Management Program\n";
        printSeparator();
        std::cout << '\n';
    }

    /**
     * Reads a positive integer from the user.
     *
     * @return A valid positive integer representing the array size.
     */
    int readArraySize()
    {
        int size = 0;

        while (true)
        {
            std::cout << "Enter the number of elements for the array: ";

            if (std::cin >> size && size > 0)
            {
                return size;
            }

            std::cout << "\nInvalid input.\n";
            std::cout << "Please enter a positive whole number.\n\n";

            std::cin.clear();
            std::cin.ignore(
                std::numeric_limits<std::streamsize>::max(),
                '\n'
            );
        }
    }

    /**
     * Reads the user's choice to repeat or exit.
     *
     * @return 'y' to create another array or 'n' to exit.
     */
    char readContinueChoice()
    {
        char choice = '\0';

        while (true)
        {
            std::cout << "\nWould you like to create another array?\n";
            std::cout << "  [Y] Yes, create another array\n";
            std::cout << "  [N] No, end the program\n";
            std::cout << "Enter your choice: ";

            if (std::cin >> choice)
            {
                if (choice == 'y' || choice == 'Y')
                {
                    return 'y';
                }

                if (choice == 'n' || choice == 'N')
                {
                    return 'n';
                }
            }

            std::cout << "\nInvalid choice. Please enter Y or N.\n";

            std::cin.clear();
            std::cin.ignore(
                std::numeric_limits<std::streamsize>::max(),
                '\n'
            );
        }
    }
}

/**
 * Dynamically allocates an integer array.
 *
 * @param size Number of elements to allocate.
 * @return Pointer to the allocated array, or nullptr if allocation fails.
 *
 * The caller owns the returned memory and must release it using
 * deleteArray().
 */
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
 * Initializes the array with values from 0 to size - 1.
 *
 * @param array Pointer to the dynamically allocated array.
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
 * Displays all values stored in the array.
 *
 * @param array Pointer to the array.
 * @param size Number of elements in the array.
 */
void printArray(const int* const array, const int size)
{
    if (array == nullptr || size <= 0)
    {
        std::cout << "The array is empty and cannot be displayed.\n";
        return;
    }

    std::cout << "Here is the array:\n\n";
    std::cout << "  [";

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
 * Releases the memory occupied by the dynamically allocated array.
 *
 * @param array Reference to the array pointer. The pointer is set to
 *              nullptr after deletion to prevent dangling-pointer access.
 */
void deleteArray(int*& array)
{
    delete[] array;
    array = nullptr;
}

int main()
{
    displayProjectHeader();

    bool programIsRunning = true;

    while (programIsRunning)
    {
        std::cout << "ARRAY CREATION\n";
        printSeparator();

        const int size = readArraySize();

        std::cout << "\nCreating a dynamic array containing "
                  << size << " element";

        if (size != 1)
        {
            std::cout << 's';
        }

        std::cout << "...\n";

        int* array = createArray(size);

        if (array == nullptr)
        {
            std::cerr << "\nError: The program was unable to allocate memory "
                      << "for the array.\n";
            return FAILURE;
        }

        std::cout << "Array successfully created.\n";

        std::cout << "\nInitializing the array with values from 0 to "
                  << size - 1 << "...\n";

        initializeArray(array, size);

        std::cout << "Array successfully initialized.\n\n";

        printArray(array, size);

        std::cout << "\nThe array is no longer needed.\n";
        std::cout << "Deleting the array and releasing its memory...\n";

        deleteArray(array);

        if (array == nullptr)
        {
            std::cout << "Memory successfully deleted and released.\n";
        }

        printSeparator();

        const char choice = readContinueChoice();

        if (choice == 'n')
        {
            programIsRunning = false;
        }
        else
        {
            std::cout << "\nStarting a new array operation...\n\n";
            printSeparator();
        }
    }

    std::cout << '\n';
    printSeparator();
    std::cout << "Thank you for using our dynamic array program.\n";
    std::cout << "COMP 371 Assignment 1 - Part 1 completed successfully.\n";
    printSeparator();

    return SUCCESS;
}