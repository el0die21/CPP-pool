/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Diamond.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elrichar <elrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 12:46:51 by elrichar          #+#    #+#             */
/*   Updated: 2024/04/04 15:30:38 by elrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Diamond.hpp"

DiamondTrap::DiamondTrap(void) : ClapTrap(), ScavTrap(), FragTrap()
{
		std::cout << "DiamondTrap Default constructor called" << std::endl;

}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name)
{
	_name = name;
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 30;
	std::cout << "DiamondTrap parametric constructor called" << std::endl;
	
}


DiamondTrap::DiamondTrap(DiamondTrap const &other)
{
	std::cout << "DiamondTrap Copy constructor called" << std::endl;
	
	this->_name = other._name;
	this->_hitPoints = other._hitPoints;
	this->_energyPoints = other._energyPoints;
	this->_attackDamage = other._attackDamage;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other)
{
	std::cout << "DiamondTrap Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->_name = other._name;
		this->_hitPoints = other._hitPoints;
		this->_energyPoints = other._energyPoints;
		this->_attackDamage = other._attackDamage;
	}
	return (*this);
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "DiamondTrap Destructor called" << std::endl;
	
}

void	DiamondTrap::whoAmI(void)
{
	std::cout << "DiamondTrap name : " << this->_name << " and ClapTrap name : " << ClapTrap::_name << std::endl;
}
void 	DiamondTrap::attack(const std::string& target)
{
	if (!this->_hitPoints || !this->_energyPoints)
	{
		std::cout << "DiamondTrap " << this->_name << " is dead" << std::endl;
		return ;
	}
	this->_energyPoints--;
	if (this->_energyPoints < 0)
		this->_energyPoints = 0;
	std::cout << "DiamondTrap " << this->_name << " attacks " << target;
	std::cout << " , causing " << this->_attackDamage << " points of damage!" << std::endl;
}

