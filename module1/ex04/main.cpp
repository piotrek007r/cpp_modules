#include "repertory.hpp"


int main(int argc, char **argv)
{
    if(argc < 4 || argc > 4)
    {
        cout << "Invalid number of parameters" << endl;
        return 1;
    }

    str file = argv[1];
    str s1 = argv[2];
    str s2 = argv[3];
    str newline;
    size_t pos = 0;
    size_t s1len = s1.length();
    ifstream inFile(file.c_str());

    if(s1.empty())
    {
        cout << "Second parameter connot be empty!";
        return 1;
    }

    if(inFile.fail())
    {
        cout << "Failed to open a file" << endl;
        return 1;
    }

    stringstream buffer;
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
    ofstream outFile((file + ".replace").c_str());
    if(!outFile)
    {
        cout << "Failed to create new file!";
        return 1;
    }
    outFile << newline;
    return 0;
}