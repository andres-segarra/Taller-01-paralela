#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <iomanip>
#include <omp.h>

// using
using namespace std;

int main()
{
    // variable con las respuestas correctas
    string correctas[13] = {"-", "A", "E", "C", "B", "B", "D", "A", "B", "E", "C", "B", "D"}; // Arreglo con las respuestas correctas
    ifstream lector;    // La variable lector crea un espacio donde se cargara la información del documento a leer
    string linea;       // Variable multiuso para la lectura de filas
    // Aca se abre el archivo que se va a leer
    lector.open("pruebas.csv", ios::in);
    if (lector.fail())
    { // Por si no se pudo abrir el archivo
        cout << "ERROR AL LEER EL ARCHIVO" << endl;
        exit(1);
    }
    char delimitador = ';'; // Caracter que delimita las distintas columnas de las filas
    getline(lector, linea); // Con esta acción se pasará directamente a la fila de estudiantes
    ofstream Resultado;     // Aca se crea el archivo csv
    if (Resultado.fail())
    { // No se pudo crear el archivo
        cout << "ERROR AL CREAR EL ARCHIVO DE SALIDA" << endl;
        exit(1);
    }
    // Se reescribe el archivo Resultados.csv, y procede en llenar lo que seria la primera fila del archivo = El encabezado
    Resultado.open("Resultados.csv", ios::out);
    Resultado << '"' << "Token Estudiante" << '"' << ';' << '"' << "Correctas" << '"' << ';' << '"' << "Incorrectas" << '"' << ';' << '"' << "Omitidas" << '"' << ';' << '"' << "Puntaje" << '"' << ';' << '"' << "Nota" << '"' << "\n";
    getline(lector, linea);
    for (int m = 0; m >= 0; m++)
    {
        // Codigo base
        string recibidor[13]; // Arreglo de 13 espacios para recibir las filas del archivo
        int rcorrectas = 0;   // Contador de preguntas correctas
        int rmalas = 0;       // Contador de preguntas incorrectas
        int romitidas = 0;    // Contador de preguntas omitidas
        float notaaux = 1;    // Nota base
        stringstream stream(linea);
        string nombre, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12; // Variables vacias donde guardaremos información de la fila
        getline(lector, linea);
        getline(stream, nombre, delimitador);//Ahora se guardaran los datos de la fila en cada variable deteniendose en cuando encuentren el delimitador previamente detallado
        getline(stream, p1, delimitador);
        getline(stream, p2, delimitador);
        getline(stream, p3, delimitador);
        getline(stream, p4, delimitador);
        getline(stream, p5, delimitador);
        getline(stream, p6, delimitador);
        getline(stream, p7, delimitador);
        getline(stream, p8, delimitador);
        getline(stream, p9, delimitador);
        getline(stream, p10, delimitador);
        getline(stream, p11, delimitador);
        getline(stream, p12, delimitador);
        recibidor[0] = nombre;//Cada dato guardado en las variables ahora formará parte del arreglo recibidor para analizarlo
        recibidor[1] = p1;
        recibidor[2] = p2;
        recibidor[3] = p3;
        recibidor[4] = p4;
        recibidor[5] = p5;
        recibidor[6] = p6;
        recibidor[7] = p7;
        recibidor[8] = p8;
        recibidor[9] = p9;
        recibidor[10] = p10;
        recibidor[11] = p11;
        recibidor[12] = p12;
#pragma omp parallel num_threads(3) // Definimos la cantidad de hilos a trabajar, en este caso 3
#pragma omp for
        for (int i = 1; i < 13; i++)
        {
            // Se compara la entrada con que si la pregunta es correcta
#pragma omp critical
            if (recibidor[i] == ('"' + correctas[i] + '"')) // Se compara el dato de entrada con las respuestas correctas
            {
                notaaux += 0.5;
                rcorrectas++;
            }
            else
            {
                if (recibidor[i] == '"' + correctas[0] + '"') // Se compara con el valor de la posicion correctas[0] que es "-"
                {
                    romitidas++;
                }
                else
                { // Sino es una pregunta mal respondida
                    notaaux -= 0.12;
                    rmalas++;
                }
            }
        }

        if (notaaux < 1)
        { // Si es nota menor a 1, se deja como esta nota como minima
            notaaux = 1.0;
        }

        if (lector.eof())  // Se corrobora si el archivo esta vacio
        {
            m = -10;
        }
        else
        {   //Aca se meten los valores en el archivo, llamado Resultado
            Resultado << recibidor[0] << ';' << '"' << rcorrectas << '"' << ';' << '"' << rmalas << '"' << ';' << '"' << romitidas << '"' << ';' << '"' << (rcorrectas * 0.5 - rmalas * 0.12) << '"' << ';' << '"' << fixed << setprecision(1) << notaaux << '"' << "\n"; // se llena el archivo con lo datos
            rcorrectas = 0;       // Se reinician los valores de las variables                                                                                                                                                                                                                                        // reestablecer valores de variables
            rmalas = 0;
            romitidas = 0;
            notaaux = 1.0;
        }
    } 

    lector.close(); // Se cierran los archivos
    Resultado.close();

    cout << "----------------" << endl;
    cout << "=== Integrantes ===" << endl;
    cout << "Luis Rivas Sanchez" << endl;
    cout << "Rodrigo Mora Palta" << endl;
    cout << "Andres Segarra Pavez" << endl;
    cout << "----------------" << endl;

    return 0;
}
