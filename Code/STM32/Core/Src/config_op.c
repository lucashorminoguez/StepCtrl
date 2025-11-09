#include "config_op.h"
#include "Ctrl.h"

uint16_t c_rpm_to_freq(uint16_t rpm ){
    //uint32_t necesario para calculos intermedios
    uint32_t freq_calc = ((uint32_t)rpm * PASOS_POR_VUELTA * MICROSTEPPING) / 60;
    /*factor de correccion del 1.5% aprox, uso aritmetica entera para hacerlo rapido
    */
    freq_calc = (freq_calc * 1015) / 1000;
    return (uint16_t)freq_calc;
}

