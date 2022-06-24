# Dispositivo Factor de potencia

El dispositivo FP-10 es un monitor de energía electrica desarrollado para medir parametros que permitan llevar un seguimiento del consumo energetico de un lugar, puesto que los datos obtenidos son enviados a una plataforma de internet para su visualizacion del tiempo de medición transcurrido. El dispositivo mide las siguientes variables: voltaje, corriente y factor de potencia. El monitor esta diseñado  para ser usado en una instalación trifásica y capaz de medir hasta 10 lineas.

A continuación se muestra el esquema general del dispositivo y una descripcción breve de los parametros que mide:

1. Corriente
2. Voltaje
3. Factor de potencia

![](https://github.com/Dispositivos-Edificio-Bioclimatico/DFP-10/blob/master/Imagenes/Esquema_general.png?raw=true)

[Diagrama electrico](https://github.com/Dispositivos-Edificio-Bioclimatico/DFP-10/blob/master/Diagramas/circuito_acondicionamiento.png?raw=true)

**Corriente**

Sensor propuesto: SCT-013-030


El SCT-013-030 es un sensor de corriente no invasivo que permite medir la intensidad que atraviesa un conductor sin necesidad de cortar o modificar el conductor. La medición se realiza por inducción electromagnética y puede soportar hasta 30A.


**Voltaje**

Sensor propuesto: ZMPT101B


Es un módulo utilizado para medir la tensión de fase de corriente alterna. El sensor de voltaje AC está diseñado a partir de un transformador, por lo cual única y exclusivamente se puede utilizar para medir el voltaje de Corriente Alterna. El sensor incluye un circuito de amplificador operacional de precisión, señal para muestreo adecuado y función de compensación.
Puede medir hasta 250 V de AC de acuerdo con la salida analógica, la cual es ajustable.


**Factor de potencia**

Para medir el factor de potencia con un microcontrolador, se utilizan amplificadores operacionales para detectar el paso por cero de las señales de voltaje y corriente y para determinar el cambio de fase entre la fase de corriente y el voltaje. La medida del desfase se realiza únicamente para la fundamental entre corriente y tensión. Los amplificadores operacionales convierten señales de ondas sinusoidales con diferentes amplitudes provenientes de equipos de medición (pueden ser resistivos, divisores resistivos o transformadores de corriente y transformadores de tensión) en ondas rectangulares con una amplitud de aproximadamente 4 V, que luego se conectan a las entradas de la puerta XOR TTL. 

La salida de la puerta lógica XOR será 1 solo cuando las entradas tengan señales diferentes para cargas reactivas y la salida de la puerta lógica XOR será 0 cuando la carga sea resistiva. Entonces, cuando las fases de voltaje y corriente comienzan y terminan al mismo tiempo, la salida de la puerta lógica XOR será 0, y cuando la carga es inductiva o capacitiva, la salida de la puerta lógica XOR es 1, porque hay una diferencia de fase entre el voltaje y la corriente.

[Diagrama electrico](https://github.com/Dispositivos-Edificio-Bioclimatico/DFP-10/blob/master/Diagramas/Circuito%20factor%20de%20potencia.png?raw=true)

La lista de la electronica y materiales del dispositivo se encuentra en el archivo  [materiales](https://github.com/Dispositivos-Edificio-Bioclimatico/DFP-10/blob/master/Materiales/Lista_materiales_fp10.xlsx) o en [lista_drive](https://docs.google.com/spreadsheets/d/1BcxM7iUYsvm2OvhtAZ04L2_tH826wTiQOnGWFX_L0z4/edit)

## Elementos del repositorio
- [ ] Lista de costos
- [ ] src/ completos
- [ ] Pictograma de conexión
- [ ] Esquemático de conexión
- [ ] Archivos de diseño PCB
- [ ] Archivos gerber para el maquinado del PCB
- [x] Lista de materiales
- [ ] Planos CAD
- [ ] Archivos de diseño CAD
- [ ] Archivos STL para impresión 3D
- [ ] Manual de operación
- [ ] Manual de ensamble
- [ ] Fichas técnicas o datasheet de los módulos, sensores y componentes usados
- [ ] Documento de errores, soluciones y recomendaciones



### 1.1 Sobre los autores

|Nombre|Instituto/Organización|Email|
| ------------ | ------------ | ------------ |
|Juan Valle Bahena|ITZ|juanvb999@gmail.com|
|Guillermo Barrios del Valle|IER-UNAM|gbv@ier.unam.mx|
|Guillermo Ramírez Zúñiga|IER-UNAM|guraz@ier.unam.mx|
|Giovanni Velazquez Avilez ||velazquezgio96@gmail.com|

------------

# 2. Alcance

El dispositivo Factor de potencia tiene como alcance, en esta etapa, contar con toda la documentación necesaria  e incluso en atapa inicial de pruebas, después de ser trabajado por un grupo de personas se espera que el proyecto tenga todo lo que se necesita para que otras personas puedan entender el funcionamiento y requisitos de operación.

La audiencia a la que está destinada es:

- Por el momento a personal del IER-UNAM que se encuentra trabajando en el proyecto "Edificios demostrativos de diseño bioclimático en clima cálido subhúmedo en el Instituto de Energías Renovables UNAM".

Proyecto número 291600 del Fondo de Sustentabilidad Energética.
- Compañeros que se interesen en aportar al proyecto para mejorar o para replicarlo directamente.

------------


### Thingsboard

Dispositivo:
[**JUAN_VALLE_ENERGÍA**](http://iot.ier.unam.mx:8080/devices)

Dashboard:
[**JUAN_VALLE_ENERGÍA**](http://iot.ier.unam.mx:8080/dashboards/a7021b60-13df-11eb-9c3f-d1ead9980bc3)

**Las credenciales para acceder a Thinsgboard deberán ser solicitadas a los doctores**
------------

## PENDIENTES
1.- Comprar el sensor de corriente Hall Split core HSTS016L y hacer pruebas para verificar que el Factor de Potencia (FP) sea correcto.

2.- Poner una carcasa al dispositivo como proteccion para el sistema.

3.- Instalar el dispositivo en un edificio para probar la medición de las 10 lineas.

## RECOMENDACIONES
1.- Si se replica el sistema:

      * Montar el circuito en una placa de pruebas antes de montar en PCB para verificar que todos los componentes esten bien.
      
      * Será de ayuda usar un osciloscopio, para verificar que los circuitos integrados LM324N Y CD4030BE esten procesando la señal correctamente.
      
2.- **IMPORTANTE** - **Extremar precauciones a la hora de hacer pruebas, ya que se trabaja con un voltaje que puede poner en riesgo la salud o incluso la vida**


