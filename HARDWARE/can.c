#include "can.h"
#include "string.h"

extern CAN_HandleTypeDef hcan;
static CanTxMsgTypeDef canTxMsg;
static CanRxMsgTypeDef canRxMsg;

CAN_FilterConfTypeDef CanFilterConfig;

void Config_CanFilter(void)
{
    CanFilterConfig.FilterNumber        =   0;
    CanFilterConfig.FilterMode          =   CAN_FILTERMODE_IDMASK;
    CanFilterConfig.FilterScale         =   CAN_FILTERSCALE_32BIT;
    
    CanFilterConfig.FilterIdHigh        =   0xffff;
    CanFilterConfig.FilterIdLow         =   0xffff;
    CanFilterConfig.FilterMaskIdHigh    =   0x0000;
    CanFilterConfig.FilterMaskIdLow     =   0x0000;
    
    CanFilterConfig.FilterFIFOAssignment    =   CAN_FILTER_FIFO0;
    CanFilterConfig.FilterActivation        =   ENABLE;
    
    HAL_CAN_ConfigFilter(&hcan,&CanFilterConfig);
    
    hcan.pTxMsg     =   &canTxMsg;
    hcan.pRxMsg     =   &canRxMsg;
}

void sendCanData(uint32_t id,uint8_t * buf,uint32_t len)
{
    hcan.pTxMsg->StdId      =       id;
    hcan.pTxMsg->RTR        =       CAN_RTR_DATA;
    hcan.pTxMsg->IDE        =       CAN_ID_STD;
    hcan.pTxMsg->DLC        =       len;
    
    memcpy(canTxMsg.Data,buf,len);
//    memcpy(hcan.pTxMsg->Data,buf,len);
    
    if(HAL_CAN_Transmit(&hcan,100) != HAL_OK)
    {}
}

void HAL_CAN_RxCpltCallback(CAN_HandleTypeDef* hcan)
{
    HAL_CAN_Receive_IT(hcan,CAN_FIFO0);
    
//    HAL_GPIO_TogglePin(LED1_GPIO_Port,LED1_Pin);
//    HAL_GPIO_TogglePin(LED2_GPIO_Port,LED2_Pin);
    
    printf("stdid = %d .\n",hcan->pRxMsg->StdId);
    
    for(int i = 0; i < 8; i++)printf("can data = %d .\n",hcan->pRxMsg->Data[i]);
}
