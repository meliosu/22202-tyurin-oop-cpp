//
// Created by Alexander on 13.10.2023.
//

#include "BitArray.h"

#include <algorithm>

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

BitArray& BitArray::operator=(const BitArray &b) {
    std::copy(b.blocks.begin(), b.blocks.end(), blocks.begin());
    num_bits = b.num_bits;
    return *this;
}

void BitArray::clear() {
    blocks.clear();
    num_bits = 0;
}

BitArray& BitArray::operator&=(const BitArray &b) {
    for (int i = 0; i <  blocks.size(); i++) {
        blocks[i] &= b.blocks[i];
    }

    return *this;
}

BitArray& BitArray::operator|=(const BitArray &b) {
    for (int i = 0; i <  blocks.size(); i++) {
        blocks[i] |= b.blocks[i];
    }

    return *this;
}

BitArray& BitArray::operator^=(const BitArray &b) {
    for (int i = 0; i <  blocks.size(); i++) {
        blocks[i] ^= b.blocks[i];
    }

    return *this;
}

bool BitArray::any() const {
    for (unsigned long long block : blocks) {
        if (block) {
            return true;
        }
    }

    return false;
}

bool BitArray::none() const {
    for (unsigned long long block : blocks) {
        if (block) {
            return false;
        }
    }

    return true;
}

int BitArray::count() const {
    int count = 0;
    for (unsigned long long block : blocks) {
        count += __builtin_popcount(block);
    }

    return count;
}

bool BitArray::operator[](int i) const {
    bool bit = (blocks[i / BITS_PER_BLOCK] >> (i % BITS_PER_BLOCK)) & 1;
    return bit;
}

int BitArray::size() const {
    return num_bits;
}

bool BitArray::empty() const {
    return num_bits == 0;
}

std::string BitArray::to_string() const {
    std::string string_representation;
    for (int i = 0; i < num_bits; i++) {
        string_representation += (*this)[i] ? '1' : '0';
    }

    return string_representation;
}
