/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksura <ksura@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 11:09:08 by ksura             #+#    #+#             */
/*   Updated: 2023/04/19 13:34:11 by ksura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/PmergeMe.hpp"

int main(int argc, char ** argv)
{
    if (argc < 2)
    {
        std::cout << "Check the Syntax: \"./PmergeMe 5 4 1 ...\"" 
        << std::endl;
        return (1);
    }
    PmergeMe function(argc, argv);
    // std::cout << "Check the Syntax: \"./PmergeMe 5 4 1 ...\"" 
    //     << std::endl;
    function.run();
    
    return (0);
}