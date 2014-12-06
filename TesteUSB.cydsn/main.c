//#include <device.h>
//#include <project.h>

#include <device.h>

/* Create Defines for various Endpoints */
#define EP1 0x01
#define EP2 0x02
#define EP3 0x03
#define EP4 0x04
#define EP5 0x05
#define EP6 0x06
#define ZeroBandwidthInterface 0
#define UnassignedAddress 0



/* Function Prototypes */
void Interrupt_Transfer (void);
void Bulk_Transfer (void);
void Isochronous_Transfer (void);

/* External variable that contains device address assigned by host */
extern volatile uint8 USBFS_deviceAddress;

uint8 AltSettingNumber = 0u;


/* Buffers variables where data sent from host will be stored */
uint8 Interrupt_OUT_Buffer[8], EP2_Count;
uint8 Bulk_OUT_Buffer[8], EP4_Count;
uint8 Isochronous_OUT_Buffer[8], EP6_Count ;




int main(void)
{
     
    /* Start all components used on schematic */
    ADC_DelSig_IRQ_Start();
    ADC_DelSig_Start();
    ADC_DelSig_StartConvert();
    Filter_Start();
    WaveDAC8_Start();
    Opamp_1_Start();
    //isr_StartEx(isr);

	// Enable the interrupt register bit to poll
    // Value 1 for Channel A, Value 2 for Channel B
    Filter_INT_CTRL_REG |= (1 << Filter_CHANNEL_A);
	    
     /* Local Variable to store active configuration number */
     //uint8 AltSettingNumber = 0u;
      
     /* Enable global interrupts */
     CYGlobalIntEnable;
     
     /* Start USBFS Component based on power settings in DWR (5V in this case) */
     USBFS_Start(0, USBFS_DWR_VDDD_OPERATION);
     
     /* Wait until device address is assigned */
     while(USBFS_deviceAddress == UnassignedAddress);
     for(;;)
     {
         /* Ensure USB device is fully enumerated prior to running code */
         if(USBFS_GetConfiguration() != 0)
         {
         /* Check USB configuration has changed */
             if(USBFS_IsConfigurationChanged() != ZeroBandwidthInterface)
             {
                 /* Get the active interface number and re-enable OUT EP based on Alternative Setting */
                 AltSettingNumber = USBFS_GetInterfaceSetting(0);
                 if(AltSettingNumber == 0x01) USBFS_EnableOutEP(2);
                 if(AltSettingNumber == 0x02) USBFS_EnableOutEP(4);
                 if(AltSettingNumber == 0x03) USBFS_EnableOutEP(6);
             }
             /* Check the Alternative Setting variable to see which endpoint buffers to read and load */
         switch(AltSettingNumber)
         {
             /* Check if Interrupt Configuration is Active */
             case 0x01:Interrupt_Transfer();
             break;
             /* Check if Bulk Configuration is Active */
             case 0x02:Bulk_Transfer();
             break;
             /* Check if Isochronous Configuration is Active */
             case 0x03:Isochronous_Transfer();
             break;
             /* Should Never Get Here */
             default: break;
            }
        }
    }  
 return(0);

    
}

/* Transfer data from ADC - Is a bulk transfer actually, change name some time in teh future */
void Interrupt_Transfer (void)
{
    /* Check to see if OUT Endpoint has data. If so, read EP2 buffer and load back into EP1 for loopback */
    if(USBFS_GetEPState(EP2) == USBFS_OUT_BUFFER_FULL)    
    {
        /* Determine the number of bytes received */
        EP2_Count = USBFS_GetEPCount(EP2);
        /* Read data from OUT endpoint and store in Interrupt_OUT_Buffer */
        USBFS_ReadOutEP(EP2, Interrupt_OUT_Buffer, EP2_Count);
        /* Send data from the ADC */
        // Fill in the buffer
        int i;
        /* Remove the code in the interrupt routine because the ADC_GetResult 
           makes ADC_IsEndConversion useless. Will not work if this is not done */
        for(i=0;i<8;i++){
        while(ADC_DelSig_IsEndConversion(ADC_DelSig_WAIT_FOR_RESULT)==0);
        Interrupt_OUT_Buffer[i] = ADC_DelSig_GetResult8();
        
        }
        // Sends the buffer
        USBFS_LoadInEP(EP1, Interrupt_OUT_Buffer, 8);
        /* Re-arm the Out Endpoint */
        USBFS_EnableOutEP(EP2);
    
    }    
    
//    /* Check to see if OUT Endpoint has data. If so, read EP2 buffer and load back into EP1 for loopback */
// if(USBFS_GetEPState(EP2) == USBFS_OUT_BUFFER_FULL)
// {
//     /* Determine the number of bytes received */
//     EP2_Count = USBFS_GetEPCount(EP2);
//     /* Read data from OUT endpoint and store in Interrupt_OUT_Buffer */
//     USBFS_ReadOutEP(EP2, Interrupt_OUT_Buffer, EP2_Count);
//     /* Create loopback by reloading data received into IN endpoint */
//     USBFS_LoadInEP(EP1, Interrupt_OUT_Buffer, 8);
//     /* Re-arm the Out Endpoint */
//     USBFS_EnableOutEP(EP2);
// }
}

/* Transfer data from Filter */
void Bulk_Transfer (void)
{
    // Check if there is data available. If so, send some data into EP3
    if( USBFS_bGetEPState(EP4) == USBFS_OUT_BUFFER_FULL)
    {
    // Determine number of bytes received
    EP4_Count = USBFS_wGetEPCount(EP4);
    /* Read data from OUT endpoint and store in Bulk_OUT_Buffer */
    USBFS_ReadOutEP(EP4, Bulk_OUT_Buffer, EP4_Count);
   
    // Get data from the filter
    int i ;
    for(i = 0;i < 8;i++)
    {
        while (Filter_IsInterruptChannelA() == 0) ; 
        Bulk_OUT_Buffer[i] = Filter_Read8(Filter_CHANNEL_A);
    
    }
       
    // Sends the buffer to client 
    USBFS_LoadInEP(EP3, Bulk_OUT_Buffer, 8);
    /* Re-arm the OUT Endpoint */
    USBFS_EnableOutEP(EP4);

    }
    
// /* Check to see if OUT Endpoint has data. If so, read EP4 buffer and load back into EP3 for loopback */
// if(USBFS_bGetEPState(EP4) == USBFS_OUT_BUFFER_FULL)
// {
//     /* Determine the number of bytes received */
//     EP4_Count = USBFS_wGetEPCount(EP4);
//     /* Read data from OUT endpoint and store in Bulk_OUT_Buffer */
//     USBFS_ReadOutEP(EP4, Bulk_OUT_Buffer, EP4_Count);
//     /* Create loopback by reloading data received into IN endpoint */
//     USBFS_LoadInEP(EP3, Bulk_OUT_Buffer, EP4_Count);
//     /* Re-arm the OUT Endpoint */
//     USBFS_EnableOutEP(EP4);
// }
}

void Isochronous_Transfer (void)
{
 /* Check to see if OUT Endpoint has data. If so, read EP6 buffer and load back into EP5 for loopback */
 if(USBFS_bGetEPState(EP6) == USBFS_OUT_BUFFER_FULL)
 {
     /* Determine the number of bytes received */
     EP6_Count = USBFS_wGetEPCount(EP6);
     /* Read data from OUT endpoint and store in Isochronous_OUT_Buffer */
     USBFS_ReadOutEP(EP6, Isochronous_OUT_Buffer, EP6_Count);
      /* Create loopback by reloading data received into IN endpoint */
     USBFS_LoadInEP(EP5, Isochronous_OUT_Buffer, EP6_Count);
     /* Re-arm the OUT Endpoint */
     USBFS_EnableOutEP(EP6);
 }
}