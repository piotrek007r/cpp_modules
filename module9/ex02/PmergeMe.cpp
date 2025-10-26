#include "PmergeMe.hpp"

void    printLoser(std::vector<vectorEl> vector)
{
        std::cout << std::endl;
        std::vector<vectorEl>::iterator losers = vector.begin();
        
        std::cout << "losers!: \n";
        for(;losers != vector.end(); losers++)
        {
            std::cout << losers->number << " "; 
        }
        std::cout << std::endl;
}

void printList(std::list<listEl> list)
{
            iterLst winners = list.begin();
        
        std::cout << "winners!: \n";
        for(;winners != list.end(); winners++)
        {
            std::cout << winners->number << " "; 
        }
        std::cout << std::endl;
}

void printVector(std::vector<vectorEl> vector)
{
            iter winners = vector.begin();
        
        std::cout << "winners!: \n";
        for(;winners != vector.end(); winners++)
        {
            std::cout << winners->number << " "; 
        }
        std::cout << std::endl;
}

PmergeMe::PmergeMe(std::vector<int> vec, std::list<int> lst) : level(0)
{
    std::list<int>::iterator iTlist = lst.begin();
    for(; iTlist != lst.end(); iTlist++)
    {
        listEl listEl;
        listEl.number = *iTlist;
        listEl.loseTo = list.end();
        listEl.winTo = list.end();
        this->list.push_back(listEl);
    }
    std::vector<int>::iterator itVec = vec.begin();
    for(; itVec != vec.end(); itVec++)
    {
        vectorEl vectorEl;
        vectorEl.number = *itVec;
        vectorEl.loseTo = -1;
        vectorEl.winTo = -1;
        this->vector.push_back(vectorEl);
    }
}

iterLst findLoserList(iterLst prev, iterLst next)
{
    if(prev->number < next->number)
    {
        prev->loseTo = next;
        next->winTo = prev;
        return prev;
    }
    else
    {
        next->loseTo = prev;
        prev->winTo = next;
        return next;
    }
}

iter findLoserVector(iter prev, iter next)
{
    if(prev->number < next->number)
    {
        prev->loseTo = next->number;
        next->winTo = prev->number;
        return prev;
    }
    else
    {
        next->loseTo = prev->number;
        prev->winTo = next->number;
        return next;
    }
}

bool isOdd(int listSize)
{
    if(listSize % 2 == 1)
        return true;
    return false;
} 

void PmergeMe::insertionList()
{
    size_t iterNum = list.size() -1;
    for(size_t i = 0; i < iterNum; i++)
    {
        iterLst revIt = --list.end();
        if(revIt->winTo == list.end())
            revIt->winTo = list.begin();
        iterLst elToCompare = revIt->loseTo;
        iterLst elToSclice = revIt;
        while(true)
        {
            iterLst prev = elToCompare;
            prev--;
            if((elToSclice->number > prev->number) || (elToCompare == list.begin()))
            {
                list.splice(elToCompare, list, elToSclice);
                break;
            }
            if(elToCompare == list.begin())
                break;
            elToCompare--;
        }
    }
    // printList(this->list);
}

void PmergeMe::mergeList()
{
    iterLst winLosBoundry;
    bool flag = false;
    size_t winnerNum = list.size();
    size_t mergeNum = 0;
    
    while(true)
    {
        iterLst it = ++list.begin(); // c++98 way of setting iterator on second element 
        iterLst elToSplice;
        this->level = 0;
        size_t sizeList = winnerNum;
        mergeNum = winnerNum / 2;
        for(size_t i = 0; i < mergeNum; i++)
        {
            iterLst prev = it;
            level++;
            prev--; 
            elToSplice = findLoserList(prev, it);
            winnerNum--;
            if(!flag)
            {
                flag = true;
                winLosBoundry = elToSplice;
            }
            if(level == mergeNum && isOdd(sizeList))
            {
                std::advance(it, 1);
                list.splice(list.end(), list, elToSplice);
                break;
            }
            else if(level < sizeList / 2)
                std::advance(it, 2);
            list.splice(list.end(), list, elToSplice);
        }       
        if(it == winLosBoundry)
            break;
    }
}


void PmergeMe::mergeVector()
{
    size_t winnerNum = vector.size();
    size_t mergeNum = 0;
    iter elToPush;
    
    while(true)
    {
        iter it = ++vector.begin(); // c++98 way of setting iterator on second element 
        this->level = 0;
        size_t sizeList = winnerNum;
        mergeNum = winnerNum / 2;
        for(size_t i = 0; i < mergeNum; i++)
        {
            iter prev = it;
            level++;
            prev--; 
            elToPush = findLoserVector(prev, it);
            winnerNum--;
            c << "run \n";
            if(level == mergeNum && isOdd(sizeList))
            {
                // std::advance(it, 1);
                c << "element to be pushed: " << elToPush->number << e;
                loserVector.push_back(*elToPush);
                vector.erase(elToPush);
                c << "Where it after erase is pointing now: " << it->number << e;
                break;
            }
            else if(level < sizeList / 2)
            {
                std::advance(it, 1);
                c << "iterator after advence 2: " << it->number << e;
            }
            c << "element to be pushed: " << elToPush->number << e;
            loserVector.push_back(*elToPush);
            vector.erase(elToPush);
                c << "Where it after erase is pointing now: " << it->number << e;

        }       
        c << "size of the vector: " << vector.size() << e;
        if(vector.size() == 1)
            break;
    }
    printLoser(this->loserVector);
    // printVector(this->vector);
}

void PmergeMe::main()
{
    // mergeList();
    // insertionList();
    mergeVector();
}


    /*
    --> TWO CONTAINER SOLUTION EXAMPLE FOR 8 elements 
    create loser list los_lst
    create size_t level
    create int array lst_size / 2 + 1

 
    loop list jumping every 1 elements <-- level 1 (8 elements 4 iters)
        comparing this and prev or next
        set loser info to lose whom 
        splice loser to los_lst (4 winners and 4 loser 1111) 
        iterator ++
        level ++
        
    loop list jumping every 2 elements <-- level 2 (4 elements 2 iters)
        comparing this and prev or next
        set loser info to lose whom 
        splice loser to los_lst (2 winners and 6 loser 111122) 
        iterator ++
        level ++

    loop list jumping every 2 elements <-- level 3 (2 elements 1 iters)
        comparing this and next
        push loser to end of los_vec (1 winners) (7 loser 11112223)

    3 1 5 6 2 8 4 7 -> 1 3 5 6 4 7 2 8
    
    reverse los_vec (3221111)

    loop los_vec jumping every 1 <--- levels doesn matter or does?

    compare loser and winner from same lv and place before 
        
    */
