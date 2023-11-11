// CLASS LIBRARY
#include "libLog/include/AppLog.h"

AppLog::AppLog()
{
	AppLog::isLogSetup_ = false;
}

AppLog::~AppLog() {}

void AppLog::setup(
	const std::string &logFileStr,
	spdlog::level::level_enum loggingLevel,
	uint64_t file_size_MB, uint64_t num_files)
{
	std::lock_guard<std::mutex> lock(logMutex_);

	if (!AppLog::isLogSetup_)
	{
		/***************************/
		// Set up log file str and logging level
		/***************************/
		AppLog::logFileStr_ = logFileStr;
		AppLog::logLevel_ = loggingLevel;

		/***************************/
		// Set up dist sink
		/***************************/
		// configure so that each log message gets sent to all sinks.
		AppLog::distSink_ = std::make_shared<spdlog::sinks::dist_sink_mt>();

#if 1
		// console sink
		AppLog::distSink_->add_sink( std::make_shared<spdlog::sinks::stdout_color_sink_mt>() );
#else 
	   //older version
		AppLog::distSink_->add_sink(spdlog::sinks::stdout_sink_mt::instance());
#endif

		// all messages file sink.  <num_files> x <file_size_MB> MB rotating logs
		AppLog::distSink_->add_sink(
			std::make_shared<spdlog::sinks::rotating_file_sink_mt>(
				AppLog::logFileStr_.c_str(),
				1024 * 1024 * file_size_MB,
				num_files));
		/***************************/
		// Save set up boolean
		/***************************/
		AppLog::isLogSetup_ = true;
	}
	else
	{
		auto slh = AppLog::getInstance();
		auto logger = slh->getLogger(AppLog::defaultLogName_);
		logger->error("setup -> Set up already performed. This should only be done once. Nothing changed.");
	}
	return;
}

void AppLog::resetLogLevel(spdlog::level::level_enum loggingLevel)
{
	{
		std::lock_guard<std::mutex> lock(logMutex_);
		AppLog::logLevel_ = loggingLevel;
	}

	auto slh = AppLog::getInstance();
	auto logger = slh->getLogger(AppLog::defaultLogName_);
	logger->info(
		"resetLogLevel -> Logging level updated to {}",
		AppLog::logLevelStr[AppLog::logLevel_]);
}

std::shared_ptr<spdlog::logger> AppLog::getLogger(const std::string &logger_name)
{
	std::shared_ptr<spdlog::logger> logger = NULL;
	{
		std::lock_guard<std::mutex> lock(logMutex_);
		if (AppLog::isLogSetup_)
		{
			// Set up logging
			logger = spdlog::get(logger_name);
			if (logger == NULL)
			{
				spdlog::register_logger(std::make_shared<spdlog::logger>(logger_name, AppLog::distSink_));
				logger = spdlog::get(logger_name);
				logger->flush_on(spdlog::level::err);

				std::string log_level_str = AppLog::logLevelStr[logLevel_];

				logger->set_level(logLevel_);

				logger->trace(
					"AppLog::getLogger -> Set {} logging level to {}",
					logger_name, log_level_str);
			}
		}
	}
	return logger;
}

/*
 * Static methods and variable should be defined outside the class.
 */
bool AppLog::isLogSetup_ = false;
const std::string AppLog::defaultLogName_ = "AppLog";
std::string AppLog::logFileStr_;
spdlog::level::level_enum AppLog::logLevel_ = spdlog::level::info;
std::shared_ptr<spdlog::sinks::dist_sink_mt> AppLog::distSink_{nullptr};
AppLog *AppLog::logInstance_{nullptr};
std::mutex AppLog::logMutex_;

/**
 * The first time we call getInstance we will lock the storage location
 *      and then we make sure again that the variable is null and then we
 *      set the logFileStr. RU:
 */
AppLog *AppLog::getInstance()
{
	std::lock_guard<std::mutex> lock(logMutex_);
	if (logInstance_ == nullptr)
	{
		logInstance_ = new AppLog();
	}
	return logInstance_;
}


//--------------- global funcs -------------------
void setupAppLogger(const std::string &logger_file_path, const std::string &logger_name, const int logger_level)
{
	g_log_default_name = logger_name;

	// todo: check existence and make logging_directory

	spdlog::level::level_enum logLevel;
	if (logger_level < (int)spdlog::level::trace)
		logLevel = spdlog::level::trace;
	else if (logger_level > (int)spdlog::level::off)
		logLevel = spdlog::level::off;
	else
		logLevel = (spdlog::level::level_enum)logger_level;

	// Get instance of AppLog and create the dist sink
	auto slh = AppLog::getInstance();
	uint64_t file_size_MB = 1000, num_files = 50;
	slh->setup(logger_file_path, logLevel, file_size_MB, num_files);

	std::shared_ptr<spdlog::logger> logger = slh->getLogger(logger_name);
	logger->set_level(logLevel);
	logger->flush_on(logLevel);

	// spdlog::set_pattern("[source %s] [function %!] [line %#] %v");

	logger->info("==== start log :{} =====", logger_file_path);
	logger->info("Setting {} logging level to {}", logger->name(), logLevel);
}

#include <stdarg.h>
static char g_log_buffer[1024];
std::string g_log_default_name = "app";
#define LOG_PARSE_ARGS                            \
	{                                             \
		va_list args;                             \
		va_start(args, fmt);                      \
		vsnprintf(g_log_buffer, 1024, fmt, args); \
		va_end(args);                             \
	}

void appLog(const char *fmt, ...)
{
	LOG_PARSE_ARGS
	spdlog::get(g_log_default_name)->info(g_log_buffer);
}

void appInfo(const char *fmt, ...)
{
	LOG_PARSE_ARGS
	spdlog::get(g_log_default_name)->info(g_log_buffer);
}

void appDebug(const char *fmt, ...)
{
	LOG_PARSE_ARGS
	spdlog::get(g_log_default_name)->debug(g_log_buffer);
}

void appAssert(const bool flag2Check, const char *fmt, ...)
{
	LOG_PARSE_ARGS
	if (!flag2Check)
	{
		spdlog::get(g_log_default_name)->error(g_log_buffer);
		spdlog::get(g_log_default_name)->flush();
	}
}

void appErr(const char *fmt, ...)
{
	LOG_PARSE_ARGS
	spdlog::get(g_log_default_name)->error(g_log_buffer);
	spdlog::get(g_log_default_name)->flush();
}

// instead of using err, I some people like write error. It's fine also
void appError(const char *fmt, ...)
{
	LOG_PARSE_ARGS
	spdlog::get(g_log_default_name)->error(g_log_buffer);
	spdlog::get(g_log_default_name)->flush();
}

void appLog2(const std::string &keyword, const char *fmt, ...)
{
	auto slh = AppLog::getInstance();
	std::shared_ptr<spdlog::logger> logger = slh->getLogger(keyword);
	if (logger)
	{
		LOG_PARSE_ARGS
		logger->info(g_log_buffer);
		logger->flush();
	}
}

void appInfo2(const std::string &keyword, const char *fmt, ...)
{
	auto slh = AppLog::getInstance();
	std::shared_ptr<spdlog::logger> logger = slh->getLogger(keyword);
	if (logger)
	{
		LOG_PARSE_ARGS
		logger->info(g_log_buffer);
		logger->flush();
	}
}

void appErr2(const std::string &keyword, const char *fmt, ...)
{
	auto slh = AppLog::getInstance();
	std::shared_ptr<spdlog::logger> logger = slh->getLogger(keyword);
	if (logger)
	{
		LOG_PARSE_ARGS
		logger->error(g_log_buffer);
		logger->flush();
	}
}

// instead of using err, I some people like write error. It's fine also
void appError2(const std::string &keyword, const char *fmt, ...)
{
	auto slh = AppLog::getInstance();
	std::shared_ptr<spdlog::logger> logger = slh->getLogger(keyword);
	if (logger)
	{
		LOG_PARSE_ARGS
		logger->error(g_log_buffer);
		logger->flush();
	}
}

void appDebug2(const std::string &keyword, const char *fmt, ...)
{
	auto slh = AppLog::getInstance();
	std::shared_ptr<spdlog::logger> logger = slh->getLogger(keyword);
	if (logger)
	{
		LOG_PARSE_ARGS
		logger->debug(g_log_buffer);
		logger->flush();
	}
}

void appAssert2(const bool flag2Check, const std::string &keyword, const char *fmt, ...)
{
	auto slh = AppLog::getInstance();
	std::shared_ptr<spdlog::logger> logger = slh->getLogger(keyword);
	if (logger)
	{
		LOG_PARSE_ARGS
		logger->error(g_log_buffer);
		logger->flush();
	}
}
