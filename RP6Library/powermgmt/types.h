#ifndef powermgmt_types_h
    #define powermgmt_types_h

/* ADC states */
typedef struct ADCStates_s {
    uint16_t adcBat;
    uint16_t adcMotorCurrentLeft;
    uint16_t adcMotorCurrentRight;
    uint16_t adcLSL;
    uint16_t adcLSR;
    uint16_t adc0;
    uint16_t adc1;
} powermgmt_ADCStates_t;

#endif
