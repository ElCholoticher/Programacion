#include <iostream>

int numero;

int main(){

    std::cout << "ingresa un numero:" << std::endl;
    std::cin >> numero;

    if(numero>0){

        std::cout << "El numero ingresado es positivo" << std::endl;
    }
    else if(numero<0){

        std::cout << "El numero ingresado es negativo" << std::endl;
    }
    else{

        std::cout << "El numero ingresado es cero" << std::endl;
    }


}
