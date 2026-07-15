#pragma once

#include <memory>
#include <utility>

template <typename T>
class SingletonPtr {
private:
    // T のデストラクタが private でも破棄できるようにする
    struct Deleter {
        void operator()(T* ptr) const noexcept {
            delete ptr;
        }
    };

public:
    template <typename... Args>
    static T* GetInstance(Args&&... args) {
        // 初回呼び出し時の引数だけが使用される
        static std::unique_ptr<T, Deleter> instance{
            new T(std::forward<Args>(args)...)
        };

        // 返却されるポインタは非所有ポインタ
        return instance.get();
    }

    SingletonPtr(const SingletonPtr&) = delete;
    SingletonPtr& operator=(const SingletonPtr&) = delete;
    SingletonPtr(SingletonPtr&&) = delete;
    SingletonPtr& operator=(SingletonPtr&&) = delete;

protected:
    SingletonPtr() = default;
    virtual ~SingletonPtr() = default;
};

/**
 * @brief SingletonPtr<T> をフレンド宣言する。
 */
#define SINGLETON_PTR_FRIEND(T) \
    friend class SingletonPtr<T>

 /**
  * @brief デフォルトコンストラクタ版。
  */
#define SINGLETON_PTR_CLASS(T) \
    SINGLETON_PTR_FRIEND(T);   \
private:                       \
    T() = default;             \
    ~T() = default

  /**
   * @brief 引数付きコンストラクタ版。
   *        コンストラクタ定義は自分で記述する。
   */
#define SINGLETON_PTR_CLASS_CUSTOM_CTOR(T) \
    SINGLETON_PTR_FRIEND(T);               \
private:                                   \
    ~T() = default

   /**
    * @brief T::Get() でポインタを取得するアクセサ。
    */
#define SINGLETON_PTR_ACCESSOR(T) \
    static T* Get() { return T::GetInstance(); }

    /**
     * @brief シングルトンへのポインタをローカル変数に束縛する。
     */
#define SINGLETON_PTR_REF(T, name) \
    T* name = T::GetInstance()