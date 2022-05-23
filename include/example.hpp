// Copyright 2022 Lonskiy Yuriy <yuralong.skiy@mail.ru>

#ifndef INCLUDE_EXAMPLE_HPP_
#define INCLUDE_EXAMPLE_HPP_
#include <iostream>

template <typename T>
class Stack
{ private:
  struct Node
  {
    int data;
    Node *next;
  };
 public:
  const T& head() const;
  int counter = -1;
  void push(T&& value); //done
  void push(const T& value);//done
  T pop();//done
  Stack();
  //const T& head() const;
  ~Stack(){
    std::cout << "Stack have destructed";
  }
  Node *top_node;
};

template <typename T>
Stack<T>::Stack(){
  if (counter == -1){
    top_node = new Node;
    top_node->data = 0;
    top_node->next = nullptr;
    counter++;
  }
}


template <typename T>
void Stack<T>::push(T&& value){
  top_node = new Node;
  top_node->data = value;
  top_node->next = std::move(this->top_node->next);
  counter++;
}
template <typename T>
void Stack<T>::push(const T& value){
  top_node = new Node;
  top_node->data = value;
  top_node->next = std::move(this->top_node->next);
  counter++;
}
template <typename T>
T Stack<T>::pop(){
  if (top_node->next != nullptr) {
    T a = this->top_node->data;
    Node *destr = top_node;
    delete destr;
    top_node = std::move(top_node->next);
    counter--;
    return a;
  }
  else{
    T a = this->top_node->data;
    counter--;
    std::cout << "End of stack" << std::endl;
    return a;
  }
}
template <typename T>
const T& Stack<T>::head() const {
  if (top_node == nullptr)
    throw std::runtime_error("stack is empty");
  return top_node->data;
}
#endif // INCLUDE_EXAMPLE_HPP_
