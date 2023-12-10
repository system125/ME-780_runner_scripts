/*
 * K_control.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "K_control".
 *
 * Model version              : 1.45
 * Simulink Coder version : 9.6 (R2021b) 14-May-2021
 * C source code generated on : Sat Dec  9 23:55:15 2023
 *
 * Target selection: quarc_win64.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "K_control.h"
#include "K_control_private.h"
#include "K_control_dt.h"

/* Block signals (default storage) */
B_K_control_T K_control_B;

/* Block states (default storage) */
DW_K_control_T K_control_DW;

/* Real-time model */
static RT_MODEL_K_control_T K_control_M_;
RT_MODEL_K_control_T *const K_control_M = &K_control_M_;

/* Model output function */
void K_control_output(void)
{
  /* local block i/o variables */
  real_T rtb_FromWorkspace;
  real_T rtb_InverseModulus1;
  real_T rtb_Diff_e;
  real_T rtb_Sum;

  /* S-Function (hil_read_encoder_block): '<S3>/HIL Read Encoder1' */

  /* S-Function Block: K_control/Plant/HIL Read Encoder1 (hil_read_encoder_block) */
  {
    t_error result = hil_read_encoder(K_control_DW.HILInitialize_Card,
      &K_control_P.HILReadEncoder1_channels, 1,
      &K_control_DW.HILReadEncoder1_Buffer);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(K_control_M, _rt_error_message);
    } else {
      rtb_Diff_e = K_control_DW.HILReadEncoder1_Buffer;
    }
  }

  /* Gain: '<S3>/mm//cn' */
  K_control_B.mmcn = K_control_P.mmcn_Gain * rtb_Diff_e;

  /* S-Function (inverse_modulus_block): '<S3>/Inverse Modulus' */
  /* S-Function Block: K_control/Plant/Inverse Modulus (inverse_modulus_block) */
  {
    static const real_T sampling_period = 0.001;
    real_T half_range = K_control_P.InverseModulus_Modulus / 2.0;
    real_T du, dy;
    if (K_control_DW.InverseModulus_FirstSample) {
      K_control_DW.InverseModulus_FirstSample = false;
      K_control_DW.InverseModulus_PreviousInput = K_control_B.mmcn;
    }

    du = (real_T) K_control_B.mmcn - K_control_DW.InverseModulus_PreviousInput;
    if (du > half_range) {
      K_control_DW.InverseModulus_Revolutions =
        K_control_DW.InverseModulus_Revolutions - 1;
      dy = du - K_control_P.InverseModulus_Modulus;
    } else if (du < -half_range) {
      K_control_DW.InverseModulus_Revolutions =
        K_control_DW.InverseModulus_Revolutions + 1;
      dy = du + K_control_P.InverseModulus_Modulus;
    } else {
      dy = du;
    }

    K_control_B.InverseModulus = K_control_B.mmcn +
      K_control_DW.InverseModulus_Revolutions *
      K_control_P.InverseModulus_Modulus;
    K_control_DW.InverseModulus_PreviousInput = K_control_B.mmcn;
  }

  /* S-Function (hil_read_encoder_block): '<S3>/HIL Read Encoder 2' */

  /* S-Function Block: K_control/Plant/HIL Read Encoder 2 (hil_read_encoder_block) */
  {
    t_error result = hil_read_encoder(K_control_DW.HILInitialize_Card,
      &K_control_P.HILReadEncoder2_channels, 1,
      &K_control_DW.HILReadEncoder2_Buffer);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(K_control_M, _rt_error_message);
    } else {
      rtb_Diff_e = K_control_DW.HILReadEncoder2_Buffer;
    }
  }

  /* Gain: '<S3>/mm//cn - 2' */
  K_control_B.mmcn2 = K_control_P.mmcn2_Gain * rtb_Diff_e;

  /* S-Function (inverse_modulus_block): '<S3>/Inverse Modulus1' */
  /* S-Function Block: K_control/Plant/Inverse Modulus1 (inverse_modulus_block) */
  {
    static const real_T sampling_period = 0.001;
    real_T half_range = K_control_P.InverseModulus1_Modulus / 2.0;
    real_T du, dy;
    if (K_control_DW.InverseModulus1_FirstSample) {
      K_control_DW.InverseModulus1_FirstSample = false;
      K_control_DW.InverseModulus1_PreviousInput = K_control_B.mmcn2;
    }

    du = (real_T) K_control_B.mmcn2 - K_control_DW.InverseModulus1_PreviousInput;
    if (du > half_range) {
      K_control_DW.InverseModulus1_Revolutions =
        K_control_DW.InverseModulus1_Revolutions - 1;
      dy = du - K_control_P.InverseModulus1_Modulus;
    } else if (du < -half_range) {
      K_control_DW.InverseModulus1_Revolutions =
        K_control_DW.InverseModulus1_Revolutions + 1;
      dy = du + K_control_P.InverseModulus1_Modulus;
    } else {
      dy = du;
    }

    rtb_InverseModulus1 = K_control_B.mmcn2 +
      K_control_DW.InverseModulus1_Revolutions *
      K_control_P.InverseModulus1_Modulus;
    K_control_DW.InverseModulus1_PreviousInput = K_control_B.mmcn2;
  }

  /* Sin: '<Root>/Sine Wave' */
  K_control_B.SineWave = sin(K_control_P.SineWave_Freq * K_control_M->Timing.t[0]
    + K_control_P.SineWave_Phase) * K_control_P.SineWave_Amp +
    K_control_P.SineWave_Bias;

  /* Sum: '<Root>/Sum' */
  rtb_Sum = K_control_B.SineWave - K_control_B.InverseModulus;

  /* DiscreteIntegrator: '<Root>/Discrete-Time Integrator' */
  K_control_B.DiscreteTimeIntegrator =
    K_control_DW.DiscreteTimeIntegrator_DSTATE;

  /* Gain: '<Root>/Gain2' */
  K_control_B.Gain2 = K_control_P.Kd * rtb_Sum;

  /* SampleTimeMath: '<S1>/TSamp'
   *
   * About '<S1>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  K_control_B.TSamp = K_control_B.Gain2 * K_control_P.TSamp_WtEt;

  /* DiscreteTransferFcn: '<Root>/Discrete Transfer Fcn' incorporates:
   *  Sum: '<S1>/Diff'
   *  UnitDelay: '<S1>/UD'
   */
  K_control_DW.DiscreteTransferFcn_tmp = ((K_control_B.TSamp -
    K_control_DW.UD_DSTATE) - K_control_P.DiscreteTransferFcn_DenCoef[1] *
    K_control_DW.DiscreteTransferFcn_states) /
    K_control_P.DiscreteTransferFcn_DenCoef[0];

  /* DiscreteTransferFcn: '<Root>/Discrete Transfer Fcn' */
  K_control_B.DiscreteTransferFcn = K_control_P.DiscreteTransferFcn_NumCoef[0] *
    K_control_DW.DiscreteTransferFcn_tmp +
    K_control_P.DiscreteTransferFcn_NumCoef[1] *
    K_control_DW.DiscreteTransferFcn_states;

  /* Sum: '<Root>/Sum1' incorporates:
   *  Gain: '<Root>/Gain'
   */
  K_control_B.Sum1 = (K_control_P.Kp * rtb_Sum +
                      K_control_B.DiscreteTimeIntegrator) +
    K_control_B.DiscreteTransferFcn;

  /* FromWorkspace: '<Root>/From Workspace' */
  {
    real_T *pDataValues = (real_T *) K_control_DW.FromWorkspace_PWORK.DataPtr;
    real_T *pTimeValues = (real_T *) K_control_DW.FromWorkspace_PWORK.TimePtr;
    int_T currTimeIndex = K_control_DW.FromWorkspace_IWORK.PrevIndex;
    real_T t = K_control_M->Timing.t[0];

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

    K_control_DW.FromWorkspace_IWORK.PrevIndex = currTimeIndex;

    /* Post output */
    {
      real_T t1 = pTimeValues[currTimeIndex];
      real_T t2 = pTimeValues[currTimeIndex + 1];
      if (t1 == t2) {
        if (t < t1) {
          rtb_FromWorkspace = pDataValues[currTimeIndex];
        } else {
          rtb_FromWorkspace = pDataValues[currTimeIndex + 1];
        }
      } else {
        real_T f1 = (t2 - t) / (t2 - t1);
        real_T f2 = 1.0 - f1;
        real_T d1;
        real_T d2;
        int_T TimeIndex = currTimeIndex;
        d1 = pDataValues[TimeIndex];
        d2 = pDataValues[TimeIndex + 1];
        rtb_FromWorkspace = (real_T) rtInterpolate(d1, d2, f1, f2);
        pDataValues += 1701;
      }
    }
  }

  /* Sum: '<Root>/Sum3' */
  K_control_B.Sum3 = K_control_B.Sum1 + rtb_FromWorkspace;

  /* Sum: '<S5>/Diff' incorporates:
   *  ZeroOrderHold: '<Root>/Zero-Order Hold'
   */
  rtb_Diff_e = K_control_B.Sum3;

  /* Saturate: '<Root>/Saturation' */
  if (rtb_Diff_e > K_control_P.Saturation_UpperSat) {
    /* Saturate: '<Root>/Saturation' */
    K_control_B.Saturation = K_control_P.Saturation_UpperSat;
  } else if (rtb_Diff_e < K_control_P.Saturation_LowerSat) {
    /* Saturate: '<Root>/Saturation' */
    K_control_B.Saturation = K_control_P.Saturation_LowerSat;
  } else {
    /* Saturate: '<Root>/Saturation' */
    K_control_B.Saturation = rtb_Diff_e;
  }

  /* End of Saturate: '<Root>/Saturation' */

  /* Sum: '<S5>/Diff' incorporates:
   *  Gain: '<S3>/Cable Gain'
   */
  rtb_Diff_e = K_control_P.CableGain_Gain * K_control_B.Saturation;

  /* S-Function (hil_write_analog_block): '<S3>/HIL Write Analog' */

  /* S-Function Block: K_control/Plant/HIL Write Analog (hil_write_analog_block) */
  {
    t_error result;
    result = hil_write_analog(K_control_DW.HILInitialize_Card,
      &K_control_P.HILWriteAnalog_channels, 1, &rtb_Diff_e);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(K_control_M, _rt_error_message);
    }
  }

  /* SampleTimeMath: '<S5>/TSamp'
   *
   * About '<S5>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  K_control_B.TSamp_i = K_control_B.SineWave * K_control_P.TSamp_WtEt_i;

  /* Sum: '<S5>/Diff' incorporates:
   *  UnitDelay: '<S5>/UD'
   */
  rtb_Diff_e = K_control_B.TSamp_i - K_control_DW.UD_DSTATE_c;

  /* SampleTimeMath: '<S2>/TSamp'
   *
   * About '<S2>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  K_control_B.TSamp_g = rtb_Diff_e * K_control_P.TSamp_WtEt_o;

  /* Sum: '<Root>/Sum2' incorporates:
   *  Gain: '<Root>/Gain3'
   *  Gain: '<Root>/Gain4'
   *  Sum: '<S2>/Diff'
   *  UnitDelay: '<S2>/UD'
   */
  K_control_B.Sum2 = (K_control_B.TSamp_g - K_control_DW.UD_DSTATE_i) *
    K_control_P.k_acc + K_control_P.k_vel * rtb_Diff_e;

  /* Gain: '<Root>/Gain1' */
  K_control_B.Gain1 = K_control_P.Gain1_Gain * rtb_Sum;
}

/* Model update function */
void K_control_update(void)
{
  /* Update for DiscreteIntegrator: '<Root>/Discrete-Time Integrator' */
  K_control_DW.DiscreteTimeIntegrator_DSTATE +=
    K_control_P.DiscreteTimeIntegrator_gainval * K_control_B.Gain1;

  /* Update for UnitDelay: '<S1>/UD' */
  K_control_DW.UD_DSTATE = K_control_B.TSamp;

  /* Update for DiscreteTransferFcn: '<Root>/Discrete Transfer Fcn' */
  K_control_DW.DiscreteTransferFcn_states = K_control_DW.DiscreteTransferFcn_tmp;

  /* Update for UnitDelay: '<S5>/UD' */
  K_control_DW.UD_DSTATE_c = K_control_B.TSamp_i;

  /* Update for UnitDelay: '<S2>/UD' */
  K_control_DW.UD_DSTATE_i = K_control_B.TSamp_g;

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++K_control_M->Timing.clockTick0)) {
    ++K_control_M->Timing.clockTickH0;
  }

  K_control_M->Timing.t[0] = K_control_M->Timing.clockTick0 *
    K_control_M->Timing.stepSize0 + K_control_M->Timing.clockTickH0 *
    K_control_M->Timing.stepSize0 * 4294967296.0;

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
    if (!(++K_control_M->Timing.clockTick1)) {
      ++K_control_M->Timing.clockTickH1;
    }

    K_control_M->Timing.t[1] = K_control_M->Timing.clockTick1 *
      K_control_M->Timing.stepSize1 + K_control_M->Timing.clockTickH1 *
      K_control_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Model initialize function */
void K_control_initialize(void)
{
  /* Start for S-Function (hil_initialize_block): '<S3>/HIL Initialize' */

  /* S-Function Block: K_control/Plant/HIL Initialize (hil_initialize_block) */
  {
    t_int result;
    t_boolean is_switching;
    result = hil_open("q2_usb", "0", &K_control_DW.HILInitialize_Card);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(K_control_M, _rt_error_message);
      return;
    }

    is_switching = false;
    result = hil_set_card_specific_options(K_control_DW.HILInitialize_Card,
      "d0=digital;d1=digital;led=auto;update_rate=normal;decimation=1", 63);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(K_control_M, _rt_error_message);
      return;
    }

    result = hil_watchdog_clear(K_control_DW.HILInitialize_Card);
    if (result < 0 && result != -QERR_HIL_WATCHDOG_CLEAR) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(K_control_M, _rt_error_message);
      return;
    }

    if ((K_control_P.HILInitialize_AIPStart && !is_switching) ||
        (K_control_P.HILInitialize_AIPEnter && is_switching)) {
      K_control_DW.HILInitialize_AIMinimums[0] =
        (K_control_P.HILInitialize_AILow);
      K_control_DW.HILInitialize_AIMinimums[1] =
        (K_control_P.HILInitialize_AILow);
      K_control_DW.HILInitialize_AIMaximums[0] =
        K_control_P.HILInitialize_AIHigh;
      K_control_DW.HILInitialize_AIMaximums[1] =
        K_control_P.HILInitialize_AIHigh;
      result = hil_set_analog_input_ranges(K_control_DW.HILInitialize_Card,
        K_control_P.HILInitialize_AIChannels, 2U,
        &K_control_DW.HILInitialize_AIMinimums[0],
        &K_control_DW.HILInitialize_AIMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(K_control_M, _rt_error_message);
        return;
      }
    }

    if ((K_control_P.HILInitialize_AOPStart && !is_switching) ||
        (K_control_P.HILInitialize_AOPEnter && is_switching)) {
      K_control_DW.HILInitialize_AOMinimums[0] =
        (K_control_P.HILInitialize_AOLow);
      K_control_DW.HILInitialize_AOMinimums[1] =
        (K_control_P.HILInitialize_AOLow);
      K_control_DW.HILInitialize_AOMaximums[0] =
        K_control_P.HILInitialize_AOHigh;
      K_control_DW.HILInitialize_AOMaximums[1] =
        K_control_P.HILInitialize_AOHigh;
      result = hil_set_analog_output_ranges(K_control_DW.HILInitialize_Card,
        K_control_P.HILInitialize_AOChannels, 2U,
        &K_control_DW.HILInitialize_AOMinimums[0],
        &K_control_DW.HILInitialize_AOMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(K_control_M, _rt_error_message);
        return;
      }
    }

    if ((K_control_P.HILInitialize_AOStart && !is_switching) ||
        (K_control_P.HILInitialize_AOEnter && is_switching)) {
      K_control_DW.HILInitialize_AOVoltages[0] =
        K_control_P.HILInitialize_AOInitial;
      K_control_DW.HILInitialize_AOVoltages[1] =
        K_control_P.HILInitialize_AOInitial;
      result = hil_write_analog(K_control_DW.HILInitialize_Card,
        K_control_P.HILInitialize_AOChannels, 2U,
        &K_control_DW.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(K_control_M, _rt_error_message);
        return;
      }
    }

    if (K_control_P.HILInitialize_AOReset) {
      K_control_DW.HILInitialize_AOVoltages[0] =
        K_control_P.HILInitialize_AOWatchdog;
      K_control_DW.HILInitialize_AOVoltages[1] =
        K_control_P.HILInitialize_AOWatchdog;
      result = hil_watchdog_set_analog_expiration_state
        (K_control_DW.HILInitialize_Card, K_control_P.HILInitialize_AOChannels,
         2U, &K_control_DW.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(K_control_M, _rt_error_message);
        return;
      }
    }

    if ((K_control_P.HILInitialize_EIPStart && !is_switching) ||
        (K_control_P.HILInitialize_EIPEnter && is_switching)) {
      K_control_DW.HILInitialize_QuadratureModes[0] =
        K_control_P.HILInitialize_EIQuadrature;
      K_control_DW.HILInitialize_QuadratureModes[1] =
        K_control_P.HILInitialize_EIQuadrature;
      result = hil_set_encoder_quadrature_mode(K_control_DW.HILInitialize_Card,
        K_control_P.HILInitialize_EIChannels, 2U, (t_encoder_quadrature_mode *)
        &K_control_DW.HILInitialize_QuadratureModes[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(K_control_M, _rt_error_message);
        return;
      }
    }

    if ((K_control_P.HILInitialize_EIStart && !is_switching) ||
        (K_control_P.HILInitialize_EIEnter && is_switching)) {
      K_control_DW.HILInitialize_InitialEICounts[0] =
        K_control_P.HILInitialize_EIInitial;
      K_control_DW.HILInitialize_InitialEICounts[1] =
        K_control_P.HILInitialize_EIInitial;
      result = hil_set_encoder_counts(K_control_DW.HILInitialize_Card,
        K_control_P.HILInitialize_EIChannels, 2U,
        &K_control_DW.HILInitialize_InitialEICounts[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(K_control_M, _rt_error_message);
        return;
      }
    }
  }

  /* Start for S-Function (inverse_modulus_block): '<S3>/Inverse Modulus' */

  /* S-Function Block: K_control/Plant/Inverse Modulus (inverse_modulus_block) */
  {
    K_control_DW.InverseModulus_FirstSample = true;
    K_control_DW.InverseModulus_Revolutions = 0;
  }

  /* Start for S-Function (inverse_modulus_block): '<S3>/Inverse Modulus1' */

  /* S-Function Block: K_control/Plant/Inverse Modulus1 (inverse_modulus_block) */
  {
    K_control_DW.InverseModulus1_FirstSample = true;
    K_control_DW.InverseModulus1_Revolutions = 0;
  }

  /* Start for FromWorkspace: '<Root>/From Workspace' */
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

    static real_T pDataValues0[] = { 0.0, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5,
      0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5,
      0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5,
      0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5,
      0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5,
      0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5,
      0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5,
      0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5,
      0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5,
      0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5,
      0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5,
      0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5,
      0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5,
      0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5,
      0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5,
      0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5,
      0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5,
      0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5,
      0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5,
      0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5,
      0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5,
      0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5,
      0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5,
      0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5,
      0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5,
      0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5,
      0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5,
      0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5,
      0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5,
      0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5,
      0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5,
      0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5,
      0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5,
      0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5,
      0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5,
      0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5,
      0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5,
      0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5,
      0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5,
      0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5,
      0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5,
      0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5,
      0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5,
      0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5,
      0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5,
      0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5,
      0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5,
      0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5,
      0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5,
      0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5,
      0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5,
      0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5,
      0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5,
      0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5,
      0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5,
      0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5,
      0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5,
      -0.5, 0.0, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5,
      -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5,
      -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5,
      -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5,
      -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5,
      -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5,
      -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5,
      -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5,
      -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5,
      -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5,
      -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5,
      -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5,
      -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5,
      -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5,
      -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5,
      -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5,
      -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5,
      -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5,
      -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5,
      -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5,
      -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5,
      -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5,
      -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5,
      -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5,
      -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5,
      -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5,
      -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5,
      -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5,
      -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5,
      -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5,
      -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5,
      -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5,
      -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5,
      -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5,
      -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5,
      -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5,
      -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5,
      -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5,
      -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5,
      -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5,
      -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5,
      -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5,
      -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5,
      -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5,
      -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5,
      -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5,
      -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5,
      -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5,
      -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5,
      -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5,
      -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5,
      -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5,
      -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5,
      -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5,
      -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5,
      -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5,
      -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5,
      -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5,
      -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5,
      -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5,
      -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5,
      -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5,
      -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5,
      -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5,
      -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5,
      -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5,
      -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5,
      -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5,
      -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5,
      -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5,
      -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, 0.0 } ;

    K_control_DW.FromWorkspace_PWORK.TimePtr = (void *) pTimeValues0;
    K_control_DW.FromWorkspace_PWORK.DataPtr = (void *) pDataValues0;
    K_control_DW.FromWorkspace_IWORK.PrevIndex = 0;
  }

  /* InitializeConditions for DiscreteIntegrator: '<Root>/Discrete-Time Integrator' */
  K_control_DW.DiscreteTimeIntegrator_DSTATE =
    K_control_P.DiscreteTimeIntegrator_IC;

  /* InitializeConditions for UnitDelay: '<S1>/UD' */
  K_control_DW.UD_DSTATE = K_control_P.DiscreteDerivative_ICPrevScaled;

  /* InitializeConditions for DiscreteTransferFcn: '<Root>/Discrete Transfer Fcn' */
  K_control_DW.DiscreteTransferFcn_states =
    K_control_P.DiscreteTransferFcn_InitialStat;

  /* InitializeConditions for UnitDelay: '<S5>/UD' */
  K_control_DW.UD_DSTATE_c = K_control_P.DiscreteDerivative_ICPrevScal_g;

  /* InitializeConditions for UnitDelay: '<S2>/UD' */
  K_control_DW.UD_DSTATE_i = K_control_P.DiscreteDerivative1_ICPrevScale;
}

/* Model terminate function */
void K_control_terminate(void)
{
  /* Terminate for S-Function (hil_initialize_block): '<S3>/HIL Initialize' */

  /* S-Function Block: K_control/Plant/HIL Initialize (hil_initialize_block) */
  {
    t_boolean is_switching;
    t_int result;
    t_uint32 num_final_analog_outputs = 0;
    hil_task_stop_all(K_control_DW.HILInitialize_Card);
    hil_monitor_stop_all(K_control_DW.HILInitialize_Card);
    is_switching = false;
    if ((K_control_P.HILInitialize_AOTerminate && !is_switching) ||
        (K_control_P.HILInitialize_AOExit && is_switching)) {
      K_control_DW.HILInitialize_AOVoltages[0] =
        K_control_P.HILInitialize_AOFinal;
      K_control_DW.HILInitialize_AOVoltages[1] =
        K_control_P.HILInitialize_AOFinal;
      num_final_analog_outputs = 2U;
    } else {
      num_final_analog_outputs = 0;
    }

    if (num_final_analog_outputs > 0) {
      result = hil_write_analog(K_control_DW.HILInitialize_Card,
        K_control_P.HILInitialize_AOChannels, num_final_analog_outputs,
        &K_control_DW.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(K_control_M, _rt_error_message);
      }
    }

    hil_task_delete_all(K_control_DW.HILInitialize_Card);
    hil_monitor_delete_all(K_control_DW.HILInitialize_Card);
    hil_close(K_control_DW.HILInitialize_Card);
    K_control_DW.HILInitialize_Card = NULL;
  }
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  K_control_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  K_control_update();
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
  K_control_initialize();
}

void MdlTerminate(void)
{
  K_control_terminate();
}

/* Registration function */
RT_MODEL_K_control_T *K_control(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)K_control_M, 0,
                sizeof(RT_MODEL_K_control_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&K_control_M->solverInfo,
                          &K_control_M->Timing.simTimeStep);
    rtsiSetTPtr(&K_control_M->solverInfo, &rtmGetTPtr(K_control_M));
    rtsiSetStepSizePtr(&K_control_M->solverInfo, &K_control_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&K_control_M->solverInfo, (&rtmGetErrorStatus
      (K_control_M)));
    rtsiSetRTModelPtr(&K_control_M->solverInfo, K_control_M);
  }

  rtsiSetSimTimeStep(&K_control_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&K_control_M->solverInfo,"FixedStepDiscrete");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = K_control_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;

    /* polyspace +2 MISRA2012:D4.1 [Justified:Low] "K_control_M points to
       static memory which is guaranteed to be non-NULL" */
    K_control_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    K_control_M->Timing.sampleTimes = (&K_control_M->Timing.sampleTimesArray[0]);
    K_control_M->Timing.offsetTimes = (&K_control_M->Timing.offsetTimesArray[0]);

    /* task periods */
    K_control_M->Timing.sampleTimes[0] = (0.0);
    K_control_M->Timing.sampleTimes[1] = (0.001);

    /* task offsets */
    K_control_M->Timing.offsetTimes[0] = (0.0);
    K_control_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(K_control_M, &K_control_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = K_control_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    K_control_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(K_control_M, 1.712);
  K_control_M->Timing.stepSize0 = 0.001;
  K_control_M->Timing.stepSize1 = 0.001;

  /* External mode info */
  K_control_M->Sizes.checksums[0] = (1134674048U);
  K_control_M->Sizes.checksums[1] = (566475829U);
  K_control_M->Sizes.checksums[2] = (1410947570U);
  K_control_M->Sizes.checksums[3] = (1358366083U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    K_control_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(K_control_M->extModeInfo,
      &K_control_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(K_control_M->extModeInfo, K_control_M->Sizes.checksums);
    rteiSetTPtr(K_control_M->extModeInfo, rtmGetTPtr(K_control_M));
  }

  K_control_M->solverInfoPtr = (&K_control_M->solverInfo);
  K_control_M->Timing.stepSize = (0.001);
  rtsiSetFixedStepSize(&K_control_M->solverInfo, 0.001);
  rtsiSetSolverMode(&K_control_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  K_control_M->blockIO = ((void *) &K_control_B);
  (void) memset(((void *) &K_control_B), 0,
                sizeof(B_K_control_T));

  /* parameters */
  K_control_M->defaultParam = ((real_T *)&K_control_P);

  /* states (dwork) */
  K_control_M->dwork = ((void *) &K_control_DW);
  (void) memset((void *)&K_control_DW, 0,
                sizeof(DW_K_control_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    K_control_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 19;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Initialize Sizes */
  K_control_M->Sizes.numContStates = (0);/* Number of continuous states */
  K_control_M->Sizes.numY = (0);       /* Number of model outputs */
  K_control_M->Sizes.numU = (0);       /* Number of model inputs */
  K_control_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  K_control_M->Sizes.numSampTimes = (2);/* Number of sample times */
  K_control_M->Sizes.numBlocks = (39); /* Number of blocks */
  K_control_M->Sizes.numBlockIO = (16);/* Number of block outputs */
  K_control_M->Sizes.numBlockPrms = (96);/* Sum of parameter "widths" */
  return K_control_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
