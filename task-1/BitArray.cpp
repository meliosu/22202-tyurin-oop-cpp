//
// Created by Alexander on 13.10.2023.
//

#include "BitArray.h"

#define BITS_PER_BLOCK 64

BitArray::BitArray() {
    num_bits = 0;
}

BitArray::BitArray(int num_bits, unsigned long value) {
    int new_size = static_cast<int>((num_bits - 1) / BITS_PER_BLOCK) + 1;
    blocks.resize(new_size);

    this->num_bits = num_bits;
    blocks[0] = value;
}

BitArray::BitArray(const BitArray &b) {
    std::copy(b.blocks.begin(), b.blocks.end(), blocks.begin());
    num_bits = b.num_bits;
}

