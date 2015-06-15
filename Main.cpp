#include <iostream>
using namespace std;

#include "LinkedList.h"

int main(int argc, char *argv[])
{
    LinkedList list;
    list.add(42);
    list.add(15);
    list.add(14);
    list.add(29);
    list.print();
    return 0;
}
