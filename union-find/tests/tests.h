#pragma once
#include <stdio.h>

void init_parent_test(size_t parent_size, size_t parent[parent_size]);
bool test_findroot(size_t parent_size, const size_t parent[parent_size], size_t handler(size_t parent_size, const size_t parent[parent_size], size_t target));
bool test_find_replace(size_t size, const size_t parent[size], void handler(size_t size, size_t parent[size], size_t entry_point, size_t value));
bool test_find_compress(size_t size, const size_t parent[size], size_t handler(size_t size, size_t parent[size], size_t target));
bool test_Union(size_t size, const size_t parent[size], size_t handler(size_t size, size_t parent[size], size_t target_1, size_t target_2));