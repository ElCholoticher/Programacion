#include <iostream>

int numero;
int numero2;
int suma , resta , multi;
int division;

int main() {

    std::cout << "Ingrese un numero: ";
    std::cin >> numero; 
    std::cout << "Ingrese otro numero: ";
    std::cin >> numero2;
    suma = numero + numero2;
    resta = numero - numero2;
    multi = numero * numero2;
    division = numero / numero2;
    std::cout << "La suma es: " << suma << std::endl;
    std::cout << "La resta es: " << resta << std::endl;
    std::cout << "La multi es: " << multi << std::endl;
    std::cout << "La division es: " << division << std::endl;
    std::cin.ignore();
    std::cin.get();
    return 0;   
    
}
