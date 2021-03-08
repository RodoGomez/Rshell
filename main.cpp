#include "Shell.h"
#include "Parser.h"

void init_command(Command &command);

int main(){

    Shell shell;
    Command command;    
    Parser parser;
    
    int exec_return_status {};
    std::string shell_input {};

    while(shell.is_running()){
        std::getline(std::cin, shell_input); 
        parser.parse_shell_input(shell_input, command);
        exec_return_status = shell.execute_command(&command);
    }
    return exec_return_status;
}

void init_command(Command &command){
    command.binary = nullptr;
    command.args[0] = nullptr;
    command.args[1] = nullptr;
}

