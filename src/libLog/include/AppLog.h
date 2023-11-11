#pragma once

#include "spdlog/spdlog.h"
#include "spdlog/sinks/dist_sink.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/sinks/rotating_file_sink.h"

#define APP_STRING(var)	#var

//define <m_logger> and <m_logname> in your application class header
#define ADD_SPD_LOG(logName)             					\
		std::string	m_logname{APP_STRING(logName)};			\
		std::shared_ptr<spdlog::logger> m_logger{nullptr};	

//create <m_Logger> in your application constructor
#define GET_SPD_LOG				                \
    auto slh = AppLog::getInstance();			\
	m_logger = slh->getLogger( m_logname );     \
    if (!m_logger) {                            \
        printf("error");                        \
    }


class AppLog
{
private:
	static AppLog* logInstance_;
	static std::mutex logMutex_;

protected:
	AppLog();
	~AppLog();

	static bool isLogSetup_;
	static const std::string defaultLogName_;
	static std::string logFileStr_;
	static spdlog::level::level_enum logLevel_;
	static std::shared_ptr<spdlog::sinks::dist_sink_mt> distSink_;

public:
	AppLog(AppLog& other) = delete;
	void operator=(const AppLog&) = delete;

	static AppLog* getInstance();

	void setup(
		const std::string& logFileStr, spdlog::level::level_enum loggingLevel,
		uint64_t file_size_MB, uint64_t num_files);

	void resetLogLevel(spdlog::level::level_enum loggingLevel);

	inline std::string getLogFileStr() const 
	{ 
		std::string ret;
		{
			std::lock_guard<std::mutex> lock(logMutex_);
			ret =  AppLog::logFileStr_; 
		}
		return ret;
	}

	inline std::string getDefaultLogName() const 
	{ 
		std::string ret;
		{
			std::lock_guard<std::mutex> lock(logMutex_);
			ret =  AppLog::defaultLogName_; 
		}
		return ret;
	}
	
	const static inline std::vector<std::string> logLevelStr={"trace", "debug", "info", "warn", "err","off"};
	std::shared_ptr<spdlog::logger> getLogger(const std::string &logger_name);
};

//
//  the following are the global UI functions about our log
//  see logUsageExamples() for more details
//
extern std::string g_log_default_name;
//logger_level: [0,6], 0 - logged most messages, 6- looge lessest messages
void setupAppLogger(const std::string& logger_file_path, const std::string& logger_name= g_log_default_name, const int logger_level= (int)spdlog::level::debug);
//printf() style with default keyword: < g_log_default_name>
void appLog(const char* fmt, ...);
void appInfo(const char* fmt, ...);
void appErr(const char* fmt, ...);
void appError(const char* fmt, ...);
void appDebug(const char* fmt, ...);
void appAssert(const bool flag2Check, const char* fmt, ...);

//printf() style with any keyword 
void appLog2(const std::string& keyword, const char* fmt, ...);
void appInfo2(const std::string& keyword, const char* fmt, ...);
void appErr2(const std::string& keyword, const char* fmt, ...);
void appError2(const std::string& keyword, const char* fmt, ...);
void appDebug2(const std::string& keyword, const char* fmt, ...);
void appAssert2(const bool flag2Check, const std::string& keyword, const char* fmt, ...);


//todo: define some macros to log file, function names and line #
// 
//----------------eof------------