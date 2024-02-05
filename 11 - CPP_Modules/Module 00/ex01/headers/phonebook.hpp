/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperrone <aperrone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 20:56:47 by aperrone          #+#    #+#             */
/*   Updated: 2023/05/04 20:56:48 by aperrone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include "../headers/Contact.hpp"

class Phonebook {
    public:
        int     filled;
        Contact contacts[8];

        Phonebook(void);
        ~Phonebook(void);

        void        add(void);
        void        buildTable(int index);
        void        check(void);
        int         choice(const char *opt);
        void        contactBuilder(void);
        void        exit(void);
        void        menu(void);
        void        printMenu(void);
        void        printTable(void);
        void        printUser(int index);
        void        request();
        void        search(void);
        std::string truncate(std::string, int width);

};

#endif