#pragma once
#include "Worker.h"
#include <assert.h>
#include <string>
#include<fstream>

using namespace std;

class Logger
{
	static Logger instance_;
	static bool instantiated_;
	Logger () {}

	Logger (Logger&) = delete;
	Logger& operator=(const Logger&) = delete;

public:

	inline static void initInstance (string filename) { if (!instantiated_) { instance_.log_.open (filename); instance_.worker_.start (); instantiated_ = true; } }
	inline static Logger* instance() { assert(instantiated_); return &instance_; }
	void log(string info);
	void log(function<string()> f);
	
	virtual ~Logger();

private:
	Worker worker_;
	ofstream log_;
};

