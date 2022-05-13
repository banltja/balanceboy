/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: RegelkreisV1_data.c
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

/* Block parameters (default storage) */
P_RegelkreisV1_T RegelkreisV1_P = {
  /* Variable: Gr_x
   * Referenced by:
   *   '<S126>/Derivative Gain'
   *   '<S137>/Proportional Gain'
   */
  {
    8.0,
    0.1
  },

  /* Variable: Gr_omega
   * Referenced by:
   *   '<S33>/Integral Gain'
   *   '<S41>/Proportional Gain'
   */
  {
    -7.0,
    0.0
  },

  /* Variable: Gr_phi
   * Referenced by:
   *   '<S81>/Integral Gain'
   *   '<S89>/Proportional Gain'
   */
  {
    3.0,
    0.01
  },

  /* Mask Parameter: G_rphi_D
   * Referenced by: '<S78>/Derivative Gain'
   */
  0.0,

  /* Mask Parameter: G_romega_D
   * Referenced by: '<S30>/Derivative Gain'
   */
  0.0,

  /* Mask Parameter: G_rx_I
   * Referenced by: '<S129>/Integral Gain'
   */
  0.0,

  /* Mask Parameter: G_rx_InitialConditionForFilter
   * Referenced by: '<S127>/Filter'
   */
  0.0,

  /* Mask Parameter: G_rphi_InitialConditionForFilte
   * Referenced by: '<S79>/Filter'
   */
  0.0,

  /* Mask Parameter: G_romega_InitialConditionForFil
   * Referenced by: '<S31>/Filter'
   */
  0.0,

  /* Mask Parameter: G_rx_InitialConditionForIntegra
   * Referenced by: '<S132>/Integrator'
   */
  0.0,

  /* Mask Parameter: G_rphi_InitialConditionForInteg
   * Referenced by: '<S84>/Integrator'
   */
  0.0,

  /* Mask Parameter: G_romega_InitialConditionForInt
   * Referenced by: '<S36>/Integrator'
   */
  0.0,

  /* Mask Parameter: G_rx_N
   * Referenced by: '<S135>/Filter Coefficient'
   */
  100.0,

  /* Mask Parameter: G_rphi_N
   * Referenced by: '<S87>/Filter Coefficient'
   */
  100.0,

  /* Mask Parameter: G_romega_N
   * Referenced by: '<S39>/Filter Coefficient'
   */
  100.0,

  /* Expression: 51
   * Referenced by: '<Root>/Constant'
   */
  51.0,

  /* Computed Parameter: PT1Filter2_A
   * Referenced by: '<Root>/PT1-Filter2'
   */
  -10.0,

  /* Computed Parameter: PT1Filter2_C
   * Referenced by: '<Root>/PT1-Filter2'
   */
  10.0,

  /* Computed Parameter: PT1Filter1_A
   * Referenced by: '<Root>/PT1-Filter1'
   */
  -10.0,

  /* Computed Parameter: PT1Filter1_C
   * Referenced by: '<Root>/PT1-Filter1'
   */
  10.0,

  /* Expression: 0
   * Referenced by: '<Root>/Integrator'
   */
  0.0
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
