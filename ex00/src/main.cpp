/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksura <ksura@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 11:09:08 by ksura             #+#    #+#             */
/*   Updated: 2023/04/04 15:14:42 by ksura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/BitcoinExchange.hpp"

int main(int argc, char ** argv)
{
    if (argc != 2)
    {
        std::cout << "Check the Syntax: \"./btc inputfile.txt\"" << std::endl;
        return (1);
    }
    BitcoinExchange ValueCalc(argv);
    if (ValueCalc.input_check())
        return (1);
    if (ValueCalc.read_csv_file())
        return (1);
    if (ValueCalc.read_txt_file())
        return (1);
    return (0);
}