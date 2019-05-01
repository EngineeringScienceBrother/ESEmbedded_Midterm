#include <stdint.h>
#include "reg.h"
#include "blink.h"

extern int main(void);

extern  void blink(unsigned int led);

void set_sysclk_pll(void);

void reset_handler(void)
{
	
	extern uint32_t _mydata_lma_start;
	extern uint32_t _mydata_vma_start;
	extern uint32_t _mydata_vma_end;
	extern uint32_t _mybss_vma_start;
	extern uint32_t _mybss_vma_end;


	uint32_t *mydata_lstart_ptr = &_mydata_lma_start;
	uint32_t *mydata_vstart_ptr = &_mydata_vma_start;
	uint32_t *mydata_vend_ptr = &_mydata_vma_end;

	uint32_t *mybss_vstart_ptr = &_mybss_vma_start;
	uint32_t *mybss_vend_ptr = &_mybss_vma_end;

	uint32_t *src_ptr, *dst_ptr;

	src_ptr = mydata_lstart_ptr;
	dst_ptr = mydata_vstart_ptr;

	while (dst_ptr < mydata_vend_ptr)
		*dst_ptr++ = *src_ptr++;

	dst_ptr = mybss_vstart_ptr;

	while (dst_ptr < mybss_vend_ptr)
		*dst_ptr++ = 0;
	
	set_sysclk_pll();

	main();
}

void set_sysclk_pll(void)
{
	
	WRITE_BITS(RCC_BASE + RCC_CR_OFFSET, HSION_BIT, HSION_BIT, 0b1);
 
	
	while (READ_BIT(RCC_BASE + RCC_CR_OFFSET, HSIRDY_BIT) != 1);

	WRITE_BITS(RCC_BASE + RCC_PLLCFGR_OFFSET, PLLP_1_BIT, PLLP_0_BIT, 0b00);
	WRITE_BITS(RCC_BASE + RCC_PLLCFGR_OFFSET, PLLN_8_BIT, PLLN_0_BIT, 168);
	WRITE_BITS(RCC_BASE + RCC_PLLCFGR_OFFSET, PLLM_5_BIT, PLLM_0_BIT, 0b0001000);
	

	
	WRITE_BITS(RCC_BASE + RCC_CR_OFFSET, PLLON_BIT, PLLON_BIT, 0b1);

	
	while (READ_BIT(RCC_BASE + RCC_CR_OFFSET, PLLRDY_BIT) != 1);

	
	WRITE_BITS(FLASH_BASE + FLASH_ACR_OFFSET, PRFTEN_BIT, PRFTEN_BIT, 0b1);


	WRITE_BITS(FLASH_BASE + FLASH_ACR_OFFSET, LATENCY_2_BIT, LATENCY_0_BIT, 0b101);

	WRITE_BITS(RCC_BASE + RCC_CFGR_OFFSET, SW_1_BIT, SW_0_BIT, 0b10);

	while (  (READ_BIT(RCC_BASE + RCC_CFGR_OFFSET, SWS_1_BIT) != 1) || (READ_BIT(RCC_BASE + RCC_CFGR_OFFSET, SWS_0_BIT) != 0) );
		

}
