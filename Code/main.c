#include "fsm_motors.h"
#include "perifericos.h"
#include <stdint.h>
int main(){
    state_t estado_actual = CARGANDO_PARAM;
    motor_ctrl_t ctrl = f_get_ctrl_default();
    uint32_t actual_time = TIMEOUT_LIBERADO;
    uint16_t lectura_pote = f_leer_pote();
    
    while(1){
        estado_actual = fsm_ptr[estado_actual](ctrl,&actual_time);
        if (estado_actual > ESPERANDO_PASO1 && estado_actual != FINALIZANDO_CICLO){
            lectura_pote = f_pote_cambia_vel(lectura_pote);
        }
    }
    return 0;
}

