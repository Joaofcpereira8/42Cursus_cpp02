/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 13:10:11 by jofilipe          #+#    #+#             */
/*   Updated: 2024/07/29 13:10:12 by jofilipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <math.h>

class Fixed {
	private:
		int	fixedPoint;
		static const int bits = 8;

	public:
		Fixed(); //Default constructor
		Fixed(const int n_int); //Int Constructor
		Fixed(const float n_float); //Constructor that takes a float
		Fixed(const Fixed& c); //Copy constructor
		Fixed& operator=(const Fixed& o); //Copy assignment overload
		~Fixed(); //Destructor

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;
};

std::ostream& operator<<(std::ostream& os, const Fixed& obj); //<< assignment overload

#endif //FIXED_HPP