#include "log_analyzer.hpp"

#include <sstream>

LogStats analyzeLogs(const std::string& text)
{
    LogStats stats;
    std::istringstream input(text);
    std::string line;

    while (std::getline(input, line))
    {
        if (line.find("INFO") != std::string::npos)
            ++stats.info;
        else if (line.find("WARNING") != std::string::npos)
            ++stats.warning;
        else if (line.find("ERROR") != std::string::npos)
            ++stats.error;
    }

    return stats;
}
