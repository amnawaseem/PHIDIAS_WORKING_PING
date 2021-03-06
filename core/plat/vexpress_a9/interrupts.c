#include <phidias.h>
#include <interrupts.h>
#include <drivers/timer.h>
#include <drivers/uart.h>

irqhandler_function * const irqhandlers[IRQID_MAXIMUM] = {
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, &timer_interrupt, 0, 0,
	0, 0, 0, 0, 0, &uart_irq
};
