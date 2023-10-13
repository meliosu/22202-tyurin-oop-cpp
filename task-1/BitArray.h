//
// Created by Alexander on 13.10.2023.
//

#ifndef TASK_1_BITARRAY_H
#define TASK_1_BITARRAY_H

#include <string>
#include <vector>

class BitArray {
private:
    std::vector<unsigned long> blocks;
    int num_bits;
public:
    BitArray();
    ~BitArray();

    explicit BitArray(int num_bits, unsigned long value = 0);
    BitArray(const BitArray& b);

    void swap(BitArray& b);

    BitArray& operator=(const BitArray& b);

    void resize(int num_bits, bool value = false);

    void clear();

    void push_back(bool bit);

    BitArray& operator&=(const BitArray& b);

    BitArray& operator|=(const BitArray& b);

    BitArray& operator^=(const BitArray& b);

    BitArray& operator<<=(int n);

    BitArray& operator>>=(int n);

    BitArray operator<<(int n) const;

    BitArray operator>>(int n) const;

    BitArray& set(int n, bool val = true);

    BitArray& set();

    BitArray& reset(int n);

    BitArray& reset();

    bool any() const;

    bool none() const;

    BitArray operator~() const;

    int count() const;

    bool operator[](int i) const;

    int size() const;

    bool empty() const;

    std::string to_string() const;
};

bool operator==(const BitArray & a, const BitArray & b);
bool operator!=(const BitArray & a, const BitArray & b);

BitArray operator&(const BitArray& b1, const BitArray& b2);
BitArray operator|(const BitArray& b1, const BitArray& b2);
BitArray operator^(const BitArray& b1, const BitArray& b2);


#endif //TASK_1_BITARRAY_H
