/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksura <ksura@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 14:23:24 by ksura             #+#    #+#             */
/*   Updated: 2023/04/18 19:00:22 by ksura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/PmergeMe.hpp"

PmergeMe::PmergeMe(int argc,  char ** argv)
{
    std::cout << "constructor" << std::endl;
    v_input = parse_input_vector(argc, argv);
    // l_input = parse_input_list(argc, argv);
}

PmergeMe::~PmergeMe()
{
    
}

PmergeMe & PmergeMe::operator=(PmergeMe const & other)
{
    if (this != &other)
        v_input = other.v_input;
        // l_input = other.l_input;
    return (*this);
}

PmergeMe::PmergeMe(PmergeMe const & other)
{
    v_input = other.v_input;
    // l_input = other.l_input;
}

std::vector<int> PmergeMe::parse_input_vector(int argc, char ** argv)
{
    // (void) argc;
    std::vector<int> nums;
    int i = 1;
    while (i < argc) {
        nums.push_back(atoi(argv[i]));
        i++;
    }
    return (nums);
}

void    PmergeMe::run()
{
    // Print unsorted input vector
    std::cout << "Before: ";
    print_vector(v_input);

    // Sort using vector
    time_used = std::clock();
    sort(v_input, 0, v_input.size(), 15);
    time_used = std::clock() - time_used;

    //print sorted vectoe
    std::cout << "After: ";
    print_vector(v_input);
    
    //print used times
    std::cout << "Time to process a range of " << v_input.size()
    << " elements with std::vector : " << (double)time_used << "µs"<< std::endl;
}

void    PmergeMe::print_vector(std::vector<int> nums) {
    int size = nums.size();
    if (size <= 4) {
        for (int i = 0; i <= size; i++) {
            std::cout << nums[i]  << " ";
        }
        std::cout << std::endl;
    } else {
        for(int i = 0;  i < 4; i++) {
            std::cout << nums[i] << " ";
        }
        std::cout << "[...]" << std::endl;
    }
}

void PmergeMe::sort(std::vector<int>& nums, int start, int end, int k) {
    if (end - start + 1 <= k) { // base case
        insertion_sort(nums, start, end); // sort the subsequence using insertion sort
        return;
    }
    int mid = start + (end - start) / 2; // find the middle index
    sort(nums, start, mid, k); // recursively split the left subsequence
    sort(nums, mid + 1, end, k); // recursively split the right subsequence
    merge_sort(nums, start, mid, end); // merge the two sorted subsequences
}


void PmergeMe::insertion_sort(std::vector<int>& nums, int start, int end){
    // time_used = std::clock();
    for (int i = start + 1; i < end; i++) {
        const int key = nums[i];
        int j = i - 1;
        while (j >= start && nums[j] > key){
            nums[j + 1] = nums[j];
            --j;
        }
        nums[j + 1] = key;
    }
    // time_used = std::clock() - time_used;
}

void PmergeMe::merge_sort(std::vector<int>& nums, int start, int mid, int end)
{
    int n1 = mid - start + 1;
    int n2 = end - mid;
    std::vector<int> L(n1);
    std::vector<int> R(n2);
    int i, j, k;
    for (i = 0; i < n1; i++){
        L[i] = nums[start + i];
    }
    for (j = 0; j < n2; j++){
        R[j] = nums[mid + 1 + j];
    }
    i = 0;
    j = 0;
    k = start;
    while ( i < n1 && j < n2){
        if (L[i] <= R[j]){
            nums[k] = L[i];
            i++;
        } else {
            nums[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        nums[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        nums[k] = R[j];
        j++;
        k++;
    }
}
