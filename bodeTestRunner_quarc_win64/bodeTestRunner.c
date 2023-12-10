/*
 * bodeTestRunner.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "bodeTestRunner".
 *
 * Model version              : 1.42
 * Simulink Coder version : 9.6 (R2021b) 14-May-2021
 * C source code generated on : Sun Dec 10 04:06:05 2023
 *
 * Target selection: quarc_win64.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "bodeTestRunner.h"
#include "bodeTestRunner_private.h"
#include "bodeTestRunner_dt.h"

/* Block signals (default storage) */
B_bodeTestRunner_T bodeTestRunner_B;

/* Block states (default storage) */
DW_bodeTestRunner_T bodeTestRunner_DW;

/* Real-time model */
static RT_MODEL_bodeTestRunner_T bodeTestRunner_M_;
RT_MODEL_bodeTestRunner_T *const bodeTestRunner_M = &bodeTestRunner_M_;

/* Model output function */
void bodeTestRunner_output(void)
{
  /* local block i/o variables */
  real_T rtb_InverseModulus1;
  real_T rtb_CableGain;

  /* S-Function (hil_read_encoder_block): '<S2>/HIL Read Encoder1' */

  /* S-Function Block: bodeTestRunner/Plant/HIL Read Encoder1 (hil_read_encoder_block) */
  {
    t_error result = hil_read_encoder(bodeTestRunner_DW.HILInitialize_Card,
      &bodeTestRunner_P.HILReadEncoder1_channels, 1,
      &bodeTestRunner_DW.HILReadEncoder1_Buffer);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(bodeTestRunner_M, _rt_error_message);
    } else {
      rtb_CableGain = bodeTestRunner_DW.HILReadEncoder1_Buffer;
    }
  }

  /* Gain: '<S2>/mm//cn' */
  bodeTestRunner_B.mmcn = bodeTestRunner_P.mmcn_Gain * rtb_CableGain;

  /* S-Function (inverse_modulus_block): '<S2>/Inverse Modulus' */
  /* S-Function Block: bodeTestRunner/Plant/Inverse Modulus (inverse_modulus_block) */
  {
    static const real_T sampling_period = 0.001;
    real_T half_range = bodeTestRunner_P.InverseModulus_Modulus / 2.0;
    real_T du, dy;
    if (bodeTestRunner_DW.InverseModulus_FirstSample) {
      bodeTestRunner_DW.InverseModulus_FirstSample = false;
      bodeTestRunner_DW.InverseModulus_PreviousInput = bodeTestRunner_B.mmcn;
    }

    du = (real_T) bodeTestRunner_B.mmcn -
      bodeTestRunner_DW.InverseModulus_PreviousInput;
    if (du > half_range) {
      bodeTestRunner_DW.InverseModulus_Revolutions =
        bodeTestRunner_DW.InverseModulus_Revolutions - 1;
      dy = du - bodeTestRunner_P.InverseModulus_Modulus;
    } else if (du < -half_range) {
      bodeTestRunner_DW.InverseModulus_Revolutions =
        bodeTestRunner_DW.InverseModulus_Revolutions + 1;
      dy = du + bodeTestRunner_P.InverseModulus_Modulus;
    } else {
      dy = du;
    }

    bodeTestRunner_B.InverseModulus = bodeTestRunner_B.mmcn +
      bodeTestRunner_DW.InverseModulus_Revolutions *
      bodeTestRunner_P.InverseModulus_Modulus;
    bodeTestRunner_DW.InverseModulus_PreviousInput = bodeTestRunner_B.mmcn;
  }

  /* S-Function (hil_read_encoder_block): '<S2>/HIL Read Encoder 2' */

  /* S-Function Block: bodeTestRunner/Plant/HIL Read Encoder 2 (hil_read_encoder_block) */
  {
    t_error result = hil_read_encoder(bodeTestRunner_DW.HILInitialize_Card,
      &bodeTestRunner_P.HILReadEncoder2_channels, 1,
      &bodeTestRunner_DW.HILReadEncoder2_Buffer);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(bodeTestRunner_M, _rt_error_message);
    } else {
      rtb_CableGain = bodeTestRunner_DW.HILReadEncoder2_Buffer;
    }
  }

  /* Gain: '<S2>/mm//cn - 2' */
  bodeTestRunner_B.mmcn2 = bodeTestRunner_P.mmcn2_Gain * rtb_CableGain;

  /* S-Function (inverse_modulus_block): '<S2>/Inverse Modulus1' */
  /* S-Function Block: bodeTestRunner/Plant/Inverse Modulus1 (inverse_modulus_block) */
  {
    static const real_T sampling_period = 0.001;
    real_T half_range = bodeTestRunner_P.InverseModulus1_Modulus / 2.0;
    real_T du, dy;
    if (bodeTestRunner_DW.InverseModulus1_FirstSample) {
      bodeTestRunner_DW.InverseModulus1_FirstSample = false;
      bodeTestRunner_DW.InverseModulus1_PreviousInput = bodeTestRunner_B.mmcn2;
    }

    du = (real_T) bodeTestRunner_B.mmcn2 -
      bodeTestRunner_DW.InverseModulus1_PreviousInput;
    if (du > half_range) {
      bodeTestRunner_DW.InverseModulus1_Revolutions =
        bodeTestRunner_DW.InverseModulus1_Revolutions - 1;
      dy = du - bodeTestRunner_P.InverseModulus1_Modulus;
    } else if (du < -half_range) {
      bodeTestRunner_DW.InverseModulus1_Revolutions =
        bodeTestRunner_DW.InverseModulus1_Revolutions + 1;
      dy = du + bodeTestRunner_P.InverseModulus1_Modulus;
    } else {
      dy = du;
    }

    rtb_InverseModulus1 = bodeTestRunner_B.mmcn2 +
      bodeTestRunner_DW.InverseModulus1_Revolutions *
      bodeTestRunner_P.InverseModulus1_Modulus;
    bodeTestRunner_DW.InverseModulus1_PreviousInput = bodeTestRunner_B.mmcn2;
  }

  /* FromWorkspace: '<Root>/From Workspace2' */
  {
    real_T *pDataValues = (real_T *)
      bodeTestRunner_DW.FromWorkspace2_PWORK.DataPtr;
    real_T *pTimeValues = (real_T *)
      bodeTestRunner_DW.FromWorkspace2_PWORK.TimePtr;
    int_T currTimeIndex = bodeTestRunner_DW.FromWorkspace2_IWORK.PrevIndex;
    real_T t = bodeTestRunner_M->Timing.t[0];

    /* Get index */
    if (t <= pTimeValues[0]) {
      currTimeIndex = 0;
    } else if (t >= pTimeValues[5000]) {
      currTimeIndex = 4999;
    } else {
      if (t < pTimeValues[currTimeIndex]) {
        while (t < pTimeValues[currTimeIndex]) {
          currTimeIndex--;
        }
      } else {
        while (t >= pTimeValues[currTimeIndex + 1]) {
          currTimeIndex++;
        }
      }
    }

    bodeTestRunner_DW.FromWorkspace2_IWORK.PrevIndex = currTimeIndex;

    /* Post output */
    {
      real_T t1 = pTimeValues[currTimeIndex];
      real_T t2 = pTimeValues[currTimeIndex + 1];
      if (t1 == t2) {
        if (t < t1) {
          bodeTestRunner_B.FromWorkspace2 = pDataValues[currTimeIndex];
        } else {
          bodeTestRunner_B.FromWorkspace2 = pDataValues[currTimeIndex + 1];
        }
      } else {
        real_T f1 = (t2 - t) / (t2 - t1);
        real_T f2 = 1.0 - f1;
        real_T d1;
        real_T d2;
        int_T TimeIndex = currTimeIndex;
        d1 = pDataValues[TimeIndex];
        d2 = pDataValues[TimeIndex + 1];
        bodeTestRunner_B.FromWorkspace2 = (real_T) rtInterpolate(d1, d2, f1, f2);
        pDataValues += 5001;
      }
    }
  }

  /* DiscreteIntegrator: '<Root>/Discrete-Time Integrator' */
  bodeTestRunner_B.DiscreteTimeIntegrator =
    bodeTestRunner_DW.DiscreteTimeIntegrator_DSTATE;

  /* Gain: '<Root>/Gain2' incorporates:
   *  Sum: '<Root>/Sum'
   */
  bodeTestRunner_B.Gain2 = bodeTestRunner_P.Kd * bodeTestRunner_B.FromWorkspace2;

  /* SampleTimeMath: '<S1>/TSamp'
   *
   * About '<S1>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  bodeTestRunner_B.TSamp = bodeTestRunner_B.Gain2 * bodeTestRunner_P.TSamp_WtEt;

  /* DiscreteTransferFcn: '<Root>/Discrete Transfer Fcn' incorporates:
   *  Sum: '<S1>/Diff'
   *  UnitDelay: '<S1>/UD'
   */
  bodeTestRunner_DW.DiscreteTransferFcn_tmp = ((bodeTestRunner_B.TSamp -
    bodeTestRunner_DW.UD_DSTATE) - bodeTestRunner_P.DiscreteTransferFcn_DenCoef
    [1] * bodeTestRunner_DW.DiscreteTransferFcn_states) /
    bodeTestRunner_P.DiscreteTransferFcn_DenCoef[0];

  /* DiscreteTransferFcn: '<Root>/Discrete Transfer Fcn' */
  bodeTestRunner_B.DiscreteTransferFcn =
    bodeTestRunner_P.DiscreteTransferFcn_NumCoef[0] *
    bodeTestRunner_DW.DiscreteTransferFcn_tmp +
    bodeTestRunner_P.DiscreteTransferFcn_NumCoef[1] *
    bodeTestRunner_DW.DiscreteTransferFcn_states;

  /* Sum: '<Root>/Sum1' incorporates:
   *  Gain: '<Root>/Gain'
   *  Sum: '<Root>/Sum'
   */
  bodeTestRunner_B.Sum1 = (bodeTestRunner_P.Kp * bodeTestRunner_B.FromWorkspace2
    + bodeTestRunner_B.DiscreteTimeIntegrator) +
    bodeTestRunner_B.DiscreteTransferFcn;

  /* Gain: '<S2>/Cable Gain' incorporates:
   *  ZeroOrderHold: '<Root>/Zero-Order Hold'
   */
  rtb_CableGain = bodeTestRunner_B.Sum1;

  /* Saturate: '<Root>/Saturation' */
  if (rtb_CableGain > bodeTestRunner_P.Saturation_UpperSat) {
    /* Saturate: '<Root>/Saturation' */
    bodeTestRunner_B.Saturation = bodeTestRunner_P.Saturation_UpperSat;
  } else if (rtb_CableGain < bodeTestRunner_P.Saturation_LowerSat) {
    /* Saturate: '<Root>/Saturation' */
    bodeTestRunner_B.Saturation = bodeTestRunner_P.Saturation_LowerSat;
  } else {
    /* Saturate: '<Root>/Saturation' */
    bodeTestRunner_B.Saturation = rtb_CableGain;
  }

  /* End of Saturate: '<Root>/Saturation' */

  /* Gain: '<S2>/Cable Gain' */
  rtb_CableGain = bodeTestRunner_P.CableGain_Gain * bodeTestRunner_B.Saturation;

  /* S-Function (hil_write_analog_block): '<S2>/HIL Write Analog' */

  /* S-Function Block: bodeTestRunner/Plant/HIL Write Analog (hil_write_analog_block) */
  {
    t_error result;
    result = hil_write_analog(bodeTestRunner_DW.HILInitialize_Card,
      &bodeTestRunner_P.HILWriteAnalog_channels, 1, &rtb_CableGain);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(bodeTestRunner_M, _rt_error_message);
    }
  }

  /* Gain: '<Root>/Gain1' incorporates:
   *  Sum: '<Root>/Sum'
   */
  bodeTestRunner_B.Gain1 = bodeTestRunner_P.Ki * bodeTestRunner_B.FromWorkspace2;
}

/* Model update function */
void bodeTestRunner_update(void)
{
  /* Update for DiscreteIntegrator: '<Root>/Discrete-Time Integrator' */
  bodeTestRunner_DW.DiscreteTimeIntegrator_DSTATE +=
    bodeTestRunner_P.DiscreteTimeIntegrator_gainval * bodeTestRunner_B.Gain1;

  /* Update for UnitDelay: '<S1>/UD' */
  bodeTestRunner_DW.UD_DSTATE = bodeTestRunner_B.TSamp;

  /* Update for DiscreteTransferFcn: '<Root>/Discrete Transfer Fcn' */
  bodeTestRunner_DW.DiscreteTransferFcn_states =
    bodeTestRunner_DW.DiscreteTransferFcn_tmp;

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++bodeTestRunner_M->Timing.clockTick0)) {
    ++bodeTestRunner_M->Timing.clockTickH0;
  }

  bodeTestRunner_M->Timing.t[0] = bodeTestRunner_M->Timing.clockTick0 *
    bodeTestRunner_M->Timing.stepSize0 + bodeTestRunner_M->Timing.clockTickH0 *
    bodeTestRunner_M->Timing.stepSize0 * 4294967296.0;

  {
    /* Update absolute timer for sample time: [0.001s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick1"
     * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick1 and the high bits
     * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++bodeTestRunner_M->Timing.clockTick1)) {
      ++bodeTestRunner_M->Timing.clockTickH1;
    }

    bodeTestRunner_M->Timing.t[1] = bodeTestRunner_M->Timing.clockTick1 *
      bodeTestRunner_M->Timing.stepSize1 + bodeTestRunner_M->Timing.clockTickH1 *
      bodeTestRunner_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Model initialize function */
void bodeTestRunner_initialize(void)
{
  /* Start for S-Function (hil_initialize_block): '<S2>/HIL Initialize' */

  /* S-Function Block: bodeTestRunner/Plant/HIL Initialize (hil_initialize_block) */
  {
    t_int result;
    t_boolean is_switching;
    result = hil_open("q2_usb", "0", &bodeTestRunner_DW.HILInitialize_Card);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(bodeTestRunner_M, _rt_error_message);
      return;
    }

    is_switching = false;
    result = hil_set_card_specific_options(bodeTestRunner_DW.HILInitialize_Card,
      "d0=digital;d1=digital;led=auto;update_rate=normal;decimation=1", 63);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(bodeTestRunner_M, _rt_error_message);
      return;
    }

    result = hil_watchdog_clear(bodeTestRunner_DW.HILInitialize_Card);
    if (result < 0 && result != -QERR_HIL_WATCHDOG_CLEAR) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(bodeTestRunner_M, _rt_error_message);
      return;
    }

    if ((bodeTestRunner_P.HILInitialize_AIPStart && !is_switching) ||
        (bodeTestRunner_P.HILInitialize_AIPEnter && is_switching)) {
      bodeTestRunner_DW.HILInitialize_AIMinimums[0] =
        (bodeTestRunner_P.HILInitialize_AILow);
      bodeTestRunner_DW.HILInitialize_AIMinimums[1] =
        (bodeTestRunner_P.HILInitialize_AILow);
      bodeTestRunner_DW.HILInitialize_AIMaximums[0] =
        bodeTestRunner_P.HILInitialize_AIHigh;
      bodeTestRunner_DW.HILInitialize_AIMaximums[1] =
        bodeTestRunner_P.HILInitialize_AIHigh;
      result = hil_set_analog_input_ranges(bodeTestRunner_DW.HILInitialize_Card,
        bodeTestRunner_P.HILInitialize_AIChannels, 2U,
        &bodeTestRunner_DW.HILInitialize_AIMinimums[0],
        &bodeTestRunner_DW.HILInitialize_AIMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(bodeTestRunner_M, _rt_error_message);
        return;
      }
    }

    if ((bodeTestRunner_P.HILInitialize_AOPStart && !is_switching) ||
        (bodeTestRunner_P.HILInitialize_AOPEnter && is_switching)) {
      bodeTestRunner_DW.HILInitialize_AOMinimums[0] =
        (bodeTestRunner_P.HILInitialize_AOLow);
      bodeTestRunner_DW.HILInitialize_AOMinimums[1] =
        (bodeTestRunner_P.HILInitialize_AOLow);
      bodeTestRunner_DW.HILInitialize_AOMaximums[0] =
        bodeTestRunner_P.HILInitialize_AOHigh;
      bodeTestRunner_DW.HILInitialize_AOMaximums[1] =
        bodeTestRunner_P.HILInitialize_AOHigh;
      result = hil_set_analog_output_ranges(bodeTestRunner_DW.HILInitialize_Card,
        bodeTestRunner_P.HILInitialize_AOChannels, 2U,
        &bodeTestRunner_DW.HILInitialize_AOMinimums[0],
        &bodeTestRunner_DW.HILInitialize_AOMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(bodeTestRunner_M, _rt_error_message);
        return;
      }
    }

    if ((bodeTestRunner_P.HILInitialize_AOStart && !is_switching) ||
        (bodeTestRunner_P.HILInitialize_AOEnter && is_switching)) {
      bodeTestRunner_DW.HILInitialize_AOVoltages[0] =
        bodeTestRunner_P.HILInitialize_AOInitial;
      bodeTestRunner_DW.HILInitialize_AOVoltages[1] =
        bodeTestRunner_P.HILInitialize_AOInitial;
      result = hil_write_analog(bodeTestRunner_DW.HILInitialize_Card,
        bodeTestRunner_P.HILInitialize_AOChannels, 2U,
        &bodeTestRunner_DW.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(bodeTestRunner_M, _rt_error_message);
        return;
      }
    }

    if (bodeTestRunner_P.HILInitialize_AOReset) {
      bodeTestRunner_DW.HILInitialize_AOVoltages[0] =
        bodeTestRunner_P.HILInitialize_AOWatchdog;
      bodeTestRunner_DW.HILInitialize_AOVoltages[1] =
        bodeTestRunner_P.HILInitialize_AOWatchdog;
      result = hil_watchdog_set_analog_expiration_state
        (bodeTestRunner_DW.HILInitialize_Card,
         bodeTestRunner_P.HILInitialize_AOChannels, 2U,
         &bodeTestRunner_DW.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(bodeTestRunner_M, _rt_error_message);
        return;
      }
    }

    if ((bodeTestRunner_P.HILInitialize_EIPStart && !is_switching) ||
        (bodeTestRunner_P.HILInitialize_EIPEnter && is_switching)) {
      bodeTestRunner_DW.HILInitialize_QuadratureModes[0] =
        bodeTestRunner_P.HILInitialize_EIQuadrature;
      bodeTestRunner_DW.HILInitialize_QuadratureModes[1] =
        bodeTestRunner_P.HILInitialize_EIQuadrature;
      result = hil_set_encoder_quadrature_mode
        (bodeTestRunner_DW.HILInitialize_Card,
         bodeTestRunner_P.HILInitialize_EIChannels, 2U,
         (t_encoder_quadrature_mode *)
         &bodeTestRunner_DW.HILInitialize_QuadratureModes[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(bodeTestRunner_M, _rt_error_message);
        return;
      }
    }

    if ((bodeTestRunner_P.HILInitialize_EIStart && !is_switching) ||
        (bodeTestRunner_P.HILInitialize_EIEnter && is_switching)) {
      bodeTestRunner_DW.HILInitialize_InitialEICounts[0] =
        bodeTestRunner_P.HILInitialize_EIInitial;
      bodeTestRunner_DW.HILInitialize_InitialEICounts[1] =
        bodeTestRunner_P.HILInitialize_EIInitial;
      result = hil_set_encoder_counts(bodeTestRunner_DW.HILInitialize_Card,
        bodeTestRunner_P.HILInitialize_EIChannels, 2U,
        &bodeTestRunner_DW.HILInitialize_InitialEICounts[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(bodeTestRunner_M, _rt_error_message);
        return;
      }
    }
  }

  /* Start for S-Function (inverse_modulus_block): '<S2>/Inverse Modulus' */

  /* S-Function Block: bodeTestRunner/Plant/Inverse Modulus (inverse_modulus_block) */
  {
    bodeTestRunner_DW.InverseModulus_FirstSample = true;
    bodeTestRunner_DW.InverseModulus_Revolutions = 0;
  }

  /* Start for S-Function (inverse_modulus_block): '<S2>/Inverse Modulus1' */

  /* S-Function Block: bodeTestRunner/Plant/Inverse Modulus1 (inverse_modulus_block) */
  {
    bodeTestRunner_DW.InverseModulus1_FirstSample = true;
    bodeTestRunner_DW.InverseModulus1_Revolutions = 0;
  }

  /* Start for FromWorkspace: '<Root>/From Workspace2' */
  {
    static real_T pTimeValues0[] = { 0.0, 0.001, 0.002, 0.003, 0.004, 0.005,
      0.006, 0.007, 0.008, 0.0090000000000000011, 0.01, 0.011, 0.012,
      0.013000000000000001, 0.014, 0.015, 0.016, 0.017, 0.018000000000000002,
      0.019, 0.02, 0.021, 0.022, 0.023, 0.024, 0.025, 0.026000000000000002,
      0.027, 0.028, 0.029, 0.03, 0.031, 0.032, 0.033, 0.034, 0.035,
      0.036000000000000004, 0.037, 0.038, 0.039, 0.04, 0.041, 0.042,
      0.043000000000000003, 0.044, 0.045, 0.046, 0.047, 0.048, 0.049, 0.05,
      0.051000000000000004, 0.052000000000000005, 0.053, 0.054, 0.055, 0.056,
      0.057, 0.058, 0.059000000000000004, 0.06, 0.061, 0.062, 0.063, 0.064,
      0.065, 0.066, 0.067, 0.068, 0.069, 0.07, 0.071000000000000008,
      0.072000000000000008, 0.073, 0.074, 0.075, 0.076, 0.077, 0.078, 0.079,
      0.08, 0.081, 0.082, 0.083, 0.084, 0.085, 0.086000000000000007,
      0.087000000000000008, 0.088, 0.089, 0.09, 0.091, 0.092, 0.093, 0.094,
      0.095, 0.096, 0.097, 0.098, 0.099, 0.1, 0.101, 0.10200000000000001,
      0.10300000000000001, 0.10400000000000001, 0.105, 0.106, 0.107, 0.108,
      0.109, 0.11, 0.111, 0.112, 0.113, 0.114, 0.115, 0.116, 0.117,
      0.11800000000000001, 0.11900000000000001, 0.12, 0.121, 0.122, 0.123, 0.124,
      0.125, 0.126, 0.127, 0.128, 0.129, 0.13, 0.131, 0.132, 0.133, 0.134, 0.135,
      0.136, 0.137, 0.138, 0.139, 0.14, 0.14100000000000001, 0.14200000000000002,
      0.14300000000000002, 0.14400000000000002, 0.145, 0.146, 0.147, 0.148,
      0.149, 0.15, 0.151, 0.152, 0.153, 0.154, 0.155, 0.156, 0.157, 0.158, 0.159,
      0.16, 0.161, 0.162, 0.163, 0.164, 0.165, 0.166, 0.167, 0.168, 0.169, 0.17,
      0.171, 0.17200000000000001, 0.17300000000000001, 0.17400000000000002,
      0.17500000000000002, 0.176, 0.177, 0.178, 0.179, 0.18, 0.181, 0.182, 0.183,
      0.184, 0.185, 0.186, 0.187, 0.188, 0.189, 0.19, 0.191, 0.192, 0.193, 0.194,
      0.195, 0.196, 0.197, 0.198, 0.199, 0.2, 0.201, 0.202, 0.203,
      0.20400000000000001, 0.20500000000000002, 0.20600000000000002,
      0.20700000000000002, 0.20800000000000002, 0.209, 0.21, 0.211, 0.212, 0.213,
      0.214, 0.215, 0.216, 0.217, 0.218, 0.219, 0.22, 0.221, 0.222, 0.223, 0.224,
      0.225, 0.226, 0.227, 0.228, 0.229, 0.23, 0.231, 0.232, 0.233, 0.234,
      0.23500000000000001, 0.23600000000000002, 0.23700000000000002,
      0.23800000000000002, 0.23900000000000002, 0.24, 0.241, 0.242, 0.243, 0.244,
      0.245, 0.246, 0.247, 0.248, 0.249, 0.25, 0.251, 0.252, 0.253, 0.254, 0.255,
      0.256, 0.257, 0.258, 0.259, 0.26, 0.261, 0.262, 0.263, 0.264, 0.265, 0.266,
      0.267, 0.268, 0.269, 0.27, 0.271, 0.272, 0.273, 0.274, 0.275, 0.276, 0.277,
      0.278, 0.279, 0.28, 0.281, 0.28200000000000003, 0.28300000000000003,
      0.28400000000000003, 0.28500000000000003, 0.28600000000000003,
      0.28700000000000003, 0.28800000000000003, 0.289, 0.29, 0.291, 0.292, 0.293,
      0.294, 0.295, 0.296, 0.297, 0.298, 0.299, 0.3, 0.301, 0.302, 0.303, 0.304,
      0.305, 0.306, 0.307, 0.308, 0.309, 0.31, 0.311, 0.312, 0.313, 0.314, 0.315,
      0.316, 0.317, 0.318, 0.319, 0.32, 0.321, 0.322, 0.323, 0.324, 0.325, 0.326,
      0.327, 0.328, 0.329, 0.33, 0.331, 0.332, 0.333, 0.334, 0.335, 0.336, 0.337,
      0.338, 0.339, 0.34, 0.341, 0.342, 0.343, 0.34400000000000003,
      0.34500000000000003, 0.34600000000000003, 0.34700000000000003,
      0.34800000000000003, 0.34900000000000003, 0.35000000000000003,
      0.35100000000000003, 0.352, 0.353, 0.354, 0.355, 0.356, 0.357, 0.358,
      0.359, 0.36, 0.361, 0.362, 0.363, 0.364, 0.365, 0.366, 0.367, 0.368, 0.369,
      0.37, 0.371, 0.372, 0.373, 0.374, 0.375, 0.376, 0.377, 0.378, 0.379, 0.38,
      0.381, 0.382, 0.383, 0.384, 0.385, 0.386, 0.387, 0.388, 0.389, 0.39, 0.391,
      0.392, 0.393, 0.394, 0.395, 0.396, 0.397, 0.398, 0.399, 0.4, 0.401, 0.402,
      0.403, 0.404, 0.405, 0.406, 0.40700000000000003, 0.40800000000000003,
      0.40900000000000003, 0.41000000000000003, 0.41100000000000003,
      0.41200000000000003, 0.41300000000000003, 0.41400000000000003,
      0.41500000000000004, 0.41600000000000004, 0.417, 0.418, 0.419, 0.42, 0.421,
      0.422, 0.423, 0.424, 0.425, 0.426, 0.427, 0.428, 0.429, 0.43, 0.431, 0.432,
      0.433, 0.434, 0.435, 0.436, 0.437, 0.438, 0.439, 0.44, 0.441, 0.442, 0.443,
      0.444, 0.445, 0.446, 0.447, 0.448, 0.449, 0.45, 0.451, 0.452, 0.453, 0.454,
      0.455, 0.456, 0.457, 0.458, 0.459, 0.46, 0.461, 0.462, 0.463, 0.464, 0.465,
      0.466, 0.467, 0.468, 0.46900000000000003, 0.47000000000000003,
      0.47100000000000003, 0.47200000000000003, 0.47300000000000003,
      0.47400000000000003, 0.47500000000000003, 0.47600000000000003,
      0.47700000000000004, 0.47800000000000004, 0.47900000000000004, 0.48, 0.481,
      0.482, 0.483, 0.484, 0.485, 0.486, 0.487, 0.488, 0.489, 0.49, 0.491, 0.492,
      0.493, 0.494, 0.495, 0.496, 0.497, 0.498, 0.499, 0.5, 0.501, 0.502, 0.503,
      0.504, 0.505, 0.506, 0.507, 0.508, 0.509, 0.51, 0.511, 0.512, 0.513, 0.514,
      0.515, 0.516, 0.517, 0.518, 0.519, 0.52, 0.521, 0.522, 0.523, 0.524, 0.525,
      0.526, 0.527, 0.528, 0.529, 0.53, 0.531, 0.532, 0.533, 0.534, 0.535, 0.536,
      0.537, 0.538, 0.539, 0.54, 0.541, 0.542, 0.543, 0.544, 0.545, 0.546, 0.547,
      0.548, 0.549, 0.55, 0.551, 0.552, 0.553, 0.554, 0.555, 0.556, 0.557, 0.558,
      0.559, 0.56, 0.561, 0.562, 0.56300000000000006, 0.56400000000000006,
      0.56500000000000006, 0.56600000000000006, 0.56700000000000006,
      0.56800000000000006, 0.56900000000000006, 0.57000000000000006,
      0.57100000000000006, 0.57200000000000006, 0.57300000000000006,
      0.57400000000000007, 0.57500000000000007, 0.57600000000000007, 0.577,
      0.578, 0.579, 0.58, 0.581, 0.582, 0.583, 0.584, 0.585, 0.586, 0.587, 0.588,
      0.589, 0.59, 0.591, 0.592, 0.593, 0.594, 0.595, 0.596, 0.597, 0.598, 0.599,
      0.6, 0.601, 0.602, 0.603, 0.604, 0.605, 0.606, 0.607, 0.608, 0.609, 0.61,
      0.611, 0.612, 0.613, 0.614, 0.615, 0.616, 0.617, 0.618, 0.619, 0.62, 0.621,
      0.622, 0.623, 0.624, 0.625, 0.626, 0.627, 0.628, 0.629, 0.63, 0.631, 0.632,
      0.633, 0.634, 0.635, 0.636, 0.637, 0.638, 0.639, 0.64, 0.641, 0.642, 0.643,
      0.644, 0.645, 0.646, 0.647, 0.648, 0.649, 0.65, 0.651, 0.652, 0.653, 0.654,
      0.655, 0.656, 0.657, 0.658, 0.659, 0.66, 0.661, 0.662, 0.663, 0.664, 0.665,
      0.666, 0.667, 0.668, 0.669, 0.67, 0.671, 0.672, 0.673, 0.674, 0.675, 0.676,
      0.677, 0.678, 0.679, 0.68, 0.681, 0.682, 0.683, 0.684, 0.685, 0.686, 0.687,
      0.68800000000000006, 0.68900000000000006, 0.69000000000000006,
      0.69100000000000006, 0.69200000000000006, 0.69300000000000006,
      0.69400000000000006, 0.69500000000000006, 0.69600000000000006,
      0.69700000000000006, 0.69800000000000006, 0.69900000000000007,
      0.70000000000000007, 0.70100000000000007, 0.70200000000000007,
      0.70300000000000007, 0.704, 0.705, 0.706, 0.707, 0.708, 0.709, 0.71, 0.711,
      0.712, 0.713, 0.714, 0.715, 0.716, 0.717, 0.718, 0.719, 0.72, 0.721, 0.722,
      0.723, 0.724, 0.725, 0.726, 0.727, 0.728, 0.729, 0.73, 0.731, 0.732, 0.733,
      0.734, 0.735, 0.736, 0.737, 0.738, 0.739, 0.74, 0.741, 0.742, 0.743, 0.744,
      0.745, 0.746, 0.747, 0.748, 0.749, 0.75, 0.751, 0.752, 0.753, 0.754, 0.755,
      0.756, 0.757, 0.758, 0.759, 0.76, 0.761, 0.762, 0.763, 0.764, 0.765, 0.766,
      0.767, 0.768, 0.769, 0.77, 0.771, 0.772, 0.773, 0.774, 0.775, 0.776, 0.777,
      0.778, 0.779, 0.78, 0.781, 0.782, 0.783, 0.784, 0.785, 0.786, 0.787, 0.788,
      0.789, 0.79, 0.791, 0.792, 0.793, 0.794, 0.795, 0.796, 0.797, 0.798, 0.799,
      0.8, 0.801, 0.802, 0.803, 0.804, 0.805, 0.806, 0.807, 0.808, 0.809, 0.81,
      0.811, 0.812, 0.81300000000000006, 0.81400000000000006,
      0.81500000000000006, 0.81600000000000006, 0.81700000000000006,
      0.81800000000000006, 0.81900000000000006, 0.82000000000000006,
      0.82100000000000006, 0.82200000000000006, 0.82300000000000006,
      0.82400000000000007, 0.82500000000000007, 0.82600000000000007,
      0.82700000000000007, 0.82800000000000007, 0.82900000000000007,
      0.83000000000000007, 0.83100000000000007, 0.83200000000000007, 0.833,
      0.834, 0.835, 0.836, 0.837, 0.838, 0.839, 0.84, 0.841, 0.842, 0.843, 0.844,
      0.845, 0.846, 0.847, 0.848, 0.849, 0.85, 0.851, 0.852, 0.853, 0.854, 0.855,
      0.856, 0.857, 0.858, 0.859, 0.86, 0.861, 0.862, 0.863, 0.864, 0.865, 0.866,
      0.867, 0.868, 0.869, 0.87, 0.871, 0.872, 0.873, 0.874, 0.875, 0.876, 0.877,
      0.878, 0.879, 0.88, 0.881, 0.882, 0.883, 0.884, 0.885, 0.886, 0.887, 0.888,
      0.889, 0.89, 0.891, 0.892, 0.893, 0.894, 0.895, 0.896, 0.897, 0.898, 0.899,
      0.9, 0.901, 0.902, 0.903, 0.904, 0.905, 0.906, 0.907, 0.908, 0.909, 0.91,
      0.911, 0.912, 0.913, 0.914, 0.915, 0.916, 0.917, 0.918, 0.919, 0.92, 0.921,
      0.922, 0.923, 0.924, 0.925, 0.926, 0.927, 0.928, 0.929, 0.93, 0.931, 0.932,
      0.933, 0.934, 0.935, 0.936, 0.937, 0.93800000000000006,
      0.93900000000000006, 0.94000000000000006, 0.94100000000000006,
      0.94200000000000006, 0.94300000000000006, 0.94400000000000006,
      0.94500000000000006, 0.94600000000000006, 0.94700000000000006,
      0.94800000000000006, 0.94900000000000007, 0.95000000000000007,
      0.95100000000000007, 0.95200000000000007, 0.95300000000000007,
      0.95400000000000007, 0.95500000000000007, 0.95600000000000007,
      0.95700000000000007, 0.95800000000000007, 0.95900000000000007, 0.96, 0.961,
      0.962, 0.963, 0.964, 0.965, 0.966, 0.967, 0.968, 0.969, 0.97, 0.971, 0.972,
      0.973, 0.974, 0.975, 0.976, 0.977, 0.978, 0.979, 0.98, 0.981, 0.982, 0.983,
      0.984, 0.985, 0.986, 0.987, 0.988, 0.989, 0.99, 0.991, 0.992, 0.993, 0.994,
      0.995, 0.996, 0.997, 0.998, 0.999, 1.0, 1.0010000000000001, 1.002,
      1.0030000000000001, 1.004, 1.0050000000000001, 1.006, 1.0070000000000001,
      1.008, 1.0090000000000001, 1.01, 1.0110000000000001, 1.012,
      1.0130000000000001, 1.014, 1.0150000000000001, 1.016, 1.0170000000000001,
      1.018, 1.0190000000000001, 1.02, 1.0210000000000001, 1.022,
      1.0230000000000001, 1.024, 1.025, 1.026, 1.027, 1.028, 1.029, 1.03, 1.031,
      1.032, 1.033, 1.034, 1.035, 1.036, 1.037, 1.038, 1.039, 1.04, 1.041, 1.042,
      1.043, 1.044, 1.045, 1.046, 1.047, 1.048, 1.049, 1.05, 1.051, 1.052, 1.053,
      1.054, 1.055, 1.056, 1.057, 1.058, 1.059, 1.06, 1.061, 1.062, 1.063, 1.064,
      1.065, 1.066, 1.067, 1.068, 1.069, 1.07, 1.071, 1.072, 1.073, 1.074, 1.075,
      1.076, 1.077, 1.078, 1.079, 1.08, 1.081, 1.082, 1.083, 1.084, 1.085, 1.086,
      1.087, 1.088, 1.089, 1.09, 1.091, 1.092, 1.093, 1.094, 1.095, 1.096, 1.097,
      1.098, 1.099, 1.1, 1.101, 1.102, 1.103, 1.104, 1.105, 1.106, 1.107, 1.108,
      1.109, 1.11, 1.111, 1.112, 1.113, 1.114, 1.115, 1.116, 1.117, 1.118, 1.119,
      1.12, 1.121, 1.122, 1.123, 1.124, 1.125, 1.1260000000000001, 1.127,
      1.1280000000000001, 1.129, 1.1300000000000001, 1.131, 1.1320000000000001,
      1.133, 1.1340000000000001, 1.135, 1.1360000000000001, 1.137,
      1.1380000000000001, 1.139, 1.1400000000000001, 1.141, 1.1420000000000001,
      1.143, 1.1440000000000001, 1.145, 1.1460000000000001, 1.147,
      1.1480000000000001, 1.149, 1.1500000000000001, 1.151, 1.1520000000000001,
      1.153, 1.154, 1.155, 1.156, 1.157, 1.158, 1.159, 1.16, 1.161, 1.162, 1.163,
      1.164, 1.165, 1.166, 1.167, 1.168, 1.169, 1.17, 1.171, 1.172, 1.173, 1.174,
      1.175, 1.176, 1.177, 1.178, 1.179, 1.18, 1.181, 1.182, 1.183, 1.184, 1.185,
      1.186, 1.187, 1.188, 1.189, 1.19, 1.191, 1.192, 1.193, 1.194, 1.195, 1.196,
      1.197, 1.198, 1.199, 1.2, 1.201, 1.202, 1.203, 1.204, 1.205, 1.206, 1.207,
      1.208, 1.209, 1.21, 1.211, 1.212, 1.213, 1.214, 1.215, 1.216, 1.217, 1.218,
      1.219, 1.22, 1.221, 1.222, 1.223, 1.224, 1.225, 1.226, 1.227, 1.228, 1.229,
      1.23, 1.231, 1.232, 1.233, 1.234, 1.235, 1.236, 1.237, 1.238, 1.239, 1.24,
      1.241, 1.242, 1.243, 1.244, 1.245, 1.246, 1.247, 1.248, 1.249, 1.25,
      1.2510000000000001, 1.252, 1.2530000000000001, 1.254, 1.2550000000000001,
      1.256, 1.2570000000000001, 1.258, 1.2590000000000001, 1.26,
      1.2610000000000001, 1.262, 1.2630000000000001, 1.264, 1.2650000000000001,
      1.266, 1.2670000000000001, 1.268, 1.2690000000000001, 1.27,
      1.2710000000000001, 1.272, 1.2730000000000001, 1.274, 1.2750000000000001,
      1.276, 1.2770000000000001, 1.278, 1.2790000000000001, 1.28, 1.281, 1.282,
      1.283, 1.284, 1.285, 1.286, 1.287, 1.288, 1.289, 1.29, 1.291, 1.292, 1.293,
      1.294, 1.295, 1.296, 1.297, 1.298, 1.299, 1.3, 1.301, 1.302, 1.303, 1.304,
      1.305, 1.306, 1.307, 1.308, 1.309, 1.31, 1.311, 1.312, 1.313, 1.314, 1.315,
      1.316, 1.317, 1.318, 1.319, 1.32, 1.321, 1.322, 1.323, 1.324, 1.325, 1.326,
      1.327, 1.328, 1.329, 1.33, 1.331, 1.332, 1.333, 1.334, 1.335, 1.336, 1.337,
      1.338, 1.339, 1.34, 1.341, 1.342, 1.343, 1.344, 1.345, 1.346, 1.347, 1.348,
      1.349, 1.35, 1.351, 1.352, 1.353, 1.354, 1.355, 1.356, 1.357, 1.358, 1.359,
      1.36, 1.361, 1.362, 1.363, 1.364, 1.365, 1.366, 1.367, 1.368, 1.369, 1.37,
      1.371, 1.372, 1.373, 1.374, 1.375, 1.3760000000000001, 1.377,
      1.3780000000000001, 1.379, 1.3800000000000001, 1.381, 1.3820000000000001,
      1.383, 1.3840000000000001, 1.385, 1.3860000000000001, 1.387,
      1.3880000000000001, 1.389, 1.3900000000000001, 1.391, 1.3920000000000001,
      1.393, 1.3940000000000001, 1.395, 1.3960000000000001, 1.397,
      1.3980000000000001, 1.399, 1.4000000000000001, 1.401, 1.4020000000000001,
      1.403, 1.4040000000000001, 1.405, 1.4060000000000001, 1.407, 1.408, 1.409,
      1.41, 1.411, 1.412, 1.413, 1.414, 1.415, 1.416, 1.417, 1.418, 1.419, 1.42,
      1.421, 1.422, 1.423, 1.424, 1.425, 1.426, 1.427, 1.428, 1.429, 1.43, 1.431,
      1.432, 1.433, 1.434, 1.435, 1.436, 1.437, 1.438, 1.439, 1.44, 1.441, 1.442,
      1.443, 1.444, 1.445, 1.446, 1.447, 1.448, 1.449, 1.45, 1.451, 1.452, 1.453,
      1.454, 1.455, 1.456, 1.457, 1.458, 1.459, 1.46, 1.461, 1.462, 1.463, 1.464,
      1.465, 1.466, 1.467, 1.468, 1.469, 1.47, 1.471, 1.472, 1.473, 1.474, 1.475,
      1.476, 1.477, 1.478, 1.479, 1.48, 1.481, 1.482, 1.483, 1.484, 1.485, 1.486,
      1.487, 1.488, 1.489, 1.49, 1.491, 1.492, 1.493, 1.494, 1.495, 1.496, 1.497,
      1.498, 1.499, 1.5, 1.5010000000000001, 1.502, 1.5030000000000001, 1.504,
      1.5050000000000001, 1.506, 1.5070000000000001, 1.508, 1.5090000000000001,
      1.51, 1.5110000000000001, 1.512, 1.5130000000000001, 1.514,
      1.5150000000000001, 1.516, 1.5170000000000001, 1.518, 1.5190000000000001,
      1.52, 1.5210000000000001, 1.522, 1.5230000000000001, 1.524,
      1.5250000000000001, 1.526, 1.5270000000000001, 1.528, 1.5290000000000001,
      1.53, 1.5310000000000001, 1.532, 1.5330000000000001, 1.534,
      1.5350000000000001, 1.536, 1.537, 1.538, 1.539, 1.54, 1.541, 1.542, 1.543,
      1.544, 1.545, 1.546, 1.547, 1.548, 1.549, 1.55, 1.551, 1.552, 1.553, 1.554,
      1.555, 1.556, 1.557, 1.558, 1.559, 1.56, 1.561, 1.562, 1.563, 1.564, 1.565,
      1.566, 1.567, 1.568, 1.569, 1.57, 1.571, 1.572, 1.573, 1.574, 1.575, 1.576,
      1.577, 1.578, 1.579, 1.58, 1.581, 1.582, 1.583, 1.584, 1.585, 1.586, 1.587,
      1.588, 1.589, 1.59, 1.591, 1.592, 1.593, 1.594, 1.595, 1.596, 1.597, 1.598,
      1.599, 1.6, 1.601, 1.602, 1.603, 1.604, 1.605, 1.606, 1.607, 1.608, 1.609,
      1.61, 1.611, 1.612, 1.613, 1.614, 1.615, 1.616, 1.617, 1.618, 1.619, 1.62,
      1.621, 1.622, 1.623, 1.624, 1.625, 1.6260000000000001, 1.627,
      1.6280000000000001, 1.629, 1.6300000000000001, 1.631, 1.6320000000000001,
      1.633, 1.6340000000000001, 1.635, 1.6360000000000001, 1.637,
      1.6380000000000001, 1.639, 1.6400000000000001, 1.641, 1.6420000000000001,
      1.643, 1.6440000000000001, 1.645, 1.6460000000000001, 1.647,
      1.6480000000000001, 1.649, 1.6500000000000001, 1.651, 1.6520000000000001,
      1.653, 1.6540000000000001, 1.655, 1.6560000000000001, 1.657,
      1.6580000000000001, 1.659, 1.6600000000000001, 1.661, 1.6620000000000001,
      1.663, 1.6640000000000001, 1.665, 1.666, 1.667, 1.668, 1.669, 1.67, 1.671,
      1.672, 1.673, 1.674, 1.675, 1.676, 1.677, 1.678, 1.679, 1.68, 1.681, 1.682,
      1.683, 1.684, 1.685, 1.686, 1.687, 1.688, 1.689, 1.69, 1.691, 1.692, 1.693,
      1.694, 1.695, 1.696, 1.697, 1.698, 1.699, 1.7, 1.701, 1.702, 1.703, 1.704,
      1.705, 1.706, 1.707, 1.708, 1.709, 1.71, 1.711, 1.712, 1.713, 1.714, 1.715,
      1.716, 1.717, 1.718, 1.719, 1.72, 1.721, 1.722, 1.723, 1.724, 1.725, 1.726,
      1.727, 1.728, 1.729, 1.73, 1.731, 1.732, 1.733, 1.734, 1.735, 1.736, 1.737,
      1.738, 1.739, 1.74, 1.741, 1.742, 1.743, 1.744, 1.745, 1.746, 1.747, 1.748,
      1.749, 1.75, 1.7510000000000001, 1.752, 1.7530000000000001, 1.754,
      1.7550000000000001, 1.756, 1.7570000000000001, 1.758, 1.7590000000000001,
      1.76, 1.7610000000000001, 1.762, 1.7630000000000001, 1.764,
      1.7650000000000001, 1.766, 1.7670000000000001, 1.768, 1.7690000000000001,
      1.77, 1.7710000000000001, 1.772, 1.7730000000000001, 1.774,
      1.7750000000000001, 1.776, 1.7770000000000001, 1.778, 1.7790000000000001,
      1.78, 1.7810000000000001, 1.782, 1.7830000000000001, 1.784,
      1.7850000000000001, 1.786, 1.7870000000000001, 1.788, 1.7890000000000001,
      1.79, 1.7910000000000001, 1.792, 1.793, 1.794, 1.795, 1.796, 1.797, 1.798,
      1.799, 1.8, 1.801, 1.802, 1.803, 1.804, 1.805, 1.806, 1.807, 1.808, 1.809,
      1.81, 1.811, 1.812, 1.813, 1.814, 1.815, 1.816, 1.817, 1.818, 1.819, 1.82,
      1.821, 1.822, 1.823, 1.824, 1.825, 1.826, 1.827, 1.828, 1.829, 1.83, 1.831,
      1.832, 1.833, 1.834, 1.835, 1.836, 1.837, 1.838, 1.839, 1.84, 1.841, 1.842,
      1.843, 1.844, 1.845, 1.846, 1.847, 1.848, 1.849, 1.85, 1.851, 1.852, 1.853,
      1.854, 1.855, 1.856, 1.857, 1.858, 1.859, 1.86, 1.861, 1.862, 1.863, 1.864,
      1.865, 1.866, 1.867, 1.868, 1.869, 1.87, 1.871, 1.872, 1.873, 1.874, 1.875,
      1.8760000000000001, 1.877, 1.8780000000000001, 1.879, 1.8800000000000001,
      1.881, 1.8820000000000001, 1.883, 1.8840000000000001, 1.885,
      1.8860000000000001, 1.887, 1.8880000000000001, 1.889, 1.8900000000000001,
      1.891, 1.8920000000000001, 1.893, 1.8940000000000001, 1.895,
      1.8960000000000001, 1.897, 1.8980000000000001, 1.899, 1.9000000000000001,
      1.901, 1.9020000000000001, 1.903, 1.9040000000000001, 1.905,
      1.9060000000000001, 1.907, 1.9080000000000001, 1.909, 1.9100000000000001,
      1.911, 1.9120000000000001, 1.913, 1.9140000000000001, 1.915,
      1.9160000000000001, 1.917, 1.9180000000000001, 1.919, 1.92, 1.921, 1.922,
      1.923, 1.924, 1.925, 1.926, 1.927, 1.928, 1.929, 1.93, 1.931, 1.932, 1.933,
      1.934, 1.935, 1.936, 1.937, 1.938, 1.939, 1.94, 1.941, 1.942, 1.943, 1.944,
      1.945, 1.946, 1.947, 1.948, 1.949, 1.95, 1.951, 1.952, 1.953, 1.954, 1.955,
      1.956, 1.957, 1.958, 1.959, 1.96, 1.961, 1.962, 1.963, 1.964, 1.965, 1.966,
      1.967, 1.968, 1.969, 1.97, 1.971, 1.972, 1.973, 1.974, 1.975, 1.976, 1.977,
      1.978, 1.979, 1.98, 1.981, 1.982, 1.983, 1.984, 1.985, 1.986, 1.987, 1.988,
      1.989, 1.99, 1.991, 1.992, 1.993, 1.994, 1.995, 1.996, 1.997, 1.998, 1.999,
      2.0, 2.001, 2.0020000000000002, 2.003, 2.004, 2.005, 2.0060000000000002,
      2.007, 2.008, 2.009, 2.0100000000000002, 2.011, 2.012, 2.013,
      2.0140000000000002, 2.015, 2.016, 2.017, 2.0180000000000002, 2.019, 2.02,
      2.021, 2.0220000000000002, 2.023, 2.024, 2.025, 2.0260000000000002, 2.027,
      2.028, 2.029, 2.0300000000000002, 2.031, 2.032, 2.033, 2.0340000000000003,
      2.035, 2.036, 2.037, 2.0380000000000003, 2.039, 2.04, 2.041,
      2.0420000000000003, 2.043, 2.044, 2.045, 2.0460000000000003, 2.047, 2.048,
      2.049, 2.05, 2.051, 2.052, 2.053, 2.054, 2.055, 2.056, 2.057, 2.058, 2.059,
      2.06, 2.061, 2.062, 2.063, 2.064, 2.065, 2.066, 2.067, 2.068, 2.069, 2.07,
      2.071, 2.072, 2.073, 2.074, 2.075, 2.076, 2.077, 2.078, 2.079, 2.08, 2.081,
      2.082, 2.083, 2.084, 2.085, 2.086, 2.087, 2.088, 2.089, 2.09, 2.091, 2.092,
      2.093, 2.094, 2.095, 2.096, 2.097, 2.098, 2.099, 2.1, 2.101, 2.102, 2.103,
      2.104, 2.105, 2.106, 2.107, 2.108, 2.109, 2.11, 2.111, 2.112, 2.113, 2.114,
      2.115, 2.116, 2.117, 2.118, 2.119, 2.12, 2.121, 2.122, 2.123, 2.124, 2.125,
      2.126, 2.1270000000000002, 2.128, 2.129, 2.13, 2.1310000000000002, 2.132,
      2.133, 2.134, 2.1350000000000002, 2.136, 2.137, 2.138, 2.1390000000000002,
      2.14, 2.141, 2.142, 2.1430000000000002, 2.144, 2.145, 2.146,
      2.1470000000000002, 2.148, 2.149, 2.15, 2.1510000000000002, 2.152, 2.153,
      2.154, 2.1550000000000002, 2.156, 2.157, 2.158, 2.1590000000000003, 2.16,
      2.161, 2.162, 2.1630000000000003, 2.164, 2.165, 2.166, 2.1670000000000003,
      2.168, 2.169, 2.17, 2.1710000000000003, 2.172, 2.173, 2.174,
      2.1750000000000003, 2.176, 2.177, 2.178, 2.179, 2.18, 2.181, 2.182, 2.183,
      2.184, 2.185, 2.186, 2.187, 2.188, 2.189, 2.19, 2.191, 2.192, 2.193, 2.194,
      2.195, 2.196, 2.197, 2.198, 2.199, 2.2, 2.201, 2.202, 2.203, 2.204, 2.205,
      2.206, 2.207, 2.208, 2.209, 2.21, 2.211, 2.212, 2.213, 2.214, 2.215, 2.216,
      2.217, 2.218, 2.219, 2.22, 2.221, 2.222, 2.223, 2.224, 2.225, 2.226, 2.227,
      2.228, 2.229, 2.23, 2.231, 2.232, 2.233, 2.234, 2.235, 2.236, 2.237, 2.238,
      2.239, 2.24, 2.241, 2.242, 2.243, 2.244, 2.245, 2.246, 2.247, 2.248, 2.249,
      2.25, 2.251, 2.2520000000000002, 2.253, 2.254, 2.255, 2.2560000000000002,
      2.257, 2.258, 2.259, 2.2600000000000002, 2.261, 2.262, 2.263,
      2.2640000000000002, 2.265, 2.266, 2.267, 2.2680000000000002, 2.269, 2.27,
      2.271, 2.2720000000000002, 2.273, 2.274, 2.275, 2.2760000000000002, 2.277,
      2.278, 2.279, 2.2800000000000002, 2.281, 2.282, 2.283, 2.2840000000000003,
      2.285, 2.286, 2.287, 2.2880000000000003, 2.289, 2.29, 2.291,
      2.2920000000000003, 2.293, 2.294, 2.295, 2.2960000000000003, 2.297, 2.298,
      2.299, 2.3000000000000003, 2.301, 2.302, 2.303, 2.3040000000000003, 2.305,
      2.306, 2.307, 2.308, 2.309, 2.31, 2.311, 2.312, 2.313, 2.314, 2.315, 2.316,
      2.317, 2.318, 2.319, 2.32, 2.321, 2.322, 2.323, 2.324, 2.325, 2.326, 2.327,
      2.328, 2.329, 2.33, 2.331, 2.332, 2.333, 2.334, 2.335, 2.336, 2.337, 2.338,
      2.339, 2.34, 2.341, 2.342, 2.343, 2.344, 2.345, 2.346, 2.347, 2.348, 2.349,
      2.35, 2.351, 2.352, 2.353, 2.354, 2.355, 2.356, 2.357, 2.358, 2.359, 2.36,
      2.361, 2.362, 2.363, 2.364, 2.365, 2.366, 2.367, 2.368, 2.369, 2.37, 2.371,
      2.372, 2.373, 2.374, 2.375, 2.376, 2.3770000000000002, 2.378, 2.379, 2.38,
      2.3810000000000002, 2.382, 2.383, 2.384, 2.3850000000000002, 2.386, 2.387,
      2.388, 2.3890000000000002, 2.39, 2.391, 2.392, 2.3930000000000002, 2.394,
      2.395, 2.396, 2.3970000000000002, 2.398, 2.399, 2.4, 2.4010000000000002,
      2.402, 2.403, 2.404, 2.4050000000000002, 2.406, 2.407, 2.408,
      2.4090000000000003, 2.41, 2.411, 2.412, 2.4130000000000003, 2.414, 2.415,
      2.416, 2.4170000000000003, 2.418, 2.419, 2.42, 2.4210000000000003, 2.422,
      2.423, 2.424, 2.4250000000000003, 2.426, 2.427, 2.428, 2.4290000000000003,
      2.43, 2.431, 2.432, 2.433, 2.434, 2.435, 2.436, 2.437, 2.438, 2.439, 2.44,
      2.441, 2.442, 2.443, 2.444, 2.445, 2.446, 2.447, 2.448, 2.449, 2.45, 2.451,
      2.452, 2.453, 2.454, 2.455, 2.456, 2.457, 2.458, 2.459, 2.46, 2.461, 2.462,
      2.463, 2.464, 2.465, 2.466, 2.467, 2.468, 2.469, 2.47, 2.471, 2.472, 2.473,
      2.474, 2.475, 2.476, 2.477, 2.478, 2.479, 2.48, 2.481, 2.482, 2.483, 2.484,
      2.485, 2.486, 2.487, 2.488, 2.489, 2.49, 2.491, 2.492, 2.493, 2.494, 2.495,
      2.496, 2.497, 2.498, 2.499, 2.5, 2.501, 2.502, 2.503, 2.504, 2.505, 2.506,
      2.507, 2.508, 2.509, 2.51, 2.511, 2.512, 2.513, 2.514, 2.515, 2.516, 2.517,
      2.518, 2.519, 2.52, 2.521, 2.522, 2.523, 2.524, 2.525, 2.526, 2.527, 2.528,
      2.529, 2.53, 2.531, 2.532, 2.533, 2.534, 2.535, 2.536, 2.537, 2.538, 2.539,
      2.54, 2.541, 2.542, 2.543, 2.544, 2.545, 2.546, 2.547, 2.548, 2.549, 2.55,
      2.551, 2.552, 2.553, 2.554, 2.555, 2.556, 2.557, 2.558, 2.559, 2.56, 2.561,
      2.562, 2.563, 2.564, 2.565, 2.566, 2.567, 2.568, 2.569, 2.57,
      2.5709999999999997, 2.572, 2.573, 2.574, 2.5749999999999997, 2.576, 2.577,
      2.578, 2.5789999999999997, 2.58, 2.581, 2.582, 2.5829999999999997, 2.584,
      2.585, 2.586, 2.5869999999999997, 2.588, 2.589, 2.59, 2.5909999999999997,
      2.592, 2.593, 2.594, 2.5949999999999998, 2.596, 2.597, 2.598,
      2.5989999999999998, 2.6, 2.601, 2.602, 2.6029999999999998, 2.604, 2.605,
      2.606, 2.6069999999999998, 2.608, 2.609, 2.61, 2.6109999999999998, 2.612,
      2.613, 2.614, 2.6149999999999998, 2.616, 2.617, 2.618, 2.6189999999999998,
      2.62, 2.621, 2.622, 2.6229999999999998, 2.624, 2.625, 2.626, 2.627, 2.628,
      2.629, 2.63, 2.631, 2.632, 2.633, 2.634, 2.635, 2.636, 2.637, 2.638, 2.639,
      2.64, 2.641, 2.642, 2.643, 2.644, 2.645, 2.646, 2.647, 2.648, 2.649, 2.65,
      2.651, 2.652, 2.653, 2.654, 2.655, 2.656, 2.657, 2.658, 2.659, 2.66, 2.661,
      2.662, 2.663, 2.664, 2.665, 2.666, 2.667, 2.668, 2.669, 2.67, 2.671, 2.672,
      2.673, 2.674, 2.675, 2.676, 2.677, 2.678, 2.679, 2.68, 2.681, 2.682, 2.683,
      2.684, 2.685, 2.686, 2.687, 2.688, 2.689, 2.69, 2.691, 2.692, 2.693, 2.694,
      2.695, 2.6959999999999997, 2.697, 2.698, 2.699, 2.6999999999999997, 2.701,
      2.702, 2.703, 2.7039999999999997, 2.705, 2.706, 2.707, 2.7079999999999997,
      2.709, 2.71, 2.711, 2.7119999999999997, 2.713, 2.714, 2.715,
      2.7159999999999997, 2.717, 2.718, 2.719, 2.7199999999999998, 2.721, 2.722,
      2.723, 2.7239999999999998, 2.725, 2.726, 2.727, 2.7279999999999998, 2.729,
      2.73, 2.731, 2.7319999999999998, 2.733, 2.734, 2.735, 2.7359999999999998,
      2.737, 2.738, 2.739, 2.7399999999999998, 2.741, 2.742, 2.743,
      2.7439999999999998, 2.745, 2.746, 2.747, 2.7479999999999998, 2.749, 2.75,
      2.751, 2.752, 2.753, 2.754, 2.755, 2.756, 2.757, 2.758, 2.759, 2.76, 2.761,
      2.762, 2.763, 2.764, 2.765, 2.766, 2.767, 2.768, 2.769, 2.77, 2.771, 2.772,
      2.773, 2.774, 2.775, 2.776, 2.777, 2.778, 2.779, 2.78, 2.781, 2.782, 2.783,
      2.784, 2.785, 2.786, 2.787, 2.788, 2.789, 2.79, 2.791, 2.792, 2.793, 2.794,
      2.795, 2.796, 2.797, 2.798, 2.799, 2.8, 2.801, 2.802, 2.803, 2.804, 2.805,
      2.806, 2.807, 2.808, 2.809, 2.81, 2.811, 2.812, 2.813, 2.814, 2.815, 2.816,
      2.817, 2.818, 2.819, 2.82, 2.821, 2.822, 2.823, 2.824, 2.8249999999999997,
      2.826, 2.827, 2.828, 2.8289999999999997, 2.83, 2.831, 2.832,
      2.8329999999999997, 2.834, 2.835, 2.836, 2.8369999999999997, 2.838, 2.839,
      2.84, 2.8409999999999997, 2.842, 2.843, 2.844, 2.8449999999999998, 2.846,
      2.847, 2.848, 2.8489999999999998, 2.85, 2.851, 2.852, 2.8529999999999998,
      2.854, 2.855, 2.856, 2.8569999999999998, 2.858, 2.859, 2.86,
      2.8609999999999998, 2.862, 2.863, 2.864, 2.8649999999999998, 2.866, 2.867,
      2.868, 2.8689999999999998, 2.87, 2.871, 2.872, 2.8729999999999998, 2.874,
      2.875, 2.876, 2.877, 2.878, 2.879, 2.88, 2.881, 2.882, 2.883, 2.884, 2.885,
      2.886, 2.887, 2.888, 2.889, 2.89, 2.891, 2.892, 2.893, 2.894, 2.895, 2.896,
      2.897, 2.898, 2.899, 2.9, 2.901, 2.902, 2.903, 2.904, 2.905, 2.906, 2.907,
      2.908, 2.909, 2.91, 2.911, 2.912, 2.913, 2.914, 2.915, 2.916, 2.917, 2.918,
      2.919, 2.92, 2.921, 2.922, 2.923, 2.924, 2.925, 2.926, 2.927, 2.928, 2.929,
      2.93, 2.931, 2.932, 2.933, 2.934, 2.935, 2.936, 2.937, 2.938, 2.939, 2.94,
      2.941, 2.942, 2.943, 2.944, 2.945, 2.946, 2.947, 2.948, 2.949, 2.95, 2.951,
      2.952, 2.953, 2.9539999999999997, 2.955, 2.956, 2.957, 2.9579999999999997,
      2.959, 2.96, 2.961, 2.9619999999999997, 2.963, 2.964, 2.965,
      2.9659999999999997, 2.967, 2.968, 2.969, 2.9699999999999998, 2.971, 2.972,
      2.973, 2.9739999999999998, 2.975, 2.976, 2.977, 2.9779999999999998, 2.979,
      2.98, 2.981, 2.9819999999999998, 2.983, 2.984, 2.985, 2.9859999999999998,
      2.987, 2.988, 2.989, 2.9899999999999998, 2.991, 2.992, 2.993,
      2.9939999999999998, 2.995, 2.996, 2.997, 2.9979999999999998, 2.999, 3.0,
      3.001, 3.002, 3.003, 3.004, 3.005, 3.0060000000000002, 3.0069999999999997,
      3.008, 3.009, 3.01, 3.011, 3.012, 3.013, 3.0140000000000002,
      3.0149999999999997, 3.016, 3.017, 3.018, 3.019, 3.02, 3.021,
      3.0220000000000002, 3.0229999999999997, 3.024, 3.025, 3.026, 3.027, 3.028,
      3.029, 3.0300000000000002, 3.0309999999999997, 3.032, 3.033, 3.034, 3.035,
      3.036, 3.037, 3.0380000000000003, 3.0389999999999997, 3.04, 3.041, 3.042,
      3.043, 3.044, 3.045, 3.0460000000000003, 3.0469999999999997, 3.048, 3.049,
      3.05, 3.051, 3.052, 3.053, 3.0540000000000003, 3.0549999999999997, 3.056,
      3.057, 3.058, 3.059, 3.06, 3.061, 3.0620000000000003, 3.0629999999999997,
      3.064, 3.065, 3.066, 3.067, 3.068, 3.069, 3.0700000000000003,
      3.0709999999999997, 3.072, 3.073, 3.074, 3.075, 3.076, 3.077,
      3.0780000000000003, 3.0789999999999997, 3.08, 3.081, 3.082, 3.083,
      3.0839999999999996, 3.085, 3.086, 3.0869999999999997, 3.088, 3.089, 3.09,
      3.091, 3.0919999999999996, 3.093, 3.094, 3.0949999999999998, 3.096, 3.097,
      3.098, 3.099, 3.0999999999999996, 3.101, 3.102, 3.1029999999999998, 3.104,
      3.105, 3.106, 3.107, 3.1079999999999997, 3.109, 3.11, 3.1109999999999998,
      3.112, 3.113, 3.114, 3.115, 3.1159999999999997, 3.117, 3.118,
      3.1189999999999998, 3.12, 3.121, 3.122, 3.123, 3.1239999999999997, 3.125,
      3.126, 3.127, 3.128, 3.129, 3.13, 3.1310000000000002, 3.1319999999999997,
      3.133, 3.134, 3.135, 3.136, 3.137, 3.138, 3.1390000000000002,
      3.1399999999999997, 3.141, 3.142, 3.143, 3.144, 3.145, 3.146,
      3.1470000000000002, 3.1479999999999997, 3.149, 3.15, 3.151, 3.152, 3.153,
      3.154, 3.1550000000000002, 3.1559999999999997, 3.157, 3.158, 3.159, 3.16,
      3.161, 3.162, 3.1630000000000003, 3.1639999999999997, 3.165, 3.166, 3.167,
      3.168, 3.169, 3.17, 3.1710000000000003, 3.1719999999999997, 3.173, 3.174,
      3.175, 3.176, 3.177, 3.178, 3.1790000000000003, 3.1799999999999997, 3.181,
      3.182, 3.183, 3.184, 3.185, 3.186, 3.1870000000000003, 3.1879999999999997,
      3.189, 3.19, 3.191, 3.192, 3.193, 3.194, 3.1950000000000003,
      3.1959999999999997, 3.197, 3.198, 3.199, 3.2, 3.201, 3.202,
      3.2030000000000003, 3.2039999999999997, 3.205, 3.206, 3.207, 3.208,
      3.2089999999999996, 3.21, 3.211, 3.2119999999999997, 3.213, 3.214, 3.215,
      3.216, 3.2169999999999996, 3.218, 3.219, 3.2199999999999998, 3.221, 3.222,
      3.223, 3.224, 3.2249999999999996, 3.226, 3.227, 3.2279999999999998, 3.229,
      3.23, 3.231, 3.232, 3.2329999999999997, 3.234, 3.235, 3.2359999999999998,
      3.237, 3.238, 3.239, 3.24, 3.2409999999999997, 3.242, 3.243,
      3.2439999999999998, 3.245, 3.246, 3.247, 3.248, 3.2489999999999997, 3.25,
      3.251, 3.252, 3.253, 3.254, 3.255, 3.2560000000000002, 3.2569999999999997,
      3.258, 3.259, 3.26, 3.261, 3.262, 3.263, 3.2640000000000002,
      3.2649999999999997, 3.266, 3.267, 3.268, 3.269, 3.27, 3.271,
      3.2720000000000002, 3.2729999999999997, 3.274, 3.275, 3.276, 3.277, 3.278,
      3.279, 3.2800000000000002, 3.2809999999999997, 3.282, 3.283, 3.284, 3.285,
      3.286, 3.287, 3.2880000000000003, 3.2889999999999997, 3.29, 3.291, 3.292,
      3.293, 3.294, 3.295, 3.2960000000000003, 3.2969999999999997, 3.298, 3.299,
      3.3, 3.301, 3.302, 3.303, 3.3040000000000003, 3.3049999999999997, 3.306,
      3.307, 3.308, 3.309, 3.31, 3.311, 3.3120000000000003, 3.3129999999999997,
      3.314, 3.315, 3.316, 3.317, 3.318, 3.319, 3.3200000000000003,
      3.3209999999999997, 3.322, 3.323, 3.324, 3.325, 3.326, 3.327,
      3.3280000000000003, 3.3289999999999997, 3.33, 3.331, 3.332, 3.333, 3.334,
      3.335, 3.336, 3.3369999999999997, 3.338, 3.339, 3.34, 3.341,
      3.3419999999999996, 3.343, 3.344, 3.3449999999999998, 3.346, 3.347, 3.348,
      3.349, 3.3499999999999996, 3.351, 3.352, 3.3529999999999998, 3.354, 3.355,
      3.356, 3.357, 3.3579999999999997, 3.359, 3.36, 3.3609999999999998, 3.362,
      3.363, 3.364, 3.365, 3.3659999999999997, 3.367, 3.368, 3.3689999999999998,
      3.37, 3.371, 3.372, 3.373, 3.3739999999999997, 3.375, 3.376, 3.377, 3.378,
      3.379, 3.38, 3.3810000000000002, 3.3819999999999997, 3.383, 3.384, 3.385,
      3.386, 3.387, 3.388, 3.3890000000000002, 3.3899999999999997, 3.391, 3.392,
      3.393, 3.394, 3.395, 3.396, 3.3970000000000002, 3.3979999999999997, 3.399,
      3.4, 3.401, 3.402, 3.403, 3.404, 3.4050000000000002, 3.4059999999999997,
      3.407, 3.408, 3.409, 3.41, 3.411, 3.412, 3.4130000000000003,
      3.4139999999999997, 3.415, 3.416, 3.417, 3.418, 3.419, 3.42,
      3.4210000000000003, 3.4219999999999997, 3.423, 3.424, 3.425, 3.426, 3.427,
      3.428, 3.4290000000000003, 3.4299999999999997, 3.431, 3.432, 3.433, 3.434,
      3.435, 3.436, 3.4370000000000003, 3.4379999999999997, 3.439, 3.44, 3.441,
      3.442, 3.443, 3.444, 3.4450000000000003, 3.4459999999999997, 3.447, 3.448,
      3.449, 3.45, 3.451, 3.452, 3.4530000000000003, 3.4539999999999997, 3.455,
      3.456, 3.457, 3.458, 3.459, 3.46, 3.4610000000000003, 3.4619999999999997,
      3.463, 3.464, 3.465, 3.466, 3.4669999999999996, 3.468, 3.469,
      3.4699999999999998, 3.471, 3.472, 3.473, 3.474, 3.4749999999999996, 3.476,
      3.477, 3.4779999999999998, 3.479, 3.48, 3.481, 3.482, 3.4829999999999997,
      3.484, 3.485, 3.4859999999999998, 3.487, 3.488, 3.489, 3.49,
      3.4909999999999997, 3.492, 3.493, 3.4939999999999998, 3.495, 3.496, 3.497,
      3.498, 3.4989999999999997, 3.5, 3.501, 3.502, 3.503, 3.504, 3.505,
      3.5060000000000002, 3.5069999999999997, 3.508, 3.509, 3.51, 3.511, 3.512,
      3.513, 3.5140000000000002, 3.5149999999999997, 3.516, 3.517, 3.518, 3.519,
      3.52, 3.521, 3.5220000000000002, 3.5229999999999997, 3.524, 3.525, 3.526,
      3.527, 3.528, 3.529, 3.5300000000000002, 3.5309999999999997, 3.532, 3.533,
      3.534, 3.535, 3.536, 3.537, 3.5380000000000003, 3.5389999999999997, 3.54,
      3.541, 3.542, 3.543, 3.544, 3.545, 3.5460000000000003, 3.5469999999999997,
      3.548, 3.549, 3.55, 3.551, 3.552, 3.553, 3.5540000000000003,
      3.5549999999999997, 3.556, 3.557, 3.558, 3.559, 3.56, 3.561,
      3.5620000000000003, 3.5629999999999997, 3.564, 3.565, 3.566, 3.567, 3.568,
      3.569, 3.5700000000000003, 3.5709999999999997, 3.572, 3.573, 3.574, 3.575,
      3.576, 3.577, 3.5780000000000003, 3.5789999999999997, 3.58, 3.581, 3.582,
      3.583, 3.584, 3.585, 3.5860000000000003, 3.5869999999999997, 3.588, 3.589,
      3.59, 3.591, 3.592, 3.593, 3.594, 3.5949999999999998, 3.596, 3.597, 3.598,
      3.599, 3.5999999999999996, 3.601, 3.602, 3.6029999999999998, 3.604, 3.605,
      3.606, 3.607, 3.6079999999999997, 3.609, 3.61, 3.6109999999999998, 3.612,
      3.613, 3.614, 3.615, 3.6159999999999997, 3.617, 3.618, 3.6189999999999998,
      3.62, 3.621, 3.622, 3.623, 3.6239999999999997, 3.625, 3.626, 3.627, 3.628,
      3.629, 3.63, 3.6310000000000002, 3.6319999999999997, 3.633, 3.634, 3.635,
      3.636, 3.637, 3.638, 3.6390000000000002, 3.6399999999999997, 3.641, 3.642,
      3.643, 3.644, 3.645, 3.646, 3.6470000000000002, 3.6479999999999997, 3.649,
      3.65, 3.651, 3.652, 3.653, 3.654, 3.6550000000000002, 3.6559999999999997,
      3.657, 3.658, 3.659, 3.66, 3.661, 3.662, 3.6630000000000003,
      3.6639999999999997, 3.665, 3.666, 3.667, 3.668, 3.669, 3.67,
      3.6710000000000003, 3.6719999999999997, 3.673, 3.674, 3.675, 3.676, 3.677,
      3.678, 3.6790000000000003, 3.6799999999999997, 3.681, 3.682, 3.683, 3.684,
      3.685, 3.686, 3.6870000000000003, 3.6879999999999997, 3.689, 3.69, 3.691,
      3.692, 3.693, 3.694, 3.6950000000000003, 3.6959999999999997, 3.697, 3.698,
      3.699, 3.7, 3.701, 3.702, 3.7030000000000003, 3.7039999999999997, 3.705,
      3.706, 3.707, 3.708, 3.709, 3.71, 3.7110000000000003, 3.7119999999999997,
      3.713, 3.714, 3.715, 3.716, 3.717, 3.718, 3.7190000000000003,
      3.7199999999999998, 3.721, 3.722, 3.723, 3.724, 3.7249999999999996, 3.726,
      3.727, 3.7279999999999998, 3.729, 3.73, 3.731, 3.732, 3.7329999999999997,
      3.734, 3.735, 3.7359999999999998, 3.737, 3.738, 3.739, 3.74,
      3.7409999999999997, 3.742, 3.743, 3.7439999999999998, 3.745, 3.746, 3.747,
      3.748, 3.7489999999999997, 3.75, 3.751, 3.752, 3.753, 3.754, 3.755,
      3.7560000000000002, 3.7569999999999997, 3.758, 3.759, 3.76, 3.761, 3.762,
      3.763, 3.7640000000000002, 3.7649999999999997, 3.766, 3.767, 3.768, 3.769,
      3.77, 3.771, 3.7720000000000002, 3.7729999999999997, 3.774, 3.775, 3.776,
      3.777, 3.778, 3.779, 3.7800000000000002, 3.7809999999999997, 3.782, 3.783,
      3.784, 3.785, 3.786, 3.787, 3.7880000000000003, 3.7889999999999997, 3.79,
      3.791, 3.792, 3.793, 3.794, 3.795, 3.7960000000000003, 3.7969999999999997,
      3.798, 3.799, 3.8, 3.801, 3.802, 3.803, 3.8040000000000003,
      3.8049999999999997, 3.806, 3.807, 3.808, 3.809, 3.81, 3.811,
      3.8120000000000003, 3.8129999999999997, 3.814, 3.815, 3.816, 3.817, 3.818,
      3.819, 3.8200000000000003, 3.8209999999999997, 3.822, 3.823, 3.824, 3.825,
      3.826, 3.827, 3.8280000000000003, 3.8289999999999997, 3.83, 3.831, 3.832,
      3.833, 3.834, 3.835, 3.8360000000000003, 3.8369999999999997, 3.838, 3.839,
      3.84, 3.841, 3.842, 3.843, 3.8440000000000003, 3.8449999999999998, 3.846,
      3.847, 3.848, 3.849, 3.8499999999999996, 3.851, 3.852, 3.8529999999999998,
      3.854, 3.855, 3.856, 3.857, 3.8579999999999997, 3.859, 3.86,
      3.8609999999999998, 3.862, 3.863, 3.864, 3.865, 3.8659999999999997, 3.867,
      3.868, 3.8689999999999998, 3.87, 3.871, 3.872, 3.873, 3.8739999999999997,
      3.875, 3.876, 3.877, 3.878, 3.879, 3.88, 3.8810000000000002,
      3.8819999999999997, 3.883, 3.884, 3.885, 3.886, 3.887, 3.888,
      3.8890000000000002, 3.8899999999999997, 3.891, 3.892, 3.893, 3.894, 3.895,
      3.896, 3.8970000000000002, 3.8979999999999997, 3.899, 3.9, 3.901, 3.902,
      3.903, 3.904, 3.9050000000000002, 3.9059999999999997, 3.907, 3.908, 3.909,
      3.91, 3.911, 3.912, 3.9130000000000003, 3.9139999999999997, 3.915, 3.916,
      3.917, 3.918, 3.919, 3.92, 3.9210000000000003, 3.9219999999999997, 3.923,
      3.924, 3.925, 3.926, 3.927, 3.928, 3.9290000000000003, 3.9299999999999997,
      3.931, 3.932, 3.933, 3.934, 3.935, 3.936, 3.9370000000000003,
      3.9379999999999997, 3.939, 3.94, 3.941, 3.942, 3.943, 3.944,
      3.9450000000000003, 3.9459999999999997, 3.947, 3.948, 3.949, 3.95, 3.951,
      3.952, 3.9530000000000003, 3.9539999999999997, 3.955, 3.956, 3.957, 3.958,
      3.959, 3.96, 3.9610000000000003, 3.9619999999999997, 3.963, 3.964, 3.965,
      3.966, 3.967, 3.968, 3.9690000000000003, 3.9699999999999998, 3.971, 3.972,
      3.973, 3.974, 3.975, 3.976, 3.977, 3.9779999999999998, 3.979, 3.98, 3.981,
      3.982, 3.9829999999999997, 3.984, 3.985, 3.9859999999999998, 3.987, 3.988,
      3.989, 3.99, 3.9909999999999997, 3.992, 3.993, 3.9939999999999998, 3.995,
      3.996, 3.997, 3.998, 3.9989999999999997, 4.0, 4.001, 4.002, 4.003, 4.004,
      4.005, 4.006, 4.007, 4.008, 4.009, 4.01, 4.011, 4.0120000000000005, 4.013,
      4.014, 4.015, 4.016, 4.017, 4.018, 4.019, 4.02, 4.021, 4.022, 4.023, 4.024,
      4.025, 4.026, 4.027, 4.0280000000000005, 4.029, 4.03, 4.031, 4.032, 4.033,
      4.034, 4.035, 4.036, 4.037, 4.038, 4.039, 4.04, 4.041, 4.042, 4.043, 4.044,
      4.045, 4.046, 4.047, 4.048, 4.0489999999999995, 4.05, 4.051, 4.052, 4.053,
      4.054, 4.055, 4.056, 4.057, 4.058, 4.059, 4.06, 4.061, 4.062, 4.063, 4.064,
      4.0649999999999995, 4.066, 4.067, 4.068, 4.069, 4.07, 4.071, 4.072, 4.073,
      4.074, 4.075, 4.076, 4.077, 4.078, 4.079, 4.08, 4.0809999999999995, 4.082,
      4.083, 4.084, 4.085, 4.086, 4.087, 4.088, 4.089, 4.09, 4.091, 4.092, 4.093,
      4.094, 4.095, 4.096, 4.0969999999999995, 4.098, 4.099, 4.1, 4.101, 4.102,
      4.103, 4.104, 4.105, 4.106, 4.107, 4.108, 4.109, 4.11, 4.111, 4.112,
      4.1129999999999995, 4.114, 4.115, 4.116, 4.117, 4.118, 4.119, 4.12, 4.121,
      4.122, 4.123, 4.124, 4.125, 4.126, 4.127, 4.128, 4.129, 4.13, 4.131, 4.132,
      4.133, 4.134, 4.135, 4.136, 4.1370000000000005, 4.138, 4.139, 4.14, 4.141,
      4.142, 4.143, 4.144, 4.145, 4.146, 4.147, 4.148, 4.149, 4.15, 4.151, 4.152,
      4.1530000000000005, 4.154, 4.155, 4.156, 4.157, 4.158, 4.159, 4.16, 4.161,
      4.162, 4.163, 4.164, 4.165, 4.166, 4.167, 4.168, 4.169, 4.17, 4.171, 4.172,
      4.173, 4.1739999999999995, 4.175, 4.176, 4.177, 4.178, 4.179, 4.18, 4.181,
      4.182, 4.183, 4.184, 4.185, 4.186, 4.187, 4.188, 4.189, 4.1899999999999995,
      4.191, 4.192, 4.193, 4.194, 4.195, 4.196, 4.197, 4.198, 4.199, 4.2, 4.201,
      4.202, 4.203, 4.204, 4.205, 4.2059999999999995, 4.207, 4.208, 4.209, 4.21,
      4.211, 4.212, 4.213, 4.214, 4.215, 4.216, 4.217, 4.218, 4.219, 4.22, 4.221,
      4.2219999999999995, 4.223, 4.224, 4.225, 4.226, 4.227, 4.228, 4.229, 4.23,
      4.231, 4.232, 4.233, 4.234, 4.235, 4.236, 4.237, 4.2379999999999995, 4.239,
      4.24, 4.241, 4.242, 4.243, 4.244, 4.245, 4.246, 4.247, 4.248, 4.249, 4.25,
      4.251, 4.252, 4.253, 4.254, 4.255, 4.256, 4.257, 4.258, 4.259, 4.26, 4.261,
      4.2620000000000005, 4.263, 4.264, 4.265, 4.266, 4.267, 4.268, 4.269, 4.27,
      4.271, 4.272, 4.273, 4.274, 4.275, 4.276, 4.277, 4.2780000000000005, 4.279,
      4.28, 4.281, 4.282, 4.283, 4.284, 4.285, 4.286, 4.287, 4.288, 4.289, 4.29,
      4.291, 4.292, 4.293, 4.2940000000000005, 4.295, 4.296, 4.297, 4.298,
      4.2989999999999995, 4.3, 4.301, 4.302, 4.303, 4.304, 4.305, 4.306, 4.307,
      4.308, 4.309, 4.31, 4.311, 4.312, 4.313, 4.314, 4.3149999999999995, 4.316,
      4.317, 4.318, 4.319, 4.32, 4.321, 4.322, 4.323, 4.324, 4.325, 4.326, 4.327,
      4.328, 4.329, 4.33, 4.3309999999999995, 4.332, 4.333, 4.334, 4.335, 4.336,
      4.337, 4.338, 4.339, 4.34, 4.341, 4.342, 4.343, 4.344, 4.345, 4.346,
      4.3469999999999995, 4.348, 4.349, 4.35, 4.351, 4.352, 4.353, 4.354, 4.355,
      4.356, 4.357, 4.358, 4.359, 4.36, 4.361, 4.362, 4.3629999999999995, 4.364,
      4.365, 4.366, 4.367, 4.368, 4.369, 4.37, 4.371, 4.372, 4.373, 4.374, 4.375,
      4.376, 4.377, 4.378, 4.379, 4.38, 4.381, 4.382, 4.383, 4.384, 4.385, 4.386,
      4.3870000000000005, 4.388, 4.389, 4.39, 4.391, 4.392, 4.393, 4.394, 4.395,
      4.396, 4.397, 4.398, 4.399, 4.4, 4.401, 4.402, 4.4030000000000005, 4.404,
      4.405, 4.406, 4.407, 4.408, 4.409, 4.41, 4.411, 4.412, 4.413, 4.414, 4.415,
      4.416, 4.417, 4.418, 4.4190000000000005, 4.42, 4.421, 4.422, 4.423,
      4.4239999999999995, 4.425, 4.426, 4.427, 4.428, 4.429, 4.43, 4.431, 4.432,
      4.433, 4.434, 4.435, 4.436, 4.437, 4.438, 4.439, 4.4399999999999995, 4.441,
      4.442, 4.443, 4.444, 4.445, 4.446, 4.447, 4.448, 4.449, 4.45, 4.451, 4.452,
      4.453, 4.454, 4.455, 4.4559999999999995, 4.457, 4.458, 4.459, 4.46, 4.461,
      4.462, 4.463, 4.464, 4.465, 4.466, 4.467, 4.468, 4.469, 4.47, 4.471,
      4.4719999999999995, 4.473, 4.474, 4.475, 4.476, 4.477, 4.478, 4.479, 4.48,
      4.481, 4.482, 4.483, 4.484, 4.485, 4.486, 4.487, 4.4879999999999995, 4.489,
      4.49, 4.491, 4.492, 4.493, 4.494, 4.495, 4.496, 4.497, 4.498, 4.499, 4.5,
      4.501, 4.502, 4.503, 4.504, 4.505, 4.506, 4.507, 4.508, 4.509, 4.51, 4.511,
      4.5120000000000005, 4.513, 4.514, 4.515, 4.516, 4.517, 4.518, 4.519, 4.52,
      4.521, 4.522, 4.523, 4.524, 4.525, 4.526, 4.527, 4.528, 4.529, 4.53, 4.531,
      4.532, 4.533, 4.534, 4.535, 4.536, 4.537, 4.538, 4.539, 4.54, 4.541, 4.542,
      4.543, 4.544, 4.545, 4.546, 4.547, 4.548, 4.549, 4.55, 4.551, 4.552, 4.553,
      4.554, 4.555, 4.556, 4.557, 4.558, 4.559, 4.56, 4.561, 4.562, 4.563, 4.564,
      4.565, 4.566, 4.567, 4.568, 4.569, 4.57, 4.571, 4.572, 4.573, 4.574, 4.575,
      4.576, 4.577, 4.578, 4.579, 4.58, 4.581, 4.582, 4.583, 4.584, 4.585, 4.586,
      4.587, 4.588, 4.589, 4.59, 4.591, 4.592, 4.593, 4.594, 4.595, 4.596,
      4.5969999999999995, 4.598, 4.599, 4.6, 4.601, 4.602, 4.603, 4.604, 4.605,
      4.606, 4.607, 4.608, 4.609, 4.61, 4.611, 4.612, 4.6129999999999995, 4.614,
      4.615, 4.616, 4.617, 4.618, 4.619, 4.62, 4.621, 4.622, 4.623, 4.624, 4.625,
      4.626, 4.627, 4.628, 4.629, 4.63, 4.631, 4.632, 4.633, 4.634, 4.635, 4.636,
      4.6370000000000005, 4.638, 4.639, 4.64, 4.641, 4.642, 4.643, 4.644, 4.645,
      4.646, 4.647, 4.648, 4.649, 4.65, 4.651, 4.652, 4.653, 4.654, 4.655, 4.656,
      4.657, 4.658, 4.659, 4.66, 4.661, 4.662, 4.663, 4.664, 4.665, 4.666, 4.667,
      4.668, 4.669, 4.67, 4.671, 4.672, 4.673, 4.674, 4.675, 4.676, 4.677, 4.678,
      4.679, 4.68, 4.681, 4.682, 4.683, 4.684, 4.685, 4.686, 4.687, 4.688, 4.689,
      4.69, 4.691, 4.692, 4.693, 4.694, 4.695, 4.696, 4.697, 4.698, 4.699, 4.7,
      4.701, 4.702, 4.703, 4.704, 4.705, 4.706, 4.707, 4.708, 4.709, 4.71, 4.711,
      4.712, 4.713, 4.714, 4.715, 4.716, 4.717, 4.718, 4.719, 4.72, 4.721,
      4.7219999999999995, 4.723, 4.724, 4.725, 4.726, 4.727, 4.728, 4.729, 4.73,
      4.731, 4.732, 4.733, 4.734, 4.735, 4.736, 4.737, 4.7379999999999995, 4.739,
      4.74, 4.741, 4.742, 4.743, 4.744, 4.745, 4.746, 4.747, 4.748, 4.749, 4.75,
      4.751, 4.752, 4.753, 4.754, 4.755, 4.756, 4.757, 4.758, 4.759, 4.76, 4.761,
      4.762, 4.763, 4.764, 4.765, 4.766, 4.767, 4.768, 4.769, 4.77, 4.771, 4.772,
      4.773, 4.774, 4.775, 4.776, 4.777, 4.778, 4.779, 4.78, 4.781, 4.782, 4.783,
      4.784, 4.785, 4.786, 4.787, 4.788, 4.789, 4.79, 4.791, 4.792, 4.793, 4.794,
      4.795, 4.796, 4.797, 4.798, 4.799, 4.8, 4.801, 4.802, 4.803, 4.804, 4.805,
      4.806, 4.807, 4.808, 4.809, 4.81, 4.811, 4.812, 4.813, 4.814, 4.815, 4.816,
      4.817, 4.818, 4.819, 4.82, 4.821, 4.822, 4.823, 4.824, 4.825, 4.826, 4.827,
      4.828, 4.829, 4.83, 4.831, 4.832, 4.833, 4.834, 4.835, 4.836, 4.837, 4.838,
      4.839, 4.84, 4.841, 4.842, 4.843, 4.844, 4.845, 4.846, 4.847, 4.848, 4.849,
      4.85, 4.851, 4.852, 4.853, 4.854, 4.855, 4.856, 4.857, 4.858, 4.859, 4.86,
      4.861, 4.862, 4.8629999999999995, 4.864, 4.865, 4.866, 4.867, 4.868, 4.869,
      4.87, 4.871, 4.872, 4.873, 4.874, 4.875, 4.876, 4.877, 4.878, 4.879, 4.88,
      4.881, 4.882, 4.883, 4.884, 4.885, 4.886, 4.887, 4.888, 4.889, 4.89, 4.891,
      4.892, 4.893, 4.894, 4.895, 4.896, 4.897, 4.898, 4.899, 4.9, 4.901, 4.902,
      4.903, 4.904, 4.905, 4.906, 4.907, 4.908, 4.909, 4.91, 4.911, 4.912, 4.913,
      4.914, 4.915, 4.916, 4.917, 4.918, 4.919, 4.92, 4.921, 4.922, 4.923, 4.924,
      4.925, 4.926, 4.927, 4.928, 4.929, 4.93, 4.931, 4.932, 4.933, 4.934, 4.935,
      4.936, 4.937, 4.938, 4.939, 4.94, 4.941, 4.942, 4.943, 4.944, 4.945, 4.946,
      4.947, 4.948, 4.949, 4.95, 4.951, 4.952, 4.953, 4.954, 4.955, 4.956, 4.957,
      4.958, 4.959, 4.96, 4.961, 4.962, 4.963, 4.964, 4.965, 4.966, 4.967, 4.968,
      4.969, 4.97, 4.971, 4.972, 4.973, 4.974, 4.975, 4.976, 4.977, 4.978, 4.979,
      4.98, 4.981, 4.982, 4.983, 4.984, 4.985, 4.986, 4.987, 4.988, 4.989, 4.99,
      4.991, 4.992, 4.993, 4.994, 4.995, 4.996, 4.997, 4.998, 4.999, 5.0 } ;

    static real_T pDataValues0[] = { 0.0, 0.00049999791666927083,
      0.00099998333341666653, 0.0014999437506328091, 0.0019998666693333083,
      0.0024997395914712335, 0.002999550020249566, 0.0034992854604336196,
      0.0039989334186634161, 0.0044984814037660244, 0.0049979169270678338,
      0.0054972275027067724, 0.00599640064794446, 0.00649542388347826,
      0.0069942847337532768, 0.0074929707272742346, 0.00799146939691727,
      0.0084897682802416025, 0.0089878549198011051, 0.00948571686345573,
      0.0099833416646828155, 0.01048071688288825, 0.01097783008371748,
      0.011474668839366382, 0.011971220728891938, 0.01246747333852277,
      0.012963414261969487, 0.013459031100734832, 0.013954311464423649,
      0.014449242971052642, 0.014943813247359923, 0.015438009929114342,
      0.0159318206614246, 0.016425233099048097, 0.016918234906699605,
      0.017410813759359597, 0.017902957342582421, 0.018394653352804123,
      0.01888588949765006, 0.019376653496242194, 0.019866933079506124,
      0.0203567159904778, 0.020845989984609958, 0.021334742830078232,
      0.021822962308086932, 0.022310636213174542, 0.02279775235351884,
      0.023284298551241679, 0.023770262642713459, 0.024255632478857207,
      0.024740395925452296, 0.025224540863437808, 0.025708055189215512,
      0.026190926814952442, 0.026673143668883115, 0.027154693695611288,
      0.027635564856411377, 0.028115745129529409, 0.028595222510483562,
      0.02907398501236428, 0.029552020666133955, 0.030029317520926153,
      0.03050586364434435, 0.030981647122760289, 0.031456656061611778,
      0.031930878585700095, 0.032404302839486837, 0.032876916987390314,
      0.033348709214081444, 0.03381966772477913, 0.034289780745545138,
      0.034759036523578431, 0.035227423327509, 0.035694929447691141,
      0.0361615431964962, 0.03662725290860476, 0.037092046941298272,
      0.037555913674750127, 0.038018841512316146, 0.038480818880824504,
      0.038941834230865058, 0.039401876037078044, 0.0398609327984423,
      0.040318993038562671, 0.04077604530595702, 0.041232078174342483,
      0.041687080242921087, 0.042141040136664809, 0.042593946506599957,
      0.043045788030090883, 0.043496553411123018, 0.043946231380585322,
      0.044394810696551976, 0.044842280144563443, 0.045288628537906828,
      0.045733844717895544, 0.046177917554148289, 0.046620835944867274,
      0.047062588817115808, 0.047503165127095084, 0.0479425538604203,
      0.04838074403239602, 0.048817724688290758, 0.049253484903610867,
      0.04968801378437368, 0.050121300467379795, 0.0505533341204847,
      0.050984103942869591, 0.051413599165311324, 0.051841809050451708,
      0.052268722893065923, 0.052694330020330138, 0.053118619792088345,
      0.05354158160111834, 0.053963204873396932, 0.054383479068364264,
      0.054802393679187357, 0.055219938233022771, 0.05563610229127839,
      0.056050875449874429, 0.056464247339503539, 0.056876207625890011,
      0.057286746010048128, 0.057695852228539679, 0.058103516053730514,
      0.058509727294046222, 0.058914475794226956, 0.059317751435581295,
      0.059719544136239214, 0.060119843851404113, 0.060518640573603955,
      0.06091592433294149, 0.061311685197343382, 0.061705913272808666,
      0.062098598703655972, 0.062489731672769992, 0.062879302401846859,
      0.06326730115163863, 0.0636537182221968, 0.0640385439531147,
      0.064421768723769118, 0.064803382953560737, 0.065183377102153675,
      0.065561741669714041, 0.065938467197147327, 0.06631354426633497,
      0.066686963500369789, 0.06705871556379038, 0.067428791162814514,
      0.067797181045571489, 0.068163876002333409, 0.0685288668657455,
      0.068892144511055131, 0.06925369985634014, 0.069613523862735671,
      0.069971607534660349, 0.070327941920041021, 0.0706825181105366,
      0.071035327241760787, 0.071386360493503692, 0.071735609089952287,
      0.072083064299909849, 0.072428717437014262, 0.072772559859955052,
      0.073114582972689593, 0.07345477822465786, 0.073793137110996276,
      0.074129651172750319, 0.074464311997085947, 0.07479711121749999,
      0.075128040514029271, 0.075457091613458635, 0.075784256289527716,
      0.076109526363136643, 0.07643289370255052, 0.076754350223602719,
      0.077073887889896928, 0.077391498713008169, 0.077707174752682392,
      0.078020908117035048, 0.078332690962748336, 0.0786425154952674,
      0.078950373968995041, 0.079256258687485467, 0.079560162003636609,
      0.079862076319881431, 0.080161994088377708, 0.080459907811196912,
      0.080755810040511425, 0.081049693378780985, 0.081341550478937374,
      0.081631374044568356, 0.081919156830099829, 0.08220489164097719,
      0.082488571333845018, 0.082770188816725765, 0.083049737049197048,
      0.083327209042567615, 0.083602597860052058, 0.0838758966169443,
      0.084147098480789662, 0.084416196671555643, 0.084683184461801522,
      0.084948055176846449, 0.0852108021949363, 0.085471418947409353,
      0.085729898918860348, 0.085986235647303469, 0.086240422724333854,
      0.0864924537952878, 0.0867423225594017, 0.086990022769969422,
      0.087235548234498639, 0.087478892814865483, 0.087720050427468166,
      0.0879590150433789, 0.088195780688494763, 0.088430341443686916,
      0.088662691444948732, 0.088892824883542262, 0.08912073600614355,
      0.089346419114986364, 0.089569868568004765, 0.089791078778974076,
      0.09001004421765052, 0.090226759409909527, 0.0904412189378826,
      0.0906534174400927, 0.090863349611588332, 0.091071010204076139,
      0.091276394026052116, 0.091479495942931421, 0.091680310877176707,
      0.09187883380842507, 0.092075059773613577, 0.0922689838671033,
      0.092460601240802048, 0.0926499071042854, 0.092836896724916684,
      0.093021565427965081, 0.093203908596722632, 0.093383921672619663,
      0.0935616001553386, 0.093736939602926644, 0.093909935631906763,
      0.094080583917387217, 0.094248880193169751, 0.094414820251856255,
      0.0945783999449539, 0.094739615182978881, 0.09489846193555862,
      0.0950549362315326, 0.095209034159051575, 0.095360751865675386,
      0.095510085558469238, 0.0956570315040986, 0.0958015860289225,
      0.095943745519085355, 0.09608350642060727, 0.096220865239473027,
      0.0963558185417193, 0.096488362953520562, 0.09661849516127341,
      0.096746211911679425, 0.096871510011826534, 0.096994386329268725,
      0.097114837792104461, 0.09723286138905346, 0.097348454169531945,
      0.097461613243726417, 0.097572335782665914, 0.097680619018292725,
      0.097786460243531631, 0.09788985681235747, 0.097990806139861428,
      0.098089305702315568, 0.098185353037235981, 0.098278945743444271,
      0.098370081481127664, 0.098458757971897459, 0.098544972998846028,
      0.098628724406602156, 0.09871001010138504, 0.098788828051056529,
      0.098865176285172, 0.098939052895029536, 0.099010456033717789,
      0.099079383916161987, 0.099145834819168652, 0.09920980708146869,
      0.099271299103758856, 0.0993303093487418, 0.099386836341164492,
      0.099440878667855032, 0.0994924349777581, 0.0995415039819686,
      0.099588084453764, 0.099632175228634948, 0.099673775204314349,
      0.09971288334080497, 0.099749498660405445, 0.0997836202477347,
      0.099815247249754824, 0.0998443788757924, 0.0998710143975583,
      0.099895153149165888, 0.0999167945271476, 0.099935937990470139,
      0.099952583060547912, 0.099966729321255027, 0.0999783764189357,
      0.099987524062413111, 0.099994172022996639, 0.099998320134487617,
      0.099999968293183472, 0.099999116457880316, 0.099995764649874017,
      0.099989912952959559, 0.099981561513429087, 0.099970710540068161,
      0.099957360304150519, 0.0999415111394314, 0.099923163442139057,
      0.099902317670965, 0.0998789743470524, 0.099853134053983161,
      0.099824797437763249, 0.0997939652068066, 0.099760638131917379,
      0.099724817046270717, 0.099686502845391892, 0.099645696487133936,
      0.099602398991653684, 0.09955661144138625, 0.099508334981018021,
      0.099457570817457985, 0.099404320219807607, 0.099348584519329028,
      0.09929036510941186, 0.099229663445538324, 0.099166481045246863,
      0.099100819488094183, 0.0990326804156158, 0.09896206553128499,
      0.098888976600470149, 0.098813415450390768, 0.098735383970071644,
      0.098654884110295743, 0.098571917883555349, 0.098486487364001826,
      0.09839859468739369, 0.0983082420510433, 0.098215431713761847,
      0.098120165995802935, 0.098022447278804548, 0.097922278005729529,
      0.097819660680804485, 0.097714597869457173, 0.097607092198252421,
      0.097497146354826425, 0.097384763087819529, 0.09726994520680754,
      0.097152695582231538, 0.097033017145326014, 0.096910912888045653,
      0.096786385862990515, 0.096659439183329754, 0.096530076022723774,
      0.09639829961524482, 0.096264113255296227, 0.09612752029753,
      0.095988524156762969, 0.095847128307891424, 0.095703336285804214,
      0.0955571516852944, 0.095408578160969384, 0.095257619427159546,
      0.095104279257825344, 0.094948561486463051, 0.09479047000600882,
      0.094630008768741447, 0.0944671817861835, 0.09430199312900106,
      0.094134446926901941, 0.093964547368532492, 0.093792298701372817,
      0.0936177052316306, 0.093440771324133531, 0.093261501402220059,
      0.093079899947628886, 0.09289597150038692, 0.0927097206586958,
      0.092521152078816837, 0.092330270474954679, 0.092137080619139541,
      0.091941587341107717, 0.091743795528180988, 0.091543710125144367,
      0.091341336134122514, 0.09113667861445468, 0.090929742682568176,
      0.090720533511850526, 0.0905090563325201, 0.090295316431495368,
      0.090079319152262735, 0.0898610698947429, 0.089640574115155983,
      0.089417837325884958, 0.08919286509533797, 0.088965663047809049,
      0.088736236863337536, 0.08850459227756613, 0.088270735081597412,
      0.08803467112184904, 0.0877964062999078, 0.087555946572381776,
      0.087313297950751656, 0.087068466501220312, 0.086821458344561273,
      0.086572279655965548, 0.086320936664887382, 0.086067435654888488,
      0.0858117829634809, 0.085553984981968589, 0.085294048155287627,
      0.08503197898184521, 0.084767784013357, 0.084501469854683417,
      0.084233043163664575, 0.0839625106509538, 0.083689879079849774,
      0.083415155266127625, 0.083138346077868311, 0.0828594584352872,
      0.082578499310560827, 0.082295475727652612, 0.082010394762137409,
      0.081723263541024563, 0.08143408924257961, 0.081142879096144926,
      0.08084964038195902, 0.080554380430974487, 0.080257106624674723,
      0.079957826394889409, 0.079656547223608654, 0.079353276642796122,
      0.079048022234200488, 0.078740791629166085, 0.078431592508441991,
      0.0781204326019902, 0.07780731968879212, 0.0774922615966543,
      0.07717526620201258, 0.076856341429735367, 0.076535495252925356,
      0.076212735692720246, 0.075888070818092179, 0.075561508745646211,
      0.075233057639417081, 0.074902725710665349, 0.074570521217672,
      0.074236452465532121, 0.07390052780594708, 0.073562755637015892,
      0.073223144403025117, 0.072881702594238013, 0.072538438746681963,
      0.072193361441935278, 0.0718464793069126, 0.071497801013649262,
      0.071147335279084442, 0.07079509086484323, 0.070441076577017592,
      0.070085301265946365, 0.06972777382599378, 0.069368503195327183,
      0.069007498355693614, 0.068644768332195322, 0.068280322193063972,
      0.067914169049434064, 0.0675463180551151, 0.067176778406362811,
      0.0668055593416491, 0.066432670141431338, 0.066058120127920075,
      0.065681918664846142, 0.065304075157226513, 0.06492459905112917,
      0.064543499833437087, 0.06416078703161078, 0.06377647021345037,
      0.063390558986856346, 0.063003062999589229, 0.062613991939028529,
      0.062223355531930508, 0.061831163544184935, 0.061437425780571181,
      0.06104215208451276, 0.060645352337831471, 0.060247036460500385,
      0.059847214410395644, 0.0594458961830477, 0.059043091811391307,
      0.058638811365514742, 0.058233064952408188, 0.0578258627157108,
      0.057417214835457232, 0.057007131527823288, 0.056595623044870286,
      0.056182699674288829, 0.0557683717391417, 0.055352649597605663,
      0.054935543642712664, 0.054517064302089829, 0.054097222037698824,
      0.053676027345574473, 0.05325349075556212, 0.052829622831054482,
      0.052404434168727615, 0.051977935398275887, 0.051550137182146419,
      0.0511210502152723, 0.050690685224805312, 0.050259052969847874,
      0.049826164241183857, 0.049392029861008921, 0.048956660682659955,
      0.048520067590343711, 0.048082261498864826, 0.04764325335335276,
      0.047203054128988231, 0.046761674830729009, 0.046319126493034518,
      0.045875420179590155, 0.045430566983030649, 0.0449845780246627,
      0.044537464454187117, 0.044089237449419838, 0.043639908216012595,
      0.0431894879871729, 0.042737988023382981, 0.042285419612118409,
      0.0418317940675659, 0.041377122730340395, 0.040921416967201731,
      0.040464688170770209, 0.040006947759241913, 0.03954820717610337,
      0.039088477889845222, 0.038627771393675688, 0.038166099205233173,
      0.0377034728662983, 0.03723990394250553, 0.036775404023053779,
      0.036309984720416792, 0.035843657670052979, 0.03537643453011427,
      0.034908326981154834, 0.034439346725839, 0.0339695054886487,
      0.033498815015590468, 0.033027287073901575, 0.03255493345175596,
      0.03208176595796966, 0.031607796421705345, 0.031133036692176715,
      0.030657498638352293, 0.030181194148658615, 0.029704135130683196,
      0.0292263335108766, 0.0287478012342544, 0.02826855026409866,
      0.027788592581658635, 0.027307940185851393, 0.026826605092961794,
      0.026344599336342041, 0.025861934966111041, 0.0253786240488529,
      0.024894678667315304, 0.024410110920107614, 0.023924932921398245,
      0.023439156800611968, 0.022952794702126467, 0.022465858784968824,
      0.021978361222511695, 0.021490314202168712, 0.02100172992508996,
      0.020512620605856919, 0.020022998472177055, 0.019532875764578291,
      0.019042264736102751, 0.018551177652000546, 0.018059626789423293,
      0.017567624437116909, 0.017075182895114577, 0.0165823144744292,
      0.016089031496745575, 0.01559534629411255, 0.015101271208634429,
      0.01460681859216257, 0.014112000805986721, 0.013616830220525726,
      0.013121319215018424, 0.012625480177214149, 0.012129325503062977,
      0.011632867596406006, 0.011136118868665001, 0.010639091738532246,
      0.010141798631660188, 0.0096442519803505572, 0.00914646422324372,
      0.00864844780500768, 0.0081502151760269124, 0.0076517787920912786,
      0.00715315111408437, 0.0066543446076721266, 0.0061553717429913149,
      0.0056562449943375207, 0.0051569768398534643, 0.0046575797612170029,
      0.0041580662433290489, 0.0036584487740016223, 0.00315873984364539,
      0.002658951944957539, 0.002159097572609596, 0.0016591892229347906,
      0.0011592393936158275, 0.00065926058337240133, 0.00015926529164868284,
      -0.00034073398169898747, -0.00084072473671486191, -0.0013406944736561505,
      -0.001840630693305381, -0.0023405208972831449, -0.0028403525883603791,
      -0.0033401132707708385, -0.0038397904505235378, -0.0043393716357149189,
      -0.0048388443368414151, -0.0053381960671115575, -0.0058374143427580086,
      -0.0063364866833499241, -0.0068354006121047785, -0.0073341436562003419,
      -0.00783270334708653, -0.0083310672207969512, -0.00882922281826076,
      -0.00932715768561401, -0.0098248593745108685, -0.010322315442435073,
      -0.010819513453010838, -0.011316440976313792, -0.011813085589181781,
      -0.012309434875525261, -0.012805476426637969, -0.013301197841507004,
      -0.01379658672712273, -0.014291630698788849, -0.014786317380431853,
      -0.015280634404910466, -0.015774569414324865, -0.016268110060325455,
      -0.016761244004421832, -0.017253958918291123, -0.017746242484086058,
      -0.018238082394743171, -0.018729466354290316, -0.0192203820781541,
      -0.01971081729346703, -0.020200759739374186, -0.020690197167339979,
      -0.021179117341454244, -0.021667508038738008, -0.02215535704944932,
      -0.022642652177388315, -0.023129381240202182, -0.023615532069689745,
      -0.024101092512105494, -0.024586050428463704, -0.025070393694841771,
      -0.025554110202683167, -0.026037187859100443, -0.026519614587177338,
      -0.027001378326270788, -0.027482467032312441, -0.027962868678109626,
      -0.028442571253646257, -0.028921562766382965, -0.029399831241556804,
      -0.029877364722480843, -0.030354151270842934, -0.0308301789670042,
      -0.031305435910297066, -0.031779910219322624, -0.0322535900322479,
      -0.032726463507102281, -0.033198518822073454, -0.033669744175803158,
      -0.0341401277876821, -0.034609657898144477, -0.035078322768962028,
      -0.035546110683537309, -0.036013009947196854, -0.036479008887483448,
      -0.036944095854447669, -0.037408259220939821, -0.037871487382899763,
      -0.0383337687596476, -0.038795091794173037, -0.039255444953424146,
      -0.039714816728595982, -0.040173195635418074, -0.040630570214441636,
      -0.041086929031326054, -0.04154226067712459, -0.041996553768569853,
      -0.042449796948358265, -0.042901978885433845, -0.043353088275271776,
      -0.043803113840160786, -0.044252044329485207, -0.044699868520006229,
      -0.045146575216142321, -0.045592153250249387, -0.046036591482899833,
      -0.0464798788031609, -0.046922004128872714, -0.047362956406925158,
      -0.047802724613534249, -0.04824129775451777, -0.048678664865569946,
      -0.049114815012535826, -0.049549737291684492, -0.049983420829981549,
      -0.050415854785361147, -0.050847028346996948, -0.051276930735572351,
      -0.051705551203550061, -0.05213287903544065, -0.052558903548070607,
      -0.05298361409084934, -0.053407000046035318, -0.053829050829001773,
      -0.054249755888501075, -0.054669104706928685, -0.055087086800585994,
      -0.055503691719942384, -0.055918909049896583, -0.056332728410037,
      -0.056745139454901145, -0.057156131874234378, -0.057565695393247643,
      -0.057973819772874281, -0.0583804948100261, -0.058785710337848275,
      -0.059189456225973769, -0.059591722380776424, -0.059992498745623263,
      -0.060391775301126063, -0.060789542065391736, -0.061185789094271893,
      -0.061580506481611487, -0.06197368435949633, -0.062365312898499975,
      -0.062755382307929361, -0.063143882836069545, -0.063530804770427565,
      -0.063916138437975209, -0.064299874205390892, -0.0646820024793004,
      -0.065062513706516736, -0.065441398374279092, -0.065818647010490533,
      -0.066194250183954723, -0.066568198504611917, -0.0669404826237736,
      -0.067311093234356176, -0.067680021071113691, -0.068047256910869408,
      -0.068412791572746476, -0.068776615918397413, -0.06913872085223248,
      -0.0694990973216472, -0.069857736317248634, -0.07021462887308054,
      -0.070569766066847672, -0.070923139020138623, -0.071274738898647952,
      -0.0716245569123971, -0.071972584315953811, -0.07231881240865122,
      -0.072663232534805, -0.073005836083929951, -0.073346614490955239,
      -0.073685559236438339, -0.0740226618467783, -0.074357913894427488,
      -0.074691306998102086, -0.0750228328229919, -0.075352483080968577,
      -0.075680249530792831, -0.076006123978320489, -0.076330098276707337,
      -0.076652164326612857, -0.07697231407640244, -0.0772905395223491,
      -0.077606832708833229, -0.077921185728541675, -0.07823359072266528,
      -0.078544039881095484, -0.078852525442619559, -0.079159039695114411,
      -0.079463574975739748, -0.0797661236711294, -0.080066678217581774,
      -0.080365231101248838, -0.080661774858324056, -0.080956302075228956,
      -0.081248805388798417, -0.081539277486464945, -0.081827711106441089,
      -0.082114099037901414, -0.082398434121162586, -0.082680709247862291,
      -0.082960917361137088, -0.08323905145579874, -0.0835151045785094,
      -0.083789069827955309, -0.0840609403550195, -0.084330709362953,
      -0.08459837010754466, -0.084863915897289768, -0.085127340093557449,
      -0.085388636110756519, -0.085647797416500124, -0.085904817531769137,
      -0.086159690031074057, -0.086412408542615685, -0.086662966748444384,
      -0.086911358384618123, -0.087157577241358822, -0.087401617163207934,
      -0.087643472049180146, -0.087883135852915878, -0.088120602582832538,
      -0.088355866302274225, -0.088588921129660228, -0.088819761238632,
      -0.089048380858198856, -0.089274774272882162, -0.089498935822858353,
      -0.089720859904100392, -0.089940540968517779, -0.090157973524095339,
      -0.090373152135030541, -0.090586071421869321, -0.090796726061640548,
      -0.09100511078798923, -0.091211220391308037, -0.091415049718867658,
      -0.0916165936749455, -0.091815847220953151, -0.092012805375562376,
      -0.092207463214829519, -0.0923998158723188, -0.092589858539223732,
      -0.092777586464487555, -0.09296299495492194, -0.093146079375324264,
      -0.093326835148593565, -0.093505257755844909, -0.093681342736522455,
      -0.0938550856885108, -0.0940264822682452, -0.09419552819082011,
      -0.094362219230096245, -0.094526551218806334, -0.094688520048659214,
      -0.09484812167044257, -0.095005352094124154, -0.095160207388951618,
      -0.095312683683550573, -0.09546277716602164, -0.09561048408403558,
      -0.095755800744927122, -0.095898723515787321, -0.096039248823554343,
      -0.096177373155102844, -0.09631309305733167, -0.096446405137250377,
      -0.096577306062063883, -0.096705792559255918, -0.096831861416670717,
      -0.096955509482593419, -0.097076733665828835, -0.097195530935778665,
      -0.0973118983225174, -0.097425832916866351, -0.097537331870466648,
      -0.097646392395850268, -0.0977530117665097, -0.0978571873169663,
      -0.097958916442836691, -0.09805819660089804, -0.098155025309151558,
      -0.098249400146884575, -0.09834131875473108, -0.098430778834730656,
      -0.098517778150385954, -0.098602314526718624, -0.098684385850323658,
      -0.098763990069422242, -0.098841125193913068, -0.098915789295422,
      -0.0989879805073504, -0.099057697024921731, -0.0991249371052267,
      -0.099189699067266782, -0.099251981291996319, -0.099311782222362921,
      -0.099369100363346452, -0.099423934281996362, -0.099476282607467562,
      -0.099526144031054614, -0.099573517306224546, -0.099618401248647931,
      -0.099660794736228561, -0.099700696709131439, -0.09973810616980934,
      -0.099773022183027679, -0.099805443875887953, -0.099835370437849513,
      -0.0998628011207499, -0.099887735238823439, -0.099910172168718489,
      -0.099930111349512962, -0.0999475522827284, -0.099962494532342377,
      -0.0999749377247994, -0.099984881549020341, -0.0999923257564101,
      -0.099997270160863863, -0.0999997146387718, -0.099999659129022089,
      -0.09999710363300246, -0.099992048214600171, -0.099984493000200445,
      -0.099974438178683234, -0.099961884001418547, -0.099946830782260174,
      -0.0999292788975378, -0.099909228786047632, -0.09988668094904142,
      -0.099861635950213912, -0.099834094415688759, -0.099804057034002913,
      -0.099771524556089342, -0.099736497795258283, -0.099698977627176957,
      -0.099658964989847609, -0.099616460883584071, -0.0995714663709868,
      -0.099523982576916276, -0.099474010688464842, -0.099421551954927134,
      -0.099366607687768768, -0.099309179260593544, -0.099249268109109154,
      -0.099186875731091265, -0.099122003686346077, -0.09905465359667133,
      -0.09898482714581576, -0.098912526079437, -0.098837752205057916,
      -0.098760507392021538, -0.098680793571444117, -0.098598612736167046,
      -0.0985139669407069, -0.098426858301204165, -0.0983372889953703,
      -0.098245261262433256, -0.0981507774030816, -0.0980538397794069,
      -0.097954450814844662, -0.097852612994113852, -0.097748328863154682,
      -0.097641601029064981, -0.097532432160035043, -0.097420824985280929,
      -0.097306782294976149, -0.097190306940182089, -0.0970714018327765,
      -0.096950069945380885, -0.096826314311286132, -0.0967001380243766,
      -0.096571544239052953, -0.096440536170153052, -0.096307117092871874,
      -0.09617129034267935, -0.096033059315237188, -0.095892427466313851,
      -0.095749398311698236, -0.095603975427111812, -0.095456162448119039,
      -0.095305963070036775, -0.095153381047841559, -0.094998420196076086,
      -0.094841084388753535, -0.0946813775592609, -0.094519303700260571,
      -0.094354866863590667, -0.094188071160163422, -0.094018920759862845,
      -0.093847419891440076, -0.0936735728424079, -0.093497383958933464,
      -0.093318857645729766, -0.093137998365945218, -0.092954810641052515,
      -0.09276929905073511, -0.092581468232773245, -0.092391322882927437,
      -0.09219886775482164, -0.092004107659823975, -0.0918070474669267,
      -0.091607692102624372, -0.091406046550790709, -0.091202115852554,
      -0.090995905106171032, -0.09078741946689986, -0.090576664146870448,
      -0.09036364441495498, -0.090148365596635485, -0.089930833073871383,
      -0.089711052284964246, -0.089489028724422479, -0.089264767942823467,
      -0.0890382755466751, -0.088809557198275435, -0.088578618615571383,
      -0.088345465572015322, -0.088110103896421321, -0.087872539472818992,
      -0.087632778240306519, -0.0873908261929022, -0.087146689379394751,
      -0.086900373903191608, -0.086651885922167049, -0.086401231648507437,
      -0.086148417348556772, -0.0858934493426592, -0.08563633400500173,
      -0.085377077763454337, -0.085115687099409587, -0.084852168547620413,
      -0.084586528696037014, -0.084318774185641668, -0.084048911710283336,
      -0.083776948016509784, -0.0835028899033992, -0.083226744222390084,
      -0.082948517877110231, -0.082668217823203577, -0.082385851068157087,
      -0.0821014246711247, -0.081814945742751777, -0.081526421444996347,
      -0.081235858990951024, -0.080943265644661949, -0.080648648720947569,
      -0.080352015585215542, -0.080053373653278984, -0.079752730391170437,
      -0.07945009331495595, -0.079145469990546613, -0.078838868033509646,
      -0.078530295108878, -0.078219758930958852, -0.077907267263140262,
      -0.077592827917697879, -0.07727644875559872, -0.0769581376863056,
      -0.076637902667578431, -0.076315751705276214, -0.0759916928531561,
      -0.075665734212672586, -0.0753378839327746, -0.075008150209702265,
      -0.074676541286781237, -0.0743430654542175, -0.074007731048889441,
      -0.073670546454139715, -0.0733315200995656, -0.072990660460808446,
      -0.072647976059341243, -0.072303475462256447, -0.071957167282050746,
      -0.0716090601764109, -0.071259162847996146, -0.070907484044221675,
      -0.0705540325570392, -0.070198817222717466, -0.0698418469216213,
      -0.069483130577989813, -0.069122677159712639, -0.0687604956781067,
      -0.068396595187690076, -0.068030984785956067, -0.067663673613145625,
      -0.067294670852019137, -0.066923985727626131, -0.0665516275070757,
      -0.0661776054993037, -0.065801929054841085, -0.065424607565579149,
      -0.065045650464535656, -0.06466506722561835, -0.064282867363388382,
      -0.063899060432822313, -0.063513656029073634, -0.063126663787232085,
      -0.06273809338208379, -0.062347954527868538, -0.061956256978037361,
      -0.061563010525008566, -0.061168224999923186, -0.060771910272398512,
      -0.060374076250282377, -0.0599747328794043, -0.059573890143328083,
      -0.05917155806310094, -0.058767746697004131, -0.058362466140300731,
      -0.057955726524983521, -0.057547538019521643, -0.05713791082860669,
      -0.0567268551928968, -0.056314381388761686, -0.055900499728024883,
      -0.055485220557706376, -0.055068554259763695, -0.054650511250832812,
      -0.0542311019819669, -0.053810336938376127, -0.05338822663916435,
      -0.052964781637067387, -0.052540012518187934, -0.05211392990173204,
      -0.051686544439742882, -0.051257866816834731, -0.050827907749925766,
      -0.050396677987970477, -0.049964188311690166, -0.049530449533304446,
      -0.049095472496260173, -0.0486592680749604, -0.048221847174493238,
      -0.047783220730358109, -0.047343399708193588, -0.046902395103502,
      -0.046460217941375739, -0.046016879276220744, -0.045572390191480551,
      -0.045126761799359059, -0.04468000524054308, -0.044232131683923023,
      -0.043783152326314689, -0.043333078392178578, -0.042881921133339593,
      -0.042429691828705624, -0.04197640178398597, -0.04152206233140783,
      -0.041066684829434166, -0.0406102806624785, -0.040152861240621548,
      -0.039694437999324705, -0.039235022399145392, -0.038774625925449578,
      -0.038313260088125134, -0.0378509364212939, -0.037387666483023684,
      -0.03692346185503851, -0.036458334142430132, -0.035992294973367069,
      -0.035525355998804263, -0.035057528892191686, -0.034588825349182888,
      -0.034119257087341683, -0.03364883584585051, -0.033177573385215563,
      -0.03270548148697415, -0.032232571953398806, -0.031758856607203484,
      -0.031284347291247093, -0.030809055868237813, -0.030332994220436379,
      -0.029856174249359442, -0.029378607875481112, -0.028900307037936113,
      -0.028421283694220392, -0.027941549819892587, -0.027461117408274491,
      -0.026979998470151617, -0.026498205033472028, -0.026015749143046892,
      -0.025532642860247992, -0.025048898262707578, -0.024564527444015057,
      -0.02407954251341592, -0.023593955595508091, -0.023107778829939224,
      -0.022621024371103055, -0.022133704387835955, -0.021645831063111784,
      -0.021157416593738505, -0.020668473190052331, -0.02017901307561289,
      -0.019689048486897461, -0.019198591672995504, -0.018707654895301472,
      -0.018216250427209587, -0.017724390553805616, -0.017232087571561115,
      -0.016739353788024654, -0.016246201521515419, -0.0157526431008143,
      -0.015258690864856116, -0.014764357162420942, -0.01426965435182586,
      -0.013774594800615018, -0.013279190885251674, -0.012783454990807823,
      -0.012287399510655005, -0.011791036846154302, -0.011294379406346738,
      -0.010797439607642085, -0.010300229873509786, -0.00980276263416694,
      -0.00930505032626898, -0.0088071053925973218, -0.00830894028174964,
      -0.0078105674478276725, -0.0073119993501263086, -0.0068132484528219371,
      -0.0063143272246612772, -0.0058152481386486952, -0.0053160236717356129,
      -0.0048166663045076134, -0.0043171885208728679, -0.0038176028077498664,
      -0.0033179216547556817, -0.0028181575538927589, -0.0023183229992379448,
      -0.0018184304866287187, -0.0013184925133522141, -0.00081852157783136946,
      -0.00031853017931379908, 0.00018146918244166406, 0.0006814640074770176,
      0.0011814417959477661, 0.0016813900484349714, 0.0021812962662587157,
      0.002681147951789324, 0.0031809326087607805, 0.003680637742582692,
      0.0041802508606528259, 0.0046797594726689885, 0.0051791510909422493,
      0.0056784132307078055, 0.0061775334104385224, 0.0066764991521555466,
      0.0071752979817416782, 0.0076739174292518924, 0.0081723450292260566,
      0.0086705683210001327, 0.0091685748490178652, 0.0096663521631417254,
      0.010163887818965137, 0.010661169378122356, 0.011158184408600391,
      0.011654920485049364, 0.012151365189093152, 0.01264750610964027,
      0.013143330843193197, 0.013638826994159765, 0.014133982175161748,
      0.014628784007345495, 0.015123220120690976, 0.015617278154321191,
      0.016110945756810775, 0.016604210586495725, 0.017097060311780723,
      0.017589482611448402, 0.01808146517496691, 0.018572995702797874,
      0.019064061906703438, 0.019554651510054429, 0.020044752248135962,
      0.020534351868455463, 0.021023438131047574, 0.021511998808781553,
      0.022000021687665641, 0.022487494567153373, 0.022974405260448149,
      0.023460741594808081, 0.023946491411849884, 0.024431642567853774,
      0.024916182934065861, 0.025400100397002315, 0.025883382858751764,
      0.026366018237277924, 0.026847994466721203, 0.027329299497701326,
      0.027809921297617231, 0.028289847850949297, 0.028769067159558348,
      0.029247567242986973, 0.029725336138757743, 0.030202361902673239,
      0.0306786326091142, 0.031154136351337871, 0.031628861241775191,
      0.03210279541232898, 0.032575927014669388, 0.033048244220531091,
      0.033519735222008545, 0.033990388231851354, 0.034460191483758527,
      0.034929133232673569, 0.035397201755076858, 0.035864385349280041,
      0.036330672335717254, 0.036796051057238467, 0.03726050987939962,
      0.037724037190754442, 0.038186621403144286, 0.038648250951988018,
      0.039108914296570714, 0.039568599920333083, 0.040027296331158223,
      0.040484992061659834, 0.0409416756694685, 0.041397335737517887,
      0.041851960874329776, 0.042305539714299761, 0.042758060917980151,
      0.043209513172364718, 0.043659885191170311, 0.04410916571512024,
      0.044557343512224561, 0.045004407378061766, 0.0454503461360585,
      0.045895148637769112, 0.046338803763153996, 0.046781300420858429,
      0.047222627548488792, 0.047662774112889952, 0.048101729110420724,
      0.048539481567229106, 0.048976020539526252, 0.049411335113860894,
      0.049845414407391042, 0.050278247568157276, 0.050709823775352804,
      0.051140132239595237, 0.051569162203195157, 0.051996902940425874,
      0.052423343757791258, 0.052848473994293155, 0.053272283021697564,
      0.05369476024480118, 0.054115895101695191, 0.0545356770640302,
      0.054954095637279016, 0.055371140360999153, 0.055786800809094018,
      0.056201066590074379, 0.056613927347316975, 0.05702537275932467,
      0.05743539253998331, 0.057843976438820027, 0.058251114241258388,
      0.058656795768874642, 0.0590610108796517, 0.059463749468232935,
      0.0598650014661744, 0.0602647568421973, 0.060663005602437869,
      0.061059737790697913, 0.061454943488693375, 0.061848612816302467,
      0.062240735931812285, 0.062631303032165658, 0.063020304353205131,
      0.063407730169918214, 0.0637935707966794, 0.064177816587493372,
      0.0645604579362352, 0.064941485276891128, 0.0653208890837975,
      0.065698659871878978, 0.066074788196885323, 0.066449264655628268,
      0.066822079886215677, 0.067193224568286219, 0.0675626894232422,
      0.067930465214481553, 0.068296542747628461, 0.068660912870763785,
      0.069023566474653561, 0.069384494492976373, 0.06974368790255063,
      0.070101137723559817, 0.070456835019777064, 0.070810770898788331,
      0.0711629365122153, 0.071513323055935787, 0.071861921770304538,
      0.072208723940371852, 0.072553720896101556, 0.0728969040125876,
      0.073238264710270146, 0.073577794455149309, 0.073915484758999381,
      0.074251327179580121, 0.074585313320848751, 0.074917434833168942,
      0.075247683413520255, 0.075576050805705383, 0.07590252880055666,
      0.076227109236141066, 0.07654978399796486, 0.07687054501917559,
      0.077189384280764523, 0.077506293811766713, 0.077821265689460434,
      0.078134292039565012, 0.078445365036438189, 0.078754476903271045,
      0.079061619912283221, 0.079366786384915275, 0.079669968692021476,
      0.079971159254059829, 0.080270350541281968, 0.080567535073921337,
      0.08086270542238011, 0.081155854207414835, 0.081446974100321326,
      0.0817360578231173, 0.082023098148724771, 0.082308087901150559,
      0.082591019955665743, 0.082871887238983533, 0.083150682729436709,
      0.0834273994571523, 0.08370203050422674, 0.083974569004897956,
      0.084245008145717809, 0.084513341165721734, 0.084779561356598254,
      0.085043662062856448, 0.085305636681992481, 0.08556547866465436,
      0.085823181514806252, 0.086078738789890183, 0.0863321441009876,
      0.086583391112979, 0.086832473544702152, 0.087079385169109125,
      0.087324119813422321, 0.087566671359288237, 0.087807033742931,
      0.0880452009553034, 0.088281167042237679, 0.088514926104593827,
      0.088746472298407528, 0.088975799835035965, 0.08920290298130272,
      0.089427776059640848, 0.089650413448235253, 0.0898708095811627,
      0.090088958948531375, 0.09030485609661848, 0.090518495628006582,
      0.090729872201718409, 0.090938980533350769, 0.091145815395206137,
      0.091350371616423856, 0.091552644083108925, 0.091752627738460366,
      0.091950317582897068, 0.092145708674183285, 0.0923387961275519,
      0.092529575115826657, 0.0927180408695427, 0.092904188677066138,
      0.093088013884711371, 0.09326951189685781, 0.093448678176064615,
      0.093625508243184163, 0.093799997677473892, 0.093972142116707166,
      0.09414193725728183, 0.094309378854328343, 0.09447446272181538,
      0.094637184732654978, 0.094797540818805259, 0.094955526971372425,
      0.0951111392407109, 0.095264373736522079, 0.095415226627951488,
      0.095563694143684777, 0.095709772572041732, 0.095853458261069266,
      0.095994747618632636, 0.096133637112505277, 0.096270123270457017,
      0.096404202680341111, 0.096535871990179184, 0.096665127908245468,
      0.096791967203148643, 0.096916386703913018, 0.0970383833000575,
      0.097157953941673564, 0.097275095639501374, 0.097389805465004642,
      0.097502080550443626, 0.097611918088947119, 0.097719315334582307,
      0.097824269602423686, 0.097926778268620007, 0.098026838770459979,
      0.09812444860643621, 0.098219605336307969, 0.098312306581161885,
      0.09840255002347173, 0.098490333407156086, 0.098575654537634977,
      0.098658511281884589, 0.098738901568490578, 0.098816823387700037,
      0.0988922747914715, 0.0989652538935238, 0.0990357588693832,
      0.09910378795642899, 0.099169339453937508, 0.099232411723124747,
      0.099293003187187256, 0.099351112331341584, 0.099406737702862166,
      0.099459877911117614, 0.099510531627605481, 0.099558697585985484,
      0.099604374582111188, 0.099647561474060065, 0.099688257182162066,
      0.099726460689026589, 0.099762171039567984, 0.099795387341029329,
      0.099826108763004809, 0.09985433453746051, 0.099880063958753484,
      0.0999032963836496, 0.0999240312313394, 0.099942267983452793,
      0.099958006184071926, 0.0999712454397426, 0.09998198541948411,
      0.099990225854797526, 0.0999959665396724, 0.09999920733059188,
      0.0999999481465364, 0.09999818896898556, 0.099993929841918752,
      0.099987170871813913, 0.099977912227644919, 0.099966154140877422,
      0.099951896905462967, 0.0999351408778317, 0.099915886476883445,
      0.0998941341839772, 0.099869884542919188, 0.099843138159949149,
      0.099813895703725272, 0.099782157905307436, 0.099747925558138953,
      0.0997111995180267, 0.09967198070311982, 0.099630270093886572,
      0.099586068733090061, 0.099539377725761991, 0.099490198239175126,
      0.099438531502814037, 0.0993843788083445, 0.099327741509580972,
      0.099268621022453055, 0.0992070188249698, 0.099142936457182959,
      0.099076375521148355, 0.099007337680885973, 0.09893582466233819,
      0.098861838253326756, 0.098785380303508016, 0.098706452724326765,
      0.098625057488968382, 0.098541196632309466, 0.098454872250867076,
      0.098366086502746322, 0.098274841607586191, 0.098181139846504367,
      0.098084983562039957, 0.097986375158095121, 0.097885317099874747,
      0.0977818119138251, 0.097675862187570364, 0.097567470569848269,
      0.0974566397704435, 0.097343372560120364, 0.0972276717705532,
      0.097109540294255683, 0.0969889810845086, 0.096865997155285932,
      0.096740591581179453, 0.096612767497322061, 0.096482528099309087,
      0.096349876643118823, 0.096214816445030632, 0.096077350881542567,
      0.095937483389286426, 0.09579521746494235, 0.095650556665150918,
      0.0955035046064247, 0.095354064965057439, 0.095202241477032434,
      0.095048037937928889, 0.094891458202827322, 0.094732506186213,
      0.094571185861877946, 0.094407501262821908, 0.094241456481151425,
      0.094073055667977259, 0.0939023030333111, 0.093729202845959758,
      0.093553759433419079, 0.093375977181765074, 0.093195860535544919,
      0.093013413997665273, 0.092828642129280187, 0.092641549549676627,
      0.092452140936159388, 0.092260421023934031, 0.092066394605988242,
      0.091870066532972416, 0.091671441713078228, 0.0914705251119157,
      0.091267321752389524, 0.091061836714572963, 0.090854075135581427,
      0.0906440422094434, 0.090431743186971253, 0.09021718337562934,
      0.090000368139401918, 0.089781302898658447, 0.0895599931300187,
      0.0893364443662152, 0.089110662195955551, 0.088882652263782114,
      0.088652420269931365, 0.088419971970191275, 0.088185313175757049,
      0.0879484497530865, 0.08770938762375266, 0.087468132764296533,
      0.087224691206076815, 0.08697906903512, 0.086731272391967373,
      0.086481307471522273, 0.086229180522894536, 0.085974897849244836,
      0.08571846580762682, 0.085459890808828057, 0.085199179317210091,
      0.084936337850546731, 0.084671372979860784, 0.084404291329260417,
      0.084135099575772754, 0.083863804449177834, 0.083590412731839481,
      0.0833149312585366, 0.083037366916291488, 0.0827577266441984,
      0.082476017433249421, 0.082192246326160331, 0.081906420417193815,
      0.081618546851982943, 0.08132863282735163, 0.081036685591135485,
      0.080742712442000333, 0.080446720729259374, 0.080148717852690107,
      0.079848711262349034, 0.079546708458385074, 0.079242716990852835,
      0.078936744459522923, 0.078628798513692921, 0.078318886851995229,
      0.078007017222205433, 0.077693197421047841, 0.077377435294001345,
      0.077059738735102468, 0.076740115686748725, 0.076418574139499817,
      0.076095122131877441, 0.075769767750165043, 0.075442519128205349,
      0.075113384447196618, 0.074782371935488978, 0.074449489868377766,
      0.074114746567897516, 0.0737781504026131, 0.07343970978741135,
      0.073099433183289764, 0.072757329097145981, 0.072413406081564088,
      0.072067672734601809, 0.071720137699574568, 0.071370809664840371,
      0.071019697363581658, 0.0706668095735878, 0.070312155117035285,
      0.0699557428602668, 0.069597581713570347, 0.069237680630956047,
      0.068876048609931961, 0.06851269469128006, 0.068147627958829116,
      0.067780857539228676, 0.06741239260171987, 0.06704224235790722,
      0.06667041606152728, 0.066296923008218336, 0.065921772535287013,
      0.06554497402147573, 0.065166536886727855, 0.064786470591951764,
      0.064404784638785156, 0.064021488569357118, 0.063636591966049191,
      0.063250104451256631, 0.062862035687146919, 0.062472395375419244,
      0.06208119325706081, 0.061688439112104476, 0.061294142759383143,
      0.060898314056285353, 0.060500962898507815, 0.060102099219809038,
      0.059701732991759938, 0.059299874223495655, 0.058896532961464167,
      0.058491719289176174, 0.058085443326952528, 0.057677715231670847,
      0.057268545196512421, 0.056857943450706966, 0.056445920259276444,
      0.056032485922779478, 0.055617650777052642, 0.055201425192953291,
      0.054783819576099027, 0.054364844366608836, 0.053944510038840834,
      0.053522827101131626, 0.053099806095532366, 0.052675457597546341,
      0.052249792215864038, 0.051822820592097522, 0.051394553400515311,
      0.050965001347775041, 0.050534175172655342, 0.050102085645788469,
      0.04966874356938978, 0.049234159776988917, 0.048798345133157756,
      0.04836131053324, 0.047923066903077571, 0.047483625198738721,
      0.047042996406242842, 0.046601191541287112, 0.046158221648969849,
      0.045714097803515583, 0.04526883110799701, 0.044822432694058494,
      0.04437491372163728, 0.043926285378684066, 0.043476558880884357,
      0.043025745471376872, 0.042573856420473691, 0.042120903025377215,
      0.041666896609899071, 0.041211848524175664, 0.040755770144385757,
      0.040298672872464775, 0.039840568135820875, 0.039381467387048764,
      0.038921382103642932, 0.038460323787711664, 0.037998303965689005,
      0.03753533418804611, 0.037071426029003651, 0.036606591086241105,
      0.036140840980608151, 0.035674187355832859, 0.035206641878231866,
      0.034738216236417423, 0.034268922141006519, 0.033798771324326758,
      0.033327775540124414, 0.03285594656326922, 0.032383296189461355,
      0.031909836234935214, 0.031435578536165167, 0.030960534949569154,
      0.030484717351211763, 0.030008137636508326, 0.029530807719927079,
      0.02905273953469072, 0.028573945032479328, 0.028094436183130178,
      0.027614224974339869, 0.027133323411363278, 0.026651743516714756,
      0.026169497329866259, 0.025686596906947686, 0.025203054320444104,
      0.024718881658895173, 0.02423409102659238, 0.023748694543275939,
      0.023262704343832832, 0.022776132577992894, 0.022288991410024592,
      0.0218012930184321, 0.02131304959564945, 0.020824273347737138,
      0.020334976494075559, 0.019845171267060913, 0.019354869911798019,
      0.018864084685795566, 0.018372827858658302, 0.01788111171178166,
      0.017388948538043358, 0.01689635064149745, 0.016403330337065352,
      0.015909899950229161, 0.015416071816723033, 0.01492185828222423,
      0.014427271702045552, 0.01393232444082592, 0.01343702887222073,
      0.012941397378593756, 0.012445442350706172, 0.011949176187408195,
      0.011452611295327708, 0.010955760088561507, 0.010458634988363526,
      0.0099612484228357324, 0.0094636128266160063, 0.0089657406405685112,
      0.0084676443114721413, 0.0079693362917088346, 0.0074708290389533015,
      0.006972135015861078, 0.0064732666897564118, 0.0059742365323218289,
      0.0054750570192849185, 0.0049757406301078619, 0.0044762998476740277,
      0.0039767471579773206, 0.0034770950498086081, 0.0029773560144449266,
      0.0024775425453357766, 0.0019776671377922097, 0.0014777422886730236,
      0.00097778049607376424, 0.00047779425901285118, -2.220392287965203E-5,
      -0.00052220154967506211, -0.0010221861214591058, -0.0015221451386433519,
      -0.0020220661022782326, -0.00252193651436605, -0.0030217438781721812,
      -0.0035214756985389182, -0.0040211194821964244, -0.0045206627380764862,
      -0.0050200929776233688, -0.0055193977151074512, -0.0060185644679359484,
      -0.0065175807569663909, -0.0070164341068173659, -0.0075151120461809306,
      -0.0080136021081349314, -0.008511891830453604, -0.0090099687559196655,
      -0.0095078204326362742, -0.010005434414337088, -0.010502798260698836,
      -0.01099989953765091, -0.011496725817687632, -0.011993264680177522,
      -0.012489503711675232, -0.01298543050623047, -0.01348103266569955,
      -0.013976297800053951, -0.014471213527691455, -0.0149657674757443,
      -0.015459947280389894, -0.015953740587158684, -0.016447135051243542,
      -0.016940118337808913, -0.017432678122297967, -0.017924802090742081,
      -0.01841647794006734, -0.018907693378403465, -0.019398436125389724,
      -0.019888693912483362, -0.02037845448326488, -0.020867705593745869,
      -0.021356435012673869, -0.021844630521838698, -0.02233227991637839,
      -0.022819371005083314, -0.023305891610701443, -0.023791829570243325,
      -0.024277172735284937, -0.024761908972272772, -0.02524602616282581,
      -0.025729512204039847, -0.026212355008788692, -0.026694542506027708,
      -0.027176062641094248, -0.027656903376010344, -0.028137052689782335,
      -0.028616498578702722, -0.029095229056648915, -0.029573232155384235,
      -0.030050495924855938, -0.030527008433494481, -0.0310027577685123,
      -0.031477732036200641, -0.031951919362227368, -0.032425307891934367,
      -0.032897885790632714, -0.0333696412438999, -0.033840562457873813,
      -0.034310637659548976, -0.034779855097069504, -0.035248203040024205,
      -0.0357156697797386, -0.036182243629568844, -0.036647912925192837,
      -0.037112666024902284, -0.037576491309894232, -0.038039377184560526,
      -0.038501312076778267, -0.038962284438199518, -0.039422282744538947,
      -0.03988129549586316, -0.040339311216876964, -0.04079631845721151,
      -0.041252305791709271, -0.04170726182071096, -0.042161175170339217,
      -0.042614034492784274, -0.043065828466586326, -0.043516545796919888,
      -0.043966175215874849, -0.044414705482739479, -0.0448621253842803,
      -0.045308423735022918, -0.045753589377532142, -0.046197611182689918,
      -0.046640478049974093, -0.047082178907736361, -0.047522702713477985,
      -0.047962038454127054, -0.048400175146312646, -0.04883710183664057,
      -0.049272807601966027, -0.049707281549667873, -0.050140512817919737,
      -0.050572490575962796, -0.051003204024375443, -0.051432642395343731,
      -0.051860794952931083, -0.052287650993345682, -0.052713199845208607,
      -0.053137430869821034, -0.053560333461429133, -0.05398189704749045,
      -0.054402111088936979, -0.054820965080439737, -0.055238448550671032,
      -0.055654551062565262, -0.0560692622135816, -0.056482571635962868,
      -0.05689446899699533, -0.057304943999265827, -0.05771398638092097,
      -0.058121585915922674, -0.058527732414303639, -0.058932415722422429,
      -0.059335625723217683, -0.059737352336460117, -0.060137585519005589,
      -0.060536315265045264, -0.060933531606356089, -0.061329224612550387,
      -0.061723384391323868, -0.06211600108870205, -0.062507064889288214,
      -0.062896566016507865, -0.063284494732852956, -0.063670841340125656,
      -0.064055596179681179, -0.0644387496326683, -0.0648202921202709,
      -0.06520021410394658, -0.065578506085665358, -0.065955158608147532,
      -0.066330162255099939, -0.066703507651450389, -0.0670751854635837,
      -0.0674451863995739, -0.067813501209417162, -0.068180120685261858,
      -0.068545035661640483, -0.068908237015697607, -0.069269715667418574,
      -0.069629462579855389, -0.069987468759354229, -0.070343725255779407,
      -0.070698223162736926, -0.071050953617797438, -0.071401907802718184,
      -0.0717510769436626, -0.072098452311420577, -0.0724440252216259,
      -0.072787787034973669, -0.0731297291574366, -0.073469843040479543,
      -0.073808120181273029, -0.074144552122906035, -0.0744791304545978,
      -0.074811846811907168, -0.075142692876942821, -0.075471660378570227,
      -0.07579874109261886, -0.076123926842088019, -0.076447209497351162,
      -0.076768580976358247, -0.077088033244839288, -0.077405558316504211,
      -0.077721148253242972, -0.078034795165323162, -0.078346491211588529,
      -0.07865622859965414, -0.07896399958610166, -0.079269796476672011,
      -0.079573611626459081, -0.079875437440100047, -0.08017526637196519,
      -0.080473090926346719, -0.0807689036576465, -0.081062697170561443,
      -0.08135446412026924, -0.081644197212611236, -0.0819318892042751,
      -0.082217532902976162, -0.082501121167637, -0.082782646908565377,
      -0.083062103087632622, -0.083339482718448932, -0.083614778866537884,
      -0.08388798464951, -0.084159093237235139, -0.084428097852012537,
      -0.084694991768741013, -0.084959768315086476, -0.085222420871648941,
      -0.085482942872128279, -0.08574132780348824, -0.085997569206118618,
      -0.086251660673997879, -0.086503595854852566, -0.086753368450316448,
      -0.087000972216087283, -0.087246400962084025, -0.087489648552600788,
      -0.087730708906460675, -0.08796957599716701, -0.088206243853055186,
      -0.08844070655744117, -0.0886729582487695, -0.088902993120759929,
      -0.08913080542255275, -0.089356389458852173, -0.08957973959006918,
      -0.089800850232462037, -0.090019715858276131, -0.0902363309958823,
      -0.090450690229913519, -0.0906627882013998, -0.090872619607903063,
      -0.091080179203649164, -0.091285461799658921, -0.091488462263878065,
      -0.091689175521305691, -0.0918875965541207, -0.092083720401807734,
      -0.092277542161280743, -0.092469056987005763, -0.092658260091122213,
      -0.092845146743562451, -0.093029712272169662, -0.093211952062815351,
      -0.093391861559514261, -0.093569436264538453, -0.093744671738529337,
      -0.093917563600609266, -0.094088107528490728, -0.094256299258584517,
      -0.094422134586105891, -0.094585609365180429, -0.094746719508947239,
      -0.094905460989661031, -0.095061829838793022, -0.095215822147130216,
      -0.095367434064872858, -0.095516661801730962, -0.095663501627018852,
      -0.095807949869748471, -0.095950002918721355, -0.096089657222618752,
      -0.09622690929009016, -0.096361755689841122, -0.096494193050718727,
      -0.0966242180617958, -0.0967518274724538, -0.096877018092464171,
      -0.09699978679206786, -0.09712013050205387, -0.097238046213835638,
      -0.097353530979526523, -0.0974665819120134, -0.097577196185028942,
      -0.097685371033221918, -0.097791103752226841, -0.097894391698731251,
      -0.097995232290541912, -0.098093623006649158, -0.098189561387290278,
      -0.098283045034010752, -0.098374071609724334, -0.098462638838771266,
      -0.098548744506975483, -0.0986323864616998, -0.098713562611899675,
      -0.098792270928175552, -0.098868509442823688, -0.098942276249885108,
      -0.099013569505193549, -0.099082387426421323, -0.099148728293123933,
      -0.099212590446783211, -0.0992739722908487, -0.099332872290777363,
      -0.099389288974072357, -0.099443220930319542, -0.099494666811222765,
      -0.09954362533063775, -0.099590095264604023, -0.099634075451375648,
      -0.099675564791450247, -0.099714562247596519, -0.099751066844880054,
      -0.099785077670687825, -0.099816593874750947, -0.099845614669166027,
      -0.099872139328414627, -0.099896167189381685, -0.099917697651371928,
      -0.099936730176124963, -0.0999532642878286, -0.099967299573130941,
      -0.099978835681150582, -0.099987872323485424, -0.099994409274219875,
      -0.0999984463699305, -0.099999983509690138, -0.099999020655070353,
      -0.099995557830142467, -0.099989595121476926, -0.099981132678141141,
      -0.099970170711695741, -0.099956709496189344, -0.0999407493681516,
      -0.099922290726584886, -0.0999013340329543, -0.099877879811176073,
      -0.099851928647604546, -0.099823481191017457, -0.0997925381525997,
      -0.099759100305925663, -0.099723168486939767, -0.0996847435939356,
      -0.099643826587533485, -0.099600418490656484, -0.099554520388504722,
      -0.09950613342852839, -0.0994552588203989, -0.099401897835978914,
      -0.0993460518092902, -0.099287722136480516, -0.099226910275788616,
      -0.099163617747507926, -0.0990978461339483, -0.099029597079396667,
      -0.098958872290075828, -0.098885673534101867, -0.098810002641439812,
      -0.0987318615038581, -0.098651252074881055, -0.0985681763697402,
      -0.0984826364653239, -0.098394634500125269, -0.098304172674188783,
      -0.098211253249055511, -0.09811587854770619, -0.098018050954503333,
      -0.0979177729151317, -0.097815046936537128, -0.097709875586863615,
      -0.097602261495389531, -0.09749220735246146, -0.0973797159094273,
      -0.0972647899785673, -0.0971474324330237, -0.097027646206728976,
      -0.096905434294332668, -0.096780799751126148, -0.096653745692966531,
      -0.096524275296198517, -0.096392391797575513, -0.09625809849417799,
      -0.096121398743331574, -0.095982295962522779, -0.095840793629314081,
      -0.095696895281256383, -0.095550604515800788, -0.0954019249902089,
      -0.09525086042146115, -0.095097414586163789, -0.094941591320454821,
      -0.094783394519907652, -0.094622828139434123, -0.094459896193185428,
      -0.094294602754451673, -0.094126951955560131, -0.093956947987772252,
      -0.093784595101178259, -0.0936098976045913, -0.093432859865439727,
      -0.093253486309657879, -0.09307178142157517, -0.092887749743804468,
      -0.092701395877128, -0.092512724480382821, -0.092321740270344052,
      -0.09212844802160694, -0.091932852566467507, -0.0917349587948022,
      -0.091534771653944913, -0.0913322961485637, -0.0911275373405355,
      -0.090920500348820155, -0.090711190349331547, -0.090499612574808735,
      -0.090285772314684917, -0.090069674914955766, -0.089851325778044874,
      -0.089630730362669192, -0.089407894183702707, -0.089182822812038376,
      -0.088955521874448593, -0.088725997053445124, -0.08849425408713639,
      -0.088260298769084533, -0.088024136948160428, -0.0877857745283972,
      -0.087545217468842765, -0.087302471783411439, -0.087057543540732515,
      -0.086810438863999223, -0.086561163930815713, -0.0863097249730424,
      -0.086056128276639984, -0.085800380181512814, -0.085542487081349872,
      -0.085282455423465062, -0.085020291708636633, -0.084756002490943616,
      -0.084489594377602714, -0.084221074028802675, -0.0839504481575386,
      -0.083677723529443027, -0.083402906962617415, -0.083126005327461436,
      -0.082847025546501946, -0.082565974594218744, -0.082282859496870892,
      -0.08199768733232117, -0.081710465229858975, -0.081421200370021651,
      -0.081129899984415887, -0.0808365713555359, -0.080541221816582284,
      -0.080243858751278208, -0.079944489593684692, -0.079643121828014918,
      -0.0793397629884477, -0.079034420658938079, -0.078727102473028235,
      -0.078417816113656932, -0.078106569312967167, -0.077793369852112493,
      -0.077478225561063374, -0.077161144318410438, -0.076842134051168354,
      -0.076521202734577284, -0.076198358391903337, -0.075873609094238015,
      -0.075546962960297323, -0.075218428156217335, -0.074888012895351089,
      -0.074555725438062645, -0.074221574091521567, -0.073885567209493908,
      -0.07354771319213424, -0.073208020485775113, -0.072866497582717,
      -0.072523153021014461, -0.0721779953842635, -0.071831033301387209,
      -0.0714822754464197, -0.071131730538288945, -0.07077940734059962,
      -0.0704253146614131, -0.070069461353028009, -0.069711856311758677,
      -0.069352508477712363, -0.068991426834565966, -0.068628620409342256,
      -0.068264098272182716, -0.067897869536121674, -0.067529943356858566,
      -0.067160328932528851, -0.066789035503473621, -0.066416072352009511,
      -0.06604144880219566, -0.0656651742196014, -0.065287258011071839,
      -0.064907709624492382, -0.064526538548552656, -0.064143754312510223,
      -0.0637593664859508, -0.06337338467855004, -0.062985818539832719,
      -0.0625966777589327, -0.062205972064348948, -0.061813711223703473,
      -0.061419905043496592, -0.061024563368862854, -0.060627696083323246,
      -0.060229313108539108, -0.059829424404064205, -0.059428039967095447,
      -0.059025169832222585, -0.05862082407117828, -0.058215012792585209,
      -0.057807746141704364, -0.057399034300180944, -0.056988887485789542,
      -0.056577315952178867, -0.056164329988616424, -0.055749939919729478,
      -0.055334156105248035, -0.054916988939745948, -0.054498448852380782,
      -0.054078546306632606, -0.0536572918000435, -0.0532346958639539,
      -0.05281076906324033, -0.052385521996050892, -0.051958965293539966,
      -0.051531109619602583, -0.051101965670608929, -0.050671544175135065,
      -0.050239855893695978, -0.049806911618475884, -0.049372722173059748,
      -0.048937298412160782, -0.048500651221350326, -0.048062791516785094,
      -0.047623730244935526, -0.04718347838231024, -0.046742046935182704,
      -0.046299446939316272, -0.045855689459687939, -0.045410785590211271,
      -0.044964746453460151, -0.044517583200389448, -0.044069307010057353,
      -0.043619929089345449, -0.04316946067267817, -0.042717913021742167,
      -0.042265297425205829, -0.041811625198435176, -0.041356907683212096,
      -0.040901156247450936, -0.04044438228491401, -0.039986597214926284,
      -0.039527812482090974, -0.039068039556002361, -0.038607289930959306,
      -0.0381455751256791, -0.0376829066830075, -0.037219296169631474,
      -0.036754755175789376, -0.036289295314982532, -0.035822928223682875,
      -0.0353556655610434, -0.034887519008606004, -0.034418500270010789,
      -0.03394862107070145, -0.033477893157633332, -0.033006328298979912,
      -0.032533938283838264, -0.032060734921933821, -0.031586730043326336,
      -0.031111935498112732, -0.030636363156132093, -0.030160024906668359,
      -0.029682932658152791, -0.029205098337866414, -0.028726533891643032,
      -0.028247251283568531, -0.027767262495682978, -0.027286579527681244,
      -0.02680521439661266, -0.026323179136580097, -0.025840485798440289,
      -0.025357146449501208, -0.024873173173221567, -0.024388578068908248,
      -0.023903373251413441, -0.023417570850831973, -0.022931183012199242,
      -0.022444221895185537, -0.021956699673793423, -0.021468628536052695,
      -0.020980020683717071, -0.020490888331957058, -0.020001243709055982,
      -0.01951109905610356, -0.019020466626691289, -0.018529358686604,
      -0.018037787513514435, -0.017545765396676502, -0.01705330463661767,
      -0.016560417544830942, -0.016067116443468286, -0.015573413665031198,
      -0.015079321552063596, -0.014584852456842752, -0.014090018741070111,
      -0.013594832775562447, -0.013099306939943808, -0.01260345362233393,
      -0.012107285219039744, -0.011610814134245669, -0.011114052779703145,
      -0.010617013574419807, -0.010119708944350256, -0.0096221513220839851,
      -0.0091243531465358147, -0.0086263268626343859, -0.0081280849210106781,
      -0.0076296397776869284, -0.0071310038937664674, -0.0066321897351200691,
      -0.006133209772075719, -0.0056340764791065045, -0.005134802334518399,
      -0.0046353998201397219, -0.004135881421006969, -0.0036362596250539233,
      -0.00313654692279964, -0.0026367558070358264, -0.0021368987725139893,
      -0.0016369883156343143, -0.0011370369341318302, -0.00063705712676521357,
      -0.00013706139300378542, 0.00036293776728532921, 0.00086292785414951987,
      0.0013628963678619457, 0.0018628308092361592, 0.0023627186799373419,
      0.0028625474827945838, 0.0033623047221136696, 0.00386197790399,
      0.0043615545366196976, 0.0048610221306133218, 0.0053603681993068574,
      0.0058595802590744196, 0.00635864582964069, 0.0068575524343927538,
      0.0073562876006907684, 0.0078548388601819043, 0.0083531937491106416,
      0.0088513398086310664, 0.0093492645851169284, 0.0098469556304751054,
      0.01034440050245538, 0.010841586764962217, 0.011338501988364244,
      0.011835133749807106, 0.012331469633522813, 0.012827497231139946,
      0.013323204141994222, 0.01381857797343904, 0.014313606341154065,
      0.014808276869456233, 0.015302577191607934, 0.015796494950126673,
      0.016290017797094394, 0.016783133394465976, 0.017275829414376467,
      0.017768093539451382, 0.0182599134631134, 0.018751276889889881,
      0.019242171535720571, 0.019732585128265236, 0.020222505407209254,
      0.020711920124571528, 0.021200817045009427, 0.021689183946125234,
      0.022177008618772039, 0.022664278867358768, 0.023150982510153895,
      0.023637107379592053, 0.024122641322576816, 0.024607572200785247,
      0.025091887890969958, 0.025575576285264263, 0.026058625291483496,
      0.026541022833428005, 0.027022756851183674, 0.0275038153014255,
      0.027984186157717451, 0.0284638574108128, 0.028942817068955535,
      0.02942105315817899, 0.029898553722605661, 0.030375306824746484,
      0.030851300545799071, 0.031326522985944509, 0.0318009622646469,
      0.032274606520949128, 0.032747443913769304, 0.03321946262219707,
      0.033690650845789614, 0.034160996804865576, 0.0346304887408008,
      0.035099114916321165, 0.035566863615796543, 0.036033723145533957,
      0.036499681834069826, 0.03696472803246053, 0.037428850114575675,
      0.03789203647738737, 0.038354275541261, 0.03881555575024339,
      0.039275865572353658, 0.039735193499870237, 0.04019352804961919,
      0.040650857763259989, 0.041107171207573928, 0.041562456974748842,
      0.042016703682664094, 0.042469899975175487, 0.042922034522399635,
      0.043373096020996087, 0.043823073194451181, 0.044271954793358867,
      0.04471972959570239, 0.045166386407135162, 0.0456119140612605,
      0.0460563014199096, 0.046499537373421967, 0.046941610840922007,
      0.047382510770595895, 0.0478222261399682, 0.0482607459561779,
      0.048698059256252119, 0.049134155107381443, 0.049569022607192148,
      0.050002650884019242, 0.050435029097178535, 0.050866146437237525,
      0.051295992126284551, 0.051724555418200091, 0.052151825598924166,
      0.0525777919867248, 0.053002443932463894, 0.053425770819865215,
      0.053847762065778626, 0.054268407120445263, 0.054687695467760068,
      0.055105616625536508, 0.055522160145767524, 0.055937315614886678,
      0.0563510726540287, 0.05676342091928948, 0.057174350101983552,
      0.057583849928903058, 0.057991910162573483, 0.058398520601510122,
      0.058803671080473296, 0.059207351470722452, 0.059609551680268248,
      0.060010261654126706, 0.060409471374569493, 0.06080717086137423,
      0.061203350172074338, 0.061597999402207948, 0.061991108685564594,
      0.062382668194432937, 0.062772668139845514, 0.063161098771823868,
      0.063547950379622561, 0.063933213291971824, 0.064316877877318365,
      0.064698934544067818, 0.065079373740823385, 0.065458185956625267,
      0.065835361721187244, 0.066210891605135089, 0.066584766220241315,
      0.066956976219660236, 0.067327512298160738, 0.067696365192360441,
      0.0680635256809563, 0.06842898458495511, 0.0687927327679032,
      0.069154761136115128, 0.069515060638900367, 0.06987362226879032,
      0.0702304370617628, 0.070585496097466435, 0.070938790499443988,
      0.071290311435354012, 0.07164005011719092, 0.071987997801506165,
      0.072334145789625867, 0.072678485427868228, 0.073021008107760119,
      0.073361705266252589, 0.073700568385934209, 0.07403758899524486,
      0.074372758668686756, 0.0747060690270354, 0.0750375117375493,
      0.075367078514178218, 0.075694761117769391, 0.076020551356275057,
      0.076344441084956208, 0.07666642220658676, 0.076986486671654933,
      0.077304626478566021, 0.077620833673841441, 0.077935100352317987,
      0.078247418657344622, 0.078557780780980191, 0.0788661789641879,
      0.079172605497029008, 0.07947705271885637, 0.07977951301850518,
      0.0800799788344836, 0.080378442655161988, 0.080674897018960579,
      0.080969334514535307, 0.08126174778096433, 0.0815521295079313,
      0.081840472435908071, 0.082126769356336365, 0.08241101311180829,
      0.08269319659624455, 0.082973312755072942, 0.083251354585403975,
      0.083527315136206287, 0.083801187508480562, 0.084072964855431975,
      0.0843426403826406, 0.084610207348232491, 0.084875659063047448,
      0.085138988890806636, 0.085400190248277691, 0.085659256605440451,
      0.0859161814856495, 0.08617095846579638, 0.0864235811764695,
      0.086674043302114437, 0.08692233858119118, 0.087168460806330589,
      0.087412403824489782, 0.087654161537106159, 0.087893727900249352,
      0.088131096924772917, 0.088366262676463525, 0.088599219276189536,
      0.088829960900048188, 0.089058481779511048, 0.089284776201567717,
      0.089508838508869593, 0.089730663099870753, 0.089950244428967874,
      0.0901675770066391, 0.090382655399581457, 0.090595474230846185,
      0.090806028179973727, 0.091014311983126234, 0.091220320433219426,
      0.091424048380052844, 0.091625490730438561, 0.091824642448328025,
      0.092021498554938824, 0.092216054128878525, 0.092408304306268063,
      0.092598244280862718, 0.0927858693041732, 0.092971174685583649,
      0.093154155792469343, 0.093334808050311871, 0.093513126942814329,
      0.093689108012013744, 0.0938627468583925, 0.094034039140988415,
      0.094202980577503481, 0.094369566944410427, 0.094533794077058919,
      0.0946956578697791, 0.094855154275984552, 0.095012279308273453,
      0.095167029038528334, 0.095319399598013735, 0.095469387177473747,
      0.095616988027226735, 0.095762198457259085, 0.095905014837317559,
      0.096045433597000213, 0.096183451225845248, 0.096319064273419228,
      0.096452269349402986, 0.096583063123676524, 0.09671144232640233,
      0.09683740374810712, 0.096960944239761718, 0.097082060712860366,
      0.097200750139497569, 0.097317009552443878, 0.0974308360452199,
      0.0975422267721693, 0.097651178948529718, 0.0977576898505025,
      0.097861756815320472, 0.097963377241315042, 0.098062548587980858,
      0.098159268376039388, 0.098253534187500963, 0.098345343665725227,
      0.098434694515479981, 0.09852158450299868, 0.098606011456036133,
      0.098687973263922868, 0.098767467877618018, 0.0988444933097604,
      0.098919047634718149, 0.098991128988637045, 0.099060735569487038,
      0.0991278656371072, 0.099192517513249312, 0.0992546895816199,
      0.099314380287920445, 0.0993715881398864, 0.09942631170732448,
      0.0994785496221483, 0.099528300578412748, 0.099575563332346517,
      0.099620336702383183, 0.099662619569190827, 0.099702410875700018,
      0.099739709627130149, 0.099774514891014368, 0.099806825797222887,
      0.099836641537984758, 0.099863961367908, 0.099888784603998276,
      0.099911110625676, 0.099930938874791764, 0.099948268855640413,
      0.0999631001349733, 0.099975432342009216, 0.099985265168443638,
      0.099992598368456392, 0.099997431758717892, 0.099999765218393613,
      0.0999995986891472, 0.099996932175141856, 0.0999917657430403,
      0.099984099522003086, 0.0999739337036853, 0.099961268542231918,
      0.099946104354271273, 0.0999284415189073, 0.099908280477709971,
      0.099885621734704236, 0.0998604658563575, 0.099832813471565418,
      0.099802665271636171, 0.0997700220102732, 0.09973488450355629,
      0.099697253629921337, 0.0996571303301382, 0.099614515607287291,
      0.0995694105267344, 0.099521816216104286, 0.0994717338652522,
      0.099419164726234271, 0.099364110113276269, 0.099306571402740657,
      0.099246550033092171, 0.099184047504861969, 0.099119065380609939,
      0.099051605284885866, 0.098981668904188608, 0.098909257986924043,
      0.098834374343361286, 0.0987570198455876, 0.098677196427461367,
      0.098594906084563852, 0.098510150874149383, 0.098422932915093811,
      0.098333254387841518, 0.0982411175343511, 0.098146524658038983,
      0.098049478123722222, 0.097949980357559141, 0.097848033846988688,
      0.097743641140668233, 0.097636804848410141, 0.09752752764111608,
      0.097415812250710554, 0.097301661470072409, 0.097185078152965385,
      0.097066065213966268, 0.0969446256283923, 0.096820762432226745,
      0.096694478722043217, 0.0965657776549278, 0.096434662448400432,
      0.096301136380334482, 0.096165202788874748, 0.096026865072353862,
      0.0958861266892076, 0.095742991157888119, 0.0955974620567763,
      0.095449543024092143, 0.095299237757803731, 0.095146550015534737,
      0.094991483614471017, 0.09483404243126442, 0.094674230401936232,
      0.094512051521778953, 0.0943475098452562, 0.094180609485901151,
      0.094011354616214279, 0.093839749467558353, 0.093665798330053215,
      0.093489505552468308, 0.093310875542113841, 0.093129912764730621,
      0.092946621744378927, 0.0927610070633246, 0.092573073361924982,
      0.092382825338512692, 0.092190267749278673, 0.091995405408152486,
      0.091798243186682546, 0.091598786013913927, 0.091397038876265879,
      0.091193006817406178, 0.090986694938125612, 0.090778108396210477,
      0.090567252406313525, 0.090354132239823373, 0.090138753224733262,
      0.089921120745507177, 0.089701240242945832, 0.089479117214050427,
      0.089254757211885027, 0.089028165845437879, 0.088799348779481618,
      0.088568311734430832, 0.088335060486199546, 0.088099600866056865,
      0.087861938760481151, 0.087622080111012468, 0.087380030914104748,
      0.087135797220975128, 0.0868893851374533, 0.0866408008238286,
      0.086390050494695864, 0.086137140418800051, 0.085882076918880237,
      0.0856248663715105, 0.085365515206941078, 0.085104029908937423,
      0.084840417014618724, 0.084574683114293434, 0.084306834851295212,
      0.0840368789218165, 0.08376482207474184, 0.083490671111478065,
      0.083214432885784881, 0.08293611430360362, 0.08265572232288447,
      0.082373263953412115, 0.0820887462566313, 0.081802176345469421,
      0.081513561384159439, 0.08122290858806043, 0.080930225223477092,
      0.080635518607478182, 0.080338796107713828, 0.08004006514223122,
      0.079739333179288677, 0.079436607737169859, 0.079131896383994815,
      0.078825206737531628, 0.078516546465005582, 0.078205923282907319,
      0.077893344956799976, 0.077578819301125881, 0.077262354179009826,
      0.076943957502063356, 0.076623637230186614, 0.076301401371370148,
      0.075977257981493435, 0.075651215164124319, 0.07532328107031605,
      0.074993463898404319, 0.074661771893801063, 0.07432821334878896,
      0.073992796602314378, 0.073655530039778663, 0.073316422092828057,
      0.072975481239143811, 0.072632716002229258, 0.072288134951197611,
      0.071941746700557307, 0.07159355990999644, 0.071243583284166426,
      0.070891825572465136, 0.070538295568816842, 0.070183002111453036,
      0.069825954082691821, 0.069467160408715423, 0.069106630059346766,
      0.068744372047826061, 0.068380395430584454, 0.068014709307018556,
      0.067647322819262543, 0.067278245151959348, 0.066907485532031172,
      0.0665350532284497, 0.0661609575520029, 0.065785207855063171,
      0.065407813531353109, 0.065028784015711688, 0.064648128783856784,
      0.064265857352149389, 0.063881979277355061, 0.063496504156406286,
      0.0631094416261607, 0.062720801363161119, 0.062330593083394593,
      0.061938826542047076, 0.061545511533262, 0.061150657889894211,
      0.060754275483263981, 0.060356374222910937, 0.05995696405634602,
      0.059556054968802313, 0.059153656982986393, 0.058749780158826682,
      0.058344434593223027, 0.057937630419793162, 0.057529377808620386,
      0.057119686965998867, 0.056708568134178017, 0.0562960315911074,
      0.055882087650179373, 0.055466746659970173, 0.055050019003983652,
      0.054631915100389228, 0.0542124454017624, 0.053791620394824394,
      0.053369450600178163, 0.052945946572046279, 0.052521118898008305,
      0.052094978198732739, 0.051667535127715783, 0.051238800371011653,
      0.050808784646966636, 0.050377498705952033, 0.049944953330093605,
      0.049511159333002916, 0.049076127559508069, 0.048639868885379973,
      0.048202394217063065, 0.047763714491401425, 0.047323840675365034,
      0.046882783765776544, 0.046440554789035873, 0.045997164800844093,
      0.045552624885928143, 0.045106946157762409, 0.044660139758292208,
      0.044212216857653946, 0.043763188653896952, 0.0433130663727031,
      0.042861861267105665, 0.04240958461720893, 0.041956247729905922,
      0.0415018619385944, 0.041046438602896293, 0.040589989108370944,
      0.040132524866231624, 0.039674057313061208, 0.039214597910524319,
      0.038754158145081763, 0.038292749527704686, 0.037830383593583171,
      0.03736707190184247, 0.036902826035250427, 0.036437657599929195,
      0.035971578225066081, 0.035504599562620864, 0.035036733287035444,
      0.034567991094943178, 0.03409838470487362, 0.033627925856962393,
      0.033156626312656368, 0.032684497854419257, 0.032211552285438108,
      0.031737801429327674, 0.031263257129834347, 0.030787931250541235,
      0.030311835674570228, 0.029834982304286262, 0.029357383060998433,
      0.0288790498846631, 0.028399994733585111, 0.027920229584117429,
      0.027439766430364672, 0.026958617283880305, 0.026476794173367593,
      0.025994309144379887, 0.02551117425901744, 0.025027401595626882,
      0.024543003248500631, 0.024057991327570756, 0.023572377958111058,
      0.023086175280430138, 0.022599395449569258, 0.02211205063499954,
      0.021624153020315617, 0.021135714802932092, 0.020646748193779832,
      0.020157265416997736, 0.019667278709630066, 0.01917680032131917,
      0.018685842513998855, 0.018194417561588912, 0.017702537749687726,
      0.017210215375264633, 0.016717462746353697, 0.016224292181744624,
      0.0157307160106762, 0.015236746572526641, 0.014742396216506352,
      0.014247677301348655, 0.013752602195000314, 0.013257183274313378,
      0.012761432924735416, 0.012265363539998464, 0.011768987521812185,
      0.011272317279550829, 0.010775365229944231, 0.010278143796768453,
      0.0097806654105330737, 0.00928294250817149, 0.008784987532731393,
      0.0082868129330598232, 0.0077884311634968846, 0.0072898546835605043,
      0.0067910959576363622, 0.0062921674546673346, 0.0057930816478396589,
      0.0052938510142721542, 0.0047944880347055461, 0.004295005193187428,
      0.0037954149767631786, 0.0032957298751623656, 0.0027959623804861482,
      0.0022961249868960411, 0.0017962301903010295, 0.0012962904880446362,
      0.00079631837859373434, 0.00029632636122466495, -0.00020367306428782368,
      -0.00070366739798449079, -0.0012036441400328577, -0.0017035907910402358,
      -0.0022034948523667439, -0.0027033438264367085, -0.003203125217051456,
      -0.0037028265297031383, -0.0042024352718840795, -0.0047019389534021,
      -0.0052013250866915321, -0.0057005811871243452, -0.0061996947733243849,
      -0.006698653367478347, -0.0071974444956462991, -0.0076960556880774373,
      -0.0081944744795168552, -0.008692688409521079, -0.0091906850227681646,
      -0.0096884518693680071, -0.010185976505175722, -0.010683246492101679,
      -0.011180249398421225, -0.011676972799088465, -0.012173404276043904,
      -0.012669531418526298, -0.013165341823383274, -0.013660823095380359,
      -0.014155962847511387, -0.01465074870130869, -0.015145168287151343,
      -0.0156392092445758, -0.016132859222583517, -0.016626105879951093,
      -0.017118936885537613, -0.017611339918593427, -0.018103302669068712,
      -0.018594812837920149, -0.019085858137418768, -0.019576426291458525,
      -0.020066505035860254, -0.020556082118681217, -0.02104514530052019,
      -0.0215336823548224, -0.022021681068187287, -0.022509129240672776,
      -0.022996014686098906, -0.023482325232356285, -0.023968048721705545,
      -0.024453173011085096, -0.024937685972413318, -0.02542157549289072,
      -0.025904829475304838, -0.026387435838331631, -0.02686938251683629,
      -0.027350657462177821, -0.027831248642507307, -0.028311144043070103,
      -0.028790331666506533, -0.029268799533150619, -0.029746535681330802,
      -0.03022352816766858, -0.03069976506737597, -0.03117523447455562,
      -0.031649924502497449, -0.032123823283974819, -0.0325969189715432,
      -0.033069199737835044, -0.033540653775856133, -0.034011269299279404,
      -0.0344810345427416, -0.034949937762136458, -0.035417967234907227,
      -0.035885111260341822, -0.03635135815986424, -0.036816696277325305,
      -0.037281113979297634, -0.037744599655361866, -0.038207141718400589,
      -0.038668728604886626, -0.039129348775171206, -0.039588990713774391,
      -0.040047642929671994, -0.040505293956581832, -0.040961932353252406,
      -0.041417546703747588, -0.041872125617732653, -0.04232565773075779,
      -0.042778131704544121, -0.043229536227266191, -0.043679860013833782,
      -0.044129091806176024, -0.044577220373521825, -0.045024234512679694,
      -0.045470123048319752, -0.045914874833252156, -0.046358478748704808,
      -0.046800923704603252, -0.047242198639846932, -0.047682292522584518,
      -0.04812119435049312, -0.048558893151048964, -0.04899537798180513,
      -0.049430637930663907, -0.049864662116148609, -0.050297439687677525,
      -0.050728959825834224, -0.051159211742636782, -0.051588184681810936,
      -0.052015867919054617, -0.052442250762309475, -0.052867322552026953,
      -0.053291072661433826, -0.053713490496799736, -0.054134565497701105,
      -0.054554287137283941, -0.0549726449225303, -0.055389628394516471,
      -0.055805227128677637, -0.056219430735067411, -0.056632228858616608,
      -0.057043611179393917, -0.057453567412863074, -0.05786208731013897,
      -0.058269160658245771, -0.058674777280371251, -0.059078927036120416,
      -0.059481599821770696, -0.059882785570523712, -0.060282474252756069,
      -0.060680655876271833, -0.061077320486551123, -0.061472458166999644,
      -0.0618660590391954, -0.062258113263137363, -0.062648611037490629,
      -0.063037542599830632, -0.063424898226888834, -0.063810668234795018,
      -0.064194842979318253, -0.064577412856111044, -0.064958368300945563,
      -0.06533769978995578, -0.065715397839874554, -0.066091453008269713,
      -0.066465855893781928, -0.066838597136358827, -0.067209667417488225,
      -0.067579057460432676, -0.06794675803046038, -0.068312759935076461,
      -0.068677054024251866, -0.06903963119065358, -0.0694004823698716,
      -0.069759598540644716, -0.070116970725087643, -0.0704725899889146,
      -0.070826447441662041, -0.071178534236912311, -0.071528841572514115,
      -0.07187736069080182, -0.072224082878815862, -0.072568999468519843,
      -0.072912101837016269, -0.073253381406764739, -0.073592829645793084,
      -0.073930438067913246, -0.074266198232932484, -0.074600101746863684,
      -0.07493214026213664, -0.075262305477805991, -0.07559058913975783,
      -0.075916983040918651, -0.076241479021457226, -0.076564068968991164,
      -0.076884744818788819, -0.077203498553970185, -0.07752032220570873,
      -0.077835207853429844, -0.078148147625008116, -0.0784591336969664,
      -0.078768158294668461, -0.079075213692515661, -0.079380292214139253,
      -0.079683386232591663, -0.079984488170538437, -0.080283590500447019,
      -0.0805806857447743, -0.080875766476154867, -0.081168825317586027,
      -0.08145985494261157, -0.081748848075506253, -0.082035797491457008,
      -0.082320696016742953, -0.082603536528916013, -0.08288431195697811,
      -0.0831630152815584, -0.083439639535087817, -0.083714177801974682,
      -0.083986623218776812, -0.084256968974372376, -0.084525208310132341,
      -0.084791334520086734, -0.085055340951094321, -0.085317221003008273,
      -0.08557696812884058, -0.085834575834926791, -0.086090037681087861,
      -0.086343347280790572, -0.0865944983013083, -0.086843484463878629,
      -0.087090299543860633, -0.08733493737088982, -0.087577391829033416,
      -0.087817656856942775, -0.088055726448004384, -0.088291594650491023,
      -0.088525255567710071, -0.08875670335815046, -0.088985932235629631,
      -0.089212936469437759, -0.089437710384480479, -0.089660248361421807,
      -0.089880544836824061, -0.090098594303286358, -0.090314391309584,
      -0.090527930460802639, -0.09073920641847473, -0.090948213900712518,
      -0.091154947682339518, -0.091359402595022121, -0.091561573527398285,
      -0.091761455425204808, -0.0919590432914052, -0.092154332186312721,
      -0.092347317227715275, -0.092537993590997028, -0.092726356509258562,
      -0.092912401273436848, -0.093096123232422612, -0.093277517793176057,
      -0.093456580420843149, -0.0936333066388671, -0.093807692029101816,
      -0.093979732231921742, -0.09414942294633051, -0.094316759930069244,
      -0.094481738999722176, -0.0946443560308209, -0.094804606957948262,
      -0.09496248777483951, -0.095117994534482234, -0.095271123349215669,
      -0.0954218703908275, -0.095570231890649338, -0.09571620413965154,
      -0.095859783488535452, -0.096000966347824956, -0.096139749187955689,
      -0.096276128539364014, -0.096410100992573328, -0.096541663198279073,
      -0.096670811867433093, -0.096797543771325434, -0.096921855741664842,
      -0.0970437446706589, -0.097163207511090477, -0.097280241276394855,
      -0.097394843040734078, -0.097507009939069841, -0.097616739167235608,
      -0.097724027982006467, -0.0978288737011675, -0.097931273703581262,
      -0.098031225429253008, -0.098128726379394876, -0.098223774116488069,
      -0.098316366264344146, -0.098406500508164352, -0.0984941745945971,
      -0.098579386331794888, -0.098662133589468792, -0.098742414298941539,
      -0.098820226453199628, -0.098895568106943332, -0.098968437376635132,
      -0.0990388324405471, -0.099106751538806381, -0.0991721929734389,
      -0.099235155108412409, -0.099295636369676629, -0.099353635245203256,
      -0.099409150285023465, -0.099462180101264064, -0.099512723368182454,
      -0.0995607788221996, -0.0996063452619316, -0.099649421548219944,
      -0.099690006604159609, -0.099728099415126364, -0.09976369902880193,
      -0.099796804555197779, -0.09982741516667748, -0.099855530097977388,
      -0.0998811486462256, -0.099904270170959847, -0.099924894094143138,
      -0.099943019900178509, -0.09995864713592173, -0.099971775410692715,
      -0.099982404396285307, -0.0999905338269754, -0.099996163499527654,
      -0.099999293273200549, -0.0999999230697499, -0.099998052873430832,
      -0.099993682730998165, -0.09998681275170522, -0.099977443107301112,
      -0.0999655740320265, -0.099951205822607608, -0.099934338838248926,
      -0.099914973500624227, -0.0998931102938659, -0.099868749764552969,
      -0.099841892521697451, -0.099812539236728962, -0.099780690643478137,
      -0.099746347538158128, -0.099709510779344757, -0.099670181287955129,
      -0.099628360047224446, -0.099584048102681524, -0.099537246562122747,
      -0.099487956595584126, -0.0994361794353123, -0.0993819163757335,
      -0.099325168773421485, -0.099265938047063323, -0.099204225677424027,
      -0.099140033207309727, -0.0990733622415288, -0.099004214446851813,
      -0.0989325915519702, -0.098858495347452516, -0.098781927685699975,
      -0.098702890480900224, -0.098621385708979215, -0.098537415407551954,
      -0.0984509816758718, -0.098362086674777249, -0.098270732626638935,
      -0.0981769218153032, -0.0980806565860354, -0.097981939345461386,
      -0.097880772561506943, -0.097777158763336355, -0.097671100541289385,
      -0.097562600546815759, -0.097451661492409927, -0.097338286151542386,
      -0.097222477358590673, -0.097104238008768745, -0.096983571058054108,
      -0.096860479523114162, -0.096734966481231116, -0.09660703507022414,
      -0.096476688488372112, -0.0963439299943327, -0.096208762907061235,
      -0.096071190605728066, -0.095931216529633462, -0.095788844178121932,
      -0.095644077110495038, -0.095496918945921841, -0.095347373363348684,
      -0.095195444101407567, -0.095041134958321991, -0.0948844497918124,
      -0.094725392519000029, -0.0945639671163083, -0.094400177619363854,
      -0.094234028122895483, -0.094065522780632183, -0.093894665805198591,
      -0.093721461468010109, -0.09354591409916635, -0.0933680280873423,
      -0.093187807879678869, -0.093005257981672224, -0.0928203829570598,
      -0.092633187427707958, -0.092443676073495074, -0.092251853632194986,
      -0.092057724899359011, -0.091861294728195222, -0.091662568029447528,
      -0.091461549771273326, -0.091258244979118455, -0.091052658735592137,
      -0.09084479618033961, -0.090634662509914213, -0.09042226297764662,
      -0.090207602893513927, -0.089990687624007359, -0.089771522591997208,
      -0.089550113276597676, -0.089326465213030462, -0.089100583992485341,
      -0.0888724752619809, -0.08864214472422384, -0.088409598137465448,
      -0.088174841315358118, -0.087937880126810669, -0.087698720495839821,
      -0.087457368401424374, -0.08721382987735396, -0.086968111012078825,
      -0.086720217948558137, -0.08647015688410542, -0.086217934070234079,
      -0.085963555812501841, -0.085707028470351207, -0.08544835845695288,
      -0.085187552239043576, -0.084924616336764958, -0.084659557323501264,
      -0.084392381825713833, -0.084123096522776, -0.083851708146806869,
      -0.083578223482500977, -0.083302649366961246, -0.083024992689526012,
      -0.082745260391597547, -0.082463459466469144, -0.082179596959149045,
      -0.081893679966184948, -0.0816057156354872, -0.081315711166148857,
      -0.081023673808266333, -0.0807296108627588, -0.080433529681184363,
      -0.080135437665556919, -0.079835342268161774, -0.079533250991368015,
      -0.079229171387441816, -0.078923111058357226, -0.078615077655606991,
      -0.078305078880009871, -0.077993122481518934, -0.077679216259028322,
      -0.077363368060177018, -0.077045585781153544, -0.07672587736649833,
      -0.076404250808904867, -0.076080714149020789, -0.07575527547524552,
      -0.075427942923528724, -0.075098724677167619, -0.074767628966600955,
      -0.074434664069204279, -0.074099838309082441, -0.073763160056862481,
      -0.073424637729482919, -0.07308427978998408, -0.07274209474729719,
      -0.072398091156030284, -0.072052277616254948, -0.071704662773292169,
      -0.07135525531749469, -0.071004063984030447, -0.070651097552664952,
      -0.0702963648475404, -0.069939874736955662, -0.0695816361331457,
      -0.069221657992055971, -0.068859949313121963, -0.06849651913904159,
      -0.06813137655555, -0.0677645306911933, -0.0673959907170987,
      -0.067025765846746119, -0.066653865335738832, -0.066280298481569175,
      -0.065905074623389834, -0.065528203141777458, -0.065149693458499192,
      -0.064769555036277945, -0.0643877973785542, -0.064004430029249257,
      -0.0636194625725277, -0.063232904632554765, -0.0628447658732597,
      -0.062455055998090939, -0.062063784749774822, -0.061670961910072722,
      -0.0612765972995349, -0.060880700777255804, -0.060483282240628412,
      -0.060084351625095178, -0.059683918903900429, -0.0592819940878419,
      -0.058878587225018764, -0.058473708400581317, -0.05806736773647965,
      -0.057659575391208896, -0.057250341559556474, -0.056839676472346556,
      -0.056427590396185529, -0.056014093633203511, -0.055599196520797783,
      -0.055182909431375105, -0.054765242772090765, -0.054346206984589175,
      -0.053925812544744094, -0.05350406996239343, -0.053080989781080667,
      -0.052656582577788026, -0.052230858962673155, -0.051803829578804875,
      -0.051375505101895237, -0.050945896240033567, -0.050515013733419614,
      -0.050082868354093327, -0.049649470905666654, -0.049214832223052951,
      -0.048778963172197244, -0.0483418746498028, -0.04790357758305961,
      -0.047464082929372133, -0.0470234016760835, -0.046581544840201793,
      -0.046138523468125504, -0.045694348635365561, -0.045249031446269336,
      -0.044802583033743987, -0.044355014558976259, -0.043906337211154389,
      -0.043456562207189679, -0.0430057007914325, -0.042553764235395732,
      -0.042100763837469427, -0.041646710922639607, -0.041191616842206132,
      -0.04073549297349701, -0.040278350719584854, -0.039820201509003193,
      -0.039361056795457122, -0.038900928057541549, -0.038439826798450621,
      -0.037977764545691475, -0.037514752850797028, -0.0370508032890352,
      -0.036585927459120537, -0.036120136982925578, -0.035653443505186642,
      -0.035185858693217352, -0.034717394236613332, -0.034248061846961254,
      -0.033777873257547095, -0.033306840223060755, -0.032834974519303235,
      -0.032362287942893218, -0.031888792310970165, -0.031414499460899879,
      -0.030939421249979573, -0.030463569555139444, -0.029986956272646737,
      -0.02950959331780938, -0.029031492624676032, -0.02855266614573912,
      -0.028073125851635346, -0.027592883730847763, -0.027111951789404034,
      -0.026630342050577308, -0.026148066554586652, -0.02566513735829401,
      -0.025181566534903794, -0.024697366173662434, -0.024212548379552362,
      -0.023727125272994216, -0.02324110898954003, -0.022754511679571238,
      -0.022267345507995927, -0.021779622653942676, -0.021291355310457429,
      -0.020802555684197997, -0.020313235995130276, -0.019823408476220654,
      -0.019333085373131248, -0.018842278943914791, -0.018351001458706103,
      -0.017859265199416382, -0.017367082459427193, -0.016874465543281057,
      -0.01638142676637486, -0.015887978454653059, -0.015394132944297385,
      -0.01489990258141953, -0.014405299721753879, -0.013910336730344756,
      -0.013415025981242223, -0.01291937985718886, -0.012423410749311595,
      -0.011927131056813003, -0.011430553186659196, -0.01093368955327071,
      -0.01043655257821356, -0.0099391546898848181, -0.0094415083232068479,
      -0.0089436259193125412, -0.0084455199252357113, -0.0079472027936009753,
      -0.0074486869823103159, -0.0069499849542326957, -0.0064511091768939075,
      -0.0059520721221609819, -0.0054528862659353619, -0.0049535640878370967,
      -0.0044541180708942791, -0.0039545607012320292, -0.0034549044677582154,
      -0.0029551618618522944, -0.0024553453770540974, -0.0019554675087493562,
      -0.0014555407538583886, -0.00095557761052473883, -0.00045559057780059564,
      4.4407844664619136E-5, 0.00054440515693567493, 0.0010443888591061619,
      0.0015443464516095662, 0.0020442654355324703, 0.0025441333129256026,
      0.003043937587118419, 0.003543665763030451, 0.0040433053474826178,
      0.0045428438495116854, 0.0050422687806814769, 0.00554156765539366,
      0.006040727991203791, 0.0065397373091284072, 0.0070385831339609076,
      0.0075372529945820057, 0.0080357344242704479, 0.0085340149610168125,
      0.0090320821478339849, 0.00952992353306753, 0.010027526670709096,
      0.010524879120706161, 0.011021968449273733, 0.011518782229203779,
      0.012015308040178032, 0.01251153346907743, 0.013007446110291391,
      0.013503033566030062, 0.01399828344663322, 0.014493183370878938,
      0.014987720966295234, 0.015481883869468333, 0.015975659726350695,
      0.016469036192571961, 0.016962000933746526, 0.017454541625780483,
      0.017946645955183582, 0.018438301619372179, 0.018929496326980613,
      0.019420217798167133, 0.019910453764919823, 0.020400191971365389,
      0.020889420174074528, 0.021378126142366612, 0.021866297658619274,
      0.022353922518568988, 0.022840988531620005, 0.023327483521147715,
      0.02381339532480202, 0.024298711794813486, 0.024783420798295985,
      0.025267510217548635, 0.025750967950362552, 0.026233781910318561,
      0.026715940027093155, 0.027197430246758872, 0.027678240532084605,
      0.028158358862838608, 0.02863777323608796, 0.029116471666497626,
      0.029594442186632104, 0.030071672847253636, 0.030548151717619876,
      0.031023866885784224, 0.031498806458892595, 0.031972958563479717,
      0.032446311345768, 0.032918852971962557, 0.033390571628547673,
      0.033861455522580831, 0.034331492881989542, 0.034800671955864629,
      0.035268981014753023, 0.035736408350952972, 0.036202942278805744,
      0.036668571134986457, 0.037133283278799278, 0.037597067092463826,
      0.038059910981409234, 0.038521803374562721, 0.038982732724637863,
      0.03944268750842523, 0.039901656227079196, 0.040359627406406022,
      0.040816589597149427, 0.041272531375278754, 0.041727441342273644,
      0.042181308125407956, 0.042634120378036072, 0.043085866779875581,
      0.043536536037289325, 0.043986116883569661, 0.044434598079219179,
      0.044881968412230688, 0.0453282166983695, 0.045773331781452,
      0.046217302533623369, 0.046660117855639172, 0.04710176667713848,
      0.047542237956924083, 0.047981520683237223, 0.048419603874032012,
      0.0488564765772518, 0.049292127871102071, 0.049726546864322242,
      0.050159722696461351, 0.050591644538145221, 0.051022301591350606,
      0.05145168308967394, 0.051879778298599494, 0.052306576515769643,
      0.052732067071251512, 0.053156239327802446, 0.053579082681139346,
      0.054000586560199487, 0.05442074042740816, 0.054839533778940845,
      0.055256956144984985, 0.055672997090003479, 0.056087646212994627,
      0.0565008931477514, 0.056912727563122226, 0.057323139163268477,
      0.057732117687920928, 0.058139652912638055, 0.058545734649060766,
      0.058950352745166218, 0.059353497085523357, 0.0597551575915447,
      0.060155324221738776, 0.060553986971960107, 0.060951135875660992,
      0.061346761004139806, 0.061740852466788378, 0.062133400411340946,
      0.062524395024119619, 0.0629138265302786, 0.063301685194051646,
      0.063687961318991543, 0.064072645248215529, 0.064455727364645693,
      0.064837198091248535, 0.065217047891276025, 0.065595267268503232,
      0.06597184676746487, 0.066346776973693358, 0.066720048513953065,
      0.067091652056475187, 0.067461578311189971, 0.067829818029960617,
      0.06819636200681356, 0.068561201078167974, 0.068924326123066315,
      0.06928572806340165, 0.069645397864143768, 0.070003326533566654,
      0.070359505123472443, 0.070713924729414457, 0.071066576490921241,
      0.0714174515917174, 0.0717665412599429, 0.072113836768375267,
      0.072459329434644074, 0.072803010621450948, 0.073144871736784342,
      0.073484904234133716, 0.073823099612704557, 0.07415944941763028,
      0.074493945240182546, 0.074826578717984177, 0.075157341535214833,
      0.07548622542282156, 0.0758132221587245, 0.07613832356802186,
      0.076461521523195547, 0.076782807944313747, 0.077102174799232,
      0.077419614103796441, 0.077735117922040353, 0.0780486783663849,
      0.078360287597835532, 0.078669937826177275, 0.078977621310170748,
      0.0792833303577451, 0.079587057326189634, 0.07988879462234616,
      0.080188534702798214, 0.080486270074058966, 0.080781993292759868,
      0.081075696965836039, 0.081367373750710542, 0.081657016355479173,
      0.081944617539091866, 0.082230170111534245, 0.082513666934006441,
      0.082795100919102874, 0.083074465030988767, 0.083351752285575481,
      0.0836269557506963, 0.0839000685462791, 0.084171083844517658,
      0.084439994870044388, 0.084706794900097082, 0.0849714772646891,
      0.085234035346775261, 0.085494462582416844, 0.085752752460946713,
      0.086008898525131328, 0.086262894371332624, 0.086514733649667316,
      0.086764410064166742, 0.08701191737293372, 0.087257249388298042,
      0.087500399976972329, 0.08774136306020465, 0.087980132613930173,
      0.088216702668922634, 0.088451067310943154, 0.088683220680887562,
      0.088913156974933849, 0.089140870444686826, 0.089366355397321115,
      0.089589606195725285, 0.089810617258640521, 0.090029383060801924,
      0.090245898133075986, 0.090460157062596872, 0.090672154492902654,
      0.090881885124068765, 0.091089343712839915, 0.091294525072762769,
      0.091497424074313716, 0.091698035645028014, 0.0918963547696274,
      0.092092376490143527, 0.092286095906044155, 0.0924775081743537,
      0.09266660850977515, 0.0928533921848105, 0.09303785452987734,
      0.09321999093342638, 0.093399796842057556, 0.093577267760632243,
      0.093752399252386487, 0.093925186939042588, 0.094095626500917032,
      0.094263713677029765, 0.094429444265210258, 0.094592814122202176,
      0.094753819163767766, 0.094912455364789358, 0.095068718759370285,
      0.0952226054409336, 0.09537411156232041, 0.095523233335885666,
      0.095669967033592582, 0.095814308987106467, 0.095956255587886091,
      0.096095803287273643, 0.096232948596583989, 0.09636768808719165,
      0.0965000183906161, 0.096629936198607, 0.096757438263225748,
      0.096882521396927171, 0.097005182472639812, 0.0971254184238429,
      0.097243226244643988, 0.097358602989853812, 0.097471545775059565,
      0.097582051776697556, 0.097690118232123632, 0.097795742439681824,
      0.097898921758772572, 0.097999653609918233, 0.098097935474827869,
      0.098193764896459812, 0.098287139479083616, 0.098378056888339616,
      0.098466514851297149, 0.098552511156511979, 0.09863604365408081,
      0.098717110255695489, 0.0987957089346954, 0.098871837726117531,
      0.098945494726745978, 0.09901667809515978, 0.0990853860517783,
      0.09915161687890614, 0.099215368920776231, 0.099276640583590675,
      0.099335430335561276, 0.0993917367069472, 0.099445558290092023,
      0.099496893739459122, 0.0995457417716648, 0.0995921011655109,
      0.099635970762014955, 0.099677349464439277, 0.099716236238318559,
      0.099752630111485441, 0.099786530174094917, 0.099817935578647321,
      0.099846845540009083, 0.099873259335432674, 0.09989717630457462,
      0.099918595849511932, 0.0999375174347571, 0.099953940587271459,
      0.099967864896477077, 0.099979290014266919, 0.099988215655013674,
      0.099994641595576764, 0.099998567675308014, 0.099999993796055633,
      0.0999989199221667, 0.099995346080487962, 0.099989272360365311,
      0.0999806989136414, 0.099969625954651989, 0.099956053760220459,
      0.099939982669650956, 0.09992141308471994, 0.099900345469666,
      0.099876780351178474, 0.0998507183183841, 0.0998221600228323,
      0.099791106178479, 0.099757557561668708, 0.099721515011115036,
      0.099682979427879931, 0.099641951775350956, 0.099598433079217244,
      0.099552424427444, 0.099503926970245085, 0.099452941920054369,
      0.09939947055149552, 0.099343514201349958, 0.099285074268523482,
      0.099224152214011346, 0.099160749560861822, 0.099094867894137892,
      0.099026508860877757, 0.098955674170053812, 0.09888236559252947,
      0.098806584961015409, 0.098728334170023635, 0.098647615175819561,
      0.098564429996374, 0.098478780711312219, 0.098390669461861618,
      0.09830009845079897, 0.098207069942394989, 0.098111586262357275,
      0.098013649797773092, 0.097913262997048708, 0.097810428369849045,
      0.097705148487034557, 0.097597425980596564, 0.097487263543592384,
      0.097374663930076932, 0.097259629955034829, 0.09714216449430961,
      0.097022270484531339, 0.0968999509230442, 0.096775208867831031,
      0.096648047437436352, 0.096518469810889476, 0.096386479227624527,
      0.09625207898739882, 0.096115272450211661, 0.095976063036219236,
      0.095834454225649554, 0.0956904495587157, 0.095544052635526761,
      0.095395267115998175, 0.095244096719760085, 0.095090545226064749,
      0.094934616473691377, 0.094776314360850544, 0.094615642845087083,
      0.09445260594318039, 0.09428720773104439, 0.094119452343626037,
      0.093949343974801133, 0.093776886877269927, 0.093602085362451251,
      0.093424943800373361, 0.093245466619566342, 0.093063658306950625,
      0.092879523407724041, 0.092693066525249862, 0.092504292320940318,
      0.092313205514140531, 0.092119810882011, 0.091924113259407331,
      0.091726117538759755, 0.091525828669951237, 0.091323251660192936,
      0.091118391573899546, 0.090911253532562408, 0.090701842714622061,
      0.09049016435533791, 0.090276223746657724, 0.090060026237086088,
      0.089841577231548828, 0.089620882191260021, 0.0893979466335845,
      0.089172776131898959, 0.08894537631545453, 0.088715752869235109,
      0.088483911533814241, 0.088249858105213561, 0.088013598434756923,
      0.087775138428923122, 0.087534484049200556, 0.0872916413119355,
      0.087046616288184081, 0.086799415103559485, 0.086550043938077734,
      0.086298509026005707, 0.086044816655702377, 0.085788973169464156,
      0.085530984963365239, 0.08527085848709659, 0.085008600243806964,
      0.084744216789939153, 0.084477714735064949, 0.084209100741722262,
      0.0839383815252473, 0.083665563853605615, 0.083390654547225343,
      0.083113660478824666, 0.08283458857324065, 0.082553445807256792,
      0.082270239209427415, 0.08198497585990272, 0.081697662890251349,
      0.081408307483283024, 0.081116916872867609, 0.080823498343755018,
      0.0805280592313936, 0.080230606921745551, 0.079931148851102918,
      0.079629692505902308, 0.079326245422536426, 0.079020815187166332,
      0.078713409435532664, 0.07840403585276233, 0.078092702173179207,
      0.077779416180109515, 0.07746418570568589, 0.077147018630654429,
      0.076827922884175281, 0.076506906443625261, 0.076183977334399092,
      0.075859143629707484, 0.0755324134503759, 0.075203794964642245,
      0.074873296387951357, 0.074540925982750181, 0.074206692058282,
      0.073870602970377286, 0.073532667121245759, 0.073192892959265773,
      0.072851288978774159, 0.072507863719852433, 0.0721626257681139,
      0.071815583754490125, 0.071466746355012378, 0.071116122290598,
      0.0707637203268308, 0.070409549273740546, 0.070053617985585612,
      0.069695935360630151, 0.069336510340920171, 0.068975351912062929,
      0.068612469103000881, 0.06824787098578429, 0.067881566675348157,
      0.0675135653292801, 0.06714387614759515, 0.066772508372504119,
      0.066399471288180967, 0.066024774220534446, 0.065648426536970672,
      0.065270437646162652, 0.064890816997813516, 0.064509574082418628,
      0.064126718431031543, 0.063742259615024152, 0.063356207245845772,
      0.062968570974786017, 0.062579360492732064, 0.062188585529924581,
      0.061796255855718109, 0.0614023812783338, 0.061006971644615285,
      0.060610036839783388, 0.060211586787187257, 0.05981163144805747,
      0.059410180821256389, 0.059007244943029329, 0.058602833886752,
      0.058196957762679427, 0.057789626717694165, 0.057380850935050846,
      0.056970640634122431, 0.056559006070145683, 0.056145957533962954,
      0.055731505351765846, 0.05531565988483822, 0.054898431529293905,
      0.054479830715820646, 0.054059867909417574, 0.053638553609131778,
      0.053215898347799745, 0.052791912691780657, 0.052366607240693558,
      0.051939992627153167, 0.0515120795165023, 0.051082878606546138,
      0.050652400627285689, 0.050220656340647686, 0.049787656540216531,
      0.049353412050965273, 0.048917933728983239, 0.048481232461205781,
      0.048043319165141547, 0.047604204788601057, 0.047163900309419617,
      0.046722416735186893, 0.046279765102969869, 0.045835956479035045,
      0.045391001958575532, 0.0449449126654318, 0.044497699751811677,
      0.044049374398015345, 0.043599947812153941, 0.043149431229867419,
      0.04269783591404816, 0.042245173154554248, 0.041791454267931738,
      0.041336690597129813, 0.040880893511215266, 0.0404240744050928,
      0.039966244699214969, 0.03950741583930123, 0.03904759929604984,
      0.038586806564849127, 0.038125049165494015, 0.037662338641896109,
      0.037198686561793065, 0.03673410451646341, 0.036268604120434741,
      0.035802197011191382, 0.035334894848887771, 0.0348667093160533,
      0.034397652117301565, 0.033927734979038775, 0.033456969649168576,
      0.0329853678967997, 0.032512941511951048, 0.032039702305258315,
      0.031565662107676688, 0.03109083277018608, 0.030615226163495858,
      0.030138854177746095, 0.029661728722211279, 0.029183861725003632,
      0.028705265132772845, 0.028225950910408467, 0.027745931040742106,
      0.027265217524244153, 0.026783822378728145, 0.026301757639048351,
      0.025819035356796773, 0.025335667600006356, 0.024851666452845513,
      0.024367044015317352, 0.023881812402958277, 0.023395983746532966,
      0.022909570191732186, 0.022422583898870165, 0.021935037042578515,
      0.0214469418115029, 0.020958310407999375, 0.020469155047827224,
      0.019979487959844982, 0.01948932138570399, 0.018998667579543774,
      0.018507538807683584, 0.018015947348316783, 0.0175239054912053,
      0.017031425537368548, 0.016538519798780411, 0.016045200598059386,
      0.015551480268158394, 0.01505737115206067, 0.014562885602469086,
      0.01406803598149522, 0.013572834660354525, 0.013077294019054941,
      0.01258142644608529, 0.01208524433811047, 0.011588760099655933,
      0.011091986142802483, 0.01059493488687388, 0.010097618758124215,
      0.0096000501894322222, 0.009102241619984788, 0.008604205494970929,
      0.0081059542652685383, 0.0076075003871309936, 0.0071088563218799933,
      0.0066100345355919084, 0.0061110474987839964, 0.005611907686106898,
      0.0051126275760306431, 0.0046132196505305608, 0.0041136963947798408,
      0.003614070296833507, 0.00311435384731763, 0.002614559539118131,
      0.0021146998670663283, 0.00161478732762799, 0.0011148344185902088,
      0.00061485363875038261, 0.00011485748760161118, -0.00038514153497872335,
      -0.00088513092904038762, -0.0013850981948749265, -0.001885030833327089,
      -0.0023849163461062417, -0.0028847422361009565, -0.00338449600769037,
      -0.0038841651670551572, -0.0043837372224937781, -0.0048831996847301566,
      -0.00538254006722804, -0.0058817458865052926, -0.0063808046624413686,
      -0.0068797039185932163, -0.0073784311825057713, -0.0078769739860227016,
      -0.0083753198656002417, -0.00887345636261771, -0.0093713710236879161,
      -0.0098690514009706232, -0.010366485052482673, -0.010863659542407977,
      -0.011360562441410536, -0.011857181326943755, -0.012353503783561714,
      -0.012849517403227789, -0.013345209785628734, -0.013840568538480104,
      -0.014335581277838167, -0.014830235628411632, -0.015324519223866793,
      -0.01581841970713881, -0.016311924730742722, -0.016805021957077945,
      -0.0172976990587388, -0.017789943718824811, -0.01828174363124371,
      -0.018773086501024702, -0.019263960044620929, -0.019754351990218674,
      -0.020244250078046231, -0.020733642060675531, -0.021222515703333885,
      -0.021710858784204992, -0.022198659094736575, -0.022685904439947661,
      -0.023172582638729303, -0.023658681524151192, -0.024144188943767891,
      -0.0246290927599185, -0.025113380850032192, -0.025597041106933307,
      -0.02608006143913958, -0.026562429771168211, -0.027044134043836366,
      -0.027525162214561628, -0.028005502257665127, -0.02848514216467081,
      -0.028964069944606308, -0.029442273624301397, -0.029919741248689333,
      -0.030396460881104703, -0.03087242060358086, -0.031347608517149864,
      -0.031822012742138965, -0.032295621418466564, -0.032768422705940763,
      -0.033240404784554346, -0.033711555854778912, -0.034181864137863581,
      -0.034651317876125104, -0.035119905333243821, -0.035587614794559033,
      -0.036054434567357567, -0.036520352981169742, -0.036985358388059823,
      -0.0374494391629162, -0.037912583703743986, -0.038374780431954122,
      -0.038836017792651813, -0.0392962842549274, -0.039755568312143615,
      -0.040213858482222309, -0.040671143307933408, -0.0411274113571801,
      -0.041582651223285243, -0.042036851525275233, -0.042490000908166514,
      -0.042942088043248422, -0.043393101628365183, -0.043843030388201927,
      -0.044291863074562454, -0.044739588466652352, -0.0451861953713614,
      -0.045631672623539607, -0.046076009086278236, -0.046519193651190144,
      -0.046961215238683629, -0.047402062798241426, -0.047841725308698742,
      -0.048280191778514475, -0.048717451246050952, -0.049153492779843655,
      -0.049588305478876306, -0.05002187847285533, -0.050454200922477224,
      -0.050885262019704482, -0.051315050988031533, -0.051743557082755923,
      -0.052170769591248826, -0.052596677833219169, -0.053021271160982486,
      -0.053444538959728907, -0.053866470647784909, -0.054287055676879636,
      -0.054706283532410506, -0.055124143733702051, -0.0555406258342713,
      -0.055955719422087727, -0.056369414119832664, -0.056781699585160508,
      -0.0571925655109561, -0.05760200162559298, -0.058009997693189042,
      -0.058416543513864119, -0.058821628923994174, -0.059225243796464461,
      -0.059627378040924474, -0.06002802160403934, -0.06042716446974,
      -0.060824796659476738, -0.061220908232464927, -0.061615489285935333,
      -0.062008529955383286, -0.062400020414811963, -0.062789950876979722,
      -0.063178311593646411, -0.063565092855813507, -0.063950284993969916,
      -0.064333878378332474, -0.064715863419086014, -0.0650962305666247,
      -0.0654749703117899, -0.06585207318610721, -0.066227529762024645,
      -0.066601330653147384, -0.066973466514472876, -0.067343928042623444,
      -0.067712705976080437, -0.068079791095414982, -0.0684451742235177,
      -0.0688088462258297, -0.069170798010570078, -0.069531020528962345,
      -0.069889504775463282, -0.070246241787984928, -0.070601222648120007,
      -0.070954438481366539, -0.071305880457346579, -0.071655539790028519,
      -0.072003407737948263, -0.072349475604424257, -0.07269373473777882,
      -0.073036176531551061, -0.0733767924247135, -0.0737155739018875,
      -0.07405251249355331, -0.0743875997762632, -0.074720827372853516,
      -0.075052186952650743, -0.075381670231683587, -0.075709268972886767,
      -0.076034974986308332, -0.076358780129315865, -0.076680676306797188,
      -0.077000655471364143, -0.077318709623555248, -0.077634830812032526,
      -0.077949011133783, -0.078261242734315173, -0.078571517807854874,
      -0.078879828597541654, -0.079186167395622023, -0.079490526543641568,
      -0.079792898432637649, -0.080093275503328787, -0.080391650246304069,
      -0.080688015202210056, -0.080982362961938489, -0.081274686166810883,
      -0.081564977508761974, -0.081853229730523516, -0.0821394356258052,
      -0.0824235880394739, -0.082705679867734916, -0.082985704058306825,
      -0.08326365361059905, -0.083539521575888051, -0.083813301057488465,
      -0.084084985210927721, -0.0843545672441163, -0.084622040417517072,
      -0.084887398044314791, -0.0851506334905828, -0.085411740175448281,
      -0.085670711571257913, -0.085927541203740465, -0.086182222652168114,
      -0.086434749549518117, -0.086685115582631186, -0.086933314492369712,
      -0.087179340073773537, -0.087423186176216083, -0.0876648467035577,
      -0.087904315614297263, -0.088141586921725149, -0.088376654694070689,
      -0.0886095130546515, -0.088840156182021346, -0.089068578310113722,
      -0.089294773728387011, -0.089518736781968186, -0.089740461871792243,
      -0.089959943454743146, -0.090177176043793425, -0.090392154208139008,
      -0.09060487257333763, -0.090815325821440918, -0.09102350869112831,
      -0.09122941597783954, -0.091433042533902553, -0.09163438326866466,
      -0.091833433148617652, -0.092030187197524649, -0.0922246404965452,
      -0.092416788184356724, -0.092606625457276714, -0.092794147569383811,
      -0.0929793498326347, -0.093162227616982174, -0.09334277635049168,
      -0.0935209915194539, -0.093696868668499009, -0.093870403400707569,
      -0.094041591377720071, -0.094210428319846121, -0.094376910006170975,
      -0.094541032274661249, -0.094702791022268543, -0.094862182205032716,
      -0.095019201838182618, -0.095173845996235351, -0.095326110813095166,
      -0.095475992482149635, -0.095623487256364548, -0.095768591448378668,
      -0.0959113014305945, -0.096051613635269747, -0.096189524554607,
      -0.096325030740840242, -0.096458128806321708, -0.096588815423607047,
      -0.096717087325537368, -0.096842941305321908, -0.0969663742166178,
      -0.097087382973608513, -0.09720596455108152, -0.097322115984503632,
      -0.097435834370094912, -0.097547116864901709, -0.09765596068686748,
      -0.097762363114902384, -0.097866321488951122, -0.097967833210059849,
      -0.098066895740440863, -0.098163506603535955, -0.098257663384078653,
      -0.098349363728154379, -0.098438605343259128, -0.098525385998357431,
      -0.0986097035239373, -0.098691555812064888, -0.098770940816437447,
      -0.098847856552433916, -0.0989223010971648, -0.098994272589520538,
      -0.0990637692302174, -0.099130789281843171, -0.099195331068899939,
      -0.099257392977846332, -0.099316973457138011, -0.099374071017266016,
      -0.099428684230794234, -0.099480811732395327, -0.099530452218884347,
      -0.099577604449251816, -0.09962226724469439, -0.099664439488644452,
      -0.09970412012679819, -0.099741308167141676, -0.0997760026799758,
      -0.09980820279793963, -0.099837907716031835, -0.099865116691631,
      -0.099889829044514239, -0.099912044156873908, -0.099931761473333422,
      -0.099948980500960877, -0.099963700809281464, -0.099975922030288267,
      -0.099985643858451378, -0.099992866050725632, -0.099997588426556566,
      -0.099999810867885036, -0.099999533319150125, -0.099996755787290545,
      -0.099991478341744433, -0.099983701114447668, -0.099973424299830527,
      -0.099960648154812828, -0.099945372998797535, -0.099927599213662788,
      -0.099907327243752231, -0.099884557595864079, -0.099859290839238349,
      -0.099831527605542633, -0.099801268588856351, -0.099768514545653331,
      -0.099733266294782907, -0.09969552471744958, -0.099655290757190776,
      -0.0996125654198534, -0.0995673497735687, -0.099519644948725464,
      -0.099469452137941824, -0.099416772596035388, -0.099361607639992036,
      -0.09930395864893278, -0.099243827064079318, -0.0991812143887183,
      -0.099116122188163153, -0.0990485520897156, -0.098978505782624682,
      -0.0989059850180442, -0.09883099160898963, -0.098753527430292393,
      -0.098673594418552682, -0.098591194572091756, -0.0985063299509016,
      -0.098419002676593093, -0.09832921493234377, -0.098236968962842341,
      -0.098142267074233319, -0.098045111634059157, -0.09794550507120052,
      -0.097843449875816571, -0.097738948599281589, -0.097632003854122185,
      -0.097522618313951592, -0.097410794713402277, -0.0972965358480586,
      -0.097179844574386415, -0.097060723809661145, -0.096939176531895974,
      -0.0968152057797664, -0.0966888146525347, -0.096560006309972662,
      -0.096428783972282037, -0.096295150920014339, -0.096159110493989078,
      -0.096020666095209775, -0.095879821184779168, -0.095736579283812559,
      -0.095590943973350245, -0.095442918894267287, -0.095292507747182842,
      -0.095139714292367977, -0.09498454234965098, -0.094826995798322267,
      -0.0946670785770377, -0.094504794683719057, -0.094340148175455441,
      -0.09417314316840121, -0.094003783837672383, -0.093832074417243644,
      -0.0936580191998418, -0.093481622536837741, -0.0933028888381392,
      -0.093121822572079238, -0.092938428265304934, -0.092752710502664662,
      -0.0925646739270927, -0.092374323239493489, -0.092181663198624586,
      -0.091986698620976845, -0.091789434380654553, -0.091589875409253285,
      -0.091388026695737257, -0.0911838932863136, -0.0909774802843068,
      -0.090768792850031449, -0.090557836200662378, -0.0903446156101047,
      -0.090129136408862526, -0.089911403983904029, -0.089691423778528831,
      -0.0894692012922309, -0.0892447420805602, -0.08901805175498563,
      -0.088789135982753883, -0.088558000486746655, -0.088324651045339986,
      -0.08808909349225709, -0.087851333716424854, -0.08761137766182564,
      -0.087369231327347627, -0.0871249007666369, -0.086878392087945122,
      -0.086629711453975689, -0.086378865081732231, -0.08612585924236027,
      -0.085870700260992958, -0.085613394516591917, -0.08535394844178662,
      -0.085092368522715789, -0.084828661298864169, -0.084562833362897841,
      -0.084294891360501945, -0.0840248419902124, -0.0837526920032492,
      -0.08347844820334821, -0.08320211744659, -0.082923706641228834,
      -0.082643222747520784, -0.082360672777548383, -0.082076063795046159,
      -0.081789402915223644, -0.08150069730458831, -0.0812099541807652,
      -0.080917180812317024, -0.0806223845185632, -0.080325572669395481,
      -0.080026752685094446, -0.079725932036144753, -0.079423118243046126,
      -0.079118318876128024, -0.078811541555359216, -0.078502793950155858,
      -0.0781920837791924, -0.077879418810207421, -0.077564806859807961,
      -0.077248255793277057, -0.076929773524374662, -0.076609368015140678,
      -0.076287047275696629, -0.075962819364043976, -0.075636692385863361,
      -0.075308674494312736, -0.07497877388982209, -0.074646998819889343,
      -0.074313357578873723, -0.073977858507789346, -0.073640509994095285,
      -0.073301320471486561, -0.072960298419684336, -0.072617452364221124,
      -0.072272790876230966, -0.071926322572233609, -0.0715780561139176,
      -0.071228000207926773, -0.070876163605641015, -0.0705225551029561,
      -0.070167183540066652, -0.069810057801243733, -0.069451186814611224,
      -0.0690905795519261, -0.068728245028350149, -0.068364192302228052,
      -0.067998430474859581, -0.067630968690270285, -0.0672618161349867,
      -0.066890982037802429, -0.066518475669551116, -0.066144306342873091,
      -0.06576848341198098, -0.06539101627242902, -0.065011914360876541,
      -0.064631187154850556, -0.064248844172512171, -0.063864894972415764,
      -0.063479349153271067, -0.063092216353704017, -0.0627035062520142,
      -0.062313228565933576, -0.061921393052384567, -0.061528009507234332,
      -0.06113308776505099, -0.06073663769885726, -0.060338669219884691,
      -0.059939192277324277, -0.059538216858078467, -0.059135752986512441,
      -0.058731810724201729, -0.058326400169681582, -0.057919531458195589,
      -0.057511214761439215, -0.057101460287309162, -0.056690278279646546,
      -0.056277679017978977, -0.05586367281726709, -0.055448270027644908,
      -0.055031481034159384, -0.054613316256514513, -0.054193786148807682,
      -0.053772901199269411, -0.05335067193000214, -0.052927108896715286,
      -0.05250222268846233, -0.052076023927376959, -0.0516485232684057,
      -0.051219731399042748, -0.050789659039062213, -0.050358316940251294,
      -0.0499257158861397, -0.049491866691730939, -0.04905678020323289,
      -0.0486204672977848, -0.048182938883186269, -0.047744205897625805,
      -0.047304279309403952, -0.046863170116663133, -0.046420889347110805,
      -0.045977448057741926, -0.045532857334566253, -0.045087128292329359,
      -0.0446402720742328, -0.044192299851660038, -0.043743222823892036,
      -0.043293052217831716, -0.042841799287721444, -0.042389475314859676,
      -0.041936091607322812, -0.041481659499680586, -0.041026190352710719,
      -0.04056969555311947, -0.040112186513251741, -0.039653674670810352,
      -0.039194171488568144, -0.038733688454079429, -0.03827223707939674,
      -0.037809828900781065, -0.037346475478411474, -0.036882188396100378,
      -0.036416979261000328, -0.035950859703315137, -0.035483841376010128,
      -0.035015935954518844, -0.0345471551364521, -0.034077510641306617,
      -0.033607014210169962, -0.033135677605428425, -0.032663512610472227,
      -0.032190531029402322, -0.031716744686733273, -0.031242165427098637,
      -0.030766805114955848, -0.030290675634287629, -0.02981378888830585,
      -0.029336156799155341, -0.028857791307612093, -0.028378704372789165,
      -0.027898907971835658, -0.027418414099635243, -0.026937234768510371,
      -0.026455382007919956, -0.025972867864156535, -0.025489704400049613,
      -0.02500590369466027, -0.024521477842980612, -0.024036438955632379,
      -0.023550799158562154, -0.023064570592739225, -0.022577765413853097,
      -0.022090395792007552, -0.021602473911417744, -0.021114011970104932,
      -0.020625022179592903, -0.0201355167646006, -0.019645507962737563,
      -0.019155008024199005, -0.0186640292114575, -0.018172583798957441,
      -0.017680684072809594, -0.017188342330480097, -0.016695570880487565,
      -0.016202382042093282, -0.015708788144991118, -0.015214801529003492,
      -0.014720434543770783, -0.014225699548440466, -0.01373060891136306,
      -0.013235175009777304 } ;

    bodeTestRunner_DW.FromWorkspace2_PWORK.TimePtr = (void *) pTimeValues0;
    bodeTestRunner_DW.FromWorkspace2_PWORK.DataPtr = (void *) pDataValues0;
    bodeTestRunner_DW.FromWorkspace2_IWORK.PrevIndex = 0;
  }

  /* InitializeConditions for DiscreteIntegrator: '<Root>/Discrete-Time Integrator' */
  bodeTestRunner_DW.DiscreteTimeIntegrator_DSTATE =
    bodeTestRunner_P.DiscreteTimeIntegrator_IC;

  /* InitializeConditions for UnitDelay: '<S1>/UD' */
  bodeTestRunner_DW.UD_DSTATE = bodeTestRunner_P.DiscreteDerivative_ICPrevScaled;

  /* InitializeConditions for DiscreteTransferFcn: '<Root>/Discrete Transfer Fcn' */
  bodeTestRunner_DW.DiscreteTransferFcn_states =
    bodeTestRunner_P.DiscreteTransferFcn_InitialStat;
}

/* Model terminate function */
void bodeTestRunner_terminate(void)
{
  /* Terminate for S-Function (hil_initialize_block): '<S2>/HIL Initialize' */

  /* S-Function Block: bodeTestRunner/Plant/HIL Initialize (hil_initialize_block) */
  {
    t_boolean is_switching;
    t_int result;
    t_uint32 num_final_analog_outputs = 0;
    hil_task_stop_all(bodeTestRunner_DW.HILInitialize_Card);
    hil_monitor_stop_all(bodeTestRunner_DW.HILInitialize_Card);
    is_switching = false;
    if ((bodeTestRunner_P.HILInitialize_AOTerminate && !is_switching) ||
        (bodeTestRunner_P.HILInitialize_AOExit && is_switching)) {
      bodeTestRunner_DW.HILInitialize_AOVoltages[0] =
        bodeTestRunner_P.HILInitialize_AOFinal;
      bodeTestRunner_DW.HILInitialize_AOVoltages[1] =
        bodeTestRunner_P.HILInitialize_AOFinal;
      num_final_analog_outputs = 2U;
    } else {
      num_final_analog_outputs = 0;
    }

    if (num_final_analog_outputs > 0) {
      result = hil_write_analog(bodeTestRunner_DW.HILInitialize_Card,
        bodeTestRunner_P.HILInitialize_AOChannels, num_final_analog_outputs,
        &bodeTestRunner_DW.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(bodeTestRunner_M, _rt_error_message);
      }
    }

    hil_task_delete_all(bodeTestRunner_DW.HILInitialize_Card);
    hil_monitor_delete_all(bodeTestRunner_DW.HILInitialize_Card);
    hil_close(bodeTestRunner_DW.HILInitialize_Card);
    bodeTestRunner_DW.HILInitialize_Card = NULL;
  }
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  bodeTestRunner_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  bodeTestRunner_update();
  UNUSED_PARAMETER(tid);
}

void MdlInitializeSizes(void)
{
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
}

void MdlStart(void)
{
  bodeTestRunner_initialize();
}

void MdlTerminate(void)
{
  bodeTestRunner_terminate();
}

/* Registration function */
RT_MODEL_bodeTestRunner_T *bodeTestRunner(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)bodeTestRunner_M, 0,
                sizeof(RT_MODEL_bodeTestRunner_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&bodeTestRunner_M->solverInfo,
                          &bodeTestRunner_M->Timing.simTimeStep);
    rtsiSetTPtr(&bodeTestRunner_M->solverInfo, &rtmGetTPtr(bodeTestRunner_M));
    rtsiSetStepSizePtr(&bodeTestRunner_M->solverInfo,
                       &bodeTestRunner_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&bodeTestRunner_M->solverInfo, (&rtmGetErrorStatus
      (bodeTestRunner_M)));
    rtsiSetRTModelPtr(&bodeTestRunner_M->solverInfo, bodeTestRunner_M);
  }

  rtsiSetSimTimeStep(&bodeTestRunner_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&bodeTestRunner_M->solverInfo,"FixedStepDiscrete");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = bodeTestRunner_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;

    /* polyspace +2 MISRA2012:D4.1 [Justified:Low] "bodeTestRunner_M points to
       static memory which is guaranteed to be non-NULL" */
    bodeTestRunner_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    bodeTestRunner_M->Timing.sampleTimes =
      (&bodeTestRunner_M->Timing.sampleTimesArray[0]);
    bodeTestRunner_M->Timing.offsetTimes =
      (&bodeTestRunner_M->Timing.offsetTimesArray[0]);

    /* task periods */
    bodeTestRunner_M->Timing.sampleTimes[0] = (0.0);
    bodeTestRunner_M->Timing.sampleTimes[1] = (0.001);

    /* task offsets */
    bodeTestRunner_M->Timing.offsetTimes[0] = (0.0);
    bodeTestRunner_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(bodeTestRunner_M, &bodeTestRunner_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = bodeTestRunner_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    bodeTestRunner_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(bodeTestRunner_M, 5.0);
  bodeTestRunner_M->Timing.stepSize0 = 0.001;
  bodeTestRunner_M->Timing.stepSize1 = 0.001;

  /* External mode info */
  bodeTestRunner_M->Sizes.checksums[0] = (2381060693U);
  bodeTestRunner_M->Sizes.checksums[1] = (20138934U);
  bodeTestRunner_M->Sizes.checksums[2] = (77087351U);
  bodeTestRunner_M->Sizes.checksums[3] = (2226536805U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    bodeTestRunner_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(bodeTestRunner_M->extModeInfo,
      &bodeTestRunner_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(bodeTestRunner_M->extModeInfo,
                        bodeTestRunner_M->Sizes.checksums);
    rteiSetTPtr(bodeTestRunner_M->extModeInfo, rtmGetTPtr(bodeTestRunner_M));
  }

  bodeTestRunner_M->solverInfoPtr = (&bodeTestRunner_M->solverInfo);
  bodeTestRunner_M->Timing.stepSize = (0.001);
  rtsiSetFixedStepSize(&bodeTestRunner_M->solverInfo, 0.001);
  rtsiSetSolverMode(&bodeTestRunner_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  bodeTestRunner_M->blockIO = ((void *) &bodeTestRunner_B);
  (void) memset(((void *) &bodeTestRunner_B), 0,
                sizeof(B_bodeTestRunner_T));

  /* parameters */
  bodeTestRunner_M->defaultParam = ((real_T *)&bodeTestRunner_P);

  /* states (dwork) */
  bodeTestRunner_M->dwork = ((void *) &bodeTestRunner_DW);
  (void) memset((void *)&bodeTestRunner_DW, 0,
                sizeof(DW_bodeTestRunner_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    bodeTestRunner_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 19;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Initialize Sizes */
  bodeTestRunner_M->Sizes.numContStates = (0);/* Number of continuous states */
  bodeTestRunner_M->Sizes.numY = (0);  /* Number of model outputs */
  bodeTestRunner_M->Sizes.numU = (0);  /* Number of model inputs */
  bodeTestRunner_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  bodeTestRunner_M->Sizes.numSampTimes = (2);/* Number of sample times */
  bodeTestRunner_M->Sizes.numBlocks = (26);/* Number of blocks */
  bodeTestRunner_M->Sizes.numBlockIO = (12);/* Number of block outputs */
  bodeTestRunner_M->Sizes.numBlockPrms = (86);/* Sum of parameter "widths" */
  return bodeTestRunner_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
