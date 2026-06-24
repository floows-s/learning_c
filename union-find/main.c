#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "tests/tests.h"

/* NO AI HAS BEEN USED TO MAKE THIS CODE. MADE BY HUMANS. */

/*
    Challenge 4 (Union-Find)

    The Union-Find problem deals with the representation of partitions over a base set. 
    We will identify the elements of the base set using the numbers equation image and will represent partitions with a forest data structure where each element knows a “parent” that is another element inside the same partition. 
    Each set in such a partition is identified by a designated element called the root of the set.

    We want to perform two principal operations:

        A Find operation receives one element of the ground set and returns the root of the corresponding set.
        A Union 1 operation receives two elements and merges the two sets to which these elements belong into one.

    Can you implement a forest data structure in an index table of base type size_t called parent? 
    Here, a value in the table SIZE_MAX would mean a position represents a root of one of the trees; another number represents the position of the parent of the corresponding tree. 
    One of the important features of starting the implementation is an initialization function that makes parent the singleton partition; that is, the partition where each element is the root of its own private set.

    find_root: With this index table, can you implement a Find function that, for a given index, finds the root of its tree?

    find_replace: Can you implement a find_replace function that changes all parent entries on a path to the root (including) to a specific value?

    find_compress: Can you implement a find_compress function that changes all parent entries to the root that has been found?

    Can you implement a Union function that, for two given elements, combines their trees into one? Use FindCompress for one side and FindReplace for the other.
*/

size_t Union(size_t size, size_t parent[size], size_t target_1, size_t target_2);
size_t find_compress(size_t size, size_t parent[size], size_t target);
void find_replace(size_t size, size_t parent[size], size_t entry_point, size_t value);
size_t find_root(size_t parent_size, const size_t parent[parent_size], size_t target);

void print_arr(size_t size, size_t arr[size]);
void init_parent_empty(size_t parent_size, size_t parent[parent_size]);
void init_parent_test(size_t parent_size, size_t parent[parent_size]);

int main(){
    // Setup
    size_t parent_size = 10;
    size_t parent[parent_size];
    init_parent_empty(parent_size, parent);

    init_parent_test(parent_size, parent);
    
    printf("Initial values: \n");
    print_arr(parent_size, parent);

    // Tests
    printf("\nRunning tests...\n\n");

    test_findroot(parent_size, parent, find_root);
    printf("\n");
    test_find_replace(parent_size, parent, find_replace);
    printf("\n");
    test_find_compress(parent_size, parent, find_compress);
    printf("\n");
    test_Union(parent_size, parent, Union);

    return 0;
}


/// @brief Combine the tree's of two given elements. The root of target_1 will be the root of the combined of the trees.
/// @param size 
/// @param parent 
/// @param target_1 
/// @param target_2 
/// @return 
size_t Union(size_t size, size_t parent[size], size_t target_1, size_t target_2){

    // Flatten first target
    size_t root_target_1 = find_compress(size, parent, target_1);

    // Add nodes of target 2 to target 1's tree (including the root of target 2)
    find_replace(size, parent, target_2, root_target_1);
    
    return root_target_1;
}

/// @brief Compress / flatten a tree in the given index table.
/// @param size 
/// @param parent 
/// @param target 
/// @return Root of target
size_t find_compress(size_t size, size_t parent[size], size_t target){
    size_t root = find_root(size, parent, target);

    size_t parent_copy[size];
    memcpy(parent_copy, parent, sizeof(parent[0]) * size);

    for(int i=0; i<size; i++){
        if(parent[i] == __SIZE_MAX__){
            continue;
        }

        if(i == target){
            parent[i] = root;
            continue;
        }

        size_t found_root = find_root(size, parent_copy, parent_copy[i]);

        if(found_root == root){
            parent[i] = root;
        }
    }

    return root;
}


/// @brief Replace all values on a given path. Including the root.
/// @param size of parent
/// @param parent 
/// @param entry_point of the path to change the values of
/// @param value replacement value
void find_replace(size_t size, size_t parent[size], size_t entry_point, size_t value){
    if(parent[entry_point] == __SIZE_MAX__){
        parent[entry_point] = value;
        return;
    }

    find_replace(
        size, 
        parent, 
        parent[entry_point], // Next node on path
        value
    );

    parent[entry_point] = value;
}

size_t find_root(size_t parent_size, const size_t parent[parent_size], size_t target){
    if(target > parent_size - 1){
        printf("Error: target out of bound");
        abort(); // Dont know how to propely do errors in C yet
    }

    size_t target_parent = parent[target];
    
    if(target_parent == __SIZE_MAX__){
        return target;
    }

    // Climb up the tree
    return find_root(parent_size, parent, target_parent);
}



void print_arr(size_t size, size_t arr[size]){
    for(int i = 0; i < size; i++){
        if(arr[i] == __SIZE_MAX__){
            printf("[%d]: SIZE_MAX\n",
                i
            );
            continue;
        }

        printf("[%d]: %zu\n",
            i,
            arr[i]
        );
    }
}
void init_parent_empty(size_t parent_size, size_t parent[parent_size]){
    for(int i = 0; i < parent_size; i++){
        parent[i] = __SIZE_MAX__;
    }
}



