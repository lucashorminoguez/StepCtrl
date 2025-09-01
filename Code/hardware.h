#ifndef _HARDWARE_
#define _HARDWARE_
// MICROCONTROLADOR :



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

//FUNCIONES :

/** DEVUELVE EL ESTADO DE LA ENTRADA ASOCIADA A UN PIN DEL MICROCONTROLADOR 
    SIGNAL 1 = 0 ; SIGNAL 2 = 1 ; SIGNAL 3 = 2 ; BOTON 1 = 3; BOTON 2 ; BOTON 3 ; BOTON 4 ;
*/
int h_getSignalPin(int index);

#endif