// Command.h
#pragma once
#include "CommandBase.h"
#include <memory>
#include <string>
#include <unordered_map>
#include <vector>

namespace MyCLI {

class CommandManager {
public:
    void register_command(std::shared_ptr<CommandBase> command);
    void run(int argc, char** argv);

private:
    std::unordered_map<std::string, std::shared_ptr<CommandBase>> commands_;
    void print_help();
};

} // namespace MyCLI
