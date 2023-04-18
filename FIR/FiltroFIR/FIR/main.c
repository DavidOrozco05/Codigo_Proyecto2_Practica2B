    /**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.8
        Device            :  PIC18F46K42
        Driver Version    :  2.00
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#include "mcc_generated_files/mcc.h"
#include "cola.h"
#include "filtro.h"
#include "Funciones.h"

static const uint8_t lookuphexa[] =
{
48, 49, 50, 51, 52, 53, 54, 55,
56, 57, 97, 98, 99, 100, 101, 102,
};

volatile char ADCInterrupt = 0;
char conv = 0;
int resultado = 0;
int resultado_filtro = 0;
char D1, D2, D3, D4, D5, D6;
char Dato1 = 0;
char Dato2 = 0;
char inicie_envio = 0;
void InterruocionADC(void){
    ADCInterrupt = 1;
}

/*
                         Main application
 */
void main(void)
{
    // Initialize the device
    SYSTEM_Initialize();

    // If using interrupts in PIC18 High/Low Priority Mode you need to enable the Global High and Low Interrupts
    // If using interrupts in PIC Mid-Range Compatibility Mode you need to enable the Global Interrupts
    // Use the following macros to:

    // Enable the Global Interrupts
    INTERRUPT_GlobalInterruptEnable();

    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();
    INTERRUPT_Initialize();
    UART1_Initialize();
    eCola cola;
    inicie_cola(&cola); 
    ADCC_SetADIInterruptHandler(InterruocionADC);
    ADPCH = primerADC;
    SPI1CON0bits.EN = 1;
    while (1)
    {
        if(ADCInterrupt==1){
            ADCInterrupt = 0;
            resultado = ADCC_GetConversionResult();
            D1 = lookuphexa[(resultado>>8)&0x0F];
            D2 = lookuphexa[(resultado>>4)&0x0F];
            D3 = lookuphexa[(resultado)&0x0F];
            Out_SetHigh();
            resultado_filtro = filtrar_dato((long)(resultado));
            D4 = lookuphexa[(resultado_filtro>>8)&0x0F];
            D5 = lookuphexa[(resultado_filtro>>4)&0x0F];
            D6 = lookuphexa[(resultado_filtro)&0x0F];
            Out_SetLow();
            //resultado_filtro = resultado;
            Dato1 = ((0x00 << 7) & (0x80)) | ((0x01 << 5) & (0x20)) | ((0x01 << 4) & (0x10)) | (resultado_filtro >> 8) & (0x0F);
            Dato2 = (resultado_filtro & 0xFF); 
            UART1_Write(D1);
            UART1_Write(D2);
            UART1_Write(D3);
            UART1_Write(',');
            UART1_Write(Dato1);
            UART1_Write(D5);
            UART1_Write(D6);
            UART1_Write('\n');
            //cola_add(&cola,(char)((resultado & 0x0F00) >> 8));
            //cola_add(&cola,(char)(resultado & 0x00FF));
            //cola_add(&cola,(char)(0x13));
            //cola_add(&cola,(char)(0x10));
            conv = 1;
        }
        if(!(inicie_envio) && conv){
            DAC_CS_SetLow();
            SPI1_WriteByte(Dato1);
            SPI1_WriteByte(Dato2);
            inicie_envio = 1;
            conv = 0;
        }
       if((SPI1STATUSbits.TXBE) && inicie_envio){
           inicie_envio = 0;
           DAC_CS_SetHigh();
           LDAC_SetLow();
           LDAC_SetHigh();

       }
        //if(!(cola_vacia(&cola)) && UART1_is_tx_ready()){
        //    U1TXB = cola_get(&cola);
        //}
        
    }
}
/**
 End of File
*/