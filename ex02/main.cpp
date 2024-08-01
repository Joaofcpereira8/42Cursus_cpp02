/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 13:10:13 by jofilipe          #+#    #+#             */
/*   Updated: 2024/07/29 13:10:14 by jofilipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void ) {
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	Fixed c = Fixed(5.05f);
	Fixed d = Fixed(2);
	Fixed e;
	std::cout << "Valor inicial de a:" << a << std::endl;
	std::cout << "Valor pre incremento:" << ++a << std::endl;
	std::cout << "Valor apos pre incremento:" << a << std::endl;
	std::cout << "Valor pos incremento:" << a++ << std::endl;
	std::cout << "Valor apos pos incremento:" << a << std::endl;
	std::cout << "Valor em float:" << a.toFloat() << std::endl;
	std::cout << "Valor inicial de b:" << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
	e = c * d;
	std::cout << c << std::endl;
	std::cout << d << std::endl;
	std::cout << e << std::endl;

	return 0;
}