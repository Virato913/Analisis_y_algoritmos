/******************************************************************************
**                                                                           **
* @file     Source.cpp
* @author   Alberto Villa
* @date     2019/05/09
* @brief	
**                                                                           **
******************************************************************************/

#include "Binary.h"
#include "Bubble.h"
#include "Insert.h"
#include "Linear.h"
#include "Merge.h"
#include "Quick.h"
#include "Timer.h"
#include "Vector.h"

int main() {
  Vector v;
  v.fill(5, Type::kRandom);
  v.print();
  Timer start, end;
  start.setCurrentTime();
  Quick::sort(v, 0, v.m_vector.size() - 1);
  end.setCurrentTime();
  auto time = Timer::getDifference(start, end);

  int result = Binary::search(v, 0, v.m_vector.size() - 1, 3);

  (result == -1) ? printf("Element is not present\n")
    : printf("Element is present at index %i\n", result);

  v.print();
  system("PAUSE");
}
