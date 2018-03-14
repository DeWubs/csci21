#include <cstdlib>
#include "List.h"
using namespace std;
int main(){
    List Robert;
    Robert.addNode(15);
    Robert.addNode(55);
    Robert.addNode(11);
    Robert.printList();
    return 0;
}