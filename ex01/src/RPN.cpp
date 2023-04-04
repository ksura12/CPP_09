/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksura <ksura@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 15:59:21 by ksura             #+#    #+#             */
/*   Updated: 2023/04/04 16:38:10 by ksura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/RPN.hpp"

RPN::RPN(char ** argv)
{
    input = argv;
}

RPN::RPN(RPN const & other)
{
    input = other.input;
    stack = other.stack
}

RPN & RPN::operator=(RPN const & other)
{
    if (this != &other)
    {
        input = other.input;
        stack = other.stack;
    }
    
}

RPN::~RPN()
{}

int RPN::calculating()
{
    int i = 1;
    while (input[i] != '\0')
    {
        if (isdigit(input[i][0])) {
            double num = std::stod(input[i]);
            stack.push(num);
        }
        else {
            
        }
    }
    
}


// int main()
// {
//     while (std::cin >> input && input != "q") {
//         if (isdigit(input[0])) {
//             // Convert input to double and push onto stack
//             double num = std::stod(input);
//             s.push(num);
//         }
//         else {
//             // Input is an operator, pop two operands and perform operation
//             double operand2 = s.top(); s.pop();
//             double operand1 = s.top(); s.pop();

//             if (input == "+") s.push(operand1 + operand2);
//             else if (input == "-") s.push(operand1 - operand2);
//             else if (input == "*") s.push(operand1 * operand2);
//             else if (input == "/") s.push(operand1 / operand2);
//             else std::cout << "Invalid operator\n";
//         }
//     }

//     if (!s.empty()) {
//         std::cout << "Result: " << s.top() << '\n';
//     }
//     else {
//         std::cout << "No operands entered\n";
//     }

//     return 0;
// }