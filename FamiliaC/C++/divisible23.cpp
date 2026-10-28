#include <iostream>

int num;

int main(){

std::cout<< "ingresa un numero: ";
std::cin >> num;


if (num % 2 == 0 && num % 3 == 0){
    std::cout << "El numero es divisible por 2 y 3." << std::endl;
} else {
    if(num % 2 !=0 && num % 3 ==0){
        std::cout << "El numero es divisible solamente entre 3" << std::endl;
    } else {
        if (num % 2 ==0 && num %3 !=0){
            std::cout  << "El numero es divisible solamente entre 2" << std::endl;
        } else {
            std::cout  << "El numero no es divisible solamente entre 2 y 3" << std::endl;
        }
    }
}

}
