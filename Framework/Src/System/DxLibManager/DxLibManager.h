#pragma once

#include<Log/ErrorHandle/ErrorHandle.h>
#include"DxLibConfig.h"

class DxLibManager
{
public:
	virtual ~DxLibManager();

	/// <summary>
	/// 初期化
	/// </summary>
	/// <param name="config">設定</param>
	/// <returns></returns>
	ErrorHandle Initialize(const DxLibConfig& config);

	/// <summary>
	/// 終了処理
	/// </summary>
	void Finalize();

	/// <summary>
	/// 描画開始
	/// </summary>
	/// <returns></returns>
	bool BeginFrame();

	/// <summary>
	/// 描画終了
	/// </summary>
	void EndFrame();

	/// <summary>
	/// 初期化処理を行ったかどうか
	/// </summary>
	/// <returns></returns>
	bool IsInitialized() const noexcept;

private:
	bool mIsInitialized = false;
};

