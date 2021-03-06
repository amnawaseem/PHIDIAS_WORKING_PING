#ifndef	_PHIDIAS_ASM_UART_PL011_H_
#define	_PHIDIAS_ASM_UART_PL011_H_

#include <asm/amba.h>

#define	PL011REG_UARTDR		0x000
#define	PL011REG_UARTFR		0x018
#define	PL011REG_UARTIBRD	0x024
#define	PL011REG_UARTFBRD	0x028
#define	PL011REG_UARTLCR	0x02c
#define	PL011REG_UARTCR		0x030
#define	PL011REG_UARTIFLS	0x034
#define	PL011REG_UARTIMSC	0x038
#define	PL011REG_UARTRIS	0x03c
#define	PL011REG_UARTMIS	0x040
#define	PL011REG_UARTICR	0x044

#define	PL011BIT_UARTFR_TXFE	0x80
#define	PL011BIT_UARTFR_RXFF	0x40
#define	PL011BIT_UARTFR_TXFF	0x20
#define	PL011BIT_UARTFR_RXFE	0x10
#define	PL011BIT_UARTFR_BUSY	0x08
#define	PL011BIT_UARTCR_RXEN	0x200
#define	PL011BIT_UARTCR_TXEN	0x100
#define	PL011BIT_UARTCR_EN	0x001
#define	PL011BIT_UARTLCR_WLEN8	0x60
#define	PL011BIT_UARTLCR_FEN	0x10
#define	PL011BIT_UARTIMSC_MASKALL	0x7ff
#define	PL011BIT_UARTIRQ_RT		0x040
#define	PL011BIT_UARTIRQ_TX		0x020
#define	PL011BIT_UARTIRQ_RX		0x010

#endif
