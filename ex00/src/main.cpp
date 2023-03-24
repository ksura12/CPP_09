/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksura <ksura@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 11:09:08 by ksura             #+#    #+#             */
/*   Updated: 2023/03/24 15:02:59 by ksura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <map>
#include <time.h>
#include <stdio.h>
#include <ctime>
#include <cstdlib>

int main(void)
{
    const char* filename = "src/data.csv";

    std::ifstream datafile(filename);

    std::map<std::time_t, float> datamap;

    std::string format = "%Y-%m-%d";
    // char *strptime(const char *s, const char *format, struct tm *tm);
    
    if(datafile.is_open()){
        //read file line by line
        std::string line;
        int linecount = 0;
        while (std::getline(datafile, line)) {
            //splitting line at comma
            if (linecount == 0)
                continue;
            std::stringstream ssline(line);
            std::string element;
            int i = 0;
            struct tm tm;
            float value = -1;
            while (std::getline(ssline, element, ','))
            {
                if(i == 0)
                {
                    strptime(element.c_str(), "%Y-%m-%d", &tm);
                }
                else
                    value = atof(element.c_str());

                
                std::cout << element << std::endl;
                i++;
            }
            if (value != -1)
                datamap.insert(std::pair<time_t, float>(mktime(&tm),value));
            
            //printing map
            std::map<std::time_t, float>::iterator it;
            std::cout << "Map Content:" <<std:: endl;
            for (it = datamap.begin(); it != datamap.end(); it++)
                std::cout << it->first << "---" << it->second << std::endl;
            linecount++;
            if (linecount == 3)
                break;
        }
    } 
    else {
        std::cout << "ERROR: Could not read Data.csv" << std::endl;
        return 1;
    }
    datafile.close();
}