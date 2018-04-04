#define CATCH_CONFIG_MAIN
#include "catch.hpp"

// For NULL
#include <cstddef>
// To test for correct header guards
#include "stack.h"

TEST_CASE("End") {
    Stack emptyStack;
    SECTION("Empty stack") {
        CHECK(emptyStack.empty() == true);
    }
    SECTION("Print stack") {
        CHECK(emptyStack.print() == "");
    }
    SECTION("Print size") {
        CHECK(emptyStack.size() == 0);
    }
    SECTION("Pop head") {
        CHECK(emptyStack.pop() == "!@*$#%");
    }
}

TEST_CASE("stack with values") {
    Stack *stack = new Stack();
    stack->push("3");
    stack->push("2");
    stack->push("8");
    
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