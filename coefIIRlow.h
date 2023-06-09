/*
 * Filter Coefficients (C Source) generated by the Filter Design and Analysis Tool
 * Generated by MATLAB(R) 9.13 and DSP System Toolbox 9.15.
 * Generated on: 05-Apr-2023 12:23:02
 */

/*
 * Discrete-Time IIR Filter (real)
 * -------------------------------
 * Filter Structure    : Direct-Form II, Second-Order Sections
 * Number of Sections  : 2
 * Stable              : Yes
 * Linear Phase        : No
 * Arithmetic          : single
 */

/* General type conversion for MATLAB generated C-code  */
#include "tmwtypes.h"
/* 
 * Expected path to tmwtypes.h 
 * C:\Program Files\MATLAB\R2022b\extern\include\tmwtypes.h 
 */
#define MWSPT_NSEC 5
const int NL[MWSPT_NSEC] = { 1,3,1,3,1 };
const real32_T NUM[MWSPT_NSEC][3] = {
  {
    0.02666378766,              0,              0 
  },
  {
                1,              2,              1 
  },
  {
    0.02291339263,              0,              0 
  },
  {
                1,              2,              1 
  },
  {
                1,              0,              0 
  }
};
const int DL[MWSPT_NSEC] = { 1,3,1,3,1 };
const real32_T DEN[MWSPT_NSEC][3] = {
  {
                1,              0,              0 
  },
  {
                1,   -1.661870599,   0.7685257196 
  },
  {
                1,              0,              0 
  },
  {
                1,   -1.428120136,   0.5197736621 
  },
  {
                1,              0,              0 
  }
};
