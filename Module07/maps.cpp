#include <iostream>

#include <map>
#include <unordered_map>
#include <string>

int main()
{
    std::map<std::string, int> m;

    m.emplace("one", 1);
    m.emplace("ten", 12);
    m.emplace("eleven", 11);
    m.emplace("seven", 7);
    m.emplace("seven", 7);
    m.emplace("seven", 7);
    m.emplace("seven", 7);
    m.emplace("three", 3);

    std::cout << "Map\n";

    for (auto [key, value] : m)
    {
        std::cout << key << ": " << value << "\n";
    }

    std::unordered_map<std::string, int> um;

    um.emplace("one", 1);
    um.emplace("ten", 12);
    um.emplace("eleven", 11);
    um.emplace("seven", 7);
    um.emplace("seven", 7);
    um.emplace("seven", 7);
    um.emplace("seven", 7);
    um.emplace("three", 3);

    std::cout << "\nUnordered map\n";

    for (auto [key, value] : um)
    {
        std::cout << key << ": " << value << "\n";
    }

    auto found = um.find("two");

    if (found != um.end())
    {
        std::cout << "Encontrado\n";
    }
    else
    {
        std::cout << "No encontrado\n";
    }

    return 0;
}