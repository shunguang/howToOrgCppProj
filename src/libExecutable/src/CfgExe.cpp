// CfgExe.cpp
#include "libExecutable/include/CfgExe.h"

int CfgExe::m_logLevel =  1;

// Constructor
CfgExe::CfgExe(bool isInit,bool makeLog)
    : m_isInit(isInit)
    , m_makeLog(makeLog)
{
    // Additional initialization code can be added here if needed
}

// Destructor
CfgExe::~CfgExe()
{
    // Cleanup resources if needed
}

// Getter for m_isInit
bool CfgExe::isInit() const
{
    std::lock_guard<std::mutex> lock(m_mutex);
    return m_isInit;
}

// Setter for m_isInit
void CfgExe::setInit(bool init)
{
    std::lock_guard<std::mutex> lock(m_mutex);
    m_isInit = init;
}

bool CfgExe::makeLog() const
{
   std::lock_guard<std::mutex> lock(m_mutex);
   return m_makeLog;
}

void CfgExe::setMakeLog(bool flag)
{
    std::lock_guard<std::mutex> lock(m_mutex);
    m_makeLog = flag;
}


// Set program name
void CfgExe::setProgName(const std::string& name) {
    std::lock_guard<std::mutex> lock(mutex_);
    m_progName = name;
}

// Getter methods
int CfgExe::getProgId() const {
    return m_progId;
}

std::string CfgExe::getProgGuid() const {
    return m_progGuid;
}

std::string CfgExe::getProgName() const { 
    std::lock_guard<std::mutex> lock(mutex_);
    return m_progName; 
}

void CfgExe::generateLogPath( const std::string &logDir )
{
    std::lock_guard<std::mutex> lock(mutex_);
    m_logPath = logDir + "/log-" +  m_progName + ".txt";
}

// Initialize static counter for program IDs
// Generate GUID
std::string CfgExe::generateGuid() {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::uniform_int_distribution<int> dist(0, 15);

    std::stringstream ss;
    ss << std::hex << std::uppercase;
    for (int i = 0; i < 8; i++) ss << dist(gen);
    ss << "-";
    for (int i = 0; i < 4; i++) ss << dist(gen);
    ss << "-4"; // Version 4 UUID
    for (int i = 0; i < 3; i++) ss << dist(gen);
    ss << "-";
    ss << (dist(gen) & 0x3 | 0x8); // Variant
    for (int i = 0; i < 3; i++) ss << dist(gen);
    ss << "-";
    for (int i = 0; i < 12; i++) ss << dist(gen);
    return ss.str();
}
