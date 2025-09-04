#ifndef RV_TARGET_H
#define RV_TARGET_H

#define MEM_SIZE 262143k  // Max Addr 0x0ffffc00
#define STACK_SIZE 51200k // 50 MiB
#define HEAP_SIZE 51200k  // 50 MiB

// Profiler internal counters
#define NUM_PROFILER_COUNTERS 8

// mtimer MMIO 
#define MTIMER_BASE_ADDR 0x10500000
#define MTIMER_COUNTER      *((volatile uint64_t *) MTIMER_BASE_ADDR)
#define MTIMER_CMP          *((volatile uint64_t *) (MTIMER_BASE_ADDR + 8))

// FPGA serial MMIO
#define FPGA_SERIAL_DATA_ADDR   0x10510000
#define FPGA_SERIAL_DATA_REG    *((volatile uint32_t *) FPGA_SERIAL_DATA_ADDR)

// Serial print register MMIO 
#define PRINT_REG_ADDR 0x10600000
#define PRINT_REG       *((volatile uint32_t *) PRINT_REG_ADDR)

// Exit/Reset status MMIO
#define EXIT_STATUS_ADDR 0x10601000
#define EXIT_STATUS_REG *((volatile uint32_t *) EXIT_STATUS_ADDR)

// Debug stop MMIO
#define DEBUG_REQ_ADDR 0x10602000
#define DEBUG_REQ_REG *((volatile uint32_t *) DEBUG_REQ_ADDR)

// Debug trace start/stop MMIO
#define DEBUG_TRACE_ADDR 0x10603000
#define DEBUG_TRACE_REG *((volatile uint32_t *) DEBUG_TRACE_ADDR)

// Profiler counter MMIO
#define PROFILER_SINGLE_MODE 0 // Default
#define PROFILER_ACC_MODE 1

#define PROFILER_BASE_ADDR 0x10700000
#define PROFILER_COUNTER_START *((volatile uint32_t *) PROFILER_BASE_ADDR)
#define PROFILER_STOP_ADDR (PROFILER_BASE_ADDR + 4)
#define PROFILER_COUNTER_STOP *((volatile uint32_t *) PROFILER_STOP_ADDR)
#define PROFILER_MODE_ADDR (PROFILER_STOP_ADDR + 4)
#define PROFILER_MODE *((volatile uint32_t *) PROFILER_STOP_ADDR)

#endif
