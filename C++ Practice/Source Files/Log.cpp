//
//  Log.cpp
//  C++ Practice
//
//  Created by Branden Arms on 10/24/22.
//
#include <iostream>
#include "Log.h"

class Log
{
public: // Public members
    enum Level : unsigned char
    {
        LevelError = 0, LevelWarning, LevelInfo
    };
private: // Private members
    Level m_logLevel = LevelInfo;
    
public: // Public methods
    void SetLevel(Level level)
    {
        m_logLevel = level;
    }
    
    void Error(const char* message)
    {
        if (m_logLevel >= Level::LevelError)
            std::cout << "[ERROR]: " << message << std::endl;
    }
    
    void Warn(const char* message)
    {
        if (m_logLevel >= Level::LevelWarning)
            std::cout << "[WARNING]: " << message << std::endl;
    }
    
    void Info(const char* message)
    {
        if (m_logLevel >= Level::LevelInfo)
            std::cout << "[INFO]: " << message << std::endl;
    }
};
/*
 int main()
 {
 class Log log;
 log.SetLevel(Log::LevelWarning);
 log.Warn("Hello");
 log.Error("Hello");
 log.Info("Hello");
 std::cin.get();
 }
 */
