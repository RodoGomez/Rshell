#include "Parser.h"


Parser::Parser()
    : m_utility{}, m_args{}, m_parsing_arg_found {false}, m_args_found {}, m_parsed_argument {}
{
}

Parser::~Parser(){
}

/*
 * Brief: In this initial and minimal shell, this will be the first way to parse the input from the user
 * It will parse the command and set the final values to the struct command.
*/
void Parser::parse_shell_input(const std::string &raw_input, Command &command){
    
    for(auto current_char : raw_input){
        if(white_space(current_char) && m_parsing_arg_found){
            add_parsed_arg_to_vector();
        }
        else if(white_space(current_char) && !m_parsing_arg_found){
            continue;
        }
        else if(character_found(current_char)){
            m_parsing_arg_found = true;
            m_parsed_argument += current_char;
        }
        else{
            std::cout << "unknown character" << std::endl;
        }
    }

    if(m_parsing_arg_found){
        add_parsed_arg_to_vector();
    }
    
    fill_command_struct(command); 
    parsing_finished();
}

bool Parser::white_space(char current_char){
    return ((current_char == ' ') || (current_char == '\t'));
}

bool Parser::character_found(char current_char){
    return (current_char) != ' ';
}

void Parser::parsing_finished(void){
    m_args = {};
    m_args_found = 0;
}

void Parser::add_parsed_arg_to_vector(void){
    m_args.push_back(m_parsed_argument);
    m_parsed_argument = {};
    m_parsing_arg_found = false;
    ++m_args_found;   
}

bool Parser::empty_input_from_user(void){
    return (m_args_found == 0);
}

bool Parser::only_bin_name_was_provided(void){
    return (m_args_found == 1);
}

void Parser::fill_command_struct(Command &command){

    if(empty_input_from_user()){
        command.binary = nullptr;
        command.args[0] = nullptr;
    }
    else{
        set_bin_command(command); 
        set_command_args(command);
    }
}


void Parser::set_bin_command(Command &command){
    command.binary = (char*)malloc(m_args[0].size() + 1);
    if(!command.binary){
        perror("malloc failed.!");
        exit(1);
    }
    std::strcpy(command.binary, m_args[0].c_str());  
}

void Parser::set_command_args(Command &command){
    command.args[0] = (char*)malloc(m_args[0].size() + 1);
    if(!command.args[0]){
        perror("malloc failed.!");
        exit(1);
    }
    std::strcpy(command.args[0], m_args[0].c_str());

    if(m_args_found > 1){
        for(int i {1}; i < m_args_found; ++i){
            command.args[i] = (char*)malloc( m_args[i].size() + 1);
            if(!command.args[i]){
                perror("malloc failed.!");
                exit(1);
            }
            std::strcpy(command.args[i], m_args[i].c_str());
        }
    }    
    command.args[m_args_found] = NULL;      // This looks wired but it's only adding NULL as the last of the args in command (see API for execvp)
}

