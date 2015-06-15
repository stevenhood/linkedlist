#include <limits> // numeric_limits
#include <iostream>

#include "LinkedList.h"

void PrintOptions(void)
{
    std::cout << "Options:\n"
        << "1: Add\n"
        << "2: Add (to index)\n"
        << "3: AddHead\n"
        << "4: AddTail\n"
        << "s: Size\n"
        << "p: Print\n"
        << "q: Quit" << std::endl;
}

// http://stackoverflow.com/questions/14613243/a-call-to-stdcin-does-not-block
template <typename T>
T* GetInput(T *tVal, std::string strPrompt)
{
    std::cout << strPrompt;
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
    int iInput, iIndex;
    bool bInvalid = false;
    bool bRunning = true;

    PrintOptions();

    while (bRunning) {
        GetInput(&cOption, "Enter option > ");

        switch (cOption) {
            case '1':
                GetInput(&iInput, "Add value > ");
                oList.Add(iInput);
                break;
            case '2':
                GetInput(&iInput, "Add value > ");
                GetInput(&iIndex, "Index > ");
                oList.Add(iIndex, iInput);
                break;
            case '3':
                GetInput(&iInput, "Add value > ");
                oList.AddHead(iInput);
                break;
            case '4':
                GetInput(&iInput, "Add value > ");
                oList.AddTail(iInput);
                break;
            case 's':
            case 'S':
                std::cout << "Size: " << oList.Size() << std::endl;
                break;
            case 'p':
            case 'P':
                std::cout << "List:" << std::endl;
                oList.Print();
                break;
            case 'q':
            case 'Q':
                std::cout << "Quitting..." << std::endl;
                bRunning = false;
                break;
            default:
                std::cout << "Invalid option" << std::endl;
                PrintOptions();
                bInvalid = true;
                break;
        }

        if (bInvalid) {
            bInvalid = false;
            continue;
        }
    }

    return 0;
}
