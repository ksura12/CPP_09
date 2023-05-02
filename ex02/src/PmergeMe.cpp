/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksura <ksura@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 14:23:24 by ksura             #+#    #+#             */
/*   Updated: 2023/05/02 17:54:08 by ksura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/PmergeMe.hpp"

PmergeMe::PmergeMe(int argc,  char ** argv)
{
    std::cout << "constructor" << std::endl;
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
    while (i < argc) {
        if (strtol(argv[i], NULL, 0))
            nums.push_back(strtol(argv[i], NULL, 0));
        i++;
    }
    return (nums);
}

std::list<long int> PmergeMe::parse_input_list(int argc, char ** argv)
{
    std::list<long int> nums;
    int i = 1;
    while (i < argc) {
        if (strtol(argv[i], NULL, 0))
            nums.push_back(strtol(argv[i], NULL, 0));
        i++;
    }
    return (nums);
}

void    PmergeMe::run()
{
    // Print unsorted input vector
    std::cout << "Before:\t";
    print_vector(v_input);

    // Sort using vector
    time_used = std::clock();
    sort(v_input, 0, v_input.size() - 1, 15);
    std::clock_t end = (std::clock());

    //print sorted vectoe
    std::cout << "After:\t";
    print_vector(v_input);
    
    //print used times
    std::cout << "Time to process a range of " << v_input.size() << std::fixed
    << std::setprecision(0) << " elements with std::vector : " 
    << (double)(end - time_used)  * 1000000 / CLOCKS_PER_SEC << "µs"<< std::endl;

    //prnt before sorting
    std::cout << "List Before:\t";
    print_list(l_input);
    
    //sorting using list
    time_used = std::clock();
    sort(l_input, 0, l_input.size() - 1, 15);
    end = std::clock();
    
    //prnt before sorting
    std::cout << "List After:\t";
    print_list(l_input);
    
    //print used times
    std::cout << "Time to process a range of " << v_input.size() << std::fixed
    << std::setprecision(0) << " elements with std::list : " 
    << (double)(end - time_used)  * 1000000 / CLOCKS_PER_SEC << "µs"<< std::endl;
    
}

void    PmergeMe::print_vector(std::vector<long int> nums) {
    int size = nums.size();
    
    // if (size <= 4) {
        for (int i = 0; i < size; i++) {
            std::cout << nums[i]  << " ";
        }
        std::cout << std::endl;
    // } else {
    //     for(int i = 0;  i < 4; i++) {
    //         std::cout << nums[i] << " ";
    //     }
    //     std::cout << "[...]" << std::endl;
    // }
}

void PmergeMe::sort(std::vector<long int>& nums, int start, int end, int k) {
    if (end - start <= k) { // base case
        insertion_sort(nums, start, end); // sort the subsequence using insertion sort
        return;
    }
    int mid = start + (end - start) / 2; // find the middle index
    // std::cout << "start, mid, end" << start << " " << mid << " " << end << std::endl;
    sort(nums, start, mid, k); // recursively split the left subsequence
    sort(nums, mid + 1, end, k); // recursively split the right subsequence
    merge_sort(nums, start, mid, end); // merge the two sorted subsequences
}



void PmergeMe::insertion_sort(std::vector<long int>& nums, int start, int end){
    for (int i = start + 1; i <= end; i++) {
        const int key = nums[i];
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
    // std::cout << "1" << std::endl;
  for (i = 0; i < n1; i++){
        L[i] = nums[start + i];
        // std::cout << i << nums[start + i]<< std::endl;

    }
    // std::cout << "2" << std::endl;
    for (j = 0; j < n2; j++){
        R[j] = nums[mid  + j + 1];
                // // std::cout << j  << nums[mid +1 + j]<< std::endl;

    }
    i = 0;
    j = 0;
    k = start;
    // std::cout << "3" << std::endl;
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
    // std::cout << "4" << std::endl;
    while (i < n1 && L[i]) {
        nums[k] = L[i];
        i++;
        k++;
    }
    // std::cout << "5" << std::endl;
    while (j < n2 && R[j]) {
        nums[k] = R[j];
        j++;
        k++;
    }
    // std::cout << "6" << std::endl;
}


void PmergeMe::sort(std::list<long int>& nums, int start, int end, int k) {
    if (end - start == 0)
        return;
    else if (end - start <= k) { // base case
        insertion_sort(nums, start, end); // sort the subsequence using insertion sort
        return;
    }
    int mid = start + (end - start) / 2; // find the middle index
    // std::cout << "start, mid, end" << start << " " << mid << " " << end << std::endl;
    sort(nums, start, mid, k); // recursively split the left subsequence
    sort(nums, mid + 1, end, k); // recursively split the right subsequence
    merge_sort(nums, start, mid, end); // merge the two sorted subsequences
}

// void PmergeMe::insertion_sort(std::vector<long int>& nums, int start, int end){
//     for (int i = start + 1; i <= end; i++) {
//         const int key = nums[i];
//         int j = i - 1;
//         while (j >= start && nums[j] > key){
//             nums[j + 1] = nums[j];
//             --j;
//         }
//         nums[j + 1] = key;
//     }
// }

void PmergeMe::insertion_sort(std::list<long int>& nums, int start, int end) {
    int i = start + 1;
    int j = i - 1;
    std::list<long int>::iterator it = nums.begin();
    std::list<long int>::iterator jt = nums.begin();
    std::advance(it, start + 1);
    std::advance(jt, start);
    // long int key = *jt;
    while( j <= end)
    {
        if(*jt >= *it){
            jt = it;
        }
        std::advance(it, 1);
        j++;
    }
    // std::cout << "status before first change it: " << *it << std::endl;
    // std::cout << "status before first change jt: " << *jt << std::endl;
    it = nums.insert(it, *jt);
    jt = nums.erase(jt);
    
    // std::cout << "status after first change it: " << *it << std::endl;
    // std::cout << "status after first change jt: " << *jt << std::endl;

    //printing list
    // print_list(nums);
    //reset values for ordering list
    i = start + 2;
    // j = i - 1;
    std::list<long int>::iterator to_sort = nums.begin();
    std::list<long int>::iterator sorted = nums.begin();
    std::list<long int>::iterator prev = nums.begin();
    while(i <= end){
        to_sort = nums.begin();
        std::advance(to_sort, i);
        // sorted = nums.begin();
        // std::advance(sorted, j);
        // std::cout << "to_sort: " << *to_sort << std::endl;
        // std::cout << "sorted: " << *sorted << std::endl;
        j = i - 1 ;
        while(j >= start){
            sorted = nums.begin();
            std::advance(sorted, j);
            // std::advance(jt, - 1);
            // std::cout << "sorted 2: " << *sorted << std::endl;
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


// void PmergeMe::insertion_sort(std::list<long int>& nums, int start, int end){
//     std::list<long int>::iterator i, j;
//     i = nums.begin();
//     std::advance(i, start + 1);
//     j = i;
//     std::advance(j, -1);

//     for (; i != nums.end() && start <= end; ++i, ++start) {
//         const long int key = *i;
//         j = i;
//         std::advance(j, -1);  
//         while (j != nums.begin() && *j > key){
//             std::list<long int>::iterator temp = j;
//             std::advance(temp, 1);
//             *temp = *j;
//             std::advance(j, -1);
//         }
//         std::list<long int>::iterator temp = j;
//         std::advance(temp, 1);
//         *temp = key;
//     }
// }

void PmergeMe::merge_sort(std::list<long int>& nums, int start, int mid, int end)
{
    int n1 = mid - start + 1;
    int n2 = end - mid;
    int i, j;
    std::list<long int> L(n1);
    std::list<long int> R(n2);
    std::list<long int>::iterator it = nums.begin();

    std::list<long int>::iterator R_it = R.begin();
    std::list<long int>::iterator L_it = L.begin();
    for (i = 0; i < n1; i++){
        L_it = L.begin();
        std::advance(L_it, i);
        it = nums.begin();
        std::advance(it, start + i);
        *L_it = *it;
        // std::cout << i << *it << std::endl;

    }
    for (j = 0; j < n2; j++){
        R_it = R.begin();
        std::advance(R_it, j);
        it = nums.begin();
        std::advance(it, mid + j + 1);
        *R_it = *it;
                std::cout << j << "  " << *it<< std::endl;

    }
    
    std::cout << "R begin: " << *R_it << std::endl;
    std::cout << "L begin: " << *L_it << std::endl;
    R_it = R.begin();
    L_it = L.begin();
    j = 0;
    i = 0;
    // k = 1;
    nums.clear();
    while ( j <= n2 && i <= n1){
        if (*R_it <= *L_it){
            nums.push_back(*R_it);
            R_it = R.erase(R_it);
            i++;
        }
        else{
            nums.push_back(*L_it);
            L_it = L.erase(L_it);
            j++;
        }     
    }
    while (j <= n2){
        nums.push_back(*L_it);
        L_it = L.erase(L_it);
        j++;
    }
    while (i <= n1){
        nums.push_back(*R_it);
        R_it = R.erase(R_it);
        i++;
    }
    //putting lists together
    // for(j = 0; R_it <= L_it)
//     int n1 = mid - start + 1;
//     int n2 = end - mid;
//     std::list<long int> L(n1);
//     std::list<long int> R(n2);
//     int i, j, k;
//     std::list<long int>::iterator it = nums.begin();
//     std::list<long int>::iterator R_it = R.begin();
//     std::list<long int>::iterator L_it = L.begin();
//   for (i = 0; i < n1; i++){
//         L_it = L.begin();
//         std::advance(L_it, i);
//         it = nums.begin();
//         std::advance(it, start + i);
//         *L_it = *it;
//         // std::cout << i << *it << std::endl;

//     }
//     for (j = 0; j < n2; j++){
//         R_it = R.begin();
//         std::advance(R_it, j);
//         it = nums.begin();
//         std::advance(it, mid + j + 1);
//         *R_it = *it;
//                 // std::cout << j  << *it<< std::endl;

//     }
//     i = 0;
//     j = 0;
//     k = start;
//     while ( i < n1 && j < n2){
//         R_it = R.begin();
//         L_it = L.begin();
//         std::advance(L_it, i);
//         std::advance(R_it, j);
//         it = nums.begin();
//         std::advance(it, k);
//         if (*L_it <= *R_it){
//             *it = *L_it;
//             i++;
//         } else {
//             *it = *R_it;
//             j++;
//         }
//         k++;
//     }
//     while (i < n1 && *L_it) {
//         L_it = L.begin();
//         std::advance(L_it, i);
//         it = nums.begin();
//         std::advance(it, k);
//         *it = *L_it;
//         i++;
//         k++;
//     }
//     while (j < n2 && *R_it) {
//         R_it = R.begin();
//         std::advance(R_it, j);
//         it = nums.begin();
//         std::advance(it, k);
//         *it = *R_it;
//         j++;
//         k++;
//     }
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