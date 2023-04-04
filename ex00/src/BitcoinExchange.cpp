/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksura <ksura@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 11:14:21 by ksura             #+#    #+#             */
/*   Updated: 2023/04/04 15:30:58 by ksura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(char ** argv)
{ 
    filename = argv[1];
}

BitcoinExchange::~BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const & input)
{
    filename = input.filename;
    datamap = input.datamap;
}

BitcoinExchange & BitcoinExchange::operator=(BitcoinExchange const & input)
{
    if (this != &input)
    {
        filename = input.filename;
        datamap = input.datamap;
    }
    return (*this);
}

int BitcoinExchange::read_csv_file()
{
    const char* csv_file = "src/data.csv";
    std::ifstream datafile(csv_file);
    std::string format = "%Y-%m-%d";  
    if(datafile.is_open()) {
        //read file line by line
        std::string line;
        int linecount = -1;
        while (std::getline(datafile, line)) {
            //splitting line at comma
            linecount++;
            if (linecount == 0)
                continue;
            std::stringstream ssline(line);
            std::string element;
            int i = 0;
            struct tm tm_struct = {};
            float value = -1;
            while (std::getline(ssline, element, ',')) {
                if(i == 0)
                {
                    if(!strptime(element.c_str(), "%Y-%m-%d", &tm_struct))
                    {
                        std::cout << "Error: Failed to parse date string " << element << std::endl;
                        break; 
                    }
                }
                else
                    value = atof(element.c_str());
                i++;
            }
            if (value != -1)
                datamap.insert(std::pair<time_t, float>(timegm(&tm_struct),value));
        }
    } 
    else {
        std::cout << "ERROR: Could not read Data.csv" << std::endl;
        return (1);
    }
    datafile.close();
    return  (0);
}

int BitcoinExchange::read_txt_file()
{
    std::ifstream txtfile(filename.c_str());
    std::string format = "%Y-%m-%d";
    if(txtfile.is_open()){
        std::string line;
        int linecount = -1;
        while (std::getline(txtfile, line)) {
            //splitting line at pipe
            linecount++;
            if (linecount == 0)
                continue;
            std::stringstream ssline(line);
            std::string element;
            int i = 0;
            int processed = 0;
            struct tm tm_struct = {};
            float value = -1;
            while (std::getline(ssline, element, '|')){
                //cutting leading and following spaces and tabs
                int leading = 0;
                int following = element.length();
                while(element[leading] == ' ' || element[leading] == '\t')
                    leading++;
                while(element[following] == ' ' || element[following] == '\t')
                    leading--;
                element = element.substr(leading, following - leading);
                if(i == 0){
                    if(!strptime(element.c_str(), "%Y-%m-%d", &tm_struct))
                    {
                        std::cout << "Error: Failed to parse date string " 
                        << element << std::endl;
                        processed = 1;
                        break; 
                    }
                }
                else{
                    value = atof(element.c_str());
                    if (value > 1000 || value < 0)
                    {
                        std::cout << "Error: Bitcoin Value not between 0-1000" << std::endl;
                        value = -1;
                        break;
                    }
                }   
                i++;
            }
            // comparing of timestamps
            if (value != -1){
                std::map<std::time_t, float>::iterator iter;
                iter = datamap.lower_bound(timegm(&tm_struct));
                if ((datamap.begin()->first > timegm(&tm_struct)) && processed == 0)
                    {
                        char buf[80];
                        std::strftime(buf, sizeof(buf), "%Y-%m-%d", &tm_struct);
                        std::cout << "Error: No Bitcoin Value before this date: " << buf << std::endl;
                        processed = 1;
                    }
                else if ((--datamap.end())->first < timegm(&tm_struct)){
                    iter = datamap.end();
                    iter--;
                }
                else if ((iter->first != timegm(&tm_struct)) && (datamap.end() != iter) && processed == 0)          
                    iter--;
                // calculating result of Amount * Value
                if (processed == 0){
                    float result = value * iter->second;
                    char buf[80];
                    std::strftime(buf, sizeof(buf), "%Y-%m-%d", &tm_struct);
                    std::cout << buf << " => " << std::fixed << std::setprecision(2)
                    << value  << " * " << iter->second 
                    << " = " <<  result << std::endl;
                }
            }
        }
    } 
    else {
        std::cout << "ERROR: Could not read input.txt" << std::endl;
        return (1);
    }
    txtfile.close();
    return  (0);
}

int BitcoinExchange::input_check()
{
    size_t len = filename.length();
    if (strncmp(&filename[len - 4], ".txt", 4) != 0)
    {
        std::cout << "ERROR: Please use a .txt file as input" << std::endl;
        return (1);
    }
    return (0);
}