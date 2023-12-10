/*
 * run_q2_test_data.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "run_q2_test".
 *
 * Model version              : 1.43
 * Simulink Coder version : 9.6 (R2021b) 14-May-2021
 * C source code generated on : Sun Dec 10 17:47:56 2023
 *
 * Target selection: quarc_win64.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "run_q2_test.h"
#include "run_q2_test_private.h"

/* Block parameters (default storage) */
P_run_q2_test_T run_q2_test_P = {
  /* Variable: pid_param
   * Referenced by:
   *   '<Root>/Gain'
   *   '<Root>/Gain1'
   *   '<Root>/Gain2'
   */
  {
    0.70590372219145414,
    5.2214451208522679,
    0.015653281683425585,
    68.752171366320837,
    0.10018928342466786,
    5.2214451208522679,
    0.014544995163452586,
    0.049548882566602108
  },

  /* Mask Parameter: DiscreteDerivative_ICPrevScaled
   * Referenced by: '<S1>/UD'
   */
  0.0,

  /* Mask Parameter: HILReadEncoder1_channels
   * Referenced by: '<S2>/HIL Read Encoder1'
   */
  0U,

  /* Mask Parameter: HILReadEncoder2_channels
   * Referenced by: '<S2>/HIL Read Encoder 2'
   */
  1U,

  /* Mask Parameter: HILWriteAnalog_channels
   * Referenced by: '<S2>/HIL Write Analog'
   */
  0U,

  /* Expression: set_other_outputs_at_terminate
   * Referenced by: '<S2>/HIL Initialize'
   */
  0.0,

  /* Expression: set_other_outputs_at_switch_out
   * Referenced by: '<S2>/HIL Initialize'
   */
  0.0,

  /* Expression: set_other_outputs_at_start
   * Referenced by: '<S2>/HIL Initialize'
   */
  0.0,

  /* Expression: set_other_outputs_at_switch_in
   * Referenced by: '<S2>/HIL Initialize'
   */
  0.0,

  /* Expression: final_analog_outputs
   * Referenced by: '<S2>/HIL Initialize'
   */
  0.0,

  /* Expression: final_pwm_outputs
   * Referenced by: '<S2>/HIL Initialize'
   */
  0.0,

  /* Expression: analog_input_maximums
   * Referenced by: '<S2>/HIL Initialize'
   */
  10.0,

  /* Expression: analog_input_minimums
   * Referenced by: '<S2>/HIL Initialize'
   */
  -10.0,

  /* Expression: analog_output_maximums
   * Referenced by: '<S2>/HIL Initialize'
   */
  10.0,

  /* Expression: analog_output_minimums
   * Referenced by: '<S2>/HIL Initialize'
   */
  -10.0,

  /* Expression: initial_analog_outputs
   * Referenced by: '<S2>/HIL Initialize'
   */
  0.0,

  /* Expression: watchdog_analog_outputs
   * Referenced by: '<S2>/HIL Initialize'
   */
  0.0,

  /* Expression: pwm_frequency
   * Referenced by: '<S2>/HIL Initialize'
   */
  50.0,

  /* Expression: initial_pwm_outputs
   * Referenced by: '<S2>/HIL Initialize'
   */
  0.0,

  /* Expression: watchdog_pwm_outputs
   * Referenced by: '<S2>/HIL Initialize'
   */
  0.0,

  /* Expression: -0.0046592
   * Referenced by: '<S2>/mm//cn'
   */
  -0.0046592,

  /* Expression: modulus
   * Referenced by: '<S2>/Inverse Modulus'
   */
  65536.0,

  /* Expression: -0.0046592
   * Referenced by: '<S2>/mm//cn - 2'
   */
  -0.0046592,

  /* Expression: modulus
   * Referenced by: '<S2>/Inverse Modulus1'
   */
  65536.0,

  /* Computed Parameter: DiscreteTimeIntegrator_gainval
   * Referenced by: '<Root>/Discrete-Time Integrator'
   */
  0.001,

  /* Expression: 0
   * Referenced by: '<Root>/Discrete-Time Integrator'
   */
  0.0,

  /* Computed Parameter: TSamp_WtEt
   * Referenced by: '<S1>/TSamp'
   */
  1000.0,

  /* Expression: [(1-ad) 0]
   * Referenced by: '<Root>/Discrete Transfer Fcn'
   */
  { 0.06644198618151953, 0.0 },

  /* Expression: [1 -ad]
   * Referenced by: '<Root>/Discrete Transfer Fcn'
   */
  { 1.0, -0.93355801381848047 },

  /* Expression: 0
   * Referenced by: '<Root>/Discrete Transfer Fcn'
   */
  0.0,

  /* Expression: 3.0
   * Referenced by: '<Root>/Saturation'
   */
  3.0,

  /* Expression: -3.0
   * Referenced by: '<Root>/Saturation'
   */
  -3.0,

  /* Expression: -1
   * Referenced by: '<S2>/Cable Gain'
   */
  -1.0,

  /* Computed Parameter: HILInitialize_CKChannels
   * Referenced by: '<S2>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_DOWatchdog
   * Referenced by: '<S2>/HIL Initialize'
   */
  1,

  /* Computed Parameter: HILInitialize_EIInitial
   * Referenced by: '<S2>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_POModes
   * Referenced by: '<S2>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_AIChannels
   * Referenced by: '<S2>/HIL Initialize'
   */
  { 0U, 1U },

  /* Computed Parameter: HILInitialize_AOChannels
   * Referenced by: '<S2>/HIL Initialize'
   */
  { 0U, 1U },

  /* Computed Parameter: HILInitialize_EIChannels
   * Referenced by: '<S2>/HIL Initialize'
   */
  { 0U, 1U },

  /* Computed Parameter: HILInitialize_EIQuadrature
   * Referenced by: '<S2>/HIL Initialize'
   */
  4U,

  /* Computed Parameter: HILInitialize_Active
   * Referenced by: '<S2>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_AOTerminate
   * Referenced by: '<S2>/HIL Initialize'
   */
  true,

  /* Computed Parameter: HILInitialize_AOExit
   * Referenced by: '<S2>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_DOTerminate
   * Referenced by: '<S2>/HIL Initialize'
   */
  true,

  /* Computed Parameter: HILInitialize_DOExit
   * Referenced by: '<S2>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_POTerminate
   * Referenced by: '<S2>/HIL Initialize'
   */
  true,

  /* Computed Parameter: HILInitialize_POExit
   * Referenced by: '<S2>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_CKPStart
   * Referenced by: '<S2>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_CKPEnter
   * Referenced by: '<S2>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_CKStart
   * Referenced by: '<S2>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_CKEnter
   * Referenced by: '<S2>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_AIPStart
   * Referenced by: '<S2>/HIL Initialize'
   */
  true,

  /* Computed Parameter: HILInitialize_AIPEnter
   * Referenced by: '<S2>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_AOPStart
   * Referenced by: '<S2>/HIL Initialize'
   */
  true,

  /* Computed Parameter: HILInitialize_AOPEnter
   * Referenced by: '<S2>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_AOStart
   * Referenced by: '<S2>/HIL Initialize'
   */
  true,

  /* Computed Parameter: HILInitialize_AOEnter
   * Referenced by: '<S2>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_AOReset
   * Referenced by: '<S2>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_DOPStart
   * Referenced by: '<S2>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_DOPEnter
   * Referenced by: '<S2>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_DOStart
   * Referenced by: '<S2>/HIL Initialize'
   */
  true,

  /* Computed Parameter: HILInitialize_DOEnter
   * Referenced by: '<S2>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_DOReset
   * Referenced by: '<S2>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_EIPStart
   * Referenced by: '<S2>/HIL Initialize'
   */
  true,

  /* Computed Parameter: HILInitialize_EIPEnter
   * Referenced by: '<S2>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_EIStart
   * Referenced by: '<S2>/HIL Initialize'
   */
  true,

  /* Computed Parameter: HILInitialize_EIEnter
   * Referenced by: '<S2>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_POPStart
   * Referenced by: '<S2>/HIL Initialize'
   */
  true,

  /* Computed Parameter: HILInitialize_POPEnter
   * Referenced by: '<S2>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_POStart
   * Referenced by: '<S2>/HIL Initialize'
   */
  true,

  /* Computed Parameter: HILInitialize_POEnter
   * Referenced by: '<S2>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_POReset
   * Referenced by: '<S2>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_OOReset
   * Referenced by: '<S2>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_DOFinal
   * Referenced by: '<S2>/HIL Initialize'
   */
  true,

  /* Computed Parameter: HILInitialize_DOInitial
   * Referenced by: '<S2>/HIL Initialize'
   */
  true,

  /* Computed Parameter: HILReadEncoder1_Active
   * Referenced by: '<S2>/HIL Read Encoder1'
   */
  true,

  /* Computed Parameter: HILReadEncoder2_Active
   * Referenced by: '<S2>/HIL Read Encoder 2'
   */
  true,

  /* Computed Parameter: HILWriteAnalog_Active
   * Referenced by: '<S2>/HIL Write Analog'
   */
  true
};
