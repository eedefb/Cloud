#include <iostream>
#include <omp.h>

#define N 1000          // Tamaño del arreglo
#define chunk 100       // Tamaño de los pedazos para el schedule
#define mostrar 10      // Número de elementos a imprimir

void imprimeArreglo(float* d);

int main()
{
    std::cout << "Sumando Arreglos en Paralelo!\n";

    // Declaración de arreglos
    float a[N], b[N], c[N];
    int i;

    // Inicialización de los arreglos
    for (i = 0; i < N; i++)
    {
        a[i] = i * 10;
        b[i] = (i + 3) * 3.7;
    }

    int pedazos = chunk;

    // Suma de arreglos en paralelo
#pragma omp parallel for \
    shared(a, b, c, pedazos) private(i) \
    schedule(static, pedazos)
    for (i = 0; i < N; i++)
    {
        c[i] = a[i] + b[i];
    }

    // Imprimir los primeros valores de cada arreglo
    std::cout << "Imprimiendo los primeros " << mostrar << " valores del arreglo a: " << std::endl;
    imprimeArreglo(a);

    std::cout << "Imprimiendo los primeros " << mostrar << " valores del arreglo b: " << std::endl;
    imprimeArreglo(b);

    std::cout << "Imprimiendo los primeros " << mostrar << " valores del arreglo c: " << std::endl;
    imprimeArreglo(c);

    return 0;
}

// Función para imprimir los primeros valores de un arreglo
void imprimeArreglo(float* d)
{
    for (int x = 0; x < mostrar; x++)
    {
        std::cout << d[x] << " ";
    }
    std::cout << std::endl;
}
