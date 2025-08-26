# StepCtrl (prueba)
Sistema de manejo y control de motores paso a paso.
## Microcontrolador
el pretendido es un stm32 blue pill, no tengo experiencia usandolo. Lo escuche en clase y me parecio una buena idea implementarlo por las prestaciones de los timers y que son usados para tareas similares.
## Motor y driver 
Cualquiera, este modulo carece de fuente y manejo de corriente para los motores, solo envia la secuencia de steps segun seteos y entradas aisladas.
## Cargar Valores
Los campos a modificar son:
- Velocidad
- Dirección
- Modo
- Cantidad de movimientos
- Cantidad de pulsos
- Entradas:Trigger y SignalContinue
- TimeOut
- Salida
### Seteo de campos :
De momento se van a ingresar modificando un archivo de texto antes de la compilación. Esto es para tener una buena base sin complicar el desarrollo, lo intención es en un futuro poner display y armar la ui.
## Funcionamiento :
### Modo One-Shot:  El modo simple para disparo del motor. Solo se tiene en cuenta el Trigger y se puede configurar si dar fin al movimiento por tiempo o trigger/señal externa.
### Modo Continuo : Este modo es mas completo, se pueden configurar de 2 a 3 pasos o instancias con parámetros independientes sincronizadas por trigger,timer, señal externa o cantidad de pulsos individual.
*Aclaracion : La instancia intermedia, puede ser usada para un tiempo muerto donde se requiera no accionar el motor (velocidad=0).* 
## Diagrama de estados :
![Image_Alt](https://github.com/lucashorminoguez/StepCtrl/blob/main/StepCtrl.diagramaDeEstados.png?raw=true)
- Hace falta borrar el lazo de Girando1 hacia Esperando el final porque creo que no tiene sentido existiendo one-shot. 
- No se si deberia encapsular las variables que avanzan al estado siguiente en una sola para el diagrama de estados o terminar de especificar todas las opciones.
##### *sujeto a cualquier cambio*
## -----------BORRADOR-----------
Contador de ciclos
