#include <iostream>

int resultado, num1, num2;

int sumar(int a, int b) {
    return a + b;
}

int main() {
    std::cout << "Ingrese el primer número: ";
    std::cin >> num1;
    std::cout << "Ingrese el segundo número: ";
    std::cin >> num2;

    resultado = sumar(num1, num2);
    std::cout << "La suma es: " << resultado << std::endl;

    return 0;
}




