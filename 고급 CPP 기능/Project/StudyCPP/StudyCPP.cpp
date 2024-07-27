#include <iostream>
#include "Template.h"

int main(int argc, char* argv[])
{
    std::cout << max(3, 7) << std::endl;
    std::cout << max(3.5, 7.2) << std::endl;
    std::cout << max('a', 'b') << std::endl;

    Pair<int> intPair(1, 2);
    Pair<double> doublePair(3.5, 4.5);
    Pair<const char*> charPair("hello", "world");

    std::cout << "Int Pair: " << intPair.getFirst() << ", " << intPair.getSecond() << std::endl;
    std::cout << "Double Pair: " << doublePair.getFirst() << ", " << doublePair.getSecond() << std::endl;
    std::cout << "Char Pair comparison: " << charPair.compare() << std::endl;
    
    
    return 0;
}
