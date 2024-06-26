/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elrichar <elrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 17:08:06 by elrichar          #+#    #+#             */
/*   Updated: 2024/04/30 14:43:39 by elrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(void) : _name("random name"), _isSigned(0), _gradeToSign(10), _gradeToExecute(20) {}

Form::Form(const std::string name, const int gradeToSign, const int gradeToExecute) : _name(name), _isSigned(0), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (this->_gradeToExecute < 1 || this->_gradeToSign < 1)
		throw Form::GradeTooHighException();
	else if (this->_gradeToExecute > 150 || this->_gradeToSign > 150)
		throw Form::GradeTooLowException();
}

Form::Form(const Form &other) : _name(other._name), _isSigned(other._isSigned), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute){}

Form& Form::operator = (const Form &other)
{
	if (this != &other)
	{
		this->_isSigned = other._isSigned;
	}
	return (*this);
} 

Form::~Form(void) {}

/*****getters*****/
std::string Form::getName(void) const
{
	return (this->_name);
}

bool Form::getIsSigned(void) const
{
	return (this->_isSigned);
}

int Form::getGradeToSign(void) const
{
	return (this->_gradeToSign);
}

int Form::getGradeToExecute(void) const
{
	return (this->_gradeToExecute);
}

/****Exceptions*****/

void Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() <= this->getGradeToSign())
	{
		if (this->_isSigned)
			throw Form::FormAlreadySignedException();
		else
			this->_isSigned = 1;
	}
	else
		throw Form::GradeTooLowException();
}

const char* Form::GradeTooHighException::what(void) const throw()
{
	return ("[Form] Exception : Grade Too High!");
}

const char* Form::GradeTooLowException::what(void) const throw()
{
	return ("[Form] Exception : Grade Too Low!");
}

const char* Form::FormAlreadySignedException::what(void) const throw()
{
	return ("[Form] Exception : Form Already Signed!");
}

std::ostream &operator<<(std::ostream &os, const Form &form)
{
	os << "Form name = " << form.getName() << std::endl;
	if (form.getIsSigned())
		os << "This form is signed" << std::endl;
	else
		os << "This form is not signed" << std::endl;
	os << "Grade required to sign the form : " << form.getGradeToSign() << std::endl;
	os << "Grade required to execute the form : " << form.getGradeToExecute() << std::endl;

	return (os);
}