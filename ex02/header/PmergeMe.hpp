/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksura <ksura@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 14:13:45 by ksura             #+#    #+#             */
/*   Updated: 2023/04/28 13:46:16 by ksura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
 #define PMERGEME_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <list>
#include <ctime>
#include <algorithm>
#include <cstdlib>

class PmergeMe
{
private:
    std::vector<long int> parse_input_vector(int argc, char ** argv);
    std::list<long int> parse_input_list(int argc, char ** argv);
    
    
    // void display() const;
    // void displayTime(const std::string& containerName, clock_t time) const;
    
    // void print_vector(const std::vector<int>& v);
    // void print_time_diff(std::chrono::high_resolution_clock::time_point t1, std::chrono::high_resolution_clock::time_point t2);
    
    
    // void    devide_container(std::vector<int>& v);
    // void    devide_container(std::list<int>& l);
    void    insertion_sort(std::vector<long int>& nums, int start, int end);
    void    insertion_sort(std::list<long int>& nums, int start, int end);
    void    merge_sort(std::vector<long int>& nums, int start, int mid, int end);
    void    merge_sort(std::list<long int>& nums, int start, int mid, int end);

    void    print_vector(std::vector<long int> nums);
    void    print_list(std::list<long int> nums);
    
    std::vector<long int> v_input;
    std::list<long int> l_input;
    std::clock_t time_used;
    
public:
    PmergeMe(int argc, char ** argv);
    PmergeMe(PmergeMe const & other);
    PmergeMe & operator=(PmergeMe const & other);
    ~PmergeMe();

    void run();
    void sort(std::vector<long int>& nums, int start, int end, int k);
    void sort(std::list<long int>& nums, int start, int end, int k);
};

#endif