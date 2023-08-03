#pragma once

#include <array>
#include <cassert>
#include <initializer_list>

namespace GOL
{

namespace STRUCTURE
{

enum class TYPE {
    BLOCK,
    BEEHIVE,
    LOAF,
    BLINKER_H,
    BLINKER_V,
    TOAD,
    BEACON,
    GLIDER
};

template <int32_t Width, int32_t Height>
class Object
{
    private:
    std::array<bool, Width * Height> m_data;

    public:
    Object() = delete;
    constexpr Object( const std::array<bool, Width * Height> & arr ) :
        m_data( arr ) {}

    [[nodiscard]] constexpr inline auto width() const noexcept { return Width; }
    [[nodiscard]] constexpr inline auto height() const noexcept {
        return Height;
    }
    [[nodiscard]] constexpr inline auto data() const noexcept { return m_data; }

    constexpr inline void
    data( const std::array<bool, Width * Height> & arr ) noexcept {
        m_data = arr;
    }

    template <int32_t A_Width, int32_t A_Height, int32_t X, int32_t Y>
    constexpr inline void
    mask( std::array<bool, A_Width * A_Height> & a ) const noexcept {
        static_assert(
            A_Width - X >= Width && A_Width - X >= 0 && A_Width - X <= A_Width,
            "Object x position incompatible object & array dimensions." );
        static_assert(
            A_Height - Y >= Height && A_Height - Y >= 0
                && A_Height - Y <= A_Height,
            "Object Y position incompatible object & array dimensions." );
        for ( int32_t x{ 0 }; x < Width; ++x ) {
            for ( int32_t y{ 0 }; y < Height; ++y ) {
                a[A_Width * ( Y + y ) + ( X + x )] = m_data[Width * y + x];
            }
        }
    }
};

// Still-life structures

constexpr static Object<2, 2> BLOCK{ {
    // clang-format off
        1, 1,
        1, 1,
    // clang-format on
} };

constexpr static Object<4, 3> BEEHIVE{ {
    // clang-format off
    0, 1, 1, 0,
    1, 0, 0, 1,
    0, 1, 1, 0
    // clang-format on
} };

constexpr static Object<4, 4> LOAF{ {
    // clang-format off
    0, 1, 1, 0,
    1, 0, 0, 1,
    0, 1, 0, 1,
    0, 0, 1, 0
    // clang-format on
} };

// Oscillator structures

constexpr static Object<3, 1> BLINKER_H{ {
    // clang-format off
    1, 1, 1
    // clang-format on
} };

constexpr static Object<1, 3> BLINKER_V{ {
    // clang-format off
    1,
    1,
    1
    // clang-format on
} };

constexpr static Object<4, 4> TOAD{ {
    // clang-format off
    0, 0, 1, 0,
    1, 0, 0, 1,
    1, 0, 0, 1,
    0, 1, 0, 0
    // clang-format on
} };

constexpr static Object<4, 4> BEACON{ {
    // clang-format off
    1, 1, 0, 0,
    1, 0, 0, 0,
    0, 0, 0, 1,
    0, 0, 1, 1
    // clang-format on
} };

// Spaceship structures

constexpr static Object<3, 3> GLIDER{ {
    // clang-format off
    1, 0, 0,
    0, 1, 1,
    1, 1, 0
    // clang-format on
} };

}; // namespace STRUCTURE

namespace MASK
{

template <int32_t Width, int32_t Height, int32_t X, int32_t Y>
constexpr inline std::array<bool, Width * Height>
mask( std::array<bool, Width * Height> & a, const STRUCTURE::TYPE type ) {
    switch ( type ) {
    case STRUCTURE::TYPE::BLOCK:
        STRUCTURE::BLOCK.mask<Width, Height, X, Y>( a );
        break;
    case STRUCTURE::TYPE::BEEHIVE:
        STRUCTURE::BEEHIVE.mask<Width, Height, X, Y>( a );
        break;
    case STRUCTURE::TYPE::LOAF:
        STRUCTURE::LOAF.mask<Width, Height, X, Y>( a );
        break;
    case STRUCTURE::TYPE::BLINKER_H:
        STRUCTURE::BLINKER_H.mask<Width, Height, X, Y>( a );
        break;
    case STRUCTURE::TYPE::BLINKER_V:
        STRUCTURE::BLINKER_V.mask<Width, Height, X, Y>( a );
        break;
    case STRUCTURE::TYPE::TOAD:
        STRUCTURE::TOAD.mask<Width, Height, X, Y>( a );
        break;
    case STRUCTURE::TYPE::BEACON:
        STRUCTURE::BEACON.mask<Width, Height, X, Y>( a );
        break;
    case STRUCTURE::TYPE::GLIDER:
        STRUCTURE::GLIDER.mask<Width, Height, X, Y>( a );
        break;
    }
    return a;
}

}; // namespace MASK

}; // namespace GOL
