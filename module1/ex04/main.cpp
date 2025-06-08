#include "repertory.hpp"


int main(int argc, char **argv)
{
    if(argc < 4 || argc > 4)
    {
        std::cout << "Invalid number of parameters" << std::endl;
        return 1;
    }

    std::string file = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];
    std::string newline;
    size_t pos = 0;
    size_t s1len = s1.length();
    std::ifstream inFile(file.c_str());

    if(s1.empty())
    {
        std::cout << "Second parameter connot be empty!" << std::endl;
        return 1;
    }

    if(inFile.fail())
    {
        std::cout << "Failed to open a file" << std::endl;
        return 1;
    }

    std::stringstream buffer;
    buffer << inFile.rdbuf();
    newline = buffer.str();
    inFile.close();

    while(true)
    {
        pos = newline.find(s1, pos);
        if (pos == std::string::npos)
            break;
        newline.erase(pos, s1len);
        newline.insert(pos, s2);
        pos += s2.length();
    }
    std::ofstream outFile((file + ".replace").c_str());
    if(!outFile)
    {
        std::cout << "Failed to create new file!";
        return 1;
    }
    outFile << newline;
    return 0;
}
/*
    testing yes testing again yes and again yes
    new line testing yes --- yes yes yes  
*/
