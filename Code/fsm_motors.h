#ifndef _FSM_MOTOR_H_
#define _FSM_MOTOR_H_

#include "hardware.h"

// ESTADOS 
typedef enum {
    CARGANDO_PARAM,
    ESPERANDO_PASO1,
    GIRANDO1,
    ESPERANDO_PASO2,
    GIRANDO2,
    ESPERANDO_PASO3,
    GIRANDO3,
    ESPERANDO_ONESHOT,
    GIRANDO_ONESHOT,
    ESPERANDO_FINAL,
    FINALIZANDO
} state_t;

/*FORMATO CTRL :
Estructura de datos cargados por el usuario en archivo CTRL que determina el funcionamiento del programa
*/
typedef struct {    
    int vel_0;      // velocidad del modo oneshot, [rpm] pasado a frecuencia de pulsos 
    int vel_1;      // velocidad del PASO1 en modo Secuencia, [rpm] pasado a frecuencia de pulsos 
    int vel_2;      // velocidad del PASO2 en modo Secuencia, [rpm] pasado a frecuencia de pulsos 
    int vel_3;      // velocidad del PASO3 en modo Secuencia, [rpm] pasado a frecuencia de pulsos 

    int direc_0;    // DIRECCION DEL ONESHOT 0=HORARIO, 1=ANTIHORARIO
    int direc_1;    // DIRECCION PASO1 Secuencia 0=HORARIO, 1=ANTIHORARIO
    int direc_2;    // DIRECCION PASO2 Secuencia 0=HORARIO, 1=ANTIHORARIO
    int direc_3;    // DIRECCION PASO3 Secuencia 0=HORARIO, 1=ANTIHORARIO

    int salida; // próxima implementación

    int trigger_oneshot;    // numero de entrada, 0, 1, 2 y 3=boton
    int trigger_paso1;      // numero de entrada, 0, 1, 2 y 3=boton    
    int trigger_paso2;      // numero de entrada, 0, 1, 2 y 3=boton
    int trigger_paso3;      // numero de entrada, 0, 1, 2 y 3=boton
    int trigger_final;      // numero de entrada, 0, 1, 2 y 3=boton
    int habilitacion_ciclo; // numero de entrada, 0, 1, 2 y 3=boton

    int state_trigger_oneshot;      // 0=ACTIVO BAJO 1=ACTIVO ALTO
    int state_trigger1;             // 0=ACTIVO BAJO 1=ACTIVO ALTO
    int state_trigger2;             // 0=ACTIVO BAJO 1=ACTIVO ALTO
    int state_trigger3;             // 0=ACTIVO BAJO 1=ACTIVO ALTO
    int state_trigger_final;        // 0=ACTIVO BAJO 1=ACTIVO ALTO
    int state_habilitacion_ciclo;   // 0=ACTIVO BAJO 1=ACTIVO ALTO

    int modo; // 0=ONESHOT, 1=Secuencia
    int cant_pasos; //  <1 INACTIVO, cantidad de pasos en modo Secuencia

    int timeout_0; // timeout del modo oneshot[segundos]
    int timeout_1; // timeout del paso1 en modo Secuencia[segundos]
    int timeout_2; // timeout del paso2 en modo Secuencia[segundos]
    int time_out_final; // timeout del paso3 en modo Secuencia[segundos]

} motor_ctrl_t;

/*Decide entre Modo Secuencia y Modo One-shot
de momento no va a cargar valores nuevos pero me sirve que exista. */
state_t f_cargando_param(motor_ctrl_t ctrl);
//Espera Trigger segun el seteo de ctrl para pasar a GIRANDO ONESHOT
state_t f_esperando_oneshot(motor_ctrl_t ctrl);
//Activa el motor y espera devuelta el mismo Trigger o Timeout 
state_t f_girando_oneshot(motor_ctrl_t ctrl);       
//Espera Trigger segun seteo de ctrl para pasar a GIRANDO1
state_t f_esperando_paso1(motor_ctrl_t ctrl);       
/*Activa el motor, con cierta velocidad y sentido de giro segun archivo ctrl.
Avanza a ESPERANDO_PASO2 o ESPERANDO_FINAL segun seteo de cant_pasos*/
state_t f_girando1(motor_ctrl_t ctrl);              
//Espera Trigger o Timeout segun seteo de ctrl para pasar a GIRANDO2
state_t f_esperando_paso2(motor_ctrl_t ctrl);       
/*Modifica velocidad y sentido de giro segun parametros en archivo ctrl.
Avanza a ESPERANDO_PASO3 o ESPERANDO_FINAL segun seteo de cant_pasos*/
state_t f_girando2(motor_ctrl_t ctrl);              
//Espera Trigger o Timeout segun seteo de ctrl para pasar a GIRANDO3
state_t f_esperando_paso3(motor_ctrl_t ctrl);
/*Modifica velocidad y sentido de giro segun parametros en archivo ctrl.
Avanza a ESPERANDO_FINAL */
state_t f_girando3(motor_ctrl_t ctrl);
/*Espera Trigger o Timeout para continuar
Avanza a FINALIZANDO */
state_t f_esperando_final(motor_ctrl_t ctrl);
/*Apaga el motor
Espera Habilitacion de ciclo para continuar 
Vuelve a CARGANDO_PARAM*/
state_t f_finalizando(motor_ctrl_t ctrl);


// ARRAY DE PUNTEROS A FUNCIONES DE ESTADO
state_t (*fsm_ptr[])(motor_ctrl_t ctrl) = {
    f_cargando_param,      // CARGANDO_PARAM
    f_esperando_oneshot,   // ESPERANDO_ONESHOT
    f_girando_oneshot,     // GIRANDO_ONESHOT
    f_esperando_paso1,     // ESPERANDO_PASO1
    f_girando1,            // GIRANDO1
    f_esperando_paso2,     // ESPERANDO_PASO2
    f_girando2,            // GIRANDO2
    f_esperando_paso3,     // ESPERANDO_PASO3
    f_girando3,            // GIRANDO3
    f_esperando_final,     // ESPERANDO_FINAL
    f_finalizando          // FINALIZANDO
};

// DEVUELVE LOS VALORES DE ARCHIVO CTRL
motor_ctrl_t f_get_ctrl_default(); 
//CARGA VALORES EN CONFIG, POR EL MOMENTO NO TIENE APLICACIÓN
int f_set_ctrl(motor_ctrl_t new_ctrl); 

#endif


