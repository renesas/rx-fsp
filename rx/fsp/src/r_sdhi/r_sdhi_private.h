/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef SDHI_PRV_R_SDHI_PRIVATE_H
#define SDHI_PRV_R_SDHI_PRIVATE_H

/**********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
#include "bsp_api.h"

/** Common macro for FSP header files. There is also a corresponding FSP_FOOTER macro at the end of this file. */
FSP_HEADER

/**********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/
#define SDHI_PRV_CSD_VERSION_1_0                        (0U)
#define SDHI_PRV_CSD_VERSION_2_0                        (1U) /* value of 1 is CSD 2.0 according to SD spec. */

#define SDHI_PRV_CMD_GO_IDLE_STATE                      (0U)
#define SDHI_PRV_CMD_SEND_OP_COND                       (1U)
#define SDHI_PRV_CMD_ALL_SEND_CID                       (2U)
#define SDHI_PRV_CMD_SEND_RELATIVE_ADDR                 (3U)
#define SDHI_PRV_CMD_SET_BUS_WIDTH                      (6U)
#define SDHI_PRV_CMD_SWITCH                             (6U)
#define SDHI_PRV_CMD_SEL_DES_CARD                       (7U)
#define SDHI_PRV_CMD_IF_COND                            (8U)
#define SDHI_PRV_CMD_SEND_CSD                           (9U)
#define SDHI_PRV_CMD_SET_BLOCKLEN                       (16U)
#define SDHI_PRV_CMD_READ_SINGLE_BLOCK                  (17U)
#define SDHI_PRV_CMD_READ_MULTIPLE_BLOCK                (18U)
#define SDHI_PRV_CMD_WRITE_SINGLE_BLOCK                 (24U)
#define SDHI_PRV_CMD_WRITE_MULTIPLE_BLOCK               (25U)
#define SDHI_PRV_CMD_ERASE_WR_BLK_START                 (32U)
#define SDHI_PRV_CMD_ERASE_WR_BLK_END                   (33U)
#define SDHI_PRV_CMD_TAG_ERASE_GROUP_START              (0x423U)
#define SDHI_PRV_CMD_TAG_ERASE_GROUP_END                (0x424U)
#define SDHI_PRV_CMD_ERASE                              (38U)
#define SDHI_PRV_CMD_SD_SEND_OP_COND                    (41U)
#define SDHI_PRV_CMD_IO_RW_DIRECT                       (52U)
#define SDHI_PRV_CMD_IO_READ_EXT_SINGLE_BLOCK           (0x1c35U)
#define SDHI_PRV_CMD_IO_EXT_MULTI_BLOCK                 (0x6000U)
#define SDHI_PRV_CMD_IO_WRITE_EXT_SINGLE_BLOCK          (0x0c35U)

#define SDHI_PRV_CMD_APP_CMD                            (55U)
#define SDHI_PRV_CMD_C_ACMD                             (1U << 6) /* APP Command */

#define SDHI_PRV_IF_COND_VOLTAGE                        (1U)
#define SDHI_PRV_IF_COND_CHECK_PATTERN                  (0xAAU)

#define SDHI_PRV_OCR_CAPACITY_HC                        (1U << 30)
#define SDHI_PRV_RESPONSE_R3_CARD_CAPACITY_STATUS       (1U << 30)
#define SDHI_PRV_RESPONSE_R3_POWER_UP_STATUS            (1U << 31)
#define SDHI_PRV_RESPONSE_R6_RCA_SHIFT                  (16U)

#define SDHI_PRV_OCR_VDD_2_7_V                          (1U << 15)
#define SDHI_PRV_OCR_VDD_2_8_V                          (1U << 16)
#define SDHI_PRV_OCR_VDD_2_9_V                          (1U << 17)
#define SDHI_PRV_OCR_VDD_3_0_V                          (1U << 18)
#define SDHI_PRV_OCR_VDD_3_1_V                          (1U << 19)
#define SDHI_PRV_OCR_VDD_3_2_V                          (1U << 20)
#define SDHI_PRV_OCR_VDD_3_3_V                          (1U << 21)
#define SDHI_PRV_OCR_VDD_3_4_V                          (1U << 22)
#define SDHI_PRV_OCR_VDD_3_5_V                          (1U << 23)
#define SDHI_PRV_OCR_VDD_SUPPORTED                                                                       \
    (SDHI_PRV_OCR_VDD_2_7_V | SDHI_PRV_OCR_VDD_2_8_V | SDHI_PRV_OCR_VDD_2_9_V | SDHI_PRV_OCR_VDD_3_0_V | \
     SDHI_PRV_OCR_VDD_3_1_V |                                                                            \
     SDHI_PRV_OCR_VDD_3_2_V | SDHI_PRV_OCR_VDD_3_3_V | SDHI_PRV_OCR_VDD_3_4_V | SDHI_PRV_OCR_VDD_3_5_V)

/* SWITCH command argument's bit position */
#define SDHI_PRV_SWITCH_ACCESS_SHIFT                    (24U)
#define SDHI_PRV_SWITCH_INDEX_SHIFT                     (16U)
#define SDHI_PRV_SWITCH_VALUE_SHIFT                     (8U)

#define SDHI_PRV_EMMC_EXT_CSD_SIZE                      (512U)

/* Offsets */
#define SDHI_PRV_EMMC_EXT_CSD_HS_TIMING_OFFSET          (185U)
#define SDHI_PRV_EMMC_EXT_CSD_DEVICE_TYPE_OFFSET        (196U)
#define SDHI_PRV_EMMC_EXT_CSD_SEC_COUNT_OFFSET          (212U)

/* Commands */
#define SDHI_PRV_EMMC_SWITCH_ACCESS_WRITE_BYTE          (3U)
#define SDHI_PRV_EMMC_HIGH_SPEED_52_MHZ_BIT             (2U)
#define SDHI_PRV_EMMC_HIGH_SPEED_MODE                   (((SDHI_PRV_EMMC_SWITCH_ACCESS_WRITE_BYTE << 24U) |  \
                                                          (SDHI_PRV_EMMC_EXT_CSD_HS_TIMING_OFFSET << 16U)) | \
                                                         (SDHI_PRV_EMMC_HIGH_SPEED_52_MHZ_BIT << 8U))

#define SDHI_PRV_SD_SWITCH_STATUS_SIZE                  (64U)
#define SDHI_PRV_SD_SWITCH_HIGH_SPEED_RESPONSE          (13U)
#define SDHI_PRV_SD_SWITCH_HIGH_SPEED_ERROR_RESPONSE    (16U)
#define SDHI_PRV_SD_SWITCH_HIGH_SPEED_ERROR             (0x0fU)
#define SDHI_PRV_SD_SWITCH_HIGH_SPEED_OK                (0x02U)

#define SDHI_PRV_EMMC_SEND_OP_COND                      (0x701U)
#define SDHI_PRV_EMMC_CMD_SWITCH_WBUSY                  (0x506U)      /* eMMC CMD6 switch command "with response busy" */
#define SDHI_PRV_EMMC_CMD_SEND_EXT_CSD                  (0x1C08U)     /* CMD 8, read data */
#define SDHI_PRV_EMMC_DEFAULT_CLOCK_RATE                (26000000U)   /* 26 MHz */
#define SDHI_PRV_EMMC_HIGH_SPEED_CLOCK_RATE             (52000000U)   /* 52 MHz */
#define SDHI_PRV_SD_HIGH_SPEED_MODE_SWITCH              (0x80FFFFF1U) /* set SD high speed */
#define SDHI_PRV_SD_DEFAULT_CLOCK_RATE                  (25000000U)   /* 25 MHz */
#define SDHI_PRV_SD_HIGH_SPEED_CLOCK_RATE               (50000000U)   /* 50 MHz */

#define SDHI_PRV_EMMC_ERASE_ARGUMENT_TRIM               (1U)

#define SDHI_PRV_CSD_CID_SERIAL_NUMBER_BITS             (32)
#define SDHI_PRV_CSD_CID_PRODUCT_NAME_BITS              (40)
#define SDHI_PRV_CSD_RESPONSE_BIT_OFFSET                (8U)

/* CSD field bit positions */
#define SDHI_PRV_CSD_STRUCTURE_HIGH_BIT                 (127U)
#define SDHI_PRV_CSD_STRUCTURE_LOW_BIT                  (126U)
#define SDHI_PRV_CSD_CCC_HIGH_BIT                       (95U)
#define SDHI_PRV_CSD_CCC_LOW_BIT                        (84U)
#define SDHI_PRV_CSD_READ_BL_LEN_HIGH_BIT               (83U)
#define SDHI_PRV_CSD_READ_BL_LEN_LOW_BIT                (80U)
#define SDHI_PRV_CSD_V1_C_SIZE_HIGH_BIT                 (73U)
#define SDHI_PRV_CSD_V1_C_SIZE_LOW_BIT                  (62U)
#define SDHI_PRV_CSD_V1_C_SIZE_MULT_HIGH_BIT            (49U)
#define SDHI_PRV_CSD_V1_C_SIZE_MULT_LOW_BIT             (47U)
#define SDHI_PRV_CSD_V1_SECTOR_SIZE_HIGH_BIT            (45U)
#define SDHI_PRV_CSD_V1_SECTOR_SIZE_LOW_BIT             (39U)
#define SDHI_PRV_CSD_V2_C_SIZE_HIGH_BIT                 (69U)
#define SDHI_PRV_CSD_V2_C_SIZE_LOW_BIT                  (48U)

#if defined(__BIG) && defined(__GNUC__)
 #define SDHI_PRV_EXT_SWAP_ENABLE                       (1)
#else
 #define SDHI_PRV_EXT_SWAP_ENABLE                       (0)
#endif

/**********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/
typedef enum e_sdmmc_priv_sd_state
{
    SDMMC_PRIV_SD_STATE_IDLE,
    SDMMC_PRIV_SD_STATE_READY,
    SDMMC_PRIV_SD_STATE_IDENT,
    SDMMC_PRIV_SD_STATE_STBY,
    SDMMC_PRIV_SD_STATE_TRANSFER,
    SDMMC_PRIV_SD_STATE_DATA,
    SDMMC_PRIV_SD_STATE_RCV,
    SDMMC_PRIV_SD_STATE_PROG,
    SDMMC_PRIV_SD_STATE_DIS,
    SDMMC_PRIV_SD_STATE_RSVD9,
    SDMMC_PRIV_SD_STATE_RSVD10,
    SDMMC_PRIV_SD_STATE_RSVD11,
    SDMMC_PRIV_SD_STATE_RSVD12,
    SDMMC_PRIV_SD_STATE_RSVD13,
    SDMMC_PRIV_SD_STATE_RSVD14,
    SDMMC_PRIV_SD_STATE_RSVD15
} sdmmc_priv_sd_state_t;

/** SDMMC card specific data */
typedef struct st_sdmmc_priv_csd_reg
{
    union
    {
        uint8_t array[16];

        /* All structures in this union must be packed since some bitfields span more than one 32-bit word. */
#if  defined(__ICCARM__) || defined(__ICCRX__)
        __packed struct
#elif defined(__GNUC__)
        struct __attribute__((__packed__))
#elif defined(__CCRX__)
        struct
#endif
        {
#if defined(__BIG) && defined(__GNUC__)
            volatile uint32_t sdrsp76;
            volatile uint32_t sdrsp54;
            volatile uint32_t sdrsp32;
            volatile uint32_t sdrsp10;
#else
            volatile uint32_t sdrsp10;
            volatile uint32_t sdrsp32;
            volatile uint32_t sdrsp54;
            volatile uint32_t sdrsp76;
#endif
        } reg;

        /* All structures in this union must be packed since some bitfields span more than one 32-bit word. */
#if  defined(__ICCARM__) || defined(__ICCRX__)
        __packed struct
#elif defined(__GNUC__)
        struct __attribute__((__packed__))
#elif defined(__CCRX__)
        struct
#endif
        {
#if defined(__BIG) && defined(__GNUC__)
            uint64_t reserved_128       : 8;  ///< [135:128]
            uint64_t csd_structure      : 2;  ///< [127:126] csd structure
            uint64_t reserved_120       : 6;  ///< [125:120]
            uint64_t taac               : 8;  ///< [119:112] data read access-time-1
            uint64_t nsac               : 8;  ///< [111:104] data read access-time-2 clk cycles
            uint64_t tran_speed         : 8;  ///< [103:96] max. data transfer rate
            uint64_t ccc                : 12; ///< [95:84] card command classes
            uint64_t read_bl_len        : 4;  ///< [83:80] max read data block length
            uint64_t read_bl_partial    : 1;  ///< [79]    partial blocks for read allowed
            uint64_t write_blk_misalign : 1;  ///< [78]    write block misalignment
            uint64_t read_blk_misalign  : 1;  ///< [77]    read block misalignment
            uint64_t dsr_imp            : 1;  ///< [76]    dsr implemented
            uint64_t reserved_74        : 2;  ///< [75:74]
            uint64_t c_size_l           : 2;  ///< [73:72] 2-bit lower of device size
            uint64_t c_size_u           : 10; ///< [71:62] 10-bit upper of device size
            uint64_t vdd_r_curr_min     : 3;  ///< [61:59] max. read current for vdd min
            uint64_t vdd_r_curr_max     : 3;  ///< [58:56] max. read current for vdd max
            uint64_t vdd_w_curr_min     : 3;  ///< [55:53] max. write current for vdd min
            uint64_t vdd_w_curr_max     : 3;  ///< [52:50] max. write current for vdd max
            uint64_t c_size_mult        : 3;  ///< [49:47] device size multiplier*/
            uint64_t erase_blk_en       : 1;  ///< [46]    erase single block enable
            uint64_t sector_size        : 7;  ///< [45:39] erase sector size
            uint64_t wp_grp_size        : 7;  ///< [38:32] write protect group size
            uint64_t wp_grp_enable      : 1;  ///< [31]    write protect group enable
            uint64_t reserved_29        : 2;  ///< [30:29]
            uint64_t r2w_factor         : 3;  ///< [28:26] write speed factor
            uint64_t write_bl_len       : 4;  ///< [25:22] max. write data block length
            uint64_t write_bl_partial   : 1;  ///< [21]    partial blocks for write allowed
            uint64_t reserved_20        : 5;  ///< [16-20]
            uint64_t file_format_grp    : 1;  ///< [15]    file format group
            uint64_t copy               : 1;  ///< [14]    copy flag
            uint64_t perm_write_protect : 1;  ///< [13]    permanent write protection
            uint64_t tmp_write_protect  : 1;  ///< [12]    temporary write protection
            uint64_t file_format        : 2;  ///< [11:10] file format
            uint64_t reserved_8         : 2;  ///< [9:8]
#else
            uint64_t reserved_8         : 2;  ///< [9:8]
            uint64_t file_format        : 2;  ///< [11:10] file format
            uint64_t tmp_write_protect  : 1;  ///< [12]    temporary write protection
            uint64_t perm_write_protect : 1;  ///< [13]    permanent write protection
            uint64_t copy               : 1;  ///< [14]    copy flag
            uint64_t file_format_grp    : 1;  ///< [15]    file format group
            uint64_t reserved_20        : 5;  ///< [16-20]
            uint64_t write_bl_partial   : 1;  ///< [21]    partial blocks for write allowed
            uint64_t write_bl_len       : 4;  ///< [25:22] max. write data block length
            uint64_t r2w_factor         : 3;  ///< [28:26] write speed factor
            uint64_t reserved_29        : 2;  ///< [30:29]
            uint64_t wp_grp_enable      : 1;  ///< [31]    write protect group enable
            uint64_t wp_grp_size        : 7;  ///< [38:32] write protect group size
            uint64_t sector_size        : 7;  ///< [45:39] erase sector size
            uint64_t erase_blk_en       : 1;  ///< [46]    erase single block enable
            uint64_t c_size_mult        : 3;  ///< [49:47] device size multiplier*/
            uint64_t vdd_w_curr_max     : 3;  ///< [52:50] max. write current for vdd max
            uint64_t vdd_w_curr_min     : 3;  ///< [55:53] max. write current for vdd min
            uint64_t vdd_r_curr_max     : 3;  ///< [58:56] max. read current for vdd max
            uint64_t vdd_r_curr_min     : 3;  ///< [61:59] max. read current for vdd min
            uint64_t c_size_u           : 10; ///< [71:62] 10-bit upper of device size
            uint64_t c_size_l           : 2;  ///< [73:72] 2-bit lower of device size
            uint64_t reserved_74        : 2;  ///< [75:74]
            uint64_t dsr_imp            : 1;  ///< [76]    dsr implemented
            uint64_t read_blk_misalign  : 1;  ///< [77]    read block misalignment
            uint64_t write_blk_misalign : 1;  ///< [78]    write block misalignment
            uint64_t read_bl_partial    : 1;  ///< [79]    partial blocks for read allowed
            uint64_t read_bl_len        : 4;  ///< [83:80] max read data block length
            uint64_t ccc                : 12; ///< [95:84] card command classes
            uint64_t tran_speed         : 8;  ///< [103:96] max. data transfer rate
            uint64_t nsac               : 8;  ///< [111:104] data read access-time-2 clk cycles
            uint64_t taac               : 8;  ///< [119:112] data read access-time-1
            uint64_t reserved_120       : 6;  ///< [125:120]
            uint64_t csd_structure      : 2;  ///< [127:126] csd structure
            uint64_t reserved_128       : 8;  ///< [135:128]
#endif
        } csd_v1_b;

        /* All structures in this union must be packed since some bitfields span more than one 32-bit word. */
#if  defined(__ICCARM__) || defined(__ICCRX__)
        __packed struct
#elif defined(__GNUC__)
        struct __attribute__((__packed__))
#elif defined(__CCRX__)
        struct
#endif
        {
#if defined(__BIG) && defined(__GNUC__)
            uint64_t reserved_128       : 8;  ///< [135:128]
            uint64_t csd_structure      : 2;  ///< [127:126] csd structure
            uint64_t reserved_120       : 6;  ///< [125:120]
            uint64_t taac               : 8;  ///< [119:112] data read access-time-1
            uint64_t nsac               : 8;  ///< [111:104] data read access-time-2 clk cycles
            uint64_t tran_speed         : 8;  ///< [103:96] max. data transfer rate
            uint64_t ccc                : 12; ///< [95:84] card command classes
            uint64_t read_bl_len        : 4;  ///< [83:80] max read data block length
            uint64_t read_bl_partial    : 1;  ///< [79]    partial blocks for read allowed
            uint64_t write_blk_misalign : 1;  ///< [78]    write block misalignment
            uint64_t read_blk_misalign  : 1;  ///< [77]    read block misalignment
            uint64_t dsr_imp            : 1;  ///< [76]    dsr implemented
            uint64_t reserved_72        : 4;  ///< [75:72]
            uint64_t reserved_70        : 2;  ///< [71:70]
            uint64_t c_size             : 22; ///< [69:48] device size
            uint64_t reserved_47        : 1;  ///< [47]
            uint64_t erase_blk_en       : 1;  ///< [46]    erase single block enable
            uint64_t sector_size        : 7;  ///< [45:39] erase sector size
            uint64_t wp_grp_size        : 7;  ///< [38:32] write protect group size
            uint64_t wp_grp_enable      : 1;  ///< [31]    write protect group enable
            uint64_t reserved_29        : 2;  ///< [30:29]
            uint64_t r2w_factor         : 3;  ///< [28:26] write speed factor
            uint64_t write_bl_len       : 4;  ///< [25:22] max. write data block length
            uint64_t write_bl_partial   : 1;  ///< [21]    partial blocks for write allowed
            uint64_t reserved_20        : 5;  ///< [20:16]
            uint64_t file_format_grp    : 1;  ///< [15]    file format group
            uint64_t copy               : 1;  ///< [14]    copy flag
            uint64_t perm_write_protect : 1;  ///< [13]    permanent write protection
            uint64_t tmp_write_protect  : 1;  ///< [12]    temporary write protection
            uint64_t file_format        : 2;  ///< [11:10] file format
            uint64_t reserved_8         : 2;  ///< [9:8]
#else
            uint64_t reserved_8         : 2;  ///< [9:8]
            uint64_t file_format        : 2;  ///< [11:10] file format
            uint64_t tmp_write_protect  : 1;  ///< [12]    temporary write protection
            uint64_t perm_write_protect : 1;  ///< [13]    permanent write protection
            uint64_t copy               : 1;  ///< [14]    copy flag
            uint64_t file_format_grp    : 1;  ///< [15]    file format group
            uint64_t reserved_20        : 5;  ///< [20:16]
            uint64_t write_bl_partial   : 1;  ///< [21]    partial blocks for write allowed
            uint64_t write_bl_len       : 4;  ///< [25:22] max. write data block length
            uint64_t r2w_factor         : 3;  ///< [28:26] write speed factor
            uint64_t reserved_29        : 2;  ///< [30:29]
            uint64_t wp_grp_enable      : 1;  ///< [31]    write protect group enable
            uint64_t wp_grp_size        : 7;  ///< [38:32] write protect group size
            uint64_t sector_size        : 7;  ///< [45:39] erase sector size
            uint64_t erase_blk_en       : 1;  ///< [46]    erase single block enable
            uint64_t reserved_47        : 1;  ///< [47]
            uint64_t c_size             : 22; ///< [69:48] device size
            uint64_t reserved_70        : 2;  ///< [71:70]
            uint64_t reserved_72        : 4;  ///< [75:72]
            uint64_t dsr_imp            : 1;  ///< [76]    dsr implemented
            uint64_t read_blk_misalign  : 1;  ///< [77]    read block misalignment
            uint64_t write_blk_misalign : 1;  ///< [78]    write block misalignment
            uint64_t read_bl_partial    : 1;  ///< [79]    partial blocks for read allowed
            uint64_t read_bl_len        : 4;  ///< [83:80] max read data block length
            uint64_t ccc                : 12; ///< [95:84] card command classes
            uint64_t tran_speed         : 8;  ///< [103:96] max. data transfer rate
            uint64_t nsac               : 8;  ///< [111:104] data read access-time-2 clk cycles
            uint64_t taac               : 8;  ///< [119:112] data read access-time-1
            uint64_t reserved_120       : 6;  ///< [125:120]
            uint64_t csd_structure      : 2;  ///< [127:126] csd structure
            uint64_t reserved_128       : 8;  ///< [135:128]
#endif
        } csd_v2_b;

        /* All structures in this union must be packed since some bitfields span more than one 32-bit word. */
#if  defined(__ICCARM__) || defined(__ICCRX__)
        __packed struct
#elif defined(__GNUC__)
        struct __attribute__((__packed__))
#elif defined(__CCRX__)
        struct
#endif
        {
#if defined(__BIG) && defined(__GNUC__)
            uint64_t mfg_id           : 8;
            uint64_t oem_id           : 16;
            uint64_t product_name     : SDHI_PRV_CSD_CID_PRODUCT_NAME_BITS;
            uint64_t product_revision : 8;
            uint64_t serial_number    : SDHI_PRV_CSD_CID_SERIAL_NUMBER_BITS;
            uint64_t reserved_23      : 4;
            uint64_t mfg_date         : 12;
            uint64_t crc              : 7;
            uint64_t reserved_0       : 1;
#else
            uint64_t reserved_0       : 1;
            uint64_t crc              : 7;
            uint64_t mfg_date         : 12;
            uint64_t reserved_23      : 4;
            uint64_t serial_number    : SDHI_PRV_CSD_CID_SERIAL_NUMBER_BITS;
            uint64_t product_revision : 8;
            uint64_t product_name     : SDHI_PRV_CSD_CID_PRODUCT_NAME_BITS;
            uint64_t oem_id           : 16;
            uint64_t mfg_id           : 8;
#endif
        } cid;
    } csd_u;
} sdmmc_priv_csd_reg_t;

/*******************************************************************************************************************//**
 * Extracts a CSD field from the SD R2 response registers.
 *
 * @param[in]  p_csd_reg    Pointer to card specific data.
 * @param[in]  high_bit     CSD field high bit.
 * @param[in]  low_bit      CSD field low bit.
 *
 * @return     Extracted CSD field value.
 **********************************************************************************************************************/
__STATIC_INLINE uint32_t r_sdhi_csd_bitfield_get (sdmmc_priv_csd_reg_t const * const p_csd_reg,
                                                  uint32_t                           high_bit,
                                                  uint32_t                           low_bit)
{
    uint32_t const response_word[] =
    {
        p_csd_reg->csd_u.reg.sdrsp10,
        p_csd_reg->csd_u.reg.sdrsp32,
        p_csd_reg->csd_u.reg.sdrsp54,
        p_csd_reg->csd_u.reg.sdrsp76,
    };

    uint32_t bit_count = (high_bit - low_bit) + 1U;
    uint32_t bit_index = low_bit - SDHI_PRV_CSD_RESPONSE_BIT_OFFSET;
    uint32_t value     = 0U;
    uint32_t shift     = 0U;

    while (bit_count > 0U)
    {
        uint32_t word_index      = bit_index / 32U;
        uint32_t word_bit_offset = bit_index % 32U;
        uint32_t bits_available  = 32U - word_bit_offset;
        uint32_t bits_to_copy    = (bit_count < bits_available) ? bit_count : bits_available;
        uint32_t mask            = (32U == bits_to_copy) ? UINT32_MAX : ((1U << bits_to_copy) - 1U);

        value |= ((response_word[word_index] >> word_bit_offset) & mask) << shift;

        bit_count -= bits_to_copy;
        bit_index += bits_to_copy;
        shift     += bits_to_copy;
    }

    return value;
}

/** Common macro for FSP header files. There is also a corresponding FSP_HEADER macro at the top of this file. */
FSP_FOOTER

#endif
