// CfgExe.h
#pragma once

#include <mutex>

class CfgExe {
public:
    // Constructor
    // Initializes m_isInit to the provided value (default is false)
    CfgExe(bool isInit = false, bool makeLog = true);

    // Destructor
    ~CfgExe();

    // Getter for m_isInit
    // Returns the current value of m_isInit in a thread-safe manner
    bool isInit() const;
    bool makeLog() const;

    // Setter for m_isInit
    // Sets the value of m_isInit in a thread-safe manner
    void setInit(bool init);
    void setMakeLog(bool flag);

    // Set program name
    void setProgName(const std::string& name);
    void setProgId();
    void setProgGuid();

    std::string getProgName() const;
    int getProgId();
    std::string getProgGuid() const;

    void generateLogPath( const std::string &logDir );

    virtual std::string disp() const
    {
    }

    virtual std::string toString() const
    {       
    }

public:
    static int          m_logLevel;      

protected:
    std::string m_logDir{"./"};          // log dir
    bool m_isInit{false};                // Indicates whether initialization has occurred
    bool m_makeLog{false};

    uint32_t    m_progId;                   // Auto-generated unique program ID
    std::string m_progGuid;         // Auto-generated unique GUID
    std::string m_progName;         // Program name, modifiable at runtime
    std::string m_logPath;         // Program name, modifiable at runtime
    mutable std::mutex m_mutex;   // Mutex to protect access to m_isInit
};
typedef std::shared_ptr<CfgExe> CfgExePtrS;
