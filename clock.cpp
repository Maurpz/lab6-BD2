#include <iostream>
#include "Clock.h"
using namespace std;
int main() {
  Clock c1(4);
  c1.getElement(1);
  c1.getElement(2);
  c1.getElement(3);
  c1.getElement(4);
  c1.getElement(1);
  c1.getElement(2);
  c1.getElement(5);
  c1.getElement(2);
  c1.getElement(7);
  c1.getElement(8);

  return 0;
}