/*
 * run_q1_test.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "run_q1_test".
 *
 * Model version              : 1.42
 * Simulink Coder version : 9.6 (R2021b) 14-May-2021
 * C source code generated on : Tue Dec 12 08:11:37 2023
 *
 * Target selection: quarc_win64.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "run_q1_test.h"
#include "run_q1_test_private.h"
#include "run_q1_test_dt.h"

/* Block signals (default storage) */
B_run_q1_test_T run_q1_test_B;

/* Block states (default storage) */
DW_run_q1_test_T run_q1_test_DW;

/* Real-time model */
static RT_MODEL_run_q1_test_T run_q1_test_M_;
RT_MODEL_run_q1_test_T *const run_q1_test_M = &run_q1_test_M_;

/* Model output function */
void run_q1_test_output(void)
{
  /* local block i/o variables */
  real_T rtb_InverseModulus1;
  real_T rtb_CableGain;
  real_T rtb_Sum;

  /* S-Function (hil_read_encoder_block): '<S2>/HIL Read Encoder1' */

  /* S-Function Block: run_q1_test/Plant/HIL Read Encoder1 (hil_read_encoder_block) */
  {
    t_error result = hil_read_encoder(run_q1_test_DW.HILInitialize_Card,
      &run_q1_test_P.HILReadEncoder1_channels, 1,
      &run_q1_test_DW.HILReadEncoder1_Buffer);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(run_q1_test_M, _rt_error_message);
    } else {
      rtb_CableGain = run_q1_test_DW.HILReadEncoder1_Buffer;
    }
  }

  /* Gain: '<S2>/mm//cn' */
  run_q1_test_B.mmcn = run_q1_test_P.mmcn_Gain * rtb_CableGain;

  /* S-Function (inverse_modulus_block): '<S2>/Inverse Modulus' */
  /* S-Function Block: run_q1_test/Plant/Inverse Modulus (inverse_modulus_block) */
  {
    static const real_T sampling_period = 0.001;
    real_T half_range = run_q1_test_P.InverseModulus_Modulus / 2.0;
    real_T du, dy;
    if (run_q1_test_DW.InverseModulus_FirstSample) {
      run_q1_test_DW.InverseModulus_FirstSample = false;
      run_q1_test_DW.InverseModulus_PreviousInput = run_q1_test_B.mmcn;
    }

    du = (real_T) run_q1_test_B.mmcn -
      run_q1_test_DW.InverseModulus_PreviousInput;
    if (du > half_range) {
      run_q1_test_DW.InverseModulus_Revolutions =
        run_q1_test_DW.InverseModulus_Revolutions - 1;
      dy = du - run_q1_test_P.InverseModulus_Modulus;
    } else if (du < -half_range) {
      run_q1_test_DW.InverseModulus_Revolutions =
        run_q1_test_DW.InverseModulus_Revolutions + 1;
      dy = du + run_q1_test_P.InverseModulus_Modulus;
    } else {
      dy = du;
    }

    run_q1_test_B.InverseModulus = run_q1_test_B.mmcn +
      run_q1_test_DW.InverseModulus_Revolutions *
      run_q1_test_P.InverseModulus_Modulus;
    run_q1_test_DW.InverseModulus_PreviousInput = run_q1_test_B.mmcn;
  }

  /* S-Function (hil_read_encoder_block): '<S2>/HIL Read Encoder 2' */

  /* S-Function Block: run_q1_test/Plant/HIL Read Encoder 2 (hil_read_encoder_block) */
  {
    t_error result = hil_read_encoder(run_q1_test_DW.HILInitialize_Card,
      &run_q1_test_P.HILReadEncoder2_channels, 1,
      &run_q1_test_DW.HILReadEncoder2_Buffer);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(run_q1_test_M, _rt_error_message);
    } else {
      rtb_CableGain = run_q1_test_DW.HILReadEncoder2_Buffer;
    }
  }

  /* Gain: '<S2>/mm//cn - 2' */
  run_q1_test_B.mmcn2 = run_q1_test_P.mmcn2_Gain * rtb_CableGain;

  /* S-Function (inverse_modulus_block): '<S2>/Inverse Modulus1' */
  /* S-Function Block: run_q1_test/Plant/Inverse Modulus1 (inverse_modulus_block) */
  {
    static const real_T sampling_period = 0.001;
    real_T half_range = run_q1_test_P.InverseModulus1_Modulus / 2.0;
    real_T du, dy;
    if (run_q1_test_DW.InverseModulus1_FirstSample) {
      run_q1_test_DW.InverseModulus1_FirstSample = false;
      run_q1_test_DW.InverseModulus1_PreviousInput = run_q1_test_B.mmcn2;
    }

    du = (real_T) run_q1_test_B.mmcn2 -
      run_q1_test_DW.InverseModulus1_PreviousInput;
    if (du > half_range) {
      run_q1_test_DW.InverseModulus1_Revolutions =
        run_q1_test_DW.InverseModulus1_Revolutions - 1;
      dy = du - run_q1_test_P.InverseModulus1_Modulus;
    } else if (du < -half_range) {
      run_q1_test_DW.InverseModulus1_Revolutions =
        run_q1_test_DW.InverseModulus1_Revolutions + 1;
      dy = du + run_q1_test_P.InverseModulus1_Modulus;
    } else {
      dy = du;
    }

    rtb_InverseModulus1 = run_q1_test_B.mmcn2 +
      run_q1_test_DW.InverseModulus1_Revolutions *
      run_q1_test_P.InverseModulus1_Modulus;
    run_q1_test_DW.InverseModulus1_PreviousInput = run_q1_test_B.mmcn2;
  }

  /* FromWorkspace: '<Root>/From Workspace2' */
  {
    real_T *pDataValues = (real_T *) run_q1_test_DW.FromWorkspace2_PWORK.DataPtr;
    real_T *pTimeValues = (real_T *) run_q1_test_DW.FromWorkspace2_PWORK.TimePtr;
    int_T currTimeIndex = run_q1_test_DW.FromWorkspace2_IWORK.PrevIndex;
    real_T t = run_q1_test_M->Timing.t[0];

    /* Get index */
    if (t <= pTimeValues[0]) {
      currTimeIndex = 0;
    } else if (t >= pTimeValues[1700]) {
      currTimeIndex = 1699;
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

    run_q1_test_DW.FromWorkspace2_IWORK.PrevIndex = currTimeIndex;

    /* Post output */
    {
      real_T t1 = pTimeValues[currTimeIndex];
      real_T t2 = pTimeValues[currTimeIndex + 1];
      if (t1 == t2) {
        if (t < t1) {
          run_q1_test_B.FromWorkspace2 = pDataValues[currTimeIndex];
        } else {
          run_q1_test_B.FromWorkspace2 = pDataValues[currTimeIndex + 1];
        }
      } else {
        real_T f1 = (t2 - t) / (t2 - t1);
        real_T f2 = 1.0 - f1;
        real_T d1;
        real_T d2;
        int_T TimeIndex = currTimeIndex;
        d1 = pDataValues[TimeIndex];
        d2 = pDataValues[TimeIndex + 1];
        run_q1_test_B.FromWorkspace2 = (real_T) rtInterpolate(d1, d2, f1, f2);
        pDataValues += 1701;
      }
    }
  }

  /* Sum: '<Root>/Sum' */
  rtb_Sum = run_q1_test_B.FromWorkspace2 - run_q1_test_B.InverseModulus;

  /* DiscreteIntegrator: '<Root>/Discrete-Time Integrator' */
  run_q1_test_B.DiscreteTimeIntegrator =
    run_q1_test_DW.DiscreteTimeIntegrator_DSTATE;

  /* Gain: '<Root>/Gain2' */
  run_q1_test_B.Gain2 = run_q1_test_P.Kd * rtb_Sum;

  /* SampleTimeMath: '<S1>/TSamp'
   *
   * About '<S1>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  run_q1_test_B.TSamp = run_q1_test_B.Gain2 * run_q1_test_P.TSamp_WtEt;

  /* DiscreteTransferFcn: '<Root>/Discrete Transfer Fcn' incorporates:
   *  Sum: '<S1>/Diff'
   *  UnitDelay: '<S1>/UD'
   */
  run_q1_test_DW.DiscreteTransferFcn_tmp = ((run_q1_test_B.TSamp -
    run_q1_test_DW.UD_DSTATE) - run_q1_test_P.DiscreteTransferFcn_DenCoef[1] *
    run_q1_test_DW.DiscreteTransferFcn_states) /
    run_q1_test_P.DiscreteTransferFcn_DenCoef[0];

  /* DiscreteTransferFcn: '<Root>/Discrete Transfer Fcn' */
  run_q1_test_B.DiscreteTransferFcn = run_q1_test_P.DiscreteTransferFcn_NumCoef
    [0] * run_q1_test_DW.DiscreteTransferFcn_tmp +
    run_q1_test_P.DiscreteTransferFcn_NumCoef[1] *
    run_q1_test_DW.DiscreteTransferFcn_states;

  /* Sum: '<Root>/Sum1' incorporates:
   *  Gain: '<Root>/Gain'
   */
  run_q1_test_B.Sum1 = (run_q1_test_P.Kp * rtb_Sum +
                        run_q1_test_B.DiscreteTimeIntegrator) +
    run_q1_test_B.DiscreteTransferFcn;

  /* Gain: '<S2>/Cable Gain' incorporates:
   *  ZeroOrderHold: '<Root>/Zero-Order Hold'
   */
  rtb_CableGain = run_q1_test_B.Sum1;

  /* Saturate: '<Root>/Saturation' */
  if (rtb_CableGain > run_q1_test_P.Saturation_UpperSat) {
    /* Saturate: '<Root>/Saturation' */
    run_q1_test_B.Saturation = run_q1_test_P.Saturation_UpperSat;
  } else if (rtb_CableGain < run_q1_test_P.Saturation_LowerSat) {
    /* Saturate: '<Root>/Saturation' */
    run_q1_test_B.Saturation = run_q1_test_P.Saturation_LowerSat;
  } else {
    /* Saturate: '<Root>/Saturation' */
    run_q1_test_B.Saturation = rtb_CableGain;
  }

  /* End of Saturate: '<Root>/Saturation' */

  /* Gain: '<S2>/Cable Gain' */
  rtb_CableGain = run_q1_test_P.CableGain_Gain * run_q1_test_B.Saturation;

  /* S-Function (hil_write_analog_block): '<S2>/HIL Write Analog' */

  /* S-Function Block: run_q1_test/Plant/HIL Write Analog (hil_write_analog_block) */
  {
    t_error result;
    result = hil_write_analog(run_q1_test_DW.HILInitialize_Card,
      &run_q1_test_P.HILWriteAnalog_channels, 1, &rtb_CableGain);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(run_q1_test_M, _rt_error_message);
    }
  }

  /* Gain: '<Root>/Gain1' */
  run_q1_test_B.Gain1 = run_q1_test_P.Ki * rtb_Sum;
}

/* Model update function */
void run_q1_test_update(void)
{
  /* Update for DiscreteIntegrator: '<Root>/Discrete-Time Integrator' */
  run_q1_test_DW.DiscreteTimeIntegrator_DSTATE +=
    run_q1_test_P.DiscreteTimeIntegrator_gainval * run_q1_test_B.Gain1;

  /* Update for UnitDelay: '<S1>/UD' */
  run_q1_test_DW.UD_DSTATE = run_q1_test_B.TSamp;

  /* Update for DiscreteTransferFcn: '<Root>/Discrete Transfer Fcn' */
  run_q1_test_DW.DiscreteTransferFcn_states =
    run_q1_test_DW.DiscreteTransferFcn_tmp;

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++run_q1_test_M->Timing.clockTick0)) {
    ++run_q1_test_M->Timing.clockTickH0;
  }

  run_q1_test_M->Timing.t[0] = run_q1_test_M->Timing.clockTick0 *
    run_q1_test_M->Timing.stepSize0 + run_q1_test_M->Timing.clockTickH0 *
    run_q1_test_M->Timing.stepSize0 * 4294967296.0;

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
    if (!(++run_q1_test_M->Timing.clockTick1)) {
      ++run_q1_test_M->Timing.clockTickH1;
    }

    run_q1_test_M->Timing.t[1] = run_q1_test_M->Timing.clockTick1 *
      run_q1_test_M->Timing.stepSize1 + run_q1_test_M->Timing.clockTickH1 *
      run_q1_test_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Model initialize function */
void run_q1_test_initialize(void)
{
  /* Start for S-Function (hil_initialize_block): '<S2>/HIL Initialize' */

  /* S-Function Block: run_q1_test/Plant/HIL Initialize (hil_initialize_block) */
  {
    t_int result;
    t_boolean is_switching;
    result = hil_open("q2_usb", "0", &run_q1_test_DW.HILInitialize_Card);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(run_q1_test_M, _rt_error_message);
      return;
    }

    is_switching = false;
    result = hil_set_card_specific_options(run_q1_test_DW.HILInitialize_Card,
      "d0=digital;d1=digital;led=auto;update_rate=normal;decimation=1", 63);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(run_q1_test_M, _rt_error_message);
      return;
    }

    result = hil_watchdog_clear(run_q1_test_DW.HILInitialize_Card);
    if (result < 0 && result != -QERR_HIL_WATCHDOG_CLEAR) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(run_q1_test_M, _rt_error_message);
      return;
    }

    if ((run_q1_test_P.HILInitialize_AIPStart && !is_switching) ||
        (run_q1_test_P.HILInitialize_AIPEnter && is_switching)) {
      run_q1_test_DW.HILInitialize_AIMinimums[0] =
        (run_q1_test_P.HILInitialize_AILow);
      run_q1_test_DW.HILInitialize_AIMinimums[1] =
        (run_q1_test_P.HILInitialize_AILow);
      run_q1_test_DW.HILInitialize_AIMaximums[0] =
        run_q1_test_P.HILInitialize_AIHigh;
      run_q1_test_DW.HILInitialize_AIMaximums[1] =
        run_q1_test_P.HILInitialize_AIHigh;
      result = hil_set_analog_input_ranges(run_q1_test_DW.HILInitialize_Card,
        run_q1_test_P.HILInitialize_AIChannels, 2U,
        &run_q1_test_DW.HILInitialize_AIMinimums[0],
        &run_q1_test_DW.HILInitialize_AIMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(run_q1_test_M, _rt_error_message);
        return;
      }
    }

    if ((run_q1_test_P.HILInitialize_AOPStart && !is_switching) ||
        (run_q1_test_P.HILInitialize_AOPEnter && is_switching)) {
      run_q1_test_DW.HILInitialize_AOMinimums[0] =
        (run_q1_test_P.HILInitialize_AOLow);
      run_q1_test_DW.HILInitialize_AOMinimums[1] =
        (run_q1_test_P.HILInitialize_AOLow);
      run_q1_test_DW.HILInitialize_AOMaximums[0] =
        run_q1_test_P.HILInitialize_AOHigh;
      run_q1_test_DW.HILInitialize_AOMaximums[1] =
        run_q1_test_P.HILInitialize_AOHigh;
      result = hil_set_analog_output_ranges(run_q1_test_DW.HILInitialize_Card,
        run_q1_test_P.HILInitialize_AOChannels, 2U,
        &run_q1_test_DW.HILInitialize_AOMinimums[0],
        &run_q1_test_DW.HILInitialize_AOMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(run_q1_test_M, _rt_error_message);
        return;
      }
    }

    if ((run_q1_test_P.HILInitialize_AOStart && !is_switching) ||
        (run_q1_test_P.HILInitialize_AOEnter && is_switching)) {
      run_q1_test_DW.HILInitialize_AOVoltages[0] =
        run_q1_test_P.HILInitialize_AOInitial;
      run_q1_test_DW.HILInitialize_AOVoltages[1] =
        run_q1_test_P.HILInitialize_AOInitial;
      result = hil_write_analog(run_q1_test_DW.HILInitialize_Card,
        run_q1_test_P.HILInitialize_AOChannels, 2U,
        &run_q1_test_DW.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(run_q1_test_M, _rt_error_message);
        return;
      }
    }

    if (run_q1_test_P.HILInitialize_AOReset) {
      run_q1_test_DW.HILInitialize_AOVoltages[0] =
        run_q1_test_P.HILInitialize_AOWatchdog;
      run_q1_test_DW.HILInitialize_AOVoltages[1] =
        run_q1_test_P.HILInitialize_AOWatchdog;
      result = hil_watchdog_set_analog_expiration_state
        (run_q1_test_DW.HILInitialize_Card,
         run_q1_test_P.HILInitialize_AOChannels, 2U,
         &run_q1_test_DW.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(run_q1_test_M, _rt_error_message);
        return;
      }
    }

    if ((run_q1_test_P.HILInitialize_EIPStart && !is_switching) ||
        (run_q1_test_P.HILInitialize_EIPEnter && is_switching)) {
      run_q1_test_DW.HILInitialize_QuadratureModes[0] =
        run_q1_test_P.HILInitialize_EIQuadrature;
      run_q1_test_DW.HILInitialize_QuadratureModes[1] =
        run_q1_test_P.HILInitialize_EIQuadrature;
      result = hil_set_encoder_quadrature_mode(run_q1_test_DW.HILInitialize_Card,
        run_q1_test_P.HILInitialize_EIChannels, 2U, (t_encoder_quadrature_mode *)
        &run_q1_test_DW.HILInitialize_QuadratureModes[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(run_q1_test_M, _rt_error_message);
        return;
      }
    }

    if ((run_q1_test_P.HILInitialize_EIStart && !is_switching) ||
        (run_q1_test_P.HILInitialize_EIEnter && is_switching)) {
      run_q1_test_DW.HILInitialize_InitialEICounts[0] =
        run_q1_test_P.HILInitialize_EIInitial;
      run_q1_test_DW.HILInitialize_InitialEICounts[1] =
        run_q1_test_P.HILInitialize_EIInitial;
      result = hil_set_encoder_counts(run_q1_test_DW.HILInitialize_Card,
        run_q1_test_P.HILInitialize_EIChannels, 2U,
        &run_q1_test_DW.HILInitialize_InitialEICounts[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(run_q1_test_M, _rt_error_message);
        return;
      }
    }
  }

  /* Start for S-Function (inverse_modulus_block): '<S2>/Inverse Modulus' */

  /* S-Function Block: run_q1_test/Plant/Inverse Modulus (inverse_modulus_block) */
  {
    run_q1_test_DW.InverseModulus_FirstSample = true;
    run_q1_test_DW.InverseModulus_Revolutions = 0;
  }

  /* Start for S-Function (inverse_modulus_block): '<S2>/Inverse Modulus1' */

  /* S-Function Block: run_q1_test/Plant/Inverse Modulus1 (inverse_modulus_block) */
  {
    run_q1_test_DW.InverseModulus1_FirstSample = true;
    run_q1_test_DW.InverseModulus1_Revolutions = 0;
  }

  /* Start for FromWorkspace: '<Root>/From Workspace2' */
  {
    static real_T pTimeValues0[] = { 0.0, 0.0010078957757599682,
      0.0020157915515199363, 0.0030236873272799052, 0.0040315831030398727,
      0.0050394788787998411, 0.00604737465455981, 0.007055270430319777,
      0.0080631662060797454, 0.0090710619818397155, 0.010078957757599682,
      0.011086853533359651, 0.012094749309119621, 0.013102645084879587,
      0.014110540860639554, 0.015118436636399526, 0.016126332412159491,
      0.017134228187919459, 0.018142123963679431, 0.019150019739439396,
      0.020157915515199364, 0.021165811290959336, 0.0221737070667193,
      0.023181602842479269, 0.024189498618239241, 0.025197394393999206,
      0.026205290169759175, 0.027213185945519143, 0.028221081721279108,
      0.029228977497039083, 0.030236873272799052, 0.031244769048559017,
      0.032252664824318981, 0.033260560600078953, 0.034268456375838918,
      0.03527635215159889, 0.036284247927358862, 0.037292143703118827,
      0.038300039478878792, 0.039307935254638764, 0.040315831030398729,
      0.041323726806158693, 0.042331622581918672, 0.043339518357678637,
      0.0443474141334386, 0.045355309909198574, 0.046363205684958539,
      0.047371101460718504, 0.048378997236478483, 0.049386893012238448,
      0.050394788787998412, 0.051402684563758384, 0.052410580339518349,
      0.053418476115278314, 0.054426371891038286, 0.055434267666798251,
      0.056442163442558216, 0.057450059218318188, 0.058457954994078166,
      0.059465850769838131, 0.0604737465455981, 0.061481642321358068,
      0.062489538097118033, 0.063497433872878, 0.064505329648637963,
      0.065513225424397942, 0.0665211212001579, 0.067529016975917872,
      0.068536912751677836, 0.0695448085274378, 0.07055270430319778,
      0.071560600078957759, 0.072568495854717724, 0.073576391630477689,
      0.074584287406237654, 0.075592183181997619, 0.076600078957757584,
      0.077607974733517562, 0.078615870509277527, 0.079623766285037492,
      0.080631662060797457, 0.081639557836557422, 0.082647453612317387,
      0.083655349388077366, 0.084663245163837345, 0.085671140939597309,
      0.086679036715357274, 0.087686932491117239, 0.0886948282668772,
      0.089702724042637183, 0.090710619818397148, 0.091718515594157113,
      0.092726411369917078, 0.093734307145677043, 0.094742202921437008,
      0.095750098697196986, 0.096757994472956965, 0.09776589024871693,
      0.0987737860244769, 0.09978168180023686, 0.10078957757599682,
      0.10179747335175679, 0.10280536912751677, 0.10381326490327673,
      0.1048211606790367, 0.10582905645479666, 0.10683695223055663,
      0.10784484800631661, 0.10885274378207657, 0.10986063955783654,
      0.1108685353335965, 0.11187643110935647, 0.11288432688511643,
      0.11389222266087641, 0.11490011843663638, 0.11590801421239634,
      0.11691590998815633, 0.1179238057639163, 0.11893170153967626,
      0.11993959731543623, 0.12094749309119621, 0.12195538886695617,
      0.12296328464271614, 0.1239711804184761, 0.12497907619423607,
      0.12598697196999603, 0.126994867745756, 0.12800276352151596,
      0.12901065929727593, 0.13001855507303592, 0.13102645084879588,
      0.13203434662455585, 0.13304224240031581, 0.13405013817607578,
      0.13505803395183574, 0.13606592972759571, 0.13707382550335567,
      0.13808172127911564, 0.1390896170548756, 0.14009751283063557,
      0.14110540860639556, 0.14211330438215553, 0.14312120015791552,
      0.14412909593367548, 0.14513699170943545, 0.14614488748519541,
      0.14715278326095538, 0.14816067903671534, 0.14916857481247531,
      0.15017647058823527, 0.15117647058823527, 0.15217767106842736,
      0.15317887154861942, 0.15418007202881151, 0.15518127250900357,
      0.15618247298919566, 0.15718367346938775, 0.15818487394957981,
      0.1591860744297719, 0.16018727490996396, 0.16118847539015604,
      0.1621896758703481, 0.16319087635054019, 0.16419207683073228,
      0.16519327731092434, 0.16619447779111643, 0.16719567827130849,
      0.16819687875150058, 0.16919807923169267, 0.17019927971188473,
      0.17120048019207681, 0.17220168067226888, 0.17320288115246096,
      0.17420408163265305, 0.17520528211284511, 0.1762064825930372,
      0.17720768307322926, 0.17820888355342135, 0.17921008403361344,
      0.1802112845138055, 0.18121248499399759, 0.18221368547418965,
      0.18321488595438173, 0.18421608643457382, 0.18521728691476588,
      0.18621848739495797, 0.18721968787515003, 0.18822088835534212,
      0.18922208883553421, 0.19022328931572627, 0.19122448979591836,
      0.19222569027611044, 0.19322689075630251, 0.19422809123649459,
      0.19522929171668665, 0.19623049219687874, 0.1972316926770708,
      0.19823289315726289, 0.19923409363745498, 0.20023529411764704,
      0.20123529411764704, 0.20223647848401102, 0.20323766285037503,
      0.20423884721673902, 0.20524003158310303, 0.206241215949467,
      0.20724240031583102, 0.208243584682195, 0.209244769048559,
      0.210245953414923, 0.21124713778128698, 0.212248322147651,
      0.21324950651401497, 0.21425069088037899, 0.21525187524674297,
      0.21625305961310698, 0.21725424397947096, 0.21825542834583495,
      0.21925661271219896, 0.22025779707856294, 0.22125898144492695,
      0.22226016581129093, 0.22326135017765492, 0.22426253454401893,
      0.22526371891038294, 0.22626490327674692, 0.2272660876431109,
      0.22826727200947491, 0.2292684563758389, 0.23026964074220291,
      0.23127082510856689, 0.23227200947493087, 0.23327319384129488,
      0.2342743782076589, 0.23527556257402288, 0.23627674694038686,
      0.23727793130675087, 0.23827911567311486, 0.23928030003947887,
      0.24028148440584285, 0.24128266877220683, 0.24228385313857084,
      0.24328503750493483, 0.24428622187129884, 0.24528740623766282,
      0.24628859060402683, 0.24728977497039081, 0.24829095933675482,
      0.24929214370311881, 0.25029332806948279, 0.25129451243584677,
      0.25229569680221081, 0.25329688116857479, 0.25429806553493878,
      0.25529924990130276, 0.2563004342676668, 0.25730161863403078,
      0.25830280300039477, 0.25930398736675875, 0.26030517173312273,
      0.26130635609948677, 0.26230754046585075, 0.26330872483221474,
      0.26430990919857872, 0.26531109356494276, 0.26631227793130674,
      0.26731346229767072, 0.26831464666403471, 0.26931583103039869,
      0.27031701539676267, 0.27131819976312671, 0.27231938412949069,
      0.27332056849585468, 0.27432175286221872, 0.2753229372285827,
      0.27632412159494668, 0.27732530596131066, 0.27832649032767465,
      0.27932767469403863, 0.28032885906040267, 0.28133004342676665,
      0.28233122779313063, 0.28333241215949467, 0.28433359652585866,
      0.28533478089222264, 0.28633596525858662, 0.28733714962495061,
      0.28833833399131459, 0.28933951835767857, 0.29034070272404261,
      0.29134188709040659, 0.29234307145677063, 0.29334425582313461,
      0.2943454401894986, 0.29534662455586258, 0.29634780892222656,
      0.29734899328859055, 0.29835017765495453, 0.29935136202131857,
      0.30035254638768255, 0.30135373075404659, 0.30235491512041057,
      0.30335609948677456, 0.30435728385313854, 0.30535846821950252,
      0.3063596525858665, 0.30736083695223049, 0.30836202131859453,
      0.30936320568495851, 0.31036439005132255, 0.31136557441768653,
      0.31236675878405051, 0.3133679431504145, 0.31436912751677848,
      0.31537031188314246, 0.31637149624950645, 0.31737268061587048,
      0.31837386498223447, 0.31937504934859845, 0.32037623371496249,
      0.32137741808132647, 0.32237860244769045, 0.32337978681405444,
      0.32438097118041842, 0.3253821555467824, 0.32638333991314644,
      0.32738452427951042, 0.32838570864587446, 0.32938689301223845,
      0.33038807737860243, 0.33138926174496641, 0.3323904461113304,
      0.33339163047769438, 0.33439281484405836, 0.33539399921042234,
      0.33639518357678638, 0.33739636794315037, 0.33839755230951435,
      0.33939873667587839, 0.34039992104224237, 0.34140110540860635,
      0.34240228977497034, 0.34340347414133432, 0.34440465850769836,
      0.34540584287406234, 0.34640702724042638, 0.34740821160679036,
      0.34840939597315435, 0.34941058033951833, 0.35041176470588231,
      0.35141176470588231, 0.3524129490722463, 0.35341413343861028,
      0.35441531780497432, 0.3554165021713383, 0.35641768653770228,
      0.35741887090406627, 0.3584200552704303, 0.35942123963679429,
      0.36042242400315827, 0.36142360836952225, 0.36242479273588624,
      0.36342597710225027, 0.36442716146861426, 0.36542834583497824,
      0.36642953020134222, 0.36743071456770626, 0.36843189893407025,
      0.36943308330043423, 0.37043426766679821, 0.37143545203316219,
      0.37243663639952623, 0.37343782076589022, 0.3744390051322542,
      0.37544018949861818, 0.37644137386498222, 0.3774425582313462,
      0.37844374259771019, 0.37944492696407417, 0.38044611133043815,
      0.38144729569680219, 0.38244848006316617, 0.38344966442953016,
      0.38445084879589414, 0.38545203316225812, 0.38645321752862216,
      0.38745440189498614, 0.38845558626135013, 0.38945677062771411,
      0.39045795499407809, 0.39145913936044213, 0.39246032372680612,
      0.3934615080931701, 0.39446269245953408, 0.39546387682589812,
      0.3964650611922621, 0.39746624555862609, 0.39846742992499007,
      0.39946861429135405, 0.40046979865771809, 0.40147098302408207,
      0.40247216739044606, 0.40347335175681004, 0.40447453612317408,
      0.40547572048953806, 0.40647690485590204, 0.407478089222266,
      0.40847927358863, 0.40948045795499405, 0.41048164232135803,
      0.411482826687722, 0.412484011054086, 0.41348519542045, 0.414486379786814,
      0.415487564153178, 0.416488748519542, 0.41748993288590597,
      0.41849111725226995, 0.419492301618634, 0.420493485984998,
      0.42149467035136196, 0.422495854717726, 0.42349703908409,
      0.42449822345045396, 0.42549940781681794, 0.42650059218318193,
      0.42750177654954591, 0.42850296091590995, 0.42950414528227393,
      0.43050532964863791, 0.43150651401500195, 0.43250769838136593,
      0.43350888274772992, 0.4345100671140939, 0.43551125148045788,
      0.43651243584682187, 0.43751362021318591, 0.43851480457954989,
      0.43951598894591387, 0.44051717331227791, 0.44151835767864189,
      0.44251954204500588, 0.44352072641136986, 0.44452191077773384,
      0.44552309514409782, 0.44652427951046186, 0.44752546387682585,
      0.44852664824318983, 0.44952783260955381, 0.45052901697591785,
      0.45153020134228183, 0.45253138570864582, 0.4535325700750098,
      0.45453375444137378, 0.45553493880773782, 0.4565361231741018,
      0.45753730754046579, 0.45853849190682977, 0.45953967627319381,
      0.46054086063955779, 0.46154204500592177, 0.46254322937228576,
      0.46354441373864974, 0.46454559810501372, 0.46554678247137776,
      0.46654796683774175, 0.46754915120410573, 0.46855033557046977,
      0.46955151993683375, 0.47055270430319773, 0.47155388866956172,
      0.4725550730359257, 0.47355625740228974, 0.47455744176865372,
      0.47555862613501765, 0.47655981050138174, 0.47756099486774573,
      0.47856217923410971, 0.47956336360047369, 0.48056454796683767,
      0.48156573233320166, 0.48256691669956564, 0.48356810106592968,
      0.48456928543229366, 0.48557046979865764, 0.48657165416502168,
      0.48757283853138567, 0.48857402289774965, 0.48957520726411363,
      0.49057639163047762, 0.4915775759968416, 0.49257876036320564,
      0.49357994472956962, 0.49458112909593366, 0.49558231346229764,
      0.49658349782866162, 0.49758468219502561, 0.49858586656138959,
      0.49958705092775357, 0.50058823529411756, 0.50158823529411756,
      0.50258941966048154, 0.50359060402684552, 0.50459178839320951,
      0.50559297275957349, 0.50659415712593758, 0.50759534149230157,
      0.50859652585866555, 0.50959771022502953, 0.51059889459139352,
      0.5116000789577575, 0.51260126332412148, 0.51360244769048546,
      0.51460363205684945, 0.51560481642321354, 0.51660600078957752,
      0.51760718515594151, 0.51860836952230549, 0.51960955388866947,
      0.52061073825503346, 0.52161192262139744, 0.52261310698776142,
      0.52361429135412541, 0.5246154757204895, 0.52561666008685348,
      0.52661784445321747, 0.52761902881958145, 0.52862021318594543,
      0.52962139755230941, 0.5306225819186734, 0.53162376628503738,
      0.53262495065140136, 0.53362613501776535, 0.53462731938412944,
      0.53562850375049342, 0.53662968811685741, 0.53763087248322139,
      0.53863205684958537, 0.53963324121594936, 0.54063442558231334,
      0.54163560994867732, 0.54263679431504142, 0.5436379786814054,
      0.54463916304776938, 0.54564034741413336, 0.54664153178049735,
      0.54764271614686133, 0.54864390051322531, 0.5496450848795893,
      0.55064626924595328, 0.55164745361231726, 0.55264863797868136,
      0.55364982234504534, 0.55465100671140932, 0.55565219107777331,
      0.55665337544413729, 0.55765455981050127, 0.55865574417686525,
      0.55965692854322924, 0.56065811290959322, 0.56165929727595731,
      0.5626604816423213, 0.56366166600868528, 0.56466285037504926,
      0.56566403474141325, 0.56666521910777723, 0.56766640347414121,
      0.5686675878405052, 0.56966877220686918, 0.57066995657323316,
      0.57167114093959726, 0.57267232530596124, 0.57367350967232522,
      0.5746746940386892, 0.57567587840505319, 0.57667706277141717,
      0.57767824713778115, 0.57867943150414514, 0.57968061587050923,
      0.58068180023687321, 0.5816829846032372, 0.58268416896960118,
      0.58368535333596516, 0.58468653770232915, 0.58568772206869313,
      0.58668890643505711, 0.58769009080142109, 0.58869127516778508,
      0.58969245953414906, 0.59069364390051315, 0.59169482826687714,
      0.59269601263324112, 0.5936971969996051, 0.59469838136596909,
      0.59569956573233307, 0.596700750098697, 0.59770193446506115,
      0.59870311883142513, 0.59970430319778911, 0.6007054875641531,
      0.60170667193051708, 0.60270785629688106, 0.603709040663245,
      0.604710225029609, 0.605711409395973, 0.606712593762337, 0.607713778128701,
      0.60871496249506507, 0.609716146861429, 0.610717331227793,
      0.611718515594157, 0.612719699960521, 0.613720884326885, 0.614722068693249,
      0.61572325305961306, 0.616724437425977, 0.617725621792341,
      0.618726806158705, 0.619727990525069, 0.620729174891433, 0.621730359257797,
      0.62273154362416094, 0.62373272799052493, 0.62473391235688891,
      0.62573509672325289, 0.626736281089617, 0.627737465455981,
      0.628738649822345, 0.62973983418870894, 0.63074101855507292,
      0.6317422029214369, 0.63274338728780088, 0.633744571654165,
      0.634745756020529, 0.635746940386893, 0.63674812475325693,
      0.63774930911962091, 0.63875049348598489, 0.63975167785234888,
      0.64075286221871286, 0.64175404658507684, 0.64275523095144083,
      0.64375641531780481, 0.6447575996841689, 0.64575878405053289,
      0.64675996841689687, 0.64776115278326085, 0.64876233714962483,
      0.64976352151598882, 0.6507647058823528, 0.6517647058823528,
      0.65276590636254483, 0.653767106842737, 0.654768307322929,
      0.65576950780312115, 0.65677070828331319, 0.65777190876350522,
      0.65877310924369736, 0.6597743097238894, 0.66077551020408154,
      0.66177671068427357, 0.66277791116446561, 0.66377911164465775,
      0.66478031212484978, 0.66578151260504193, 0.666782713085234,
      0.667783913565426, 0.66878511404561813, 0.66978631452581017,
      0.67078751500600231, 0.67178871548619434, 0.67278991596638638,
      0.67379111644657852, 0.67479231692677055, 0.6757935174069627,
      0.67679471788715473, 0.67779591836734676, 0.67879711884753891,
      0.67979831932773094, 0.68079951980792308, 0.68180072028811511,
      0.68280192076830715, 0.68380312124849929, 0.68480432172869132,
      0.68580552220888347, 0.6868067226890755, 0.68780792316926753,
      0.68880912364945968, 0.68981032412965171, 0.69081152460984385,
      0.69181272509003588, 0.69281392557022792, 0.69381512605042006,
      0.69481632653061209, 0.69581752701080424, 0.69681872749099627,
      0.6978199279711883, 0.69882112845138045, 0.69982232893157248,
      0.70082352941176462, 0.70182352941176462, 0.70282471377812861,
      0.70382589814449259, 0.70482708251085657, 0.70582826687722056,
      0.70682945124358465, 0.70783063560994863, 0.70883181997631262,
      0.7098330043426766, 0.71083418870904058, 0.71183537307540456,
      0.71283655744176855, 0.71383774180813253, 0.71483892617449651,
      0.71584011054086061, 0.71684129490722459, 0.71784247927358857,
      0.71884366363995256, 0.71984484800631654, 0.72084603237268052,
      0.72184721673904451, 0.72284840110540849, 0.72384958547177247,
      0.72485076983813657, 0.72585195420450055, 0.72685313857086453,
      0.72785432293722852, 0.7288555073035925, 0.72985669166995648,
      0.73085787603632046, 0.73185906040268445, 0.73286024476904843,
      0.73386142913541241, 0.73486261350177651, 0.73586379786814049,
      0.73686498223450447, 0.73786616660086846, 0.73886735096723244,
      0.73986853533359642, 0.74086971969996041, 0.74187090406632439,
      0.74287208843268848, 0.74387327279905247, 0.74487445716541645,
      0.74587564153178043, 0.74687682589814441, 0.7478780102645084,
      0.74887919463087238, 0.74988037899723636, 0.75088156336360035,
      0.75188274772996433, 0.75288393209632842, 0.75388511646269241,
      0.75488630082905639, 0.75588748519542037, 0.75688866956178436,
      0.75788985392814834, 0.75889103829451232, 0.7598922226608763,
      0.76089340702724029, 0.76189459139360438, 0.76289577575996836,
      0.76389696012633235, 0.76489814449269633, 0.76589932885906031,
      0.7669005132254243, 0.76790169759178828, 0.76890288195815226,
      0.76990406632451625, 0.77090525069088023, 0.77190643505724432,
      0.77290761942360831, 0.77390880378997229, 0.77490998815633627,
      0.77591117252270025, 0.77691235688906424, 0.77791354125542822,
      0.7789147256217922, 0.7799159099881563, 0.78091709435452028,
      0.78191827872088426, 0.78291946308724825, 0.78392064745361223,
      0.78492183181997621, 0.7859230161863402, 0.78692420055270418,
      0.78792538491906816, 0.78892656928543214, 0.78992775365179613,
      0.79092893801816022, 0.7919301223845242, 0.79293130675088819,
      0.79393249111725217, 0.79493367548361615, 0.79593485984998014,
      0.79693604421634412, 0.79793722858270821, 0.7989384129490722,
      0.79993959731543618, 0.80094078168180016, 0.80194196604816415,
      0.80294315041452813, 0.80394433478089211, 0.80494551914725609,
      0.80594670351362008, 0.80694788787998406, 0.807949072246348,
      0.80895025661271214, 0.80995144097907612, 0.8109526253454401,
      0.81195380971180409, 0.81295499407816807, 0.813956178444532,
      0.814957362810896, 0.81595854717726013, 0.81695973154362411,
      0.8179609159099881, 0.81896210027635208, 0.81996328464271606,
      0.82096446900908, 0.821965653375444, 0.822966837741808, 0.823968022108172,
      0.824969206474536, 0.8259703908409, 0.826971575207264, 0.827972759573628,
      0.828973943939992, 0.829975128306356, 0.83097631267272, 0.831977497039084,
      0.832978681405448, 0.833979865771812, 0.834981050138176, 0.83598223450454,
      0.836983418870904, 0.837984603237268, 0.838985787603632,
      0.83998697196999594, 0.84098815633635993, 0.84198934070272391,
      0.84299052506908789, 0.84399170943545188, 0.844992893801816,
      0.84599407816818, 0.84699526253454394, 0.84799644690090792,
      0.8489976312672719, 0.84999881563363588, 0.85099999999999987,
      0.85099999999999987, 0.86099999999999988, 0.86200789577575987,
      0.86301579155151986, 0.86402368732727974, 0.86503158310303974,
      0.86603947887879973, 0.86704737465455972, 0.8680552704303196,
      0.8690631662060796, 0.87007106198183959, 0.87107895775759958,
      0.87208685353335957, 0.87309474930911946, 0.87410264508487945,
      0.87511054086063944, 0.87611843663639943, 0.87712633241215932,
      0.87813422818791931, 0.8791421239636793, 0.88015001973943929,
      0.88115791551519929, 0.88216581129095917, 0.88317370706671916,
      0.88418160284247915, 0.88518949861823915, 0.88619739439399914,
      0.887205290169759, 0.888213185945519, 0.889221081721279, 0.890228977497039,
      0.89123687327279888, 0.89224476904855887, 0.89325266482431886,
      0.89426056060007886, 0.89526845637583885, 0.89627635215159873,
      0.89728424792735872, 0.89829214370311872, 0.89930003947887871,
      0.90030793525463859, 0.90131583103039858, 0.90232372680615858,
      0.90333162258191857, 0.90433951835767856, 0.90534741413343844,
      0.90635530990919844, 0.90736320568495843, 0.90837110146071842,
      0.9093789972364783, 0.9103868930122383, 0.91139478878799829,
      0.91240268456375828, 0.91341058033951827, 0.91441847611527816,
      0.91542637189103815, 0.91643426766679814, 0.91744216344255813,
      0.918450059218318, 0.919457954994078, 0.920465850769838, 0.921473746545598,
      0.922481642321358, 0.92348953809711787, 0.92449743387287786,
      0.92550532964863785, 0.92651322542439785, 0.92752112120015773,
      0.92852901697591772, 0.92953691275167771, 0.93054480852743771,
      0.9315527043031977, 0.93256060007895769, 0.93356849585471757,
      0.93457639163047757, 0.93558428740623756, 0.93659218318199744,
      0.93760007895775743, 0.93860797473351743, 0.93961587050927742,
      0.94062376628503741, 0.94163166206079729, 0.94263955783655728,
      0.94364745361231728, 0.94465534938807727, 0.94566324516383726,
      0.94667114093959714, 0.94767903671535714, 0.94868693249111713,
      0.94969482826687712, 0.95070272404263712, 0.951710619818397,
      0.952718515594157, 0.953726411369917, 0.95473430714567686,
      0.95574220292143686, 0.95675009869719685, 0.95775799447295684,
      0.95876589024871683, 0.95977378602447683, 0.96078168180023671,
      0.9617895775759967, 0.96279747335175669, 0.96380536912751669,
      0.96481326490327657, 0.96582116067903656, 0.96682905645479655,
      0.96783695223055655, 0.96884484800631654, 0.96985274378207642,
      0.97086063955783641, 0.97186853533359641, 0.97287643110935629,
      0.97388432688511628, 0.97489222266087627, 0.97590011843663627,
      0.97690801421239626, 0.97791590998815625, 0.97892380576391613,
      0.97993170153967613, 0.98093959731543612, 0.98194749309119611,
      0.982955388866956, 0.983963284642716, 0.984971180418476, 0.985979076194236,
      0.986986971969996, 0.98799486774575584, 0.98900276352151584,
      0.99001065929727583, 0.99101855507303582, 0.9920264508487957,
      0.9930343466245557, 0.99404224240031569, 0.99505013817607568,
      0.99605803395183568, 0.99706592972759556, 0.99807382550335555,
      0.99908172127911554, 1.0000896170548754, 1.0010975128306354,
      1.0021054086063954, 1.0031133043821554, 1.0041212001579154,
      1.0051290959336754, 1.0061369917094354, 1.0071448874851954,
      1.0081527832609551, 1.0091606790367151, 1.0101685748124751,
      1.0111764705882351, 1.0121764705882352, 1.0131776710684273,
      1.0141788715486193, 1.0151800720288113, 1.0161812725090034,
      1.0171824729891956, 1.0181836734693877, 1.0191848739495797,
      1.0201860744297717, 1.0211872749099637, 1.022188475390156,
      1.023189675870348, 1.02419087635054, 1.0251920768307321,
      1.0261932773109241, 1.0271944777911164, 1.0281956782713084,
      1.0291968787515005, 1.0301980792316925, 1.0311992797118845,
      1.0322004801920768, 1.0332016806722688, 1.0342028811524608,
      1.0352040816326529, 1.0362052821128449, 1.0372064825930372,
      1.0382076830732292, 1.0392088835534212, 1.0402100840336133,
      1.0412112845138053, 1.0422124849939975, 1.0432136854741896,
      1.0442148859543816, 1.0452160864345736, 1.0462172869147657,
      1.0472184873949579, 1.04821968787515, 1.049220888355342, 1.050222088835534,
      1.0512232893157261, 1.0522244897959183, 1.0532256902761103,
      1.0542268907563024, 1.0552280912364944, 1.0562292917166864,
      1.0572304921968787, 1.0582316926770707, 1.0592328931572628,
      1.0602340936374548, 1.0612352941176468, 1.0622352941176469,
      1.0632364784840109, 1.0642376628503749, 1.0652388472167389,
      1.0662400315831029, 1.0672412159494669, 1.0682424003158308,
      1.0692435846821948, 1.0702447690485588, 1.0712459534149228,
      1.0722471377812868, 1.0732483221476508, 1.0742495065140147,
      1.0752506908803789, 1.0762518752467429, 1.0772530596131069,
      1.0782542439794709, 1.0792554283458349, 1.0802566127121989,
      1.0812577970785628, 1.0822589814449268, 1.0832601658112908,
      1.0842613501776548, 1.0852625345440188, 1.0862637189103828,
      1.0872649032767467, 1.0882660876431107, 1.0892672720094747,
      1.0902684563758387, 1.0912696407422029, 1.0922708251085669,
      1.0932720094749309, 1.0942731938412948, 1.0952743782076588,
      1.0962755625740228, 1.0972767469403868, 1.0982779313067508,
      1.0992791156731148, 1.1002803000394787, 1.1012814844058427,
      1.1022826687722067, 1.1032838531385707, 1.1042850375049347,
      1.1052862218712987, 1.1062874062376626, 1.1072885906040266,
      1.1082897749703906, 1.1092909593367546, 1.1102921437031186,
      1.1112933280694826, 1.1122945124358465, 1.1132956968022107,
      1.1142968811685747, 1.1152980655349387, 1.1162992499013027,
      1.1173004342676667, 1.1183016186340307, 1.1193028030003946,
      1.1203039873667586, 1.1213051717331226, 1.1223063560994866,
      1.1233075404658506, 1.1243087248322146, 1.1253099091985785,
      1.1263110935649427, 1.1273122779313067, 1.1283134622976707,
      1.1293146466640347, 1.1303158310303987, 1.1313170153967627,
      1.1323181997631266, 1.1333193841294906, 1.1343205684958546,
      1.1353217528622186, 1.1363229372285826, 1.1373241215949466,
      1.1383253059613105, 1.1393264903276745, 1.1403276746940385,
      1.1413288590604025, 1.1423300434267665, 1.1433312277931305,
      1.1443324121594944, 1.1453335965258584, 1.1463347808922224,
      1.1473359652585864, 1.1483371496249504, 1.1493383339913144,
      1.1503395183576783, 1.1513407027240425, 1.1523418870904065,
      1.1533430714567705, 1.1543442558231345, 1.1553454401894985,
      1.1563466245558625, 1.1573478089222264, 1.1583489932885904,
      1.1593501776549544, 1.1603513620213184, 1.1613525463876824,
      1.1623537307540466, 1.1633549151204106, 1.1643560994867745,
      1.1653572838531385, 1.1663584682195025, 1.1673596525858665,
      1.1683608369522305, 1.1693620213185945, 1.1703632056849584,
      1.1713643900513224, 1.1723655744176864, 1.1733667587840504,
      1.1743679431504144, 1.1753691275167784, 1.1763703118831423,
      1.1773714962495063, 1.1783726806158703, 1.1793738649822343,
      1.1803750493485983, 1.1813762337149623, 1.1823774180813262,
      1.1833786024476902, 1.1843797868140542, 1.1853809711804182,
      1.1863821555467822, 1.1873833399131464, 1.1883845242795104,
      1.1893857086458743, 1.1903868930122383, 1.1913880773786023,
      1.1923892617449663, 1.1933904461113303, 1.1943916304776943,
      1.1953928148440582, 1.1963939992104222, 1.1973951835767862,
      1.1983963679431502, 1.1993975523095142, 1.2003987366758784,
      1.2013999210422424, 1.2024011054086063, 1.2034022897749703,
      1.2044034741413343, 1.2054046585076983, 1.2064058428740623,
      1.2074070272404263, 1.2084082116067902, 1.2094093959731542,
      1.2104105803395182, 1.2114117647058822, 1.2124117647058821,
      1.2134129490722461, 1.21441413343861, 1.2154153178049742,
      1.2164165021713382, 1.2174176865377022, 1.2184188709040662,
      1.2194200552704302, 1.2204212396367942, 1.2214224240031581,
      1.2224236083695221, 1.2234247927358861, 1.22442597710225,
      1.2254271614686141, 1.2264283458349781, 1.227429530201342,
      1.2284307145677063, 1.2294318989340702, 1.2304330833004342,
      1.2314342676667982, 1.2324354520331622, 1.2334366363995262,
      1.2344378207658901, 1.2354390051322541, 1.2364401894986181,
      1.2374413738649821, 1.2384425582313461, 1.23944374259771,
      1.240444926964074, 1.241446111330438, 1.242447295696802, 1.243448480063166,
      1.24444966442953, 1.245450848795894, 1.2464520331622579,
      1.2474532175286219, 1.2484544018949859, 1.24945558626135,
      1.2504567706277139, 1.2514579549940779, 1.2524591393604421,
      1.253460323726806, 1.25446150809317, 1.255462692459534, 1.256463876825898,
      1.257465061192262, 1.258466245558626, 1.25946742992499, 1.2604686142913539,
      1.2614697986577179, 1.2624709830240819, 1.2634721673904459,
      1.2644733517568099, 1.2654745361231741, 1.266475720489538,
      1.267476904855902, 1.268478089222266, 1.26947927358863, 1.270480457954994,
      1.271481642321358, 1.2724828266877219, 1.2734840110540859,
      1.27448519542045, 1.2754863797868139, 1.2764875641531779,
      1.2774887485195419, 1.2784899328859058, 1.2794911172522698,
      1.2804923016186338, 1.2814934859849978, 1.2824946703513618,
      1.2834958547177258, 1.2844970390840897, 1.2854982234504537,
      1.2864994078168177, 1.2875005921831817, 1.2885017765495457,
      1.2895029609159099, 1.2905041452822739, 1.2915053296486378,
      1.2925065140150018, 1.2935076983813658, 1.2945088827477298,
      1.2955100671140938, 1.2965112514804578, 1.2975124358468217,
      1.2985136202131857, 1.2995148045795497, 1.3005159889459137,
      1.3015171733122779, 1.3025183576786419, 1.3035195420450059,
      1.3045207264113698, 1.3055219107777338, 1.3065230951440978,
      1.3075242795104618, 1.3085254638768258, 1.3095266482431898,
      1.3105278326095537, 1.3115290169759177, 1.3125302013422817,
      1.3135313857086457, 1.3145325700750097, 1.3155337544413737,
      1.3165349388077376, 1.3175361231741016, 1.3185373075404656,
      1.3195384919068296, 1.3205396762731936, 1.3215408606395576,
      1.3225420450059215, 1.3235432293722855, 1.3245444137386495,
      1.3255455981050135, 1.3265467824713777, 1.3275479668377417,
      1.3285491512041057, 1.3295503355704696, 1.3305515199368336,
      1.3315527043031976, 1.3325538886695616, 1.3335550730359256,
      1.3345562574022896, 1.3355574417686535, 1.3365586261350175,
      1.3375598105013817, 1.3385609948677457, 1.3395621792341097,
      1.3405633636004737, 1.3415645479668377, 1.3425657323332016,
      1.3435669166995656, 1.3445681010659296, 1.3455692854322936,
      1.3465704697986576, 1.3475716541650216, 1.3485728385313855,
      1.3495740228977495, 1.3505752072641135, 1.3515763916304775,
      1.3525775759968415, 1.3535787603632055, 1.3545799447295694,
      1.3555811290959334, 1.3565823134622974, 1.3575834978286614,
      1.3585846821950254, 1.3595858665613894, 1.3605870509277533,
      1.3615882352941173, 1.3625882352941174, 1.3635894196604814,
      1.3645906040268454, 1.3655917883932094, 1.3665929727595734,
      1.3675941571259376, 1.3685953414923016, 1.3695965258586655,
      1.3705977102250295, 1.3715988945913935, 1.3726000789577575,
      1.3736012633241215, 1.3746024476904855, 1.3756036320568494,
      1.3766048164232134, 1.3776060007895774, 1.3786071851559414,
      1.3796083695223054, 1.3806095538886693, 1.3816107382550333,
      1.3826119226213973, 1.3836131069877613, 1.3846142913541253,
      1.3856154757204893, 1.3866166600868532, 1.3876178444532172,
      1.3886190288195812, 1.3896202131859452, 1.3906213975523092,
      1.3916225819186732, 1.3926237662850371, 1.3936249506514011,
      1.3946261350177651, 1.3956273193841293, 1.3966285037504933,
      1.3976296881168573, 1.3986308724832213, 1.3996320568495852,
      1.4006332412159492, 1.4016344255823132, 1.4026356099486772,
      1.4036367943150414, 1.4046379786814054, 1.4056391630477694,
      1.4066403474141334, 1.4076415317804973, 1.4086427161468613,
      1.4096439005132253, 1.4106450848795893, 1.4116462692459533,
      1.4126474536123172, 1.4136486379786812, 1.4146498223450452,
      1.4156510067114092, 1.4166521910777732, 1.4176533754441372,
      1.4186545598105011, 1.4196557441768651, 1.4206569285432291,
      1.4216581129095931, 1.4226592972759571, 1.4236604816423211,
      1.424661666008685, 1.425662850375049, 1.426664034741413, 1.427665219107777,
      1.428666403474141, 1.429667587840505, 1.4306687722068689,
      1.4316699565732329, 1.4326711409395971, 1.4336723253059611,
      1.4346735096723251, 1.4356746940386891, 1.4366758784050531,
      1.437677062771417, 1.438678247137781, 1.439679431504145,
      1.4406806158705092, 1.4416818002368732, 1.4426829846032372,
      1.4436841689696012, 1.4446853533359652, 1.4456865377023291,
      1.4466877220686931, 1.4476889064350571, 1.4486900908014211,
      1.4496912751677851, 1.450692459534149, 1.451693643900513,
      1.452694828266877, 1.453696012633241, 1.454697196999605, 1.455698381365969,
      1.4566995657323329, 1.4577007500986969, 1.4587019344650609,
      1.4597031188314249, 1.4607043031977889, 1.4617054875641529,
      1.4627066719305168, 1.4637078562968808, 1.4647090406632448,
      1.4657102250296088, 1.4667114093959728, 1.4677125937623368,
      1.4687137781287007, 1.4697149624950649, 1.4707161468614289,
      1.4717173312277929, 1.4727185155941569, 1.4737196999605209,
      1.4747208843268849, 1.4757220686932488, 1.4767232530596131,
      1.477724437425977, 1.478725621792341, 1.479726806158705, 1.480727990525069,
      1.481729174891433, 1.4827303592577969, 1.4837315436241609,
      1.4847327279905249, 1.4857339123568889, 1.4867350967232529,
      1.4877362810896169, 1.4887374654559808, 1.4897386498223448,
      1.4907398341887088, 1.4917410185550728, 1.4927422029214368,
      1.4937433872878008, 1.4947445716541647, 1.4957457560205287,
      1.4967469403868927, 1.4977481247532567, 1.4987493091196207,
      1.4997504934859847, 1.5007516778523486, 1.5017528622187126,
      1.5027540465850766, 1.5037552309514406, 1.5047564153178046,
      1.5057575996841688, 1.5067587840505328, 1.5077599684168967,
      1.5087611527832607, 1.5097623371496247, 1.5107635215159887,
      1.5117647058823527, 1.5127647058823528, 1.5137659063625448,
      1.5147671068427369, 1.5157683073229289, 1.5167695078031209,
      1.517770708283313, 1.518771908763505, 1.5197731092436972,
      1.5207743097238893, 1.5217755102040815, 1.5227767106842736,
      1.5237779111644656, 1.5247791116446576, 1.5257803121248497,
      1.5267815126050417, 1.5277827130852337, 1.5287839135654258,
      1.529785114045618, 1.53078631452581, 1.5317875150060023,
      1.5327887154861943, 1.5337899159663864, 1.5347911164465784,
      1.5357923169267704, 1.5367935174069625, 1.5377947178871545,
      1.5387959183673465, 1.5397971188475388, 1.5407983193277308,
      1.5417995198079231, 1.5428007202881151, 1.5438019207683071,
      1.5448031212484992, 1.5458043217286912, 1.5468055222088832,
      1.5478067226890753, 1.5488079231692673, 1.5498091236494596,
      1.5508103241296516, 1.5518115246098438, 1.5528127250900359,
      1.5538139255702279, 1.55481512605042, 1.555816326530612, 1.556817527010804,
      1.557818727490996, 1.5588199279711881, 1.5598211284513803,
      1.5608223289315724, 1.5618235294117646, 1.5628235294117645,
      1.5638247137781285, 1.5648258981444925, 1.5658270825108564,
      1.5668282668772204, 1.5678294512435844, 1.5688306356099484,
      1.5698318199763124, 1.5708330043426764, 1.5718341887090403,
      1.5728353730754043, 1.5738365574417683, 1.5748377418081323,
      1.5758389261744963, 1.5768401105408605, 1.5778412949072245,
      1.5788424792735885, 1.5798436636399524, 1.5808448480063164,
      1.5818460323726804, 1.5828472167390444, 1.5838484011054084,
      1.5848495854717723, 1.5858507698381366, 1.5868519542045005,
      1.5878531385708645, 1.5888543229372285, 1.5898555073035925,
      1.5908566916699565, 1.5918578760363205, 1.5928590604026844,
      1.5938602447690484, 1.5948614291354124, 1.5958626135017764,
      1.5968637978681404, 1.5978649822345043, 1.5988661666008683,
      1.5998673509672323, 1.6008685353335963, 1.6018697196999603,
      1.6028709040663243, 1.6038720884326882, 1.6048732727990522,
      1.6058744571654162, 1.6068756415317802, 1.6078768258981442,
      1.6088780102645082, 1.6098791946308721, 1.6108803789972361,
      1.6118815633636001, 1.6128827477299641, 1.6138839320963283,
      1.6148851164626923, 1.6158863008290563, 1.6168874851954202,
      1.6178886695617842, 1.6188898539281482, 1.6198910382945122,
      1.6208922226608762, 1.6218934070272402, 1.6228945913936044,
      1.6238957757599684, 1.6248969601263323, 1.6258981444926963,
      1.6268993288590603, 1.6279005132254243, 1.6289016975917883,
      1.6299028819581522, 1.6309040663245162, 1.6319052506908802,
      1.6329064350572442, 1.6339076194236082, 1.6349088037899722,
      1.6359099881563361, 1.6369111725227001, 1.6379123568890641,
      1.6389135412554281, 1.6399147256217921, 1.6409159099881561,
      1.64191709435452, 1.642918278720884, 1.643919463087248, 1.644920647453612,
      1.645921831819976, 1.64692301618634, 1.6479242005527039,
      1.6489253849190679, 1.6499265692854319, 1.6509277536517959,
      1.65192893801816, 1.6529301223845241, 1.6539313067508881,
      1.654932491117252, 1.655933675483616, 1.65693485984998, 1.657936044216344,
      1.6589372285827082, 1.6599384129490722, 1.6609395973154362,
      1.6619407816818001, 1.6629419660481641, 1.6639431504145281,
      1.6649443347808921, 1.6659455191472561, 1.66694670351362,
      1.667947887879984, 1.668949072246348, 1.669950256612712, 1.670951440979076,
      1.67195262534544, 1.672953809711804, 1.6739549940781679,
      1.6749561784445319, 1.6759573628108959, 1.67695854717726,
      1.6779597315436239, 1.6789609159099879, 1.6799621002763518,
      1.6809632846427158, 1.6819644690090798, 1.6829656533754438,
      1.6839668377418078, 1.6849680221081718, 1.6859692064745357,
      1.6869703908408997, 1.6879715752072639, 1.6889727595736279,
      1.6899739439399919, 1.6909751283063559, 1.6919763126727199,
      1.6929774970390838, 1.6939786814054478, 1.694979865771812,
      1.695981050138176, 1.69698223450454, 1.697983418870904, 1.698984603237268,
      1.6999857876036319, 1.7009869719699959, 1.70198815633636,
      1.7029893407027239, 1.7039905250690879, 1.7049917094354519,
      1.7059928938018158, 1.7069940781681798, 1.7079952625345438,
      1.7089964469009078, 1.7099976312672718, 1.7109988156336358,
      1.7119999999999997 } ;

    static real_T pDataValues0[] = { 0.0, 5.6908874753160016E-9,
      9.0809100817424641E-8, 4.5848026027582882E-7, 1.4451024518745904E-6,
      3.5185079865050987E-6, 7.2761251590188363E-6, 1.3443140007320116E-5,
      2.2870658071458918E-5, 3.6533866152723584E-5, 5.5530194072733529E-5,
      8.107747643253223E-5, 0.0001145121143716798, 0.00015728723732734556,
      0.00021097086479340133, 0.0002772440680795142, 0.00035789913207023773,
      0.00045483771698410754, 0.00057006902013273227, 0.00070570793767988456,
      0.000863973226400599, 0.00104718566544026, 0.0012577662180736952,
      0.0014982341934642715, 0.0017712054084229865, 0.0020793903491675546,
      0.0024255923330815127, 0.0028127056704733027, 0.0032437138263353643,
      0.0037216875821032428, 0.0042497831974146506, 0.0048312405718685947,
      0.005469381406784447, 0.006167607366961053, 0.0069293982424357987,
      0.0077583101102437439, 0.008657973496176672, 0.0096320915365422019,
      0.010684438139922892, 0.011818856148935328, 0.013039255501989182,
      0.014349611395046358, 0.015753962443380072, 0.017256408843333876,
      0.01886111053408086, 0.020572285359382686, 0.022394207229348654,
      0.024331204282194867, 0.026387657046003286, 0.028567996600480747,
      0.030876702738718221, 0.033318302128949775, 0.035897366476311678,
      0.038618510684601565, 0.041486391018037486, 0.044505703263016914,
      0.04768118088987601, 0.051017593214648632, 0.054519743560825382,
      0.058192467421112649, 0.062040630619191989, 0.066069127471478833,
      0.070282878948881924, 0.0746868308385621, 0.079285951905691723,
      0.084085232055213455, 0.089089680493599416, 0.094304323890610511,
      0.099734204541055277, 0.10538437852654911, 0.11125991387727324,
      0.11736588873373394, 0.12370738950852136, 0.13028950904806913,
      0.137117344794413, 0.14419599694695, 0.15153056662419789,
      0.1591261540255538, 0.16698785659305326, 0.17512076717312991,
      0.18352997217837405, 0.1922205497492919, 0.20119756791606477,
      0.21046608276030807, 0.22003113657683027, 0.22989775603539211,
      0.24007095034246581, 0.25055570940299415, 0.2613570019821494,
      0.27247977386709255, 0.28392894602873203, 0.29570941278348356,
      0.30782603995502833, 0.32028366303607325, 0.33308708535010856,
      0.34624107621316841, 0.35975036909558872, 0.37361965978376688,
      0.387853604541921, 0.40245681827384883, 0.41743387268468668,
      0.43278929444266845, 0.44852756334088539, 0.46465311045904389,
      0.48117031632522611, 0.49808350907764826, 0.51539696262641965,
      0.53311489481530216, 0.55124146558346832, 0.56978077512726177,
      0.58873686206195608, 0.60811370158351274, 0.62791520363034192,
      0.64814521104506029, 0.6688074977362497, 0.689905766840218,
      0.711443648882758, 0.73342469994090309, 0.75585239980469132,
      0.77873015013892166, 0.802061272644914, 0.8258490072222664,
      0.850096510130617, 0.87480685215140142, 0.89998301674961212,
      0.92562789823555713, 0.95174429992662035, 0.97833493230901947,
      1.0054024111995659, 1.0329492559074227, 1.0609778873958642,
      1.089490626444036, 1.1184896918087133, 1.1479771983860598,
      1.1779551553733869, 1.2084254644309143, 1.2393899178435244,
      1.2708501966825292, 1.3028078689674212, 1.3352643878276376,
      1.368221089664319, 1.4016791923120651, 1.435639793200699,
      1.4701038675170204, 1.5050722663665694, 1.5405457149353849,
      1.5765248106517615, 1.6130100213480099, 1.6500016834222162,
      1.6875000000000007, 1.7252053469962063, 1.7634556827217263,
      1.8022060424289241, 1.8414564261178, 1.8812068337883536,
      1.9214572654405855, 1.9622077210744955, 2.003458200690083,
      2.045208704287349, 2.0874592318662928, 2.1302097834269147,
      2.1734603589692143, 2.2172109584931921, 2.2614615819988479,
      2.3062122294861815, 2.3514629009551937, 2.3972135964058832,
      2.4434643158382512, 2.4902150592522969, 2.5374658266480203,
      2.5852166180254224, 2.6334674333845021, 2.68221827272526,
      2.7314691360476955, 2.7812200233518092, 2.831470934637601,
      2.882221869905071, 2.9334728291542183, 2.9852238123850441,
      3.0374748195975476, 3.0902258507917293, 3.1434769059675891,
      3.1972279851251266, 3.2514790882643423, 3.3062302153852361,
      3.3614813664878076, 3.4172325415720577, 3.473483740637985,
      3.530234963685591, 3.5874862107148742, 3.6452374817258359,
      3.7034887767184763, 3.7622400956927931, 3.8214914386487888,
      3.8812428055864623, 3.9414941965058143, 4.0022456114068437,
      4.063497050289552, 4.1252485131539371, 4.1875, 4.2501759642781565,
      4.3134257948279515, 4.3771753584555, 4.4414243277474377,
      4.5061722472842991, 4.571418535418367, 4.6371624860515244,
      4.7034032704130935, 4.770139938837695, 4.8373714225430842,
      4.9050965354080107, 4.9733139757500524, 5.0420223281034806,
      5.1112200649970916, 5.1809055487320634, 5.2510770331598033,
      5.321732665459793, 5.3928704879174347, 5.4644884397019089,
      5.5365843586440064, 5.6091559830139959, 5.68220095329945,
      5.7557168139831107, 5.8297010153207305, 5.9041509151189189,
      5.9790637805129894, 6.0544367897448179, 6.1302670339406715,
      6.2065515188890794, 6.2832871668186572, 6.3604708181759761,
      6.4380992334033929, 6.5161690947169157, 6.59467700788403,
      6.6736195040015716, 6.7529930412735508, 6.8327940067890189,
      6.9130187182999014, 6.9936634259988582, 7.0747243142971241,
      7.15619750360236, 7.2380790520964959, 7.3203649575135854,
      7.4030511589176493, 7.4861335384805257, 7.5696079232597144,
      7.6534700869762293, 7.7377157517924449, 7.8223405900899419,
      7.9073402262473529, 7.9927102384182245, 8.0784461603088431,
      8.1645434829561054, 8.25099765650534, 8.3378040919881915,
      8.4249581631004258, 8.5124552079798157, 8.6002905309839655,
      8.6884594044681656, 8.7769570705632454, 8.8657787429534114,
      8.9549196086541034, 9.0443748297898381, 9.13413954537206,
      9.224208873076984, 9.3145779110234539, 9.4052417395507746,
      9.4961954229965659, 9.587434011474631, 9.67895254265277, 9.770746043530643,
      9.86280953221763, 9.9551380197106614, 10.047726511672074,
      10.140570010207458, 10.2336635156435, 10.32700202830584,
      10.420580550296915, 10.514394087273802, 10.608437650226067,
      10.702706257253626, 10.797194935344576, 10.891898722153051,
      10.98681266777707, 11.081931836536377, 11.177251308750309,
      11.272766182515616, 11.368471575484332, 11.464362626641606,
      11.560434498083573, 11.656682376795166, 11.753101476427998,
      11.849687039078198, 11.946434337064252, 12.043338674704858,
      12.140395390096767, 12.237599856892643, 12.334947486078907,
      12.432433727753569, 12.5300540729041, 12.627804055185265,
      12.725679252696974, 12.823675289762132, 12.921787838704478,
      13.020012621626453, 13.118345412187024, 13.216782037379549,
      13.315318379309614, 13.413950376972894, 13.512674028032979,
      13.611485390599249, 13.710380585004694, 13.809355795583794,
      13.908407272450338, 14.007531333275283, 14.106724365064595,
      14.205982825937127, 14.305303246902422, 14.404682233638583,
      14.504116468270137, 14.603602711145845, 14.703137802616588,
      14.802718664813192, 14.902342303424271, 15.002005809474113,
      15.101706361100478, 15.201441225332461, 15.30120775986838,
      15.401003414853552, 15.500825734658219, 15.600672359655331,
      15.700541027998417, 15.800429577399459, 15.900335946906695,
      16.0002581786825, 16.100194419781221, 16.200142923927025,
      16.300102053291742, 16.400070280272729, 16.5000461892707,
      16.600028478467596, 16.700015961604397, 16.800007569759007,
      16.90000235312408, 16.999999482784876, 17.099998252497112,
      17.1999980804648, 17.299998511118098, 17.399999216891164,
      17.500000000000004, 17.599882491186843, 17.699883279836595,
      17.79988406848635, 17.8998848571361, 17.999885645785852,
      18.099886434435607, 18.199887223085359, 18.299888011735113,
      18.399888800384865, 18.499889589034616, 18.599890377684371,
      18.699891166334123, 18.799891954983877, 18.899892743633629,
      18.99989353228338, 19.099894320933135, 19.199895109582886,
      19.299895898232641, 19.399896686882393, 19.499897475532144,
      19.5998982641819, 19.69989905283165, 19.799899841481402,
      19.899900630131157, 19.999901418780908, 20.099902207430663,
      20.199902996080414, 20.299903784730166, 20.399904573379921,
      20.499905362029672, 20.599906150679427, 20.699906939329178,
      20.79990772797893, 20.899908516628685, 20.999909305278436,
      21.099910093928187, 21.199910882577942, 21.299911671227694,
      21.399912459877449, 21.4999132485272, 21.599914037176951,
      21.699914825826706, 21.799915614476458, 21.899916403126213,
      21.999917191775964, 22.099917980425715, 22.19991876907547,
      22.299919557725222, 22.399920346374977, 22.499921135024728,
      22.599921923674479, 22.699922712324234, 22.799923500973986,
      22.89992428962374, 22.999925078273492, 23.099925866923243,
      23.199926655572998, 23.29992744422275, 23.399928232872504,
      23.499929021522256, 23.599929810172007, 23.699930598821762,
      23.799931387471513, 23.899932176121268, 23.99993296477102,
      24.099933753420771, 24.199934542070526, 24.299935330720277,
      24.399936119370029, 24.499936908019784, 24.599937696669535,
      24.69993848531929, 24.799939273969041, 24.899940062618796,
      24.999940851268548, 25.0999416399183, 25.19994242856805,
      25.299943217217805, 25.39994400586756, 25.499944794517312,
      25.599945583167063, 25.699946371816814, 25.799947160466569,
      25.899947949116324, 25.999948737766076, 26.099949526415827,
      26.199950315065578, 26.299951103715333, 26.399951892365085,
      26.49995268101484, 26.599953469664591, 26.699954258314342,
      26.799955046964097, 26.899955835613849, 26.999956624263604,
      27.099957412913355, 27.199958201563106, 27.299958990212858,
      27.399959778862613, 27.499960567512368, 27.599961356162119,
      27.69996214481187, 27.799962933461625, 27.89996372211138,
      27.999964510761131, 28.099965299410883, 28.199966088060634,
      28.299966876710386, 28.399967665360141, 28.499968454009895,
      28.599969242659647, 28.699970031309398, 28.799970819959153,
      28.899971608608904, 28.999972397258659, 29.099973185908411,
      29.199973974558162, 29.299974763207913, 29.399975551857668,
      29.499976340507423, 29.599977129157175, 29.699977917806926,
      29.799978706456681, 29.899979495106432, 29.99998028375618,
      30.099981072405939, 30.19998186105569, 30.299982649705445,
      30.399983438355196, 30.499984227004948, 30.599985015654703,
      30.699985804304454, 30.799986592954209, 30.89998738160396,
      30.999988170253712, 31.099988958903467, 31.199989747553218,
      31.299990536202969, 31.399991324852724, 31.499992113502476,
      31.599992902152231, 31.699993690801982, 31.799994479451733,
      31.899995268101492, 31.999996056751243, 32.099996845400995,
      32.199997634050746, 32.2999984227005, 32.399999211350249, 32.5,
      32.599882485672083, 32.69988319162772, 32.79988362277458,
      32.89988345169931, 32.999882222982428, 33.099879354976224,
      33.199874141582583, 33.299865754030819, 33.399853242655567,
      33.499835538674574, 33.599811455966581, 33.699779692849177,
      33.799738833856637, 33.899687351517741, 33.999623608133696,
      34.099545857555874, 34.199452246963773, 34.299340818642804,
      34.39920951176213, 34.499056164152563, 34.598878514084355,
      34.698674202045083, 34.798440772517473, 34.898175675757308,
      34.997876269571186, 35.097539821094422, 35.19716350856887,
      35.296744423120828, 35.3962795705388, 35.495765873051425,
      35.595200171105255, 35.694579225142654, 35.793899717379638,
      35.893158253583678, 35.992351364851622, 36.091475509387472,
      36.190527074280276, 36.28950237728197, 36.388397668585213,
      36.487209132601244, 36.585932889737705, 36.684564998176533,
      36.783101455651796, 36.8815382012275, 36.97987111707549,
      37.078096030253263, 37.176208714481831, 37.274204891923574,
      37.372080234960066, 37.469830367969948, 37.567450869106764,
      37.664937272076791, 37.762285067916935, 37.859489706772528,
      37.956546599675207, 38.053451120320744, 38.1501986068469,
      38.24678436361129, 38.3432036629692, 38.439451747051464,
      38.535523829542292, 38.631415097457108, 38.727120712920438,
      38.822635814943723, 38.9179555212032, 39.013074929817677,
      39.107989121126472, 39.202693159467223, 39.297182094953705,
      39.391450965253739, 39.485494797367, 39.579308609402815,
      39.672887412358165, 39.766226211895358, 39.859320010119987,
      39.952163807358758, 40.0447526039373, 40.137081401958042,
      40.229145207078062, 40.320939030286944, 40.412457889684582,
      40.503696812259086, 40.594650835664588, 40.685315009999094,
      40.775684399582374, 40.865754084733751, 40.955519163549965,
      41.044974753683057, 41.13411599411819, 41.222938046951484,
      41.311436099167871, 41.399605364418974, 41.487441084800913,
      41.574938532632167, 41.662093012231452, 41.74889986169552,
      41.835354454677024, 41.921452202162378, 42.007188554249609,
      42.09255900192619, 42.177559078846862, 42.262184363111544,
      42.346430479043157, 42.430293098965429, 42.513767944980792,
      42.596850790748235, 42.679537463261092, 42.761823844624971,
      42.843705873835532, 42.925179548556372, 43.006240926896858,
      43.086886129190006, 43.167111339770273, 43.246912808751446,
      43.3262868538045, 43.405229861935396, 43.483738291262981,
      43.561808672796793, 43.639437612214948, 43.71662179164197,
      43.793357971426616, 43.869642991919761, 43.945473775252253,
      44.020847327112691, 44.095760738525343, 44.170211187628006,
      44.244195941449753, 44.317712357688912, 44.390757886490789,
      44.463330072225645, 44.5354265552664, 44.607045073766614,
      44.678183465438238, 44.748839669329541, 44.819011727602884,
      44.888697787312623, 44.9578961021829, 45.026605034385568,
      45.094823056317978, 45.162548752380843, 45.2297808207561,
      45.296518075184736, 45.362759446744654, 45.42850398562851,
      45.493750862921551, 45.558499372379515, 45.622748932206392,
      45.686499086832349, 45.749749508691551, 45.8125, 45.874677144190635,
      45.936429206604153, 45.997681245036, 46.058433259486165,
      46.118685249954666, 46.178437216441473, 46.237689158946608,
      46.296441077470064, 46.35469297201184, 46.412444842571944,
      46.469696689150361, 46.526448511747105, 46.582700310362178,
      46.638452084995563, 46.693703835647277, 46.748455562317311,
      46.802707265005658, 46.856458943712333, 46.909710598437336,
      46.962462229180652, 47.0147138359423, 47.066465418722267,
      47.117716977520551, 47.168468512337157, 47.218720023172089,
      47.268471510025343, 47.317722972896917, 47.366474411786811,
      47.414725826695033, 47.462477217621576, 47.509728584566432,
      47.556479927529615, 47.602731246511127, 47.648482541510951,
      47.6937338125291, 47.738485059565569, 47.782736282620377,
      47.826487481693491, 47.869738656784925, 47.912489807894687,
      47.95474093502277, 47.996492038169173, 48.037743117333896,
      48.078494172516947, 48.118745203718319, 48.158496210938011,
      48.197747194176024, 48.236498153432365, 48.274749088707019, 48.3125,
      48.349706526908683, 48.386457485008634, 48.42270871003084,
      48.45846052938866, 48.493713398501548, 48.52846789901723,
      48.562724737033825, 48.596484741322016, 48.629748861547164,
      48.66251816649153, 48.694793842276354, 48.726577190584067,
      48.757869626880392, 48.788672678636537, 48.81898798355131,
      48.848817287773329, 48.8781624441231, 48.9070254103152, 48.935408247180483,
      48.963313116888138, 48.9907422811679, 49.0176980995322, 49.0441830274983,
      49.070199614810427, 49.095750503661996, 49.120838426917665,
      49.145466206335591, 49.169636750789493, 49.193353054490835,
      49.216618195211012, 49.239435332503454, 49.26180770592579,
      49.283738633262011, 49.305231508744647, 49.326289801276864,
      49.346917052654632, 49.367116875788923, 49.386892952927795,
      49.406249033878588, 49.425188934230064, 49.443716533574587,
      49.461835773730208, 49.479550656962864, 49.496865244208557,
      49.513783653295441, 49.530310057166, 49.546448682099239,
      49.562203805932775, 49.577579756285033, 49.592580908777371,
      49.607211685256253, 49.621476552015388, 49.635380018017884,
      49.648926633118393, 49.662120986285295, 49.674967703822816,
      49.687471447593182, 49.699636913238777, 49.711468828404328,
      49.722971950959014, 49.73415106721859, 49.745010990167657,
      49.755556557681672, 49.7657926307492, 49.775724091694023,
      49.785355842397315, 49.794692802519748, 49.8037399077237,
      49.812502107895405, 49.820984365367018, 49.829191653138885,
      49.837128953101661, 49.844801254258371, 49.852213550946708,
      49.859370841061093, 49.8662781242748, 49.872940400262209,
      49.87936266692089, 49.885549918593753, 49.891507144291232,
      49.897239325913439, 49.902751436472236, 49.908048438313514,
      49.913135281339258, 49.9180169012297, 49.922698217665513,
      49.927184132549968, 49.931479528231009, 49.935589265723479,
      49.939518182931266, 49.943271092869423, 49.946852781886342,
      49.950268007885896, 49.9535214985496, 49.956617949558748,
      49.959562022816577, 49.962358344670463, 49.965011504133955,
      49.96752605110904, 49.96990649460826, 49.972157300976846,
      49.974282892114893, 49.976287643699493, 49.978175883406891,
      49.979951889134675, 49.981619887223857, 49.983184050681082,
      49.984648497400762, 49.986017288387252, 49.987294425976913,
      49.988483852060391, 49.989589446304706, 49.990615024375352,
      49.991564336158568, 49.992441063983378, 49.99324882084381,
      49.993991148621035, 49.9946715163055, 49.995293318219083,
      49.99585987223729, 49.996374418011321, 49.996840115190338,
      49.997260041643493, 49.997637191682152, 49.997974474282067,
      49.998274711305463, 49.998540635723231, 49.998774889837058,
      49.998980023501645, 49.999158492346723, 49.999312655999368,
      49.999444776306035, 49.999557015554743, 49.999651434697263,
      49.999729991571215, 49.999794539122234, 49.9998468236262,
      49.999888482911231, 49.999921044579992, 49.999945924231767,
      49.999964423684631, 49.999977729197575, 49.99998690969273,
      49.999992914977405, 49.999996573966357, 49.999998592903879,
      49.999999553585944, 49.999999911582393, 49.999999994459081, 50.0, 50.0,
      50.0, 49.999999994309114, 49.9999999091909, 49.999999541519742,
      49.999998554897552, 49.999996481492012, 49.99999272387484,
      49.999986556859994, 49.999977129341929, 49.999963466133849,
      49.999944469805925, 49.99991892252357, 49.999885487885628,
      49.999842712762671, 49.999789029135208, 49.99972275593192,
      49.999642100867931, 49.999545162283013, 49.999429930979865,
      49.999294292062324, 49.9991360267736, 49.998952814334558,
      49.998742233781925, 49.998501765806537, 49.998228794591576,
      49.997920609650834, 49.997574407666917, 49.997187294329528,
      49.996756286173664, 49.9962783124179, 49.995750216802584,
      49.995168759428132, 49.994530618593217, 49.993832392633038,
      49.993070601757566, 49.992241689889759, 49.991342026503823,
      49.990367908463455, 49.989315561860074, 49.988181143851065,
      49.986960744498013, 49.985650388604952, 49.984246037556623,
      49.98274359115667, 49.981138889465917, 49.979427714640615,
      49.977605792770653, 49.9756687957178, 49.973612342954, 49.971432003399521,
      49.969123297261284, 49.966681697871053, 49.964102633523687,
      49.9613814893154, 49.95851360898196, 49.95549429673698, 49.952318819110126,
      49.948982406785355, 49.945480256439176, 49.941807532578885,
      49.937959369380806, 49.933930872528521, 49.929717121051119,
      49.925313169161441, 49.920714048094311, 49.915914767944784,
      49.9109103195064, 49.905695676109389, 49.900265795458942,
      49.894615621473449, 49.888740086122723, 49.882634111266263,
      49.876292610491475, 49.869710490951931, 49.862882655205588,
      49.855804003053052, 49.848469433375804, 49.840873845974443,
      49.833012143406947, 49.824879232826873, 49.816470027821623,
      49.807779450250706, 49.798802432083939, 49.789533917239694,
      49.779968863423171, 49.770102243964608, 49.759929049657536,
      49.749444290597005, 49.738642998017852, 49.72752022613291,
      49.71607105397127, 49.704290587216519, 49.692173960044968,
      49.679716336963928, 49.666912914649892, 49.653758923786832,
      49.640249630904414, 49.62638034021623, 49.612146395458076,
      49.597543181726152, 49.58256612731531, 49.567210705557329,
      49.551472436659111, 49.535346889540953, 49.518829683674774,
      49.501916490922355, 49.484603037373581, 49.4668851051847,
      49.448758534416534, 49.430219224872737, 49.411263137938043,
      49.391886298416487, 49.372084796369656, 49.351854788954938,
      49.331192502263747, 49.310094233159781, 49.288556351117244,
      49.266575300059095, 49.244147600195312, 49.221269849861081,
      49.197938727355087, 49.174150992777733, 49.149903489869381,
      49.1251931478486, 49.100016983250384, 49.074372101764446,
      49.048255700073376, 49.021665067690982, 48.994597588800431,
      48.967050744092575, 48.939022112604135, 48.910509373555961,
      48.881510308191288, 48.852022801613941, 48.82204484462661,
      48.791574535569083, 48.760610082156475, 48.729149803317469,
      48.69719213103258, 48.664735612172365, 48.631778910335683,
      48.598320807687934, 48.5643602067993, 48.529896132482982,
      48.494927733633432, 48.459454285064616, 48.423475189348238,
      48.386989978651989, 48.349998316577782, 48.3125, 48.274794653003795,
      48.236544317278273, 48.197793957571079, 48.1585435738822,
      48.118793166211645, 48.078542734559413, 48.037792278925508,
      47.996541799309917, 47.954791295712653, 47.912540768133709,
      47.869790216573087, 47.826539641030784, 47.78278904150681,
      47.738538418001156, 47.693787770513822, 47.648537099044809,
      47.602786403594116, 47.556535684161751, 47.5097849407477,
      47.462534173351983, 47.41478338197458, 47.3665325666155,
      47.317781727274742, 47.268530863952307, 47.218779976648193,
      47.1685290653624, 47.117778130094926, 47.066527170845781,
      47.014776187614956, 46.962525180402451, 46.909774149208268,
      46.856523094032411, 46.802772014874876, 46.74852091173566,
      46.693769784614766, 46.638518633512192, 46.582767458427945,
      46.526516259362012, 46.469765036314406, 46.412513789285128,
      46.354762518274164, 46.296511223281527, 46.237759904307204,
      46.178508561351208, 46.11875719441354, 46.058505803494185,
      45.997754388593158, 45.936502949710444, 45.874751486846066, 45.8125,
      45.749824035721844, 45.68657420517205, 45.6228246415445,
      45.558575672252559, 45.4938277527157, 45.428581464581633,
      45.362837513948477, 45.296596729586909, 45.229860061162306,
      45.162628577456914, 45.094903464591987, 45.026686024249948,
      44.957977671896522, 44.888779935002908, 44.819094451267937,
      44.7489229668402, 44.678267334540209, 44.607129512082565,
      44.53551156029809, 44.463415641355994, 44.390844016986, 44.31779904670055,
      44.244283186016887, 44.17029898467927, 44.095849084881081,
      44.020936219487012, 43.94556321025518, 43.869732966059331,
      43.793448481110921, 43.71671283318134, 43.639529181824024,
      43.561900766596608, 43.483830905283085, 43.40532299211597,
      43.326380495998428, 43.247006958726452, 43.167205993210985,
      43.0869812817001, 43.006336574001139, 42.925275685702879,
      42.843802496397643, 42.761920947903505, 42.679635042486417,
      42.596948841082352, 42.513866461519477, 42.430392076740283,
      42.346529913023772, 42.262284248207557, 42.177659409910056,
      42.092659773752644, 42.007289761581774, 41.921553839691157,
      41.835456517043895, 41.749002343494659, 41.66219590801181,
      41.575041836899572, 41.487544792020188, 41.399709469016031,
      41.311540595531838, 41.223042929436758, 41.13422125704659,
      41.0450803913459, 40.955625170210162, 40.865860454627942,
      40.775791126923018, 40.685422088976544, 40.594758260449225,
      40.503804577003436, 40.412565988525373, 40.321047457347234,
      40.229253956469357, 40.137190467782368, 40.04486198028934,
      39.952273488327926, 39.859429989792545, 39.7663364843565,
      39.672997971694159, 39.579419449703082, 39.4856059127262,
      39.391562349773935, 39.297293742746376, 39.202805064655422,
      39.108101277846949, 39.013187332222927, 38.918068163463623,
      38.822748691249693, 38.727233817484382, 38.631528424515665,
      38.5356373733584, 38.439565501916427, 38.343317623204833, 38.246898523572,
      38.1503129609218, 38.053565662935746, 37.956661325295144,
      37.859604609903229, 37.762400143107357, 37.6650525139211,
      37.567566272246431, 37.4699459270959, 37.372195944814735,
      37.274320747303022, 37.176324710237864, 37.078212161295525,
      36.979987378373551, 36.881654587812974, 36.783217962620455,
      36.684681620690384, 36.586049623027108, 36.487325971967024,
      36.388514609400751, 36.289619414995308, 36.1906442044162,
      36.09159272754966, 35.992468666724719, 35.893275634935407,
      35.794017174062873, 35.694696753097574, 35.595317766361418,
      35.495883531729859, 35.396397288854153, 35.296862197383412,
      35.197281335186808, 35.09765769657573, 34.997994190525887,
      34.898293638899524, 34.798558774667541, 34.698792240131624,
      34.598996585146452, 34.499174265341779, 34.399327640344666,
      34.299458972001581, 34.199570422600544, 34.099664053093306,
      33.9997418213175, 33.899805580218782, 33.799857076072975,
      33.699897946708262, 33.599929719727271, 33.499953810729295,
      33.399971521532407, 33.299984038395607, 33.199992430241, 33.09999764687592,
      33.000000517215128, 32.900001747502884, 32.800001919535205,
      32.7000014888819, 32.60000078310884, 32.5, 32.400117508813153,
      32.3001167201634, 32.20011593151365, 32.1001151428639, 32.000114354214148,
      31.900113565564393, 31.800112776914641, 31.700111988264887,
      31.600111199615135, 31.500110410965384, 31.400109622315629,
      31.300108833665877, 31.200108045016123, 31.100107256366371,
      31.00010646771662, 30.900105679066865, 30.800104890417114,
      30.700104101767359, 30.600103313117607, 30.500102524467856,
      30.4001017358181, 30.30010094716835, 30.200100158518598,
      30.100099369868843, 30.000098581219092, 29.900097792569337,
      29.800097003919586, 29.700096215269834, 29.600095426620079,
      29.500094637970328, 29.400093849320573, 29.300093060670822,
      29.20009227202107, 29.100091483371315, 29.000090694721564,
      28.900089906071813, 28.800089117422058, 28.700088328772306,
      28.600087540122551, 28.5000867514728, 28.400085962823049,
      28.300085174173294, 28.200084385523542, 28.100083596873787,
      28.000082808224036, 27.900082019574285, 27.80008123092453,
      27.700080442274778, 27.600079653625023, 27.500078864975272,
      27.400078076325521, 27.300077287675766, 27.200076499026014,
      27.10007571037626, 27.000074921726508, 26.900074133076757,
      26.800073344427002, 26.70007255577725, 26.600071767127496,
      26.500070978477744, 26.400070189827993, 26.300069401178238,
      26.200068612528487, 26.100067823878732, 26.00006703522898,
      25.900066246579229, 25.800065457929474, 25.700064669279723,
      25.600063880629971, 25.500063091980216, 25.400062303330465,
      25.30006151468071, 25.200060726030959, 25.100059937381204,
      25.000059148731452, 24.9000583600817, 24.80005757143195,
      24.700056782782195, 24.60005599413244, 24.500055205482688,
      24.400054416832937, 24.300053628183186, 24.200052839533431,
      24.100052050883676, 24.000051262233924, 23.900050473584173,
      23.800049684934422, 23.700048896284667, 23.600048107634915,
      23.50004731898516, 23.400046530335409, 23.300045741685658,
      23.200044953035903, 23.100044164386151, 23.000043375736396,
      22.900042587086645, 22.800041798436894, 22.700041009787142,
      22.600040221137387, 22.500039432487632, 22.400038643837881,
      22.30003785518813, 22.200037066538375, 22.10003627788862,
      22.000035489238869, 21.900034700589117, 21.800033911939366,
      21.700033123289614, 21.600032334639859, 21.500031545990105,
      21.400030757340353, 21.300029968690602, 21.200029180040847,
      21.100028391391096, 21.000027602741341, 20.900026814091589,
      20.800026025441838, 20.700025236792087, 20.600024448142332,
      20.500023659492577, 20.400022870842825, 20.300022082193074,
      20.200021293543319, 20.100020504893568, 20.00001971624382,
      19.900018927594061, 19.80001813894431, 19.700017350294555,
      19.600016561644804, 19.500015772995052, 19.400014984345297,
      19.300014195695546, 19.200013407045791, 19.10001261839604,
      19.000011829746288, 18.900011041096533, 18.800010252446782,
      18.700009463797031, 18.600008675147276, 18.500007886497524,
      18.400007097847769, 18.300006309198018, 18.200005520548267,
      18.100004731898508, 18.000003943248757, 17.900003154599005,
      17.800002365949254, 17.700001577299503, 17.600000788649751, 17.5,
      17.400117514327917, 17.30011680837228, 17.20011637722542,
      17.10011654830069, 17.000117777017572, 16.900120645023776,
      16.800125858417417, 16.700134245969181, 16.600146757344433,
      16.500164461325426, 16.400188544033419, 16.300220307150823,
      16.200261166143363, 16.100312648482259, 16.000376391866304,
      15.900454142444126, 15.800547753036227, 15.700659181357196,
      15.60079048823787, 15.500943835847437, 15.401121485915645,
      15.301325797954917, 15.201559227482527, 15.101824324242692,
      15.002123730428814, 14.902460178905578, 14.80283649143113,
      14.703255576879172, 14.603720429461198, 14.504234126948575,
      14.404799828894745, 14.305420774857346, 14.206100282620362,
      14.106841746416322, 14.007648635148378, 13.908524490612528,
      13.809472925719724, 13.71049762271803, 13.611602331414787,
      13.512790867398756, 13.414067110262295, 13.315435001823467,
      13.216898544348204, 13.1184617987725, 13.02012888292451,
      12.921903969746737, 12.823791285518169, 12.725795108076426,
      12.627919765039934, 12.530169632030052, 12.432549130893236,
      12.335062727923209, 12.237714932083065, 12.140510293227472,
      12.043453400324793, 11.946548879679256, 11.8498013931531,
      11.75321563638871, 11.656796337030798, 11.560548252948536,
      11.464476170457708, 11.368584902542892, 11.272879287079562,
      11.177364185056277, 11.082044478796803, 10.986925070182323,
      10.892010878873528, 10.797306840532777, 10.702817905046295,
      10.608549034746261, 10.514505202633003, 10.420691390597185,
      10.327112587641835, 10.233773788104642, 10.140679989880013,
      10.047836192641242, 9.9552473960627026, 9.8629185980419578,
      9.7708547929219378, 9.6790609697130563, 9.5875421103154181,
      9.4963031877409136, 9.4053491643354121, 9.3146849900009059,
      9.2243156004176257, 9.1342459152662485, 9.0444808364500346,
      8.9550252463169429, 8.86588400588181, 8.7770619530485163, 8.68856390083213,
      8.6003946355810257, 8.5125589151990866, 8.4250614673678328,
      8.3379069877685481, 8.25110013830448, 8.1646455453229763,
      8.0785477978376221, 7.9928114457503909, 7.90744099807381,
      7.822440921153138, 7.7378156368884561, 7.6535695209568431,
      7.5697069010345714, 7.4862320550192081, 7.4031492092517652,
      7.3204625367389085, 7.2381761553750295, 7.1562941261644681,
      7.0748204514436281, 6.993759073103142, 6.913113870809994,
      6.8328886602297274, 6.7530871912485537, 6.673713146195503,
      6.5947701380646038, 6.5162617087370194, 6.4381913272032065,
      6.3605623877850519, 6.28337820835803, 6.2066420285733841,
      6.1303570080802388, 6.0545262247477467, 5.9791526728873094,
      5.9042392614746575, 5.8297888123719943, 5.7558040585502468,
      5.6822876423110884, 5.609242113509211, 5.536669927774355,
      5.4645734447336025, 5.3929549262333865, 5.3218165345617621,
      5.2511603306704586, 5.1809882723971157, 5.1113022126873773,
      5.0421038978171, 4.9733949656144318, 4.9051769436820223,
      4.8374512476191569, 4.7702191792439024, 4.7034819248152644,
      4.6372405532553458, 4.5714960143714904, 4.5062491370784485,
      4.4415006276204849, 4.3772510677936083, 4.3135009131676512,
      4.2502504913084493, 4.1875, 4.1253228558093653, 4.0635707933958471,
      4.0023187549640014, 3.941566740513835, 3.881314750045334,
      3.8215627835585266, 3.7623108410533916, 3.7035589225299361,
      3.64530702798816, 3.5875551574280564, 3.5303033108496393,
      3.4735514882528946, 3.4172996896378223, 3.3615479150044365,
      3.3062961643527231, 3.2515444376826892, 3.1972927349943419,
      3.1435410562876669, 3.0902894015626643, 3.0375377708193483,
      2.9852861640576975, 2.9335345812777334, 2.8822830224794487,
      2.8315314876628435, 2.7812799768279106, 2.7315284899746572,
      2.6822770271030834, 2.6335255882131889, 2.5852741733049669,
      2.5375227823784243, 2.4902714154335683, 2.4435200724703847,
      2.3972687534888735, 2.3515174584890488, 2.3062661874708965,
      2.2615149404344308, 2.2172637173796232, 2.1735125183065094,
      2.130261343215075, 2.087510192105313, 2.0452590649772304,
      2.0035079618308274, 1.9622568826661038, 1.9215058274830525,
      1.8812547962816808, 1.8415037890619885, 1.8022528058239757,
      1.7635018465676353, 1.7252509112929815, 1.6875, 1.6502934730913168,
      1.6135425149913658, 1.5772912899691605, 1.5415394706113403,
      1.5062866014984522, 1.4715321009827704, 1.4372752629661747,
      1.4035152586779844, 1.3702511384528364, 1.3374818335084697,
      1.3052061577236458, 1.2734228094159334, 1.2421303731196076,
      1.2113273213634628, 1.1810120164486904, 1.1511827122266709,
      1.1218375558769011, 1.0929745896848004, 1.064591752819517,
      1.0366868831118623, 1.009257718832103, 0.98230190046780308,
      0.955816972501701, 0.92980038518957286, 0.90424949633800367,
      0.87916157308233522, 0.85453379366440885, 0.83036324921050664,
      0.80664694550916494, 0.78338180478898778, 0.76056466749654561,
      0.73819229407421, 0.71626136673798868, 0.69476849125535267,
      0.67371019872313553, 0.65308294734536787, 0.63288312421107662,
      0.61310704707220509, 0.5937509661214122, 0.57481106576993568,
      0.5562834664254126, 0.53816422626979232, 0.52044934303713575,
      0.503134755791443, 0.48621634670455904, 0.46968994283400178,
      0.45355131790076086, 0.43779619406722503, 0.42242024371496711,
      0.40741909122262854, 0.392788314743747, 0.37852344798461246,
      0.36461998198211631, 0.35107336688160728, 0.33787901371470497,
      0.32503229617718432, 0.31252855240681754, 0.30036308676122303,
      0.28853117159567176, 0.277028049040986, 0.26584893278140953,
      0.25498900983234307, 0.24444344231832815, 0.23420736925079666,
      0.22427590830597666, 0.21464415760268452, 0.20530719748025206,
      0.19626009227629737, 0.18749789210459511, 0.17901563463298231,
      0.170808346861115, 0.16287104689833853, 0.15519874574162884,
      0.1477864490532923, 0.14062915893890704, 0.13372187572520033,
      0.12705959973779102, 0.12063733307910951, 0.1144500814062468,
      0.10849285570876788, 0.10276067408656075, 0.097248563527763565,
      0.091951561686485661, 0.086864718660741858, 0.08198309877030141,
      0.077301782334487257, 0.0728158674500321, 0.068520471768991342,
      0.064410734276521, 0.06048181706873379, 0.056728907130576545,
      0.053147218113657857, 0.049731992114104173, 0.046478501450401666,
      0.043382050441252318, 0.0404379771834229, 0.037641655329537116,
      0.034988495866045355, 0.03247394889096, 0.030093505391739939,
      0.027842699023153727, 0.025717107885107282, 0.023712356300507054,
      0.021824116593109011, 0.020048110865324986, 0.01838011277614271,
      0.016815949318917944, 0.015351502599237676, 0.013982711612747778,
      0.012705574023087252, 0.011516147939609311, 0.010410553695294311,
      0.0093849756246484617, 0.0084356638414320173, 0.0075589360166219421,
      0.0067511791561898349, 0.0060088513789651188, 0.0053284836944982317,
      0.0047066817809167105, 0.0041401277627102218, 0.0036255819886790164,
      0.0031598848096621168, 0.0027399583565070884, 0.0023628083178479642,
      0.0020255257179329078, 0.0017252886945371415, 0.0014593642767692927,
      0.0012251101629416894, 0.0010199764983553905, 0.00084150765327706267,
      0.00068734400063164, 0.00055522369396499016, 0.00044298444525736613,
      0.00034856530273685848, 0.0002700084287852178, 0.00020546087776551758,
      0.00015317637380007909, 0.00011151708876866451, 7.8955420008242072E-5,
      5.4075768233019517E-5, 3.5576315369212352E-5, 2.2270802425339298E-5,
      1.309030727014715E-5, 7.0850225952767687E-6, 3.426033643449955E-6,
      1.4070961213974442E-6, 4.4641405594347816E-7, 8.8417607457813574E-8,
      5.5409188348676253E-9, 0.0 } ;

    run_q1_test_DW.FromWorkspace2_PWORK.TimePtr = (void *) pTimeValues0;
    run_q1_test_DW.FromWorkspace2_PWORK.DataPtr = (void *) pDataValues0;
    run_q1_test_DW.FromWorkspace2_IWORK.PrevIndex = 0;
  }

  /* InitializeConditions for DiscreteIntegrator: '<Root>/Discrete-Time Integrator' */
  run_q1_test_DW.DiscreteTimeIntegrator_DSTATE =
    run_q1_test_P.DiscreteTimeIntegrator_IC;

  /* InitializeConditions for UnitDelay: '<S1>/UD' */
  run_q1_test_DW.UD_DSTATE = run_q1_test_P.DiscreteDerivative_ICPrevScaled;

  /* InitializeConditions for DiscreteTransferFcn: '<Root>/Discrete Transfer Fcn' */
  run_q1_test_DW.DiscreteTransferFcn_states =
    run_q1_test_P.DiscreteTransferFcn_InitialStat;
}

/* Model terminate function */
void run_q1_test_terminate(void)
{
  /* Terminate for S-Function (hil_initialize_block): '<S2>/HIL Initialize' */

  /* S-Function Block: run_q1_test/Plant/HIL Initialize (hil_initialize_block) */
  {
    t_boolean is_switching;
    t_int result;
    t_uint32 num_final_analog_outputs = 0;
    hil_task_stop_all(run_q1_test_DW.HILInitialize_Card);
    hil_monitor_stop_all(run_q1_test_DW.HILInitialize_Card);
    is_switching = false;
    if ((run_q1_test_P.HILInitialize_AOTerminate && !is_switching) ||
        (run_q1_test_P.HILInitialize_AOExit && is_switching)) {
      run_q1_test_DW.HILInitialize_AOVoltages[0] =
        run_q1_test_P.HILInitialize_AOFinal;
      run_q1_test_DW.HILInitialize_AOVoltages[1] =
        run_q1_test_P.HILInitialize_AOFinal;
      num_final_analog_outputs = 2U;
    } else {
      num_final_analog_outputs = 0;
    }

    if (num_final_analog_outputs > 0) {
      result = hil_write_analog(run_q1_test_DW.HILInitialize_Card,
        run_q1_test_P.HILInitialize_AOChannels, num_final_analog_outputs,
        &run_q1_test_DW.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(run_q1_test_M, _rt_error_message);
      }
    }

    hil_task_delete_all(run_q1_test_DW.HILInitialize_Card);
    hil_monitor_delete_all(run_q1_test_DW.HILInitialize_Card);
    hil_close(run_q1_test_DW.HILInitialize_Card);
    run_q1_test_DW.HILInitialize_Card = NULL;
  }
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  run_q1_test_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  run_q1_test_update();
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
  run_q1_test_initialize();
}

void MdlTerminate(void)
{
  run_q1_test_terminate();
}

/* Registration function */
RT_MODEL_run_q1_test_T *run_q1_test(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)run_q1_test_M, 0,
                sizeof(RT_MODEL_run_q1_test_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&run_q1_test_M->solverInfo,
                          &run_q1_test_M->Timing.simTimeStep);
    rtsiSetTPtr(&run_q1_test_M->solverInfo, &rtmGetTPtr(run_q1_test_M));
    rtsiSetStepSizePtr(&run_q1_test_M->solverInfo,
                       &run_q1_test_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&run_q1_test_M->solverInfo, (&rtmGetErrorStatus
      (run_q1_test_M)));
    rtsiSetRTModelPtr(&run_q1_test_M->solverInfo, run_q1_test_M);
  }

  rtsiSetSimTimeStep(&run_q1_test_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&run_q1_test_M->solverInfo,"FixedStepDiscrete");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = run_q1_test_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;

    /* polyspace +2 MISRA2012:D4.1 [Justified:Low] "run_q1_test_M points to
       static memory which is guaranteed to be non-NULL" */
    run_q1_test_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    run_q1_test_M->Timing.sampleTimes = (&run_q1_test_M->
      Timing.sampleTimesArray[0]);
    run_q1_test_M->Timing.offsetTimes = (&run_q1_test_M->
      Timing.offsetTimesArray[0]);

    /* task periods */
    run_q1_test_M->Timing.sampleTimes[0] = (0.0);
    run_q1_test_M->Timing.sampleTimes[1] = (0.001);

    /* task offsets */
    run_q1_test_M->Timing.offsetTimes[0] = (0.0);
    run_q1_test_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(run_q1_test_M, &run_q1_test_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = run_q1_test_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    run_q1_test_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(run_q1_test_M, 1.712);
  run_q1_test_M->Timing.stepSize0 = 0.001;
  run_q1_test_M->Timing.stepSize1 = 0.001;

  /* External mode info */
  run_q1_test_M->Sizes.checksums[0] = (913789187U);
  run_q1_test_M->Sizes.checksums[1] = (1825507272U);
  run_q1_test_M->Sizes.checksums[2] = (91693786U);
  run_q1_test_M->Sizes.checksums[3] = (393460248U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    run_q1_test_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(run_q1_test_M->extModeInfo,
      &run_q1_test_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(run_q1_test_M->extModeInfo,
                        run_q1_test_M->Sizes.checksums);
    rteiSetTPtr(run_q1_test_M->extModeInfo, rtmGetTPtr(run_q1_test_M));
  }

  run_q1_test_M->solverInfoPtr = (&run_q1_test_M->solverInfo);
  run_q1_test_M->Timing.stepSize = (0.001);
  rtsiSetFixedStepSize(&run_q1_test_M->solverInfo, 0.001);
  rtsiSetSolverMode(&run_q1_test_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  run_q1_test_M->blockIO = ((void *) &run_q1_test_B);
  (void) memset(((void *) &run_q1_test_B), 0,
                sizeof(B_run_q1_test_T));

  /* parameters */
  run_q1_test_M->defaultParam = ((real_T *)&run_q1_test_P);

  /* states (dwork) */
  run_q1_test_M->dwork = ((void *) &run_q1_test_DW);
  (void) memset((void *)&run_q1_test_DW, 0,
                sizeof(DW_run_q1_test_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    run_q1_test_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 19;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Initialize Sizes */
  run_q1_test_M->Sizes.numContStates = (0);/* Number of continuous states */
  run_q1_test_M->Sizes.numY = (0);     /* Number of model outputs */
  run_q1_test_M->Sizes.numU = (0);     /* Number of model inputs */
  run_q1_test_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  run_q1_test_M->Sizes.numSampTimes = (2);/* Number of sample times */
  run_q1_test_M->Sizes.numBlocks = (26);/* Number of blocks */
  run_q1_test_M->Sizes.numBlockIO = (12);/* Number of block outputs */
  run_q1_test_M->Sizes.numBlockPrms = (86);/* Sum of parameter "widths" */
  return run_q1_test_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
