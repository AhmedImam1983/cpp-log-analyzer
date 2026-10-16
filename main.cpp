#include "log_analyzer.hpp"

#include <iostream>
#include <string>

int main()
{
    const std::string logs =
        "INFO Application started\n"
        "WARNING Disk space is low\n"
        "ERROR Connection failed\n"
        "INFO Application stopped\n";

    const LogStats stats = analyzeLogs(logs);

    std::cout << "INFO: " << stats.info << '\n';
    std::cout << "WARNING: " << stats.warning << '\n';
    std::cout << "ERROR: " << stats.error << '\n';

    return 0;
}