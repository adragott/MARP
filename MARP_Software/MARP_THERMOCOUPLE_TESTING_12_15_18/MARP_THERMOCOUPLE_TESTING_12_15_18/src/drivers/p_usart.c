/*
 * p_usart.c
 *
 * Created: 12/15/2018 2:22:12 PM
 *  Author: Penguin
 */ 
#include "p_usart.h"
#include <stdarg.h>
#include <string.h>
#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
volatile uint8_t debug_buffer[DEBUG_MAX_BUFFER_SIZE];
uint8_t pprint_buffer[PPRINT_BUFFER_SIZE];
static uint16_t pprint_ctr = 0;

static void debug_rx_cb(struct usart_module* const mod);
static void debug_tx_cb(struct usart_module* const mod);

void pusart_init(void)
{
	struct usart_config debug_conf;
	usart_get_config_defaults(&debug_conf);
	debug_conf.baudrate =		SERCOM_3_BAUD;
	debug_conf.character_size = SERCOM_3_CHAR_SIZE;
	debug_conf.parity =			SERCOM_3_PARITY;
	debug_conf.stopbits =		SERCOM_3_STOP_BIT;
	debug_conf.pinmux_pad0 =	SERCOM_3_PIN0;
	debug_conf.pinmux_pad1 =	SERCOM_3_PIN1;
	debug_conf.pinmux_pad2 =	SERCOM_3_PIN2;
	debug_conf.pinmux_pad3 =	SERCOM_3_PIN3;
	debug_conf.mux_setting =	SERCOM_3_MUX_SETTING;
	
	usart_init(DEBUG_MOD, DEBUG_SERCOM, &debug_conf);
	usart_enable(DEBUG_MOD);
	
	usart_register_callback(DEBUG_MOD, debug_rx_cb, USART_CALLBACK_BUFFER_RECEIVED);
	usart_enable_callback(DEBUG_MOD, USART_CALLBACK_BUFFER_RECEIVED);
	
	usart_register_callback(DEBUG_MOD, debug_tx_cb, USART_CALLBACK_BUFFER_TRANSMITTED);
	usart_enable_callback(DEBUG_MOD, USART_CALLBACK_BUFFER_TRANSMITTED);
	pprint(DEBUG_MOD, DEBUG_STARTUP_MSG);
}

void pprint(struct usart_module* mod, const char* str, ...)
{
	va_list args;
	va_start(args, str);
	vsprintf(pprint_buffer, str, args);
	va_end(args);
	uint16_t strsize = (uint16_t)strlen(pprint_buffer);
	usart_write_buffer_wait(DEBUG_MOD, pprint_buffer, strsize);	
}

void pusart_service(void)
{
	usart_read_buffer_job(DEBUG_MOD, debug_buffer, DEBUG_MAX_BUFFER_SIZE);
}

void debug_rx_cb(struct usart_module* const mod)
{
	pprint("%s", &debug_buffer[0]);
}

void debug_tx_cb(struct usart_module* const mod)
{
	const char* pprint_buffer_temp = pprint_buffer;
	uint16_t temp_ctr = 0;
	while(*pprint_buffer_temp++)
	{
		temp_ctr++;
	};
	memset(pprint_buffer, '\0', temp_ctr);
}
