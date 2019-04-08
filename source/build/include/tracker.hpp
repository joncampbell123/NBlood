

template<typename TrackedType>
class TRACKER_NAME_
{
    public:
        TrackedType TrackedValue;

        inline TrackedType* operator & ()
        {
            TRACKER_GLOBAL_HOOK_((uintptr_t)&this->TrackedValue);
            return &this->TrackedValue;
        }

        inline TrackedType operator ++ ()
        {
            TRACKER_GLOBAL_HOOK_((uintptr_t)&this->TrackedValue);
            return ++this->TrackedValue;
        }

        inline TrackedType operator ++ (int)
        {
            TRACKER_GLOBAL_HOOK_((uintptr_t)&this->TrackedValue);
            return this->TrackedValue++;
        }

        inline TrackedType operator -- ()
        {
            TRACKER_GLOBAL_HOOK_((uintptr_t)&this->TrackedValue);
            return --this->TrackedValue;
        }

        inline TrackedType operator -- (int)
        {
            TRACKER_GLOBAL_HOOK_((uintptr_t)&this->TrackedValue);
            return this->TrackedValue--;
        }

        template <typename RightHandType>
        inline TrackedType operator = (RightHandType);

        template <typename RightHandType>
        inline TrackedType operator += (RightHandType);

        template <typename RightHandType>
        inline TrackedType operator -= (RightHandType);

        template <typename RightHandType>
        inline TrackedType operator *= (RightHandType);

        template <typename RightHandType>
        inline TrackedType operator /= (RightHandType);

        template <typename RightHandType>
        inline TrackedType operator |= (RightHandType);

        template <typename RightHandType>
        inline TrackedType operator &= (RightHandType);

        template <typename RightHandType>
        inline TrackedType operator ^= (RightHandType);

        template <typename RightHandType>
        inline TrackedType operator <<= (RightHandType);

        template <typename RightHandType>
        inline TrackedType operator >>= (RightHandType);

        inline operator TrackedType() const;

        inline TrackedType cast() const;
};

#ifndef tracker_hpp_
#define tracker_hpp_

enum {
    TRACKER_NOOP_RIGHTHAND_EQUAL_ = 0,
    TRACKER_NOOP_RIGHTHAND_ZERO_,
    TRACKER_NOOP_RIGHTHAND_ONE_,
    __TRACKER_NEVER,
};

#endif

#include "tracker_operators.hpp"

template<typename TrackedType>
inline TRACKER_NAME_<TrackedType>::operator TrackedType() const
{
    return this->TrackedValue;
}

template<typename TrackedType>
inline TrackedType TRACKER_NAME_<TrackedType>::cast() const
{
    return this->TrackedValue;
}

template <typename TrackedType>
struct is_signed<TRACKER_NAME_<TrackedType>>
{
    static constexpr bool value = std::is_signed<TrackedType>::value;
};
template <typename TrackedType>
struct is_unsigned<TRACKER_NAME_<TrackedType>>
{
    static constexpr bool value = std::is_unsigned<TrackedType>::value;
};
