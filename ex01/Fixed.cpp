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

Fixed::Fixed(const int n_int): fixedPoint(n_int) {
	std::cout << "Int constructor called" << std::endl;
	this->fixedPoint = n_int << bits;
}

Fixed::Fixed(const float n_float): fixedPoint(n_float) {
	std::cout << "Float constructor called" << std::endl;
	this->fixedPoint = static_cast<int>(roundf(fixedPoint * (1 << bits))); // Convert float to fixed-point representation
}

Fixed::Fixed(const Fixed &c): fixedPoint(c.fixedPoint) {
	std::cout << "Copy constructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed& o) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this == &o)
		return *this;
	this->setRawBits(getRawBits());
	return *this;
}

std::ostream& operator<<(std::ostream& os, const Fixed& obj) {
	os << obj.toFloat();
	return os;
}

int		Fixed::getRawBits(void) const{
	std::cout << "getRawBits member function called" << std::endl;
	return (fixedPoint);
}

void	Fixed::setRawBits(int const raw) {
	fixedPoint = raw;
}

int	Fixed::toInt() const {
	return fixedPoint >> bits;
}

float	Fixed::toFloat() const {
	return static_cast<float>(fixedPoint) / (1 << bits);
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}