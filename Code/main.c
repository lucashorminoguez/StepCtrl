#include "fsm_motors.h"

int main(){
    state_t estado_actual = CARGANDO_PARAM;
    motor_ctrl_t ctrl = f_get_ctrl_default();
    long actual_time = TIMEOUT_LIBERADO;
    int lectura_pote = f_leer_pote();

    while(1){
        estado_actual = fsm_ptr[estado_actual](ctrl,&actual_time);
        if (estado_actual != CARGANDO_PARAM){
            lectura_pote = f_pote_cambia_vel(lectura_pote);
        };
    };
    return 0;
};

