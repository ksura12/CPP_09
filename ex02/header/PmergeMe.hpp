/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksura <ksura@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 14:13:45 by ksura             #+#    #+#             */
/*   Updated: 2023/04/18 18:19:34 by ksura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
 #define PMERGEME_HPP

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <ctime>
#include <algorithm>

class PmergeMe
{
private:
    std::vector<int> parse_input_vector(int argc, char ** argv);
    // std::list<int> parse_input_list(int argc, char ** argv);
    
    
    // void display() const;
    // void displayTime(const std::string& containerName, clock_t time) const;
    
    // void print_vector(const std::vector<int>& v);
    // void print_time_diff(std::chrono::high_resolution_clock::time_point t1, std::chrono::high_resolution_clock::time_point t2);
    
    
    // void    devide_container(std::vector<int>& v);
    // void    devide_container(std::list<int>& l);
    void    insertion_sort(std::vector<int>& nums, int start, int end);
    // void    insertion_sort(std::list<int>& nums, int start, int end);
    void    merge_sort(std::vector<int>& nums, int start, int mid, int end);
    // void    merge_sort(std::list<int>& l);

    void    print_vector(std::vector<int> nums);
    
    std::vector<int> v_input;
    // std::list<int> l_input;
    std::clock_t time_used;
    
public:
    PmergeMe(int argc, char ** argv);
    PmergeMe(PmergeMe const & other);
    PmergeMe & operator=(PmergeMe const & other);
    ~PmergeMe();

    void    run();
    void sort(std::vector<int>& nums, int start, int end, int k);
    // void sort(std::list<int>& nums, int start, int end, int k);
    // void sort(std::vector<int>& nums);
    // void sort(std::list<int>& nums);

    // void run();
};

#endif