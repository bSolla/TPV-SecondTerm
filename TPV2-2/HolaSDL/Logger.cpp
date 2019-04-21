#include "Logger.h"



Logger::Logger()
{
}

// TODO: -----------------------------------

void Logger::log(string info)
{
	worker_.execute([info]() {});
}

void Logger::log(function<string()> f)
{
}

Logger::~Logger()
{
}
