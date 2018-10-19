#ifndef __MODULE_CONF_H
#define __MODULE_CONF_H


// UART_DATA_OFFLOAD: Option to push data out to PC for further data analysis
//#define UART_DATA_OFFLOAD
//#define CW_TEST_MODE
//#define BYPASS_HOST_INTERFACE
//#define GLOSSY_PER_TEST
//#define GLOSSY_ANCHOR_SYNC_TEST

// FAST_RANGING_CONFIG: 6.8 Mbps
// LONG_RANGING_CONFIG: 110 Kbps
#define FAST_RANGING_CONFIG

#ifdef LONG_RANGING_CONFIG
	#define DW1000_PREAMBLE_LENGTH        DWT_PLEN_4096
	#define DW1000_PAC_SIZE               DWT_PAC64
	#define DW1000_DATA_RATE              DWT_BR_110K
	#define DW1000_SMART_PWR_EN           0
	#define DW1000_SFD_TO                 (4096+64+1)
	#define RANGING_BROADCASTS_PERIOD_US  10000
	#define RANGING_RESPONSE_PADDING_US   2000
    #define RANGING_CONTENTION_PADDING_US 10000
#endif
#ifdef FAST_RANGING_CONFIG
	#define DW1000_PREAMBLE_LENGTH        DWT_PLEN_64
	#define DW1000_PAC_SIZE               DWT_PAC8
	#define DW1000_DATA_RATE              DWT_BR_6M8
	#define DW1000_SMART_PWR_EN           1
	#define DW1000_SFD_TO                 (64 + 1 + 8 - 8) /* (Preamble length + 1 + SFD length - PAC size) */
	#define RANGING_BROADCASTS_PERIOD_US  2000
	#define RANGING_RESPONSE_PADDING_US   1000
    #define RANGING_CONTENTION_PADDING_US 1000
#endif

// Protocol adaptation -------------------------------------------------------------------------------------------------

// Allow hybrids to continue responding after they finished their own rangings
#define PROTOCOL_REENABLE_HYBRIDS

#define PROTOCOL_STANDARD_CONT_LENGTH	1

#define PROTOCOL_INIT_SCHED_MAX     10
#define PROTOCOL_RESP_SCHED_MAX     10

#define PROTOCOL_EUI_LEN            1  // Only use the first byte of the EUI to distinguish between nodes

#define PROTOCOL_INIT_SCHED_OFFSET  0
#define PROTOCOL_RESP_SCHED_OFFSET  (PROTOCOL_INIT_SCHED_OFFSET + PROTOCOL_INIT_SCHED_MAX)

// ---------------------------------------------------------------------------------------------------------------------

#endif /*__MODULE_CONF_H*/