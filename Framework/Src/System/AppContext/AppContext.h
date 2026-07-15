#pragma once

#include<Utility/Singleton/Singleton.h>
#include <stdexcept>
#include <type_traits>
#include <typeindex>
#include <unordered_map>

class Application;

class AppContext : public SingletonPtr<AppContext>
{
	SINGLETON_PTR_CLASS(AppContext);
public:
	SINGLETON_PTR_ACCESSOR(AppContext);

    template <typename T>
    T& Get() {
        if (T* object = TryGet<T>()) {
            return *object;
        }

        throw std::logic_error(
            "AppContext: object is not registered."
        );
    }

    template <typename T>
    T* TryGet() noexcept {
        using Type = std::remove_cv_t<T>;

        const auto it = mObjects.find(std::type_index(typeid(Type)));
        if (it == mObjects.end()) {
            return nullptr;
        }

        return static_cast<T*>(it->second);
    }

private:
    template <typename T>
    void Register(T& object) {
        static_assert(
            !std::is_const_v<T>,
            "AppContext cannot register const objects."
            );

        using Type = std::remove_cv_t<T>;
        const auto key = std::type_index(typeid(Type));

        if (!mObjects.emplace(key, &object).second) {
            throw std::logic_error(
                "AppContext: object is already registered."
            );
        }
    }

    void Clear() noexcept {
        mObjects.clear();
    }

    friend class Application;

private:
    std::unordered_map<std::type_index, void*> mObjects;

};