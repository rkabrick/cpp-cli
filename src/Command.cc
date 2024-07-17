#include "Command.h"
#include <iostream>
#include <algorithm>

namespace MyCLI {

void CommandManager::register_command(std::shared_ptr<CommandBase> command) {
    commands_[command->name()] = std::move(command);
}

void CommandManager::run(int argc, char** argv) {
    std::vector<std::string> args(argv + 1, argv + argc);

    if (args.empty() || std::find(args.begin(), args.end(), "--help") != args.end()) {
        print_help();
        return;
    }

    for (const auto& [name, command] : commands_) {
        if (std::find(args.begin(), args.end(), name) != args.end()) {
            command->execute(args);
            return;
        }
    }

    std::cerr << "Unknown command or option.\n";
    print_help();
}

void CommandManager::print_help() {
    std::cout << "Usage: my-cli [command] [options]\n";
    std::cout << "Available commands:\n";
    for (const auto& [name, command] : commands_) {
        std::cout << "  " << name << " - " << command->description() << "\n";
    }
}

} // namespace MyCLI
