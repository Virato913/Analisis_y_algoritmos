/******************************************************************************
**                                                                           **
* @file     Source.cpp
* @author   Alberto Villa
* @date     2019/05/09
* @brief	
**                                                                           **
******************************************************************************/

#include "Bubble.h"
#include "Insert.h"
#include "Vector.h"
#include "Timer.h"

int main() {
  Vector v;
  v.fill(5, Type::kDescending);
  v.print();
  Timer start, end;
  start.setCurrentTime();
  Bubble::sort(v);
  end.setCurrentTime();
  auto time = Timer::getDifference(start, end);
  v.print();
  system("PAUSE");
}
