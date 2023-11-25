//
// Created by Alexander on 27.10.2023.
//

#include <gtest/gtest.h>
#include "../BitArray.cpp"

const int DEFAULT_SIZE = 100;

TEST(BitArray, Info) {
    BitArray b(DEFAULT_SIZE, 0x1111);

    ASSERT_FALSE(b.empty());
    ASSERT_EQ(b.size(), DEFAULT_SIZE);
    ASSERT_TRUE(b.any());
    ASSERT_FALSE(b.none());
}

TEST(BitArray, Count) {
    BitArray b(DEFAULT_SIZE, 0x1111);
    ASSERT_EQ(b.count(), 4);

    b = ~b;
    ASSERT_EQ(b.count(), DEFAULT_SIZE - 4);
}

TEST(BitArray, Swap) {
    BitArray b1(DEFAULT_SIZE, 1);
    BitArray b2(DEFAULT_SIZE * 2, 2);
    BitArray b1_copy(b1);
    BitArray b2_copy(b2);

    b1.swap(b2);
    ASSERT_EQ(b1, b2_copy);
    ASSERT_EQ(b2, b1_copy);
}

TEST(BitArray, Resize) {
    BitArray b(DEFAULT_SIZE, 0x1111);

    b.resize(DEFAULT_SIZE * 10);
    ASSERT_EQ(b.size(), DEFAULT_SIZE * 10);
    ASSERT_EQ(b.count(), 4);
}

TEST(BitArray, Indexing) {
    BitArray b(8);

    b[0] = true;
    b[3] = true;
    b[7] = true;

    ASSERT_EQ(b.toString(), "10010001");
}

TEST(BitArray, Operators) {
    BitArray b1(4);
    BitArray b2(4);

    b1[0] = true;
    b1[1] = true;
    b2[0] = true;
    b2[2] = true;

    // b1 = 1100, b2 = 1010
    ASSERT_EQ((b1 & b2).toString(), "1000");
    ASSERT_EQ((b1 | b2).toString(), "1110");
    ASSERT_EQ((b1 ^ b2).toString(), "0110");
    ASSERT_EQ((~b1).toString(), "0011");
}

TEST(BitArray, PushBack) {
    BitArray b(4);

    b.pushBack(true);

    ASSERT_EQ(b.toString(), "00001");
}

TEST(BitArray, SmallBitShifts) {
    BitArray b(8);

    b[0] = true;
    b[3] = true;
    b[7] = true;

    b >>= 1;
    ASSERT_EQ(b.toString(), "01001000");

    b <<= 2;
    ASSERT_EQ(b.toString(), "00100000");
}

TEST(BitArray, BigBitShifts) {
    BitArray b(DEFAULT_SIZE * 10);
    b.set();

    b >>= DEFAULT_SIZE * 2;
    ASSERT_EQ(b.count(), DEFAULT_SIZE * 8);

    b <<= DEFAULT_SIZE * 3;
    ASSERT_EQ(b.count(), DEFAULT_SIZE * 7);
}

// Exceptions test section

TEST(BitArray, NegativeNumberOfBits) {
    BitArray b(100);

    ASSERT_THROW(b.resize(-1), BitArrayException);
}

TEST(BitArray, NonMatchingOperandSize) {
    BitArray b1(DEFAULT_SIZE);
    BitArray b2(DEFAULT_SIZE * 2);

    ASSERT_THROW(b1 &= b2, BitArrayException);
    ASSERT_THROW(b1 |= b2, BitArrayException);
    ASSERT_THROW(b1 ^= b2, BitArrayException);

    ASSERT_THROW(b1 & b2, BitArrayException);
    ASSERT_THROW(b1 | b2, BitArrayException);
    ASSERT_THROW(b1 ^ b2, BitArrayException);
}

TEST(BitArray, NegativeBitshift) {
    BitArray b(DEFAULT_SIZE);

    ASSERT_THROW(b <<= -1, BitArrayException);
    ASSERT_THROW(b >>= -1, BitArrayException);
}

TEST(BitArray, OutOfBounds) {
    BitArray b(1);

    ASSERT_EQ(b.capacity(), 64);

    b[100] = 1;

    ASSERT_EQ(b.size(), 101);
    ASSERT_EQ(b.capacity(), 128);
    ASSERT_EQ(static_cast<bool>(b[100]), 1);
}
