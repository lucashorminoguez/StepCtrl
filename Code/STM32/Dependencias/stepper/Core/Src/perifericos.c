#include "perifericos.h"
#include "hal_micro.h"
#include "config_op.h"
#include "Ctrl.h"

uint16_t f_leer_pote(){
    return h_getAnalog(POTENCIOMETRO);
}

uint16_t f_pote_cambia_vel(uint16_t old_pote){
    uint16_t new_pote = (diferencia_16(old_pote,f_leer_pote())>= ERROR_POTE) ? (f_leer_pote()) : (old_pote);
    if (old_pote != new_pote){
        m_cambia_vel(c_rpm_to_freq(adc_to_rpm(new_pote)));
    }
    return new_pote;
}

uint16_t adc_to_rpm(uint16_t adc_value){
	uint16_t rpm = (adc_value * MAX_RPM) / ADC_MAX_VALUE;
	return rpm;
}

uint16_t diferencia_16(uint16_t a, uint16_t b){
    uint16_t dif = (a > b) ? (a - b) : (b - a);
    return dif;
}

uint16_t potencia_16(uint16_t a, uint16_t b){
	uint16_t pot = 1;
	for(uint16_t i=0;i<b;i++){
		pot *= a;
	}
	return pot;
}
