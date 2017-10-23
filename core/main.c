#include <phidias.h>
#include <misc_ops.h>
#include <linker_symbols.h>
#include <memarea.h>
#include <version.h>
#include <drivers/uart.h>
#include <drivers/clock.h>
#include <drivers/timer.h>
#include <drivers/irq.h>
#include <xcore.h>
#include <trace.h>
#include <schedule.h>

uint32_t cpu_number = 0;

void prepare_areas(uint32_t cpu) {
	memcpy(	(void *)_specification.cpus[cpu].memareas[MEMAREA_CORE_RW].vaddr,
		(void *)_specification.cpus[cpu].memareas[MEMAREA_CORE_RWT].vaddr,
		__phidias_data_end - __phidias_data_start);

	memcpy(	(void *)_specification.cpus[cpu].memareas[MEMAREA_CONFIG_RW].vaddr,
		(void *)_specification.cpus[cpu].memareas[MEMAREA_CONFIG_RWT].vaddr,
		_specification.cpus[cpu].memareas[MEMAREA_CONFIG_RWT].size);
}

static void print_banner() {
	if (cpu_number == 0) {
		printf("\e[34;1mPHIDIAS v%d.%3d (git rev %s, toolchain %s/%s)\r\n",
			PHIDIAS_VERSION_MAJOR,
			PHIDIAS_VERSION_MINOR,
			phidias_buildstamp_git_revision,
			gcc_version, binutils_version);
		printf("Build: C %s I %s\e[0m\r\n",
			phidias_buildstamp_time_compile,
			_specification.timestamp);
	}

	printf("\e[34mPHIDIAS CPU #%d up.\e[0m\r\n",
			cpu_number);
}

void __attribute__((section(".text"))) main() {

    if (cpu_number == 0 || cpu_number == 1) {
		uart_setup();
	}

	print_banner();

	if (cpu_number == 0) {
		platform_boot_cpus();
	}

	xcore_setup();

	clock_setup();
	timer_setup();
	irq_setup();

	trace_setup();
 #if 0
     /* Enable CLock of USB
           clk0_en offset    0x200 
       #define PERI_CLK0_USBOTG              (1 << 4)*/
      uint32_t data;
      volatile uint32_t *xva = (volatile uint32_t *)core_memarea(MEMAREA_THERMAL)->vaddr;
      data = xva[0x200];
      printf("USB DWC2 clock read %x\r\n", xva[ 0x200]);
      data |= (1 << 4);
      
      xva[ 0x200]= (1 << 4);
    
      do {
           data = xva[ 0x200 + 0x02];
      } while ((data & (1 << 4)) == 0);
      printf("USB DWC2 clock enabled\r\n");
    
     /* take usb IPs out of reset */
     xva[  0x304] =(1 << 4) | (1 << 5) | (1 << 6) | (1 << 7);
    
    
    do {
        data = xva[  0x308];
        data &= (1 << 4) | (1 << 5) | (1 << 6) | (1 << 7);
    } while (data);
    
    
    /*CTRL 5*/
    data = xva[  0x10];
    data &= ~(1 << 5);
    data |= (1 << 3) | (1 << 4);
    data |= 0x300;
    xva[  0x10] = data;
    
    /*CTRL 4*/
    
    /* configure USB PHY */
    data = xva[  0xc];
    
    /* make PHY out of low power mode */
    data &= ~(1 << 6);
    data &= ~(1 << 8);
    data |= (1 << 11) | (1 << 10);
    xva[  0xc] = data;
    
    xva[  0x18] = 0x70533483;
#endif
	sched_start();

	reschedule();
}
