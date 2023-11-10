//
// Created by Alexander on 13.10.2023.
//

#ifndef TASK_1_BITARRAY_H
#define TASK_1_BITARRAY_H

#include <string>
#include <vector>

#include "BitArrayException.cpp"

class BitArray {
private:
    std::vector<unsigned long long> blocks;
    int numBits;

    class Reference {
    private:
        BitArray& bitArray;
        int index;

    public:
        Reference(BitArray &bitArray, int i);
        Reference& operator=(bool value);
        Reference& operator=(Reference& reference);
        operator bool();
    };

    void set(int i);

    void reset(int i);

    bool read(int i) const;

public:
    BitArray() = default;
    ~BitArray() = default;

    // Create BitArray of size numBits, initialize first 64 bits with value
    // Throws an exception if numBits is negative or value doesn't fit into BitArray
    explicit BitArray(int numBits, unsigned long long value = 0);

    // Copy constructor
    BitArray(const BitArray& b);

    // Swap two BitArrays
    void swap(BitArray& b);

    // Assign BitArray to another
    BitArray& operator=(const BitArray& b);

    // Resize BitArray, if new number of bits is bigger, set new bits to value (default = 0)
    void resize(int newNumBits, bool value = false);

    // Clear BitArray
    void clear();

    // Push back one bit, resize BitArray if not enough capacity
    void pushBack(bool bit);

    // Bitwise and
    // Throws an exception if BitArray sizes don't match
    BitArray& operator&=(const BitArray& b);

    // Bitwise or
    // Throws an exception if BitArray sizes don't match
    BitArray& operator|=(const BitArray& b);

    // Bitwise xor
    // Throws an exception if BitArray sizes don't match
    BitArray& operator^=(const BitArray& b);

    // Left shift whole BitArray in-place by n bits
    // Throws an exception if n is negative
    BitArray& operator<<=(int n);

    // Right shift whole BitArray in-place by n bits
    // Throws an exception if n is negative
    BitArray& operator>>=(int n);

    // Left shift whole BitArray by n bits
    // Throws an exception if n is negative
    BitArray operator<<(int n) const;

    // Right shift whole BitArray by n bits
    // Throws an exception if n is negative
    BitArray operator>>(int n) const;

    // Set bits in BitArray to 1's
    BitArray& set();

    // Set bits in BitArray to 0's
    BitArray& reset();

    // Return true if BitArray has at least one non-zero bit, false otherwise
    bool any() const;

    // Return true if BitArray has no non-zero bits, false otherwise
    bool none() const;

    // Invert BitArray: 1 -> 0, 0 -> 1
    BitArray operator~() const;

    // Return number of set bits
    int count() const;

    // Return the value of i'th bit
    // Throws an exception if i is out of range
    bool operator[](int i) const;

    // Assign a value to i'th bit
    // Throws an exception if i is out of range
    Reference operator[](int i);

    // Return size of BitArray in bits
    int size() const;

    // Return true if BitArray size is 0, false otherwise
    bool empty() const;

    // Get string representation of BitArray
    std::string toString() const;

    // Check BitArrays for (un)equality
    friend bool operator==(const BitArray& a, const BitArray& b);
    friend bool operator!=(const BitArray& a, const BitArray& b);

    // Bitwsie operators
    // Throw an exception if sizes don't match
    friend BitArray operator&(const BitArray& b1, const BitArray& b2);
    friend BitArray operator|(const BitArray& b1, const BitArray& b2);
    friend BitArray operator^(const BitArray& b1, const BitArray& b2);
};


#endif //TASK_1_BITARRAY_H
