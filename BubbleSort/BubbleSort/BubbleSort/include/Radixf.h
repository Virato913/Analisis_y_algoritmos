/******************************************************************************
**                                                                           **
* @file     Radixf.h
* @author   Alberto Villa
* @date     2019/06/03
* @brief	  
**                                                                           **
******************************************************************************/

#pragma once

#include "Vectorf.h"

/**
*  Description:
*
*  Sample usage:
*
*/
namespace Radixf
{
  float
    getMax(Vectorf v);

  void
    expSort(Vectorf& v, int exp);

  void
    sort(Vectorf& v);
};
