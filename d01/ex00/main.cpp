/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjuery <sjuery@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 14:47:56 by sjuery            #+#    #+#             */
/*   Updated: 2018/10/03 15:29:10 by sjuery           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pony.hpp"

int main(void) {
	std::cout << "Heap Pony:" << std::endl;
	Pony::ponyOnTheHeap("John", "White", 26, 80, 1.1);
	std::cout << "\nStack Pony:" << std::endl;
	Pony::ponyOnTheStack("Adam", "Gray", 20, 84, 1.2);
}
