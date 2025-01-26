#include <iostream>
#include <omp.h>
#include <vector>
#include <cstdlib>
#include <ctime>

int main() {
    // Solicitamos al usuario la cantidad de elementos del arreglo que debe tener, valores entre 1 y 10,000
    int ARRAY_SIZE;
    do {
        std::cout << "Ingrese la cantidad de elementos del arreglo (entre 1 y 10,000): ";
        std::cin >> ARRAY_SIZE;
        if (ARRAY_SIZE < 1 || ARRAY_SIZE > 10000) {
            std::cout << "Error: debe ingresar un valor entre 1 y 10,000.\n";
        }
    } while (ARRAY_SIZE < 1 || ARRAY_SIZE > 10000);

    // Inicializamos los arreglos
    std::vector<int> A(ARRAY_SIZE);
    std::vector<int> B(ARRAY_SIZE);
    std::vector<int> R(ARRAY_SIZE);

    // Semilla para la generación de números aleatorios
    std::srand(std::time(0));

    // Llenamos los arreglos A y B con valores aleatorios entre 1 y 100
    for (int i = 0; i < ARRAY_SIZE; ++i) {
        A[i] = std::rand() % 100 + 1;
        B[i] = std::rand() % 100 + 1;
    }

    // Realizamos la suma de los arreglos en paralelo utilizando OpenMP
#pragma omp parallel for
    for (int i = 0; i < ARRAY_SIZE; ++i) {
        R[i] = A[i] + B[i];
    }

    // Solicitamos al usuario cuántos elementos desea imprimir, son valores entre 1 y 10,000
    int print_count;
    do {
        std::cout << "Ingrese la cantidad de elementos a imprimir (entre 1 y " << ARRAY_SIZE << "): ";
        std::cin >> print_count;
        if (print_count < 1 || print_count > ARRAY_SIZE) {
            std::cout << "Error: debe ingresar un valor entre 1 y " << ARRAY_SIZE << ".\n";
        }
    } while (print_count < 1 || print_count > ARRAY_SIZE);

    // Imprimimos los elementos solicitados de cada arreglo
    std::cout << "Elementos del arreglo A:" << std::endl;
    for (int i = 0; i < print_count; ++i) {
        std::cout << A[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Elementos del arreglo B:" << std::endl;
    for (int i = 0; i < print_count; ++i) {
        std::cout << B[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Elementos del arreglo R (resultado):" << std::endl;
    for (int i = 0; i < print_count; ++i) {
        std::cout << R[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
