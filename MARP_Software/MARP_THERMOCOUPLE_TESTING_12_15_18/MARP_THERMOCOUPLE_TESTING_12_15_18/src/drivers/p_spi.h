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

void p_spi_init();

struct spi_module spi_sercom5_mod;
struct spi_module spi_sercom1_mod;

//See comments in implementation
void p_spi_sensor_init(p_spi_sensor* sensor);

enum status_code p_spi_read(p_spi_sensor* sensor, uint8_t reg, uint8_t length);
enum status_code p_spi_write(p_spi_sensor* sensor, uint8_t length);



#endif