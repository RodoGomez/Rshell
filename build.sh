#!/bin/bash

rm rshell
g++ -std=c++17 main.cpp Shell.cpp Parser.cpp -o rshell 

