#include <iostream>
using namespace std;


#ifndef CLOCK_H
#define CLOCK_H

typedef struct Marco {
  u_int8_t bitUso;
  int value;
} Marco;

class Clock {
  private:
    int sizeBuffer;
    Marco * buffer;
    int elements;
    int punteroIndice;
  public:
  Clock(int size) {
    this->sizeBuffer = size;
    this->buffer = new Marco[size];
    this->elements = 0;
    this->punteroIndice = 0;
  }
  ~Clock() {
    delete [] buffer;
  }

  bool isFull() {
    return !(elements < sizeBuffer);
  }
  int findElement (int element) {
    for (int i = 0; i<sizeBuffer; i++) {
      if (buffer[i].value == element) return i;
    }
    return -1;
  }

  int getElement(int element) {
    cout<<"---------- getElement "<<element<<"----------"<<endl;
    int flag = findElement(element);
    if (flag >=0) {
      buffer[flag].bitUso = 1;
      cout<<"El elemento ya esta en el buffer"<<endl;
      return buffer[flag].value;
    }
    int result = 0;
    bool complete = false;
    while(!complete) {
      if (!isFull()) {
        buffer[elements].bitUso = 1;
        buffer[elements].value = element;
        result = buffer[elements].value;
        elements++;
        complete = true;
        cout<<"Interrupcion por carga del elemento: "<<element<<endl;
      }
      else {
        int puntero = punteroIndice % sizeBuffer;
        if (buffer[puntero].bitUso != 0) {
          buffer[puntero].bitUso = 0;
          punteroIndice++;
        }
        else {
          cout<<"\tRemplazo de elemento: "<<buffer[puntero].value<<endl;
          buffer[puntero].bitUso = 1;
          buffer[puntero].value = element;
          result = buffer[puntero].value;
          complete = true;
          cout<<"Interrupcion por carga del elemento: "<<element<<endl;
          punteroIndice++;
        }
        cout<<"puntero del buffer: "<<puntero<<endl;
        
      }
      
    }
    return result;
  }
};
#endif