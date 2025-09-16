# StepCtrl
Sistema de manejo y control de motores paso a paso.
## Descripción:
Este sistema permite el manejo secuencial de motores paso a paso o steppers cambiando valores según el proposito de la operación. 
El codigo provee manejo de: 
- Velocidad (rampa de aceleracion ajustada para el arranque, frenado y alteraciones).
  Sincronizada o en tiempo real mediante entrada analogica.
- Dirección/sentido de giro.
- Señales de disparo y timeouts por cada movimiento.
- Secuencias de hasta 3 pasos u operaciones.
- 2 Modos de funcionamiento, para tareas simples o complejas.
---
## Modos de Funcionamiento:
- ### Modo One-Shot:  
El modo simple para disparo del motor. Solo se tiene en cuenta una señal de disparo única y se puede configurar si dar fin al movimiento por tiempo o Trigger/señal externa.
- ### Modo Secuencia : 
Este modo es mas completo, se pueden configurar hasta 3 pasos o secuencias de movimiento con parámetros independientes sincronizadas por Trigger/señal externa o Timeout.
Al finalizar un ciclo completo se puede leer un valor de habilitación para el ciclo siguiente o continuar sin validar.
Cada ciclo se registra aumentando un contador que sirve para activar una salida definida en placa.
Todas las funciones pueden desahabilitarse poniendo valores en 0 segun se requiera.

*Aclaracion : La instancia intermedia, puede ser usada para un tiempo muerto donde se requiera no accionar el motor (velocidad=0).* 

---
## HARDWARE:
### Microcontrolador:
El pretendido es un STM32 STM32F103C8T6, pero la idea es que pueda llevarse a cabo en cualquier micro modificando el archivo "hal_ctrl.h".
### Motor y driver:
Cualquiera, este modulo carece de fuente y manejo de corriente para los motores, solo envia la secuencia de steps segun seteos y entradas.
### Circuito propuesto:
---

## Cargar Valores usando el archivo CTRL.h :
Dentro del archivo nos encontramos von varios `#define` a completar segun el motor y driver que estemos utilizando, asi como el resto de parametros para la operación deseada :

### Motor y driver

- `PASOS_POR_VUELTA` : Cantidad de pasos que da el motor en una vuelta completa. 

- `MICROSTEPPING`    : Configuración del driver para microstepping.  
  Ej: 1 = full step, 2 = half step, 16, 32, etc.

> Internamente, la frecuencia de pulsos se calcula como:  
> 
> Frecuencia [Hz] = (CTRL_VEL/ 60) * (PASOS_POR_VUELTA * MICROSTEPPING)
> 
> Esto permite que el usuario trabaje en RPM, simplificando la configuración.

---
### Velocidad:
- `CTRL_VEL_0` : Velocidad [rpm] para el Trigger del oneshot
- `CTRL_VEL_1` : Velocidad [rpm] para el Trigger del paso 1  
- `CTRL_VEL_2` : Velocidad [rpm] para el Trigger del paso 2
- `CTRL_VEL_3` : Velocidad [rpm] para el Trigger del paso 3
---
### Dirección:
- `CTRL_DIREC_0` : Sentido de giro para el Trigger del oneshot
- `CTRL_DIREC_1` : Sentido de giro para el Trigger del paso 1
- `CTRL_DIREC_2` : Sentido de giro para el Trigger del paso 2
- `CTRL_DIREC_3` : Sentido de giro para el Trigger del paso 3
---
### Trigger:
Son las señales de disparo de los distintos eventos, el modulo esta pensado para 3 entradas distintas + boton.
- `CTRL_TRIGGER_ONESHOT`    : Entrada para el Trigger del oneshot
- `CTRL_TRIGGER_PASO1`      : Entrada para el Trigger del paso 1
- `CTRL_TRIGGER_PASO2`      : Entrada para el Trigger del paso 2
- `CTRL_TRIGGER_PASO3`      : Entrada para el Trigger del paso 3
- `CTRL_TRIGGER_FINAL`      : Entrada para el Trigger del final
- `CTRL_HABILITACION_CICLO` : Entrada para el Trigger de habilitar ciclo
---
### Lógica de señales:
- `CTRL_STATE_TRIGGER_ONESHOT`    :Activo bajo/alto
- `CTRL_STATE_TRIGGER1`           :Activo bajo/alto  
- `CTRL_STATE_TRIGGER2`           :Activo bajo/alto
- `CTRL_STATE_TRIGGER3`           :Activo bajo/alto
- `CTRL_STATE_TRIGGER_FINAL`      :Activo bajo/alto
- `CTRL_STATE_HABILITACION_CICLO` :Activo bajo/alto
### Modo:
- `CTRL_MODO`            1       : Modo Secuencia o Modo ONE-SHOT
- `CTRL_CANT_PASOS`      3       : Hasta 3 Pasos/Movimientos independientes en Modo Secuencia
---
### Timeouts:
- `CTRL_TIMEOUT_0`       60      : Timeout [Segundos] para el Trigger del oneshot
- `CTRL_TIMEOUT_1`       10      : Timeout [Segundos] para el Trigger del paso 1
- `CTRL_TIMEOUT_2`       10      : Timeout [Segundos] para el Trigger del paso 2
- `CTRL_TIMEOUT_FINAL`   10      : Timeout [Segundos] para el Trigger del final

## Diagrama de estados :
![Image_Alt](https://github.com/lucashorminoguez/StepCtrl/blob/main/StepCtrl.diagramaDeEstados.png?raw=true)
##### *sujeto a cualquier cambio*