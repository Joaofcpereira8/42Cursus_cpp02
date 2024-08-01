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

Fixed::Fixed(const int n_int): fixedPoint(n_int << bits) {
	//Convert int to fixed-point
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float n_float): fixedPoint(static_cast<int>(roundf(n_float * (1 << bits)))) {
	// Convert float to fixed-point representation
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &c): fixedPoint(c.fixedPoint) {
	std::cout << "Copy constructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed& o) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &o)
		this->setRawBits(o.getRawBits());
	return *this;
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

bool	Fixed::operator>(const Fixed &o) const {
	return this->toFloat() > o.toFloat();
}

bool	Fixed::operator>=(const Fixed &o) const {
	return this->toFloat() >= o.toFloat();
}

bool	Fixed::operator<(const Fixed &o) const {
	return this->toFloat() < o.toFloat();
}

bool	Fixed::operator<=(const Fixed &o) const {
	return this->toFloat() <= o.toFloat();
}

bool	Fixed::operator==(const Fixed &o) const {
	return this->toFloat() == o.toFloat();
}

bool	Fixed::operator!=(const Fixed &o) const {
	return this->toFloat() != o.toFloat();
}

Fixed Fixed::operator+(const Fixed &o) const {
	return this->toFloat() + o.toFloat();
}

Fixed Fixed::operator-(const Fixed &o) const {
	return this->toFloat() - o.toFloat();
}

Fixed Fixed::operator*(const Fixed &o) const {
	return this->toFloat() * o.toFloat();
}

Fixed Fixed::operator/(const Fixed &o) const {
	return this->toFloat() / o.toFloat();
}

//Pre-increment
Fixed &Fixed::operator++() {
	this->fixedPoint++; //Incrementamos o valor
	return *this; //Retornamos o objeto currente pela referencia
}

//Pre-decrement
Fixed &Fixed::operator--() {
	this->fixedPoint--;
	return *this;
}

//Pos-increment
Fixed Fixed::operator++(int) {
	Fixed temp = *this; //Criamos uma copia do objecto
	this->fixedPoint++; //Incrementamos o objeto
	return temp; //Returnamos a copia pelo valor
}

//Pos-decrement
Fixed Fixed::operator--(int) {
	Fixed temp = *this;
	this->fixedPoint--;
	return temp;
}

Fixed	&Fixed::min(Fixed &Fixed1, Fixed &Fixed2) {
	return (Fixed1 < Fixed2 ? Fixed1 : Fixed2);
}

Fixed	&Fixed::max(Fixed &Fixed1, Fixed &Fixed2) {
	return (Fixed1 > Fixed2 ? Fixed1 : Fixed2);
}

const	Fixed	&Fixed::min(const Fixed &Fixed1, const Fixed &Fixed2) {
	return (Fixed1 < Fixed2 ? Fixed1 : Fixed2);
}

const	Fixed	&Fixed::max(const Fixed &Fixed1, const Fixed &Fixed2) {
	return (Fixed1 > Fixed2 ? Fixed1 : Fixed2);
}

std::ostream& operator<<(std::ostream& os, const Fixed& obj) {
	os << obj.toFloat();
	return os;
}