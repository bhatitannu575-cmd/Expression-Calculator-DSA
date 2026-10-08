# Expression Calculator using C++ and DSA

A simple **Expression Calculator** developed in C++ using the **Stack data structure**.

## Features

- Converts an infix expression into postfix notation.
- Evaluates the postfix expression using a stack.
- Supports:
  - Addition `+`
  - Subtraction `-`
  - Multiplication `*`
  - Division `/`
  - Modulo `%`
  - Parentheses `( )`
- Handles spaces in expressions.
- Checks division/modulo by zero.
- Supports decimal numbers.

## Example

### Input
```text
(10 + 5) * 2
```

### Output
```text
Postfix Expression: 10 5 + 2 *
Result: 30
```

## DSA Concepts Used

### 1. Stack
A stack follows the **LIFO (Last In, First Out)** principle.

It is used for:
- Storing operators during infix-to-postfix conversion.
- Storing operands while evaluating the postfix expression.

### 2. Infix Expression
The normal mathematical form:

```text
(10 + 5) * 2
```

### 3. Postfix Expression
The converted form:

```text
10 5 + 2 *
```

## Algorithm

### Infix to Postfix

1. Read the expression from left to right.
2. If the character is a number, add it to the postfix expression.
3. If it is `(`, push it into the stack.
4. If it is `)`, pop operators until `(` is found.
5. If it is an operator, pop operators having higher or equal precedence and then push the current operator.
6. Pop all remaining operators.

### Postfix Evaluation

1. Read the postfix expression from left to right.
2. Push numbers into the stack.
3. When an operator is found, pop two values.
4. Apply the operator.
5. Push the result back into the stack.
6. The final stack value is the answer.

## Time Complexity

For an expression containing `n` tokens:

- Infix to Postfix: **O(n)**
- Postfix Evaluation: **O(n)**
- Space Complexity: **O(n)**

## How to Run

### Using g++

```bash
g++ main.cpp -o calculator
```

Then:

```bash
./calculator
```

On Windows:

```bash
calculator.exe
```

## Sample Output

```text
=====================================
       EXPRESSION CALCULATOR
       DSA - STACK PROJECT
=====================================
Operators: +  -  *  /  %
Use parentheses when required.

Enter expression: (10+5)*2

Postfix Expression: 10 5 + 2 *
Result: 30
```

## Author

Tannu Bhati
