#ifndef _PERIFERICOS_
#define _PERIFERICOS_
#include <stdint.h>
// DEVUELVE EL VALOR DEL PIN ANALOGICO ASIGNADO AL POTENCIOMETRO
uint16_t f_leer_pote(void);

/*Lee el valor del buffer del potenciometro y segun el offset por error en la lectura, decide si cambiar o no la velocidad.
- Devuelve el valor el mismo valor de entrada en caso de que no haya cambio significativo
- En caso de modificar la velocidad devuelve el valor actual del potenciometro
*/
uint16_t f_pote_cambia_vel(uint16_t old_pote);

/*TRANSFORMA UN VALOR LEIDO DEL ADC A RPM VALIDO PARA EL MOTOR
*/
uint16_t adc_to_rpm(uint16_t adc_value);

//AUXILIAR MATH

//DEVUELVE EL MODULO DE LA RESTA ENTRE AMBOS NUMEROS
uint16_t diferencia_16(uint16_t a, uint16_t  b);

//FUNCION LOGICA DE POTENCIA, INGRESA a = BASE uint16_t , b = EXPONENTE uint16_t
uint16_t potencia_16(uint16_t a, uint16_t);

#endif
