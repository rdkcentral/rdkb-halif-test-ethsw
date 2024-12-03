#include <string.h>
#include <stdlib.h>
#include <setjmp.h>
#include "ccsp_hal_ethsw.h"


INT CcspHalEthSwInit(void)
{
  /*TODO: Implement Me!*/
  return (INT)0;
}

INT CcspHalEthSwGetPortStatus(CCSP_HAL_ETHSW_PORT PortId, PCCSP_HAL_ETHSW_LINK_RATE pLinkRate, PCCSP_HAL_ETHSW_DUPLEX_MODE pDuplexMode, PCCSP_HAL_ETHSW_LINK_STATUS pStatus)
{
  /*TODO: Implement Me!*/
  (void)PortId;
  (void)pLinkRate;
  (void)pDuplexMode;
  (void)pStatus;
  return (INT)0;
}

INT CcspHalEthSwGetPortCfg(CCSP_HAL_ETHSW_PORT PortId, PCCSP_HAL_ETHSW_LINK_RATE pLinkRate, PCCSP_HAL_ETHSW_DUPLEX_MODE pDuplexMode)
{
  /*TODO: Implement Me!*/
  (void)PortId;
  (void)pLinkRate;
  (void)pDuplexMode;
  return (INT)0;
}

INT CcspHalEthSwSetPortCfg(CCSP_HAL_ETHSW_PORT PortId, CCSP_HAL_ETHSW_LINK_RATE LinkRate, CCSP_HAL_ETHSW_DUPLEX_MODE DuplexMode)
{
  /*TODO: Implement Me!*/
  (void)PortId;
  (void)LinkRate;
  (void)DuplexMode;
  return (INT)0;
}

INT CcspHalEthSwGetPortAdminStatus(CCSP_HAL_ETHSW_PORT PortId, PCCSP_HAL_ETHSW_ADMIN_STATUS pAdminStatus)
{
  /*TODO: Implement Me!*/
  (void)PortId;
  (void)pAdminStatus;
  return (INT)0;
}

INT CcspHalEthSwSetPortAdminStatus(CCSP_HAL_ETHSW_PORT PortId, CCSP_HAL_ETHSW_ADMIN_STATUS AdminStatus)
{
  /*TODO: Implement Me!*/
  (void)PortId;
  (void)AdminStatus;
  return (INT)0;
}

INT CcspHalEthSwSetAgingSpeed(CCSP_HAL_ETHSW_PORT PortId, INT AgingSpeed)
{
  /*TODO: Implement Me!*/
  (void)PortId;
  (void)AgingSpeed;
  return (INT)0;
}

INT CcspHalEthSwLocatePortByMacAddress(unsigned char* mac, INT* port)
{
  /*TODO: Implement Me!*/
  (void)mac;
  (void)port;
  return (INT)0;
}

INT CcspHalExtSw_getAssociatedDevice(ULONG* output_array_size, eth_device_t** output_struct)
{
  /*TODO: Implement Me!*/
  (void)output_array_size;
  (void)output_struct;
  return (INT)0;
}

void CcspHalExtSw_ethAssociatedDevice_callback_register(CcspHalExtSw_ethAssociatedDevice_callback callback_proc)
{
  /*TODO: Implement Me!*/
  (void)callback_proc;
}

int CcspHalExtSw_ethPortConfigure(char* ifname, BOOLEAN WanMode)
{
  /*TODO: Implement Me!*/
  (void)ifname;
  (void)WanMode;
  return (int)0;
}

INT CcspHalExtSw_getEthWanEnable(BOOLEAN* pFlag)
{
  /*TODO: Implement Me!*/
  (void)pFlag;
  return (INT)0;
}

INT CcspHalExtSw_setEthWanEnable(BOOLEAN Flag)
{
  /*TODO: Implement Me!*/
  (void)Flag;
  return (INT)0;
}

BOOLEAN CcspHalExtSw_getCurrentWanHWConf(void)
{
  /*TODO: Implement Me!*/
  return (BOOLEAN)0;
}

INT CcspHalExtSw_getEthWanPort(UINT* pPort)
{
  /*TODO: Implement Me!*/
  (void)pPort;
  return (INT)0;
}

INT CcspHalExtSw_setEthWanPort(UINT Port)
{
  /*TODO: Implement Me!*/
  (void)Port;
  return (INT)0;
}

INT CcspHalEthSwGetEthPortStats(CCSP_HAL_ETHSW_PORT PortId, PCCSP_HAL_ETH_STATS pStats)
{
  /*TODO: Implement Me!*/
  (void)PortId;
  (void)pStats;
  return (INT)0;
}

void GWP_RegisterEthWan_Callback(appCallBack* obj)
{
  /*TODO: Implement Me!*/
  (void)obj;
}

INT GWP_GetEthWanLinkStatus(void)
{
  /*TODO: Implement Me!*/
  return (INT)0;
}

INT GWP_GetEthWanInterfaceName(unsigned char* Interface, ULONG maxSize)
{
  /*TODO: Implement Me!*/
  (void)Interface;
  (void)maxSize;
  return (INT)0;
}

