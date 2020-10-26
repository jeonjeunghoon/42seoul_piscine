
	#include <stdio.h>
	#include <stdarg.h>
	#include <string.h>
	#include <stdlib.h>

int					is_valid(char *base);
int					make_digit(char *str, char *base, int len);
int					make_digit_len(int digit, int len);
char				*ft_itoa(int digit, char *base, int len);
char				*ft_convert_base(char *nbr, char *base_from, char *base_to);

int main()
{
	
	printf("%d\n", get_length_to_allocate(0, "0123456789"));
	printf("%s\n", ft_convert_base("2147483647", "0123456789", "0123456789abcdef"));
	printf("%s\n", ft_convert_base("-2147483648", "0123456789", "0123456789abcdef"));
	printf("%s\n", ft_convert_base("-----7fffffff", "0123456789abcdef", "01"));
	printf("%s\n", ft_convert_base("-++--+--0001023a", "0123456789", "0123456789"));
	printf("%s\n", ft_convert_base("-0", "0123456789", "abcdefghij"));
	printf("%s\n", ft_convert_base(" \t\t\t ---+++ff-f", "0123456789abcdef", "0123456789"));
	printf("%s\n", ft_convert_base("aasdffeessddfffss", "asedf", "ss"));
	printf("%s\n", ft_convert_base("-+-+- -+asdf", "asdf", "fdsa"));
	printf("%s\n", ft_convert_base("  -+-+- -+asdf", "ai sdf", "fdsa"));
	printf("%s\n", ft_convert_base("\t\t\t\t \v --++-asdf", "asdf", "fd-as"));
	printf("%s\n", ft_convert_base("   -+a", "abcde", ""));
	printf("%s\n", ft_convert_base(" -+a", "", "df"));
}
