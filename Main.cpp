#include <iostream>
using namespace std;

#include "LinkedList.h"

int main(int argc, char *argv[])
{
    LinkedList oList;
    oList.add(42);
    oList.add(15);
    cout << "size = " << oList.size() << endl;
    oList.add(14);
    oList.add(29);
    oList.print();
    cout << oList.get(4) << endl;
    return 0;
}
