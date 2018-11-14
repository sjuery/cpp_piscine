#include <iostream>
#include <fstream>
#include <string>

void createFiles(std::string filename, std::string s1, std::string s2) {
	std::ofstream oldfile;


	oldfile.open(filename);
	std::string filecontent(istreambuf_iterator<char>(infile), istreambuf_iterator<char>());
	std::cout << filecontent << s1 << s2 << std::endl;
}

int main(int argc, char const *argv[]) {
	if(argc == 4)
	{
		createFiles(argv[1], argv[2], argv[3]);
	}
	else
		std::cout << "Usage: ./replace FileName S1 S2";
	return 0;
}
