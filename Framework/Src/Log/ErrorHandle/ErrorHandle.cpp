#include"pch.h"
#include "ErrorHandle.h"

#include <iostream>
#include <string>

#ifdef _WIN32
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#endif

namespace Error
{
    void ShowErrorWindow(const ErrorHandle& error)
    {
        const std::string message =
            "Error Code: " + std::to_string(error.ErrorCode) +
            "\n\n" +
            "Message: " + error.ErrorMessage;

#ifdef _WIN32
        MessageBoxA(
            nullptr,
            message.c_str(),
            "Application Error",
            MB_OK | MB_ICONERROR
        );
#else
        std::cerr << message << std::endl;
#endif
    }
}