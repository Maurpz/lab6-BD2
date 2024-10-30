#include <iostream>
#include "Mru.h"
using namespace std;
int main () {
  Mru p1(3);
  p1.getElement(1);
  p1.getElement(2);
  p1.getElement(3);
  p1.getElement(1);
  p1.getElement(6);
  return 0;
}