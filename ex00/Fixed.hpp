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

class Fixed {
	private:
		int	fixedPoint;
		static const int bits = 8;

	public:
		Fixed();
		Fixed(const Fixed& c);
		Fixed& operator=(const Fixed& o);
		~Fixed();

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
};

#endif //FIXED_HPP