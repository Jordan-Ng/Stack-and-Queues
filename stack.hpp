#pragma once
#include <vector>
#include <cstddef>

// (2) defining the interface
namespace DS::ContAdapter{
    template <typename T, class UnderlyingContainer = std::vector<T>>
    class Stack {
        public:        
            // required by definition
            void push(T& item);
            void pop();
            T& top();
            // T const& top();

            // extra memeber functions
            bool isEmpty();
            std::size_t size();
        
        private:
            // keeping track of size here because std::list and 
            // std::forward_list calculates size at O(n) time
            std::size_t _size=0;
            UnderlyingContainer _collection;
    };
}

namespace DS::ContAdapter{
    #ifndef STACK_HELPER_CONCEPTS
    #define STACK_HELPER_CONCEPTS
        template<typename Container>
        concept is_front_insertable = requires(Container c){
            c.push_front(c.front());
            c.pop_front();
            c.front();
        };        
    #endif

    template<typename T, class UnderlyingContainer>
    bool Stack<T, UnderlyingContainer>::isEmpty() {return size() == 0;};

    template<typename T, class UnderlyingContainer>
    std::size_t Stack<T, UnderlyingContainer>::size() {return _size;};

    // accessors
    template<typename T, class UnderlyingContainer>
    T& Stack<T, UnderlyingContainer>::top(){
        if constexpr(is_front_insertable<UnderlyingContainer>){ return _collection.front();}
        else {return _collection.back();}
    }

    template<typename T, class UnderlyingContainer>
    void Stack<T, UnderlyingContainer>::push(T& data){
        if constexpr(is_front_insertable<UnderlyingContainer>){ _collection.push_front(data);}
        else{ _collection.push_back(data);}
        ++_size;
    }

    template<typename T, class UnderlyingContainer>
    void Stack<T, UnderlyingContainer>::pop(){
        if constexpr(is_front_insertable<UnderlyingContainer>) {_collection.pop_front();}
        else {_collection.pop_back();}
        --_size;
    }
}






