/*******************************************************************************
*                                 AMetal
*                       ----------------------------
*                       innovating embedded platform
*
* Copyright (c) 2001-2018 Guangzhou ZHIYUAN Electronics Co., Ltd.
* All rights reserved.
*
* Contact information:
* web site:    http://www.zlg.cn/
*******************************************************************************/

/**
 * \file
 * \brief 传感器 TCS3430 配置文件
 *
 * \internal
 * \par Modification history
 * - 1.00 20-04-26  fzb, first implementation.
 * \endinternal
 */

#include "am_sensor_tcs3430.h"
#include "am_common.h"
#include "zlg237_pin.h"
#include "am_zlg237_inst_init.h"

am_const am_local tcs3430_param_config_t __g_tcs3430_param_default = {
        AM_TCS3430_ATIME_50MS,                  /* ALS ADC的积分时间 */
        AM_TCS3430_WTIME_2_78MS_OR_33_4MS,      /* (与wlong_en配置相关)如果wlong_en为真，等待时间为后者，否则为前者 */
        2,                                      /* 连续故障次数进入ALS中断，该操作直接配置寄存器值，详细内容查阅数据手册Page16 */
        AM_FALSE,                               /* WLONG使能设置，使能后WTIME值将扩大12倍 */
        AM_TCS3430_AMUX_DISABLE,                /* AMUX */
        AM_TCS3430_AGAIN_128,                   /* ALS传感器增益 */
        AM_FALSE,                               /* sleep_after_interrupt */
        0,                                      /* AZ_MODE */
        0x7f,                                   /* AZ_NTH_ITERATION */
};

/** \brief 传感器 TCS3430 设备信息实例 */
am_const am_local struct am_sensor_tcs3430_devinfo __g_tcs3430_info = {
        &__g_tcs3430_param_default,             /**< \brief 参数初始化 */
        PIOA_1,                                 /**< \brief 报警输出引脚 */
        0x39,                                   /**< \brief I2C 7位 设备地址 */
};

/** \breif 传感器 TCS3430 设备结构体定义 */
am_local struct am_sensor_tcs3430_dev __g_tcs3430_dev;

/** \brief 传感器 TCS3430 设备实例化 */
am_sensor_handle_t am_sensor_tcs3430_inst_init (void)
{
    return am_sensor_tcs3430_init(&__g_tcs3430_dev,
                                  &__g_tcs3430_info,
                                  am_zlg237_i2c1_inst_init());
}

/** \brief 传感器 TCS3430 实例解初始化 */
am_err_t am_sensor_tcs3430_inst_deinit (am_sensor_handle_t handle)
{
    return am_sensor_tcs3430_deinit(handle);
}

/* end of file */
