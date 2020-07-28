#include <iostream>
#include <cstdlib>
#include <fstream>
#include <ctime> 
#include <string.h>
using namespace std;

#define MIN 1
#define MAX 3

// este bloque define nuestra clase QueueSimple
class QueueSimple {
private:
	struct nodeQueue {
        string val;
		nodeQueue* next;
	};
	typedef struct nodeQueue nodoQ;

	nodoQ *Q;	// puntero AL FRENTE de la cola, por donde se eliminan los elementos (dequeue)
	int nItems;	// almacena la cantidad de elementos de la cola

public:
    QueueSimple();
    QueueSimple(string num);
    ~QueueSimple();

    void enqueue(string); //Inserta un elemento al final de la cola
    string dequeue(); //elimina y retorna el elemento que está al frente de la cola
    string front(); //retorna el elemento que está al frente de la cola
    string last(); //retorna el elemento que está al final de la cola
    int size(); //retorna la cantidad de nodos de la cola
    bool isEmpty(); //retorna verdadero si la cola está vacia
    void display(); // imprime la cola desde el frente al final
};

// constructor de la clase.. crea la cola vacia
QueueSimple::QueueSimple(){
	cout << "creando Cola vacia..." << endl;
	Q = NULL;
	nItems = 0;
}

// constructor de la clase.. crea la cola con un elemento
QueueSimple::QueueSimple(string num){
    Q = new nodoQ;
    Q->val = num;
    Q->next = NULL;
	 nItems = 1;
}

// destructor de la clase, libera la memoria de todos los nodoQ
QueueSimple::~QueueSimple() {
	nodoQ *p;

	while(Q != nullptr){
 		p = Q;
 		Q = Q->next;
		delete p;
	}
}

// inserta un elemento al final de la cola, la recorre desde la izquierda y lo pone al final (a la derecha)
void QueueSimple::enqueue(string elem) {
    nodoQ *q = new nodoQ;
    q->val = elem;
    q->next = NULL;
    nItems++;

    if(Q==nullptr){
        Q = q;
        return;
    }
	nodoQ *p = Q;
    while(p->next != nullptr){
        p = p->next;
    }
    p->next = q;
}

// Elimina el elemento que esta al frente de la cola y retorna su valo
string QueueSimple::dequeue(){
    if(Q==nullptr){
        cout << "Advertencia, cola vacía!!" << endl;
        return " -1";
    }
    nodoQ *p = Q;
    string info = p->val; // info ahora guarda la informacion del nodo eliminado
    Q = Q->next;
    delete p;
    nItems--;

    return info;
}
/*
// retorna el elemento que esta al frente de la cola, corre en O(1)
string QueueSimple::front(){
	if(Q==nullptr){
        cout << "Advertencia, cola vacía!! = ";
        return " -1";
    }
    return Q->val; //valor al tope de la cola
}

// retorna el elemento que esta al final de la cola (el último que se inserto) recorriendo la cola desde la izquierda
string QueueSimple::last(){
    if(Q==nullptr){
        cout << "Advertencia, cola vacía!! = ";
        return " -1";
    }
	nodoQ *p = Q;
    while(p->next !=nullptr)
        p = p->next;
    return p->val; //valor al final de la cola
}
*/
// retorna la cantidad de elementos que hay en la cola, en O(1) time
int QueueSimple::size(){
	return nItems;
}

bool QueueSimple::isEmpty(){
    if(Q==nullptr)
        return true;
    return false;
}

// lista la cola
void QueueSimple::display(){
    if(Q==nullptr){
        cout << "Cola vacía" << endl;
        return;
    }
    cout << "Cola con " << nItems << " nodos..." << endl;

    nodoQ *p = Q;
    while(p!=nullptr){
        cout << p->val << " ";
        p = p->next; //recorre hasta el final de la cola
    }
    cout << endl;
}

void agregaDatos(string *A, string txt);    //agrega todas las lineas del .txt en un arreglo donde cada línea es un elemento

void procesoQS(int n, string *texto);   //Proceso QueueSimple

int main(int argc, char **argv){
    int n;
    clock_t begin, end;
    double time_spent;
    if(argc != 2){
        cout << "Error. Debe ejecutarse como ./simple n" << endl;
        exit(EXIT_FAILURE);
    } 
    n = atoi(argv[1]);

    //crea un strig de tamaño [t]
    string* texto= new string[370099];
    agregaDatos(texto,"words_alpha.txt");   //función que agrega cada palabra de un txt a una celda de mi arreglo

    //Inicio proceso QueueSimple
    begin = clock();
    procesoQS(n, texto);    
    end = clock();  //Fin proceso QueueSimple

    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    cout << "Tiempo de ejecución " << time_spent << " s" << endl;

    
    cout << "###### Fin programa ######" << endl;

	return EXIT_SUCCESS;
}

void agregaDatos(string *A,string txt){
    ifstream file(txt);
    if(file.is_open() ){
            for(int i = 0;i<370099;i++){
                file>>A[i];
            }
        }
}
//Proceso QueueSimple
void procesoQS(int n, string *texto){
    int k,x,i,j;

    // 1 Crea la cola con un solo dato aleatorio de tamaño mínimo MIN y máximo MAX.
    x = rand()%370099; 
    while((texto[x].length() < MIN) | (texto[x].length() > MAX))
                x = rand()%370099;

    QueueSimple q1(texto[x]);   //crea estructura q1 con información texto[x]

    // 2 Ingresa y elimina datos alternadamente de acuerdo a la regla
    while(q1.size() < n){
        k = q1.size();
        for(i=0; i<(k*2); i++){ 
            x = rand()%370099;  
            while((texto[x].length() < MIN) | (texto[x].length() > MAX))
                x = rand()%370099;
            q1.enqueue(texto[x]);
        }
        k = q1.size();
        if(q1.size() >= n){
            if(k!=n)
                cout << "Aviso! el valor mas cercano que supera a " << n << " es " << k <<endl;
            cout << "Se creará una cola de tamaño " << k <<endl;
            break;
        }
        for(j=0; j<(k/2); j++)
            q1.dequeue();
    }
    //q1.display();

    // 3 vacía todos los elementos de la cola
    while(!(q1.isEmpty()))
        q1.dequeue();
    //q1.display();
}