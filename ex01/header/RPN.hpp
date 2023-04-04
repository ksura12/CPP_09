/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksura <ksura@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 15:45:54 by ksura             #+#    #+#             */
/*   Updated: 2023/04/04 16:07:18 by ksura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef RPN_HPP
 #define RPN_HPP

#include <iostream>
#include <stack>
#include <string>

class RPN
{
    private:
        std::stack<double> stack;
        char ** input;

    public:
        RPN(char ** argv);
        RPN(RPN const & other);
        RPN & operator=(RPN const & other);
        ~RPN();

        int calculating();  
};

#endif
