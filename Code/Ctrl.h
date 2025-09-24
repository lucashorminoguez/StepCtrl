#ifndef CTRL_H
#define CTRL_H

// CONFIGURACIÓN DEL MOTOR :
#define PASOS_POR_VUELTA    200
#define MICROSTEPPING       16


// CONFIGURACIÓN FUNCIONAMIENTO POR DEFECTO

#define CTRL_VEL_0          500    // rpm para el Oneshot
#define CTRL_VEL_1          200     // rpm para el Paso 1  
#define CTRL_VEL_2          150     // rpm para el Paso 2
#define CTRL_VEL_3          300     // rpm para el Paso 3

#define CTRL_DIREC_0        0       //Sentido de giro para el Trigger del oneshot
#define CTRL_DIREC_1        0       //Sentido de giro para el Trigger del paso 1
#define CTRL_DIREC_2        1       //Sentido de giro para el Trigger del paso 2
#define CTRL_DIREC_3        0       //Sentido de giro para el Trigger del paso 3

#define CTRL_SALIDA         0

#define CTRL_TRIGGER_ONESHOT    3   // Entrada para el Trigger del oneshot
#define CTRL_TRIGGER_PASO1      0   // Entrada para el Trigger del paso 1
#define CTRL_TRIGGER_PASO2      1   // Entrada para el Trigger del paso 2
#define CTRL_TRIGGER_PASO3      2   // Entrada para el Trigger del paso 3
#define CTRL_TRIGGER_FINAL      3   // Entrada para el Trigger del final
#define CTRL_HABILITACION_CICLO 3   // Entrada para el Trigger de habilitar ciclo

#define CTRL_STATE_TRIGGER_ONESHOT   0   // Activo bajo/alto
#define CTRL_STATE_TRIGGER1          1   // Activo bajo/alto  
#define CTRL_STATE_TRIGGER2          0   // Activo bajo/alto
#define CTRL_STATE_TRIGGER3          1   // Activo bajo/alto
#define CTRL_STATE_TRIGGER_FINAL     0   // Activo bajo/alto
#define CTRL_STATE_HABILITACION_CICLO 0  // Activo bajo/alto

#define CTRL_MODO            1       // Modo continuo
#define CTRL_CANT_PASOS      3       // 3 pasos en modo continuo

#define CTRL_TIMEOUT_0       60       // segundos para el Trigger del oneshot
#define CTRL_TIMEOUT_1       10       // segundos para el Trigger del paso 1
#define CTRL_TIMEOUT_2       10       // segundos para el Trigger del paso 2
#define CTRL_TIMEOUT_FINAL   10      // segundos para el Trigger del final



#endif