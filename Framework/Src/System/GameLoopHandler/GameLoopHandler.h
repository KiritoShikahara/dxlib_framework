#pragma once

/// <summary>
/// ゲームループハンドラのインターフェース
/// </summary>
class IGameLoopHandler {
public:
    virtual ~IGameLoopHandler() = default;

    // 初期化
    virtual bool Initialize() = 0;
    // 終了処理
    virtual bool Finalize() = 0;

    // 事前更新（リソース読み込みなど）
    virtual void PreUpdate(float deltaTime,float rawDeltaTime) {}

    // メイン更新（ゲームロジックなど）
    virtual void Update(float deltaTime, float rawDeltaTime) {}

    // 事後更新（クリーンアップなど）
    virtual void PostUpdate(float deltaTime, float rawDeltaTime) {}

    // 固定ステップループ用の更新（物理演算など）
    virtual void FixedUpdate(float fixedDeltaTime, float rawDeltaTime) {}

    // 描画処理（Render）
    virtual void Render() {}

};