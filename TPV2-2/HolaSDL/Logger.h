#pragma once
#include "Worker.h"
#include <assert.h>
#include <string>
#include<fstream>

using namespace std;

class Logger
{
	static Logger* instance_;

	Logger();

public:

	inline static void initInstance(string filename) { if (instance_ == nullptr) { instance_ = new Logger(); instance_->log_.open(filename); instance_->worker_.start(); } }
	inline static Logger* instance() { assert(instance_ != nullptr); return instance_; }
	void log(string info);
	void log(function<string()> f);
	
	virtual ~Logger();

private:
	Worker worker_;
	ofstream log_;
};

