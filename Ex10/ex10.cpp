#include <iostream>
#include <stack>
#include <sstream>
#include <string>

double evaluate(const std::string& expression) {
    std::stack<double> operands;
    std::stack<char> operations;

    std::stringstream ss(expression);
    std::string token;
    while (ss >> token) {
        if (token == "(") {
            // Ignore left parenthesis
        } else if (token == "+" || token == "-" || token == "*" || token == "/") {
            // Push operation onto the stack
            operations.push(token[0]);
        } else if (token == ")") {
            // Pop an operation and the required number of operands,
            // evaluate the operation, and push the result back onto the stack
            double operand2 = operands.top();
            operands.pop();
            double operand1 = operands.top();
            operands.pop();

            char operation = operations.top();
            operations.pop();

            double result;
            switch (operation) {
                case '+':
                    result = operand1 + operand2;
                    break;
                case '-':
                    result = operand1 - operand2;
                    break;
                case '*':
                    result = operand1 * operand2;
                    break;
                case '/':
                    result = operand1 / operand2;
                    break;
            }

            operands.push(result);
        } else {
            // Push operand onto the stack
            double operand = std::stod(token);
            operands.push(operand);
        }
    }

    // The final result is the top element of the operands stack
    return operands.top();
}

int main() {
    std::string expression = "( 1 + ( 2 + 3 ) )";
    double result = evaluate(expression);
    std::cout << "Result: " << result << std::endl;

    return 0;
}