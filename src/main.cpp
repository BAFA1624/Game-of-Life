#include "board.hpp"
#include "rules.hpp"

#include <cstdint>
#include <iostream>

template <std::int32_t Width, std::int32_t Height,
          boundary Boundary = boundary::VOID>
inline constexpr auto
raw_idx( const std::int32_t x, const std::int32_t y ) {
    const auto i{ x < 0 || x >= Width ? static_cast<bool>( Boundary ) : x + 1 };
    const auto j{ y < 0 || y >= Height ? static_cast<bool>( Boundary ) :
                                         y + 1 };
    return Height * j + i;
}

template <typename T, std::size_t Size>
void
print( const std::array<T, Size> & arr ) {
    for ( const auto & x : arr ) { std::cout << x << std::endl; }
    std::cout << std::endl;
}

int
main() {
    // clang-format off
    //std::array<bool, 64> init1{
    //    0, 1, 1, 1, 0, 0, 0, 1,
    //    1, 0, 0, 1, 1, 1, 0, 0,
    //    0, 0, 0, 0, 1, 1, 1, 1,
    //    0, 1, 1, 1, 0, 0, 1, 0,
    //    1, 1, 1, 1, 1, 1, 1, 1,
    //    0, 0, 1, 1, 1, 0, 0, 0,
    //    0, 0, 0, 0, 0, 0, 0, 1,
    //    0, 1, 1, 0, 0, 0, 1, 1
    //};

    //std::array<bool, 64> init_block{
    //    0, 0, 0, 0, 0, 0, 0, 0,
    //    0, 0, 0, 0, 0, 0, 0, 0,
    //    0, 0, 0, 0, 0, 0, 0, 0,
    //    0, 0, 0, 1, 1, 0, 0, 0,
    //    0, 0, 0, 1, 1, 0, 0, 0,
    //    0, 0, 0, 0, 0, 0, 0, 0,
    //    0, 0, 0, 0, 0, 0, 0, 0,
    //    0, 0, 0, 0, 0, 0, 0, 0
    //};

    std::array<bool, 64> init_blinker {
        0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,
        0,0,0,1,1,1,0,0,
        0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0
    };
    // clang-format o

    Board<8, 8, boundary::VOID, neighbourhood::MOORE> board{ init_blinker };
    for ( int i{ 0 }; i < 10; ++i ) {
        std::cout << board << std::endl;
        board.step();
    }
    std::cout << board << std::endl;
}
