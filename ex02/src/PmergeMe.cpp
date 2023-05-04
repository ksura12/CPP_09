/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksura <ksura@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 14:23:24 by ksura             #+#    #+#             */
/*   Updated: 2023/05/04 13:21:08 by ksura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/PmergeMe.hpp"

PmergeMe::PmergeMe(int argc,  char ** argv)
{
    v_input = parse_input_vector(argc, argv);
    l_input = parse_input_list(argc, argv);
}

PmergeMe::~PmergeMe()
{
}

PmergeMe & PmergeMe::operator=(PmergeMe const & other)
{
    if (this != &other) {
        v_input = other.v_input;
        l_input = other.l_input;   
    }
    return (*this);
}

PmergeMe::PmergeMe(PmergeMe const & other)
{
    v_input = other.v_input;
    l_input = other.l_input;
}

std::vector<long int> PmergeMe::parse_input_vector(int argc, char ** argv)
{
    std::vector<long int> nums;
    int i = 1;
    char *check;
    long int result;
    while (i < argc) {
        result = strtol(argv[i], &check, 0);
        if (argv[i] != check)
            nums.push_back(result);
        i++;
    }
    return (nums);
}

std::list<long int> PmergeMe::parse_input_list(int argc, char ** argv)
{
    std::list<long int> nums;
    char *check;
    int i = 1;
    long int result;
    while (i < argc) {
        result = strtol(argv[i], &check, 0);
        if (argv[i] != check){
            if(result >= 0)
                nums.push_back(result);
            else{
                std::cout << "ERROR: Positive Integer Values only" << std::endl;
                nums.clear();
                return(nums);
            }
        }
        else{
            std::cout << "ERROR: Positive Integer Values only" << std::endl;
            nums.clear();
            return(nums);
        }
        i++;
    }
    return (nums);
}

void    PmergeMe::run()
{
    // Print unsorted input vector
    if(v_input.size() == 0 || l_input.size() == 0)
        return;
    std::cout << "Before:\t";
    print_vector(v_input);

    // Sort using vector
    time_used = std::clock();
    sort(v_input, 0, v_input.size() - 1, 15);
    std::clock_t end = (std::clock());

    //print sorted vector
    std::cout << "After:\t";
    print_vector(v_input);
    
    //print used time
    std::cout << "Time to process a range of " << v_input.size() << std::fixed
    << std::setprecision(0) << " elements with std::vector :\t" 
    << (double)(end - time_used)  * 1000000 / CLOCKS_PER_SEC << "µs"<< std::endl;

    // // prnt before sorting
    // std::cout << "List Before:\t";
    // print_list(l_input);
    
    //sorting using list
    time_used = std::clock();
    sort(l_input, 0, l_input.size() - 1, 15);
    end = std::clock();
    
    // // prnt before sorting
    // std::cout << "List After:\t";
    // print_list(l_input);
    
    //print used times
    std::cout << "Time to process a range of " << v_input.size() << std::fixed
    << std::setprecision(0) << " elements with std::list :\t\t" 
    << (double)(end - time_used)  * 1000000 / CLOCKS_PER_SEC << "µs"<< std::endl;
    
}

void    PmergeMe::print_vector(std::vector<long int> nums) {
    int size = nums.size();
    for (int i = 0; i < size; i++) {
        std::cout << nums[i]  << " ";
    }
    std::cout << std::endl;
}

void PmergeMe::sort(std::vector<long int>& nums, int start, int end, int k) {
    if (end - start <= k) { // base case
        insertion_sort(nums, start, end); // sort the subsequence using insertion sort
        return;
    }
    int mid = start + (end - start) / 2; // find the middle index
    sort(nums, start, mid, k); // recursively split the left subsequence
    sort(nums, mid + 1, end, k); // recursively split the right subsequence
    merge_sort(nums, start, mid, end); // merge the two sorted subsequences
}



void PmergeMe::insertion_sort(std::vector<long int>& nums, int start, int end){
    for (int i = start + 1; i <= end; i++) {
        const long int key = nums[i];
        int j = i - 1;
        while (j >= start && nums[j] > key){
            nums[j + 1] = nums[j];
            --j;
        }
        nums[j + 1] = key;
    }
}


void PmergeMe::merge_sort(std::vector<long int>& nums, int start, int mid, int end)
{
    int n1 = mid - start + 1;
    int n2 = end - mid;
    std::vector<long int> L(n1);
    std::vector<long int> R(n2);
    int i, j, k;
  for (i = 0; i < n1; i++){
        L[i] = nums[start + i];
    }
    for (j = 0; j < n2; j++){
        R[j] = nums[mid  + j + 1];
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
    while (i < n1 && L[i]) {
        nums[k] = L[i];
        i++;
        k++;
    }
    while (j < n2 && R[j]) {
        nums[k] = R[j];
        j++;
        k++;
    }
}


void PmergeMe::sort(std::list<long int>& nums, int start, int end, int k) {
    if (end - start == 0)
        return;
    else if (end - start <= k) { // base case
        insertion_sort(nums, start, end); // sort the subsequence using insertion sort
        return;
    }
    int mid = start + (end - start) / 2; // find the middle index
    sort(nums, start, mid, k); // recursively split the left subsequence
    sort(nums, mid + 1, end, k); // recursively split the right subsequence
    merge_sort(nums, start, mid, end); // merge the two sorted subsequences
}

void PmergeMe::insertion_sort(std::list<long int>& nums, int start, int end) {
    int i = start + 1;
    int j = i - 1;
 
    std::list<long int>::iterator it = nums.begin();
    std::list<long int>::iterator jt = nums.begin();
    std::advance(it, start + 1);
    std::advance(jt, start);
    while( j < end)
    {
        if(*jt >= *it){
            jt = it;
        }
        std::advance(it, 1);
        j++;
    }
    long int smallest = *jt;
    jt = nums.erase(jt);
    it = nums.begin();
    std::advance(it, start);
    nums.insert(it, smallest);
    i = start + 2;
    std::list<long int>::iterator to_sort = nums.begin();
    std::list<long int>::iterator sorted = nums.begin();
    std::list<long int>::iterator prev = nums.begin();
    while(i <= end){
        to_sort = nums.begin();
        std::advance(to_sort, i);
        j = i - 1 ;
        while(j >= start){
            sorted = nums.begin();
            std::advance(sorted, j);
            prev = nums.begin();
            std::advance(prev, j - 1);
            if(*sorted >= *to_sort && *to_sort >= *prev){
                sorted = nums.insert(sorted, *to_sort);
                to_sort = nums.erase(to_sort);
                break;
            }
            j--;
        }
        i++;
    }
}

void PmergeMe::merge_sort(std::list<long int>& nums, int start, int mid, int end)
{
    int n1 = mid - start + 1;
    int n2 = end - mid;
    int i, j;
    std::list<long int> L;
    std::list<long int> R;
    std::list<long int>::iterator it = nums.begin();

    std::list<long int>::iterator R_it = R.begin();
    std::list<long int>::iterator L_it = L.begin();
    for (i = 0; i < n1; i++){
        it = nums.begin();
        std::advance(it, start + i);
        L.push_back(*it);
    }
    for (j = 0; j < n2; j++){
        it = nums.begin();
        std::advance(it, mid + j + 1);
        R.push_back(*it);
    }
    R_it = R.begin();
    L_it = L.begin();
    j = 0;
    i = 0;
    std::list<long int>::iterator begin = nums.begin();
    std::advance(begin, start);
    std::list<long int>::iterator ending = nums.begin();
    std::advance(ending, end + 1);
    ending = nums.erase(begin, ending);
    while ( j < n2 && i < n1){
        if (*R_it <= *L_it){
            nums.insert(ending, *R_it);
            R_it = R.erase(R_it);
            j++;
        }
        else{
            nums.insert(ending, *L_it);
            L_it = L.erase(L_it);
            i++;
        }     
    }
    while (i < n1){
        nums.insert(ending, *L_it);
        L_it = L.erase(L_it);
        i++;
    }
    while (j < n2){
        nums.insert(ending, *R_it);
        R_it = R.erase(R_it);
        j++;
    }
}

void    PmergeMe::print_list(std::list<long int> nums) {
    std::list<long int>::iterator it = nums.begin();
    unsigned int i = 0;
    while (i < nums.size()) {
        std::cout << *it << " ";
        it++;
        i++;
    }
    std::cout << std::endl;
}