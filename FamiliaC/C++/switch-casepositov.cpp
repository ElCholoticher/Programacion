#include <iostream>

int num;
int comparacion;

int main() {

    std::cout << "Ingrese un numero: ";
    std::cin >> num;
    comparacion = (num > 0) ? 1 : (num < 0) ? -1 : 0;
    switch (comparacion)
    {
    case 1:
        std::cout << "El numero es positivo." << std::endl;
        break;
    case -1:
        std::cout << "El numero es negativo." << std::endl;
    
    default:
        std::cout << "El numero es cero." << std::endl;
        break;
    }   


}