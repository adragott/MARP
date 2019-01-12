/*
 * p_usart.h
 *
 * Created: 12/15/2018 2:22:02 PM
 *  Author: Penguin
 */ 

#ifndef _P_USART_H_
#define _P_USART_H_
#include <asf.h>

void pusart_init(void);
void pprint(struct usart_module* mod, const char* str, ...);
void pusart_service(void);
struct usart_module debug_mod;

#define DEBUG(str, ...) pprint(DEBUG_MOD, (str), ##__VA_ARGS__)
#endif
