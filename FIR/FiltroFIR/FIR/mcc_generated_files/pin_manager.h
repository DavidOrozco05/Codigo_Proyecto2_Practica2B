/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for .
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.8
        Device            :  PIC18F46K42
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.36 and above
        MPLAB 	          :  MPLAB X 6.00	
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

#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

/**
  Section: Included Files
*/

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set primerADC aliases
#define primerADC_TRIS                 TRISAbits.TRISA6
#define primerADC_LAT                  LATAbits.LATA6
#define primerADC_PORT                 PORTAbits.RA6
#define primerADC_WPU                  WPUAbits.WPUA6
#define primerADC_OD                   ODCONAbits.ODCA6
#define primerADC_ANS                  ANSELAbits.ANSELA6
#define primerADC_SetHigh()            do { LATAbits.LATA6 = 1; } while(0)
#define primerADC_SetLow()             do { LATAbits.LATA6 = 0; } while(0)
#define primerADC_Toggle()             do { LATAbits.LATA6 = ~LATAbits.LATA6; } while(0)
#define primerADC_GetValue()           PORTAbits.RA6
#define primerADC_SetDigitalInput()    do { TRISAbits.TRISA6 = 1; } while(0)
#define primerADC_SetDigitalOutput()   do { TRISAbits.TRISA6 = 0; } while(0)
#define primerADC_SetPullup()          do { WPUAbits.WPUA6 = 1; } while(0)
#define primerADC_ResetPullup()        do { WPUAbits.WPUA6 = 0; } while(0)
#define primerADC_SetPushPull()        do { ODCONAbits.ODCA6 = 0; } while(0)
#define primerADC_SetOpenDrain()       do { ODCONAbits.ODCA6 = 1; } while(0)
#define primerADC_SetAnalogMode()      do { ANSELAbits.ANSELA6 = 1; } while(0)
#define primerADC_SetDigitalMode()     do { ANSELAbits.ANSELA6 = 0; } while(0)

// get/set LDAC aliases
#define LDAC_TRIS                 TRISBbits.TRISB4
#define LDAC_LAT                  LATBbits.LATB4
#define LDAC_PORT                 PORTBbits.RB4
#define LDAC_WPU                  WPUBbits.WPUB4
#define LDAC_OD                   ODCONBbits.ODCB4
#define LDAC_ANS                  ANSELBbits.ANSELB4
#define LDAC_SetHigh()            do { LATBbits.LATB4 = 1; } while(0)
#define LDAC_SetLow()             do { LATBbits.LATB4 = 0; } while(0)
#define LDAC_Toggle()             do { LATBbits.LATB4 = ~LATBbits.LATB4; } while(0)
#define LDAC_GetValue()           PORTBbits.RB4
#define LDAC_SetDigitalInput()    do { TRISBbits.TRISB4 = 1; } while(0)
#define LDAC_SetDigitalOutput()   do { TRISBbits.TRISB4 = 0; } while(0)
#define LDAC_SetPullup()          do { WPUBbits.WPUB4 = 1; } while(0)
#define LDAC_ResetPullup()        do { WPUBbits.WPUB4 = 0; } while(0)
#define LDAC_SetPushPull()        do { ODCONBbits.ODCB4 = 0; } while(0)
#define LDAC_SetOpenDrain()       do { ODCONBbits.ODCB4 = 1; } while(0)
#define LDAC_SetAnalogMode()      do { ANSELBbits.ANSELB4 = 1; } while(0)
#define LDAC_SetDigitalMode()     do { ANSELBbits.ANSELB4 = 0; } while(0)

// get/set RC3 procedures
#define RC3_SetHigh()            do { LATCbits.LATC3 = 1; } while(0)
#define RC3_SetLow()             do { LATCbits.LATC3 = 0; } while(0)
#define RC3_Toggle()             do { LATCbits.LATC3 = ~LATCbits.LATC3; } while(0)
#define RC3_GetValue()              PORTCbits.RC3
#define RC3_SetDigitalInput()    do { TRISCbits.TRISC3 = 1; } while(0)
#define RC3_SetDigitalOutput()   do { TRISCbits.TRISC3 = 0; } while(0)
#define RC3_SetPullup()             do { WPUCbits.WPUC3 = 1; } while(0)
#define RC3_ResetPullup()           do { WPUCbits.WPUC3 = 0; } while(0)
#define RC3_SetAnalogMode()         do { ANSELCbits.ANSELC3 = 1; } while(0)
#define RC3_SetDigitalMode()        do { ANSELCbits.ANSELC3 = 0; } while(0)

// get/set RC4 procedures
#define RC4_SetHigh()            do { LATCbits.LATC4 = 1; } while(0)
#define RC4_SetLow()             do { LATCbits.LATC4 = 0; } while(0)
#define RC4_Toggle()             do { LATCbits.LATC4 = ~LATCbits.LATC4; } while(0)
#define RC4_GetValue()              PORTCbits.RC4
#define RC4_SetDigitalInput()    do { TRISCbits.TRISC4 = 1; } while(0)
#define RC4_SetDigitalOutput()   do { TRISCbits.TRISC4 = 0; } while(0)
#define RC4_SetPullup()             do { WPUCbits.WPUC4 = 1; } while(0)
#define RC4_ResetPullup()           do { WPUCbits.WPUC4 = 0; } while(0)
#define RC4_SetAnalogMode()         do { ANSELCbits.ANSELC4 = 1; } while(0)
#define RC4_SetDigitalMode()        do { ANSELCbits.ANSELC4 = 0; } while(0)

// get/set RC5 procedures
#define RC5_SetHigh()            do { LATCbits.LATC5 = 1; } while(0)
#define RC5_SetLow()             do { LATCbits.LATC5 = 0; } while(0)
#define RC5_Toggle()             do { LATCbits.LATC5 = ~LATCbits.LATC5; } while(0)
#define RC5_GetValue()              PORTCbits.RC5
#define RC5_SetDigitalInput()    do { TRISCbits.TRISC5 = 1; } while(0)
#define RC5_SetDigitalOutput()   do { TRISCbits.TRISC5 = 0; } while(0)
#define RC5_SetPullup()             do { WPUCbits.WPUC5 = 1; } while(0)
#define RC5_ResetPullup()           do { WPUCbits.WPUC5 = 0; } while(0)
#define RC5_SetAnalogMode()         do { ANSELCbits.ANSELC5 = 1; } while(0)
#define RC5_SetDigitalMode()        do { ANSELCbits.ANSELC5 = 0; } while(0)

// get/set RC6 procedures
#define RC6_SetHigh()            do { LATCbits.LATC6 = 1; } while(0)
#define RC6_SetLow()             do { LATCbits.LATC6 = 0; } while(0)
#define RC6_Toggle()             do { LATCbits.LATC6 = ~LATCbits.LATC6; } while(0)
#define RC6_GetValue()              PORTCbits.RC6
#define RC6_SetDigitalInput()    do { TRISCbits.TRISC6 = 1; } while(0)
#define RC6_SetDigitalOutput()   do { TRISCbits.TRISC6 = 0; } while(0)
#define RC6_SetPullup()             do { WPUCbits.WPUC6 = 1; } while(0)
#define RC6_ResetPullup()           do { WPUCbits.WPUC6 = 0; } while(0)
#define RC6_SetAnalogMode()         do { ANSELCbits.ANSELC6 = 1; } while(0)
#define RC6_SetDigitalMode()        do { ANSELCbits.ANSELC6 = 0; } while(0)

// get/set RC7 procedures
#define RC7_SetHigh()            do { LATCbits.LATC7 = 1; } while(0)
#define RC7_SetLow()             do { LATCbits.LATC7 = 0; } while(0)
#define RC7_Toggle()             do { LATCbits.LATC7 = ~LATCbits.LATC7; } while(0)
#define RC7_GetValue()              PORTCbits.RC7
#define RC7_SetDigitalInput()    do { TRISCbits.TRISC7 = 1; } while(0)
#define RC7_SetDigitalOutput()   do { TRISCbits.TRISC7 = 0; } while(0)
#define RC7_SetPullup()             do { WPUCbits.WPUC7 = 1; } while(0)
#define RC7_ResetPullup()           do { WPUCbits.WPUC7 = 0; } while(0)
#define RC7_SetAnalogMode()         do { ANSELCbits.ANSELC7 = 1; } while(0)
#define RC7_SetDigitalMode()        do { ANSELCbits.ANSELC7 = 0; } while(0)

// get/set Out aliases
#define Out_TRIS                 TRISDbits.TRISD4
#define Out_LAT                  LATDbits.LATD4
#define Out_PORT                 PORTDbits.RD4
#define Out_WPU                  WPUDbits.WPUD4
#define Out_OD                   ODCONDbits.ODCD4
#define Out_ANS                  ANSELDbits.ANSELD4
#define Out_SetHigh()            do { LATDbits.LATD4 = 1; } while(0)
#define Out_SetLow()             do { LATDbits.LATD4 = 0; } while(0)
#define Out_Toggle()             do { LATDbits.LATD4 = ~LATDbits.LATD4; } while(0)
#define Out_GetValue()           PORTDbits.RD4
#define Out_SetDigitalInput()    do { TRISDbits.TRISD4 = 1; } while(0)
#define Out_SetDigitalOutput()   do { TRISDbits.TRISD4 = 0; } while(0)
#define Out_SetPullup()          do { WPUDbits.WPUD4 = 1; } while(0)
#define Out_ResetPullup()        do { WPUDbits.WPUD4 = 0; } while(0)
#define Out_SetPushPull()        do { ODCONDbits.ODCD4 = 0; } while(0)
#define Out_SetOpenDrain()       do { ODCONDbits.ODCD4 = 1; } while(0)
#define Out_SetAnalogMode()      do { ANSELDbits.ANSELD4 = 1; } while(0)
#define Out_SetDigitalMode()     do { ANSELDbits.ANSELD4 = 0; } while(0)

// get/set DAC_CS aliases
#define DAC_CS_TRIS                 TRISEbits.TRISE0
#define DAC_CS_LAT                  LATEbits.LATE0
#define DAC_CS_PORT                 PORTEbits.RE0
#define DAC_CS_WPU                  WPUEbits.WPUE0
#define DAC_CS_OD                   ODCONEbits.ODCE0
#define DAC_CS_ANS                  ANSELEbits.ANSELE0
#define DAC_CS_SetHigh()            do { LATEbits.LATE0 = 1; } while(0)
#define DAC_CS_SetLow()             do { LATEbits.LATE0 = 0; } while(0)
#define DAC_CS_Toggle()             do { LATEbits.LATE0 = ~LATEbits.LATE0; } while(0)
#define DAC_CS_GetValue()           PORTEbits.RE0
#define DAC_CS_SetDigitalInput()    do { TRISEbits.TRISE0 = 1; } while(0)
#define DAC_CS_SetDigitalOutput()   do { TRISEbits.TRISE0 = 0; } while(0)
#define DAC_CS_SetPullup()          do { WPUEbits.WPUE0 = 1; } while(0)
#define DAC_CS_ResetPullup()        do { WPUEbits.WPUE0 = 0; } while(0)
#define DAC_CS_SetPushPull()        do { ODCONEbits.ODCE0 = 0; } while(0)
#define DAC_CS_SetOpenDrain()       do { ODCONEbits.ODCE0 = 1; } while(0)
#define DAC_CS_SetAnalogMode()      do { ANSELEbits.ANSELE0 = 1; } while(0)
#define DAC_CS_SetDigitalMode()     do { ANSELEbits.ANSELE0 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/