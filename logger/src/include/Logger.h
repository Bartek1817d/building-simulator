/*
 * Logger.h
 *
 *  Created on: 25-12-2018
 *      Author: Bartłomiej Płonka
 */

#ifndef LOGGER_H_
#define LOGGER_H_

#include "stdio.h"
#include <cstdarg>
#include <string>

using namespace std;

namespace logger {

	enum class Target {
		CONSOLE, FILE
	};

	enum class Level {
		INFO, DEBUG, ERROR, WARNING
	};

	class Logger {

		static constexpr const char * const INFO = "INFO";
		static constexpr const char * const DEBUG = "DEBUG";
		static constexpr const char * const ERROR = "ERROR";
		static constexpr const char * const WARNING = "WARNING";

		const string className;
		const Target target;
		FILE * outputFile;


	public:
		Logger(string className, Target target);
		virtual ~Logger();

		template <typename... Args> void info(string message, Args... args);
		template <typename... Args> void debug(string message, Args... args);
		template <typename... Args> void error(string message, Args... args);
		template <typename... Args> void warning(string message, Args... args);

	private:
		template <typename... Args> void log(Level level, string message, Args... args);
		void logToConsole(string message, ...);
		void logToFile(string message, ...);
		string prepareLogTemplate(Level level, string message);
		string levelToString(Level level);
		FILE * getOutputStream(Target target, Level level);
		FILE * determineConsoleStream(Level level);
		string currentStringTime();

	};

}

#include "../implementation/Logger.tpp"

#endif /* LOGGER_H_ */
