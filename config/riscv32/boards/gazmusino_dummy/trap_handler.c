#include "csr.h"
#include "mtimer.h"

#include <stdio.h>
#include <stdlib.h>

void _trap_handler() {
    u32 mcause = read_mcause();

    switch (mcause) {
        case MCAUSE_TIMER_IRQ:
            _mtimer_irq();
            break;
        default:
            printf("Unexpected mcause found: 0x%08lx\n", mcause);
            printf("MEPC: 0x%08lx\n", read_mepc());
            printf("MSCRATCH: 0x%08lx\n", read_mscratch());
            //exit(mcause);
    }
}
