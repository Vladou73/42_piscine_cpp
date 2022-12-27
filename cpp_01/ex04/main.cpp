//https://cplusplus.com/doc/tutorial/files/

#include "main.hpp"

std::string	ft_find_replace(std::string input, std::string old_str, std::string new_str)
{
	std::string buff;
    size_t pos = 0;
    size_t new_pos = input.find(old_str); // Get first occurrence
	while (new_pos != std::string::npos) // Repeat till end is reached
	{
		buff += input.substr(pos, new_pos - pos);
        buff += new_str;
		pos = new_pos + old_str.size();
        new_pos = input.find(old_str, new_pos + old_str.size()); // Get next occurrence
	}
    buff += input.substr(pos, new_pos - pos);
	return buff;
}

int main(int argc, char **argv) {
    if (argc != 4) {
        std::cout << "please use 3 arguments for the program to work" << std::endl;
        return 1;
    }

    std::string line;
    std::string filename = argv[1];
    std::ifstream in_file;

    in_file.open(filename.c_str(), std::ios::in);
    if (!in_file.is_open()) {
        std::cout << "please enter a valid existing filename as first argument" << std::endl;
        return 1;
    }

    std::ofstream out_file;
    out_file.open ((filename + ".replace").c_str(), std::ios::out | std::ios::trunc);
    if (!out_file.is_open()) {
        std::cout << "something went wrong with the output file" << std::endl;
        return 1;
    }

    while (std::getline(in_file, line)) {
      out_file << ft_find_replace(line, argv[2], argv[3]) << std::endl;
    }

    if (in_file.is_open())
        in_file.close();
    if (out_file.is_open())
        out_file.close();
    return 0;
}