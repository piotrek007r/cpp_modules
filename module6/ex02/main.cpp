#include "Base.cpp"

int main()
{
    srand(time(NULL));

    std::string input;
    Base *ptr;

    while(1)
    {
        std::cout << "select type: \n1: pointer\n2: reference\n3: exit program\n--------------" << std::endl;
        std::getline(std::cin, input);
        if(input == "1")
        {
            ptr = generate();
            identify(ptr);
            delete ptr;
        }
        else if(input == "2")
        {
            ptr = generate();
            identify(*ptr);
            delete ptr;
        }
        else if(input == "3")
            break;
        else
            std::cout << "wrong type, try again!" << std::endl;
        std::cout << "-----------" << std::endl;
    }

    return 0;
}