#ifndef __PIT_H__
#define __PIT_H__
extern void pit_init(void);
extern void pit_start(unsigned int ch);
extern void pit_stop(unsigned int ch);
extern unsigned int pit_read(unsigned int ch);
extern void pit_set_period(unsigned int ch, unsigned int period);
extern void pit_irq_enable(unsigned int ch);
extern void pit_irq_disable(unsigned int ch);
extern void pit_irq_clear(unsigned int ch);
extern unsigned int pit_irq_status(unsigned int ch);
#endif	// __PIT_H__
