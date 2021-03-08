#pragma once

#include <sys/types.h>
#include <unistd.h>

#define MAX_SIZE_INPUT_SHELL 60
#define FORK_FAILED(pid) (pid < 0) 
#define CHILD_PROCESS(pid) (pid == 0)
#define PARENT_PROCESS(pid) (pid != 0)

/*This struct will contain the final parsed command to be run in this first version of Rshell*/
typedef struct {
    char *binary;
    char *args[MAX_SIZE_INPUT_SHELL];
} Command;


class Shell{

private:
    bool m_shell_active {false};
    void quit_shell();
    void reset_command(Command *command);

public:
    Shell();
    ~Shell();
    int execute_command(Command *command);
    bool is_running();
};

