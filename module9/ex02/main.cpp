#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
    if(argc > 1)
    {   
        std::vector<int> seq_v;
        std::list<int> seq_lst;
        for(int i = 1; i < argc; i++)
        {
            std::string tok;
            std::istringstream iss(argv[i]);
            int num;
            while(iss >> tok)
            {
                std::istringstream isInt(tok);
                if(!(isInt >> num) || num < 0)
                {
                    std::cerr << "Error: invalid argument!" << std::endl;
                    return 1;
                }
                seq_v.push_back(num);
                seq_lst.push_back(num);
            }
        }
        PmergeMe pmMergeMe(seq_v, seq_lst);

        pmMergeMe.main();

    }
    else
    {
        std::cerr << "Error: Invalid number of argument!" << std::endl;
        return 1;
    }
    return 0;
}

// consider checking for double and float
