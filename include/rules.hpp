#pragma once

#include <array>
#include <iostream>

enum class boundary { VOID, SOLID };
enum class neighbourhood { MOORE, VN };

void
print_group( const std::array<bool, 9> & a ) {
    std::cout << a[0] << " " << a[1] << " " << a[2] << "\n"
              << a[3] << " " << a[4] << " " << a[5] << "\n"
              << a[6] << " " << a[7] << " " << a[8] << "\n";
}

template <neighbourhood Neighbourhood>
constexpr inline std::size_t
count_neighbourhood( const std::array<bool, 9> & a ) {
    if constexpr ( Neighbourhood == neighbourhood::MOORE ) {
        return static_cast<std::size_t>( a[0] + a[1] + a[2] + a[3] + a[5] + a[6]
                                         + a[7] + a[8] );
    }
    else {
        return static_cast<std::size_t>( a[1] + a[3] + a[5] + a[7] );
    }
}

template <neighbourhood Neighbourhood>
inline bool
transform_cell( const std::array<bool, 9> & a ) {
    const auto live_neighbours{ count_neighbourhood<Neighbourhood>( a ) };
    if ( a[4] ) {
        switch ( live_neighbours ) {
        case 0: {
            return false;
        } break;
        case 1: {
            return false;
        } break;
        case 2: {
            return true;
        } break;
        case 3: {
            return true;
        } break;
        case 4: {
            return false;
        } break;
        case 5: {
            return false;
        } break;
        case 6: {
            return false;
        } break;
        case 7: {
            return false;
        } break;
        case 8: {
            return false;
        } break;
        }
    }

    if ( live_neighbours == 3 ) {
        return true;
    }

    return false;
}

