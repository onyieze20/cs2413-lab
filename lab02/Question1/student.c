// Question1/Student.c
// ------------------------------------------------------------
// CS Lab - Valid Parentheses (STACK PRACTICE)
//
// Task:
// Implement `isValid(const char *s)`.
// Given a string s containing only: () {} []
// return true if it is a valid parentheses string, else false.
//
// Valid rules:
// 1) Open brackets must be closed by the same type of brackets.
// 2) Open brackets must be closed in the correct order.
// 3) Every close bracket has a corresponding open bracket.
//
// Examples:
//   s = "()"        -> true
//   s = "()[]{}"    -> true
//   s = "(]"        -> false
//   s = "([)]"      -> false
//   s = "{[]}"      -> true
//   s = ""          -> true   (empty string is valid)
//
// How to run tests (from the folder containing the Makefile):
//   make run1
// ------------------------------------------------------------

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

static bool is_open(char c) {
    return (c == '(' || c == '[' || c == '{');
}

static bool matches(char open, char close) {
    return (open == '(' && close == ')') ||
        (open == '[' && close == ']') ||
        (open == '{' && close == '}');
}

bool isValid(const char* s) {
    if (s == NULL) return true; // or false depending on your lab's expectations

    size_t n = strlen(s);
    char* stack = (char*)malloc(n);   // stack capacity = n
    if (!stack) return false;

    size_t top = 0; // number of items in stack

    for (size_t i = 0; i < n; i++) {
        char c = s[i];

        if (is_open(c)) {
            stack[top++] = c; // push
        }
        else {
            // closing bracket: stack must not be empty
            if (top == 0) {
                free(stack);
                return false;
            }
            char open = stack[top - 1]; // peek
            if (!matches(open, c)) {
                free(stack);
                return false;
            }
            top--; // pop
        }
    }

    bool ok = (top == 0);
    free(stack);
    return ok;
}
