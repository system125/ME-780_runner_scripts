/*
 * run_q2_test_types.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "run_q2_test".
 *
 * Model version              : 1.44
 * Simulink Coder version : 9.6 (R2021b) 14-May-2021
 * C source code generated on : Tue Dec 12 08:01:40 2023
 *
 * Target selection: quarc_win64.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_run_q2_test_types_h_
#define RTW_HEADER_run_q2_test_types_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#include "zero_crossing_types.h"

/* Model Code Variants */
#ifndef DEFINED_TYPEDEF_FOR_struct_wMsc3CgFqIXYmuQYnOzvCC_
#define DEFINED_TYPEDEF_FOR_struct_wMsc3CgFqIXYmuQYnOzvCC_

typedef struct {
  real_T Kp;
  real_T Ki;
  real_T Kd;
  real_T a;
  real_T Ti;
  real_T K;
  real_T Ta;
  real_T Td;
} struct_wMsc3CgFqIXYmuQYnOzvCC;

#endif

/* Parameters (default storage) */
typedef struct P_run_q2_test_T_ P_run_q2_test_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_run_q2_test_T RT_MODEL_run_q2_test_T;

#endif                                 /* RTW_HEADER_run_q2_test_types_h_ */
