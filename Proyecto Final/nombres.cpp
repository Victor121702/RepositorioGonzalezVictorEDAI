#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <utility> 
 
using namespace std;


//Estructura cola
struct Cola
{
    string dato;
    Cola *ptrSiguiente;
};

//Estructura pila
struct Pila
{
    string dato;
    Pila *ptrSiguiente;
};

//Las dos estructuras de tipo string porque trabajaremos con letras, es decir con carácteres
//Al igual las dos cuentan con punteros, solo que uno de tipo cola y otro de tipo pila

//Instanciando estructuras de pila y cola
typedef Cola *ptrNodoCola;
typedef Pila *ptrNodoPila;
 
//Cabecera de funciones
//Es decir las funciones que utilizará el programa
void informacion();
void crearFichero();
void deFicheroAPila(ptrNodoPila *ptrCima, ifstream& in);
void empujarPila(ptrNodoPila *ptrCima, string info);
void imprimePila(ptrNodoPila ptrActual);
void dePilaAVector(ptrNodoPila ptrActual, vector<string>& v);
void ordenarPorBurbuja(vector<string>& v);
void imprimeVector(const vector<string>& v);
void deVectorACola(const vector<string>& v, ptrNodoCola *ptrCabeza, ptrNodoCola *ptrTalon);
void agregarCola(ptrNodoCola *ptrCabeza, ptrNodoCola *ptrTalon, string valor);
bool estaVacia(ptrNodoCola ptrCabeza);
void imprimeCola(ptrNodoCola ptrActual);
 
//Método principal
//Aquí se va a colocar todo lo que haremos posteriormente
//Es decir, dentro del main
int main()
{
    informacion(); //Se imprime la información sobre el programa
    
    crearFichero(); //Creando fichero con nombres

    ifstream in("Listar.txt"); //Ahora lee el fichero 
    vector<string> vector;
 
    ptrNodoCola ptrCabeza = NULL; 
    ptrNodoCola ptrTalon = NULL;  //Declaramos variables del vector, la ultima parte de la cola, de la pila, la cima de la cola
 
    ptrNodoPila ptrPila1 = NULL;
 
    deFicheroAPila(&ptrPila1, in); //Pasamos el fichero a la pila

 
    //imprimimos la pila una vez que esta creada, con los nombres no ordenados
    cout << "\nPila : ";
    imprimePila(ptrPila1);

    //Pasamos valores de la pila a un vector
    dePilaAVector(ptrPila1, vector);
 
    //Ordenamos los nombres del vector por ordenamientoburbuja
    ordenarPorBurbuja(vector);
    
    //imprimimos el vector con nombres ordenados
    cout << "\nVector ordenado: ";
    imprimeVector(vector);
    
    //Pasamos los valores del vector a la cola
    deVectorACola(vector, &ptrCabeza, &ptrTalon);
 
    //imprimimos la cola con los nombres ordenados, ya que se ordeno todo en el vector
    cout << "\nCola: ";
    imprimeCola(ptrCabeza);
 
    return EXIT_SUCCESS;
}

//Aquí simplemente mando a imprimir la información del programa
void informacion(){
    cout<<"Programa con el uso de Pilas y Colas en C++ que crea un fichero de texto llamado 'Listar.txt' con 10 nombres, y lo lee para después ordenarlos de manera alfabética\n";
}

//Esta función crea un archivo de texto, y mientras lo esta haciendo, agrega diez nombres distintos
void crearFichero(){
    string nombreArchivo = "Listar.txt";
    ofstream archivo;
		// Abrimos el archivo
		archivo.open(nombreArchivo.c_str(), fstream::out);

		archivo << "Helena" << endl;
		archivo << "Lorena" << endl;
		archivo << "Carlos" << endl;
        archivo << "Tamara" << endl;
        archivo << "José" << endl;
        archivo << "Marcelo" << endl;
        archivo << "Alicia" << endl;
        archivo << "Brenda" << endl;
        archivo << "Daniel" << endl;
        archivo << "Gerardo" << endl;
    // Finalmente lo cerramos
		archivo.close();
		cout << "Fichero creado correctamente";
}
 
//Pasamos los valores del fichero a la pila
void deFicheroAPila(ptrNodoPila *ptrCima, ifstream& in)
{
    string nombre;
 
    for (size_t i = 0; i < 10; i++)
    {
        in >> nombre;
        empujarPila(ptrCima, nombre);
    }
}
//Aquí estamos haciendo referencia al puntero de tipo pila del principio
void empujarPila(ptrNodoPila *ptrCima, string info)
{
    ptrNodoPila ptrNuevo;
 
    ptrNuevo = new Pila;
 
    if (ptrNuevo != NULL)
    {
        ptrNuevo->dato = info;
        ptrNuevo->ptrSiguiente = *ptrCima;
        *ptrCima = ptrNuevo;
    }
}
 
//Recorre toda la pila con el ciclo while, va imprimiendo valor por valor, haciendo referencia al elemneto siguiente
//Imprimir pila

void imprimePila(ptrNodoPila ptrActual)
{
    if (ptrActual ==  NULL)
        cout  << "La pila esta vacia" << endl;
 
    else
    {
        while (ptrActual != NULL)
        {
            cout << "-> " << ptrActual->dato;
            ptrActual = ptrActual->ptrSiguiente;
        }
 
        cout << "-> NULL\n\n";
    }
}
 
//Si la pila no esta vacía pasa los nombres al vector
//Pasamos los valores de la pila al vector
void dePilaAVector(ptrNodoPila ptrActual, vector<string>& v)
{
    while (ptrActual != NULL)
        {
            v.push_back(ptrActual->dato);
            ptrActual = ptrActual->ptrSiguiente;
        }
}
 
//Ordenamiento burbuja para ordenar los nombres alfabéticamente del vector
//Esto con ayuda del ciclo for, con dos en este caso
//Un for recorre la columna es decir, la primera letra, y el otro las filas, todos los nombres
void ordenarPorBurbuja(vector<string>& v)
{
    for (size_t i = 0; i < v.size() - 1; i++)
        for (size_t j = 0; j < v.size() - i - 1; j++)
            if (v[j] > v[j + 1])
                swap(v[j], v[j+1]);
}
 
//Imprimir nombres en el vector
//Con el ciclo for se recorre el vector, y despúes se imprime
void imprimeVector(const vector<string>& v)
{
    for (size_t i = 0; i < v.size(); i++)
        cout << v[i] << " ";
 
    cout << endl;
}
 
//Esta función pasa el vector a la estructura cola

void deVectorACola(const vector<string>& v, ptrNodoCola *ptrCabeza, ptrNodoCola *ptrTalon)
{
    for (size_t i = 0; i < v.size(); i++)
        agregarCola(ptrCabeza, ptrTalon, v[i]);
}
 
//Esta función esta haciendo un puntero de tipo cola, y agrega los valores por medio del valor "dato"
void agregarCola(ptrNodoCola *ptrCabeza, ptrNodoCola *ptrTalon, string valor)
{
    ptrNodoCola ptrNuevo;
 
    ptrNuevo = new Cola;
 
    ptrNuevo->dato = valor;
    ptrNuevo->ptrSiguiente = NULL;
 
    if (estaVacia(*ptrCabeza))
        *ptrCabeza = ptrNuevo;
 
    else
        (*ptrTalon)->ptrSiguiente = ptrNuevo;
 
    *ptrTalon = ptrNuevo;
}
 
bool estaVacia(ptrNodoCola ptrCabeza)
{
    return ptrCabeza == NULL;
}
 
//Imprimimos la cola
//Se recorre toda la cola y va imprimiendo valor por valor
void imprimeCola(ptrNodoCola ptrActual)
{
    if (ptrActual ==  NULL)
        cout  << "La pila esta vacia" << endl;
 
    else
    {
        while (ptrActual != NULL)
        {
            cout << "-> " << ptrActual->dato;
            ptrActual = ptrActual->ptrSiguiente;
        }
 
        cout << "-> NULL\n\n";
    }
}


