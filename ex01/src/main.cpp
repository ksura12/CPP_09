/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksura <ksura@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 11:09:08 by ksura             #+#    #+#             */
/*   Updated: 2023/04/04 19:54:05 by ksura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/RPN.hpp"

int main(int argc, char ** argv)
{
    if (argc != 2)
    {
        std::cout << "Check the Syntax: \"./RPN \"1 1 + 2 *...\"\"" 
        << std::endl;
        return (1);
    }
    RPN function(argv);
    if(function.calculating())
        return (1);
    return (0);
}