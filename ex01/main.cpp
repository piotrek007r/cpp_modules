#include "repertory.hpp"

// class here

class Phonebook
{
    public:
	    Phonebook();
	    ~Phonebook();

        void add();
        void search();

    private:
        int max;
        int current_nb;
        int nb_count;

        // Contact contact_arr[8];

};

class Contact
{
    public:
        Contact();
        ~Contact();

    private:
        str name;
        str surname;
        str phone_number;
        str adress;

};

Phonebook::Phonebook()
{
    std::cout << "constructor set" << std::endl;
}

Phonebook::~Phonebook()
{
    std::cout << "deconstruction" << std::endl;
    
}

void Phonebook::add()
{
    str name;
    str surname;
    str phone_num;
    str adress;

    std::cout << "type name" << std::endl;
    std::getline(std::cin, name); 
    std::cout << "type surname" << std::endl;
    std::getline(std::cin, surname); 
    std::cout << "type phone_num" << std::endl;
    std::getline(std::cin, phone_num); 
    std::cout << "type adress" << std::endl;
    std::getline(std::cin, adress); 


}

int	main(void)
{
	Phonebook phonebook;

    str line;
    str add = "ADD";
    str search = "SEARCH";
    str exit = "EXIT";


    while(1)
    {
        std::cout << "please type ADD, SEARCH or EXIT" << std::endl;
        std::getline(std::cin, line);
        if(!line.compare(add))
            phonebook.add();
        if(!line.compare(search))
            phonebook.search();
        if(!line.compare(exit))
        {
            std::cout << "closing app" << std::endl;
            // cleaning is nesesary?
            break;
        }
    }
    sleep(1);
    system("clear");   
}