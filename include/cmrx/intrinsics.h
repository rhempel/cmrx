#pragma once

/** Get value of process SP
 * @return top of application stack
 */
__attribute__((always_inline)) static inline void * __get_PSP(void)
{
	void * psp;
	asm volatile(
			".syntax unified\n\t"
			"MRS %0, psp\n\t"
			: "=r" (psp) 
			:
			: "sp"
	);

	return psp;
}

/** Set value of process SP
 * @param stack_top new top of application stack
 */
__attribute__((always_inline)) static inline void __set_PSP(uint32_t * stack_top)
{
	asm volatile(
			".syntax unified\n\t"
			"MSR psp, %0\n\t"
			: : "r" (stack_top)
	);
}

/** Save application context.
 * This function will grab process SP
 * @return top of application stack after application context was saved
 */
__attribute__((always_inline)) static inline void * save_context()
{
	uint32_t * scratch;
	asm (
			".syntax unified\n\t"
			"MRS %0, PSP\n\t"
			"SUBS %0, #16\n\t"
			"STMEA %0!, {r4 - r7}\n\t"
			"SUBS %0, #32\n\t"
			"MOV r4, r8\n\t"
			"MOV r5, r9\n\t"
			"MOV r6, r10\n\t"
			"MOV r7, r11\n\t"
			"STMEA %0!, {r4 - r7}\n\t"
			"SUBS %0, #16\n\t"
			: "=r" (scratch)
			:
			: "r4", "r5", "r6", "r7", "r8", "r9", "r10", "r11"
	);

	return scratch;
}

/** Load application context saved by save_context
 * from address sp.
 * @param sp address where top of the stack containing application context is
 */
__attribute__((always_inline)) static inline void load_context(uint32_t * sp)
{
	asm (
			"LDMFD %0!, {r4 - r7}\n\t"
			"MOV r8, r4\n\t"
			"MOV r9, r5\n\t"
			"MOV r10, r6\n\t"
			"MOV r11, r7\n\t"
			"LDMFD %0!, {r4 - r7}\n\t"
			"MSR PSP, %0\n\t"
			:
			: [scratch] "r" (sp)
			: "r4", "r5", "r6", "r7", "r8", "r9", "r10", "r11"
	);
}

__attribute__((always_inline)) static inline void __set_CONTROL(uint32_t control)
{
	asm volatile("MSR control, %0\n" : : "r" (control) : "memory");
}

__attribute__((always_inline)) static inline void __DSB()
{
	asm volatile("DSB 0xF\n" : : : "memory");	
}

__attribute__((always_inline)) static inline void __ISB()
{
	asm volatile("ISB 0xF\n" : : : "memory");	
}


