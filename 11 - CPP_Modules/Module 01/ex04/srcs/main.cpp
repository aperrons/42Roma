/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperrone <aperrone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 01:18:48 by aperrone          #+#    #+#             */
/*   Updated: 2023/05/05 01:18:49 by aperrone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

int main(int argc, char **argv) {
    
    std::ifstream   origin;
    std::string     destination_name = "";
    std::string     search;
    std::string     replace;
    std::string     buf;
    size_t          pos;

	origin.open(argv[1]);
	if (argc != 4 || !origin) {
		std::cout << "Something went wrong.";
		exit(1);
	}
    search = argv[2];
    replace = argv[3];
    destination_name.append(argv[1]).append(".replace");
    std::ofstream destination(destination_name, std::ios_base::trunc);
    while(std::getline(origin, buf)) {
        pos = 0;
        while ((pos = buf.find(search, pos)) != std::string::npos) {
            buf.erase(pos, search.size());
            buf.insert(pos, replace);
            pos += replace.size();
        }
        destination << buf << std::endl;
    }
    origin.close();
    destination.close();
    return 0;
}