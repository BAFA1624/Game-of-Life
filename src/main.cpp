#include "board.hpp"
#include "rules.hpp"
#include "structure_masks.hpp"

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

    std::array<bool, 400> init { false };
    // clang-format on

    // GOL::MASK::mask<20, 20, 0, 0>( init, GOL::STRUCTURE::TYPE::BLOCK );
    // GOL::MASK::mask<20, 20, 3, 3>( init, GOL::STRUCTURE::TYPE::BEEHIVE );
    // GOL::MASK::mask<20, 20, 0, 8>( init, GOL::STRUCTURE::TYPE::LOAF );
    // GOL::MASK::mask<20, 20, 9, 3>( init, GOL::STRUCTURE::TYPE::BLINKER_V );
    // GOL::MASK::mask<20, 20, 9, 9>( init, GOL::STRUCTURE::TYPE::TOAD );
    // GOL::MASK::mask<20, 20, 0, 14>( init, GOL::STRUCTURE::TYPE::BEACON );

    GOL::MASK::mask<20, 20, 0, 0>( init, GOL::STRUCTURE::TYPE::GLIDER );

    Board<20, 20, boundary::VOID, neighbourhood::MOORE> board{
        init, std::chrono::milliseconds( 200 )
    };
    for ( int i{ 0 }; i < 100; ++i ) {
        std::cout << board << std::endl;
        board.step();
    }
    std::cout << board << std::endl;
}
