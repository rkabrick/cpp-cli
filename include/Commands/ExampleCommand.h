#include "CommandBase.h"
#include <iostream>

class ExampleCommand : public MyCLI::CommandBase {
public:
    void configure(std::vector<std::pair<std::string, std::string>>& options) override {
        options.push_back({"-v", "--verbose"});
    }

    void execute(const std::vector<std::string>& args) override {
        bool verbose = std::find(args.begin(), args.end(), "-v") != args.end() ||
                       std::find(args.begin(), args.end(), "--verbose") != args.end();

        if (verbose) {
            std::cout << "Example command executed with verbosity!\n";
        } else {
            std::cout << "Example command executed.\n";
        }
    }

    std::string name() const override {
        return "example";
    }

    std::string description() const override {
        return "description of the command";
    }
};
