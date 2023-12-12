/*
 * bodeTestRunner.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "bodeTestRunner".
 *
 * Model version              : 1.50
 * Simulink Coder version : 9.6 (R2021b) 14-May-2021
 * C source code generated on : Tue Dec 12 08:18:59 2023
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

  /* S-Function (hil_read_encoder_block): '<S1>/HIL Read Encoder1' */

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

  /* Gain: '<S1>/mm//cn' */
  bodeTestRunner_B.mmcn = bodeTestRunner_P.mmcn_Gain * rtb_CableGain;

  /* S-Function (inverse_modulus_block): '<S1>/Inverse Modulus' */
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

  /* S-Function (hil_read_encoder_block): '<S1>/HIL Read Encoder 2' */

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

  /* Gain: '<S1>/mm//cn - 2' */
  bodeTestRunner_B.mmcn2 = bodeTestRunner_P.mmcn2_Gain * rtb_CableGain;

  /* S-Function (inverse_modulus_block): '<S1>/Inverse Modulus1' */
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

  /* Sin: '<Root>/Sine Wave' */
  bodeTestRunner_B.SineWave = sin(bodeTestRunner_P.SineWave_Freq *
    bodeTestRunner_M->Timing.t[0] + bodeTestRunner_P.SineWave_Phase) *
    bodeTestRunner_P.SineWave_Amp + bodeTestRunner_P.SineWave_Bias;

  /* Gain: '<S1>/Cable Gain' incorporates:
   *  ZeroOrderHold: '<Root>/Zero-Order Hold'
   */
  rtb_CableGain = bodeTestRunner_B.SineWave;

  /* Saturate: '<Root>/Saturation' */
  if (rtb_CableGain > bodeTestRunner_P.Saturation_UpperSat) {
    /* Saturate: '<Root>/Saturation' */
    bodeTestRunner_B.in = bodeTestRunner_P.Saturation_UpperSat;
  } else if (rtb_CableGain < bodeTestRunner_P.Saturation_LowerSat) {
    /* Saturate: '<Root>/Saturation' */
    bodeTestRunner_B.in = bodeTestRunner_P.Saturation_LowerSat;
  } else {
    /* Saturate: '<Root>/Saturation' */
    bodeTestRunner_B.in = rtb_CableGain;
  }

  /* End of Saturate: '<Root>/Saturation' */

  /* Gain: '<S1>/Cable Gain' */
  rtb_CableGain = bodeTestRunner_P.CableGain_Gain * bodeTestRunner_B.in;

  /* S-Function (hil_write_analog_block): '<S1>/HIL Write Analog' */

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
}

/* Model update function */
void bodeTestRunner_update(void)
{
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
  /* Start for S-Function (hil_initialize_block): '<S1>/HIL Initialize' */

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

  /* Start for S-Function (inverse_modulus_block): '<S1>/Inverse Modulus' */

  /* S-Function Block: bodeTestRunner/Plant/Inverse Modulus (inverse_modulus_block) */
  {
    bodeTestRunner_DW.InverseModulus_FirstSample = true;
    bodeTestRunner_DW.InverseModulus_Revolutions = 0;
  }

  /* Start for S-Function (inverse_modulus_block): '<S1>/Inverse Modulus1' */

  /* S-Function Block: bodeTestRunner/Plant/Inverse Modulus1 (inverse_modulus_block) */
  {
    bodeTestRunner_DW.InverseModulus1_FirstSample = true;
    bodeTestRunner_DW.InverseModulus1_Revolutions = 0;
  }
}

/* Model terminate function */
void bodeTestRunner_terminate(void)
{
  /* Terminate for S-Function (hil_initialize_block): '<S1>/HIL Initialize' */

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

  rtmSetTFinal(bodeTestRunner_M, 20.0);
  bodeTestRunner_M->Timing.stepSize0 = 0.001;
  bodeTestRunner_M->Timing.stepSize1 = 0.001;

  /* External mode info */
  bodeTestRunner_M->Sizes.checksums[0] = (178411266U);
  bodeTestRunner_M->Sizes.checksums[1] = (2145821607U);
  bodeTestRunner_M->Sizes.checksums[2] = (67147437U);
  bodeTestRunner_M->Sizes.checksums[3] = (3059341886U);

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
  bodeTestRunner_M->Sizes.numBlocks = (15);/* Number of blocks */
  bodeTestRunner_M->Sizes.numBlockIO = (5);/* Number of block outputs */
  bodeTestRunner_M->Sizes.numBlockPrms = (78);/* Sum of parameter "widths" */
  return bodeTestRunner_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
