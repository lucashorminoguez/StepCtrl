# StepCtrl
Sistema de manejo y control de motores paso a paso.
## Microcontrolador
el pretendido es un STM32 STM32F103C8T6, no tengo experiencia usandolo. Lo escuche en clase y me parecio una buena idea implementarlo por las prestaciones de los timers y que son usados para tareas similares.
## Motor y driver 
Cualquiera, este modulo carece de fuente y manejo de corriente para los motores, solo envia la secuencia de steps segun seteos y entradas aisladas.
## Cargar Valores
Los campos a modificar por el usuario según el proyecto son:

- CTRL_VEL_0 : Velocidad [rpm] para el Trigger del oneshot
- CTRL_VEL_1 : Velocidad [rpm] para el Trigger del paso 1  
- CTRL_VEL_2 : Velocidad [rpm] para el Trigger del paso 2
- CTRL_VEL_3 : Velocidad [rpm] para el Trigger del paso 3

- CTRL_DIREC_0 : Sentido de giro para el Trigger del oneshot
- CTRL_DIREC_1 : Sentido de giro para el Trigger del paso 1
- CTRL_DIREC_2 : Sentido de giro para el Trigger del paso 2
- CTRL_DIREC_3 : Sentido de giro para el Trigger del paso 3

- CTRL_SALIDA  : Salida Configurable 

- CTRL_TRIGGER_ONESHOT    : Entrada para el Trigger del oneshot
- CTRL_TRIGGER_PASO1      : Entrada para el Trigger del paso 1
- CTRL_TRIGGER_PASO2      : Entrada para el Trigger del paso 2
- CTRL_TRIGGER_PASO3      : Entrada para el Trigger del paso 3
- CTRL_TRIGGER_FINAL      : Entrada para el Trigger del final
- CTRL_HABILITACION_CICLO : Entrada para el Trigger de habilitar ciclo

- CTRL_STATE_TRIGGER_ONESHOT    :Activo bajo/alto
- CTRL_STATE_TRIGGER1           :Activo bajo/alto  
- CTRL_STATE_TRIGGER2           :Activo bajo/alto
- CTRL_STATE_TRIGGER3           :Activo bajo/alto
- CTRL_STATE_TRIGGER_FINAL      :Activo bajo/alto
- CTRL_STATE_HABILITACION_CICLO :Activo bajo/alto

- CTRL_MODO            1       : Modo continuo o Modo ONE-SHOT
- CTRL_CANT_PASOS      3       : Hasta 3 Pasos/Movimientos independientes en modo continuo

- CTRL_TIMEOUT_0       60      : Timeout [Segundos] para el Trigger del oneshot
- CTRL_TIMEOUT_1       10      : Timeout [Segundos] para el Trigger del paso 1
- CTRL_TIMEOUT_2       10      : Timeout [Segundos] para el Trigger del paso 2
- CTRL_TIMEOUT_FINAL   10      : Timeout [Segundos] para el Trigger del final

### Seteo de campos usando el archivo CTRL.h :
De momento se van a ingresar modificando los #define con los campos expresados arriba antes de la compilación. Esto es para tener una buena base sin complicar el desarrollo, la intención es en un futuro poner display y armar la ui para ejecutar cambios en caliente.
## Funcionamiento :

### Modo One-Shot:  El modo simple para disparo del motor. Solo se tiene en cuenta el Trigger y se puede configurar si dar fin al movimiento por tiempo o trigger/señal externa.
### Modo Continuo : Este modo es mas completo, se pueden configurar de 2 a 3 pasos o instancias con parámetros independientes sincronizadas por trigger,timer, señal externa o cantidad de pulsos individual.
*Aclaracion : La instancia intermedia, puede ser usada para un tiempo muerto donde se requiera no accionar el motor (velocidad=0).* 
## Diagrama de estados :
![Image_Alt](https://github.com/lucashorminoguez/StepCtrl/blob/main/StepCtrl.diagramaDeEstados.png?raw=true)
- Hace falta borrar el lazo de Girando1 hacia Esperando el final porque creo que no tiene  sentido existiendo one-shot. 
- No se si deberia encapsular las variables que avanzan al estado siguiente en una sola para el diagrama de estados o terminar de especificar todas las opciones.
##### *sujeto a cualquier cambio*
## -----------BORRADOR-----------
Contador de ciclos
