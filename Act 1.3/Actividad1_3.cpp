/*
Nombres y matrículas:
    Esthela Sofía Cedillo Moreno A00828420
    Rodrigo Pelayo Ochoa A00827285
    Juan Carlos Triana Vela A00827629

Equipo 17
*/


#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

//Estructura de Bitacora
struct Bitacora{
    string mes;
    int dia;
    int key;
    string hora;
    string IP;
    string concepto;
};

//Funcion: une
//Valores de entrada: un vector con la bitacora, el vector auxiliar, un número de inicio y de fin
//Descripcion: une de vuelta las 2 mitades ordenadas del arreglo
//Complejidad: O(n)
void une(vector<Bitacora> &v, vector<Bitacora> &aux,int ini, int fin){
    int m = (ini+fin)/2;
    int i = ini, j = m+1, k = ini;
    int cant = 0;
    while (i<=m && j<=fin){
        cant++;
        if (v[i].key <= v[j].key ){ //Evalua cual elemento de cada mitad es menor
            aux[k++] = v[i++];
        }
        else{
            aux[k++] = v[j++];
        }
    }
    //Lleva los elementos restantes de la mitad que faltó hasta el final
    while (i<=m){
        aux[k++] = v[i++];
    }
    while (j<=fin){
        aux[k++] = v[j++];
    }
    
    for(int z=ini; z<=fin; z++){
        v[z] = aux [z];
    }
}

//Funcion: ordenaMerge
//Valores de entrada: un vector de bitacoras, un vector auxiliar, el inicio y el fin
//Descripcion: ordena el vector de Bitacoras en base a su fechas (key)
//Complejidad O(nlog n)
void ordenaMerge(vector<Bitacora> &v, vector<Bitacora> &aux, int ini, int fin){

    if (ini < fin){
        int mid = (ini + fin) /2; //indice en el cual se va a dividir el vector
        ordenaMerge(v, aux, ini, mid);
        ordenaMerge(v, aux, mid+1, fin);
        une(v, aux, ini, fin);
    }
    
}

//Funcion: busqBinariaMin
//Valores de entrada: un vector bitacora ya ordenado, el dato a buscar
//Descripción: realiza una búsqueda binaria del dato solicitado y retorna su índice del vector o el siguiente
//Complejidad: O(log2 n)
int busqBinariaMin(vector<Bitacora> &v, int dato){
    int ini=0, fin = v.size()-1, mit;
    while (ini <= fin){
        mit = (ini+fin)/2;
        if(v[mit].key>= dato && dato>v[mit-1].key){
            return mit;
        }
        if (v[mit].key >= dato){
            fin = mit-1;
        }
        else{
            ini = mit +1;
        }
    }
    return ini;
}

//Funcion: busqBinariaMay
//Valores de entrada: un vector bitacora ya ordenado, el dato a buscar
//Descripción: realiza una búsqueda binaria del dato solicitado y retorna su índice mayor en el vector o el más cercano
//Complejidad: O(log2 n)
int busqBinariaMay(vector<Bitacora> &v, int dato){
    int ini=0, fin = v.size()-1, mit;
    while (ini <= fin){
        mit = (ini+fin)/2;
        if(v[mit].key<= dato && dato<v[mit+1].key){
            return mit;
        }
        if (v[mit].key > dato){
            fin = mit-1;
        }
        else{
            ini = mit +1;
        }
    }
    return ini;
}



//Función: createKey
//Valores de entrada: un string con las iniciales del mes y un int que representa el dia
//Descripción: crea un key que una el mes y el dia para clasificarlos de mayor a menor
//Complejidad O(1)
int createKey(string mes, int dia){
    if (mes=="Ene"){
        return 100+dia;
    }
    else if(mes=="Feb"){
        return 200+dia;
    }
    else if(mes=="Mar"){
        return 300+dia;
    }    
    else if(mes=="Abr"){
        return 400+dia;
    }
    else if(mes=="May"){
        return 500+dia;
    }
    else if(mes=="Jun"){
        return 600+dia;
    }
    else if(mes=="Jul"){
        return 700+dia;
    }
    else if(mes=="Aug"){
        return 800+dia;
    }
    else if(mes=="Sep"){
        return 900+dia;
    }
    else if(mes=="Oct"){
        return 1000+dia;
    }
    else if(mes=="Nov"){
        return 1100+dia;
    }
    else if(mes=="Dic"){
        return 1200+dia;
    }
}


int main(){

    //Vector de la bitacora de busquedas
    vector<Bitacora> vecBitacora;

    //Variable de almacenaje de busqueda
    Bitacora almacena;
    
    //Variables de lectura 
    ifstream archivo("bitacora.txt");
    string line;
    string valor;
    int iRegistros=0;
    char delim=' '; //El delimitador de las variables es el espacio

    //Lectura del archivo
    while (getline(archivo,line)){ //mientras haya lineas que leer
        stringstream ss(line);
        getline(ss,valor,delim);
        almacena.mes = valor;
        getline(ss,valor,delim);
        almacena.dia = stoi(valor);
        almacena.key = createKey(almacena.mes, almacena.dia);
        getline(ss,valor,delim);
        almacena.hora = valor;
        getline(ss,valor,delim);
        almacena.IP = valor;
        getline(ss,valor);  //El último valor de la lectura ya no usa el delim
        almacena.concepto = valor;
        vecBitacora.push_back(almacena);
        iRegistros++;
    }
    archivo.close();
    
    //Merge del vector
   vector<Bitacora> aux(iRegistros);
   ordenaMerge(vecBitacora,aux,0,iRegistros-1);

   ofstream archivo2;
   archivo2.open("bitacora_ordenada.txt",ios::out); //Se crea el archivo. Si ya existe, lo reemplaza

   if (archivo2.fail()){ //En caso de error al crear el archivo
       cout << "No se pudo abrir el archivo" << endl;
       archivo2.close();
   }
   else{
       for(int i=0; i<iRegistros; i++){ //Escribe en el archivo en el mismo formato que la bitacora original
           archivo2 << vecBitacora[i].mes << " ";
           archivo2 << vecBitacora[i].dia << " ";
           archivo2 << vecBitacora[i].hora << " ";
           archivo2 << vecBitacora[i].IP << " ";
           archivo2 << vecBitacora[i].concepto <<endl;
       }
       archivo2.close();
   }
   
   //Variables para realizar la búsqueda
   int diaMin, diaMay, keyIni, keyFin, iniIndex, finIndex; 
   string mesMin, mesMax;

   cout << "Ingresa la fecha de incio." << endl;
   cout << "Mes: ";
   cin >> mesMin;
   cout << "Dia: ";
   cin >> diaMin;
   keyIni = createKey(mesMin,diaMin); //Se crea una key de la fecha de inicio

   cout << "Ingresa la fecha final." << endl;
   cout << "Mes: ";
   cin >> mesMax;
   cout << "Dia: ";
   cin >> diaMay;
   keyFin = createKey(mesMax,diaMay); //Se crea una key de la fecha final

   iniIndex = busqBinariaMin(vecBitacora,keyIni);
   finIndex = busqBinariaMay(vecBitacora,keyFin);

   for(int i=iniIndex-1; i<=finIndex; i++){ //Despliegue de los datos a modo de lista

       cout << " Mes: " << vecBitacora[i].mes << endl;
       cout << " Dia: " << vecBitacora[i].dia << endl;
       cout << " Hora: " << vecBitacora[i].hora << endl;
       cout << " IP: " << vecBitacora[i].IP << endl;
       cout << " Concepto: " << vecBitacora[i].concepto << endl;
       cout << endl;
   }


    return 0;
}