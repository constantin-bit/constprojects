#pragma once
#include <iostream>
#include <cassert>

//stack
template <typename T>
class stack{
    public:
        stack(T* _array, int _size){
            size = _size;
            array = new T[size];
            for (int i = 0; i < size; i++){
                *(array + i) = *(_array + i);
            }
        }
        stack(){
            size = 0;
            array = new T[0];
        }
        void operator<<(T element){
            T* _array;
            _array = new T[size + 1];
            for (int i = 0; i < size; i++){
                _array[1 + i] = array[i];
            }
            _array[0] = element;
            size += 1;
            delete[] array;
            array = new T[size];
            for (int i = 0; i < size; i++){
                array[i] = _array[i];
            }
            delete[] _array;
        }
        void operator>>(T &element){
            element = array[0];
            T* _array;
            _array = new T[size - 1];
            size -= 1;
            for (int i = 0; i < size; i++){
                _array[i] = array[i + 1];
            }
            delete[] array;
            array = new T[size];
            for (int i = 0; i < size; i++){
                array[i] = _array[i];
            }
            delete[] _array;
        }
        T operator[](int i){
            return array[size - i - 1];
        }
        void operator=(stack new_stack){
            delete[] array;
            array = new T[new_stack.get_size()];
            size = new_stack.get_size();
            for (int i = 0; i < size; i++){
                array[i] = new_stack[i];
            }
        }
        int get_size(){
            return size;
        }
        bool operator<(stack second_stack){
            if (size < second_stack.get_size()) return true;
            return false;
        }
        bool operator==(stack second_stack){
            if (size == second_stack.get_size()) return true;
            return false;
        }
        bool operator>(stack second_stack){
            if (size > second_stack.get_size()) return true;
            return false;
        }
        void print(){
            std::cout << "stack: ";
            for (int i = 0; i < size; i++){
                std::cout << array[i];
            }
            std::cout << std::endl;
        }
    protected:
    private:
        T* array;
        int size;
};
