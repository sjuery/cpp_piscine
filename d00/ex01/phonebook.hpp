/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjuery <sjuery@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 14:52:17 by sjuery            #+#    #+#             */
/*   Updated: 2018/09/30 20:58:38 by sjuery           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

class Contact {
public:
	void printInfo(void);
	void previewInfo(int contactNbr);
	void addContact(void);

private:
	std::string first_name;
	std::string last_name;
	std::string nick_name;
	std::string login;
	std::string postal_address;
	std::string email_address;
	std::string phone_number;
	std::string birthday;
	std::string favorite_meal;
	std::string underwear_color;
	std::string darkest_secret;
	std::string real_or_imaginary;
};

class Phonebook {
public:
	void searchContact(void);
	Contact contact[8];
	static int nbrContacts;
};
