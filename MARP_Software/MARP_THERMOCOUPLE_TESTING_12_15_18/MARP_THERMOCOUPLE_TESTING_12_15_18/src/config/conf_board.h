/*
Serial Bus Tree Structure

//Serial Type
//SERCOMx
Sercom bus configuration settings

	//Device name
	Device specific configuration settings
	
	//Device name
	Device specific configuration settings
*/

#ifndef CONF_BOARD_H_INCLUDED
#define CONF_BOARD_H_INCLUDED

//SPI Bus Configuration
//SERCOM 1
#define SERCOM_1_BAUD			4000000
#define SERCOM_1_CHAR_SIZE		SPI_CHARACTER_SIZE_8BIT
#define SERCOM_1_PIN0			PINMUX_PA16C_SERCOM1_PAD0	//MISO
#define SERCOM_1_PIN1			PINMUX_PA17C_SERCOM1_PAD1	//HW CS
#define SERCOM_1_PIN2			PINMUX_PA18C_SERCOM1_PAD2	//MOSI
#define SERCOM_1_PIN3			PINMUX_PA19C_SERCOM1_PAD3	//SCK

	//SD Card
	#define SD_SERCOM				SERCOM1
	#define SD_SS					16

	//Thermo
	#define THERMO_SERCOM			SERCOM1
	#define THERMO_SPI_BAUD			SERCOM_1_BAUD
	#define THERMO_OVERSAMPLE_RATE	16
	
	#define THERMO_SS_0				10
	#define THERMO_SS_1				11
	#define THERMO_SS_2				20
	#define THERMO_SS_3				21

//USART Configuration
//Sercom 3
#define SERCOM_3_BAUD				115200
#define SERCOM_3_CHAR_SIZE			USART_CHARACTER_SIZE_8BIT
#define SERCOM_3_PARITY				USART_PARITY_NONE
#define SERCOM_3_STOP_BIT			USART_STOPBITS_1
#define SERCOM_3_PIN0				PINMUX_PA22C_SERCOM3_PAD0
#define SERCOM_3_PIN1				PINMUX_PA23C_SERCOM3_PAD1
#define SERCOM_3_PIN2				PINMUX_UNUSED
#define SERCOM_3_PIN3				PINMUX_UNUSED
#define SERCOM_3_MUX_SETTING		USART_RX_1_TX_0_XCK_1
	
	//Debug Configuration
	#define DEBUG_SERCOM				SERCOM3
	#define DEBUG_MOD					(&debug_mod)
	#define DEBUG_USART_BAUD			SERCOM_3_BAUD
	#define DEBUG_STARTUP_MSG			"USART INITIALIZED\n"
	#define DEBUG_MAX_BUFFER_SIZE		1
	#define PPRINT_BUFFER_SIZE			256


#endif /* CONF_BOARD_H_INCLUDED */
