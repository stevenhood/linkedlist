#include <iostream>
using namespace std;

#include "LinkedList.h"

int main(int argc, char *argv[])
{
    LinkedList oList;
    oList.add(42);
    oList.add(15);
    oList.add(14);
    oList.add(29);
    oList.print();
    cout << oList.getAt(4) << endl;
    return 0;
}
