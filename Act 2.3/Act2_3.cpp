/*
Nombres y matrículas:
    Esthela Sofía Cedillo Moreno A00828420
    Rodrigo Pelayo Ochoa A00827285
    Juan Carlos Triana Vela A00827629

Equipo 17
*/


#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "DoubleLinkedL.h"

using namespace std;

long long ipToLong(string ip){
	int idx = 0;
	long long datoFinal= 0, dato = 0;
	while (idx < ip.size()){
		if (ip[idx]!= '.' && ip[idx]!=':'){
			dato = dato*10 + ip[idx]-'0';
		}
		else{
			datoFinal = datoFinal*1000 + dato;
			dato = 0;
		}
		idx++;
	}
	datoFinal = datoFinal*10000 + dato;
	return datoFinal;
}

int main(){

    //DoublyLinked List
    DoubleLinkedL ListaBitacora;
    //Variable de almacenaje de busqueda
    Bitacora almacena;
    
    //Variables de lectura 
    ifstream archivo("bitacora.txt");
    string line;
    string valor;
    int iRegistro=0;
    char delim=' '; //El delimitador de las variables es el espacio

    //Lectura del archivo
    while(getline(archivo, line)){
        stringstream ss(line);
        getline(ss,valor,delim);
        almacena.mes = valor;
        getline(ss,valor,delim);
        almacena.dia = stoi(valor);
        getline(ss,valor,delim);
        almacena.hora = valor;
        getline(ss,valor,delim);
        almacena.IP = valor;
        almacena.IpKey = ipToLong(valor);
        cout << "IP: " << almacena.IP << endl;
        getline(ss,valor);
        almacena.concepto = valor;
        ListaBitacora.addLast(almacena);
        iRegistro++;
    }
    archivo.close();

    //Ordena el archivo
    ListaBitacora.ordenaBurbuja();
    /*
        Apartir de aquí se podría decir que el código no funciona. En nuestras pruebas con Ipskey más pequeños 
        el programa es capaz de ordenar los resultados pero no entendemos el por qué no funciona aquí.

        El resto de funcionalidades trabaja perfectamente desde la búsqueda de posiciones mayor y menor, 
        escribir un nuevo archivo e imprimir dentro del rango de búsqueda. Absolutamente todas son funcionales el
        problema, creemos, es debido a las IPs pero tampoco podemos asegurar nada. Tal vez ordenando por otra variable
        si que fuera posible.
        
        Otro de los posibles problemas que puede tener puede ser nuestro IDE que es incapaz de llevar a cabo las operaciones indicadas...

        Lo sentimos por entregar un trabajo que no es completamente funcional. Esperamos su compresión y nos serviría de mucho
        una asesoría de ser posible para encontrar el problema.
        
        Atte Equipo 17
    */
    //Escritura del archivo
    ListaBitacora.archivoSalida("nueva_bitacora.txt");
 
    string IP;
    long long busca1, busca2;
    cout << "Escribe la IP menor que deseas buscar: ";
    cin  >> IP;

    busca1 = ipToLong(IP);

    cout << "Escribe la IP mayor que deseas buscar: " ;
    cin >> IP;
    busca2 = ipToLong(IP);

    while (busca1 > busca2){
        cout << "IP no válida por ser mayor a la menor. Intenta de nuevo: ";
        cin >> IP;
        busca2 = ipToLong(IP);
    }

    int pos1, pos2;
    pos1 = ListaBitacora.searchMen(busca1);
    pos2 = ListaBitacora.searchMay(busca2);


    ListaBitacora.printPos(pos1,pos2);

    return 0;
}
