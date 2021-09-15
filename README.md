# Dispositivo Factor de potencia

# 1.0 Introducción

El futuro de la humanidad y del planeta dependen de la manera en la que produzcamos energía: un sistema energético fiable, asequible y descarbonizado es fundamental.
Las energías renovables son fuentes de energía limpias, inagotables y crecientemente competitivas. Se diferencian de los combustibles fósiles principalmente en su diversidad, abundancia y potencial de aprovechamiento en cualquier parte del planeta, pero sobre todo en que no producen gases de efecto invernadero, causantes del cambio climático, ni emisiones contaminantes. Además, sus costes evolucionan a la baja de forma sostenida, mientras que la tendencia general de costes de los combustibles fósiles es la opuesta.
El crecimiento de las energías renovables es imparable, como queda reflejado en las estadísticas aportadas anualmente por la Agencia Internacional de la Energía (AIE): según las previsiones de la AIE, la participación de las renovables en el suministro eléctrico global pasará del 26% en 2018 al 44% en 2040, y proporcionarán 2/3 del incremento de demanda eléctrica registrado en este período, principalmente a través de las tecnologías eólica y fotovoltaica.
De acuerdo a la AIE, la demanda mundial de electricidad aumentará un 70% hasta 2040, elevando su participación en el uso de energía final del 18% al 24% en el mismo período, espoleada principalmente por regiones emergentes (India, China, África, Oriente Medio y el Sureste asiático).
Con lo anterior y compartiendo la idea de utilizar mas las energías limpias, se implementan nuevas formas de controlar los diferentes recursos que se utilizan en el día a día en el Instituto de Energías Renovables-UNAM, se implementarán dispositivos que puedan medir la cantidad de recursos que se consumen como lo son: el agua, la energía eléctrica, humedad, intensidad luminosa, temperatura, entre otras, de un edificio del instituto, con la intención de poder medir cada variable y posteriormente observar cuanto se consume para tratar de reducirlos en gran medida, lo anterior se lleva a cabo con dispositivos electrónicos que están integrados principalmente con sensores y haciendo uso de tecnologías abiertas para los programas y envío de datos a la plataforma IOT Thingsboard para la visualización de gráficos.

### 1.1 Sobre los autores

|Nombre|Instituto/Organización|Email|
| ------------ | ------------ | ------------ |
|Juan Valle Bahena|ITZ|juanvb999@gmail.com|
|Falta |Falta|Falta|
|Guillermo Barrios del Valle|IER-UNAM|gbv@ier.unam.mx|
|Guillermo Ramírez Zúñiga|IER-UNAM|guraz@ier.unam.mx|

------------

# 2. Alcance

El dispositivo Factor de potencia tiene como alcance, en esta etapa, contar con toda la documentación necesaria  e incluso en atapa inicial de pruebas, después de ser trabajado por un grupo de personas se espera que el proyecto tenga todo lo que se necesita para que otras personas puedan entender el funcionamiento y requisitos de operación.

La audiencia a la que está destinada es:

- Por el momento a personal del IER-UNAM que se encuentra trabajando en el proyecto "Edificios demostrativos de diseño bioclimático en clima cálido subhúmedo en el Instituto de Energías Renovables UNAM".

Proyecto número 291600 del Fondo de Sustentabilidad Energética.
- Compañeros que se interesen en aportar al proyecto para mejorar o para replicarlo directamente.

------------

# 3. Conceptos y definiciones

### 3.1 Saber como

Es necesario conocer algunas cosas antes de intentar entender muchos puntos del proyecto, como por ejemplo: lectura de planos electrónicos, diseño CAD, conocimiento medio de electrónica, programación, entre otras.

### 3.2 Diseño

Deberá manejar algún software de diseño por computadora, para modificar, replicar el diseño existente e incluso conocer la sección de ensamble de piezas en el software de su preferencia.

### 3.3 Hacer

Fabricar, construir, ensamblar, imprimir, configurar, programar y compilar códigos.

### 3.4 Open source

Por su traducción al español, "fuente abierta" durante el desarrollo del proyecto se busca que todos los programas a usar, sean de fuente abierta para evitar pagos costosos de Licencia, para cada necesidad existe un software de fuente abierta.

### 3.5 Thingsboard

Es una plataforma de IOT que nos ayuda a visualizar gráficamente las variables que se están midiendo para tener referencias de lo que se está haciendo.

### 3.6 Github

Plataforma web, que sirve como "bodega" para almacenar un proyecto con sus respectivas versiones o modificaciones que pueda sufirir durante el desarrollo, al mismo tiempo ayuda a documentar y a entender la estructura de su funcionamiento.

------------

# 4.0 Especificaciones de la estructura

### 4.1 Introducción

En esta sección se encuentra la estructura general del proyecto, de forma que sea entendible y que se le pueda dar seguimiento para la lectura del mismo y entender que lleva un orden.
Esta forma de estructurar el proyecto es un formato estándar de Open Know-How, cabe mencionar que no es el ideal pero para entender de forma general un proyecto de electrónica es aceptable.
El almacenamiento en Github nos ayuda en todo momento a realizar modificaciones que creemos necesarias y sobre todo a tener control total de los cambios que va sufriendo el proyecto durante el desarrollo, si alguna no nos agrada o no es la correcta, podemos regresar sin ningún problema y dejarlo como antes.

### 4.2 Estructura

### 4.2.1 Formato

El formato de archivo para la documentación del dispositivo es Markdown por su facilidad de uso.
Algunos archivos están en formato PDF pero es necesario para una mejor visualización de los esquemas que se muestran en ese formato.

### 4.2.2 Nombre del archivo

Para los nombres de los archivos, es necesario que no se usen comas, virgulilla o tilde de la ñ, las separaciones de las palabras pueden ser usadas con guiones o sin espacios, pero con una letra mayúscula para saber donde termina e inicia otra palabra, por ejemplo: ArchivoEstructura".
Las extensiones de los archivos pueden ser:

- .json | Para los archivos que se realizaron con EasyEDA.
- .md | Para los archivos que son creados en formato de texto Markdown, M Editor, DILLINGER e incluso el archivo README de Github.
- .fzz | Para los archivos que fueron creados en el software de Fritzing, pictogramas de conexiones.
- .ESTEP | Para los archivos de diseño CAD, que pueden ser visualizados en cualquier software de diseño, es formato general.
- .STL | Para los archivos de impresión, para que el diseño de la carcasa del dispositivo pueda ser visualizado al momento de imprimirlo en 3D.
- .zip | Para los archivos de impresión de la placa o PCB, están comprimidos porque son varios archivos.
- .PDF | Para los archivos que si se guardan en otro formato, posiblemente se moverían mucho las líneas, formas, tablas, imágenes, etc. Los archivos que se encontrarán en el repositorio en este formato serán los planos para el diseño de la carcasa.

### 4.2.3 Vínculos

En algunas secciones de la documentación es necesario nombrar o hacer referencias a rutas externas, pueden ser a imágenes, páginas web entre otras, simplemente se hace uso de los links originales de la web en cuestión, copiando y posteriormente pegando en la sección correspondiente para no tener que buscar de manera externa, deberán dejar espacios entre título o texto para que no existan errores de posición en el archivo de texto final.

#### 4.2.4 Ubicación del repositorio

El repositorio de todo el proyecto se encuentra en Github, las diferentes carpetas y archivos están alojadas en un un solo repositorio, no existe una carpeta raíz, pero sí existe una dirección raíz y es la siguiente:

[**Falta redireccionarlo**]()

### 4.3 Información de la web

La página de presentación del proyecto, está en la sección de Github.

El sitio web del formato estándar para documentar es el siguiente:

[**Falta redireccionarlo**]()

### 4.4 Propiedades descriptivas

### 4.4.1 Título

##### Dispositivo de Factor de potencia
##### Medidor de.....(falta complementar)

### 4.4.2 Descripción

##### Energías renovables
##### Dispositivo pensado para...(falta complementar)

### 4.4.3 Uso previsto

##### Control de variable
###### Informa al usuario el....(falta complementar)

### 4.4.4 Palabras clave

##### Electrónica
##### Dispositivo
##### Faltan poner otras

### 4.4.5 Precauciones y recomendaciones

Son recomendaciones para operar el dispositivo(falta complementar)

### 4.5.6 Contacto primario

**Inv. A tiempo completo:** Dr. Guillermo Barrios del Valle

**Email:** gbv@ier.unam.mx



**Posdoc.:** Dr. Guillermo Ramírez Zúñiga

**Email:** guraz@ier.unam.mx

### 4.5.7 Colaboradores

**Nombre: Juan Valle Bahena** 

**Instituto: Instituto Tecnológico de Zacatepec (ITZ)**

**Email: juanvb999@gmail.com**



**Nombre:**

**Instituto:**

**Email:**



**Nombre:**

**Instituto:**

**Email:**

### 4.5.7 Imagen

Representación gráfica del dispositivo Factor de potencia (**Falta**)


### 4.5.8 Etapa de desarrollo

La etapa en la que se encuentra el desarrollo del dispositivo Factor de potencia, es la de documentación y primeras pruebas.

**El porcentaje de avance en las actividades corresponde a un valor máximo de 10% para cada una, para hacer un total de 100%.**

#### Actividades y tiempos para construir el THIS

|**Actividad**|**Tiempo estimado de ejecución**|**Referenciación**|
| :------------: | :------------: | :------------: |
|**1. Revisión de documentos existentes necesarios para operarlo de acuerdo a la CHECK-LIST**|2 h|[**°Documentación**](https://github.com/Dispositivos-Edificio-Bioclimatico/FactorDePotencia/tree/master/Documentacion) [**°Check-List**](https://github.com/Dispositivos-Edificio-Bioclimatico/FactorDePotencia/blob/master/Materiales/Check-ListFP.md)|
|   |   |   |
|**2. Verificar si cuenta con los materiales requeridos**|1/2 h|[**Materiales**](https://github.com/Dispositivos-Edificio-Bioclimatico/FactorDePotencia/blob/master/Materiales/Material.txt)|
|   |   |   |
|**3. Imprimir la carcasa en 3D (2 PARTES)**|32 h|[**Archivos STL**](https://github.com/Dispositivos-Edificio-Bioclimatico/FactorDePotencia/tree/master/CAD)|
|   |   |   |
|**4. Leer los reportes de residencia para entender lo que se hará**|1 h|[**Documentación**](https://github.com/Dispositivos-Edificio-Bioclimatico/FactorDePotencia/tree/master/Documentacion)|
|   |   |   |
|**5. Entender los diagramas de conexión**|1/2 h|[**Diagramas**](https://github.com/Dispositivos-Edificio-Bioclimatico/FactorDePotencia/tree/master/Diagramas)|
|   |   |   |
|**6. Descargar el código y cargar en el IDE de Arduino**|1/2 h|[**Código de FP**](https://github.com/Dispositivos-Edificio-Bioclimatico/FactorDePotencia/tree/master/SRC/codigo_sensorcorriente)|
|   |   |   |
|**Ejecutar el código como primera prueba y asegurarse que funciona**|   |   |
|   |   |   |
|**7. Verificar si envía datos de telemetría correctamente a Thingsboard**|1/2 h|[**JUAN_VALLE_ENERGÍA**](http://iot.ier.unam.mx:8080/dashboards/a7021b60-13df-11eb-9c3f-d1ead9980bc3)  [**°Dashboard**](http://iot.ier.unam.mx:8080/devices)|
|   |   |   |
|**8. Montar el dispositivo en el lugar requerido**|1h|   |
|   |   |   |
|**9. Dejarlo operando durante 48 horas como prueba "Burn it"**|48h|   |
|   |   |   |
|**Tiempo total apróximado:**|**3 días**|Dependerá de la habilidad y conocimientos que se tengan, puede llevar menos tiempo o más|

------------

#### CHECK-LIST de lo que debe tener el dispositivo
- [x] Lista de costos
- [x] SRC completos
- [x] Pictograma de conexión
- [x] Esquemático de conexión
- [x] Archivos de diseño PCB
- [x] Archivos gerber para el maquinado del PCB
- [x] Lista de materiales
- [x] Planos CAD
- [x] Archivos de diseño CAD
- [x] Archivos STL para impresión 3D
- [x] Manual de operación
- [ ] Manual de ensamble
- [x] Fichas técnicas o datasheet de los módulos, sensores y componentes usados
- [x] Documento de errores, soluciones y recomendaciones

### 4.5.9 Fue hecho físicamente

El dispositivo aún no se ha hecho de forma práctica en su totalidad, es decir, no se ha llevado a la práctica para comprobar el funcionamiento del dispostivo completo con todos sus componentes.

### 4.5.10 Se ha comprobado la documentación

La réplica del dispositivo usando la estructura aquí mostrada y siguiendo la documentación no se ha realizado, aún está en revisión de estructura de documentación y de archivos factibles para el desarrollo eficiente.

### 4.5.11 Estándares usados

El estándar de documentación completo, no se ha seguido, pero si se ha usado el estándar para esta documentación de Open Know-How, algunos puntos se han omitido porque al no ser la estructura para documentar proyectos electrónicos, existen puntos que salen sobrando o que definitivamente no aplican para este tipo de proyectos.
El link del estándar usado es el siguiente:

[EstandarOpenKnowHow](https://app.standardsrepo.com/MakerNetAlliance/OpenKnowHow/src/branch/master/1#a40dfa47-8bff-4e28-9338-3f808ddfe6ae)

### 4.6 Documentación

### 4.6.1 Punto de entrada de la documentación:


### Carpeta [CAD](https://github.com/Dispositivos-Edificio-Bioclimatico/FactorDePotencia/tree/master/CAD)

En la carpeta CAD se deben poner los archivos .STEP del diseño de la carcasa o de alguna parte física.

En la misma carpeta se deben poner planos en formato PDF y los archivos .STL para visualización.

### Carpeta [Diagramas](https://github.com/Dispositivos-Edificio-Bioclimatico/FactorDePotencia/tree/master/Diagramas)

En la carpeta de Diagramas se debe poner, el esquemático, el diseño de PCB, representaciones gráficas de conexión (pictogramas) y archivo gerber con lo necesario para maquinar el pcb.

### Carpeta [Imagenes](https://github.com/Dispositivos-Edificio-Bioclimatico/FactorDePotencia/tree/master/Imagenes)

En esta carpeta deben ir todas las imagenes que se usaron en los archivos de los manuales y otras imagenes necesarias para el complemento del dispositivo.

### Carpeta [Manuales](https://github.com/Dispositivos-Edificio-Bioclimatico/FactorDePotencia/tree/master/Manuales)

En esta carpeta se debe contener lo siguiente:
1. El manual de operación, para consultarlo antes de iniciar con la replica del dispositivo.
2. El manual de ensamble, de manera gráfica (ilustrativa), se describe de forma general como realizar el ensamble de los componentes del dispositivo.
3. Un manual de errores y soluciones que debe tener algunas sugerencias de operación para operar el dispositivo.

### Carpeta [Materiales](https://github.com/Dispositivos-Edificio-Bioclimatico/FactorDePotencia/tree/master/Materiales)

En la carpeta "Materiales" se deben poner los archivos con extensión md y otros en PDF.
1. En el archivo Lista_de_materiales_Ejem se encuentran los materiales que ne necesitan para el pcb. (es de ejemplo, debe adaptarse)
2. En el archivo ListaCostosEjem se encuentran los costos unitarios y total de los componentes. (es de ejemplo, debe adaptarse)
3. Los archivos en PDF son hojas de datos de algunos componentes que se usan en el dipositivo. (deben ir de todos los compenentes usados)

### Carpeta [SRC](https://github.com/Dispositivos-Edificio-Bioclimatico/FactorDePotencia/tree/master/SRC)

En esta carpeta deberán ponerse todos los códigos necesarios para operar el dispositivo y debe ponerse un archivo de texto donde explique, lo que hace cada código en la carpeta. (hay uno básico de ejemplo, deberá adaptarse)

### Thingsboard

Dispositivo:
[**JUAN_VALLE_ENERGÍA**](http://iot.ier.unam.mx:8080/devices)

Dashboard:
[**JUAN_VALLE_ENERGÍA**](http://iot.ier.unam.mx:8080/dashboards/a7021b60-13df-11eb-9c3f-d1ead9980bc3)

**Las credenciales para acceder a Thinsgboard deberán ser solicitadas a los doctores**
------------

# 5.0 Bibliografía

[1] **Open Know-How**
https://app.standardsrepo.com/MakerNetAlliance/OpenKnowHow/src/branch/master/1#a40dfa47-8bff-4e28-9338-3f808ddfe6ae

[2] **Github**
https://github.com/

[3] **DILLINGER**
https://dillinger.io/

[4] **M Editor.md**
https://pandao.github.io/editor.md/en.html

