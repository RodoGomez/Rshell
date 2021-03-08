#pragma once

#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include "Shell.h"
#include <stdlib.h>

class Parser{
private:
    std::string m_utility {};
    std::vector<std::string> m_args {};
    bool m_parsing_arg_found {false};
    int m_args_found {};
    std::string m_parsed_argument {};

    bool white_space(char current_char);
    bool character_found(char current_char);
    void parsing_finished(void);
    void add_parsed_arg_to_vector(void);
    void fill_command_struct(Command &command);
    bool empty_input_from_user(void);
    bool only_bin_name_was_provided(void);
    void set_bin_command(Command &command);
    void set_command_args(Command &command);

public:

    Parser();
    ~Parser();
    void parse_shell_input(const std::string &raw_input, Command &command);
};
