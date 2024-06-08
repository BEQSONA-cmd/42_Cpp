#include <iostream>
#include <fstream>
#include <string>
#define YELLOW "\033[1;33m"
#define GREEN "\033[1;32m"
#define RED "\033[1;31m"
#define BLUE "\033[1;34m"
#define RESET "\033[0m"

void replace_on_pos(std::string& line, size_t pos, size_t len, const std::string& s2)
{
	line.erase(pos, len);
	line.insert(pos, s2);
}

std::string replace_strings(const std::string& line, const std::string& s1, const std::string& s2)
{
	std::string result = line;
	size_t pos = 0;
	while ((pos = result.find(s1, pos)) != std::string::npos)
	{
		// std::cout << YELLOW "Found " << s1 << " at position " << pos << RESET << std::endl;
		replace_on_pos(result, pos, s1.length(), s2);
		pos += s2.length();
	}
	return result;
}

int process_files(const std::string& infile, const std::string& s1, const std::string& s2, const std::string& outfile)
{
	int status = 0;
    std::ifstream ifs(infile.c_str());
    if (!ifs.is_open())
    {
        std::cerr << RED "Error: could not open file." RESET << std::endl;
        return 1;
    }
    std::ofstream ofs(outfile.c_str());

    std::string line;
	std::string result;
    while (std::getline(ifs, line))
    {
        result = replace_strings(line, s1, s2);
		if(result != line)
			status = 1;
        ofs << result << std::endl;
    }
	if(status == 0)
		std::cerr << RED "Error: no occurence of " << s1 << " found in file." RESET << std::endl;
    ifs.close();
    ofs.close();
    return 0;
}

int	main(int ac, char **av)
{
	std::string file;
	if (ac != 4)
		std::cout << RED "Usage: ./sed_replace [file] [s1] [s2]" RESET << std::endl;
	else
	{
		file = av[1] + std::string(".replace");
		if(!process_files(av[1], av[2], av[3], file))
			std::cout << GREEN "File " << file << " created with the replaced content." RESET << std::endl;
	}
	return (0);
}
