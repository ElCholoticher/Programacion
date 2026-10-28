#include <iostream>

int cantidad;
int suma, resta, multiplicacion, division;
int num1 , num2 , num3 , num4;
int op;

int main() {
    std::cout << "Bienvendio a la calculadora" << std::endl;
    std::cout << "Ingrese la cantidad de números a usar en su operación (máximo 4): ";
    std::cin >> cantidad;
    switch (cantidad)
    {
    case 1:
        std::cout << "¿como vas a operar con un numero? ";
        break;
    case 2:
        std::cout << "Ingrese la operación a realizar (1: suma, 2: resta, 3: multiplicación, 4: division): ";
        std::cin >> op;
        switch (op)
        {
        case 1:
            std::cout << "Ingrese el primer numero: ";
            std::cin >> num1;
            std::cout << "Ingrese el segundo numero: ";
            std::cin >> num2;
            suma = num1 + num2;
            std::cout << "El resultado de la suma es: " << suma << std::endl;
            break;
        case 2:
            std::cout << "Ingrese el primer numero: ";
            std::cin >> num1;
            std::cout << "Ingrese el segundo numero: ";
            std::cin >> num2;
            resta = num1 - num2;
            std::cout << "El resultado de la resta es: " << resta << std::endl;
            break;
        case 3:
            std::cout << "Ingrese el primer numero: ";
            std::cin >> num1;
            std::cout << "Ingrese el segundo numero: ";
            std::cin >> num2;
            multiplicacion = num1 * num2;
            std::cout << "El resultado de la multiplicación es: " << multiplicacion << std::endl;
            break;
        case 4:
            std::cout << "Ingrese el primer numero (dentro de la division): ";
            std::cin >> num1;
            std::cout << "Ingrese el segundo numero (fuera de la division): ";
            std::cin >> num2;
            if (num2 == 0) {
                std::cout << "Error: No se puede dividir entre cero." << std::endl;
            } else {
                division = num1 / num2;
                std::cout << "El resultado de la division es: " << division << std::endl;
            }
            break;
        default:
            std::cout << "El numero ingresado no es valido." << std::endl;
            break;
        }
    case 3:
        std::cout << "Ingrese la operación a realizar (1: suma, 2: resta, 3: multiplicación, 4: division): ";
        std::cin >> op;
        switch (op){
            case 1:
                std::cout << "Ingrese el primer numero: ";
                std::cin >> num1;
                std::cout << "Ingrese el segundo numero: ";
                std::cin >> num2;
                std::cout << "Ingrese el tercer numero: ";
                std::cin >> num3;
                suma = num1 + num2 + num3;
                std::cout << "El resultado de la suma es: " << suma << std::endl;
                break;
            case 2:
                std::cout << "Ingrese el primer numero: ";
                std::cin >> num1;
                std::cout << "Ingrese el segundo numero: ";
                std::cin >> num2;
                std::cout << "Ingrese el tercer numero: ";
                std::cin >> num3;
                resta = num1 - num2 - num3;
                std::cout << "El resultado de la resta es: " << resta << std::endl;
                break;
            case 3:
                std::cout << "Ingrese el primer numero: ";
                std::cin >> num1;
                std::cout << "Ingrese el segundo numero: ";
                std::cin >> num2;
                std::cout << "Ingrese el tercer numero: ";
                std::cin >> num3;
                multiplicacion = num1 * num2 * num3;
                std::cout << "El resultado de la multiplicación es: " << multiplicacion << std::endl;
                break;
            case 4:
                std::cout << "Ingrese el primer numero (dentro de la division): ";
                std::cin >> num1;
                std::cout << "Ingrese el segundo numero (fuera de la division): ";
                std::cin >> num2;
                std::cout << "Ingrese el tercer numero (en caso de division, este numero dividirá el resultado de la division con los números anteriores): ";
                std::cin >> num3;
                if (num3 == 0 || num2 == 0) {
                    std::cout << "Error: No se puede dividir entre cero." << std::endl;
                } else {
                    division = num1 / num2 / num3;
                    std::cout << "El resultado de la division es: " << division << std::endl;
                }
                break;
        }

        break;
    case 4:
        std::cout << "Ingrese la operación a realizar (1: suma, 2: resta, 3: multiplicación, 4: division): ";
        std::cin >> op;
        switch (op)
        {
        case 1:
            std::cout << "Ingrese el primer numero: ";
            std::cin >> num1;
            std::cout << "Ingrese el segundo numero: ";
            std::cin >> num2;
            std::cout << "Ingrese el tercer numero: ";
            std::cin >> num3;
            std::cout << "Ingrese el cuarto numero: ";
            std::cin >> num4;
            suma = num1 + num2 + num3 + num4;
            std::cout << "El resultado de la suma es: " << suma << std::endl;
            break;
        case 2:
            std::cout << "Ingrese el primer numero: ";
            std::cin >> num1;
            std::cout << "Ingrese el segundo numero: ";
            std::cin >> num2;
            std::cout << "Ingrese el tercer numero: ";
            std::cin >> num3;
            std::cout << "Ingrese el cuarto numero: ";
            std::cin >> num4;
            resta = num1 - num2 - num3 - num4;
            std::cout << "El resultado de la resta es: " << resta << std::endl;
            break;
        case 3:
            std::cout << "Ingrese el primer numero: ";
            std::cin >> num1;
            std::cout << "Ingrese el segundo numero: ";
            std::cin >> num2;
            std::cout << "Ingrese el tercer numero: ";
            std::cin >> num3;
            std::cout << "Ingrese el cuarto numero: ";
            std::cin >> num4;
            multiplicacion = num1 * num2 * num3 * num4;
            std::cout << "El resultado de la multiplicación es: " << multiplicacion << std::endl;
            break;
        case 4: 
            std::cout << "Ingrese el primer numero (dentro de la division): ";
            std::cin >> num1;
            std::cout << "Ingrese el segundo numero (fuera de la division): ";
            std::cin >> num2;
            std::cout << "Ingrese el tercer numero (en caso de division, este numero dividirá el resultado de la division con los números anteriores): ";
            std::cin >> num3;
            std::cout << "Ingrese el cuarto numero (en caso de division, este numero dividirá el resultado de la division con los números anteriores): ";
            std::cin >> num4;
            if (num2 == 0 || num3 == 0 || num4 == 0) {
                std::cout << "Error: No se puede dividir entre cero." << std::endl;
            } else {
                division = num1 / num2 / num3 / num4;
                std::cout << "El resultado de la division es: " << division << std::endl;
            }
            break;
        
        default:
            std::cout << "El numero ingresado no es valido." << std::endl;
            break;
        }
    }
}
