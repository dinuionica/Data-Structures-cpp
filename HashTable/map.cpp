#include <iostream>
#include <string>
#include <unordered_map>

int main(void) {

    std::unordered_map<std::string, int> my_map;

    my_map["Mark"] = 10;
    my_map["John"] = 9;

    if (my_map.find("Mark") == my_map.end()) {
        std::cout << "No" << "\n";
    } else {
        std::cout << "Yes" << "\n";
    }

    return 0;
}