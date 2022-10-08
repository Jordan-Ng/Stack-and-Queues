#pragma once
#include <cstddef>
#include <stdexcept>

#include <array>

namespace DS::ContAdapter{
    template<typename T, std::size_t capacity>
    class StackArray {
        public:
            void push(T& item);
            void pop();
            T& top();

            bool isEmpty();
            std::size_t size();
        
        private:
            std::size_t _size=0;
            std::array<T,capacity> _collection;
    };
}

namespace DS::ContAdapter{
    template<typename T, std::size_t capacity>
    std::size_t StackArray<T, capacity>::size(){
        return _size;
    }

    template<typename T, std::size_t capacity>
    bool StackArray<T, capacity>::isEmpty(){
       return size() == 0; 
    }

    template<typename T, std::size_t capacity>
    T& StackArray<T, capacity>::top(){
        return _collection.at(_size - 1);
    }

    template<typename T, std::size_t capacity>
    void StackArray<T, capacity>::push(T& data){
        if (_size >= capacity) throw std::out_of_range("attempting to add to a full array");

        _collection.at(_size) = data;
        ++ _size;
    }

    template<typename T, std::size_t capacity>
    void StackArray<T, capacity>::pop(){
        if(isEmpty()) throw std::out_of_range("attempting to remove value from empty stack");
        
        -- _size;
        _collection[_size] = T{};
    }
}