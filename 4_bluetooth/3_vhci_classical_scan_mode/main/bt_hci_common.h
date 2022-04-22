/* Baisc macros and functions for Bluetooth Host Controller Interface Layer.

   This example code is in the Public Domain (or CC0 licensed, at your option.)

   Unless required by applicable law or agreed to in writing, this
   software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
   CONDITIONS OF ANY KIND, either express or implied.
 */

#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include "stdio.h"
#include "string.h"

#define HCI_H4_CMD_PREAMBLE_SIZE           (4)

/*  HCI Command Opcode group Field (OGF) */
#define HCI_GRP_HOST_CONT_BASEBAND_CMDS    (0x03 << 10)            /* 0x0C00 */

/*  HCI Command Opcode Command Field (OCF) */
#define HCI_RESET                       (0x0003 | HCI_GRP_HOST_CONT_BASEBAND_CMDS)
#define HCI_CHANGE_LOCAL_NAME           (0x0013 | HCI_GRP_HOST_CONT_BASEBAND_CMDS)
#define HCI_SET_SCAN_MODE               (0x001a | HCI_GRP_HOST_CONT_BASEBAND_CMDS)

/* HCI Command length. */
#define HCIC_PARAM_SIZE_CHNAGE_LOCAL_NAME        248
#define HCIC_PARAM_SIZE_SET_SCAN_MODE            1

#define BD_ADDR_LEN     (6)                     /* Device address length */
typedef uint8_t bd_addr_t[BD_ADDR_LEN];         /* Device address */

#define UINT16_TO_STREAM(p, u16) {*(p)++ = (uint8_t)(u16); *(p)++ = (uint8_t)((u16) >> 8);}
#define UINT8_TO_STREAM(p, u8)   {*(p)++ = (uint8_t)(u8);}
#define BDADDR_TO_STREAM(p, a)   {int ijk; for (ijk = 0; ijk < BD_ADDR_LEN;  ijk++) *(p)++ = (uint8_t) a[BD_ADDR_LEN - 1 - ijk];}
#define ARRAY_TO_STREAM(p, a, len) {int ijk; for (ijk = 0; ijk < len;        ijk++) *(p)++ = (uint8_t) a[ijk];}

enum {
    H4_TYPE_COMMAND = 1,
    H4_TYPE_ACL     = 2,
    H4_TYPE_SCO     = 3,
    H4_TYPE_EVENT   = 4
};

/**
 * @brief Writes reset bit in buf and returns size of input buffer after
 *        writing in it.
 *
 * @param buf Input buffer to write which will be sent to controller.
 *
 * @return  Size of buf after writing into it.
 */
uint16_t make_cmd_reset(uint8_t *buf);

uint16_t make_cmd_chanage_local_name(uint8_t *buf,uint8_t *name);

uint16_t make_cmd_set_scan_mode(uint8_t *buf,uint8_t scan_mode);

#ifdef __cplusplus
}
#endif
