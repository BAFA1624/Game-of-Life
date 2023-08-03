#pragma once

#include <array>
#include <iostream>

enum class boundary { VOID, SOLID };
enum class neighbourhood { MOORE, VN };

void print_group( const std::array<bool, 9> & a );

template <neighbourhood Neighbourhood>
constexpr inline std::size_t
count_neighbourhood( const std::array<bool, 9> & a );

template <neighbourhood Neighbourhood>
inline bool transform_cell( const std::array<bool, 9> & a );
