#include<stdint.h>

/* This function executes in THREAD MODE */
void generate_RTC_WKUP_interrupt()
{
	uint32_t *pSTIR  = (uint32_t*)0xE000EF00;
	uint32_t *pISER0 = (uint32_t*)0xE000E100;

	*pISER0 |= (1 << 3);	//enable IRQ3 interrupt
	*pSTIR = (3 & 0x1FF);	//generate an interrupt from software for IRQ3
}

/* This function executes in THREAD MODE */
int main(void)
{
	generate_RTC_WKUP_interrupt();
	for(;;);
}

/* This (ISR) interrupt-function executes in HANDLER MODE */
void RTC_WKUP_IRQHandler(void)
{
	asm("nop"); // Assembly instruction which does nothing
}
