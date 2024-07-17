#include "Command.h"
#include "Commands/ExampleCommand.h"
#include <memory>

int main(int argc, char** argv) {
    MyCLI::CommandManager manager;

    // Register commands
    manager.register_command(std::make_shared<ExampleCommand>());

    manager.run(argc, argv);

    return 0;
}
