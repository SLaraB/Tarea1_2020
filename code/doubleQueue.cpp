#include <iostream>
#include <cstdlib>
#include<fstream>
#include <ctime> 
#include <string>
using namespace std;

//este bloque declara nuestra clase double Queue
class doubleQueue {
private:
	struct nodeDoubleQueue {
		string val;
		nodeDoubleQueue* next;
		nodeDoubleQueue* prev;
	};
	typedef struct nodeDoubleQueue nodoQ;

	nodoQ *Q;	// puntero AL FRENTE de la cola, por donde se eliminan los elementos (dequeue)
    int nitem;
public:
    doubleQueue();
	doubleQueue(string num);
    ~doubleQueue();

    void enqueue(string);
    string dequeue();
    string front();
    string last();
    int size();
    bool isEmpty();
    void display();
};
// constructor de la clase.. crea la cola vacia
doubleQueue::doubleQueue(){
	cout << "creando Cola doble vacia..." << endl;
	Q=NULL;
	nitem=0;
}

// constructor de la clase.. crea la cola con un elemento
doubleQueue::doubleQueue(string palab){
    Q = new nodoQ;
    Q->val = palab;
    Q->next=Q->prev = NULL;
	nitem=1;
}
// destructor de la clase, libera la memoria de todos los nodoQ
doubleQueue::~doubleQueue() {
	nodoQ *p;

	while(Q != nullptr){
 		p = Q;
 		Q = Q->next; //************************************************
		delete p;
	}
}

// Elimina el elemento que esta al frente de la cola y retorna su valo, en tiempo O(1)
string doubleQueue::dequeue(){
    if(Q==nullptr){
        cout << "Advertencia, cola vacía!!" << endl;
        return " -1";
    }
    nodoQ *p = Q;
    string val = p->val;
    Q = Q->next;
    delete p;
    nitem--;

    return val;
}

// retorna el elemento que esta al frente de la cola, corre en O(1)
string doubleQueue::front(){
	if(Q==nullptr){
        cout << "Advertencia, cola vacía!! = ";
        return " -1";
    }
    return Q->val; //valor al tope de la cola
}
// retorna el elemento que esta al final de la cola (el último que se inserto), corre en O(n)
// retorna el elemento que esta al final de la cola (el último que se inserto), corre en O(n)
string doubleQueue::last(){
    if(Q==nullptr){
        cout << "Advertencia, cola vacía!! = ";
        return " -1";
    }
	nodoQ *p = Q;
    while(p->next !=nullptr)
        p = p->next;
    return p->val; //valor al final de la cola
}

// retorna la cantidad de elementos que hay en la cola, en O(n) time
int doubleQueue::size(){
	if (Q == nullptr)	
		return 0;
	int cant=0;
	nodoQ *p = Q;
	while(p != nullptr){
		cant++;
		p = p->next;
	}
	//cout << "El largo de la cola es: " << cant << endl;
	return cant;
}
bool doubleQueue::isEmpty(){
    if(Q==nullptr)
        return true;
    return false;
}
// lista la cola
// lista la cola
void doubleQueue::display(){
    if(Q==nullptr){
        cout << "Cola vacía" << endl;
        return;
    }
    cout << "Cola con " << nitem << " nodos..." << endl;

    nodoQ *p = Q;
    while(p!=nullptr){
        cout << p->val << " ";
        p = p->next; //recorre hasta el final de la cola
    }
    cout << endl;
}
// inserta un elemento al final(back) de la cola en tiempo O(n): la recorre desde el front al rear y lo pone al final
void doubleQueue::enqueue(string palab) {
    nodoQ *q = new nodoQ;
    q->val = palab;
    q->prev = q->next = NULL;
    nitem++;

    if(Q==nullptr){
        Q = q;
        return;
    }
	nodoQ *p = Q;
    while(p->next != nullptr){
        p = p->next;
    }
    p->next = q;
    q->prev = p;
}

//agrega todas las lineas del .txt en un arreglo donde cada línea es un elemento
void agregaDatos(string *A, string txt);


int main(int argc, char **argv){
	unsigned t0, t1;
 	t0=clock();
	int n,k,x,i,j;
    if(argc != 2){
        cout << "Error. Debe ejecutarse como ./coladoble n" << endl;
        exit(EXIT_FAILURE);
    } 
    n = atoi(argv[1]);

    string* texto= new string[370099];
    agregaDatos(texto,"words_alpha.txt");
	cout << "Ejecutando Double Queue..."<<endl;
    // 1 Crea la cola con un solo dato aleatorio.
    x = rand()%370099; 
    doubleQueue q1(texto[x]);

    // 2 Ingresa y elimina datos alternadamente de acuerdo a la regla
    while(q1.size() < n){
        k = q1.size();
        for(i=0; i<(k*2); i++){ 
            x = rand()%370099;  
            q1.enqueue(texto[x]);
        }
        k = q1.size();
        if(q1.size() >= n){
            if(k!=n)
                cout << "Aviso! el valor mas cercano que supera a " << n << " es " << k << endl;
            break;
        }
        for(j=0; j<(k/2); j++)
            q1.dequeue();
    }
    //q1.display();

    // 3 vacía todos los elementos de la cola
    while(!(q1.isEmpty()))
        q1.dequeue();

    q1.display();
    cout << "###### Fin programa ######" << endl;
	t1 = clock();
 	double time = (double(t1-t0)/CLOCKS_PER_SEC);
	cout << "Execution Time: " << time << endl;
	return EXIT_SUCCESS;
}


void agregaDatos(string *A,string txt){
	ifstream file(txt);
	if(file.is_open() ){
			for(int i = 0;i<370099;i++){
				file>>A[i];
			}
		}
	cout << "Todas las palabras han sido exitosamente guardadas en la lista!" << endl;	
}