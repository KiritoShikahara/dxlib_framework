#pragma once

#include <string>

struct ErrorHandle
{
    int ErrorCode = 0;
    std::string ErrorMessage{};
};

namespace Error
{
    inline bool IsFailed(const ErrorHandle& error) noexcept
    {
        return error.ErrorCode != 0;
    }

    inline bool IsSuccess(const ErrorHandle& error) noexcept
    {
        return error.ErrorCode == 0;
    }

    void ShowErrorWindow(const ErrorHandle& error);
}

#ifdef FAILED
#undef FAILED
#endif

#ifdef SUCCESS
#undef SUCCESS
#endif

#define FAILED(errorHandle) \
    (::Error::IsFailed(errorHandle))

#define SUCCESS(errorHandle) \
    (::Error::IsSuccess(errorHandle))

#define SHOW_ERROR_WINDOW(errorHandle) \
    (::Error::ShowErrorWindow(errorHandle))