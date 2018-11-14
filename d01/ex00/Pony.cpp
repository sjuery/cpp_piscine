/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pony.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjuery <sjuery@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 13:30:55 by sjuery            #+#    #+#             */
/*   Updated: 2018/10/03 19:55:55 by sjuery           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pony.hpp"

Pony::Pony(std::string name, std::string color, int age, int weight, int height) : _name(name), _color(color), _age(age), _weight(weight), _height(height)
{
	std::cout << _color << " Pony " << _name << " is born!" << std::endl;
}

Pony::~Pony(void)
{
	std::cout << _color << "Pony " << _name << " died at age " << _age << "." << std::endl;
}

void Pony::ponyOnTheHeap(std::string name, std::string color, int age, int weight, int height)
{
	Pony *heapPony = new Pony(name, color, age, weight, height);
	std::cout << "Name: " << heapPony->_name << std::endl;
	std::cout << "Color: " << heapPony->_color << std::endl;
	std::cout << "Age: " << heapPony->_age << std::endl;
	std::cout << "Weight: " << heapPony->_weight << std::endl;
	std::cout << "Height: " << heapPony->_height << std::endl;
	delete heapPony;
}

void Pony::ponyOnTheStack(std::string name, std::string color, int age, int weight, int height)
{
	Pony stackPony(name, color, age, weight, height);
	std::cout << "Name: " << stackPony._name << std::endl;
	std::cout << "Color: " << stackPony._color << std::endl;
	std::cout << "Age: " << stackPony._age << std::endl;
	std::cout << "Weight: " << stackPony._weight << "kilo's" << std::endl;
	std::cout << "Height: " << stackPony._height << "meter's" << std::endl;
}
