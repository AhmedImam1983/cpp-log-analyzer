#include "log_analyzer.hpp"

#include <cassert>
#include <iostream>
#include <string>

void testMixedLogs()
{
    const std::string logs =
        "INFO Started\n"
        "WARNING Low memory\n"
        "ERROR Failed\n"
        "INFO Stopped\n";

    const LogStats stats = analyzeLogs(logs);

    assert(stats.info == 2);
    assert(stats.warning == 1);
    assert(stats.error == 1);
}

void testEmptyLogs()
{
    const LogStats stats = analyzeLogs("");

    assert(stats.info == 0);
    assert(stats.warning == 0);
    assert(stats.error == 0);
}

void testInfoOnly()
{
    const LogStats stats = analyzeLogs(
        "INFO Started\n"
        "INFO Running\n"
    );

    assert(stats.info == 2);
    assert(stats.warning == 0);
    assert(stats.error == 0);
}

int main()
{
    testMixedLogs();
    testEmptyLogs();
    testInfoOnly();

    std::cout << "All tests passed!\n";
    return 0;
}