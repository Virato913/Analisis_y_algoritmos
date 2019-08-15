#include <chrono>
#include <cmath>
#include <iostream>
#include <vector>

std::vector<std::string> obtenerSubsecuencias(std::string secuencia) {
  unsigned int n = secuencia.size();

  auto numeroDeSubsecuencias = static_cast<unsigned int>(std::pow(2, n));

  std::vector<std::string> subsecuencias;
  subsecuencias.resize(numeroDeSubsecuencias);

  for(unsigned int i = 1; i < numeroDeSubsecuencias; ++i) {
    std::string subsecuencia;
    for(unsigned int j = 0; j < n; ++j) {
      if(i & (1 << j)) {
        subsecuencia += secuencia[j];
      }
    }
    subsecuencias[i-1] = subsecuencia;
  }
  return subsecuencias;
}

std::string compararSubsecuencias(std::vector<std::string> subsecuencias1,
                                  std::vector<std::string> subsecuencias2) {
  std::string lcs;
  for(const auto& i : subsecuencias1) {
    for(const auto& j : subsecuencias2) {
      if(i == j) {
        if(lcs.size() < i.size()) {
          lcs = i;
        }
      }
    }
  }
  return lcs;
}

int main() {
  std::string secuencia1 = "TTCGCATCGGGTTG";
  std::string secuencia2 = "TGACCGTGTGTCACG";
  std::vector<std::string> subsecuencias1 = obtenerSubsecuencias(secuencia1);
  std::vector<std::string> subsecuencias2 = obtenerSubsecuencias(secuencia2);
  std::chrono::time_point<std::chrono::steady_clock> start =
    std::chrono::high_resolution_clock::now();
  std::string lcs = compararSubsecuencias(subsecuencias1, subsecuencias2);
  std::cout << "---Brute Force---" << std::endl;
  std::cout << "La subsecuencia mas larga comun de " << secuencia1.c_str() <<
    " y de " << secuencia2.c_str() << " es " << lcs.c_str() << std::endl;
  std::chrono::time_point<std::chrono::steady_clock> end =
    std::chrono::high_resolution_clock::now();
  std::cout << "Terminado en: " <<
    std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count() / 1e+9 <<
    " segundos." << std::endl;
  return 0;
}
