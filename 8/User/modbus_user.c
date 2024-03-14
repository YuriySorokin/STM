/*
 * modbus_user.c
 *
 *  Created on: 14 мар. 2024 г.
 *      Author: Yuriy
 */

#include "modbus_user.h"
#include "port.h"
#include "mb.h"
#include "LED.h"


extern uint32_t FlagIRQ ;

static USHORT usRegInputStart = REG_INPUT_START;
static USHORT usRegInputBuf[REG_INPUT_NREGS] = {'M', 'o', 'd', 'b', 'u', 's', 0x0, 0x0};


void poll_modbus (void)
{

	while (!FlagIRQ)
	{
			eMBPoll();


				usRegInputBuf[REG_INPUT_NREGS - 2] =  HAL_GetTick() / 1000;
				usRegInputBuf[REG_INPUT_NREGS - 1] =  HAL_GetTick();

	}


}
// ==================== Modbus Begin

/*----------------------------------------------------------------------------*/
eMBErrorCode eMBRegInputCB(UCHAR * pucRegBuffer, USHORT usAddress, USHORT usNRegs)
{
  eMBErrorCode eStatus = MB_ENOERR;
  int iRegIndex;
  if ((usAddress >= REG_INPUT_START) &&
      (usAddress + usNRegs <= REG_INPUT_START + REG_INPUT_NREGS))
  {
    iRegIndex = (int)(usAddress - usRegInputStart);
    while(usNRegs > 0)
    {
        *pucRegBuffer++ = (unsigned char)(usRegInputBuf[iRegIndex] >> 8);
        *pucRegBuffer++ = (unsigned char)(usRegInputBuf[iRegIndex] & 0xFF);
        iRegIndex++;
        usNRegs--;
    }
  }
  else
  {
    eStatus = MB_ENOREG;
  }
  return eStatus;
}

/*----------------------------------------------------------------------------*/
eMBErrorCode eMBRegHoldingCB(UCHAR * pucRegBuffer, USHORT usAddress, USHORT usNRegs,
                             eMBRegisterMode eMode)
{
  return MB_ENOREG;
}


eMBErrorCode eMBRegCoilsCB(UCHAR * pucRegBuffer, USHORT usAddress, USHORT usNCoils,
                           eMBRegisterMode eMode)
{
  return MB_ENOREG;
}
/*----------------------------------------------------------------------------*/
eMBErrorCode eMBRegDiscreteCB(UCHAR * pucRegBuffer, USHORT usAddress, USHORT usNDiscrete)
{
  return MB_ENOREG;
}
// ==================== Modbus END
