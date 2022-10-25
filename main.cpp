#include <iostream>
#include "priority_queue.h"

using namespace std;

int main() {
  priority_queue<int> dataset;

  dataset.push(33);
  dataset.push(6);
  dataset.push(55);
  dataset.push(11);
  dataset.push(52);


  cout << dataset.to_string() << endl;
  cout << "Tamaño del dataset: " << dataset.size() << endl;
  cout << "Elemento eliminado: " << dataset.pop() << endl;
  cout << "Elemento con mayor prioridad actual: " << dataset.top() << endl;
  cout << "Nuevo dataset: " << dataset.to_string() << endl;

  cout << "¿La lista está vacía?" << dataset.empty() << endl;
}
