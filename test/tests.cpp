// Copyright 2026 UNN-CS
#include <gtest/gtest.h>
#include <cstdint>

#include "alg.h"  // если не так — подстрой include

TEST(st1, checkPrime_small) {
  EXPECT_FALSE(checkPrime(0));
  EXPECT_FALSE(checkPrime(1));
  EXPECT_TRUE(checkPrime(2));
  EXPECT_TRUE(checkPrime(3));
}

TEST(st1, checkPrime_even) {
  EXPECT_FALSE(checkPrime(4));
  EXPECT_FALSE(checkPrime(100));
  EXPECT_FALSE(checkPrime(1000000));
}

TEST(st1, checkPrime_known_primes) {
  EXPECT_TRUE(checkPrime(5));
  EXPECT_TRUE(checkPrime(7));
  EXPECT_TRUE(checkPrime(11));
  EXPECT_TRUE(checkPrime(97));
}

TEST(st1, checkPrime_known_composites) {
  EXPECT_FALSE(checkPrime(9));    // 3*3
  EXPECT_FALSE(checkPrime(21));   // 3*7
  EXPECT_FALSE(checkPrime(49));   // 7*7
  EXPECT_FALSE(checkPrime(121));  // 11*11
}

TEST(st1, nPrime_first) {
  EXPECT_EQ(nPrime(1), 2ULL);
  EXPECT_EQ(nPrime(2), 3ULL);
  EXPECT_EQ(nPrime(3), 5ULL);
  EXPECT_EQ(nPrime(4), 7ULL);
  EXPECT_EQ(nPrime(5), 11ULL);
}

TEST(st1, nPrime_10th) {
  EXPECT_EQ(nPrime(10), 29ULL);
}

TEST(st1, nextPrime_examples) {
  EXPECT_EQ(nextPrime(4), 5ULL);
  EXPECT_EQ(nextPrime(11), 13ULL);  // value не учитывается
}

TEST(st1, nextPrime_edge) {
  EXPECT_EQ(nextPrime(0), 2ULL);
  EXPECT_EQ(nextPrime(1), 2ULL);
  EXPECT_EQ(nextPrime(2), 3ULL);
}

TEST(st1, sumPrime_small) {
  EXPECT_EQ(sumPrime(0), 0ULL);
  EXPECT_EQ(sumPrime(1), 0ULL);
  EXPECT_EQ(sumPrime(2), 0ULL);   // 2 не включается
  EXPECT_EQ(sumPrime(3), 2ULL);   // только 2
  EXPECT_EQ(sumPrime(10), 17ULL); // 2+3+5+7
}

// твои тесты (оставлены, чтобы совпало с ожиданиями задания)
TEST(st1, sumPrime1) {
  uint64_t expected = 142913828922ULL;
  uint64_t res = sumPrime(2000000ULL);
  EXPECT_EQ(expected, res);
}

TEST(st1, sumPrime2) {
  uint64_t expected = 17ULL;
  uint64_t res = sumPrime(10ULL);
  EXPECT_EQ(expected, res);
}
