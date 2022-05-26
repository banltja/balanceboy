/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: TestDerSensoren.c
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

#include "TestDerSensoren.h"
#include <string.h>
#include "rtwtypes.h"
#include <stddef.h>

/* Block states (default storage) */
DW_TestDerSensoren_T TestDerSensoren_DW;

/* Real-time model */
static RT_MODEL_TestDerSensoren_T TestDerSensoren_M_;
RT_MODEL_TestDerSensoren_T *const TestDerSensoren_M = &TestDerSensoren_M_;

/* Model step function */
void TestDerSensoren_step(void)
{
  int8_T rtb_InfraredSensor_0;
  uint8_T IRdata;
  uint8_T proximity;

  /* MATLABSystem: '<Root>/Infrared Sensor' */
  IRdata = getInfraredSensorValue(1, 1, 0, &proximity);
  memcpy((void *)&rtb_InfraredSensor_0, (void *)&IRdata, (uint32_T)((size_t)1 *
          sizeof(int8_T)));

  /* S-Function (ev3_lcd): '<S1>/LCD' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion'
   *  MATLABSystem: '<Root>/Infrared Sensor'
   */
  IRdata = 0U;
  lcdDisplay(rtb_InfraredSensor_0, &IRdata, 1U, 1U);
}

/* Model initialize function */
void TestDerSensoren_initialize(void)
{
  /* Start for S-Function (ev3_lcd): '<S1>/LCD' */
  initLCD();

  /* Start for MATLABSystem: '<Root>/Infrared Sensor' */
  TestDerSensoren_DW.obj.matlabCodegenIsDeleted = false;
  TestDerSensoren_DW.obj.isInitialized = 1;
  initInfraredSensor(1, 0);
  TestDerSensoren_DW.obj.isSetupComplete = true;
}

/* Model terminate function */
void TestDerSensoren_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/Infrared Sensor' */
  if (!TestDerSensoren_DW.obj.matlabCodegenIsDeleted) {
    TestDerSensoren_DW.obj.matlabCodegenIsDeleted = true;
    if ((TestDerSensoren_DW.obj.isInitialized == 1) &&
        TestDerSensoren_DW.obj.isSetupComplete) {
      terminateInfraredSensor(1);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Infrared Sensor' */

  /* Terminate for S-Function (ev3_lcd): '<S1>/LCD' */
  terminateLCD();
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
