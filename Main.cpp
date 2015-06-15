#include <iostream>
using namespace std;

#include "LinkedList.h"

int main(int argc, char *argv[])
{
    LinkedList oList;
    cout << "head = " << oList.getHead() << endl;
    oList.add(42);
    oList.add(15);
    oList.add(14);
    oList.add(29);
    oList.print();
    cout << oList.get(4) << endl;
    return 0;
}
