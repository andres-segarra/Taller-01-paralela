#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <iomanip>
#include <omp.h>
#define NOMBRE_ARCHIVO "pruebas.csv"

//Tag de envio
#define TAG 1


// Indica el procesador que será considerado como Líder (Master)

#define LIDER 0

//using
using namespace std;

/**
 * @param argc Cantidad de argumentos
 * @param argv El arreglo asociativo con los argumentos del programa
 * @return El programa retornará Cero en caso de éxito y un número distinto en
 * caso de error.
 */

int main(/*int argc, char *argv[]*/) {

   // Variables auxiliares
    int aux = 0;
    int aux2 = 0;
    int aux3 = 0;
    int aux4 = 0;
    int x =1;
    float notaaux =1.0;
    char line[10000];
    string correctas [13] = {"V","A","E","C","B","B","D","A","B","E","C","B","D"} ;
    int rcorrectas = 0;
    int rmalas = 0;
    int romitidas = 0;
    float puntajetotal =0;
    float nota =0;
    float resul = 0.0;

    std::ifstream lector (NOMBRE_ARCHIVO);
    string linea;
    char delimitador =';';
    getline (lector, linea);
    string recibidor [13];

    std::ofstream Resultado; //aca se creó el archivo csv
     if (Resultado.fail()){
            printf("ERROR AL LEER EL ARCHIVO"); // no se pudo abrir/crera archivo
            exit(1);
        }
    Resultado.open ("Resultados.csv");
    Resultado << "Token Estudiante"<<";"<<"Correctas"<<";"<<"Incorrectas"<<";"<<"Omitidas"<<";"<<"Puntaje"<<";"<<"Nota"<< "\n";
#pragma omp parallel
{
    //int id=omp_get_thread_num();
    //int nt= omp_get_num_threads();

    while (getline(lector, linea)){
        stringstream stream(linea);
        string nombre, p1,p2,p3,p4,p5,p6,p7,p8,p9,p10,p11,p12;
        getline(stream, nombre, delimitador);
        getline (stream, p1, delimitador);
        getline (stream, p2, delimitador);
        getline (stream, p3, delimitador);
        getline (stream, p4, delimitador);
        getline (stream, p5, delimitador);
        getline (stream, p6, delimitador);
        getline (stream, p7, delimitador);
        getline (stream, p8, delimitador);
        getline (stream, p9, delimitador);
        getline (stream, p10, delimitador);
        getline (stream, p11, delimitador);
        getline (stream, p12, delimitador);
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


#pragma omp for
        for(int i=1; i < 13; i++){
            if(recibidor[i] == correctas[i]){
                notaaux += 0.5;
                rcorrectas++;
            }else{
                if(recibidor[i] == "-"){
                    romitidas++;
                }else{
                    notaaux -= 0.12;
                    rmalas++;
                }
            }
        }
        if(notaaux<1){  //si ya teniendo 9 malas es nota 1, se ja como esta nota como minima
            notaaux = 1.0;
        }

#pragma omp critical

        Resultado << recibidor[0] <<";"<< rcorrectas <<";"<< rmalas <<";"<<romitidas <<";"<< (rcorrectas*0.5-rmalas*0.12) <<";"<< fixed << setprecision(1) << notaaux << "\n";

        rcorrectas=0;  //reestablecer valores de variables
        rmalas=0;
        romitidas=0;
        notaaux=1.0;
        resul = 0.0;
    }
    lector.close();
    Resultado.close ();
}
    cout << "----------------" << endl;
    cout << "=== Integrantes ===" << endl;
    cout << "Luis Rivas Sanchez" << endl;
    cout << "Rodrigo Mora Palta" << endl;
    cout << "Andres Segarra Pavez" << endl;
    cout << "----------------" << endl;
    return 0;

}
