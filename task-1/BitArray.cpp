//
// Created by Alexander on 13.10.2023.
//

#include <algorithm>
#include "BitArray.h"

#define BITS_PER_BLOCK 64
#define ALL_1 0xffffffffffffffff

BitArray::BitArray() {
    numBits = 0;
}

BitArray::BitArray(int numBits, unsigned long long value) {
    if (numBits < 0) {
        throw BitArrayException("Number of bits can't be negative");
    }

    if (value != 0 && numBits < BITS_PER_BLOCK) {
        throw BitArrayException("Can't initialize first bits, BitArray is too small");
    }

    int size = (numBits - 1) / BITS_PER_BLOCK + 1;
    blocks.resize(size);

    this->numBits = numBits;
    blocks[0] = value;
}

BitArray::BitArray(const BitArray &b) {
    blocks = b.blocks;
    numBits = b.numBits;
}

BitArray& BitArray::operator=(const BitArray &b) {
    blocks = b.blocks;
    numBits = b.numBits;
    return *this;
}

void BitArray::swap(BitArray &b) {
    BitArray temp = *this;
    *this = b;
    b = temp;
}

void BitArray::resize(int newNumBits, bool value) {
    if (newNumBits < 0) {
        throw BitArrayException("Number of bits can't be negative");
    }

    int newSize = (newNumBits - 1) / BITS_PER_BLOCK + 1;
    if (value) {
        if (numBits % BITS_PER_BLOCK != 0) {
            blocks[blocks.size() - 1] |= ALL_1 >> (numBits % BITS_PER_BLOCK);
        }
        blocks.resize(newSize, ALL_1);
    } else {
        blocks.resize(newSize, 0);
    }

    if (newNumBits % BITS_PER_BLOCK != 0) {
        blocks[blocks.size() - 1] &= ALL_1 << (BITS_PER_BLOCK - (numBits % BITS_PER_BLOCK));
    }

    numBits = newNumBits;
}

void BitArray::clear() {
    blocks.clear();
    numBits = 0;
}

BitArray& BitArray::operator&=(const BitArray &b) {
    if (this->size() != b.size()) {
        throw BitArrayException("BitArray operands must be of the same size");
    }

    for (int i = 0; i <  blocks.size(); i++) {
        blocks[i] &= b.blocks[i];
    }

    return *this;
}

BitArray& BitArray::operator|=(const BitArray &b) {
    if (this->size() != b.size()) {
        throw BitArrayException("BitArray operands must be of the same size");
    }

    for (int i = 0; i <  blocks.size(); i++) {
        blocks[i] |= b.blocks[i];
    }

    return *this;
}

BitArray& BitArray::operator^=(const BitArray &b) {
    if (this->size() != b.size()) {
        throw BitArrayException("BitArray operands must be of the same size");
    }

    for (int i = 0; i <  blocks.size(); i++) {
        blocks[i] ^= b.blocks[i];
    }

    return *this;
}

BitArray& BitArray::operator<<=(int n) {
    if (n < 0) {
        throw BitArrayException("Cannot bitshift by negative amount");
    }

    if (n >= numBits) {
        this->reset();
        return *this;
    }

    int elementShift = n / BITS_PER_BLOCK;
    int bitwiseShift = n % BITS_PER_BLOCK;

    if (elementShift > 0) {
        for (int i = 0; i < blocks.size() - elementShift; i++) {
            blocks[i] = blocks[i + elementShift];
        }

        for (int i = blocks.size() - elementShift; i < blocks.size(); i++) {
            blocks[i] = 0;
        }
    }

    if (bitwiseShift > 0) {
        for (int i = 0; i < blocks.size() - elementShift - 1; i++) {
            blocks[i] <<= bitwiseShift;
            blocks[i] |= (blocks[i + 1] >> (BITS_PER_BLOCK - bitwiseShift));
        }

        blocks[blocks.size() - elementShift - 1] <<= bitwiseShift;
    }

    return *this;
}

BitArray& BitArray::operator>>=(int n) {
    if (n < 0) {
        throw BitArrayException("Cannot bitshift by negative amount");
    }

    if (n >= numBits) {
        this->reset();
        return *this;
    }

    int elementShift = n / BITS_PER_BLOCK;
    int bitwiseShift = n % BITS_PER_BLOCK;

    if (elementShift > 0) {
        for (int i = blocks.size() - 1; i >= elementShift; i--) {
            blocks[i] = blocks[i - elementShift];
        }

        for (int i = elementShift - 1; i >= 0; i--) {
            blocks[i] = 0;
        }
    }

    if (bitwiseShift > 0) {
        for (int i = blocks.size() - 1; i > elementShift; i--) {
            blocks[i] >>= bitwiseShift;
            blocks[i] |= (blocks[i - 1] << (BITS_PER_BLOCK - bitwiseShift));
        }

        blocks[elementShift] >>= bitwiseShift;

        blocks[blocks.size() - 1] &= ALL_1 << (BITS_PER_BLOCK - (numBits % BITS_PER_BLOCK));
    }

    return *this;
}

BitArray BitArray::operator<<(int n) const {
    if (n < 0) {
        throw BitArrayException("Cannot bitshift by negative amount");
    }

    BitArray shiftedBitarray(*this);
    shiftedBitarray <<= n;
    return shiftedBitarray;
}

BitArray BitArray::operator>>(int n) const {
    if (n < 0) {
        throw BitArrayException("Cannot bitshift by negative amount");
    }

    BitArray shiftedBitarray(*this);
    shiftedBitarray >>= n;
    return shiftedBitarray;
}

BitArray& BitArray::set() {
    for (unsigned long long& block : blocks) {
        block = ALL_1;
    }

    if (numBits % BITS_PER_BLOCK != 0) {
        blocks[blocks.size() - 1] ^= ALL_1 >> (numBits % BITS_PER_BLOCK);
    }

    return *this;
}

void BitArray::set(int i) {
    blocks[i / BITS_PER_BLOCK] |= ((unsigned long long)1 << (BITS_PER_BLOCK - (i % BITS_PER_BLOCK) - 1));
}

BitArray& BitArray::reset() {
    for (unsigned long long& block : blocks) {
        block = 0;
    }

    return *this;
}

void BitArray::reset(int i) {
    blocks[i / BITS_PER_BLOCK] &= ~((unsigned long long)1 << (BITS_PER_BLOCK - (i % BITS_PER_BLOCK) - 1));
}

bool BitArray::read(int i) const {
    return (blocks[i / BITS_PER_BLOCK] >> (BITS_PER_BLOCK - (i % BITS_PER_BLOCK) - 1)) & 1;
}

bool BitArray::any() const {
    return std::any_of(blocks.begin(), blocks.end(), [](unsigned long long a) {return a != 0;});
}

bool BitArray::none() const {
    return std::all_of(blocks.begin(), blocks.end(), [](unsigned long long a) {return a == 0;});
}

BitArray BitArray::operator~() const {
    BitArray invertedBitarray(*this);
    for (unsigned long long& block : invertedBitarray.blocks) {
        block = ~block;
    }

    if (numBits % BITS_PER_BLOCK != 0) {
        invertedBitarray.blocks[blocks.size() - 1] ^= (ALL_1 >> (numBits % BITS_PER_BLOCK));

    }

    return invertedBitarray;
}

int BitArray::count() const {
    int count = 0;
    for (const unsigned long long& block : blocks) {
        count += __builtin_popcountll(block);
    }

    return count;
}

bool BitArray::operator[](int i) const {
    if (i >= numBits) {
        throw BitArrayException("BitArray index out of bounds");
    }

    return this->read(i);
}

BitArray::Reference::Reference(BitArray& bitArray, int i) : bitArray(bitArray) {
    this->bitArray = bitArray;
    this->index = i;
}

BitArray::Reference& BitArray::Reference::operator=(bool value) {
    if (value) {
        bitArray.set(index);
    } else {
        bitArray.reset(index);
    }

    return *this;
}

BitArray::Reference::operator bool() {
    return this->bitArray.read(this->index);
}

BitArray::Reference BitArray::operator[](int i) {
    if (i >= numBits) {
        throw BitArrayException("BitArray index out of bounds");
    }

    return BitArray::Reference(*this, i);
}

BitArray::Reference& BitArray::Reference::operator=(BitArray::Reference &reference) {
    bool value = static_cast<bool>(reference.bitArray[reference.index]);

    if (value) {
        bitArray.set(index);
    } else {
        bitArray.reset(index);
    }

    return *this;
}

void BitArray::pushBack(bool bit) {
    this->resize(numBits + 1);

    (*this)[numBits - 1] = bit;
}

int BitArray::size() const {
    return numBits;
}

bool BitArray::empty() const {
    return numBits == 0;
}

std::string BitArray::toString() const {
    std::string stringRepresentation;
    for (int i = 0; i < numBits; i++) {
        stringRepresentation += (*this)[i] ? '1' : '0';
    }

    return stringRepresentation;
}

bool operator==(const BitArray& a, const BitArray& b) {
    if (a.size() != b.size()) {
        return false;
    }

    return a.blocks == b.blocks;
}

bool operator!=(const BitArray& a, const BitArray& b) {
    if (a.size() != b.size()) {
        return true;
    }

    return a.blocks != b.blocks;
}

BitArray operator&(const BitArray& b1, const BitArray& b2) {
    if (b1.size() != b2.size()) {
        throw BitArrayException("BitArray operands must be of the same size");
    }

    BitArray newBitarray(b1);
    newBitarray &= b2;
    return newBitarray;
}

BitArray operator|(const BitArray& b1, const BitArray& b2) {
    if (b1.size() != b2.size()) {
        throw BitArrayException("BitArray operands must be of the same size");
    }

    BitArray newBitarray(b1);
    newBitarray |= b2;
    return newBitarray;
}

BitArray operator^(const BitArray& b1, const BitArray& b2) {
    if (b1.size() != b2.size()) {
        throw BitArrayException("BitArray operands must be of the same size");
    }

    BitArray newBitarray(b1);
    newBitarray ^= b2;
    return newBitarray;
}
