#include <iostream>
#include "prueba.h"

int main() {
    int num1, num2, resultado;

    std::cout << "Ingrese el primer número: ";
    std::cin >> num1;
    std::cout << "Ingrese el segundo número: ";
    std::cin >> num2;

    resultado = suma(num1, num2);
    std::cout << "La suma es: " << resultado << std::endl;

    return 0;  
}