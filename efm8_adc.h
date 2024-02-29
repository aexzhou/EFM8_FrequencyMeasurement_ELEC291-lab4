#include <EFM8LB1.h>
#include <stdio.h>

#define SYSCLK      72000000L  // SYSCLK frequency in Hz
#define BAUDRATE      115200L  // Baud rate of UART in bps

#define LCD_RS P1_7
// #define LCD_RW Px_x // Not used in this code.  Connect to GND
#define LCD_E  P2_0
#define LCD_D4 P1_3
#define LCD_D5 P1_2
#define LCD_D6 P1_1
#define LCD_D7 P1_0
#define CHARS_PER_LINE 16

#define ADC_PORT_IN P0_2 // ADC0.1 (ADC0P1) ADCCOMX: 00001
#define ADC_MUX_SEL  0b00001


void init_adc(void){
    //configure voltage reference
    REF0CN = 
    
}


unsigned long read_adc(void){

}

ADCFactor = (float)ADC_VREF_MILLIVOLTS/ADC_2POWER10;

for(delay = 0; delay < 16; delay++)
{
        //connect the ADC input to ground
        SFRPAGE = 0x00;
        ADC0MX = ADC_IN;

        //delay about 20 us
        Timer3us(20)

        //connect the ADC input to P0.2 and initiate a conversion
        /*the delay between setting the multiplexer and 
        starting the conversion increases with each loop iteration*/
        SFRPAGE = 0x00;
        ADC0MX = ADC_MUX_SEL;
        SFRPAGE = TIMER4_PAGE; TMR4L = 0; while(TMR4L < delay);
        SFRPAGE = ADC0_PAGE;
        ADC0CN0_ADBUSY = START_CONV;

        //wait until the conversion is complete
        while(ADC_CONV_COMPLETE == FALSE);
        ADC_CONV_COMPLETE = FALSE;

        //Retrieve the 10-bit ADC value, convert it to a voltage amplitude, and display the measurement
        SFRPAGE = ADC0_PAGE;
        RawADCResult = ADC0;

        ADCMeasurement = RawADCResult*ADCFactor;

        ConvertMeasurementandDisplay(VOLTAGE, ADCMeasurement);

        //delay for about 1 second
        SFRPAGE = TIMER3_PAGE; TMR3 = 0; while(TMR3 < 10000);
}