#include <iostream>

int num1 , num2 , num3;

int main (){

std::cout << "Ingrese el primer numero: ";
std::cin >> num1;   
std:: cout << "Ingrese el segundo numero: ";
std::cin >> num2;
std:: cout << "Ingrese el tercer numero: ";
std::cin >> num3;

if (num1 > num2 && num1 > num3) {
    std::cout << "El primer numero es el mayor." << std::endl;
} else {
    if (num2 > num1 && num2 > num3) {
        std::cout << "El segundo numero es el mayor." << std::endl;
    } else {
        std::cout << "El tercer numero es el mayor." << std::endl;
     }
    }

}
