//
// Created by Alexander on 13.10.2023.
//

#include "BitArray.h"

#include <algorithm>

#define BITS_PER_BLOCK 64
#define ALL_1 0xffffffffffffffff

BitArray::BitArray() {
    num_bits = 0;
}

BitArray::BitArray(int num_bits, unsigned long long value) {
    int new_size = static_cast<int>((num_bits - 1) / BITS_PER_BLOCK) + 1;
    blocks.resize(new_size);

    this->num_bits = num_bits;
    blocks[0] = value;
}

BitArray::BitArray(const BitArray &b) {
    blocks = b.blocks;
    num_bits = b.num_bits;
}

BitArray& BitArray::operator=(const BitArray &b) {
    blocks = b.blocks;
    num_bits = b.num_bits;
    return *this;
}

void BitArray::swap(BitArray &b) {
    BitArray temp = *this;
    *this = b;
    b = temp;
}

void BitArray::resize(int num_bits, bool value) {
    int new_size = static_cast<int>((num_bits - 1) / BITS_PER_BLOCK) + 1;
    blocks.resize(new_size, value);
    blocks[blocks.size() - 1] &= ALL_1 << (BITS_PER_BLOCK - (num_bits % BITS_PER_BLOCK));

    this->num_bits = num_bits;
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

BitArray& BitArray::set() {
    for (unsigned long long block : blocks) {
        block = ~0;
    }

    blocks[blocks.size() - 1] ^= ALL_1 >> (num_bits % BITS_PER_BLOCK);

    return *this;
}

void BitArray::set(int i) {
    blocks[i / BITS_PER_BLOCK] |= ((unsigned long long)1 << (BITS_PER_BLOCK - (i % BITS_PER_BLOCK) - 1));
}

BitArray& BitArray::reset() {
    for (unsigned long long block : blocks) {
        block = 0;
    }

    return *this;
}

void BitArray::reset(int i) {
    blocks[i / BITS_PER_BLOCK] &= ~((unsigned long long)1 << (BITS_PER_BLOCK - (i % BITS_PER_BLOCK)));

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

BitArray BitArray::operator~() const {
    BitArray inverted_bitarray(*this);
    for (unsigned long long& block : inverted_bitarray.blocks) {
        block = ~block;
    }

    inverted_bitarray.blocks[blocks.size() - 1] ^= (ALL_1 >> (num_bits % BITS_PER_BLOCK));
    return inverted_bitarray;
}

int BitArray::count() const {
    int count = 0;
    for (unsigned long long block : blocks) {
        count += __builtin_popcount(block);
    }

    return count;
}

bool BitArray::operator[](int i) const {
    bool bit = (blocks[i / BITS_PER_BLOCK] >> (BITS_PER_BLOCK - (i % BITS_PER_BLOCK) - 1)) & 1;
    return bit;
}

BitArray::Reference::Reference(BitArray &bitArray, int i) : bit_array(bitArray) {
    this->bit_array = bitArray;
    this->num_bit = i;
}

BitArray::Reference& BitArray::Reference::operator=(bool value) {
    if (value) {
        bit_array.set(num_bit);
    } else {
        bit_array.reset(num_bit);
    }

    return *this;
}

BitArray::Reference BitArray::operator[](int i) {
    return BitArray::Reference(*this, i);
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

bool operator==(const BitArray& a, const BitArray& b) {
    if (a.size() != b.size()) {
        return false;
    }

    return a.blocks == b.blocks;
}

bool operator!=(const BitArray& a, const BitArray& b) {
    return !(a == b);
}

BitArray operator&(const BitArray& b1, const BitArray& b2) {
    BitArray new_bitarray = b1;
    new_bitarray &= b2;
    return new_bitarray;
}

BitArray operator|(const BitArray& b1, const BitArray& b2) {
    BitArray new_bitarray = b1;
    new_bitarray |= b2;
    return new_bitarray;
}

BitArray operator^(const BitArray& b1, const BitArray& b2) {
    BitArray new_bitarray = b1;
    new_bitarray ^= b2;
    return new_bitarray;
}
