#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX 100000

char stack[MAX];
int top = -1;

// Push operation
void push(char c) {
    stack[++top] = c;
}

// Pop operation
char pop() {
    if (top == -1)
        return '\0';
    return stack[top--];
}

// Check if matching pair
bool isMatchingPair(char open, char close) {
    if (open == '(' && close == ')') return true;
    if (open == '{' && close == '}') return true;
    if (open == '[' && close == ']') return true;
    return false;
}

// Check balanced brackets
bool isBalanced(char* s) {
    for (int i = 0; s[i] != '\0'; i++) {
        
        // If opening bracket → push
        if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
            push(s[i]);
        }
        // If closing bracket → check
        else if (s[i] == ')' || s[i] == '}' || s[i] == ']') {
            if (top == -1)
                return false;

            char popped = pop();
            if (!isMatchingPair(popped, s[i]))
                return false;
        }
    }

    return (top == -1);
}

int main() {
    char s[MAX];

    scanf("%s", s);

    if (isBalanced(s))
        printf("true");
    else
        printf("false");

    return 0;
}