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
    string correctas[13] = {"-", "A", "E", "C", "B", "B", "D", "A", "B", "E", "C", "B", "D"};
    ifstream lector;
    string linea;
    // aca se abre el archivo que se va a leer
    lector.open("pruebas.csv", ios::in);
    if (lector.fail())
    { // por si no se pudo abrir el archivo
        cout << "ERROR AL LEER EL ARCHIVO" << endl;
        exit(1);
    }
    char delimitador = ';';
    getline(lector, linea);
    ofstream Resultado; // aca se crea el archivo csv
    if (Resultado.fail())
    { // no se pudo crear el archivo
        cout << "ERROR AL CREAR EL ARCHIVO DE SALIDA" << endl;
        exit(1);
    }
    // se crea/reescribe el archivo resultados.csv, y procede en llenar lo que seria la primera fila del archivo
    Resultado.open("Resultados.csv", ios::out);
    Resultado << '"' << "Token Estudiante" << '"' << ';' << '"' << "Correctas" << '"' << ';' << '"' << "Incorrectas" << '"' << ';' << '"' << "Omitidas" << '"' << ';' << '"' << "Puntaje" << '"' << ';' << '"' << "Nota" << '"' << "\n";

    for (int m = 0; m >= 0; m++)
    {
        // codigo
        string recibidor[13];
        int rcorrectas = 0;
        int rmalas = 0;
        int romitidas = 0;
        float notaaux = 1;
        stringstream stream(linea);
        string nombre, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12;
        getline(lector, linea);
        getline(stream, nombre, delimitador);
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
        recibidor[0] = nombre;
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
#pragma omp parallel num_threads(3)//definimos la cantidad de hilos a trabajar, en este caso 3
#pragma omp for
        for (int i = 1; i < 13; i++)
        {
            // se compara la entrada con que si la pregunta es correcta
#pragma omp critical
            if (recibidor[i] == ('"' + correctas[i] + '"'))
            {
                notaaux += 0.5;
                rcorrectas++;
            }
            else
            {
                if (recibidor[i] == '"' + correctas[0] + '"')
                {
                    romitidas++;
                }
                else
                { // sino es una pregunta mal respondida
                    notaaux -= 0.12;
                    rmalas++;
                }
            }
        }

        if (notaaux < 1)
        { // si es nota menor a 1, se deja como esta nota como minima
            notaaux = 1.0;
        }

        if (lector.eof())
        {
            m = -10;
        }
        else
        {
            Resultado << recibidor[0] << ';' << '"' << rcorrectas << '"' << ';' << '"' << rmalas << '"' << ';' << '"' << romitidas << '"' << ';' << '"' << (rcorrectas * 0.5 - rmalas * 0.12) << '"' << ';' << '"' << fixed << setprecision(1) << notaaux << '"' << "\n"; // se llena el archivo con lo datos
            rcorrectas = 0;                                                                                                                                                                                                                                               // reestablecer valores de variables
            rmalas = 0;
            romitidas = 0;
            notaaux = 1.0;
        }
    } // cerrado del for

    lector.close(); // se cierran los archivos
    Resultado.close();

    cout << "----------------" << endl;
    cout << "=== Integrantes ===" << endl;
    cout << "Luis Rivas Sanchez" << endl;
    cout << "Rodrigo Mora Palta" << endl;
    cout << "Andres Segarra Pavez" << endl;
    cout << "----------------" << endl;

    return 0;
}
// cierre main
