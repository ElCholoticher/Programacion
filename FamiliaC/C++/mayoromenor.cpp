#include <iostream>
int numero;
int numero2;

int main(){

    std::cout << "Ingrese un numero: ";
    std::cin >> numero; 
    std::cout << "Ingrese otro numero: ";
    std::cin >> numero2;
    if (numero > numero2){
        std::cout << "El primer numero es mayor que el segundo" << std::endl;
    } else if (numero < numero2){
        std::cout << "El segundo numero es mayor que el primero" << std::endl;
    } else {
        std::cout << "Los numeros son iguales" << std::endl;
    }
    std::cin.ignore();
    std::cin.get();
    return 0;

}
