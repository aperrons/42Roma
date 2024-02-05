/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperrone <aperrone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 20:56:36 by aperrone          #+#    #+#             */
/*   Updated: 2023/05/04 20:56:38 by aperrone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

class Contact {
	public:
		Contact();
		~Contact(void);

		void	initFirstName(std::string firstName);
		void	initLastName(std::string lastName);
		void	initNickName(std::string nickName);
		void	initPhoneNumber(std::string phoneNumber);
		void	initDarkestSecret(std::string darkestSecret);
		void	initStatus(void);

		std::string 	getFirstName(void) const;
		std::string  	getLastName(void) const;
		std::string  	getNickName(void) const;
		std::string  	getPhoneNumber(void) const;
		std::string  	getDarkestSecret(void) const;
		int				getStatus(void) const;

		void	setFirstName(void);
		void	setLastName(void);
		void	setNickName(void);
		int		setPhoneNumber(void);
		void	setDarkestSecret(void);
		void	setStatus(void);


	private:
		std::string	_firstName;
		std::string	_lastName;
		std::string	_nickName;
		std::string	_phoneNumber;
		std::string	_darkestSecret;
		int			_status;
};

#endif