/*
 * p_spi.c
 *
 * Created: 12/15/2018 2:21:48 PM
 *  Author: Penguin
 */ 

#include "p_spi.h"
#include "p_usart.h"
static void drive_ss_pin(uint8_t pin, uint8_t status);
static uint16_t spi_dummy = 0xFF;




#warning come back to this and separate this function for readability
void pspi_init()
{
	struct spi_config sercom_1_conf;
	spi_get_config_defaults(&sercom_1_conf);
	sercom_1_conf.character_size = SERCOM_1_CHAR_SIZE;
	sercom_1_conf.mode_specific.master.baudrate = SERCOM_1_BAUD;
	sercom_1_conf.pinmux_pad0 = EXT2_SPI_SERCOM_PINMUX_PAD0;
	sercom_1_conf.pinmux_pad1 = EXT2_SPI_SERCOM_PINMUX_PAD1;
	sercom_1_conf.pinmux_pad2 = EXT2_SPI_SERCOM_PINMUX_PAD2;
	sercom_1_conf.pinmux_pad3 = EXT2_SPI_SERCOM_PINMUX_PAD3;
	sercom_1_conf.mux_setting = EXT2_SPI_SERCOM_MUX_SETTING; //Extremely important
	
	
	
	spi_init(&spi_sercom1_mod, SERCOM1, &sercom_1_conf);
	spi_enable(&spi_sercom1_mod);
	
	
	
	 
	
	
}

//Unused for now. Eventually will automatically attach sensors to their respective modules
void pspi_sensor_init(p_spi_sensor* sensor)
{
	
}

enum status_code pspi_read(p_spi_sensor* sensor, uint8_t reg, uint8_t length)
{
	//unused error handling for now
	enum status_code ret = STATUS_OK;
	drive_ss_pin(sensor->ss_pin, LOW);
	ret = spi_write_buffer_wait(sensor->spi_inst, &reg, 1);
	if(ret != STATUS_OK)
	{
		DEBUG("Error on write\n");
		delay_ms(100000);
		
	}
	ret = spi_read_buffer_wait(sensor->spi_inst, sensor->buffer, length, spi_dummy);
	if(ret != STATUS_OK)
	{
		DEBUG("Error on read\n");
		delay_ms(100000);
	}
	drive_ss_pin(sensor->ss_pin, HIGH);
	return ret;
}

enum status_code pspi_write(p_spi_sensor* sensor, uint8_t length)
{
	enum status_code ret = STATUS_OK;
	drive_ss_pin(sensor->ss_pin, LOW);
	ret = spi_write_buffer_wait(sensor->spi_inst, sensor->buffer, length);
	drive_ss_pin(sensor->ss_pin, HIGH);
	if(ret != STATUS_OK) {DEBUG("somethings goofed\n"); delay_ms(100000);}
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

