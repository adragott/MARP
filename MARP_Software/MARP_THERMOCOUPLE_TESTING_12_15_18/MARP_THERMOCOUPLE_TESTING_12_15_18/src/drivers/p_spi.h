/*
 * p_spi.h
 *
 * Created: 12/15/2018 2:21:21 PM
 *  Author: Penguin
 */ 

#ifndef _P_SPI_H_
#define _P_SPI_H_
#include <asf.h>

typedef struct p_spi_sensor
{
	struct spi_module* spi_inst;
	uint8_t ss_pin;
	uint8_t* buffer;
	//unused for now
	Sercom* hw;
}p_spi_sensor;

void pspi_init(void);

struct spi_module spi_sercom1_mod;

//See comments in implementation
void pspi_sensor_init(p_spi_sensor* sensor);

enum status_code pspi_read(p_spi_sensor* sensor, uint8_t reg, uint8_t length);
enum status_code pspi_write(p_spi_sensor* sensor, uint8_t length);



#endif