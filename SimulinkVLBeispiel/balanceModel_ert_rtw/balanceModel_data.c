/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: balanceModel_data.c
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

#include "balanceModel.h"

/* Block parameters (default storage) */
P_balanceModel_T balanceModel_P = {
  /* Mask Parameter: PIDController1_D
   * Referenced by: '<S32>/Derivative Gain'
   */
  0.0,

  /* Mask Parameter: PIDController1_I
   * Referenced by: '<S35>/Integral Gain'
   */
  0.0,

  /* Mask Parameter: PIDController1_InitialCondition
   * Referenced by: '<S33>/Filter'
   */
  0.0,

  /* Mask Parameter: PIDController1_InitialConditi_k
   * Referenced by: '<S38>/Integrator'
   */
  0.0,

  /* Mask Parameter: PIDController1_N
   * Referenced by: '<S41>/Filter Coefficient'
   */
  100.0,

  /* Mask Parameter: PIDController1_P
   * Referenced by: '<S43>/Proportional Gain'
   */
  1.0,

  /* Expression: 45
   * Referenced by: '<Root>/Constant'
   */
  45.0,

  /* Start of '<S6>/If Action Subsystem1' */
  {
    /* Expression: 0
     * Referenced by: '<S56>/Constant'
     */
    0.0
  }
  ,

  /* End of '<S6>/If Action Subsystem1' */

  /* Start of '<S6>/If Action Subsystem' */
  {
    /* Expression: 1
     * Referenced by: '<S55>/Constant'
     */
    1.0
  }
  /* End of '<S6>/If Action Subsystem' */
};

/* Constant parameters (default storage) */
const ConstP_balanceModel_T balanceModel_ConstP = {
  /* Expression: lcdStr1
   * Referenced by: '<S1>/LCD'
   */
  { 115U, 101U, 110U, 115U, 111U, 114U, 0U },

  /* Expression: lcdStr1
   * Referenced by: '<S2>/LCD'
   */
  { 114U, 101U, 115U, 117U, 108U, 116U, 0U },

  /* Expression: lcdStr1
   * Referenced by: '<S3>/LCD'
   */
  { 109U, 111U, 116U, 111U, 114U, 0U }
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
