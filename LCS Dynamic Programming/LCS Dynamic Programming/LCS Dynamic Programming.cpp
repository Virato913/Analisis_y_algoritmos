#include <vector>
#include <iostream>
#include <cmath>
#include <chrono>

void lcs(std::string X, std::string Y, unsigned int m, unsigned int n) {
  std::vector<std::vector<unsigned int>> L(0);
  L.resize(m + 1);
  for(auto& it : L) {
    it.resize(n + 1);
  }

  for(unsigned int i = 0; i < m + 1; ++i) {
    for(unsigned int j = 0; j < n + 1; ++j) {
      if(i == 0 || j == 0) {
        L[i][j] = 0;
      }
      else {
        if(X[i - 1] == Y[j - 1]) {
          L[i][j] = L[i - 1][j - 1] + 1;
        }
        else {
          L[i][j] = static_cast<unsigned int>(std::fmax(L[i - 1][j], L[i][j - 1]));
        }
      }
    }
  }

  unsigned int index = L[m][n];
  std::string lcs("");
  lcs.resize(index + 1);

  unsigned int i = m;
  unsigned int j = n;
  while((i > 0) && (j > 0)) {
    if(X[i - 1] == Y[j - 1]) {
      lcs[index - 1] = X[i - 1];
      --i;
      --j;
      --index;
    }
    else {
      if(L[i - 1][j] > L[i][j - 1]) {
        --i;
      }
      else {
        --j;
      }
    }
  }

  std::cout << "La subsecuencia mas larga comun de " <<
    X.c_str() << " y de " << Y.c_str() << " es " << lcs.c_str() << std::endl;
}

int main() {
  std::string X("TTCGCATCGGGTTG");
  std::string Y("TGACCGTGTGTCACG");
  std::chrono::time_point<std::chrono::steady_clock> start =
    std::chrono::high_resolution_clock::now();
  std::cout << "---Dynamic Programming---" << std::endl;
  lcs(X, Y, X.size(), Y.size());
  std::chrono::time_point<std::chrono::steady_clock> end =
    std::chrono::high_resolution_clock::now();
  std::cout << "Terminado en: " <<
    std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count() / 1e+9 <<
    " segundos." << std::endl;
  return 0;
}
