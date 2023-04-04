/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksura <ksura@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 11:00:03 by ksura             #+#    #+#             */
/*   Updated: 2023/04/04 14:36:38 by ksura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef BITCOINEXCHANGE_HPP
 #define BITCOINEXCHANGE_HPP
 
#include <iostream>
#include <cstring>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <map>
#include <time.h>
#include <stdio.h>
#include <ctime>
#include <cstdlib>
#include <iomanip> 

class BitcoinExchange
{
private:
    std::map<std::time_t, float> datamap;
    std::string filename;
    
public:
    BitcoinExchange(char ** argv);
    BitcoinExchange(BitcoinExchange const & input);
	BitcoinExchange & operator=(BitcoinExchange const & input);
    ~BitcoinExchange();
    
    int input_check();
    int read_csv_file();
    int read_txt_file();
};

#endif
