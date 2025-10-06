#include "config_op.h"
#include "Ctrl.h"

uint16_t c_rpm_to_freq(uint16_t rpm ){
    uint16_t freq = (rpm/60)*(PASOS_POR_VUELTA * MICROSTEPPING);
    return freq;
}

