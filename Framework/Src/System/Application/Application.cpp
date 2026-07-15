#include "pch.h"
#include "Application.h"

#include"../AppContext/AppContext.h"

ErrorHandle Application::Initialize(const ApplicationConfig& config)
{
	// エラーハンドル
	ErrorHandle eh;

	// 時間クラス
	mTime = std::make_unique<Time>();
	mTime->Initialize();

	// ループハンドラの設定
	if (config.gameLoopHandler == nullptr)
	{
		return ErrorHandle{
			1,
			"GameLoopHandler is null."
		};
	}
	mGameLoopHandler = config.gameLoopHandler;


	// DxLibの生成
	mDxLib = std::make_unique<DxLibManager>();
	eh = mDxLib->Initialize(config.DxLibConfig);
	if (EH_FAILED(eh))
	{
		return eh;
	}

	// 入力
	mInput = std::make_unique<InputManager>();

	// コンテキストへの追加
	AddToContext();

	return ErrorHandle{};
}

void Application::Run()
{
	if (mDxLib->IsInitialized() == false) return;

	while (mDxLib->BeginFrame() == true)
	{
		mTime->Update();
		mInput->Update();

		float dt = mTime->GetDeltaTime();
		float rawDt = mTime->GetRawDeltaTime();

		// ゲームループの各ステップを実行
		if (mGameLoopHandler != nullptr)
		{
			// 事前更新
			mGameLoopHandler->PreUpdate(dt, rawDt);
			// 固定ステップ
			while (mTime->AccumulateFixedStep())
			{
				mGameLoopHandler->FixedUpdate(mTime->GetFixedDeltaTime(), rawDt);
			}
			// メイン更新
			mGameLoopHandler->Update(dt, rawDt);

			// 事後更新
			mGameLoopHandler->PostUpdate(dt, rawDt);

			// 描画
			mGameLoopHandler->Render();
		}

		// 画面フリップ
		mDxLib->EndFrame();
	}
}

void Application::Finalize()
{
	if (mGameLoopHandler == nullptr)
	{
		mGameLoopHandler->Finalize();
	}

	mDxLib->Finalize();
	mDxLib.reset();

}

void Application::AddToContext()
{
	AppContext::Get()->Register(*mTime);
	AppContext::Get()->Register(*mInput);
}