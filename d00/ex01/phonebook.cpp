/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjuery <sjuery@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 14:52:09 by sjuery            #+#    #+#             */
/*   Updated: 2018/09/30 20:49:25 by sjuery           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include "phonebook.hpp"

int	Phonebook::nbrContacts = 0;

void Contact::printInfo(void) {
	std::cout << "Data on " << first_name << " " << last_name << std::endl;
	std::cout << "First Name:        " << first_name << std::endl;
	std::cout << "Last Name:         " << last_name << std::endl;
	std::cout << "NickName:          " << nick_name << std::endl;
	std::cout << "Login:             " << login << std::endl;
	std::cout << "Postal Address:    " << postal_address << std::endl;
	std::cout << "Email Address:     " << email_address << std::endl;
	std::cout << "Phone Number:      " << phone_number << std::endl;
	std::cout << "Birthday:          " << birthday << std::endl;
	std::cout << "Favorite Meal:     " << favorite_meal << std::endl;
	std::cout << "Underwear Color:   " << underwear_color << std::endl;
	std::cout << "Darkest Secret:    " << darkest_secret << std::endl;
	std::cout << "Real Or Imaginary: " << real_or_imaginary << std::endl;
}

void Contact::previewInfo(int contactNbr) {
	std::cout << "|" << std::setw(10) << contactNbr+1;
	if (first_name.length() > 10)
		std::cout << "|" << std::setw(9) << first_name.substr(0,9) << '.';
	else
		std::cout << "|" << std::setw(10) << first_name;
	if (last_name.length() > 10)
		std::cout << "|" << std::setw(9) << last_name.substr(0,9) << '.';
	else
		std::cout << "|" << std::setw(10) << last_name;
	if (nick_name.length() > 10)
		std::cout << "|" << std::setw(9) << nick_name.substr(0,9) << '.' << '|' << std::endl;
	else
		std::cout << "|" << std::setw(10) << nick_name << '|' << std::endl;
}

void Contact::addContact(void) {
	std::cout << "Creating Contact N° " << Phonebook::nbrContacts+1 << std::endl;
	std::cout << "Contact's First Name:" << std::endl;
	getline(std::cin, first_name);
	std::cout << "Contact's Last Name:" << std::endl;
	getline(std::cin, last_name);
	std::cout << "Contact's NickName:" << std::endl;
	getline(std::cin, nick_name);
	std::cout << "Contact's Login:" << std::endl;
	getline(std::cin, login);
	std::cout << "Contact's Postal Address:" << std::endl;
	getline(std::cin, postal_address);
	std::cout << "Contact's Email Address:" << std::endl;
	getline(std::cin, email_address);
	std::cout << "Contact's Phone Number:" << std::endl;
	getline(std::cin, phone_number);
	std::cout << "Contact's Birthday:" << std::endl;
	getline(std::cin, birthday);
	std::cout << "Contact's Favorite Meal:" << std::endl;
	getline(std::cin, favorite_meal);
	std::cout << "Contact's Underwear Color:" << std::endl;
	getline(std::cin, underwear_color);
	std::cout << "Contact's Darkest Secret:" << std::endl;
	getline(std::cin, darkest_secret);
	std::cout << "Contact's Real Or Imaginary:" << std::endl;
	getline(std::cin, real_or_imaginary);
	Phonebook::nbrContacts++;
}

void Phonebook::searchContact(void) {
	if(nbrContacts > 0)
	{
		std::string input;

		std::cout << "|     Index|First Name| Last Name|  NickName|" << std::endl;
		for(int i = 0; i < nbrContacts; i++)
			contact[i].previewInfo(i);
		std::cout << "Choose Contact Index for more details:" << std::endl;
		while(getline(std::cin, input))
		{
			if(input >= "1" && input <= "8")
				if(stoi(input) >= 0 && stoi(input) <= nbrContacts)
					break;
			std::cout << "Please select a number between 1 and " << nbrContacts << std::endl;
		}
		contact[stoi(input)-1].printInfo();
	}
	else
		std::cout << "\033[1;36mNo friends currently in contacts, add them using \"ADD\"\033[0m" << std::endl;
}

void printCommands(void) {
	std::cout << "\033[1;32mAvailable Commands:\033[0m" << std::endl
	<< "\033[1;32mADD:    Add's contact up to a maximum of 8.\033[0m" << std::endl
	<< "\033[1;32mSEARCH: Searches your contacts and lists their information.\033[0m" << std::endl
	<< "\033[1;31mEXIT:   Obliterates your entire contacts list.\033[0m" << std::endl;
}

int main(void) {
	std::string input;
	Phonebook phonebook;

	printCommands();
	while(input != "EXIT" && !std::cin.eof())
	{
		getline(std::cin, input);
		if(input == "ADD")
		{
			if(Phonebook::nbrContacts+1 > 8) {
				std::cout << "\033[1;31mNO WAY IN HELL YOU HAVE MORE THAN 8 FRIENDS!\033[0m" << std::endl;
				continue;
			}
			phonebook.contact[Phonebook::nbrContacts].addContact();
			printCommands();
		}
		else if(input == "SEARCH") {
			phonebook.searchContact();
			printCommands();
		}
	}
}
