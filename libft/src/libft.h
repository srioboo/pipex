/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 08:43:54 by srioboo-          #+#    #+#             */
/*   Updated: 2024/12/27 18:34:25 by srioboo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

/**
 * @brief Check if is an alphabetic character
 *
 * @details Given a numeric value, it will check if this is a alphabetic
 * character, equivalent to ft_isalpha || ft_isdigit
 * @param num integer
 * @return (1) when c is an alphabetic value and (0) when it is not
 */
int		ft_isalpha(int num);

/**
 * @brief Check if is a number
 *
 * @details Given a numeric value, it will check if this is a number
 * @param num integer
 * @return (1) when c is an number value and (0) when it is not
 */
int		ft_isdigit(int num);

/**
 * @brief Check if is alphanumeric
 *
 * @details Given a numeric value, it will check if this is a number
 * and/or letter
 * @param num integer
 * @return (1) when c is an alphanumeric value and (0) when it is not
 */
int		ft_isalnum(int num);

/**
 * @brief Check if is an ascii character
 *
 * @details Given a numeric value, it will check if this is a ascii character
 * @param num integer
 * @return (1) when c is an ascii value and (0) when it is not
 */
int		ft_isascii(int num);

/**
 * @brief Check if is a printable character
 *
 * @details Given a numeric value, it will check if this is a printable character
 * @param num integer
 * @return (1) when c is printable and (0) when it is not
 */
int		ft_isprint(int num);

/**
 * @brief Convert to lowercase
 *
 * @details Given a numeric value, if is a letter it will return a numeric value
 * of the lowercase letter
 * @param num integer
 * @return the num equivalent to lowercase
 */
int		ft_tolower(int num);

/**
 * @brief Convert to uppercase
 *
 * @details Given a numeric value, if is a letter it will return a numeric value
 * of the uppercase letter
 * @param num integer
 * @return the num equivalent to uppercase
 */
int		ft_toupper(int num);

/**
 * @brief Give the string lenght
 *
 * @details Given a string, will return the lenght of this string
 * @param str with the string to treat
 * @return the string lenght
 */
size_t	ft_strlen(const char *str);

/**
 * @brief Search for the first occurence of the given character in one string
 *
 * @details Return a poninter to the first occurrence of the givien character in
 * the given string
 * @param s the string to search in
 * @param c the first character to find
 * @return a pointer to the first occurence
 */
char	*ft_strchr(const char *s, int c);

/**
 * @brief Search for the last occurence of the given character in one string
 *
 * @details Return a poninter to the last occurrence of the givien character in
 * the given string
 * @param s the string to search in
 * @param c the last character to find
 * @return a pointer to the last occurence
 */
char	*ft_strrchr(const char *s, int c);

/**
 * @brief Copy from a src string to a destination up to size - 1 characters and
 * retrurn the size of the result
 *
 * @details Copy untill size - 1 from a src str to a destinantion string a return
 * the size. Is saver than strncpy an the destination string have
 *  the NULL-terminate character
 * @param dst the destination string
 * @param src the source string
 * @param size the size of character that we whant to copy
 * @return the size of the result string
 */
size_t	ft_strlcpy(char *dst, const char *src, size_t size);

/**
 * @brief concatenate from a src string to a destination up to size - 1
 * characters and retrurn the size of the result
 *
 * @details concatenate untill size - 1 from a src str to a destinantion
 * string a return the size. Is saver than strncat an the destination string have
 *  the NULL-terminate character
 * @param dst the destination string
 * @param src the source string
 * @param size the size of character that we whant to concatenate
 * @return the size of the result string
 */
size_t	ft_strlcat(char *dst, const char *src, size_t size);

/**
 * @brief Compare two strings until the given size
 *
 * @details Compare two strings until the given size
 * @param s1 first string to compare
 * @param s2 second string to compare
 * @param n size untill we want to compare
 * @return return (0) if s1 and s2 are equal, negative if s1 is less than s2 and
 * positvie if s1 is greater than s2
 */
int		ft_strncmp(const char *s1, const char *s2, size_t n);

/**
 * @brief Locate the first ocurrence of string little in string big
 *
 * @details Locate the first ocurrence of string little
 * @param big string in which we are searching
 * @param little string to search for
 * @param len size of character to search
 * @return If little is empty, big is returned, if little not found NULL is
 * returned otherwise it will return a pointer to the first character of the
 * first ocurrence of little
 */
char	*ft_strnstr(const char *big, const char *little, size_t len);

/**
 * @brief Transform a string representing a number to an integer
 *
 * @details Given a string of character it will return the integer found in the
 * string
 * @param nptr string representing a number to find th integer
 * @return return the integer
 */
int		ft_atoi(const char *nptr);

/**
 * @brief Scans the initial n bytes of s for the first instance of c.
 *
 * @details Scans the initial n bytes of s for the first instance of c.
 * @param s memory to search
 * @param c char to search
 * @param n size to search
 * @return return void pointer
 */
void	*ft_memchr(const void *s, int c, size_t n);

/**
 * @brief Copy n bytes of s for the src memory to the destination memroy
 *
 * @details Copy n bytes of s for the src memory to the destination memroy
 * @param src memory to copy
 * @param dest destination memory to copy
 * @param n size to searcha
 * @return return void pointer
 */
void	*ft_memcpy(void *dest, const void *src, size_t n);

/**
 * @brief Fills n bytes of the memory s with constant type
 *
 * @details Fills n bytes of the memory s with constant type
 * @param s memory to set
 * @param c char to set
 * @param n size to set
 * @return return void pointer
 */
void	*ft_memset(void *s, int c, size_t n);

/**
 * @brief Fills n bytes of the memory s with 0
 *
 * @details Fills n bytes of the memory s with 0
 * @param s memory to set
 * @param n size to set
 */
void	ft_bzero(void *s, size_t n);

/**
 * @brief Compare the first n bytes dof memory s1 with memory s2
 *
 * @details Compare the first n bytes dof memory s1 with memory s2
 * @param s1 memory to compare
 * @param s2 memory to compare
 * @param n bytes to compare
 * @return return 0 or positive or negative depending on the comparison
 */
int		ft_memcmp(const void *s1, const void *s2, size_t n);

/**
 * @brief Copy from src to destine the n bytes of memory.
 *
 * @details Copy from src to destine the n bytes of memory. The areas may overlap
 * @param src memory source
 * @param src memory of destination
 * @param n bytes to move
 * @return return pointer to void
 */
void	*ft_memmove(void *dest, const void *src, size_t n);

/**
 * @brief Allocate memory of a determined size
 *
 * @details Allocate memory of a determined size. The memory is set to 0
 * @param nmemb size of the memory to allocate
 * @param size size of the object type to allocate
 * @return return pointer void
 */
void	*ft_calloc(size_t nmemb, size_t size);

/**
 * @brief Returns a pointer that is a duplicatate of the string s
 *
 * @details Returns a pointer that is a duplicatate of the string s
 * @param s string to duplicate
 * @return return the string duplicated
 */
char	*ft_strdup(const char *s);

/**
 * @brief Iterate a string applying a function a each character
 * 
 * @details Iterate a string and transform each caracter using the given
 * function as parameter.
 * 
 * @param s the string to iterate
 * @param f the function to apply to each element
 */
void	ft_striteri(char *s, void (*f)(unsigned int, char*));

/**
 * @brief Integer to string conversion
 *
 * @details Given a integer it will transform it to string
 * @param n the integer
 * @return return the string representing de number
 */
char	*ft_itoa(int n);

/**
 * @brief Writes a char in a file descriptor
 *
 * @details  Writes a char in a file descriptor
 * @param c the char to write
 * @param fd the file descriptor
 */
void	ft_putchar_fd(char c, int fd);

/**
 * @brief Write a string to the file descriptor with an end of line
 *
 * @details Write a string to the file descriptor with an end of line
 * @param s string to write
 * @param fd the file descriptor
 */
void	ft_putendl_fd(char *s, int fd);

/**
 * @brief Writes a number in a file descriptor
 *
 * @details Writes a number in a file descriptor
 * @param n number to write
 * @param fd the file descriptor
 */
void	ft_putnbr_fd(int n, int fd);

/**
 * @brief Write a string to the file descriptor
 *
 * @details Write a string to the file descriptor
 * @param s string to write
 * @param fd the file descriptor
 */
void	ft_putstr_fd(char *s, int fd);

/**
 * @brief Split a string delimiting by the given char
 *
 * @details Split a string in substring using the given char as delimiter
 * @param s string to divide
 * @param c char used as delimiter
 * @return return an array of substring
 */
char	**ft_split(char const *s, char c);

/**
	 * @brief Iterate a string and apply the given function to each character
	 *
	 * @details Apply a function to eacha caracter of one function
	 * @param s string to iterate for
	 * @param f function to apply to each character
	 */

/**
	 * @brief Iterate a string and apply the given function to each character
	 *
	 * @details Apply a function to eacha caracter of one function
	 * @param s string to iterate for
	 * @param f function to apply to each character
	 * @return the new string using malloc with the aplication of the funcion
	 * f to each caracter
	 */
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));

/**
 * @brief Join two strings
 *
 * @details Join two string reserving memory with malloc
 * @param s1 first string to join
 * @param s2 second string to join
 * @return return string result from the join
 */
char	*ft_strjoin(char const *s1, char const *s2);

/**
 * @brief Trim character given from the start and end of a chain
 *
 * @details Trim the given character from the start and the end untill find a
 * char that it is not in the string
 * @param s1 string to trim
 * @param set character set to remove
 * @return return the new string
 */
char	*ft_strtrim(char const *s1, char const *set);

/**
 * @brief Get a substring in a string from a position given
 *
 * @details Return a substring in the given string with a max lenght of len and
 * startin at the start given position
 * @param s the string to work with
 * @param start the start position of the substring
 * @param len lenght of the result string
 * @return return the substring
 */
char	*ft_substr(char const *s, unsigned int start, size_t len);

/**
 * @brief Add a node at the end of a list
 *
 * @details take a new node and added it to the end of the string
 * @param lst the list to work withs
 * @param new the new content node
 */
void	ft_lstadd_back(t_list **lst, t_list *new);

/**
 * @brief Return the list size
 *
 * @details Return the list size
 * @param lst the list
 * @return return list size
 */
int		ft_lstsize(t_list *lst);

/**
 * @brief Create a new list
 *
 * @details  Create a new list with te content given
 * @param content list content
 * @return return the new list
 */
t_list	*ft_lstnew(void *content);

/**
 * @brief Iterate a list and apply the funcion to each node
 *
 * @details Iterate a list and apply the funcion to each node. Return an correct
 * and sucesive list of the function. Using del if delete a node is needed
 * @param lst the list
 * @param f function to apply
 * @param del function to delete node
 * @return return the correct list
 */
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

/**
 * @brief Return the last list node
 *
 * @details Return the last list node
 * @param lst the list
 * @return return list node
 */
t_list	*ft_lstlast(t_list *lst);

/**
 * @brief Iterate list and apply the function f to each node
 *
 * @detailsIterate list and apply the function f to each node
 * @param lst the list
 * @param f function to apply to each node
 */
void	ft_lstiter(t_list *lst, void (*f)(void *));

/**
 * @brief Free one node
 *
 * @details Free the memory of the content using the funcion free. The memory of
 * next can't be free
 * @param lst node to liberate
 * @param del function to apply for liberation
 */
void	ft_lstdelone(t_list *lst, void (*del)(void *));

/**
 * @brief Free the node lst and the rest consecutive
 *
 * @details Free the node lst and the rest consecutive
 * @param lst the pointer to the node
 * @param del function to free the content node
 */
void	ft_lstclear(t_list **lst, void (*del)(void *));

/**
 * @brief Add a node at the start of a list
 *
 * @details take a new node and added it to the start of the string
 * @param lst the list to work withs
 * @param new the new content node
 */
void	ft_lstadd_front(t_list **lst, t_list *new);

#endif
