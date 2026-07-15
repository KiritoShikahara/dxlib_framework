#pragma once

// Utility
#include<Utility/Singleton/Singleton.h>
#include<Log/ErrorHandle/ErrorHandle.h>

// System
#include"../GameLoopHandler/GameLoopHandler.h"
#include"../Time/Time.h"
#include"../Input/InputManager.h"

// Dxlib
#include"../DxLibManager/DxLibManager.h"
#include"../DxLibManager/DxLibConfig.h"

struct ApplicationConfig
{
	// ゲームループハンドラ
	IGameLoopHandler* gameLoopHandler = nullptr;
	// DxLibの設定
	DxLibConfig DxLibConfig;
};

class Application : public SingletonPtr<Application>
{
	SINGLETON_PTR_CLASS(Application);
public:
	SINGLETON_PTR_ACCESSOR(Application);

	/// <summary>
	/// 初期化
	/// </summary>
	/// <returns></returns>
	ErrorHandle Initialize(const ApplicationConfig& config);

	/// <summary>
	/// メインループを実行する
	/// ハンドラーを継承した自身のクラスを渡すことで、Update, FixedUpdate, Drawが呼ばれる
	/// </summary>
	void Run();

	/// <summary>
	/// 終了処理
	/// </summary>
	void Finalize();

private:
	/// <summary>
	/// コンテキストに追加する
	/// </summary>
	void AddToContext();
private:
	// タイム管理のクラス
	std::unique_ptr<Time> mTime;

	// DxLib管理
	std::unique_ptr<DxLibManager> mDxLib;

	// 入力管理
	std::unique_ptr<InputManager> mInput;

	// ゲームループハンドラ
	IGameLoopHandler* mGameLoopHandler = nullptr;
};

