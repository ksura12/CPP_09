/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksura <ksura@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 15:59:21 by ksura             #+#    #+#             */
/*   Updated: 2023/04/04 19:53:18 by ksura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/RPN.hpp"

RPN::RPN(char ** argv)
{
    input = argv[1];
}

RPN::RPN(RPN const & other)
{
    input = other.input;
    stack = other.stack;
}

RPN & RPN::operator=(RPN const & other)
{
    if (this != &other)
    {
        input = other.input;
        stack = other.stack;
    }
    return (*this);
}

RPN::~RPN()
{}

int RPN::calculating()
{
    int i = 0;
    while (input[i] != '\0')
    {
        if (input[i] == ' ')
        {
            i++;
            continue;
        }
        if (isdigit(input[i])) {
            // Converting char * to double an pushing it on stack
            double num = atof(input.substr(i, 1).c_str());
            stack.push(num);
        }
        else {
            if (stack.empty())
            {
                std::cout << "Please enter operands" << std::endl;
                return (1);
            }
            // Input is an operator
            double operand2 = stack.top();
            stack.pop();
            double operand1 = stack.top();
            stack.pop();
            if (input[i] == '+')
                stack.push(operand1 + operand2);
            else if (input[i] == '-')
                stack.push(operand1 - operand2);
            else if (input[i] == '*')
                stack.push(operand1 * operand2);
            else if (input[i] == '/')
                stack.push(operand1 / operand2);
            else
            {
                std::cout << "Invalid operator\n";
                return (1);
            }    
        }
        i++;
    }
    if (!stack.empty())
    {
        std::cout << stack.top() << std::endl;
        return (0); 
    }
    else
    {
        std::cout << "Please enter operands" << std::endl;
        return (1);
    }
    return (0);
    
}
