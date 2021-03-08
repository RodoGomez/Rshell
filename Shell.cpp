#include "Shell.h"
#include <iostream>
#include <stdio.h>


Shell::Shell()
    : m_shell_active{true}
{
}


Shell::~Shell(){
}

int Shell::execute_command(Command *command){

    int exec_status {}; 

    pid_t pid;
    pid = fork();

    if(FORK_FAILED(pid)){
        perror("fork.");
        exit(1);
    }
    else if(CHILD_PROCESS(pid)){
        exec_status = execvp(command->binary, command->args);
        if(exec_status == -1)
            perror("execvp");
    }
    else if(PARENT_PROCESS(pid)){
    }
    else{
        perror("Unkown pid state");
    }
    
    reset_command(command);
    return exec_status; 
}   

bool Shell::is_running(){
    return m_shell_active;
}

void Shell::reset_command(Command *command){
    if(command->binary != nullptr){
        free(command->binary);
        command->binary = nullptr;
    }
    
    if(command->args[0] != nullptr){
        int i {}; 
        while(command->args[i] != NULL){
            free(command->args[i]);
            command->args[i] = nullptr;
            ++i;
        }
    }
}

void Shell::quit_shell(){
    m_shell_active = false;
}

