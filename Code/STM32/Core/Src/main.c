#include "fsm_motors.h"

int main(){
	f_init_system();
    state_t estado_actual = CARGANDO_PARAM;
    motor_ctrl_t ctrl = f_get_ctrl_default();
    uint32_t actual_time = TIMEOUT_LIBERADO;
    
    while(1){
        estado_actual = fsm_ptr[estado_actual](ctrl,&actual_time);
    }
    return 0;
}

