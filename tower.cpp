#include <fstream>
#include <iostream>
#include <string>

#include "S84.Tower.System.ctcode.hpp"
#include "S84.Tower.Main.ctcode.hpp"

char* ReadFileIntoBuffer(std::string file)
{
	std::ifstream file_stream(file.c_str(), std::ifstream::in | std::ifstream::binary);

	if (file_stream.bad())
	{
		return NULL;
	}

	file_stream.seekg(0, file_stream.end);
	int length = file_stream.tellg();

	if(length <= 0)
	{
		return NULL;
	}

	file_stream.seekg(0, file_stream.beg);
    char* buffer = new char[length + 1];
	const char* index = buffer;
    file_stream.read(buffer, length);
	buffer[length] = 0;
	return buffer;
}

class FileWriter : public s84::tower::system::ctcode::OutputStream {
public:
	FileWriter(std::string file_name) : destination(file_name, std::ofstream::trunc | std::ofstream::out) {}

    virtual void WriteLine(std::string line) {
		destination << line << std::endl;
	}

private:
	std::ofstream destination;
};

class LoggerClass : public s84::tower::system::ctcode::OutputStream
{
	void WriteLine(std::string line) {
		std::cout << line << std::endl;
	}
};

class System : public s84::tower::system::ctcode::System
{
public:
    std::string ReadFileToString(std::string file_name)
	{
		char* buffer = ReadFileIntoBuffer(file_name);
		std::string buffer_string = buffer ? std::string(buffer) : "";
		delete[] buffer;
		return buffer_string;
	}
    OmniPointer<s84::tower::system::ctcode::OutputStream> OpenFileWriter(std::string file_name)
	{
		return std::shared_ptr<s84::tower::system::ctcode::OutputStream>(new FileWriter(file_name));
	}
    OmniPointer<s84::tower::system::ctcode::OutputStream> GetLoggerDestination()
	{
		static OmniPointer<s84::tower::system::ctcode::OutputStream> logger =
			std::shared_ptr<s84::tower::system::ctcode::OutputStream>(new LoggerClass());
		return logger;
	}
};

int main(int argc, char* argv[])
{
	System system;
	s84::tower::main::ctcode::Main main;
	std::string dbnf_file_name;
	std::string generator_name;

	if (argc == 3)
	{
		dbnf_file_name = argv[1];
		generator_name = argv[2];
	}

	return main.RunMain(&system, dbnf_file_name, generator_name);
}

