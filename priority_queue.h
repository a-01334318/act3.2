#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include <string>
#include <sstream>
#include <vector>

using namespace std;
typedef unsigned int uint;

template <class T>

class priority_queue {
public:
  
  uint n;
  vector<T> heap;
  void swap(uint, uint);

  priority_queue();

  uint left(uint);
  uint right(uint);
  uint parent(uint);

  void push(T);
  T pop();
  T top();
  bool empty();
  uint size();
  void sort(uint);

  string to_string();
};

template <class T>
priority_queue<T>::priority_queue() {
  n = 0;
}

// Cambiar elementos i, j
template <class T>
void priority_queue<T>::swap(uint i, uint j) {
  T aux = heap[i];
  heap[i] = heap[j];
  heap[j] = aux;
}

// Obtener nodo izquierdo del nodo actual
template <class T>
uint priority_queue<T>::left(uint parent) {
  return parent * 2 + 1;
}

// Obtener nodo derecho del nodo actual
template <class T>
uint priority_queue<T>::right(uint parent) {
  return parent * 2 + 2;
}

// Obtener el nodo padre del nodo actual
template <class T>
uint priority_queue<T>::parent(uint child) {
  return (child - 1) / 2;
}

// Agregue un dato a la fila priorizada.
template <class T>
void priority_queue<T>::push(T val) {
  uint pos = n++;
  heap.push_back(val);

  while (pos > 0 && val > heap[parent(pos)]) {
    swap(pos, parent(pos));
    pos = parent(pos);
  }
}

// Saca de la fila priorizada el dato que tiene mayor prioridad
template <class T>
T priority_queue<T>::pop() {
  if (empty())
    throw;
  T aux = top();
  swap(0, --n);
  heap.pop_back();
  sort(0);
  return aux;
}

// Regresa el valor del dato que esta con mayor prioridad en la fila priorizada.
template <class T>
T priority_queue<T>::top() {
  return heap[0];
}

// Regresa un valor boleando diciendo si la fila priorizada esta vacía o tiene datos.
template <class T>
bool priority_queue<T>::empty() {
  return n == 0;
}

// Regresa la cantidad de datos que tiene la fila priorizada.
template <class T>
uint priority_queue<T>::size() {
  return heap.size();
}

// Colocar a un elemento en su posición dentro del heap.
template <class T>
void priority_queue<T>::sort(uint current) {
  uint current_right = right(current);
  uint current_left = left(current);
  uint aux = current;

  if (current_left < n && heap[current_left] > heap[current])
    current = current_left;

  if (current_right < n && heap[current_right] > heap[current])
    current = current_right;

  if (current != aux) {
    swap(current, aux);
    sort(aux);
  }
}

// Convierte la lista priorizada en un string.
template <class T>
string priority_queue<T>::to_string() {
  stringstream s;
  s << "[ ";
  for (uint i = 0; i < heap.size(); i++)
    s << heap[i] << " ";
  s << "]";
  return s.str();
}

#endif
