
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

// For NULL
#include <cstddef>

#include "stack.h"
using namespace std;

 TEST_CASE("empty Stack") {
     Stack *emptyStack = new Stack();
     SECTION("Empty stack") {
         CHECK(emptyStack->empty() == true);
     }
     SECTION("Print stack") {
         CHECK(emptyStack->print() == "");
     }
     SECTION("Print size") {
         CHECK(emptyStack->size() == 0);
     }
     SECTION("Pop head") {
         CHECK(emptyStack->pop() == "!@*$#%");
     }
 }

TEST_CASE("stack w/ values") {
    Stack *stack = new Stack();
    stack->push("3");
    stack->push("2");
    stack->push("8");
    
    SECTION("Print at certain index") {
        cout << "2: " << stack->at(2) << endl;
        CHECK(stack->at(0) == "8");
    }
      
    SECTION("Print at out of range") {
        CHECK(stack->at(3) == "ERROR");
    } 
    
    SECTION("Push multiple") {
        CHECK(stack->print() == "8 2 3 ");
    }

    SECTION("Print size") {
        CHECK(stack->size() == 3);
    }
    stack->pop();
    SECTION("Pop") {
        CHECK(stack->print() == "2 3 ");
    }
}
