/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: RegelkreisV1.c
 *
 * Code generated for Simulink model 'RegelkreisV1'.
 *
 * Model version                  : 1.4
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Thu May  5 10:55:47 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM 9
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "RegelkreisV1.h"
#include <string.h>
#include <math.h>
#include "rtwtypes.h"
#include <stddef.h>
#include "RegelkreisV1_private.h"

/* Block signals (default storage) */
B_RegelkreisV1_T RegelkreisV1_B;

/* Continuous states */
X_RegelkreisV1_T RegelkreisV1_X;

/* Block states (default storage) */
DW_RegelkreisV1_T RegelkreisV1_DW;

/* Real-time model */
static RT_MODEL_RegelkreisV1_T RegelkreisV1_M_;
RT_MODEL_RegelkreisV1_T *const RegelkreisV1_M = &RegelkreisV1_M_;

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
  int_T nXc = 9;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  RegelkreisV1_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  RegelkreisV1_step();
  RegelkreisV1_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  RegelkreisV1_step();
  RegelkreisV1_derivatives();

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

/* Model step function */
void RegelkreisV1_step(void)
{
  real_T rtb_Sum1;
  real_T rtb_Sum2;
  real_T rtb_Sum_p;
  real_T tmp;
  int32_T rtb_omega_ist_0;
  int8_T rtb_InfraredSensor_0;
  uint8_T IRdata;
  uint8_T proximity;
  if (rtmIsMajorTimeStep(RegelkreisV1_M)) {
    /* set solver stop time */
    rtsiSetSolverStopTime(&RegelkreisV1_M->solverInfo,
                          ((RegelkreisV1_M->Timing.clockTick0+1)*
      RegelkreisV1_M->Timing.stepSize0));
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(RegelkreisV1_M)) {
    RegelkreisV1_M->Timing.t[0] = rtsiGetT(&RegelkreisV1_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(RegelkreisV1_M)) {
    /* MATLABSystem: '<Root>/Infrared Sens or' */
    IRdata = getInfraredSensorValue(1, 1, 0, &proximity);
    memcpy((void *)&rtb_InfraredSensor_0, (void *)&IRdata, (uint32_T)((size_t)1 *
            sizeof(int8_T)));

    /* Sum: '<Root>/Sum' incorporates:
     *  Constant: '<Root>/Constant'
     *  MATLABSystem: '<Root>/Infrared Sens or'
     */
    rtb_Sum_p = RegelkreisV1_P.Constant_Value - (real_T)rtb_InfraredSensor_0;

    /* Gain: '<S137>/Proportional Gain' */
    RegelkreisV1_B.ProportionalGain = RegelkreisV1_P.Gr_x.P * rtb_Sum_p;

    /* Gain: '<S126>/Derivative Gain' */
    RegelkreisV1_B.DerivativeGain = RegelkreisV1_P.Gr_x.D * rtb_Sum_p;
  }

  /* Gain: '<S135>/Filter Coefficient' incorporates:
   *  Integrator: '<S127>/Filter'
   *  Sum: '<S127>/SumD'
   */
  RegelkreisV1_B.FilterCoefficient = (RegelkreisV1_B.DerivativeGain -
    RegelkreisV1_X.Filter_CSTATE) * RegelkreisV1_P.G_rx_N;

  /* Sum: '<Root>/Sum1' incorporates:
   *  Integrator: '<S132>/Integrator'
   *  Sum: '<S141>/Sum'
   *  TransferFcn: '<Root>/PT1-Filter2'
   */
  rtb_Sum1 = ((RegelkreisV1_B.ProportionalGain +
               RegelkreisV1_X.Integrator_CSTATE) +
              RegelkreisV1_B.FilterCoefficient) - RegelkreisV1_P.PT1Filter2_C *
    RegelkreisV1_X.PT1Filter2_CSTATE;

  /* Gain: '<S87>/Filter Coefficient' incorporates:
   *  Gain: '<S78>/Derivative Gain'
   *  Integrator: '<S79>/Filter'
   *  Sum: '<S79>/SumD'
   */
  RegelkreisV1_B.FilterCoefficient_a = (RegelkreisV1_P.G_rphi_D * rtb_Sum1 -
    RegelkreisV1_X.Filter_CSTATE_n) * RegelkreisV1_P.G_rphi_N;

  /* Sum: '<Root>/Sum2' incorporates:
   *  Gain: '<S89>/Proportional Gain'
   *  Integrator: '<S84>/Integrator'
   *  Sum: '<S93>/Sum'
   *  TransferFcn: '<Root>/PT1-Filter1'
   */
  rtb_Sum2 = ((RegelkreisV1_P.Gr_phi.P * rtb_Sum1 +
               RegelkreisV1_X.Integrator_CSTATE_a) +
              RegelkreisV1_B.FilterCoefficient_a) - RegelkreisV1_P.PT1Filter1_C *
    RegelkreisV1_X.PT1Filter1_CSTATE;

  /* Gain: '<S39>/Filter Coefficient' incorporates:
   *  Gain: '<S30>/Derivative Gain'
   *  Integrator: '<S31>/Filter'
   *  Sum: '<S31>/SumD'
   */
  RegelkreisV1_B.FilterCoefficient_k = (RegelkreisV1_P.G_romega_D * rtb_Sum2 -
    RegelkreisV1_X.Filter_CSTATE_nz) * RegelkreisV1_P.G_romega_N;
  if (rtmIsMajorTimeStep(RegelkreisV1_M)) {
    /* DataTypeConversion: '<S4>/Data Type Conversion' incorporates:
     *  Gain: '<S41>/Proportional Gain'
     *  Integrator: '<S36>/Integrator'
     *  Sum: '<S45>/Sum'
     */
    tmp = floor((RegelkreisV1_P.Gr_omega.P * rtb_Sum2 +
                 RegelkreisV1_X.Integrator_CSTATE_j) +
                RegelkreisV1_B.FilterCoefficient_k);
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

    /* S-Function (ev3_encoder): '<Root>/Encoder' */
    rtb_omega_ist_0 = getEncoderValueSampleReset(1U);

    /* DataTypeConversion: '<Root>/Data Type Conversion' incorporates:
     *  S-Function (ev3_encoder): '<Root>/Encoder'
     */
    RegelkreisV1_B.DataTypeConversion = rtb_omega_ist_0;

    /* Gain: '<S129>/Integral Gain' */
    RegelkreisV1_B.IntegralGain_m = RegelkreisV1_P.G_rx_I * rtb_Sum_p;
  }

  /* Gain: '<S33>/Integral Gain' */
  RegelkreisV1_B.IntegralGain = RegelkreisV1_P.Gr_omega.I * rtb_Sum2;

  /* Gain: '<S81>/Integral Gain' */
  RegelkreisV1_B.IntegralGain_n = RegelkreisV1_P.Gr_phi.I * rtb_Sum1;

  /* Integrator: '<Root>/Integrator' */
  RegelkreisV1_B.omega_ist = RegelkreisV1_X.Integrator_CSTATE_g;
  if (rtmIsMajorTimeStep(RegelkreisV1_M)) {
    rt_ertODEUpdateContinuousStates(&RegelkreisV1_M->solverInfo);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     */
    ++RegelkreisV1_M->Timing.clockTick0;
    RegelkreisV1_M->Timing.t[0] = rtsiGetSolverStopTime
      (&RegelkreisV1_M->solverInfo);

    {
      /* Update absolute timer for sample time: [0.1s, 0.0s] */
      /* The "clockTick1" counts the number of times the code of this task has
       * been executed. The resolution of this integer timer is 0.1, which is the step size
       * of the task. Size of "clockTick1" ensures timer will not overflow during the
       * application lifespan selected.
       */
      RegelkreisV1_M->Timing.clockTick1++;
    }
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void RegelkreisV1_derivatives(void)
{
  XDot_RegelkreisV1_T *_rtXdot;
  _rtXdot = ((XDot_RegelkreisV1_T *) RegelkreisV1_M->derivs);

  /* Derivatives for Integrator: '<S132>/Integrator' */
  _rtXdot->Integrator_CSTATE = RegelkreisV1_B.IntegralGain_m;

  /* Derivatives for Integrator: '<S127>/Filter' */
  _rtXdot->Filter_CSTATE = RegelkreisV1_B.FilterCoefficient;

  /* Derivatives for TransferFcn: '<Root>/PT1-Filter2' */
  _rtXdot->PT1Filter2_CSTATE = RegelkreisV1_P.PT1Filter2_A *
    RegelkreisV1_X.PT1Filter2_CSTATE;
  _rtXdot->PT1Filter2_CSTATE += RegelkreisV1_B.omega_ist;

  /* Derivatives for Integrator: '<S84>/Integrator' */
  _rtXdot->Integrator_CSTATE_a = RegelkreisV1_B.IntegralGain_n;

  /* Derivatives for Integrator: '<S79>/Filter' */
  _rtXdot->Filter_CSTATE_n = RegelkreisV1_B.FilterCoefficient_a;

  /* Derivatives for TransferFcn: '<Root>/PT1-Filter1' */
  _rtXdot->PT1Filter1_CSTATE = RegelkreisV1_P.PT1Filter1_A *
    RegelkreisV1_X.PT1Filter1_CSTATE;
  _rtXdot->PT1Filter1_CSTATE += RegelkreisV1_B.DataTypeConversion;

  /* Derivatives for Integrator: '<S36>/Integrator' */
  _rtXdot->Integrator_CSTATE_j = RegelkreisV1_B.IntegralGain;

  /* Derivatives for Integrator: '<S31>/Filter' */
  _rtXdot->Filter_CSTATE_nz = RegelkreisV1_B.FilterCoefficient_k;

  /* Derivatives for Integrator: '<Root>/Integrator' */
  _rtXdot->Integrator_CSTATE_g = RegelkreisV1_B.DataTypeConversion;
}

/* Model initialize function */
void RegelkreisV1_initialize(void)
{
  /* Registration code */
  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&RegelkreisV1_M->solverInfo,
                          &RegelkreisV1_M->Timing.simTimeStep);
    rtsiSetTPtr(&RegelkreisV1_M->solverInfo, &rtmGetTPtr(RegelkreisV1_M));
    rtsiSetStepSizePtr(&RegelkreisV1_M->solverInfo,
                       &RegelkreisV1_M->Timing.stepSize0);
    rtsiSetdXPtr(&RegelkreisV1_M->solverInfo, &RegelkreisV1_M->derivs);
    rtsiSetContStatesPtr(&RegelkreisV1_M->solverInfo, (real_T **)
                         &RegelkreisV1_M->contStates);
    rtsiSetNumContStatesPtr(&RegelkreisV1_M->solverInfo,
      &RegelkreisV1_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&RegelkreisV1_M->solverInfo,
      &RegelkreisV1_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&RegelkreisV1_M->solverInfo,
      &RegelkreisV1_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&RegelkreisV1_M->solverInfo,
      &RegelkreisV1_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&RegelkreisV1_M->solverInfo, (&rtmGetErrorStatus
      (RegelkreisV1_M)));
    rtsiSetRTModelPtr(&RegelkreisV1_M->solverInfo, RegelkreisV1_M);
  }

  rtsiSetSimTimeStep(&RegelkreisV1_M->solverInfo, MAJOR_TIME_STEP);
  RegelkreisV1_M->intgData.y = RegelkreisV1_M->odeY;
  RegelkreisV1_M->intgData.f[0] = RegelkreisV1_M->odeF[0];
  RegelkreisV1_M->intgData.f[1] = RegelkreisV1_M->odeF[1];
  RegelkreisV1_M->intgData.f[2] = RegelkreisV1_M->odeF[2];
  RegelkreisV1_M->contStates = ((X_RegelkreisV1_T *) &RegelkreisV1_X);
  rtsiSetSolverData(&RegelkreisV1_M->solverInfo, (void *)
                    &RegelkreisV1_M->intgData);
  rtsiSetIsMinorTimeStepWithModeChange(&RegelkreisV1_M->solverInfo, false);
  rtsiSetSolverName(&RegelkreisV1_M->solverInfo,"ode3");
  rtmSetTPtr(RegelkreisV1_M, &RegelkreisV1_M->Timing.tArray[0]);
  RegelkreisV1_M->Timing.stepSize0 = 0.1;

  /* Start for S-Function (ev3_motor): '<S4>/Motor' */
  initMotor(1U);

  /* Start for S-Function (ev3_encoder): '<Root>/Encoder' */
  initEncoder(1U);

  /* InitializeConditions for Integrator: '<S132>/Integrator' */
  RegelkreisV1_X.Integrator_CSTATE =
    RegelkreisV1_P.G_rx_InitialConditionForIntegra;

  /* InitializeConditions for Integrator: '<S127>/Filter' */
  RegelkreisV1_X.Filter_CSTATE = RegelkreisV1_P.G_rx_InitialConditionForFilter;

  /* InitializeConditions for TransferFcn: '<Root>/PT1-Filter2' */
  RegelkreisV1_X.PT1Filter2_CSTATE = 0.0;

  /* InitializeConditions for Integrator: '<S84>/Integrator' */
  RegelkreisV1_X.Integrator_CSTATE_a =
    RegelkreisV1_P.G_rphi_InitialConditionForInteg;

  /* InitializeConditions for Integrator: '<S79>/Filter' */
  RegelkreisV1_X.Filter_CSTATE_n =
    RegelkreisV1_P.G_rphi_InitialConditionForFilte;

  /* InitializeConditions for TransferFcn: '<Root>/PT1-Filter1' */
  RegelkreisV1_X.PT1Filter1_CSTATE = 0.0;

  /* InitializeConditions for Integrator: '<S36>/Integrator' */
  RegelkreisV1_X.Integrator_CSTATE_j =
    RegelkreisV1_P.G_romega_InitialConditionForInt;

  /* InitializeConditions for Integrator: '<S31>/Filter' */
  RegelkreisV1_X.Filter_CSTATE_nz =
    RegelkreisV1_P.G_romega_InitialConditionForFil;

  /* InitializeConditions for Integrator: '<Root>/Integrator' */
  RegelkreisV1_X.Integrator_CSTATE_g = RegelkreisV1_P.Integrator_IC;

  /* Start for MATLABSystem: '<Root>/Infrared Sens or' */
  RegelkreisV1_DW.obj.matlabCodegenIsDeleted = false;
  RegelkreisV1_DW.obj.isInitialized = 1;
  initInfraredSensor(1, 0);
  RegelkreisV1_DW.obj.isSetupComplete = true;
}

/* Model terminate function */
void RegelkreisV1_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/Infrared Sens or' */
  if (!RegelkreisV1_DW.obj.matlabCodegenIsDeleted) {
    RegelkreisV1_DW.obj.matlabCodegenIsDeleted = true;
    if ((RegelkreisV1_DW.obj.isInitialized == 1) &&
        RegelkreisV1_DW.obj.isSetupComplete) {
      terminateInfraredSensor(1);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Infrared Sens or' */

  /* Terminate for S-Function (ev3_motor): '<S4>/Motor' */
  terminateMotor(1U, 2U);

  /* Terminate for S-Function (ev3_encoder): '<Root>/Encoder' */
  terminateEncoder(1U);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
