/*
 * Filter Coefficients (C Source) generated by the Filter Design and Analysis Tool
 * Generated by MATLAB(R) 9.13 and DSP System Toolbox 9.15.
 * Generated on: 05-Apr-2023 12:15:21
 */

/*
 * Discrete-Time FIR Filter (real)
 * -------------------------------
 * Filter Structure  : Direct-Form FIR
 * Filter Length     : 8
 * Stable            : Yes
 * Linear Phase      : Yes (Type 2)
 * Arithmetic        : fixed
 * Numerator         : s8,7 -> [-1 1)
 * Input             : s12,12 -> [-5.000000e-01 5.000000e-01)
 * Filter Internals  : Full Precision
 *   Output          : s20,19 -> [-1 1)  (auto determined)
 *   Product         : s19,19 -> [-5.000000e-01 5.000000e-01)  (auto determined)
 *   Accumulator     : s20,19 -> [-1 1)  (auto determined)
 *   Round Mode      : No rounding
 *   Overflow Mode   : No overflow
 */

/* General type conversion for MATLAB generated C-code  */
#include "tmwtypes.h"
/* 
 * Expected path to tmwtypes.h 
 * C:\Program Files\MATLAB\R2022b\extern\include\tmwtypes.h 
 */
const int BL = 8;
const int8_T B[8] = {
      0,   -3,    1,   66,   66,    1,   -3,    0
};