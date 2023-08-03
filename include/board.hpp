#pragma once

// clang-format off
#include "rules.hpp"
#include "rules.cpp"
// clang-format on

#include <array>
#include <cassert>
#include <chrono>
#include <cstdint>
#include <iostream>
#include <string>
#include <vector>



template <std::int32_t Width, std::int32_t Height,
          boundary      Boundary = boundary::VOID,
          neighbourhood Neighbourhood = neighbourhood::MOORE>
class Board
{
    private:
    std::array<bool, ( Width + 2 ) * ( Height + 2 )> m_cells;

    std::chrono::duration<double> m_ms_delay;

    [[nodiscard]] inline constexpr auto
    raw_idx( const std::int32_t x, const std::int32_t y ) const noexcept {
        return ( Width + 2 ) * ( y + 1 ) + ( x + 1 );
    }

    public:
    Board() :
        m_cells( std::array<bool, ( Width + 2 ) * ( Height + 2 )>{} ),
        m_ms_delay( std::chrono::milliseconds( 200 ) ) {
        m_cells.fill( static_cast<bool>( Boundary ) );
    }
    Board( const std::array<bool, Width * Height> &        state,
           const std::chrono::duration<double, std::milli> ms_delay =
               std::chrono::milliseconds( 200 ) ) :
        m_cells(), m_ms_delay( ms_delay ) {
        // Set boundary by filling entire board
        m_cells = std::array<bool, ( Width + 2 ) * ( Height + 2 )>{};
        m_cells.fill( static_cast<bool>( Boundary ) );

        // Set user defines state
        for ( std::int32_t i{ 0 }; i < Width; ++i ) {
            for ( std::int32_t j{ 0 }; j < Height; ++j ) {
                m_cells[raw_idx( i, j )] = state[j * Height + i];
            }
        }
    }

    [[nodiscard]] inline constexpr bool
    get( const std::int32_t x, const std::int32_t y ) const noexcept {
        if ( x < 0 || x >= Width || y < 0 || y >= Height ) {
            return static_cast<bool>( Boundary );
        }
        return m_cells[raw_idx( x, y )];
    }
    // Retrieval & setting
    [[nodiscard]] constexpr inline std::array<bool, 9>
    getn( const std::int32_t x, const std::int32_t y ) {
        assert( x >= 0 || x <= Width || y >= 0 || y <= Height );

        const auto & a{ m_cells };

        // clang-format off
        return std::array<bool, 9>{
            a[raw_idx( x - 1, y - 1 )], a[raw_idx( x, y - 1 )], a[raw_idx( x + 1, y - 1 )],
            a[raw_idx( x - 1, y )],     a[raw_idx( x, y )],     a[raw_idx( x + 1, y )],
            a[raw_idx( x - 1, y + 1 )], a[raw_idx( x, y + 1 )], a[raw_idx( x + 1, y + 1 )]
        };
        // clang-format on
    }

    // Update board
    constexpr inline void step( const std::uint32_t n = 1 ) noexcept {
        for ( std::uint32_t i{ 0 }; i < n; ++i ) {
            std::array<bool, ( Width + 2 ) * ( Height + 2 )> tmp = m_cells;
            for ( std::uint32_t x{ 0 }; x < Width; ++x ) {
                for ( std::uint32_t y{ 0 }; y < Height; ++y ) {
                    tmp[raw_idx( x, y )] =
                        transform_cell<Neighbourhood>( getn( x, y ) );
                }
            }
            m_cells = tmp;
        }
    }

    [[nodiscard]] inline constexpr auto data() const noexcept {
        return m_cells;
    }

    [[nodiscard]] inline constexpr auto ms_delay() const noexcept {
        return m_ms_delay;
    }
};

template <std::int32_t Width, std::int32_t Height,
          boundary      Boundary = boundary::VOID,
          neighbourhood Neighbourhood = neighbourhood::MOORE>
std::ostream &
operator<<( std::ostream &                                        out,
            const Board<Width, Height, Boundary, Neighbourhood> & board ) {
    std::string b_str{ "|" };
    for ( std::int32_t i{ 0 }; i < Width; ++i ) { b_str += "~ "; }
    b_str.pop_back();
    b_str += "|\n";
    for ( std::int32_t j{ 0 }; j < Height; ++j ) {
        b_str += "|";
        for ( std::int32_t i{ 0 }; i < Width; ++i ) {
            b_str +=
                ( board.get( i, j ) ? std::string{ "o" } : std::string{ " " } )
                + " ";
        }
        b_str.pop_back();
        b_str += "|\n";
    }
    b_str += "|";
    for ( std::int32_t i{ 0 }; i < Width; ++i ) { b_str += "~ "; }
    b_str.pop_back();
    b_str += "|\n";
    out << "\033c" << b_str;
    const auto start{ std::chrono::steady_clock::now() };
    while ( std::chrono::duration<double>{ std::chrono::steady_clock::now()
                                           - start }
            < board.ms_delay() ) {
        continue;
    }
    return out;
}

// Default structures
