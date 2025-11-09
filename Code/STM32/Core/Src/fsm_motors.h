#ifndef _FSM_MOTOR_H_
#define _FSM_MOTOR_H_

#include <stdint.h>

#define TIMEOUT_LIBERADO 0 //INDICA LA DISPONIBILIDAD DE LA VARIABLE PARA TIMEOUT

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
    FINALIZANDO_CICLO
} state_t;


/*FORMATO CTRL :
Estructura de datos cargados por el usuario en archivo CTRL que determina el funcionamiento del programa
*/
typedef struct {    
    uint16_t vel_0;      // velocidad del modo oneshot, [rpm] pasado a frecuencia de pulsos 
    uint16_t vel_1;      // velocidad del PASO1 en modo Secuencia, [rpm] pasado a frecuencia de pulsos 
    uint16_t vel_2;      // velocidad del PASO2 en modo Secuencia, [rpm] pasado a frecuencia de pulsos 
    uint16_t vel_3;      // velocidad del PASO3 en modo Secuencia, [rpm] pasado a frecuencia de pulsos 

    uint8_t direc_0;    // DIRECCION DEL ONESHOT 0=HORARIO, 1=ANTIHORARIO
    uint8_t direc_1;    // DIRECCION PASO1 Secuencia 0=HORARIO, 1=ANTIHORARIO
    uint8_t direc_2;    // DIRECCION PASO2 Secuencia 0=HORARIO, 1=ANTIHORARIO
    uint8_t direc_3;    // DIRECCION PASO3 Secuencia 0=HORARIO, 1=ANTIHORARIO

    uint8_t salida; // próxima implementación

    uint8_t trigger_oneshot;    // numero de entrada 1, 2, 3 y 4=boton
    uint8_t trigger_paso1;      // numero de entrada 1, 2, 3 y 4=boton    
    uint8_t trigger_paso2;      // numero de entrada 1, 2, 3 y 4=boton
    uint8_t trigger_paso3;      // numero de entrada 1, 2, 3 y 4=boton
    uint8_t trigger_final;      // numero de entrada 1, 2, 3 y 4=boton
    uint8_t habilitacion_ciclo; // numero de entrada, 0=desactivada 1, 2, 3 y 4=boton

    uint8_t state_trigger_oneshot;      // 0=ACTIVO BAJO 1=ACTIVO ALTO
    uint8_t state_trigger1;             // 0=ACTIVO BAJO 1=ACTIVO ALTO
    uint8_t state_trigger2;             // 0=ACTIVO BAJO 1=ACTIVO ALTO
    uint8_t state_trigger3;             // 0=ACTIVO BAJO 1=ACTIVO ALTO
    uint8_t state_trigger_final;        // 0=ACTIVO BAJO 1=ACTIVO ALTO
    uint8_t state_habilitacion_ciclo;   // 0=ACTIVO BAJO 1=ACTIVO ALTO

    uint8_t modo;         // 0=ONESHOT, 1=Secuencia
    uint8_t cant_pasos; //  <1 INACTIVO, cantidad de pasos en modo Secuencia

    uint32_t timeout_0; // timeout del modo oneshot[segundos]
    uint32_t timeout_1; // timeout del paso1 en modo Secuencia[segundos]
    uint32_t timeout_2; // timeout del paso2 en modo Secuencia[segundos]
    uint32_t time_out_final; // timeout del paso3 en modo Secuencia[segundos]

} motor_ctrl_t;

/*Decide entre Modo Secuencia y Modo One-shot
de momento no va a cargar valores nuevos pero me sirve que exista. */
state_t f_cargando_param(motor_ctrl_t ctrl, uint32_t *actual_time);
//Espera Trigger segun el seteo de ctrl para pasar a GIRANDO ONESHOT
state_t f_esperando_oneshot(motor_ctrl_t ctrl,uint32_t *actual_time);
//Activa el motor y espera devuelta el mismo Trigger o Timeout 
state_t f_girando_oneshot(motor_ctrl_t ctrl,uint32_t *actual_time);       
//Espera Trigger segun seteo de ctrl para pasar a GIRANDO1
state_t f_esperando_paso1(motor_ctrl_t ctrl,uint32_t *actual_time);       
/*Activa el motor, con cierta velocidad y sentido de giro segun archivo ctrl.
Avanza a ESPERANDO_PASO2 o ESPERANDO_FINAL segun seteo de cant_pasos*/
state_t f_girando1(motor_ctrl_t ctrl,uint32_t *actual_time);              
//Espera Trigger o Timeout segun seteo de ctrl para pasar a GIRANDO2
state_t f_esperando_paso2(motor_ctrl_t ctrl,uint32_t *actual_time);       
/*Modifica velocidad y sentido de giro segun parametros en archivo ctrl.
Avanza a ESPERANDO_PASO3 o ESPERANDO_FINAL segun seteo de cant_pasos*/
state_t f_girando2(motor_ctrl_t ctrl,uint32_t *actual_time);              
//Espera Trigger o Timeout segun seteo de ctrl para pasar a GIRANDO3
state_t f_esperando_paso3(motor_ctrl_t ctrl,uint32_t *actual_time);
/*Modifica velocidad y sentido de giro segun parametros en archivo ctrl.
Avanza a ESPERANDO_FINAL */
state_t f_girando3(motor_ctrl_t ctrl,uint32_t *actual_time);
/*Espera Trigger o Timeout para continuar
Avanza a FINALIZANDO_CICLO */
state_t f_esperando_final(motor_ctrl_t ctrl,uint32_t *actual_time);
/*Apaga el motor
Espera Habilitacion de ciclo para continuar 
Vuelve a CARGANDO_PARAM*/
state_t f_finalizando(motor_ctrl_t ctrl,uint32_t *actual_time);


/*ARRAY DE PUNTEROS A FUNCIONES DE ESTADO DEL PROGRAMA PRINCIPAL
- Todas las funciones reciben por valor la estructura de datos ctrl y por referencia la variable actual_time
- actual_time : Sirve para realizar operaciones de tiempo con persistencia entre funciones, -1 indica el estado de "liberado"*/
extern const state_t (*fsm_ptr[])(motor_ctrl_t ctrl, uint32_t *actual_time);

// DEVUELVE LOS VALORES DE DEFAULT GUARDADOS EN EL ARCHIVO CTRL
motor_ctrl_t f_get_ctrl_default(); 

//CARGA VALORES EN CONFIG, POR EL MOMENTO NO TIENE APLICACIÓN
uint16_t f_set_ctrl(motor_ctrl_t new_ctrl); 

// TRANSFORMA EL VALOR EN RPM RECIBIDO POR EL USUARIO EN FRECUENCIA
uint16_t h_rpm_to_freq(uint16_t rpm );

// INICIALIZA EL MICROCONTROLADOR : invoca a la función h_micro_init() en hal.h sin dar acceso a el
int f_init_system(void);

#endif


