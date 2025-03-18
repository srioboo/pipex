/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 08:51:33 by srioboo-          #+#    #+#             */
/*   Updated: 2025/01/13 15:19:34 by srioboo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

/**
 * @brief It prints in console the given parameters formatted
 *
 * @details Prints the given parameters formated into the string given.
 * It allow print diferent kinds of parameter types
 * @param s string to print
 * @param ... several parameters to print
 * @return the size of the result print
 */
int		ft_printf(char const *s, ...);

/**
 * @brief check the type of parameters given and call the apropiate
 * function to print and return the size
 *
 * @details auxiliar function that detect the type of the paremeter
 * and call the proper function to insert the data into the given string
 * @param str the string in which we'll insert the parameters
 * @param args the group of parametes given to the string
 * @return the acumulated size of the string
 */
size_t	ft_type(char *str, va_list	args);

/**
 * @brief Print the given hexadecimal and return his size
 *
 * @details Print the given hexadecimal and return his size
 * @param str, the string to insert the given parameters
 * @param args, the group of parameters given to the function
 * @param c the char representing the type of the argument
 * @return the size of the hexadecimal
 */
size_t	ft_puthex(char *str, va_list args, char c);

/**
 * @brief Print the given number and return his size
 *
 * @details Print the given number and return his size
 * @param str, the string to insert the given parameters
 * @param args, the group of parameters given to the function
 * @param c the char representing the type of the argument
 * @return the size of the number
 */
size_t	ft_putnumber(char *str, va_list args, char c);

/**
 * @brief Print the given pointer and return his size
 *
 * @details Print the given pointer and return his size
 * @param str, the string to insert the given parameters
 * @param args, the group of parameters given to the function
 * @return the size of the pointer
 */
size_t	ft_putpointer(char *str, va_list args);

/**
 * @brief Print the given char and return his size
 *
 * @details Print the given char and return his size
 * @param str, the string to insert the given parameters
 * @param args, the group of parameters given to the function
 * @return the size of the char
 */
size_t	ft_putchar(char *str, va_list args);

/**
 * @brief Print the given string and return his size
 *
 * @details Print the given string and return his size
 * @param str, the string to insert the given parameters
 * @param args, the group of parameters given to the function
 * @return the size of the string
 */
size_t	ft_putstr(char *str, va_list args);

/**
 * @brief print the % character
 *
 * @details Print the % character given to the string as %%
 * @param str, the string to insert the given parameters
 * @param c the char representing the type of the argument
 * @return the size of the char %
 */
size_t	ft_putpercent(char *str, char c);

#endif
