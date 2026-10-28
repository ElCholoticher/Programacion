#include <iostream>

char num;

int main (){

    std::cout << "Ingrese una letra: ";
    std::cin >> num;
    switch (num)
    {
    case 'A':
        std::cout << "La letra es A" << std::endl;
        break;
    
    default:
        std::cout << "La letra no es A" << std::endl;
        break;
    }

}
