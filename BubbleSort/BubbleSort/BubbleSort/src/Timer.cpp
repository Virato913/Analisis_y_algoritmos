/******************************************************************************
**                                                                           **
* @file     Timer.cpp
* @author   Alberto Villa
* @date     2019/05/09
* @brief	  Implementation of Timer.h
**                                                                           **
******************************************************************************/

#include "Timer.h"

Timer::Timer() {

}

Timer::~Timer() {

}

void
Timer::setCurrentTime() {
  m_time = high_resolution_clock::now();
}

constexpr long long
Timer::getDifference(Timer start, Timer end) {
  return std::chrono::duration_cast<nanoseconds>(end.m_time - start.m_time).count();
}
