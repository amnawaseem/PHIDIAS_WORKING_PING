#ifndef	_PHIDIAS_ASM_UART_PIC32_H_
#define	_PHIDIAS_ASM_UART_PIC32_H_

/* adresses for PPS regs */
#define PIC32REG_U4RXR		0xBF801480
#define PIC32REG_RPD4R		0xBF8015D0

/* offset defines */
#define PIC32REG_UXMODE		0x00
#define PIC32REG_UXSTA		0x10
#define PIC32REG_UXTXREG	0x20
#define PIC32REG_UXRXREG	0x30
#define PIC32REG_UXBRG		0x40

/* bit mask defines */
/* U4MODE */
#define PIC32BIT_UXON		0x8000
#define PIC32BIT_UXSIDL		0x2000
#define PIC32BIT_UXIREN		0x1000
#define PIC32BIT_UXRTSMD	0x0800
#define PIC32BIT_UXUEN		0x0300
#define PIC32BIT_UXWAKE		0x0080
#define PIC32BIT_UXLPBACK	0x0040
#define PIC32BIT_UXABAUD	0x0020
#define PIC32BIT_UXRXINV	0x0010
#define PIC32BIT_UXBRGH		0x0008
#define PIC32BIT_UXPDSEL	0x0006
#define PIC32BIT_UXSTSEL	0x0001

/* U4STA */
#define PIC32BIT_UXADM_EN	0x01000000
#define PIC32BIT_UXADDR		0x00FF0000
#define PIC32BIT_UXUTXISEL	0x0000C000
#define PIC32BIT_UXUTXINV	0x00002000
#define PIC32BIT_UXURXEN	0x00001000
#define PIC32BIT_UXUTXBRK	0x00000800
#define PIC32BIT_UXUTXEN	0x00000400
#define PIC32BIT_UXUTXBF	0x00000200
#define PIC32BIT_UXTRMT		0x00000100
#define PIC32BIT_UXURXISEL	0x000000C0
#define PIC32BIT_UXADDEN	0x00000020
#define PIC32BIT_UXRIDLE	0x00000010
#define PIC32BIT_UXPERR		0x00000008
#define PIC32BIT_UXFERR		0x00000004
#define PIC32BIT_UXOERR		0x00000002
#define PIC32BIT_UXURXDA	0x00000001

/* U4TXREG,RXREG and BRG */
#define PIC32BIT_UXTX		0xFF
#define PIC32BIT_UXRX		0xFF
#define PIC32BIT_UXBRG		0xFFFF

#endif
