#include <limits> // numeric_limits
#include <iostream>

#include "LinkedList.h"

// http://stackoverflow.com/questions/14613243/a-call-to-stdcin-does-not-block
template <typename T>
T* getInput(T *tVal)
{
    // Check if operation failed
    if (!(std::cin >> *tVal)) {
        std::cout << "Invalid input" << std::endl;
        std::cin.clear(); // Reset stream
        // Ignore rest of line
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    return tVal;
}

int main(int argc, char *argv[])
{
    LinkedList oList;
    char cOption;
    int iInput;
    bool bInvalid = false;
    bool bRunning = true;

    std::cout << "Options:" << std::endl
         << "1 : add" << std::endl
         << "2 : add-index" << std::endl
         << "3: addHead" << std::endl
         << "4: addTail" << std::endl
         << "q: Quit" << std::endl;

    while (bRunning) {
        std::cout << "Enter option > ";
        getInput(&cOption);
        std::cout << "Add item > ";
        getInput(&iInput);

        switch (cOption) {
            case '1':
                oList.add(iInput);
                break;
            case '2':
                int iIndex;
                std::cout << "Index > ";
                getInput(&iIndex);
                oList.add(iIndex, iInput);
                break;
            case '3':
                oList.addHead(iInput);
                break;
            case '4':
                oList.addTail(iInput);
                break;
            case 'q':
            case 'Q':
                std::cout << "Quitting..." << std::endl;
                bRunning = false;
                break;
            default:
                std::cout << "Invalid option" << std::endl;
                bInvalid = true;
                break;
        }

        if (bInvalid) {
            bInvalid = false;
            continue;
        }
        std::cout << oList.size() << std::endl;
        oList.print();
    }

    return 0;
}
