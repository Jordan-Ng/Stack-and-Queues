#include <iostream>
#include <string>
#include <array>
#include "stack.hpp"
#include "stack_array.hpp"

// (1) pseudocode -> (2) interface -> (3) main -> (4) implementation
bool hasProperClosure(std::string inputString);
std::size_t findInArray();
int main(){
    /* GOAL: we want to understand the implementation of stacks

      stacks are container adapters (wrapper around the data structure)
      - this means that it provides an interface for the client to interact with but leaves the implementation to the container itself
      - stacks only have 3 member functions (push, pop and top), and it delegates those operations to these containers according to their implementation
          - for example, std::forward_list supports only push_front, and std::vector supports push_back, so the stack adapter needs to make sure
            to call the right functions for the right container
          - ideally, the stack adapter should support these operations (push, pop, top) in O(1) time. 
          
    Question: Why do we need to support so many type of containers ? why can't we support an implementation on say vectors, and call it a day?
    - Generally, these operations run in O(1) time. However, there are some caveats and tradeoffs to them depending on the data sample.
      See notes for further clarification.

    (1) what we need in the interface
        - push
        - pop
        - top
    */

//    -- driver code --
/*  define a function that takes in an input of strings with opening and closing brackets.
    i.e "[{}]()"
    and compute whether the brackets have proper closure
    i.e "()" => true
    i.e "[(])" => false
    i.e "[(){}]" => true
*/

//  (3)
// DS::ContAdapter::Stack<std::string > myStack;
// std::cout<< std::boolalpha << myStack.isEmpty() << "\n";
// std::string stringg {"hello"};
// myStack.push(stringg);
// std::cout << myStack.top() << std::endl;
// myStack.pop();
// std::cout << myStack.top() << std::endl;

std::cout << std::boolalpha 
    << hasProperClosure("[{}]()") << "\n"
    << hasProperClosure("()") << "\n"
    << hasProperClosure("[()]") << "\n"
    << hasProperClosure("[(])") << "\n"
    << hasProperClosure("[(){}]") << "\n";

// -- driver code for stack array --
// DS::ContAdapter::StackArray <std::string, 3> myStackArray;
// std::cout<<std::boolalpha << myStackArray.isEmpty() << std::endl;
// std::string string1 = "string1";
// std::string string2 = "string2";
// myStackArray.push(string1);
// std::cout<< myStackArray.top() << std::endl;
// myStackArray.push(string2);
// std::cout<< myStackArray.top() << std::endl;
// myStackArray.pop();
// std::cout<< myStackArray.top() << std::endl;
}

std::size_t findInOpenBracketsArray(char character){
    std::array<char, 3> open {'(', '[', '{'};
    for (auto i=0; i< open.size(); ++i){
        if (open.at(i) == character) return i;
    }
    return open.size();
}

bool hasProperClosure(std::string inputString){
    std::array<char, 3> closures {')', ']', '}'};
    DS::ContAdapter::Stack<char> expectedClosureStack;
    // iterate through the string
    for (auto character: inputString){
        unsigned result = findInOpenBracketsArray(character);        
        // if character is an opening bracket
        if (result != closures.size()){
            // push respective closing bracket to stack
            expectedClosureStack.push(closures.at(result));
        }

        // if character is a closing bracket
        else {
            // compare string[i] to last item from stack
            if (character != expectedClosureStack.top()) return false;
            // pop the last item from the stack
            expectedClosureStack.pop();
        }
    }
    
    // return true if no faults found
    return true;
}