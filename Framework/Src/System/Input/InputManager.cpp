#include "pch.h"
#include "InputManager.h"
#include <DxLib.h>

void InputManager::BindKey(const std::string& actionName, Key key) {
    mBindings[actionName].Keys.push_back(key);
}

void InputManager::BindMouseButton(const std::string& actionName, MouseButton button) {
    mBindings[actionName].MouseButtons.push_back(button);
}

void InputManager::BindPadButton(const std::string& actionName, PadButton button) {
    mBindings[actionName].PadButtons.push_back(button);
}

void InputManager::Update() {
    // 各デバイスの最新の生入力を取得
    char keyStates[256];
    GetHitKeyStateAll(keyStates);

    int mouseState = GetMouseInput();
    GetMousePoint(&mMouseX, &mMouseY);
    mMouseWheel = GetMouseWheelRotVol(); // マウスホイールの回転量

    int padState = GetJoypadInputState(DX_INPUT_PAD1);

    // 2. 登録されているすべてのアクションについて、現在のフレームの入力状態を判定
    for (auto& [actionName, binding] : mBindings) {
        ActionState& state = mActionStates[actionName];

        // 前フレームの状態を退避
        state.Previous = state.Current;
        state.Current = false;

        // A. キーボード入力のチェック
        for (auto key : binding.Keys) {
            if (keyStates[static_cast<int>(key)] == 1) {
                state.Current = true;
                break;
            }
        }

        // B. マウス入力のチェック（まだ押されていなければ）
        if (!state.Current) {
            for (auto btn : binding.MouseButtons) {
                if ((mouseState & static_cast<int>(btn)) != 0) {
                    state.Current = true;
                    break;
                }
            }
        }

        // C. ゲームパッド入力のチェック（まだ押されていなければ）
        if (!state.Current) {
            for (auto btn : binding.PadButtons) {
                if ((padState & static_cast<int>(btn)) != 0) {
                    state.Current = true;
                    break;
                }
            }
        }
    }
}

bool InputManager::IsPress(const std::string& actionName) const {
    auto it = mActionStates.find(actionName);
    if (it == mActionStates.end()) return false;
    return it->second.Current;
}

bool InputManager::IsTrigger(const std::string& actionName) const {
    auto it = mActionStates.find(actionName);
    if (it == mActionStates.end()) return false;
    return it->second.Current && !it->second.Previous;
}

bool InputManager::IsRelease(const std::string& actionName) const {
    auto it = mActionStates.find(actionName);
    if (it == mActionStates.end()) return false;
    return !it->second.Current && it->second.Previous;
}