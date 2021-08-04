#include <iostream>
#include <string>

int main(void) {

    std::pair<std::string, int> my_pair;
    my_pair = std::make_pair("Ionica", 20);

    std::cout << my_pair.first << " has " << my_pair.second << " years old!" << "\n";
    return 0;
}