/******************************************************************************
**                                                                           **
* @file     Source.cpp
* @author   Alberto Villa
* @date     2019/05/09
* @brief	
**                                                                           **
******************************************************************************/

#include <iostream>

#include "Radixf.h"
#include "Timer.h"
#include "Vectorf.h"

int main() {
  for (int i = 0; i < 100; ++i) {
    Vectorf v;
    //v.fill(5, Type::kRandom);
    v.fill(i + 1);
    //v.print();
    Timer start, end;
    start.setCurrentTime();
    Radixf::sort(v);
    end.setCurrentTime();
    auto time = Timer::getDifference(start, end);

    //int result = Binary::search(v, 0, v.m_vector.size() - 1, 3);

    //(result == -1) ? printf("Element is not present\n")
    //  : printf("Element is present at index %i\n", result);

    //v.print();
    std::cout <</* "Tomo " << */time/* / 1000000000 */ << /*" nanosegundos.*/"\n";
  }
  system("PAUSE");
}
