#include "fsm_motors.h"
#include "Ctrl.h"

state_t f_cargando_param(motor_ctrl_t ctrl){
    if (ctrl.modo==1){
        return ESPERANDO_PASO1;
    }else if (ctrl.modo==0){
        return ESPERANDO_ONESHOT;
    };
    return CARGANDO_PARAM; //Ocurrio un error o cargaron mal el valor
};

state_t f_esperando_oneshot(motor_ctrl_t ctrl){
    if(ctrl.state_trigger_oneshot == h_getSignalPin(ctrl.trigger_oneshot)){ 
        return GIRANDO_ONESHOT;
    };
    return ESPERANDO_ONESHOT;
};

state_t f_girando_oneshot(motor_ctrl_t ctrl){
    if(ctrl.state_trigger_oneshot == h_getSignalPin(ctrl.trigger_oneshot) || ctrl.timeout_0 == 0){
        m_termina(ctrl.vel_0);
        return CARGANDO_PARAM;
    };
    return GIRANDO_ONESHOT; 
};

state_t f_esperando_paso1(motor_ctrl_t ctrl){
    if(ctrl.state_trigger1 == h_getSignalPin(ctrl.trigger_paso2)){
        return GIRANDO1;
    };
    return ESPERANDO_PASO1;
};

state_t f_girando1(motor_ctrl_t ctrl){
    m_arranca(ctrl.vel_1);
    if(ctrl.cant_pasos>GIRANDO1){
        return ESPERANDO_FINAL;
    };
    return ESPERANDO_PASO2;
};

state_t f_esperando_paso2(motor_ctrl_t ctrl){
    if(ctrl.state_trigger2 == h_getSignalPin(ctrl.trigger_paso2)|| ctrl.timeout_1==0){
        return GIRANDO2;
    };
    return ESPERANDO_PASO2;
};

state_t f_girando2(motor_ctrl_t ctrl){
    m_cambia_vel(ctrl.vel_2);
    if(ctrl.cant_pasos>GIRANDO2){
        return ESPERANDO_FINAL;
    };
    return ESPERANDO_PASO3;
};

state_t f_esperando_paso3(motor_ctrl_t ctrl){
    if(ctrl.state_trigger3 == h_getSignalPin(ctrl.trigger_paso3)|| ctrl.timeout_2==0){
        return GIRANDO2;
    };
    return ESPERANDO_PASO3;    
};

state_t f_girando3(motor_ctrl_t ctrl){
    m_cambia_vel(ctrl.vel_3);
    return ESPERANDO_FINAL;
};

state_t f_esperando_final(motor_ctrl_t ctrl){
    if(ctrl.state_trigger_final == h_getSignalPin(ctrl.trigger_final) || ctrl.time_out_final==0){
        return FINALIZANDO;
    };
    return ESPERANDO_FINAL;
};

state_t f_finalizando(motor_ctrl_t ctrl){
    m_termina(0);
    if(!ctrl.habilitacion_ciclo && ctrl.state_habilitacion_ciclo == h_getSignalPin(ctrl.habilitacion_ciclo)){
        return CARGANDO_PARAM;
    };
    return FINALIZANDO;
};

motor_ctrl_t f_get_ctrl_default(){
    motor_ctrl_t ctrl_default = {
        .vel_0 = CTRL_VEL_0,
        .vel_1 = CTRL_VEL_1,
        .vel_2 = CTRL_VEL_2,
        .vel_3 = CTRL_VEL_3,
        .direc_0 = CTRL_DIREC_0,
        .direc_1 = CTRL_DIREC_1,
        .direc_2 = CTRL_DIREC_2,
        .direc_3 = CTRL_DIREC_3,
        .salida = CTRL_SALIDA,
        .trigger_oneshot = CTRL_TRIGGER_ONESHOT,
        .trigger_paso1 = CTRL_TRIGGER_PASO1,
        .trigger_paso2 = CTRL_TRIGGER_PASO2,
        .trigger_paso3 = CTRL_TRIGGER_PASO3,
        .trigger_final = CTRL_TRIGGER_FINAL,
        .habilitacion_ciclo = CTRL_HABILITACION_CICLO,
        .state_trigger_oneshot = CTRL_STATE_TRIGGER_ONESHOT,
        .state_trigger1 = CTRL_STATE_TRIGGER1,
        .state_trigger2 = CTRL_STATE_TRIGGER2,
        .state_trigger3 = CTRL_STATE_TRIGGER3,
        .state_trigger_final = CTRL_STATE_TRIGGER_FINAL,
        .state_habilitacion_ciclo = CTRL_STATE_HABILITACION_CICLO,
        .modo = CTRL_MODO,
        .cant_pasos = CTRL_CANT_PASOS,
        .timeout_0 = CTRL_TIMEOUT_0,
        .timeout_1 = CTRL_TIMEOUT_1,
        .timeout_2 = CTRL_TIMEOUT_2,
        .time_out_final = CTRL_TIMEOUT_FINAL
    };
    
    return ctrl_default;
};