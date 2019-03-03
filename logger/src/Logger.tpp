/*
 * Logger.cpp
 *
 *  Created on: 25-12-2018
 *      Author: Bartłomiej Płonka
 */

using namespace logger;

Logger::Logger(string className, Target target): 	className(className),
													target(target){
	if (target == Target::FILE)
		outputFile = fopen(className.c_str(), "a");
}

Logger::~Logger() {
	if (outputFile != NULL)
		fclose(outputFile);
}

template <typename... Args>
void Logger::info(string message, Args... args) {
	log(Level::INFO, message, args...);
}

template <typename... Args>
void Logger::debug(string message, Args... args) {
	log(Level::DEBUG, message, args...);
}

template <typename... Args>
void Logger::error(string message, Args... args) {
	log(Level::ERROR, message, args...);
}

template <typename... Args>
void Logger::warning(string message, Args... args) {
	log(Level::WARNING, message, args...);
}

template <typename... Args>
void Logger::log(Level level, string message, Args... args) {
	string logTemplate = prepareLogTemplate(level, message);
	FILE * out = getOutputStream(target, level);
	fprintf(out, logTemplate.c_str(), args...);
}

FILE * Logger::getOutputStream(Target target, Level level) {
	switch(target) {
	case Target::FILE:
		return outputFile;
	case Target::CONSOLE:
		return determineConsoleStream(level);
	default:
		return NULL;
	}
}

FILE * Logger::determineConsoleStream(Level level) {
	switch(level) {
	case Level::ERROR:
		return stderr;
	default:
		return stdout;
	}
}

string Logger::prepareLogTemplate(Level level, string message) {
	return levelToString(level) + "::" + currentStringTime() + "::" + className + "::" + message + "\n";
}

string Logger::levelToString(Level level) {
	switch(level) {
	case Level::INFO:
		return INFO;
	case Level::DEBUG:
		return DEBUG;
	case Level::ERROR:
		return ERROR;
	case Level::WARNING:
		return WARNING;
	default:
		return NULL;
	}
}

string Logger::currentStringTime() {
	time_t now;
	time(&now);
	char buf[21];
	strftime(buf, sizeof buf, "%FT%TZ", gmtime(&now));
	return buf;
}

