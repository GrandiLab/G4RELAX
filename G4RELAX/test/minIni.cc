#include <iostream>
#include <fstream>
#include <map>

int main()
{
    std::string fileName = "RELAX.ini";
    std::map<std::string, std::map<std::string, int> > config;

    std::ifstream configFile(fileName.c_str());
    std::string line;

    if(!configFile)
    {
        std::cout << "Unable to open input file " << fileName;
        return -1;
    }

    else
    {
        std::cout << "Opened the input file " << fileName << std::endl;
    }

    while(configFile)
    {
        getline(configFile, line);
        std::cout << "Line: " << line << std::endl;
    }

    return 0;
}
