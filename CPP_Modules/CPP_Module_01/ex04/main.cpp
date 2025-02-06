#include <iostream>
#include <fstream>
#include <sstream>

std::string	replace(std::string infile, std::string s1, std::string s2)
{
	std::stringstream	string;
	std::string			tmp;

	int	i = 0;
	while (infile[i])
	{
		tmp = infile.substr(i, s1.size());
		if (tmp == s1)
		{
			string << s2;
			i += s1.size() - 1;
		}
		else
			string << infile[i];
		i++;
	}
	return string.str();
}

int	main(int argc, char** argv)
{
	std::string			string;
	std::stringstream	read;
	std::string			line;

	if (argc != 4) {
		std::cout << "Wrong number of arguments" << std::endl;
		return (1);
	}
	
	std::string			filename = argv[1];
	std::string			s1 = argv[2];
	std::string			s2 = argv[3];
	std::ifstream	ifs(filename.c_str());

	if (!ifs) {
		std::cout << "Wrong filename" << std::endl;
		return 1;
	}
	while (std::getline(ifs, line))
		read << line << std::endl;
	ifs.close();
	string = replace(read.str(), s1, s2);
	std::stringstream	ofilename;
	ofilename << filename << ".replace";
	std::ofstream	ofs(ofilename.str().c_str());
	ofs << string;
	ofs.close();
}