#include "Logger.h"

Logger Logger::instance_;
bool Logger::instantiated_ = false;

void Logger::log(string info)
{
	worker_.execute ([this, info]() {log_ << info << "\n"; });
}

void Logger::log(function<string()> f)
{
	worker_.execute ([this, f]() { log_ << f () << "\n"; });
}

Logger::~Logger()
{
}

