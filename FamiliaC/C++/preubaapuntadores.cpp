#include <iostream>

int main() {
    int a = 10;
    int b = 20;
    int* ptrA = &a; 
    int* ptrB = &b; 

    std::cout << "El valor de a es: " << *ptrA << std::endl;
    std::cout << "a esta en: " << ptrA << std::endl;
    std::cout << "El valor de b es: " << *ptrB << std::endl; 
    std::cout << "b esta en: " << ptrB << std::endl;

    *ptrA = 30;
    *ptrB = 40;

    std::cout << "El nuevo valor de a es: " << a << std::endl; 
    std::cout << "El nuevo valor de b es: " << b << std::endl; 

    return 0;
}