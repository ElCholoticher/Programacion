#include <iostream>
int leer;

int main(){
std::cout << "Ingrese un numero: ";
std::cin >> leer;

if (leer == 0) {
    std::cout << "El numero es cero." << std::endl;
} else {
    if (leer > 0) {
        std::cout << "El numero es positivo." << std::endl;
    } else {
        std::cout << "El numero es negativo." << std::endl;
     }
    }
}
