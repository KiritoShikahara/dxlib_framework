#pragma once
#include <DxLib.h>

// キーボード用
enum class Key : int {
    A = KEY_INPUT_A, B = KEY_INPUT_B, C = KEY_INPUT_C, D = KEY_INPUT_D,
    E = KEY_INPUT_E, F = KEY_INPUT_F, G = KEY_INPUT_G, H = KEY_INPUT_H,
    I = KEY_INPUT_I, J = KEY_INPUT_J, K = KEY_INPUT_K, L = KEY_INPUT_L,
    M = KEY_INPUT_M, N = KEY_INPUT_N, O = KEY_INPUT_O, P = KEY_INPUT_P,
    Q = KEY_INPUT_Q, R = KEY_INPUT_R, S = KEY_INPUT_S, T = KEY_INPUT_T,
    U = KEY_INPUT_U, V = KEY_INPUT_V, W = KEY_INPUT_W, X = KEY_INPUT_X,
    Y = KEY_INPUT_Y, Z = KEY_INPUT_Z,

    Up = KEY_INPUT_UP,
    Down = KEY_INPUT_DOWN,
    Left = KEY_INPUT_LEFT,
    Right = KEY_INPUT_RIGHT,

    Space = KEY_INPUT_SPACE,
    Enter = KEY_INPUT_RETURN,
    Escape = KEY_INPUT_ESCAPE,
    LShift = KEY_INPUT_LSHIFT,
    RShift = KEY_INPUT_RSHIFT,
};

// マウスボタン用
enum class MouseButton : int {
    Left = MOUSE_INPUT_LEFT,
    Right = MOUSE_INPUT_RIGHT,
    Middle = MOUSE_INPUT_MIDDLE,
};

// ゲームパッド用 (デジタル入力)
enum class PadButton : int {
    Up = PAD_INPUT_UP,
    Down = PAD_INPUT_DOWN,
    Left = PAD_INPUT_LEFT,
    Right = PAD_INPUT_RIGHT,
    Btn1 = PAD_INPUT_1,  // 一般的な決定 / Aボタン相当
    Btn2 = PAD_INPUT_2,  // 一般的なキャンセル / Bボタン相当
    Btn3 = PAD_INPUT_3,
    Btn4 = PAD_INPUT_4,
    LeftTrigger = PAD_INPUT_5,  // L1 / LB 相当
    RightTrigger = PAD_INPUT_6,  // R1 / RB 相当
    Select = PAD_INPUT_9,
    Start = PAD_INPUT_10,
};