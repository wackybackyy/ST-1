// Copyright 2026 UNN-CS
#include <cstdint>

bool checkPrime(uint64_t value) {
  if (value < 2) return false;
  if (value == 2) return true;
  if (value % 2 == 0) return false;

  for (uint64_t i = 3; i <= value / i; i += 2) {
    if (value % i == 0) return false;
  }
  return true;
}

uint64_t nPrime(uint64_t n) {
  if (n == 0) return 0;  // "0-е простое" не определено

  uint64_t count = 0;
  uint64_t candidate = 1;
  while (count < n) {
    ++candidate;
    if (checkPrime(candidate)) ++count;
  }
  return candidate;
}

uint64_t nextPrime(uint64_t value) {
  if (value < 2) {
    return 2;
  }

  uint64_t candidate = value + 1;

  if (candidate % 2 == 0) {
    ++candidate;
  }

  while (!checkPrime(candidate)) {
    candidate += 2;
  }

  return candidate;
}

uint64_t sumPrime(uint64_t hbound) {
  uint64_t sum = 0;
  for (uint64_t x = 2; x < hbound; ++x) {
    if (checkPrime(x)) sum += x;
  }
  return sum;
}
