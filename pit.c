#include "platform.h"

#define PIT_CHNCTRL_CLK_EXTERNAL        (0 << 3)
#define PIT_CHNCTRL_CLK_PCLK            (1 << 3)

void pit_init(void)
{
	/* Disable PIT */
	DEV_PIT->CHNEN = 0;

	/* Set PIT control mode */
	DEV_PIT->CHANNEL[0].CTRL = (PIT_CHNCTRL_TMR_32BIT | PIT_CHNCTRL_CLK_PCLK);
	DEV_PIT->CHANNEL[1].CTRL = (PIT_CHNCTRL_TMR_32BIT | PIT_CHNCTRL_CLK_PCLK);
	DEV_PIT->CHANNEL[2].CTRL = (PIT_CHNCTRL_TMR_32BIT | PIT_CHNCTRL_CLK_PCLK);
	DEV_PIT->CHANNEL[3].CTRL = (PIT_CHNCTRL_TMR_32BIT | PIT_CHNCTRL_CLK_PCLK);

	/* Clear and disable interrupt */
	DEV_PIT->INTEN = 0;
	DEV_PIT->INTST = -1;
}

void pit_start(unsigned int ch)
{
	if (ch < 4)
		DEV_PIT->CHNEN |= (0x1 << (4 * (ch)));
}

void pit_stop(unsigned int ch)
{
	if (ch < 4)
		DEV_PIT->CHNEN &= ~(0x1 << (4 * (ch)));
}

unsigned int pit_read(unsigned int ch)
{
	if (ch < 4)
		return	(DEV_PIT->CHANNEL[ch].RELOAD - DEV_PIT->CHANNEL[ch].COUNTER);
	else
		return 0;
}

void pit_set_period(unsigned int ch, unsigned int period)
{
	if (ch < 4)
		DEV_PIT->CHANNEL[ch].RELOAD = period;
}

void pit_irq_enable(unsigned int ch)
{
	if (ch < 4)
		DEV_PIT->INTEN |= (0x1 << (4 * (ch)));
}

void pit_irq_disable(unsigned int ch)
{
	if (ch < 4)
		DEV_PIT->INTEN &= ~(0x1 << (4 * (ch)));
}

void pit_irq_clear(unsigned int ch)
{
	if (ch < 4)
		DEV_PIT->INTST = 0xF << (4 * (ch));
}

unsigned int pit_irq_status(unsigned int ch)
{
	return (DEV_PIT->INTST & (0xF << (4 * (ch))));
}
