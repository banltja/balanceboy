/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: RegelkreisV1.h
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

#ifndef RTW_HEADER_RegelkreisV1_h_
#define RTW_HEADER_RegelkreisV1_h_
#ifndef RegelkreisV1_COMMON_INCLUDES_
#define RegelkreisV1_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "driver_ev3.h"
#endif                                 /* RegelkreisV1_COMMON_INCLUDES_ */

#include "RegelkreisV1_types.h"
#include <string.h>
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
  real_T ProportionalGain;             /* '<S137>/Proportional Gain' */
  real_T DerivativeGain;               /* '<S126>/Derivative Gain' */
  real_T FilterCoefficient;            /* '<S135>/Filter Coefficient' */
  real_T FilterCoefficient_a;          /* '<S87>/Filter Coefficient' */
  real_T FilterCoefficient_k;          /* '<S39>/Filter Coefficient' */
  real_T DataTypeConversion;           /* '<Root>/Data Type Conversion' */
  real_T IntegralGain;                 /* '<S33>/Integral Gain' */
  real_T IntegralGain_n;               /* '<S81>/Integral Gain' */
  real_T IntegralGain_m;               /* '<S129>/Integral Gain' */
  real_T omega_ist;                    /* '<Root>/Integrator' */
} B_RegelkreisV1_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_ev3_internal_ev3__T obj; /* '<Root>/Infrared Sens or' */
} DW_RegelkreisV1_T;

/* Continuous states (default storage) */
typedef struct {
  real_T Integrator_CSTATE;            /* '<S132>/Integrator' */
  real_T Filter_CSTATE;                /* '<S127>/Filter' */
  real_T PT1Filter2_CSTATE;            /* '<Root>/PT1-Filter2' */
  real_T Integrator_CSTATE_a;          /* '<S84>/Integrator' */
  real_T Filter_CSTATE_n;              /* '<S79>/Filter' */
  real_T PT1Filter1_CSTATE;            /* '<Root>/PT1-Filter1' */
  real_T Integrator_CSTATE_j;          /* '<S36>/Integrator' */
  real_T Filter_CSTATE_nz;             /* '<S31>/Filter' */
  real_T Integrator_CSTATE_g;          /* '<Root>/Integrator' */
} X_RegelkreisV1_T;

/* State derivatives (default storage) */
typedef struct {
  real_T Integrator_CSTATE;            /* '<S132>/Integrator' */
  real_T Filter_CSTATE;                /* '<S127>/Filter' */
  real_T PT1Filter2_CSTATE;            /* '<Root>/PT1-Filter2' */
  real_T Integrator_CSTATE_a;          /* '<S84>/Integrator' */
  real_T Filter_CSTATE_n;              /* '<S79>/Filter' */
  real_T PT1Filter1_CSTATE;            /* '<Root>/PT1-Filter1' */
  real_T Integrator_CSTATE_j;          /* '<S36>/Integrator' */
  real_T Filter_CSTATE_nz;             /* '<S31>/Filter' */
  real_T Integrator_CSTATE_g;          /* '<Root>/Integrator' */
} XDot_RegelkreisV1_T;

/* State disabled  */
typedef struct {
  boolean_T Integrator_CSTATE;         /* '<S132>/Integrator' */
  boolean_T Filter_CSTATE;             /* '<S127>/Filter' */
  boolean_T PT1Filter2_CSTATE;         /* '<Root>/PT1-Filter2' */
  boolean_T Integrator_CSTATE_a;       /* '<S84>/Integrator' */
  boolean_T Filter_CSTATE_n;           /* '<S79>/Filter' */
  boolean_T PT1Filter1_CSTATE;         /* '<Root>/PT1-Filter1' */
  boolean_T Integrator_CSTATE_j;       /* '<S36>/Integrator' */
  boolean_T Filter_CSTATE_nz;          /* '<S31>/Filter' */
  boolean_T Integrator_CSTATE_g;       /* '<Root>/Integrator' */
} XDis_RegelkreisV1_T;

#ifndef ODE3_INTG
#define ODE3_INTG

/* ODE3 Integration Data */
typedef struct {
  real_T *y;                           /* output */
  real_T *f[3];                        /* derivatives */
} ODE3_IntgData;

#endif

/* Parameters (default storage) */
struct P_RegelkreisV1_T_ {
  struct_4qYBl3URLkwSYnOM8TT00B Gr_x;  /* Variable: Gr_x
                                        * Referenced by:
                                        *   '<S126>/Derivative Gain'
                                        *   '<S137>/Proportional Gain'
                                        */
  struct_czMItDs0YMKQTMbf2e3sFH Gr_omega;/* Variable: Gr_omega
                                          * Referenced by:
                                          *   '<S33>/Integral Gain'
                                          *   '<S41>/Proportional Gain'
                                          */
  struct_czMItDs0YMKQTMbf2e3sFH Gr_phi;/* Variable: Gr_phi
                                        * Referenced by:
                                        *   '<S81>/Integral Gain'
                                        *   '<S89>/Proportional Gain'
                                        */
  real_T G_rphi_D;                     /* Mask Parameter: G_rphi_D
                                        * Referenced by: '<S78>/Derivative Gain'
                                        */
  real_T G_romega_D;                   /* Mask Parameter: G_romega_D
                                        * Referenced by: '<S30>/Derivative Gain'
                                        */
  real_T G_rx_I;                       /* Mask Parameter: G_rx_I
                                        * Referenced by: '<S129>/Integral Gain'
                                        */
  real_T G_rx_InitialConditionForFilter;
                               /* Mask Parameter: G_rx_InitialConditionForFilter
                                * Referenced by: '<S127>/Filter'
                                */
  real_T G_rphi_InitialConditionForFilte;
                              /* Mask Parameter: G_rphi_InitialConditionForFilte
                               * Referenced by: '<S79>/Filter'
                               */
  real_T G_romega_InitialConditionForFil;
                              /* Mask Parameter: G_romega_InitialConditionForFil
                               * Referenced by: '<S31>/Filter'
                               */
  real_T G_rx_InitialConditionForIntegra;
                              /* Mask Parameter: G_rx_InitialConditionForIntegra
                               * Referenced by: '<S132>/Integrator'
                               */
  real_T G_rphi_InitialConditionForInteg;
                              /* Mask Parameter: G_rphi_InitialConditionForInteg
                               * Referenced by: '<S84>/Integrator'
                               */
  real_T G_romega_InitialConditionForInt;
                              /* Mask Parameter: G_romega_InitialConditionForInt
                               * Referenced by: '<S36>/Integrator'
                               */
  real_T G_rx_N;                       /* Mask Parameter: G_rx_N
                                        * Referenced by: '<S135>/Filter Coefficient'
                                        */
  real_T G_rphi_N;                     /* Mask Parameter: G_rphi_N
                                        * Referenced by: '<S87>/Filter Coefficient'
                                        */
  real_T G_romega_N;                   /* Mask Parameter: G_romega_N
                                        * Referenced by: '<S39>/Filter Coefficient'
                                        */
  real_T Constant_Value;               /* Expression: 51
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T PT1Filter2_A;                 /* Computed Parameter: PT1Filter2_A
                                        * Referenced by: '<Root>/PT1-Filter2'
                                        */
  real_T PT1Filter2_C;                 /* Computed Parameter: PT1Filter2_C
                                        * Referenced by: '<Root>/PT1-Filter2'
                                        */
  real_T PT1Filter1_A;                 /* Computed Parameter: PT1Filter1_A
                                        * Referenced by: '<Root>/PT1-Filter1'
                                        */
  real_T PT1Filter1_C;                 /* Computed Parameter: PT1Filter1_C
                                        * Referenced by: '<Root>/PT1-Filter1'
                                        */
  real_T Integrator_IC;                /* Expression: 0
                                        * Referenced by: '<Root>/Integrator'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_RegelkreisV1_T {
  const char_T *errorStatus;
  RTWSolverInfo solverInfo;
  X_RegelkreisV1_T *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  boolean_T *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T CTOutputIncnstWithState;
  real_T odeY[9];
  real_T odeF[3][9];
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
extern P_RegelkreisV1_T RegelkreisV1_P;

/* Block signals (default storage) */
extern B_RegelkreisV1_T RegelkreisV1_B;

/* Continuous states (default storage) */
extern X_RegelkreisV1_T RegelkreisV1_X;

/* Block states (default storage) */
extern DW_RegelkreisV1_T RegelkreisV1_DW;

/* Model entry point functions */
extern void RegelkreisV1_initialize(void);
extern void RegelkreisV1_step(void);
extern void RegelkreisV1_terminate(void);

/* Real-time Model object */
extern RT_MODEL_RegelkreisV1_T *const RegelkreisV1_M;

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
 * '<Root>' : 'RegelkreisV1'
 * '<S1>'   : 'RegelkreisV1/G_romega'
 * '<S2>'   : 'RegelkreisV1/G_rphi'
 * '<S3>'   : 'RegelkreisV1/G_rx'
 * '<S4>'   : 'RegelkreisV1/Motor'
 * '<S5>'   : 'RegelkreisV1/G_romega/Anti-windup'
 * '<S6>'   : 'RegelkreisV1/G_romega/D Gain'
 * '<S7>'   : 'RegelkreisV1/G_romega/Filter'
 * '<S8>'   : 'RegelkreisV1/G_romega/Filter ICs'
 * '<S9>'   : 'RegelkreisV1/G_romega/I Gain'
 * '<S10>'  : 'RegelkreisV1/G_romega/Ideal P Gain'
 * '<S11>'  : 'RegelkreisV1/G_romega/Ideal P Gain Fdbk'
 * '<S12>'  : 'RegelkreisV1/G_romega/Integrator'
 * '<S13>'  : 'RegelkreisV1/G_romega/Integrator ICs'
 * '<S14>'  : 'RegelkreisV1/G_romega/N Copy'
 * '<S15>'  : 'RegelkreisV1/G_romega/N Gain'
 * '<S16>'  : 'RegelkreisV1/G_romega/P Copy'
 * '<S17>'  : 'RegelkreisV1/G_romega/Parallel P Gain'
 * '<S18>'  : 'RegelkreisV1/G_romega/Reset Signal'
 * '<S19>'  : 'RegelkreisV1/G_romega/Saturation'
 * '<S20>'  : 'RegelkreisV1/G_romega/Saturation Fdbk'
 * '<S21>'  : 'RegelkreisV1/G_romega/Sum'
 * '<S22>'  : 'RegelkreisV1/G_romega/Sum Fdbk'
 * '<S23>'  : 'RegelkreisV1/G_romega/Tracking Mode'
 * '<S24>'  : 'RegelkreisV1/G_romega/Tracking Mode Sum'
 * '<S25>'  : 'RegelkreisV1/G_romega/Tsamp - Integral'
 * '<S26>'  : 'RegelkreisV1/G_romega/Tsamp - Ngain'
 * '<S27>'  : 'RegelkreisV1/G_romega/postSat Signal'
 * '<S28>'  : 'RegelkreisV1/G_romega/preSat Signal'
 * '<S29>'  : 'RegelkreisV1/G_romega/Anti-windup/Passthrough'
 * '<S30>'  : 'RegelkreisV1/G_romega/D Gain/Internal Parameters'
 * '<S31>'  : 'RegelkreisV1/G_romega/Filter/Cont. Filter'
 * '<S32>'  : 'RegelkreisV1/G_romega/Filter ICs/Internal IC - Filter'
 * '<S33>'  : 'RegelkreisV1/G_romega/I Gain/Internal Parameters'
 * '<S34>'  : 'RegelkreisV1/G_romega/Ideal P Gain/Passthrough'
 * '<S35>'  : 'RegelkreisV1/G_romega/Ideal P Gain Fdbk/Disabled'
 * '<S36>'  : 'RegelkreisV1/G_romega/Integrator/Continuous'
 * '<S37>'  : 'RegelkreisV1/G_romega/Integrator ICs/Internal IC'
 * '<S38>'  : 'RegelkreisV1/G_romega/N Copy/Disabled'
 * '<S39>'  : 'RegelkreisV1/G_romega/N Gain/Internal Parameters'
 * '<S40>'  : 'RegelkreisV1/G_romega/P Copy/Disabled'
 * '<S41>'  : 'RegelkreisV1/G_romega/Parallel P Gain/Internal Parameters'
 * '<S42>'  : 'RegelkreisV1/G_romega/Reset Signal/Disabled'
 * '<S43>'  : 'RegelkreisV1/G_romega/Saturation/Passthrough'
 * '<S44>'  : 'RegelkreisV1/G_romega/Saturation Fdbk/Disabled'
 * '<S45>'  : 'RegelkreisV1/G_romega/Sum/Sum_PID'
 * '<S46>'  : 'RegelkreisV1/G_romega/Sum Fdbk/Disabled'
 * '<S47>'  : 'RegelkreisV1/G_romega/Tracking Mode/Disabled'
 * '<S48>'  : 'RegelkreisV1/G_romega/Tracking Mode Sum/Passthrough'
 * '<S49>'  : 'RegelkreisV1/G_romega/Tsamp - Integral/Passthrough'
 * '<S50>'  : 'RegelkreisV1/G_romega/Tsamp - Ngain/Passthrough'
 * '<S51>'  : 'RegelkreisV1/G_romega/postSat Signal/Forward_Path'
 * '<S52>'  : 'RegelkreisV1/G_romega/preSat Signal/Forward_Path'
 * '<S53>'  : 'RegelkreisV1/G_rphi/Anti-windup'
 * '<S54>'  : 'RegelkreisV1/G_rphi/D Gain'
 * '<S55>'  : 'RegelkreisV1/G_rphi/Filter'
 * '<S56>'  : 'RegelkreisV1/G_rphi/Filter ICs'
 * '<S57>'  : 'RegelkreisV1/G_rphi/I Gain'
 * '<S58>'  : 'RegelkreisV1/G_rphi/Ideal P Gain'
 * '<S59>'  : 'RegelkreisV1/G_rphi/Ideal P Gain Fdbk'
 * '<S60>'  : 'RegelkreisV1/G_rphi/Integrator'
 * '<S61>'  : 'RegelkreisV1/G_rphi/Integrator ICs'
 * '<S62>'  : 'RegelkreisV1/G_rphi/N Copy'
 * '<S63>'  : 'RegelkreisV1/G_rphi/N Gain'
 * '<S64>'  : 'RegelkreisV1/G_rphi/P Copy'
 * '<S65>'  : 'RegelkreisV1/G_rphi/Parallel P Gain'
 * '<S66>'  : 'RegelkreisV1/G_rphi/Reset Signal'
 * '<S67>'  : 'RegelkreisV1/G_rphi/Saturation'
 * '<S68>'  : 'RegelkreisV1/G_rphi/Saturation Fdbk'
 * '<S69>'  : 'RegelkreisV1/G_rphi/Sum'
 * '<S70>'  : 'RegelkreisV1/G_rphi/Sum Fdbk'
 * '<S71>'  : 'RegelkreisV1/G_rphi/Tracking Mode'
 * '<S72>'  : 'RegelkreisV1/G_rphi/Tracking Mode Sum'
 * '<S73>'  : 'RegelkreisV1/G_rphi/Tsamp - Integral'
 * '<S74>'  : 'RegelkreisV1/G_rphi/Tsamp - Ngain'
 * '<S75>'  : 'RegelkreisV1/G_rphi/postSat Signal'
 * '<S76>'  : 'RegelkreisV1/G_rphi/preSat Signal'
 * '<S77>'  : 'RegelkreisV1/G_rphi/Anti-windup/Passthrough'
 * '<S78>'  : 'RegelkreisV1/G_rphi/D Gain/Internal Parameters'
 * '<S79>'  : 'RegelkreisV1/G_rphi/Filter/Cont. Filter'
 * '<S80>'  : 'RegelkreisV1/G_rphi/Filter ICs/Internal IC - Filter'
 * '<S81>'  : 'RegelkreisV1/G_rphi/I Gain/Internal Parameters'
 * '<S82>'  : 'RegelkreisV1/G_rphi/Ideal P Gain/Passthrough'
 * '<S83>'  : 'RegelkreisV1/G_rphi/Ideal P Gain Fdbk/Disabled'
 * '<S84>'  : 'RegelkreisV1/G_rphi/Integrator/Continuous'
 * '<S85>'  : 'RegelkreisV1/G_rphi/Integrator ICs/Internal IC'
 * '<S86>'  : 'RegelkreisV1/G_rphi/N Copy/Disabled'
 * '<S87>'  : 'RegelkreisV1/G_rphi/N Gain/Internal Parameters'
 * '<S88>'  : 'RegelkreisV1/G_rphi/P Copy/Disabled'
 * '<S89>'  : 'RegelkreisV1/G_rphi/Parallel P Gain/Internal Parameters'
 * '<S90>'  : 'RegelkreisV1/G_rphi/Reset Signal/Disabled'
 * '<S91>'  : 'RegelkreisV1/G_rphi/Saturation/Passthrough'
 * '<S92>'  : 'RegelkreisV1/G_rphi/Saturation Fdbk/Disabled'
 * '<S93>'  : 'RegelkreisV1/G_rphi/Sum/Sum_PID'
 * '<S94>'  : 'RegelkreisV1/G_rphi/Sum Fdbk/Disabled'
 * '<S95>'  : 'RegelkreisV1/G_rphi/Tracking Mode/Disabled'
 * '<S96>'  : 'RegelkreisV1/G_rphi/Tracking Mode Sum/Passthrough'
 * '<S97>'  : 'RegelkreisV1/G_rphi/Tsamp - Integral/Passthrough'
 * '<S98>'  : 'RegelkreisV1/G_rphi/Tsamp - Ngain/Passthrough'
 * '<S99>'  : 'RegelkreisV1/G_rphi/postSat Signal/Forward_Path'
 * '<S100>' : 'RegelkreisV1/G_rphi/preSat Signal/Forward_Path'
 * '<S101>' : 'RegelkreisV1/G_rx/Anti-windup'
 * '<S102>' : 'RegelkreisV1/G_rx/D Gain'
 * '<S103>' : 'RegelkreisV1/G_rx/Filter'
 * '<S104>' : 'RegelkreisV1/G_rx/Filter ICs'
 * '<S105>' : 'RegelkreisV1/G_rx/I Gain'
 * '<S106>' : 'RegelkreisV1/G_rx/Ideal P Gain'
 * '<S107>' : 'RegelkreisV1/G_rx/Ideal P Gain Fdbk'
 * '<S108>' : 'RegelkreisV1/G_rx/Integrator'
 * '<S109>' : 'RegelkreisV1/G_rx/Integrator ICs'
 * '<S110>' : 'RegelkreisV1/G_rx/N Copy'
 * '<S111>' : 'RegelkreisV1/G_rx/N Gain'
 * '<S112>' : 'RegelkreisV1/G_rx/P Copy'
 * '<S113>' : 'RegelkreisV1/G_rx/Parallel P Gain'
 * '<S114>' : 'RegelkreisV1/G_rx/Reset Signal'
 * '<S115>' : 'RegelkreisV1/G_rx/Saturation'
 * '<S116>' : 'RegelkreisV1/G_rx/Saturation Fdbk'
 * '<S117>' : 'RegelkreisV1/G_rx/Sum'
 * '<S118>' : 'RegelkreisV1/G_rx/Sum Fdbk'
 * '<S119>' : 'RegelkreisV1/G_rx/Tracking Mode'
 * '<S120>' : 'RegelkreisV1/G_rx/Tracking Mode Sum'
 * '<S121>' : 'RegelkreisV1/G_rx/Tsamp - Integral'
 * '<S122>' : 'RegelkreisV1/G_rx/Tsamp - Ngain'
 * '<S123>' : 'RegelkreisV1/G_rx/postSat Signal'
 * '<S124>' : 'RegelkreisV1/G_rx/preSat Signal'
 * '<S125>' : 'RegelkreisV1/G_rx/Anti-windup/Passthrough'
 * '<S126>' : 'RegelkreisV1/G_rx/D Gain/Internal Parameters'
 * '<S127>' : 'RegelkreisV1/G_rx/Filter/Cont. Filter'
 * '<S128>' : 'RegelkreisV1/G_rx/Filter ICs/Internal IC - Filter'
 * '<S129>' : 'RegelkreisV1/G_rx/I Gain/Internal Parameters'
 * '<S130>' : 'RegelkreisV1/G_rx/Ideal P Gain/Passthrough'
 * '<S131>' : 'RegelkreisV1/G_rx/Ideal P Gain Fdbk/Disabled'
 * '<S132>' : 'RegelkreisV1/G_rx/Integrator/Continuous'
 * '<S133>' : 'RegelkreisV1/G_rx/Integrator ICs/Internal IC'
 * '<S134>' : 'RegelkreisV1/G_rx/N Copy/Disabled'
 * '<S135>' : 'RegelkreisV1/G_rx/N Gain/Internal Parameters'
 * '<S136>' : 'RegelkreisV1/G_rx/P Copy/Disabled'
 * '<S137>' : 'RegelkreisV1/G_rx/Parallel P Gain/Internal Parameters'
 * '<S138>' : 'RegelkreisV1/G_rx/Reset Signal/Disabled'
 * '<S139>' : 'RegelkreisV1/G_rx/Saturation/Passthrough'
 * '<S140>' : 'RegelkreisV1/G_rx/Saturation Fdbk/Disabled'
 * '<S141>' : 'RegelkreisV1/G_rx/Sum/Sum_PID'
 * '<S142>' : 'RegelkreisV1/G_rx/Sum Fdbk/Disabled'
 * '<S143>' : 'RegelkreisV1/G_rx/Tracking Mode/Disabled'
 * '<S144>' : 'RegelkreisV1/G_rx/Tracking Mode Sum/Passthrough'
 * '<S145>' : 'RegelkreisV1/G_rx/Tsamp - Integral/Passthrough'
 * '<S146>' : 'RegelkreisV1/G_rx/Tsamp - Ngain/Passthrough'
 * '<S147>' : 'RegelkreisV1/G_rx/postSat Signal/Forward_Path'
 * '<S148>' : 'RegelkreisV1/G_rx/preSat Signal/Forward_Path'
 */
#endif                                 /* RTW_HEADER_RegelkreisV1_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
