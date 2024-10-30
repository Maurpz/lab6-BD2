#include <iostream>
using namespace std;

#ifndef MRU_H
#define MRU_H
class Mru {
  private:
    int sizeBuffer;       //tamaño del buffer
    int elements;         //elementos existentes en el buffer
    int * buffer;         //contendor de los elementos
    int  ultimateIndex;   //indice del ultimo elemento usado
  public:
  
  Mru(int size){
    this->sizeBuffer = size;
    this->buffer = new int[size];
    this->elements = 0;
  }
  ~Mru() {
    delete [] buffer;
  }

  void getElement(int element) {
    cout<<"--------getElement "<<element<<"--------"<<endl;
    int flag = findElement(element);
    if (flag >= 0) {
      ultimateIndex = flag;
      cout<<buffer[ultimateIndex]<<"*"<<endl;
      return;
    }

    if (!isFull()){
      buffer[elements] = element;
      ultimateIndex = elements;
      elements++;
      cout<<buffer[ultimateIndex]<<"*"<<endl;
      cout<<"Interrupcion por carga de "<<element<<endl;
      return;
    }
    cout<<"Remplazo del ultimo elemento : "<<buffer[ultimateIndex]<<endl;
    buffer[ultimateIndex] = element;
    cout<<buffer[ultimateIndex]<<"*"<<endl;
    cout<<"Interrupcion por carga de "<<element<<endl;
  }


  //si el elemento se encuentra en el buffer retorna su posicion
  //si no se encuentra retorna -1
  int findElement (int element) {
    for (int i = 0; i < sizeBuffer; i++) {
      if (buffer[i] == element) return i;
    }
    return -1;
  }

  //retorna true si el buffer esta lleno y false si no lo esta
  bool isFull() {
    return !(elements < sizeBuffer);
  }
};

#endif