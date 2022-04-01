/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: balanceModel.c
 *
 * Code generated for Simulink model 'balanceModel'.
 *
 * Model version                  : 1.4
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Fri Apr  1 15:16:11 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM 9
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "balanceModel.h"
#include "rtwtypes.h"
#include "balanceModel_private.h"
#include <string.h>
#include <math.h>
#include "rt_nonfinite.h"
#include <stddef.h>

/* Block signals (default storage) */
B_balanceModel_T balanceModel_B;

/* Continuous states */
X_balanceModel_T balanceModel_X;

/* Block states (default storage) */
DW_balanceModel_T balanceModel_DW;

/* Real-time model */
static RT_MODEL_balanceModel_T balanceModel_M_;
RT_MODEL_balanceModel_T *const balanceModel_M = &balanceModel_M_;

/*
 * This function updates continuous states using the ODE3 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  /* Solver Matrices */
  static const real_T rt_ODE3_A[3] = {
    1.0/2.0, 3.0/4.0, 1.0
  };

  static const real_T rt_ODE3_B[3][3] = {
    { 1.0/2.0, 0.0, 0.0 },

    { 0.0, 3.0/4.0, 0.0 },

    { 2.0/9.0, 1.0/3.0, 4.0/9.0 }
  };

  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE3_IntgData *id = (ODE3_IntgData *)rtsiGetSolverData(si);
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T hB[3];
  int_T i;
  int_T nXc = 2;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  balanceModel_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  balanceModel_step();
  balanceModel_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  balanceModel_step();
  balanceModel_derivatives();

  /* tnew = t + hA(3);
     ynew = y + f*hB(:,3); */
  for (i = 0; i <= 2; i++) {
    hB[i] = h * rt_ODE3_B[2][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2]);
  }

  rtsiSetT(si, tnew);
  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/*
 * Output and update for action system:
 *    '<S6>/If Action Subsystem'
 *    '<S6>/If Action Subsystem1'
 */
void balanceModel_IfActionSubsystem(RT_MODEL_balanceModel_T * const
  balanceModel_M, real_T *rty_Out1, P_IfActionSubsystem_balanceMo_T *localP)
{
  if (rtmIsMajorTimeStep(balanceModel_M)) {
    /* SignalConversion generated from: '<S55>/Out1' incorporates:
     *  Constant: '<S55>/Constant'
     */
    *rty_Out1 = localP->Constant_Value;
  }
}

/* Model step function */
void balanceModel_step(void)
{
  real_T rtb_Product1;
  real_T rtb_Sum;
  real_T tmp;
  int32_T rtb_DataTypeConversion_lk;
  int8_T rtb_InfraredSensor_0;
  uint8_T IRdata;
  uint8_T proximity;
  if (rtmIsMajorTimeStep(balanceModel_M)) {
    /* set solver stop time */
    rtsiSetSolverStopTime(&balanceModel_M->solverInfo,
                          ((balanceModel_M->Timing.clockTick0+1)*
      balanceModel_M->Timing.stepSize0));
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(balanceModel_M)) {
    balanceModel_M->Timing.t[0] = rtsiGetT(&balanceModel_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(balanceModel_M)) {
    /* MATLABSystem: '<Root>/Infrared Sensor' */
    IRdata = getInfraredSensorValue(1, 1, 0, &proximity);
    memcpy((void *)&rtb_InfraredSensor_0, (void *)&IRdata, (uint32_T)((size_t)1 *
            sizeof(int8_T)));

    /* S-Function (ev3_lcd): '<S1>/LCD' incorporates:
     *  DataTypeConversion: '<S1>/Data Type Conversion'
     *  MATLABSystem: '<Root>/Infrared Sensor'
     */
    lcdDisplay(rtb_InfraredSensor_0, balanceModel_ConstP.LCD_p1, 1U, 1U);

    /* Sum: '<Root>/Sum' incorporates:
     *  Constant: '<Root>/Constant'
     *  MATLABSystem: '<Root>/Infrared Sensor'
     */
    rtb_Sum = balanceModel_P.Constant_Value - (real_T)rtb_InfraredSensor_0;

    /* Gain: '<S43>/Proportional Gain' */
    balanceModel_B.ProportionalGain = balanceModel_P.PIDController_P * rtb_Sum;

    /* Gain: '<S32>/Derivative Gain' */
    balanceModel_B.DerivativeGain = balanceModel_P.PIDController_D * rtb_Sum;
  }

  /* Gain: '<S41>/Filter Coefficient' incorporates:
   *  Integrator: '<S33>/Filter'
   *  Sum: '<S33>/SumD'
   */
  balanceModel_B.FilterCoefficient = (balanceModel_B.DerivativeGain -
    balanceModel_X.Filter_CSTATE) * balanceModel_P.PIDController_N;

  /* Sum: '<S47>/Sum' incorporates:
   *  Integrator: '<S38>/Integrator'
   */
  rtb_Product1 = (balanceModel_B.ProportionalGain +
                  balanceModel_X.Integrator_CSTATE) +
    balanceModel_B.FilterCoefficient;
  if (rtmIsMajorTimeStep(balanceModel_M)) {
    /* DataTypeConversion: '<S2>/Data Type Conversion' */
    tmp = floor(rtb_Product1);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = fmod(tmp, 4.294967296E+9);
    }

    /* S-Function (ev3_lcd): '<S2>/LCD' incorporates:
     *  DataTypeConversion: '<S2>/Data Type Conversion'
     */
    lcdDisplay(tmp < 0.0 ? -(int32_T)(uint32_T)-tmp : (int32_T)(uint32_T)tmp,
               balanceModel_ConstP.LCD_p1_o, 2U, 1U);

    /* S-Function (ev3_buttons): '<Root>/Button' */
    proximity = getButtonValue(2U);

    /* S-Function (ev3_encoder): '<Root>/Encoder' incorporates:
     *  DataTypeConversion: '<Root>/Data Type Conversion'
     *  S-Function (ev3_buttons): '<Root>/Button'
     */
    rtb_InfraredSensor_0 = (int8_T)proximity;

    /* S-Function (ev3_encoder): '<Root>/Encoder' */
    balanceModel_B.Encoder = getEncoderValueExternalReset(1U,
      &rtb_InfraredSensor_0);

    /* S-Function (ev3_lcd): '<S3>/LCD' */
    lcdDisplay(balanceModel_B.Encoder, balanceModel_ConstP.LCD_p1_b, 3U, 1U);
  }

  /* DataTypeConversion: '<S6>/Data Type Conversion' */
  tmp = floor(rtb_Product1);
  if (rtIsNaN(tmp) || rtIsInf(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmod(tmp, 4.294967296E+9);
  }

  rtb_DataTypeConversion_lk = tmp < 0.0 ? -(int32_T)(uint32_T)-tmp : (int32_T)
    (uint32_T)tmp;

  /* End of DataTypeConversion: '<S6>/Data Type Conversion' */

  /* If: '<S6>/If' */
  if (rtsiIsModeUpdateTimeStep(&balanceModel_M->solverInfo)) {
    balanceModel_DW.If_ActiveSubsystem = (int8_T)(((rtb_DataTypeConversion_lk >=
      0) || (balanceModel_B.Encoder >= -20)) && ((rtb_DataTypeConversion_lk <= 0)
      || (balanceModel_B.Encoder <= 20)));
  }

  switch (balanceModel_DW.If_ActiveSubsystem) {
   case 0:
    /* Outputs for IfAction SubSystem: '<S6>/If Action Subsystem' incorporates:
     *  ActionPort: '<S55>/Action Port'
     */
    balanceModel_IfActionSubsystem(balanceModel_M, &balanceModel_B.Merge,
      &balanceModel_P.IfActionSubsystem);

    /* End of Outputs for SubSystem: '<S6>/If Action Subsystem' */
    break;

   case 1:
    /* Outputs for IfAction SubSystem: '<S6>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S56>/Action Port'
     */
    balanceModel_IfActionSubsystem(balanceModel_M, &balanceModel_B.Merge,
      &balanceModel_P.IfActionSubsystem1);

    /* End of Outputs for SubSystem: '<S6>/If Action Subsystem1' */
    break;
  }

  /* End of If: '<S6>/If' */
  if (rtmIsMajorTimeStep(balanceModel_M)) {
    /* DataTypeConversion: '<S4>/Data Type Conversion' incorporates:
     *  Product: '<Root>/Product1'
     */
    tmp = floor(rtb_Product1 * balanceModel_B.Merge);
    if (tmp < 128.0) {
      if (tmp >= -128.0) {
        /* S-Function (ev3_motor): '<S4>/Motor' */
        rtb_InfraredSensor_0 = (int8_T)tmp;
      } else {
        /* S-Function (ev3_motor): '<S4>/Motor' */
        rtb_InfraredSensor_0 = MIN_int8_T;
      }
    } else {
      /* S-Function (ev3_motor): '<S4>/Motor' */
      rtb_InfraredSensor_0 = MAX_int8_T;
    }

    /* End of DataTypeConversion: '<S4>/Data Type Conversion' */

    /* S-Function (ev3_motor): '<S4>/Motor' */
    setMotor(&rtb_InfraredSensor_0, 1U, 2U);

    /* Gain: '<S35>/Integral Gain' */
    balanceModel_B.IntegralGain = balanceModel_P.PIDController_I * rtb_Sum;
  }

  if (rtmIsMajorTimeStep(balanceModel_M)) {
    rt_ertODEUpdateContinuousStates(&balanceModel_M->solverInfo);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     */
    ++balanceModel_M->Timing.clockTick0;
    balanceModel_M->Timing.t[0] = rtsiGetSolverStopTime
      (&balanceModel_M->solverInfo);

    {
      /* Update absolute timer for sample time: [0.1s, 0.0s] */
      /* The "clockTick1" counts the number of times the code of this task has
       * been executed. The resolution of this integer timer is 0.1, which is the step size
       * of the task. Size of "clockTick1" ensures timer will not overflow during the
       * application lifespan selected.
       */
      balanceModel_M->Timing.clockTick1++;
    }
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void balanceModel_derivatives(void)
{
  XDot_balanceModel_T *_rtXdot;
  _rtXdot = ((XDot_balanceModel_T *) balanceModel_M->derivs);

  /* Derivatives for Integrator: '<S38>/Integrator' */
  _rtXdot->Integrator_CSTATE = balanceModel_B.IntegralGain;

  /* Derivatives for Integrator: '<S33>/Filter' */
  _rtXdot->Filter_CSTATE = balanceModel_B.FilterCoefficient;
}

/* Model initialize function */
void balanceModel_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&balanceModel_M->solverInfo,
                          &balanceModel_M->Timing.simTimeStep);
    rtsiSetTPtr(&balanceModel_M->solverInfo, &rtmGetTPtr(balanceModel_M));
    rtsiSetStepSizePtr(&balanceModel_M->solverInfo,
                       &balanceModel_M->Timing.stepSize0);
    rtsiSetdXPtr(&balanceModel_M->solverInfo, &balanceModel_M->derivs);
    rtsiSetContStatesPtr(&balanceModel_M->solverInfo, (real_T **)
                         &balanceModel_M->contStates);
    rtsiSetNumContStatesPtr(&balanceModel_M->solverInfo,
      &balanceModel_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&balanceModel_M->solverInfo,
      &balanceModel_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&balanceModel_M->solverInfo,
      &balanceModel_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&balanceModel_M->solverInfo,
      &balanceModel_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&balanceModel_M->solverInfo, (&rtmGetErrorStatus
      (balanceModel_M)));
    rtsiSetRTModelPtr(&balanceModel_M->solverInfo, balanceModel_M);
  }

  rtsiSetSimTimeStep(&balanceModel_M->solverInfo, MAJOR_TIME_STEP);
  balanceModel_M->intgData.y = balanceModel_M->odeY;
  balanceModel_M->intgData.f[0] = balanceModel_M->odeF[0];
  balanceModel_M->intgData.f[1] = balanceModel_M->odeF[1];
  balanceModel_M->intgData.f[2] = balanceModel_M->odeF[2];
  balanceModel_M->contStates = ((X_balanceModel_T *) &balanceModel_X);
  rtsiSetSolverData(&balanceModel_M->solverInfo, (void *)
                    &balanceModel_M->intgData);
  rtsiSetIsMinorTimeStepWithModeChange(&balanceModel_M->solverInfo, false);
  rtsiSetSolverName(&balanceModel_M->solverInfo,"ode3");
  rtmSetTPtr(balanceModel_M, &balanceModel_M->Timing.tArray[0]);
  balanceModel_M->Timing.stepSize0 = 0.1;

  /* Start for S-Function (ev3_lcd): '<S1>/LCD' */
  initLCD();

  /* Start for S-Function (ev3_lcd): '<S2>/LCD' */
  initLCD();

  /* Start for S-Function (ev3_buttons): '<Root>/Button' */
  initButton(2U);

  /* Start for S-Function (ev3_encoder): '<Root>/Encoder' */
  initEncoder(1U);

  /* Start for S-Function (ev3_lcd): '<S3>/LCD' */
  initLCD();

  /* Start for If: '<S6>/If' */
  balanceModel_DW.If_ActiveSubsystem = -1;

  /* Start for S-Function (ev3_motor): '<S4>/Motor' */
  initMotor(1U);

  /* InitializeConditions for Integrator: '<S38>/Integrator' */
  balanceModel_X.Integrator_CSTATE =
    balanceModel_P.PIDController_InitialConditio_p;

  /* InitializeConditions for Integrator: '<S33>/Filter' */
  balanceModel_X.Filter_CSTATE = balanceModel_P.PIDController_InitialConditionF;

  /* Start for MATLABSystem: '<Root>/Infrared Sensor' */
  balanceModel_DW.obj.matlabCodegenIsDeleted = false;
  balanceModel_DW.obj.isInitialized = 1;
  initInfraredSensor(1, 0);
  balanceModel_DW.obj.isSetupComplete = true;
}

/* Model terminate function */
void balanceModel_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/Infrared Sensor' */
  if (!balanceModel_DW.obj.matlabCodegenIsDeleted) {
    balanceModel_DW.obj.matlabCodegenIsDeleted = true;
    if ((balanceModel_DW.obj.isInitialized == 1) &&
        balanceModel_DW.obj.isSetupComplete) {
      terminateInfraredSensor(1);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Infrared Sensor' */

  /* Terminate for S-Function (ev3_lcd): '<S1>/LCD' */
  terminateLCD();

  /* Terminate for S-Function (ev3_lcd): '<S2>/LCD' */
  terminateLCD();

  /* Terminate for S-Function (ev3_buttons): '<Root>/Button' */
  terminateButton(2U);

  /* Terminate for S-Function (ev3_encoder): '<Root>/Encoder' */
  terminateEncoder(1U);

  /* Terminate for S-Function (ev3_lcd): '<S3>/LCD' */
  terminateLCD();

  /* Terminate for S-Function (ev3_motor): '<S4>/Motor' */
  terminateMotor(1U, 2U);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
