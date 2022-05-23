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

Tambien sus datos deben encontrarse separados con  ( ; ) y deben estar separados por punto y coma ("dato1";"dato2").
### Instalación 🔧

1. Clonar el proyecto a tu PC

_Para esto puedes descargarlo directo desde GitHub o clonarlo desde un terminal._

```
git clone = https://github.com/andres-segarra/Taller-01-paralela.git

2. Construccion del proyecto

El archivo pruebas.csv es muy pesado, como para subirlo, y suele tener problemas, ya que el tamaña era muy grande, asi que utilizamos un arhivo "testeo.csv" de un tamaño mas aceptable, donde en la linea 10 del codigo "  #define NOMBRE_ARCHIVO "pruebas.csv"   ",  se cambia " pruebas.csv" por "testeo.csv" .  
Se tiene el archivo make, pero no se pudo usar porque habia problemas al hacer uso de openmp, y no se pudo testear la paralelizacion 
## Ejecucion del proyecto ⚙️
usar en la terminal en la carpeta donde se encuentra main.cpp
 y escribir: 
```
g++ main.cpp -o main.out
./main.out
```

## Construido con 🛠️

* C++ - Lenguaje de programacion utilizado
* Make - Utilizado para compilar la aplicacion de C++
* [codeblocks-20.03-setup.exe] - Usado para crear el codigo

## Autores ✒️
-Luis Rivas Sanchez
-Andres Segarra Pavez
-Rodrigo Mora Palta
