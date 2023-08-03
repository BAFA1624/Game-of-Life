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



// Still-life structures

constexpr static int32_t             BLOCK_WIDTH{ 2 }, BLOCK_HEIGHT{ 2 };
constexpr static std::array<bool, 4> block{
    // clang-format off
    1, 1,
    1, 1
    // clang-format on
};



constexpr static int32_t              BEEHIVE_WIDTH{ 4 }, BEEHIVE_HEIGHT{ 3 };
constexpr static std::array<bool, 12> beehive{
    // clang-format off
    0, 1, 1, 0,
    1, 0, 0, 1,
    0, 1, 1, 0
    // clang-format on
};

constexpr static int32_t              LOAF_WIDTH{ 4 }, LOAF_HEIGHT{ 4 };
constexpr static std::array<bool, 16> loaf{
    // clang-format off
    0, 1, 1, 0,
    1, 0, 0, 1,
    0, 1, 0, 1,
    0, 0, 1, 0
    // clang-format on
};

// Oscillator structures

constexpr static int32_t BLINKER_H_WIDTH{ 3 }, BLINKER_H_HEIGHT{ 1 };
constexpr static std::array<bool, 3> blinker_h{
    // clang-format off
    1, 1, 1
    // clang-format on
};
constexpr static int32_t BLINKER_V_WIDTH{ 1 }, BLINKER_V_HEIGHT{ 3 };
constexpr static std::array<bool, 3> blinker_v{ blinker_h };

constexpr static int32_t              TOAD_WIDTH{ 4 }, TOAD_HEIGHT{ 4 };
constexpr static std::array<bool, 16> toad{
    // clang-format off
    0, 0, 1, 0,
    1, 0, 0, 1,
    1, 0, 0, 1,
    0, 1, 0, 0
    // clang-format on
};

constexpr static int32_t              BEACON_WIDTH{ 4 }, BEACON_HEIGHT{ 4 };
constexpr static std::array<bool, 20> beacon{
    // clang-format off
    1, 1, 0, 0,
    1, 0, 0, 0,
    0, 0, 0, 1,
    0, 0, 1, 1
    // clang-format on
};

// Spaceship structures

constexpr static int32_t             GLIDER_WIDTH{ 3 }, GLIDER_HEIGHT{ 3 };
constexpr static std::array<bool, 9> glider{
    // clang-format off
    1, 0, 0,
    0, 1, 1,
    1, 1, 0
    // clang-format on
};

}; // namespace STRUCTURE

namespace MASK
{

template <int32_t Width, int32_t Height, int32_t X, int32_t Y>
constexpr inline void
mask_block( std::array<bool, Width * Height> & a ) {
    assert( Width - X >= STRUCTURE::BLOCK_WIDTH && Width - X >= 0
            && Width - X <= Width );
    assert( Height - Y >= STRUCTURE::BLOCK_HEIGHT && Height - Y >= 0
            && Height - Y <= Height );
    for ( int32_t x{ 0 }; x < STRUCTURE::BLOCK_WIDTH; ++x ) {
        for ( int32_t y{ 0 }; y < STRUCTURE::BLOCK_HEIGHT; ++y ) {
            a[Height * ( Y + y ) + ( X + x )] =
                STRUCTURE::block[STRUCTURE::BLOCK_WIDTH * y + x];
        }
    }
}

template <int32_t Width, int32_t Height, int32_t X, int32_t Y>
constexpr inline void
mask_beehive( std::array<bool, Width * Height> & a ) {
    assert( Width - X >= STRUCTURE::BEEHIVE_WIDTH && Width - X >= 0
            && Width - X <= Width );
    assert( Height - Y >= STRUCTURE::BEEHIVE_HEIGHT && Height - Y >= 0
            && Height - Y <= Height );
    for ( int32_t x{ 0 }; x < STRUCTURE::BEEHIVE_WIDTH; ++x ) {
        for ( int32_t y{ 0 }; y < STRUCTURE::BEEHIVE_HEIGHT; ++y ) {
            a[Height * ( Y + y ) + ( X + x )] =
                STRUCTURE::beehive[STRUCTURE::BEEHIVE_WIDTH * y + x];
        }
    }
}

template <int32_t Width, int32_t Height, int32_t X, int32_t Y>
constexpr inline void
mask_loaf( std::array<bool, Width * Height> & a ) {
    assert( Width - X >= STRUCTURE::LOAF_WIDTH && Width - X >= 0
            && Width - X <= Width );
    assert( Height - Y >= STRUCTURE::LOAF_HEIGHT && Height - Y >= 0
            && Height - Y <= Height );
    for ( int32_t x{ 0 }; x < STRUCTURE::LOAF_WIDTH; ++x ) {
        for ( int32_t y{ 0 }; y < STRUCTURE::LOAF_HEIGHT; ++y ) {
            a[Height * ( Y + y ) + ( X + x )] =
                STRUCTURE::loaf[STRUCTURE::LOAF_WIDTH * y + x];
        }
    }
}

template <int32_t Width, int32_t Height, int32_t X, int32_t Y>
constexpr inline void
mask_blinker_h( std::array<bool, Width * Height> & a ) {
    assert( Width - X >= STRUCTURE::BLINKER_H_WIDTH && Width - X >= 0
            && Width - X <= Width );
    assert( Height - Y >= STRUCTURE::BLINKER_H_HEIGHT && Height - Y >= 0
            && Height - Y <= Height );
    for ( int32_t x{ 0 }; x < STRUCTURE::BLINKER_H_WIDTH; ++x ) {
        for ( int32_t y{ 0 }; y < STRUCTURE::BLINKER_H_HEIGHT; ++y ) {
            a[Height * ( Y + y ) + ( X + x )] =
                STRUCTURE::blinker_h[STRUCTURE::BLINKER_H_WIDTH * y + x];
        }
    }
}

template <int32_t Width, int32_t Height, int32_t X, int32_t Y>
constexpr inline void
mask_blinker_v( std::array<bool, Width * Height> & a ) {
    assert( Width - X >= STRUCTURE::BLINKER_V_WIDTH && Width - X >= 0
            && Width - X <= Width );
    assert( Height - Y >= STRUCTURE::BLINKER_V_HEIGHT && Height - Y >= 0
            && Height - Y <= Height );
    for ( int32_t x{ 0 }; x < STRUCTURE::BLINKER_V_WIDTH; ++x ) {
        for ( int32_t y{ 0 }; y < STRUCTURE::BLINKER_V_HEIGHT; ++y ) {
            a[Height * ( Y + y ) + ( X + x )] =
                STRUCTURE::blinker_v[STRUCTURE::BLINKER_V_WIDTH * y + x];
        }
    }
}

template <int32_t Width, int32_t Height, int32_t X, int32_t Y>
constexpr inline void
mask_toad( std::array<bool, Width * Height> & a ) {
    assert( Width - X >= STRUCTURE::TOAD_WIDTH && Width - X >= 0
            && Width - X <= Width );
    assert( Height - Y >= STRUCTURE::TOAD_HEIGHT && Height - Y >= 0
            && Height - Y <= Height );
    for ( int32_t x{ 0 }; x < STRUCTURE::TOAD_WIDTH; ++x ) {
        for ( int32_t y{ 0 }; y < STRUCTURE::TOAD_HEIGHT; ++y ) {
            a[Height * ( Y + y ) + ( X + x )] =
                STRUCTURE::toad[STRUCTURE::TOAD_WIDTH * y + x];
        }
    }
}

template <int32_t Width, int32_t Height, int32_t X, int32_t Y>
constexpr inline void
mask_beacon( std::array<bool, Width * Height> & a ) {
    assert( Width - X >= STRUCTURE::BEACON_WIDTH && Width - X >= 0
            && Width - X <= Width );
    assert( Height - Y >= STRUCTURE::BEACON_HEIGHT && Height - Y >= 0
            && Height - Y <= Height );
    for ( int32_t x{ 0 }; x < STRUCTURE::BEACON_WIDTH; ++x ) {
        for ( int32_t y{ 0 }; y < STRUCTURE::BEACON_HEIGHT; ++y ) {
            a[Height * ( Y + y ) + ( X + x )] =
                STRUCTURE::beacon[STRUCTURE::BEACON_WIDTH * y + x];
        }
    }
}

template <int32_t Width, int32_t Height, int32_t X, int32_t Y>
constexpr inline void
mask_glider( std::array<bool, Width * Height> & a ) {
    assert( Width - X >= STRUCTURE::GLIDER_WIDTH && Width - X >= 0
            && Width - X <= Width );
    assert( Height - Y >= STRUCTURE::GLIDER_HEIGHT && Height - Y >= 0
            && Height - Y <= Height );
    for ( int32_t x{ 0 }; x < STRUCTURE::GLIDER_WIDTH; ++x ) {
        for ( int32_t y{ 0 }; y < STRUCTURE::GLIDER_HEIGHT; ++y ) {
            a[Height * ( Y + y ) + ( X + x )] =
                STRUCTURE::glider[STRUCTURE::GLIDER_WIDTH * y + x];
        }
    }
}

template <int32_t Width, int32_t Height, int32_t X, int32_t Y>
constexpr inline std::array<bool, Width * Height>
mask( std::array<bool, Width * Height> & a, const STRUCTURE::TYPE type ) {
    switch ( type ) {
    case STRUCTURE::TYPE::BLOCK: mask_block<Width, Height, X, Y>( a ); break;
    case STRUCTURE::TYPE::BEEHIVE:
        mask_beehive<Width, Height, X, Y>( a );
        break;
    case STRUCTURE::TYPE::LOAF: mask_loaf<Width, Height, X, Y>( a ); break;
    case STRUCTURE::TYPE::BLINKER_H:
        mask_blinker_h<Width, Height, X, Y>( a );
        break;
    case STRUCTURE::TYPE::BLINKER_V:
        mask_blinker_v<Width, Height, X, Y>( a );
        break;
    case STRUCTURE::TYPE::TOAD: mask_toad<Width, Height, X, Y>( a ); break;
    case STRUCTURE::TYPE::BEACON: mask_beacon<Width, Height, X, Y>( a ); break;
    case STRUCTURE::TYPE::GLIDER: mask_glider<Width, Height, X, Y>( a ); break;
    }
    return a;
}

}; // namespace MASK

}; // namespace GOL
