/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elrichar <elrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 14:52:02 by elrichar          #+#    #+#             */
/*   Updated: 2024/04/15 20:18:42 by elrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"
#include "Brain.hpp"

class WrongCat : public WrongAnimal
{
	public:
	WrongCat(void);
	WrongCat (const WrongCat &other);
	WrongCat &operator = (const WrongCat &other);
	~WrongCat(void);

	void makeSound(void) const;
	std::string getType(void) const;


	protected:
	std::string _type;

	private:
	Brain *_brain;
};

#endif