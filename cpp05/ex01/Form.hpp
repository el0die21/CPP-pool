/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elrichar <elrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 17:08:03 by elrichar          #+#    #+#             */
/*   Updated: 2024/04/30 14:41:19 by elrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <exception>
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	public:
	Form(void);
	Form(const std::string name, const int gradeToSign, const int gradeToExecute);
	Form (const Form &other);
	Form &operator = (const Form &other);
	~Form(void);

	/*getters*/
	std::string getName(void) const;
	bool			  getIsSigned(void) const;
	int		  getGradeToSign(void) const;
	int		  getGradeToExecute(void) const;

	/*member functions*/
	void 			  beSigned(const Bureaucrat &bureaucrat);

	/*exceptions*/
	class GradeTooHighException : public std::exception
	{
		public:
		const char* what(void) const throw();	
	};
	
	class GradeTooLowException : public std::exception
	{
		public:
		const char* what(void) const throw();
	};

	class FormAlreadySignedException : public std::exception
	{
		public:
		const char* what(void) const throw();
	};

	private:
	const std::string _name;
	bool			  _isSigned;
	const int		  _gradeToSign;
	const int		  _gradeToExecute;

};

std::ostream	&operator<<(std::ostream &os, const Form &form);

#endif