#ifndef _HAL_CTRL_
#define _HAL_CTRL_
//DECLARACIONES PARA LAS FUNCIONES NECESARIAS EN CUALQUIER MICRO :

//  MOTOR :

// CAMBIA LA DIRECCION DEL MOTOR
int m_set_direc(int vel); 
// RAMPA DE ARRANQUE DEL MOTOR
int m_arranca(int vel);
// FRENA SIN RAMPA, CASO DE EMERGENCIA     
int m_stop();              
// CAMBIA LA VELOCIDAD CON RAMPA 
int m_cambia_vel(int vel);
// TERMINA DE GIRAR CON RAMPA
int m_termina(int vel);

// SEÑALES DE ENTRADA :

#define POTENCIOMETRO 0 //ENTRADA ANALOGICA
#define SIGNAL1 1       // PIN DE ENTRADA DIGITAL PARA TRIGGER
#define SIGNAL2 2       // PIN DE ENTRADA DIGITAL PARA TRIGGER
#define SIGNAL3 3       // PIN DE ENTRADA DIGITAL PARA TRIGGER
#define BOTON1 4        // PIN DE ENTRADA DIGITAL PARA BOTON 
#define BOTON2 5        // PIN DE ENTRADA DIGITAL PARA BOTON
#define BOTON3 6        // PIN DE ENTRADA DIGITAL PARA BOTON
#define BOTON4 7        // PIN DE ENTRADA DIGITAL PARA BOTON
#define ERROR_POTE 8    //Error ajustable para no tomar variaciones del potenciometro en falso 

/* DEVUELVE EL ESTADO DE LA ENTRADA ASOCIADA A UN PIN DEL MICROCONTROLADOR :
    - SIGNAL1
    - SIGNAL2 
    - SIGNAL3 
    - BOTON1 
    - BOTON2
    - BOTON3
    - BOTON4
*/
int h_getDigital(int index);

/* DEVUELVE EL VALOR DE LA ENTRADA ASOCIADA A UN PIN DEL MICROCONTROLADOR :
   - POTENCIOMETRO
*/
int h_getAnalog(int index);

// TIMERS :

//Devuelve el tiempo transcurrido en milisengundos 
long h_getMilis(); 

#endif