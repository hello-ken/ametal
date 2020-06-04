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
 * \brief ADC AWD ���̣�ͨ�� HW ��ӿ�ʵ��
 *
 * - �������裺
 *   1. ��ָ��ADCͨ����Ӧ���������ӵ�λ������� VRO��
 *
 * - ʵ������
 *   1. ���Դ��������λ�������ѹ,������AWD�趨��ֵ������жϣ���ӡADת�������AWD��ֵ��
 *
 * \note
 *    1. ʹ�� ADC ģ�鹦�ܣ����뱣֤ ADC ģ���ϵ磻
 *    2. ����۲촮�ڴ�ӡ�ĵ�����Ϣ����Ҫ�� PIOE_4 �������� PC ���ڵ� TXD��
 *       PIOE_5 �������� PC ���ڵ� RXD��
 *
 * \par Դ����
 * \snippet demo_hc32f460_hw_adc_int.c src_hc32f460_hw_adc_int
 *
 * \internal
 * \par Modification History
 * - 1.00 20-04-26  cds, first implementation
 * \endinternal
 */

/**
 * \addtogroup demo_if_hc32f460_hw_adc_int
 * \copydoc demo_hc32f460_hw_adc_int.c
 */

/** [src_hc32f460_hw_adc_int] */
#include "ametal.h"
#include "am_vdebug.h"
#include "am_hc32f460.h"
#include "am_gpio.h"
#include "am_clk.h"
#include "demo_hc32f460_core_entries.h"

/**
 * \brief �������
 */
void demo_hc32f460_core_hw_adc_awd_entry (void)
{
    AM_DBG_INFO("demo amhc32f460_core hw adc awd!\r\n");

    /* �������� */
    am_gpio_pin_cfg(PIOA_0, GPIO_MODE(AMHW_HC32F460_GPIO_MODE_AIN));

    /* ʹ��ʱ�� */
    am_clk_enable(CLK_ADC1);

    demo_hc32f460_hw_adc_awd_entry(HC32F460_ADC1,
                                   INT_VECTOR_16,
                                   INT_VECTOR_17,
                                   0,
                                   3300);
}
/** [src_hc32f460_hw_adc_awd] */

/* end of file */