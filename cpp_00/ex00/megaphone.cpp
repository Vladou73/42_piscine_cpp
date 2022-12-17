#include <iostream>

char	ft_to_uppercase(int c) {
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}

void	write_str_to_uppercase(char *s) {
	int	i = 0;
	if (!s)
		return;
	while (s[i]) {
		std::cout << ft_to_uppercase(s[i]);
		i++;
	}
}

int main(int argc, char** argv) {
	int	i = 1;
	if (i < argc) {
		while (i < argc) {
			write_str_to_uppercase(argv[i]);
			i++;
		}
		std::cout << std::endl;
	}
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;


	return 0;
}

// int		ft_strlen(char *s) {
// 	int	i = 0;
// 	if (!s)
// 		return (0);
// 	while (s[i])
// 		i++;
// 	return (i);
// }
