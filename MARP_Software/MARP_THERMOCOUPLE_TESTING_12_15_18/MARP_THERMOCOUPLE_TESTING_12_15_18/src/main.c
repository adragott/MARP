/**
 * \file
 *
 * \brief Empty user application template
 *
 */

/**
 * \mainpage User Application template doxygen documentation
 *
 * \par Empty user application template
 *
 * This is a bare minimum user application template.
 *
 * For documentation of the board, go \ref group_common_boards "here" for a link
 * to the board-specific documentation.
 *
 * \par Content
 *
 * -# Include the ASF header files (through asf.h)
 * -# Minimal main function that starts with a call to system_init()
 * -# Basic usage of on-board LED and button
 * -# "Insert application code here" comment
 *
 */

/*
 * Include header files for all drivers that have been imported from
 * Atmel Software Framework (ASF).
 */
/*
 * Support and FAQ: visit <a href="https://www.microchip.com/support/">Microchip Support</a>
 */
#include <asf.h>
#include "p_usart.h"
#include "p_spi.h"
#include <inttypes.h>
static int service_handler(void);

static p_spi_sensor test;

uint8_t tempbuf[10];

typedef union dataBytes
{
	uint32_t resultData;
	uint8_t readBuffer[4];
}dataBytes;

int main (void)
{
	union dataBytes data;
	test.buffer = data.readBuffer;
	test.hw = SERCOM1;
	test.spi_inst = &spi_sercom1_mod;
	test.ss_pin = 10;
	
	
	system_init();
	pusart_init();
	pspi_init();
	system_interrupt_enable_global();
	volatile uint32_t readval = 0x0;
	PORT->Group[0].DIR.bit.DIR |= (1 << 10);
	PORT->Group[0].OUT.bit.OUT |= (1 << 10);
	for(int x = 0; x < 10; x++)
	{
		tempbuf[x] = 0x0;
	}
	for(;;)
	{
		
		
		uint8_t tempbuf2[4];
		PORT->Group[0].OUT.bit.OUT &= ~(1 << 10);
		delay_ms(1);
		spi_read_buffer_wait(&spi_sercom1_mod, &data.readBuffer[3], 1, 0x00);
		spi_read_buffer_wait(&spi_sercom1_mod, &data.readBuffer[2], 1, 0x00);
		spi_read_buffer_wait(&spi_sercom1_mod, &data.readBuffer[1], 1, 0x00);
		spi_read_buffer_wait(&spi_sercom1_mod, &data.readBuffer[0], 1, 0x00);
		
		DEBUG("%#x\t%#x\t%#x\t%#x\n", data.readBuffer[0], data.readBuffer[1], data.readBuffer[2], data.readBuffer[3]);
		PORT->Group[0].OUT.bit.OUT |= (1 << 10);
		float tempfloat = 0.f;
		uint16_t tempData;
		if(data.resultData & (uint32_t)1 << 31)
		{
			tempData = 0xC000 | ((data.resultData >> 18) & 0x3FFF);
		}
		else
		{
			tempData = data.resultData >> 18;
		}
		tempfloat = (float)(tempData/4.0);
		DEBUG("%f\n", tempfloat);
		
		//service_handler();
		delay_ms(100);
		
	}
	
}

int service_handler(void)
{
	pusart_service();
	
	return 0;
}