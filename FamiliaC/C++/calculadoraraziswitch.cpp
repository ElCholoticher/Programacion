#include <iostream>
#include <cmath>

int cantidad;
int suma, resta, multiplicacion, division;
int num1 , num2 , num3 , num4;
int op;
double base , exponente , potencia3 , potencia4 , exponente2 , exponente3;

int main() {
    std::cout << "Bienvenido a la calculadora" << std::endl;
    std::cout << "Ingrese la cantidad de números a usar en su operación (máximo 4): ";
    std::cin >> cantidad;
    switch (cantidad)
    {
    case 1/**/:
        std::cout << "Introduce un numero para obtener su raíz cuadrada ";
        std::cin >> num1;   
        std::cout << "El resultado de la raíz cuadrada es: " << sqrt(num1) << std::endl;
        break;
    case 2:
        std::cout << "Ingrese la operación a realizar (1: suma, 2: resta, 3: multiplicación, 4: division, 5: potencia): ";
        std::cin >> op;
        switch (op)
        {
        case 1:
            suma = num1 + num2;
            std::cout << "El resultado de la suma es: " << suma << std::endl;
            break;
        case 2:
            resta = num1 - num2;
            std::cout << "El resultado de la resta es: " << resta << std::endl;
            break;

        case 3:
            multiplicacion = num1 * num2;
            std::cout << "El resultado de la multiplicación es: " << multiplicacion << std::endl;
            break;
        case 4:
            std::cout << "Ingrese el primer numero (dentro de la division): ";
            std::cin >> num1;
            std::cout << "Ingrese el segundo numero (fuera de la division): ";
            std::cin >> num2;   
            division = num1 / num2;
            std::cout << "El resultado de la division es: " << division << std::endl;
            break;
        case 5:
            std::cout << "Ingrese la base: ";
            std::cin >> base;
            std::cout << "Ingrese el exponente: ";
            std::cin >> exponente;
            std::cout << "El resultado de la potencia es: " << pow(base , exponente) << std::endl;
            break;
        
        default:
            std::cout << "El numero ingresado no es valido." << std::endl;
            break;
        }
        break;
    case 3:
        std::cout << "Ingrese la operación a realizar (1: suma, 2: resta, 3: multiplicación, 4: division, 5: potencia): ";
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
            if (num2 == 0 || num3 == 0) {
                std::cout << "Error: No se puede dividir entre cero." << std::endl;
            } else {
                division = num1 / num2 / num3;
                std::cout << "El resultado de la division es: " << division << std::endl;
            }
            break;
        case 5:
            std::cout<< "Primero se calculara la potencia de dos números, luego se elevara a el tercer numero ingresado" << std::endl;
            std::cout << "Ingrese la base: ";
            std::cin >> base;
            std::cout << "Ingrese el exponente: ";
            std::cin >> exponente;
            potencia3=pow(base , exponente);
            std::cout << "ingrese el siguiente exponente: ";
            std::cin >> exponente2;
            std::cout << "El resultado de la potencia es: " << pow(potencia3 , exponente2) << std::endl;
            break;
        default:
            std::cout << "El numero ingresado no es valido." << std::endl;
            break;
        }
        break;
    case 4:
        std::cout << "Ingrese la operación a realizar (1: suma, 2: resta, 3: multiplicación, 4: division, 5: potencia): ";
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
        case 5:
            std::cout<< "Primero se calculara la potencia de dos números, luego se elevara a el tercer numero ingresado y finalmente a el cuarto numero ingresado" << std::endl;
            std::cout << "Ingrese la base: ";
            std::cin >> base;
            std::cout << "Ingrese el exponente: ";
            std::cin >> exponente;
            potencia3=pow(base , exponente);
            std::cout << "ingrese el siguiente exponente: ";
            std::cin >> exponente2;
            potencia4=pow(potencia3 , exponente2);
            std::cout << "ingrese el siguiente exponente: ";
            std::cin >> exponente3;
            std::cout << "El resultado de la potencia es: " << pow(potencia4 , exponente3) << std::endl;
            break;
        }
        break;
    default:
    std::cout << "El numero ingresado no es valido." << std::endl;
        break;
    }   
}
