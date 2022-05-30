# Taller-01-paralela

Un país colectivista, impone una prueba de acceso universitaria (PAU). Esta es una sencilla prueba de
selección múltiple de 12 preguntas. Los resultados ayudarán a los planificadores centrales a
determinar cuántos cupos se abrirán en los centros de estudios estatales para el siguiente año. Dado
que año a año, la cantidad de cupos es muy limitada, los estudiantes lo vuelven a intentar y para este
proceso, se esperan más de 17 millones de pruebas a corregir.
Por este motivo, un comité del Estado le pide realizar un programa, que permita procesar esta prueba
de forma desatendida y en el menor tiempo posible.

## Como ejecutar 🚀

Las siguientes instrucciones te permitiran obtener una copia del programa, y asi poder ejecutarlo.

### Pre-requisitos 📋
```
 - Compilador de C/C++
 - Make (Builder)
 - Archivo con formato necesario
```
### Formato archivo 📋

Es necesario contar con un archivo llamado "pruebas.csv", el cual tiene que contener su informacion distribuida de la siguiente manera en distintas columnas:

  1. Columna debe tener el identificador encriptado del estudiante.
  2. Columna debe tener respuesta/omicion de la pregunta 01 del estudiante.
  3. Columna debe tener respuesta/omicion de la pregunta 02 del estudiante.
  4. Columna debe tener respuesta/omicion de la pregunta 03 del estudiante.
  5. Columna debe tener respuesta/omicion de la pregunta 04 del estudiante.
  6. Columna debe tener respuesta/omicion de la pregunta 05 del estudiante.
  7. Columna debe tener respuesta/omicion de la pregunta 06 del estudiante.
  8. Columna debe tener respuesta/omicion de la pregunta 07 del estudiante.
  9. Columna debe tener respuesta/omicion de la pregunta 08 del estudiante.
  10. Columna debe tener respuesta/omicion de la pregunta 09 del estudiante.
  11. Columna debe tener respuesta/omicion de la pregunta 10 del estudiante.
  12. Columna debe tener respuesta/omicion de la pregunta 11 del estudiante.
  13. Columna debe tener respuesta/omicion de la pregunta 12 del estudiante.

Tambien sus datos deben encontrarse separados con  ( ; ) y deben estar separados por punto y coma, y encerrados por doble comilla ("dato1";"dato2").

### Instalación 🔧

1. Clonar el proyecto a tu PC

_Para esto puedes descargarlo directo desde GitHub o clonarlo desde un terminal._
```
git clone = https://github.com/andres-segarra/Taller-01-paralela.git

2. Construccion del proyecto

El archivo pruebas.csv es muy pesado, como para subirlo.


## Ejecucion del proyecto ⚙️

Usar la terminal en la carpeta donde se encuentra main.cpp,  y escribir: 
make
time ./main.o
```
Una vez ya ejecutado make, no sera necesario escribirlo otra vez, ya que el ejecutable ya existira, y solo escriba: time ./main.o
 
## Construido con 🛠️

* C++ - Lenguaje de programacion utilizado
* Make - Utilizado para construir la aplicacion de C++ por consola

## Herramientas 🛠️

* VisualStudioCOde1.67.2
* [codeblocks-20.03-setup.exe] - Usado para crear el codigo
* Lubuntu 22.04

## Problemas presentados 🛠️

El trabajo presentado solo se pudo trabajar la parte secuencial y paralela (OpenMP) y correrlo con make.

La paralelizacion del uso de OMP, no quedo bien optimizado, ya que entramos en la encrucijada, de si la salida de archivos era ordenado,
se demoraba un poco mas que el secuencuial, pero si lo optimizabamos, quedando un 30-40% aprox de menor tiempo, la salida de datos quedaba
y traspapelado y desordenado.

El arhivo entregado, se demora aproximadamente lo mismo que el secuencial que serian aproximadamente 90 seg. a 100 seg. aprox., se corroboro
de que se trabajasen los hilos solicitados, dando como resultado con los datos correctos, sin quedar desordenados y traspapelados.


## Autores ✒️

-Rodrigo Mora Palta.

-Luis Rivas Sanchez.

-Andres Segarra Pavez.
