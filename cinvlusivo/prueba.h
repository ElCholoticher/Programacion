
#ifndef CPP_INCLUSIVO_H
#define CPP_INCLUSIVO_H

#include <iostream>
#include <string>

using entero = int;
using decimal = float;
using doble = double;
using logico = bool;
using caracter = char;
using cadena = std::string;

template <typename T>
inline void mostrar(const T& valor) {
    std::cout << valor;
}

template <typename T>
inline void leer(T& valor) {
    std::cin >> valor;
}


#endif
