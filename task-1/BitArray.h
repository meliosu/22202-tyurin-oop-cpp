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

    explicit BitArray(int numBits, unsigned long long value = 0);
    BitArray(const BitArray& b);

    void swap(BitArray& b);

    BitArray& operator=(const BitArray& b);

    void resize(int newNumBits, bool value = false);

    void clear();

    void pushBack(bool bit);

    BitArray& operator&=(const BitArray& b);

    BitArray& operator|=(const BitArray& b);

    BitArray& operator^=(const BitArray& b);

    BitArray& operator<<=(int n);

    BitArray& operator>>=(int n);

    BitArray operator<<(int n) const;

    BitArray operator>>(int n) const;

    BitArray& set();

    BitArray& reset();

    bool any() const;

    bool none() const;

    BitArray operator~() const;

    int count() const;

    bool operator[](int i) const;

    Reference operator[](int i);

    int size() const;

    bool empty() const;

    std::string toString() const;

    friend bool operator==(const BitArray& a, const BitArray& b);
    friend bool operator!=(const BitArray& a, const BitArray& b);

    friend BitArray operator&(const BitArray& b1, const BitArray& b2);
    friend BitArray operator|(const BitArray& b1, const BitArray& b2);
    friend BitArray operator^(const BitArray& b1, const BitArray& b2);
};


#endif //TASK_1_BITARRAY_H
