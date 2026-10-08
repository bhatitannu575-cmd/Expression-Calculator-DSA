#include <iostream>
#include <stack>
#include <string>
#include <sstream>
#include <cctype>
#include <cmath>
using namespace std;

// Check whether a character is an operator
bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '%';
}

// Return operator precedence
int precedence(char c) {
    if (c == '+' || c == '-') return 1;
    if (c == '*' || c == '/' || c == '%') return 2;
    return 0;
}

// Convert infix expression to postfix using Stack
string infixToPostfix(const string& expression) {
    stack<char> operators;
    string postfix;

    for (size_t i = 0; i < expression.length(); i++) {
        char c = expression[i];

        if (isspace(c))
            continue;

        // Read a complete number
        if (isdigit(c) || c == '.') {
            while (i < expression.length() &&
                   (isdigit(expression[i]) || expression[i] == '.')) {
                postfix += expression[i];
                i++;
            }
            postfix += ' ';
            i--;
        }
        else if (c == '(') {
            operators.push(c);
        }
        else if (c == ')') {
            while (!operators.empty() && operators.top() != '(') {
                postfix += operators.top();
                postfix += ' ';
                operators.pop();
            }

            if (!operators.empty())
                operators.pop();
        }
        else if (isOperator(c)) {
            while (!operators.empty() &&
                   operators.top() != '(' &&
                   precedence(operators.top()) >= precedence(c)) {
                postfix += operators.top();
                postfix += ' ';
                operators.pop();
            }
            operators.push(c);
        }
    }

    while (!operators.empty()) {
        postfix += operators.top();
        postfix += ' ';
        operators.pop();
    }

    return postfix;
}

// Evaluate postfix expression using Stack
double evaluatePostfix(const string& postfix) {
    stack<double> values;
    stringstream ss(postfix);
    string token;

    while (ss >> token) {
        if (isdigit(token[0]) || token[0] == '.') {
            values.push(stod(token));
        }
        else if (token.length() == 1 && isOperator(token[0])) {
            if (values.size() < 2)
                throw runtime_error("Invalid expression.");

            double b = values.top();
            values.pop();

            double a = values.top();
            values.pop();

            switch (token[0]) {
                case '+': values.push(a + b); break;
                case '-': values.push(a - b); break;
                case '*': values.push(a * b); break;
                case '/':
                    if (b == 0)
                        throw runtime_error("Division by zero is not allowed.");
                    values.push(a / b);
                    break;
                case '%':
                    if (b == 0)
                        throw runtime_error("Modulo by zero is not allowed.");
                    values.push(fmod(a, b));
                    break;
            }
        }
        else {
            throw runtime_error("Invalid expression.");
        }
    }

    if (values.size() != 1)
        throw runtime_error("Invalid expression.");

    return values.top();
}

int main() {
    string expression;

    cout << "=====================================\n";
    cout << "       EXPRESSION CALCULATOR\n";
    cout << "       DSA - STACK PROJECT\n";
    cout << "=====================================\n";
    cout << "Operators: +  -  *  /  %\n";
    cout << "Use parentheses when required.\n\n";

    cout << "Enter expression: ";
    getline(cin, expression);

    try {
        string postfix = infixToPostfix(expression);
        double result = evaluatePostfix(postfix);

        cout << "\nPostfix Expression: " << postfix << endl;
        cout << "Result: " << result << endl;
    }
    catch (const exception& e) {
        cout << "\nError: " << e.what() << endl;
    }

    return 0;
}
