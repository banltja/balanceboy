/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: balanceModel_private.h
 *
 * Code generated for Simulink model 'balanceModel'.
 *
 * Model version                  : 1.2
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Fri Apr  1 14:13:26 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM 9
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_balanceModel_private_h_
#define RTW_HEADER_balanceModel_private_h_
#include "rtwtypes.h"
#include "balanceModel.h"

/* Private macros used by the generated code to access rtModel */
#ifndef rtmIsMajorTimeStep
#define rtmIsMajorTimeStep(rtm)        (((rtm)->Timing.simTimeStep) == MAJOR_TIME_STEP)
#endif

#ifndef rtmIsMinorTimeStep
#define rtmIsMinorTimeStep(rtm)        (((rtm)->Timing.simTimeStep) == MINOR_TIME_STEP)
#endif

#ifndef rtmSetTPtr
#define rtmSetTPtr(rtm, val)           ((rtm)->Timing.t = (val))
#endif

extern void balanceModel_IfActionSubsystem(real_T *rty_Out1,
  P_IfActionSubsystem_balanceMo_T *localP);

/* private model entry point functions */
extern void balanceModel_derivatives(void);

#endif                                 /* RTW_HEADER_balanceModel_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
