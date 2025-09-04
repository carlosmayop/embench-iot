#ifndef RV_FPGA_AXI_SERIAL_H
#define RV_FPGA_AXI_SERIAL_H

#include <types.h>
#include <rvtarget.h>

__attribute__((always_inline))
inline void axi_serial_send_char(const u8 c) {
    // Busy wait
    // RDY 1 data pending for read, wait
    while(((FPGA_SERIAL_DATA_REG >> 8) & 0x1) == 1);
    // Set data with RDY flag
    FPGA_SERIAL_DATA_REG = (1 << 8) | (0xff & c);
}

#endif
