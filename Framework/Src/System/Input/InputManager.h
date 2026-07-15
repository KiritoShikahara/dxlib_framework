#pragma once
#include <string>
#include <unordered_map>
#include <vector>
#include "InputCode.h"

class InputManager {
private:
    // アクションごとの入力状態
    struct ActionState {
        bool Current = false;  // 今フレーム押されているか
        bool Previous = false; // 前フレーム押されていたか
    };

    // 1つのアクションに、複数のデバイスのキーを割り当てられる構造体
    struct ActionBinding {
        std::vector<Key> Keys;
        std::vector<MouseButton> MouseButtons;
        std::vector<PadButton> PadButtons;
    };

    // 各種データ格納用のコンテナ
    std::unordered_map<std::string, ActionState> mActionStates;
    std::unordered_map<std::string, ActionBinding> mBindings;

    // マウスの座標情報
    int mMouseX = 0;
    int mMouseY = 0;
    int mMouseWheel = 0;

public:
    InputManager() = default;
    ~InputManager() = default;

    // 毎フレーム呼び出し（入力状態の更新）
    void Update();

    // アクションの動的バインド
    void BindKey(const std::string& actionName, Key key);
    void BindMouseButton(const std::string& actionName, MouseButton button);
    void BindPadButton(const std::string& actionName, PadButton button);

    // 入力判定関数
    bool IsPress(const std::string& actionName) const;   // 押しっぱなし
    bool IsTrigger(const std::string& actionName) const; // 押した瞬間
    bool IsRelease(const std::string& actionName) const; // 離した瞬間

    // マウス専用の拡張機能
    int GetMouseX() const { return mMouseX; }
    int GetMouseY() const { return mMouseY; }
    int GetMouseWheel() const { return mMouseWheel; }
};