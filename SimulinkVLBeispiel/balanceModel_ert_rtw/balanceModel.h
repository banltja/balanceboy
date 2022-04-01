/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: balanceModel.h
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

#ifndef RTW_HEADER_balanceModel_h_
#define RTW_HEADER_balanceModel_h_
#ifndef balanceModel_COMMON_INCLUDES_
#define balanceModel_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "driver_ev3.h"
#endif                                 /* balanceModel_COMMON_INCLUDES_ */

#include "balanceModel_types.h"
#include <string.h>
#include "rtGetInf.h"
#include "rt_nonfinite.h"
#include <stddef.h>

/* Macros for accessing real-time model data structure */
#ifndef rtmGetContStateDisabled
#define rtmGetContStateDisabled(rtm)   ((rtm)->contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
#define rtmSetContStateDisabled(rtm, val) ((rtm)->contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
#define rtmGetContStates(rtm)          ((rtm)->contStates)
#endif

#ifndef rtmSetContStates
#define rtmSetContStates(rtm, val)     ((rtm)->contStates = (val))
#endif

#ifndef rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm) ((rtm)->CTOutputIncnstWithState)
#endif

#ifndef rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm, val) ((rtm)->CTOutputIncnstWithState = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
#define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
#define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetIntgData
#define rtmGetIntgData(rtm)            ((rtm)->intgData)
#endif

#ifndef rtmSetIntgData
#define rtmSetIntgData(rtm, val)       ((rtm)->intgData = (val))
#endif

#ifndef rtmGetOdeF
#define rtmGetOdeF(rtm)                ((rtm)->odeF)
#endif

#ifndef rtmSetOdeF
#define rtmSetOdeF(rtm, val)           ((rtm)->odeF = (val))
#endif

#ifndef rtmGetOdeY
#define rtmGetOdeY(rtm)                ((rtm)->odeY)
#endif

#ifndef rtmSetOdeY
#define rtmSetOdeY(rtm, val)           ((rtm)->odeY = (val))
#endif

#ifndef rtmGetPeriodicContStateIndices
#define rtmGetPeriodicContStateIndices(rtm) ((rtm)->periodicContStateIndices)
#endif

#ifndef rtmSetPeriodicContStateIndices
#define rtmSetPeriodicContStateIndices(rtm, val) ((rtm)->periodicContStateIndices = (val))
#endif

#ifndef rtmGetPeriodicContStateRanges
#define rtmGetPeriodicContStateRanges(rtm) ((rtm)->periodicContStateRanges)
#endif

#ifndef rtmSetPeriodicContStateRanges
#define rtmSetPeriodicContStateRanges(rtm, val) ((rtm)->periodicContStateRanges = (val))
#endif

#ifndef rtmGetZCCacheNeedsReset
#define rtmGetZCCacheNeedsReset(rtm)   ((rtm)->zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
#define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetdX
#define rtmGetdX(rtm)                  ((rtm)->derivs)
#endif

#ifndef rtmSetdX
#define rtmSetdX(rtm, val)             ((rtm)->derivs = (val))
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                ((rtm)->Timing.t)
#endif

/* Block signals (default storage) */
typedef struct {
  real_T Merge;                        /* '<S6>/Merge' */
  real_T ProportionalGain;             /* '<S43>/Proportional Gain' */
  real_T DerivativeGain;               /* '<S32>/Derivative Gain' */
  real_T FilterCoefficient;            /* '<S41>/Filter Coefficient' */
  real_T IntegralGain;                 /* '<S35>/Integral Gain' */
} B_balanceModel_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_ev3_internal_ev3__T obj; /* '<Root>/Infrared Sensor' */
  int8_T If_ActiveSubsystem;           /* '<S6>/If' */
} DW_balanceModel_T;

/* Continuous states (default storage) */
typedef struct {
  real_T Integrator_CSTATE;            /* '<S38>/Integrator' */
  real_T Filter_CSTATE;                /* '<S33>/Filter' */
} X_balanceModel_T;

/* State derivatives (default storage) */
typedef struct {
  real_T Integrator_CSTATE;            /* '<S38>/Integrator' */
  real_T Filter_CSTATE;                /* '<S33>/Filter' */
} XDot_balanceModel_T;

/* State disabled  */
typedef struct {
  boolean_T Integrator_CSTATE;         /* '<S38>/Integrator' */
  boolean_T Filter_CSTATE;             /* '<S33>/Filter' */
} XDis_balanceModel_T;

#ifndef ODE3_INTG
#define ODE3_INTG

/* ODE3 Integration Data */
typedef struct {
  real_T *y;                           /* output */
  real_T *f[3];                        /* derivatives */
} ODE3_IntgData;

#endif

/* Constant parameters (default storage) */
typedef struct {
  /* Expression: lcdStr1
   * Referenced by: '<S1>/LCD'
   */
  uint8_T LCD_p1[7];

  /* Expression: lcdStr1
   * Referenced by: '<S2>/LCD'
   */
  uint8_T LCD_p1_o[7];

  /* Expression: lcdStr1
   * Referenced by: '<S3>/LCD'
   */
  uint8_T LCD_p1_b[6];
} ConstP_balanceModel_T;

/* Parameters for system: '<S6>/If Action Subsystem' */
struct P_IfActionSubsystem_balanceMo_T_ {
  real_T Constant_Value;               /* Expression: 1
                                        * Referenced by: '<S55>/Constant'
                                        */
};

/* Parameters (default storage) */
struct P_balanceModel_T_ {
  real_T PIDController1_D;             /* Mask Parameter: PIDController1_D
                                        * Referenced by: '<S32>/Derivative Gain'
                                        */
  real_T PIDController1_I;             /* Mask Parameter: PIDController1_I
                                        * Referenced by: '<S35>/Integral Gain'
                                        */
  real_T PIDController1_InitialCondition;
                              /* Mask Parameter: PIDController1_InitialCondition
                               * Referenced by: '<S33>/Filter'
                               */
  real_T PIDController1_InitialConditi_k;
                              /* Mask Parameter: PIDController1_InitialConditi_k
                               * Referenced by: '<S38>/Integrator'
                               */
  real_T PIDController1_N;             /* Mask Parameter: PIDController1_N
                                        * Referenced by: '<S41>/Filter Coefficient'
                                        */
  real_T PIDController1_P;             /* Mask Parameter: PIDController1_P
                                        * Referenced by: '<S43>/Proportional Gain'
                                        */
  real_T Constant_Value;               /* Expression: 45
                                        * Referenced by: '<Root>/Constant'
                                        */
  P_IfActionSubsystem_balanceMo_T IfActionSubsystem1;/* '<S6>/If Action Subsystem1' */
  P_IfActionSubsystem_balanceMo_T IfActionSubsystem;/* '<S6>/If Action Subsystem' */
};

/* Real-time Model Data Structure */
struct tag_RTM_balanceModel_T {
  const char_T *errorStatus;
  RTWSolverInfo solverInfo;
  X_balanceModel_T *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  boolean_T *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T CTOutputIncnstWithState;
  real_T odeY[2];
  real_T odeF[3][2];
  ODE3_IntgData intgData;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    int_T numContStates;
    int_T numPeriodicContStates;
    int_T numSampTimes;
  } Sizes;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    time_T stepSize0;
    uint32_T clockTick1;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

/* Block parameters (default storage) */
extern P_balanceModel_T balanceModel_P;

/* Block signals (default storage) */
extern B_balanceModel_T balanceModel_B;

/* Continuous states (default storage) */
extern X_balanceModel_T balanceModel_X;

/* Block states (default storage) */
extern DW_balanceModel_T balanceModel_DW;

/* Constant parameters (default storage) */
extern const ConstP_balanceModel_T balanceModel_ConstP;

/* Model entry point functions */
extern void balanceModel_initialize(void);
extern void balanceModel_step(void);
extern void balanceModel_terminate(void);

/* Real-time Model object */
extern RT_MODEL_balanceModel_T *const balanceModel_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<Root>/Product' : Unused code path elimination
 * Block '<S3>/Data Type Conversion' : Eliminate redundant data type conversion
 */

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
 * '<Root>' : 'balanceModel'
 * '<S1>'   : 'balanceModel/Display'
 * '<S2>'   : 'balanceModel/Display1'
 * '<S3>'   : 'balanceModel/Display2'
 * '<S4>'   : 'balanceModel/Motor'
 * '<S5>'   : 'balanceModel/PID Controller1'
 * '<S6>'   : 'balanceModel/checkRange'
 * '<S7>'   : 'balanceModel/PID Controller1/Anti-windup'
 * '<S8>'   : 'balanceModel/PID Controller1/D Gain'
 * '<S9>'   : 'balanceModel/PID Controller1/Filter'
 * '<S10>'  : 'balanceModel/PID Controller1/Filter ICs'
 * '<S11>'  : 'balanceModel/PID Controller1/I Gain'
 * '<S12>'  : 'balanceModel/PID Controller1/Ideal P Gain'
 * '<S13>'  : 'balanceModel/PID Controller1/Ideal P Gain Fdbk'
 * '<S14>'  : 'balanceModel/PID Controller1/Integrator'
 * '<S15>'  : 'balanceModel/PID Controller1/Integrator ICs'
 * '<S16>'  : 'balanceModel/PID Controller1/N Copy'
 * '<S17>'  : 'balanceModel/PID Controller1/N Gain'
 * '<S18>'  : 'balanceModel/PID Controller1/P Copy'
 * '<S19>'  : 'balanceModel/PID Controller1/Parallel P Gain'
 * '<S20>'  : 'balanceModel/PID Controller1/Reset Signal'
 * '<S21>'  : 'balanceModel/PID Controller1/Saturation'
 * '<S22>'  : 'balanceModel/PID Controller1/Saturation Fdbk'
 * '<S23>'  : 'balanceModel/PID Controller1/Sum'
 * '<S24>'  : 'balanceModel/PID Controller1/Sum Fdbk'
 * '<S25>'  : 'balanceModel/PID Controller1/Tracking Mode'
 * '<S26>'  : 'balanceModel/PID Controller1/Tracking Mode Sum'
 * '<S27>'  : 'balanceModel/PID Controller1/Tsamp - Integral'
 * '<S28>'  : 'balanceModel/PID Controller1/Tsamp - Ngain'
 * '<S29>'  : 'balanceModel/PID Controller1/postSat Signal'
 * '<S30>'  : 'balanceModel/PID Controller1/preSat Signal'
 * '<S31>'  : 'balanceModel/PID Controller1/Anti-windup/Passthrough'
 * '<S32>'  : 'balanceModel/PID Controller1/D Gain/Internal Parameters'
 * '<S33>'  : 'balanceModel/PID Controller1/Filter/Cont. Filter'
 * '<S34>'  : 'balanceModel/PID Controller1/Filter ICs/Internal IC - Filter'
 * '<S35>'  : 'balanceModel/PID Controller1/I Gain/Internal Parameters'
 * '<S36>'  : 'balanceModel/PID Controller1/Ideal P Gain/Passthrough'
 * '<S37>'  : 'balanceModel/PID Controller1/Ideal P Gain Fdbk/Disabled'
 * '<S38>'  : 'balanceModel/PID Controller1/Integrator/Continuous'
 * '<S39>'  : 'balanceModel/PID Controller1/Integrator ICs/Internal IC'
 * '<S40>'  : 'balanceModel/PID Controller1/N Copy/Disabled'
 * '<S41>'  : 'balanceModel/PID Controller1/N Gain/Internal Parameters'
 * '<S42>'  : 'balanceModel/PID Controller1/P Copy/Disabled'
 * '<S43>'  : 'balanceModel/PID Controller1/Parallel P Gain/Internal Parameters'
 * '<S44>'  : 'balanceModel/PID Controller1/Reset Signal/Disabled'
 * '<S45>'  : 'balanceModel/PID Controller1/Saturation/Passthrough'
 * '<S46>'  : 'balanceModel/PID Controller1/Saturation Fdbk/Disabled'
 * '<S47>'  : 'balanceModel/PID Controller1/Sum/Sum_PID'
 * '<S48>'  : 'balanceModel/PID Controller1/Sum Fdbk/Disabled'
 * '<S49>'  : 'balanceModel/PID Controller1/Tracking Mode/Disabled'
 * '<S50>'  : 'balanceModel/PID Controller1/Tracking Mode Sum/Passthrough'
 * '<S51>'  : 'balanceModel/PID Controller1/Tsamp - Integral/Passthrough'
 * '<S52>'  : 'balanceModel/PID Controller1/Tsamp - Ngain/Passthrough'
 * '<S53>'  : 'balanceModel/PID Controller1/postSat Signal/Forward_Path'
 * '<S54>'  : 'balanceModel/PID Controller1/preSat Signal/Forward_Path'
 * '<S55>'  : 'balanceModel/checkRange/If Action Subsystem'
 * '<S56>'  : 'balanceModel/checkRange/If Action Subsystem1'
 */
#endif                                 /* RTW_HEADER_balanceModel_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
