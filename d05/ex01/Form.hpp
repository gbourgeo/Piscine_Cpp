// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Form.hpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: root </var/mail/root>                      +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/07/06 13:57:42 by root              #+#    #+#             //
//   Updated: 2018/07/06 14:50:08 by root             ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef FORM_HPP
# define FORM_HPP

# include <string>
# include <stdexcept>
# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
public:
	Form(std::string const & name, int const sign, int const exec);
	Form(Form const & src);
	Form & operator=(Form const & rhs);
	~Form();

	std::string const 	getName() const;
	bool				getSigned() const;
	int					getSignGrade() const;
	int					getExecGrade() const;
	void				beSigned(Bureaucrat &);
	
	class GradeTooHighException : public std::exception
	{
	public:
		virtual const char * what() const throw()
			{
				return ("Grade Too High !");
			}
	};

	class GradeTooLowException : public std::exception
	{
	public:
		virtual const char * what() const throw()
			{
				return ("Grade Too Low !");
			}
	};

private:
	Form();

	std::string	_name;
	bool		_signed;
	int			_signGrade;
	int			_execGrade;
};

std::ostream &operator<<(std::ostream & os, Form const & src);

#endif
