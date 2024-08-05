/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 13:10:08 by jofilipe          #+#    #+#             */
/*   Updated: 2024/07/29 13:10:09 by jofilipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(): fixedPoint(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &c): fixedPoint(c.fixedPoint) {
	std::cout << "Copy constructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed& o) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this == &o)
		return *this;
	this->setRawBits(o.getRawBits());
	return *this;
}

int		Fixed::   getRawBits(void) const{
	std::cout << "getRawBits member function called" << std::endl;
	return (fixedPoint);
}

void	Fixed::setRawBits(int const raw) {
	fixedPoint = raw;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}