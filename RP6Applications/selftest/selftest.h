//
//  selftest.h
//  RP6Applications
//
//  Created by Maximilian Voss on 23/12/14.
//  Copyright (c) 2014 Maximilian Voss. All rights reserved.
//

#ifndef RP6Applications_selftest_h
#define RP6Applications_selftest_h

#include <core/core.h>
#include <uart/uart.h>
#include <scheduler/scheduler.h>
#include <engine/engine.h>
#include <powermgmt/powermgmt.h>

#include "testLEDs.h"
#include "testPowerOn.h"
#include "testVoltageSensor.h"
#include "testBumpers.h"
#include "testLightSensors.h"
#include "testACS.h"
#include "testRC5.h"


void printUBat(uint16_t uBat);
uint8_t getInputLine(void);

#endif
