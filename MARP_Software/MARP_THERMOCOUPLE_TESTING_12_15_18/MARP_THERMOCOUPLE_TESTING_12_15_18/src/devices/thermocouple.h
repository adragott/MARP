/*
 * thermocouple.h
 *
 * Created: 12/15/2018 2:20:59 PM
 *  Author: Penguin
 */ 

#ifndef _THERMOCOUPLE_H_
#define _THERMOCOUPLE_H_

#include <asf.h>

#define MAX_THERMO_SAMPLE_COUNT 64

typedef struct thermocouple
{
	uint8_t id;
	float voltage[MAX_THERMO_SAMPLE_COUNT];
	float temp[MAX_THERMO_SAMPLE_COUNT];
}thermocouple;

void thermocouple_init(uint8_t ID);

void fill_thermo_data(void);

void get_thermo_data(thermocouple* inst);


#endif