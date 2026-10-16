#ifndef LOG_ANALYZER_HPP
#define LOG_ANALYZER_HPP

#include <string>

struct LogStats
{
    int info = 0;
    int warning = 0;
    int error = 0;
};

LogStats analyzeLogs(const std::string& text);

#endif
