/******************************************************************************
**                                                                           **
* @file     Main.cpp
* @author   Alberto Villa
* @date     2019/05/02
* @brief	  Fibonacci sequence
**                                                                           **
******************************************************************************/

#include <iostream>
#include <chrono>

/**
*  @brief  Fibonacci sequence on requested place (recursive)
*  @param  n int to mark the place at which the algorithm should search a value
*  @return Value found on place n
*/
int
FibonacciRecursiva(int n);

/**
*  @brief  Fibonacci sequence on requested place (non recursive)
*  @param  n int to mark the place at which the algorithm should search a value
*  @return Value found on place n
*/
int
FibonacciNoRecursiva(int n);

int main() {
  int numero = 0, resultado = 0;
  std::cout << "Introduce el número en la secuencia de Fibonacci que quieres calcular: ";
  std::cin >> numero;
  auto start = std::chrono::high_resolution_clock::now();
  resultado = FibonacciRecursiva(numero);
  auto end = std::chrono::high_resolution_clock::now();
  std::cout << "Resultado: " << resultado << " en " <<
    std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count() <<
    " nanosegundos para el algoritmo recursivo.\n";
  start = std::chrono::high_resolution_clock::now();
  resultado = FibonacciNoRecursiva(numero);
  end = std::chrono::high_resolution_clock::now();
  std::cout << "Resultado: " << resultado << " en " <<
    std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count() <<
    " nanosegundos para el algoritmo no recursivo.\n";
  system("pause");
  return 0;
}

int
FibonacciRecursiva(int n) {
  if(n <= 1) {
    return n;
  }
  else {
    return FibonacciRecursiva(n - 1) + FibonacciRecursiva(n - 2);
  }
}

int
FibonacciNoRecursiva(int n) {
  int n1 = 0;
  int n2 = 1;
  if(n <= 1) {
    return n;
  }
  else {
    int f = 0;
    for(int i = 1; i < n; ++i) {
      f = n1 + n2;
      n1 = n2;
      n2 = f;
    }
    return f;
  }
}
