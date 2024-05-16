#ifndef __AIR780_H
#define __AIR780_H

#include "main.h"

void Air780_Reset(void);
void Air780_Init(void);
void Air780_PDPact(void);
void Air780_FlightMode(void);
void Air780_GetTime(void);

extern const char * ProductID;
extern const char * DeviceName;

#endif
