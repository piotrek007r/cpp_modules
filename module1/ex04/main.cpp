#include "repertory.hpp"


int main(int argc, char **argv)
{
    if(argc < 3)
    {
        cout << "Invalid number of parameters" << endl;
        return 1;
    }

    str file = argv[1];
    str s1 = argv[2];
    str s2 = argv[3];
    str newline;
    size_t pos = 0;


    // 1. connect string ta a file name
    ifstream inFile(file.c_str());
    if(inFile.fail())
    {
        cout << "Failed to open a file" << endl;
        return 1;
    }
    // 2. read a string from file and save it
    stringstream buffer;
    buffer << inFile.rdbuf();
    newline = buffer.str();

    while(true)
    {
        pos = newline.find("yes", pos + 1);
        cout << pos << endl;
        if (pos == std::string::npos)
        {
            cout << pos << endl;
            break;
        }
    }
    

    cout << newline << endl;

    // 3. do manipulation on a string than save it
    // 4. create new file and store new string there

}