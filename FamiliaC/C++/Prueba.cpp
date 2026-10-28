#include <iostream>

int numero;
int numero2;

int main() {

    std::cout << "Ingrese un numero: ";
    std::cin >> numero; 
    std::cout << "Ingrese otro numero: ";
    std::cin >> numero2;
    numero += numero2;
    std::cout << "La suma es: " << numero << std::endl;
    std::cout << "El valor de numero es: " << numero << std::endl;
    return 0;
 
}
