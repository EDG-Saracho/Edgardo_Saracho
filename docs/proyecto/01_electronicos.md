 

### **Introducción**

El desafío principal en el desarrollo de mi prototipo fue la automatización del proceso de almacenamiento y distribución de agua. En versiones previas, este proceso se realizaba de forma mecánica. Sin embargo, en este proyecto, la incorporación de componentes electrónicos permitirá automatizar el almacenamiento de agua y su distribución, con posibles aplicaciones como el llenado de cisternas o un sistema de riego por goteo, según las características de la vivienda.

### **Esquema de Funcionamiento**

Durante la etapa de investigación, analicé diversas estrategias para llevar a cabo esta automatización y determiné la necesidad de una bomba de agua que fuera económica, compacta y lo suficientemente potente para garantizar la distribución eficiente del agua. Además, identifiqué la importancia de un sistema de control para el encendido y apagado automático, para lo cual un sensor de flotador resultó ser una opción viable. Realicé consultas a través de ChatGPT para obtener información sobre cómo construir el circuito, aunque estas consultas no resultaron suficientes para aclarar completamente el proceso.

### **Conexión y Diseño del Circuito**

En una sesión de consulta con Eduardo Chamorro, arquitecto e investigador que brinda tutorías, me ayudó a definir el esquema de conexión y determinar los componentes necesarios. Eduardo proporcionó un esquema inicial que sirvió de base para el desarrollo del proyecto.

![Diseño del circuito](../images/PI_IMG/electronicos/diseño_circuito.jpg)

Procedí a adquirir los materiales faltantes y enfrenté algunos inconvenientes, en particular con la obtención del relé mostrado en el esquema. Utilicé un relé de 5 pines incluido en mi kit de Arduino, lo que generó dificultades al integrarlo en el esquema propuesto por Eduardo. Gracias a la colaboración de Santi Fuentemilla, con quien intercambié tutoriales e información, logramos investigar alternativas; sin embargo, persistía la incertidumbre respecto al correcto funcionamiento del relé en este contexto.

![Relé alternativo](../images/PI_IMG/electronicos/rele_alternativo.jpg)


### **Prueba de Viabilidad de las Conexiones**

Antes de usar la bomba de agua nueva, decidí realizar una prueba de viabilidad utilizando una lámpara conectada a la red eléctrica. Este ensayo utiliza el mismo esquema de conexión y permite verificar la funcionalidad del circuito sin riesgo de dañar la bomba. Esta medida de precaución garantiza que las conexiones estén bien configuradas antes de realizar el prototipo.

![Prueba con luz](../images/PI_IMG/electronicos/03_prueba.webp)

----------

### **Ensayo con Lámpara de Luz**

Finalmente, tras varios intentos, logré conseguir en el mercado local un relé de 6 pines que me permitió conectarlo de acuerdo con el esquema original. Realicé una prueba utilizando una lámpara para verificar el funcionamiento del circuito.

![rele 6 pines](<../images/PI_IMG/electronicos/relé 6 pines.jpg>)

Aspectos pendientes incluyen definir cómo se alimentará la placa una vez completado el prototipo y, posiblemente, agregar en el código un retraso (delay) en el apagado para evitar un corte abrupto de energía.

![Ensayo luz](../images/PI_IMG/electronicos/ensayo_luz.gif)

----------