//https://www.naukri.com/code360/problems/day-23-:-infix-to-postfix-_1382146

#include <bits/stdc++.h>
using namespace std;

// Function to get precedence of operators
int precedence(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/' || c == '%') return 2;
    if (c == '+' || c == '-') return 1;
    return 0;
}

// Function to check if a character is an operator
bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^' || c == '%';
}

// Function to convert infix expression to postfix
string infixToPostfix(string exp) {
    stack<char> st;
    string output;

    for (char c : exp) {
        if (isalnum(c)) {
            output += c; // Append operand to output
        } else if (c == '(') {
            st.push(c);
        } else if (c == ')') {
            while (!st.empty() && st.top() != '(') {
                output += st.top();
                st.pop();
            }
            if (!st.empty()) st.pop(); // Remove '('
        } else if (isOperator(c)) {
            while (!st.empty() && precedence(st.top()) >= precedence(c)) {
                output += st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    while (!st.empty()) {
        output += st.top();
        st.pop();
    }

    return output;
}