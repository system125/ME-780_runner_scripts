/*
 * bodeTestRunner_dt.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "bodeTestRunner".
 *
 * Model version              : 1.46
 * Simulink Coder version : 9.6 (R2021b) 14-May-2021
 * C source code generated on : Sun Dec 10 17:24:57 2023
 *
 * Target selection: quarc_win64.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "ext_types.h"

/* data type size table */
static uint_T rtDataTypeSizes[] = {
  sizeof(real_T),
  sizeof(real32_T),
  sizeof(int8_T),
  sizeof(uint8_T),
  sizeof(int16_T),
  sizeof(uint16_T),
  sizeof(int32_T),
  sizeof(uint32_T),
  sizeof(boolean_T),
  sizeof(fcn_call_T),
  sizeof(int_T),
  sizeof(pointer_T),
  sizeof(action_T),
  2*sizeof(uint32_T),
  sizeof(int32_T),
  sizeof(struct_69xIBEWZoPNsgydcxPhrJC),
  sizeof(t_card),
  sizeof(char_T),
  sizeof(uchar_T),
  sizeof(time_T)
};

/* data type name table */
static const char_T * rtDataTypeNames[] = {
  "real_T",
  "real32_T",
  "int8_T",
  "uint8_T",
  "int16_T",
  "uint16_T",
  "int32_T",
  "uint32_T",
  "boolean_T",
  "fcn_call_T",
  "int_T",
  "pointer_T",
  "action_T",
  "timer_uint32_pair_T",
  "physical_connection",
  "struct_69xIBEWZoPNsgydcxPhrJC",
  "t_card",
  "char_T",
  "uchar_T",
  "time_T"
};

/* data type transitions for block I/O structure */
static DataTypeTransition rtBTransitions[] = {
  { (char_T *)(&bodeTestRunner_B.mmcn), 0, 0, 10 }
  ,

  { (char_T *)(&bodeTestRunner_DW.UD_DSTATE), 0, 0, 23 },

  { (char_T *)(&bodeTestRunner_DW.HILInitialize_Card), 16, 0, 1 },

  { (char_T *)(&bodeTestRunner_DW.HILReadEncoder1_PWORK), 11, 0, 7 },

  { (char_T *)(&bodeTestRunner_DW.HILInitialize_ClockModes), 6, 0, 7 },

  { (char_T *)(&bodeTestRunner_DW.FromWorkspace2_IWORK.PrevIndex), 10, 0, 1 },

  { (char_T *)(&bodeTestRunner_DW.InverseModulus_FirstSample), 8, 0, 2 }
};

/* data type transition table for block I/O structure */
static DataTypeTransitionTable rtBTransTable = {
  7U,
  rtBTransitions
};

/* data type transitions for Parameters structure */
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&bodeTestRunner_P.pd_param), 15, 0, 1 },

  { (char_T *)(&bodeTestRunner_P.DiscreteDerivative_ICPrevScaled), 0, 0, 1 },

  { (char_T *)(&bodeTestRunner_P.HILReadEncoder1_channels), 7, 0, 3 },

  { (char_T *)(&bodeTestRunner_P.HILInitialize_OOTerminate), 0, 0, 28 },

  { (char_T *)(&bodeTestRunner_P.HILInitialize_CKChannels), 6, 0, 4 },

  { (char_T *)(&bodeTestRunner_P.HILInitialize_AIChannels[0]), 7, 0, 7 },

  { (char_T *)(&bodeTestRunner_P.HILInitialize_Active), 8, 0, 38 }
};

/* data type transition table for Parameters structure */
static DataTypeTransitionTable rtPTransTable = {
  7U,
  rtPTransitions
};

/* [EOF] bodeTestRunner_dt.h */
