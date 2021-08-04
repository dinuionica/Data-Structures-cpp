#include "templates.hpp"

int main(void) {    
    
    // test for integer number
    std::cout << getmax<int>(2,3) << "\n";

    // test for double number
    std::cout << getmax<double>(2.3, 4.5) << "\n";

    // array with integers
    GenericArray<char> array(10);    

    array.AddElement('a');
    array.AddElement('b');

    array.ShowAllElements();

    return 0;
}