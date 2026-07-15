#include "pch.h"
#include "DxLibManager.h"

#include<DxLib.h>


DxLibManager::~DxLibManager()
{
    Finalize();
}

ErrorHandle DxLibManager::Initialize(const DxLibConfig& config)
{
    SetWindowText(config.WindowTitle.c_str());
    ChangeWindowMode(config.WindowMode? TRUE : FALSE);
    SetGraphMode(config.WindowWidth, config.WindowHeight, 32);
    SetAlwaysRunFlag(config.AlwaysRun ? TRUE : FALSE);

    if (DxLib_Init() == -1)
    {
		return ErrorHandle{
			-1,
			"Failed to initialize DxLib."
		};
    }

	SetDrawScreen(DX_SCREEN_BACK);
    mIsInitialized = true;
	return ErrorHandle{};
}

void DxLibManager::Finalize()
{
	if (mIsInitialized)
	{
		DxLib_End();
		mIsInitialized = false;
	}
}

bool DxLibManager::BeginFrame()
{
    if (ProcessMessage() != 0) {
        return false;
    }
    if (ClearDrawScreen() != 0) {
        return false;
    }
    return true;
}

void DxLibManager::EndFrame()
{
    ScreenFlip();
}

bool DxLibManager::IsInitialized() const noexcept
{
    return mIsInitialized;
}