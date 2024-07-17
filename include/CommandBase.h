#pragma once
#include <string>
#include <vector>

namespace MyCLI {

class CommandBase {
public:
    virtual ~CommandBase() = default;
    virtual void configure(std::vector<std::pair<std::string, std::string>>& options) = 0;
    virtual void execute(const std::vector<std::string>& args) = 0;
    virtual std::string name() const = 0;
    virtual std::string description() const = 0;
};

} // namespace MyCLI
