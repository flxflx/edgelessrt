// Copyright (c) Edgeless Systems GmbH.
// Licensed under the MIT License.

#pragma once

#include <openenclave/bits/types.h>

OE_EXTERNC_BEGIN

/**
 * Changes the value of all bits in the specified range to 1.
 *
 * @param bitset Pointer to the bitset.
 * @param pos Positon of the first bit.
 * @param count Number of bits to change.
 */
void oe_bitset_set_range(void* bitset, size_t pos, size_t count);

/**
 * Changes the value of all bits in the specified range to 0.
 *
 * @param bitset Pointer to the bitset.
 * @param pos Positon of the first bit.
 * @param count Number of bits to change.
 */
void oe_bitset_reset_range(void* bitset, size_t pos, size_t count);

/**
 * Finds the first position of *count* consecutive 0 bits.
 *
 * @param bitset Pointer to the bitset.
 * @param bitset_size Bitset size in bits.
 * @param count Number of 0 bits to find.
 *
 * @return If found, the position of the found range; otherwise, SIZE_MAX.
 */
size_t oe_bitset_find_unset_range(
    const void* bitset,
    size_t bitset_size,
    size_t count);

OE_EXTERNC_END
