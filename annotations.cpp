#include "annotations.h"

void TODO(std::string &comment){
    std::cout << comment << std::endl;
}

void IMPLEMENTATION_PENDING(std::string function_name, std::string comment){
    std::cout << "Implementation Pending:\n\t" 
                << function_name << ":\n\t" 
                << comment 
                << std::endl;
}

void IMPLEMENTATION_PROTOTYPE(std::string function_name, std::string comment){
    std::cout << "Function prototype created for testing porpuses, uncomplete implementation\n\t"
                << function_name << ":\n\t" 
                << comment 
                << std::endl;
}
