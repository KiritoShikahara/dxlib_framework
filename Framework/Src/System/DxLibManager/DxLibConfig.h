#pragma once

#include<string>

/// <summary>
/// DxLib初期化時の設定用構造体
/// </summary>
struct DxLibConfig
{
	// ウィンドウモードかどうか
	bool WindowMode = true;
	// ウィンドウの幅
	int WindowWidth = 1280;
	// ウィンドウの高さ
	int WindowHeight = 720;

	// ウィンドウのタイトル
	std::string WindowTitle = "DxLib Application";
	// フルスクリーンモードかどうか
	bool FullScreenMode = false;
	// VSyncを有効にするかどうか
	bool EnableVSync = true;
	// バックエンドでも実行するかどうか
	bool AlwaysRun = true;
};