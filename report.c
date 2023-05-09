#include "hal_data.h"

FSP_CPP_HEADER
void R_BSP_WarmStart(bsp_warm_start_event_t event);
FSP_CPP_FOOTER

int nowState = 1;
int btnFlag = 0;
int resetFlag = 0;

void blinkLED(int opt)
{
    if(opt== 0)
    {
        while(1)
        {
            dfs(nowState);
        }
    }
}

/* Callback function */
void button_callback(external_irq_callback_args_t *p_args)
{
    resetFlag = 1;
}
void button2_callback(external_irq_callback_args_t *p_args)
{
    btnFlag = 1 - btnFlag;
}

int isPushed()
{
    bsp_io_level_t lev1, lev2;
    R_IOPORT_PinRead (&g_ioport_ctrl, Button, &lev1);
    R_BSP_SoftwareDelay (20, BSP_DELAY_UNITS_MILLISECONDS);
    R_IOPORT_PinRead (&g_ioport_ctrl, Button, &lev2);

    if (lev1 == 0 && lev2 == 0)
        return 1;
    else
        return 0;
}

bsp_io_port_pin_t LEDs[4] =
{ LED01, LED02, LED03, LED04 };

void dfs(int now)
{
    if (now == 0x10000 || resetFlag)
    {
        resetFlag = 0;
        nowState = 1;
        return;
    }
    if(btnFlag)
    {
        nowState = now;
        return;
    }

    for (int i = 0; i < 4; i++)
    {
        if (now & 1 << i)
            R_IOPORT_PinWrite (&g_ioport_ctrl, LEDs[i], 1);
        else
            R_IOPORT_PinWrite (&g_ioport_ctrl, LEDs[i], 0);
    }

    R_BSP_SoftwareDelay (100, BSP_DELAY_UNITS_MILLISECONDS);
    dfs (now + 1);
}

void hal_entry(void)
{
    R_ICU_ExternalIrqEnable (&g_external_irq0_ctrl);
    R_ICU_ExternalIrqEnable (&g_external_irq1_ctrl);

    while (1)
    {
        blinkLED(btnFlag);
    }
}


void R_BSP_WarmStart(bsp_warm_start_event_t event)
{
    if (BSP_WARM_START_POST_C == event)
    {
        R_IOPORT_Open (&g_ioport_ctrl, g_ioport.p_cfg);
        R_SCI_UART_Open (&g_uart0_ctrl, &g_uart0_cfg);
        R_ICU_ExternalIrqOpen (&g_external_irq0_ctrl, &g_external_irq0_cfg);
        R_ICU_ExternalIrqOpen (&g_external_irq1_ctrl, &g_external_irq1_cfg);
    }

}

