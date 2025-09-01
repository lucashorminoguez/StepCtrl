#include "fsm_motors.h"

int main(){

    state_t estado_actual = CARGANDO_PARAM;
    motor_ctrl_t ctrl = f_get_ctrl_default();
    while(1){
        estado_actual = fsm_ptr[estado_actual](ctrl);
        if(estado_actual == CARGANDO_PARAM){
            //ctrl = f_get_ctrl();
        };
    };
    return 0;
};

