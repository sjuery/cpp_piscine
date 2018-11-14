/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pony.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjuery <sjuery@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 14:35:14 by sjuery            #+#    #+#             */
/*   Updated: 2018/10/03 19:55:38 by sjuery           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

class Pony
{
	std::string _name;
	std::string _color;
	int _age;
	int _weight;
	int _height;
public:
	Pony(std::string name, std::string color, int age, int weight, int height);
	~Pony(void);

	static void ponyOnTheHeap(std::string name, std::string color, int age, int weight, int height);
	static void ponyOnTheStack(std::string name, std::string color, int age, int weight, int height);
};
