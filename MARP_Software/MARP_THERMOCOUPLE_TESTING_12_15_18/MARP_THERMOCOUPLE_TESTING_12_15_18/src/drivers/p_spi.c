/*
 * p_spi.c
 *
 * Created: 12/15/2018 2:21:48 PM
 *  Author: Penguin
 */ 

#include "p_spi.h"

static void drive_ss_pin(uint8_t pin, uint8_t status);
static uint16_t spi_dummy = 0xFF;

#warning come back to this and separate this function for readability
void p_spi_init()
{
	
}

//Unused for now. Eventually will automatically attach sensors to their respective modules
void p_spi_sensor_init(p_spi_sensor* sensor)
{
	
}

enum status_code p_spi_read(p_spi_sensor* sensor, uint8_t reg, uint8_t length)
{
	//unused error handling for now
	enum status_code ret = STATUS_OK;
	drive_ss_pin(sensor->ss_pin, LOW);
	ret = spi_write_buffer_wait(sensor->spi_inst, &reg, 1);
	if(ret != STATUS_OK)
	{
		printf("Error on write\n");
		delay_ms(100000);
		
	}
	ret = spi_read_buffer_wait(sensor->spi_inst, sensor->buffer, length, spi_dummy);
	if(ret != STATUS_OK)
	{
		printf("Error on read\n");
		delay_ms(100000);
	}
	drive_ss_pin(sensor->ss_pin, HIGH);
	return ret;
}

enum status_code p_spi_write(p_spi_sensor* sensor, uint8_t length)
{
	
	enum status_code ret = STATUS_OK;
	drive_ss_pin(sensor->ss_pin, LOW);
	ret = spi_write_buffer_wait(sensor->spi_inst, sensor->buffer, length);
	drive_ss_pin(sensor->ss_pin, HIGH);
	if(ret != STATUS_OK) {printf("somethings goofed\n"); delay_ms(100000);}
	return ret;
}

void drive_ss_pin(uint8_t pin, uint8_t status)
{
	if(pin < 32)
	{
		if(status == HIGH)
		{
			PORT->Group[0].OUT.reg |= (1 << pin);
		}
		else
		{
			PORT->Group[0].OUT.reg &= ~(1 << pin);
		}
	}
	else
	{
		if(status == HIGH)
		{
			PORT->Group[1].OUT.reg |= (1 << pin);
		}
		else
		{
			PORT->Group[1].OUT.reg &= ~(1 << pin);
		}
	}
}

