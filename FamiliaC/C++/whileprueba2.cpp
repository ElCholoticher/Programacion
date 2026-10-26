#include <iostream>

int decision , salto=0;

int main() {

    while (salto < 10) {
        std::cout << "Llevas " << salto << " saltos" << std::endl;
        std::cout << "Quieres saltar otra vez? (1=si, 0=no): "<< std::endl;
        std::cin>>decision;
        if (decision==1) {
            salto++;
        } else {
            break;
        }
    }
    return 0;
}
