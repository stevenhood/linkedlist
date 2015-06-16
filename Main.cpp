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
        << "5: Get\n"
        << "6: GetHead\n"
        << "7: GetTail\n"
        << "8: Remove\n"
        << "c: Clear\n"
        << "p: Print\n"
        << "s: Size\n"
        << "q: Quit"
        << std::endl;
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
    int iInput, iIndex, iValue;
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
            case '5':
                GetInput(&iIndex, "Index > ");
                std::cout << iIndex << ": " << oList.Get(iIndex) << std::endl;
                break;
            case '6':
                std::cout << "Head: " << oList.GetHead() << std::endl;
                break;
            case '7':
                std::cout << "Tail: " << oList.GetTail() << std::endl;
                break;
            case '8':
                iValue = oList.Remove();
                std::cout << "Removed " << iValue << std::endl;
                break;
            case 'c':
            case 'C':
                oList.Clear();
                std::cout << "List cleared." << std::endl;
                break;
            case 'p':
            case 'P':
                std::cout << "List:" << std::endl;
                oList.Print();
                break;
            case 's':
            case 'S':
                std::cout << "Size: " << oList.Size() << std::endl;
                break;
            case 'q':
            case 'Q':
                std::cout << "Quitting..." << std::endl;
                bRunning = false;
                break;
            default:
                std::cout << "Invalid option" << std::endl;
                PrintOptions();
                break;
        }
    }

    return 0;
}
