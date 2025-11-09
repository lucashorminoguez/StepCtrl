#ifndef _HAL_CTRL_
#define _HAL_CTRL_
#include <stdint.h>

//DECLARACIONES PARA LAS FUNCIONES NECESARIAS EN CUALQUIER MICRO :

// ERROR PARA LAS FUNCIONES : 
#define H_MICRO_ERROR   128
// RESOLUCION DEL ADC DEL MICRO :
#define ADC_BITS 12
// VALOR MAXIMO DEL ADC DEL MICRO, DEPENDE DE ADC_BITS :
#define ADC_MAX_VALUE ((1 << ADC_BITS) - 1)
//Inicializa configuraciones necesarias en microcontrolador :
int h_micro_init();

//  MOTOR :

// CAMBIA LA DIRECCION DEL MOTOR
uint16_t m_set_direc(uint16_t freq);
// RAMPA DE ARRANQUE DEL MOTOR
uint16_t m_arranca(uint16_t freq);
// FRENA SIN RAMPA, CASO DE EMERGENCIA     
uint16_t m_stop(void);              
// CAMBIA LA VELOCIDAD CON RAMPA 
uint16_t m_cambia_vel(uint16_t freq);
// TERMINA DE GIRAR CON RAMPA
uint16_t m_termina(uint16_t freq);

// SEÑALES DE ENTRADA :

#define POTENCIOMETRO 0 //ENTRADA ANALOGICA
#define SIGNAL1 1       // PIN DE ENTRADA DIGITAL PARA TRIGGER
#define SIGNAL2 2       // PIN DE ENTRADA DIGITAL PARA TRIGGER
#define SIGNAL3 3       // PIN DE ENTRADA DIGITAL PARA TRIGGER
#define SIGNAL4 4       // PIN DE ENTRADA DIGITAL PARA TRIGGER
#define BOTON1 5        // PIN DE ENTRADA DIGITAL PARA BOTON
#define BOTON2 6        // PIN DE ENTRADA DIGITAL PARA BOTON
#define BOTON3 7        // PIN DE ENTRADA DIGITAL PARA BOTON
#define BOTON4 8        // PIN DE ENTRADA DIGITAL PARA BOTON


#define ERROR_POTE 9    //Error ajustable para no tomar variaciones del potenciometro en falso

/* DEVUELVE EL ESTADO DE LA ENTRADA ASOCIADA A UN PIN DEL MICROCONTROLADOR :
    - SIGNAL1
    - SIGNAL2 
    - SIGNAL3 
    - BOTON1 
    - BOTON2
    - BOTON3
    - BOTON4
*/
uint8_t h_getDigital(uint8_t index);

/* DEVUELVE EL VALOR DE LA ENTRADA ASOCIADA A UN PIN DEL MICROCONTROLADOR :
   - POTENCIOMETRO
*/
uint16_t h_getAnalog(uint16_t index);

// TIMERS :

//Devuelve el tiempo transcurrido en milisengundos 
uint32_t h_getMilis(); 


#endif
