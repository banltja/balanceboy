/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: TestDerSensoren.h
 *
 * Code generated for Simulink model 'TestDerSensoren'.
 *
 * Model version                  : 1.1
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Wed May 25 20:10:50 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM 9
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_TestDerSensoren_h_
#define RTW_HEADER_TestDerSensoren_h_
#ifndef TestDerSensoren_COMMON_INCLUDES_
#define TestDerSensoren_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "driver_ev3.h"
#endif                                 /* TestDerSensoren_COMMON_INCLUDES_ */

#include "TestDerSensoren_types.h"
#include <stddef.h>

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_ev3_internal_ev3__T obj; /* '<Root>/Infrared Sensor' */
} DW_TestDerSensoren_T;

/* Real-time Model Data Structure */
struct tag_RTM_TestDerSensoren_T {
  const char_T * volatile errorStatus;
};

/* Block states (default storage) */
extern DW_TestDerSensoren_T TestDerSensoren_DW;

/* Model entry point functions */
extern void TestDerSensoren_initialize(void);
extern void TestDerSensoren_step(void);
extern void TestDerSensoren_terminate(void);

/* Real-time Model object */
extern RT_MODEL_TestDerSensoren_T *const TestDerSensoren_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'TestDerSensoren'
 * '<S1>'   : 'TestDerSensoren/Display'
 */
#endif                                 /* RTW_HEADER_TestDerSensoren_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
