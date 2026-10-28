#include <iostream>
int main() {
    int num;
    std::cout << "Ingrese un numero: ";
    std::cin >> num;
    if (num % 2 == 0) {
        std::cout << "El numero ingresado es par" << std::endl;
    } else {
        std::cout << "El numero ingresado es impar" << std::endl;
    }
    std::cin.ignore();
    std::cin.get();
    return 0;
}