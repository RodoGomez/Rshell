#pragma once
#include <iostream>
/*
 * This file contains a set of functions providing annotations such as:
 *      * TODO tasks.
 *      * TO_CHECK
 *      * IMPLEMENTATION_PENDING
 *      * IMPLEMENTATION_INCOMPLETE
*/



void TODO(std::string comment);
void IMPLEMENTATION_PENDING(std::string function_name, std::string comment);
void IMPLEMENTATION_PROTOTYPE(std::string function_name, std::string comment);
