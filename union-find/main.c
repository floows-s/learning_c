#include <stdio.h>


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

    With this index table, can you implement a Find function that, for a given index, finds the root of its tree?

    Can you implement a FindReplace function that changes all parent entries on a path to the root (including) to a specific value?

    Can you implement a FindCompress function that changes all parent entries to the root that has been found?

    Can you implement a Union function that, for two given elements, combines their trees into one? Use FindCompress for one side and FindReplace for the other.
*/

void init_parent(size_t parent_size, size_t parent[parent_size]);
size_t find_root(size_t parent_size, size_t parent[parent_size], size_t target);

int main(){
    size_t parent_size = 10;
    size_t parent[parent_size];
    init_parent_test(parent_size, &parent);


    return 0;
}

void init_parent_empty(size_t parent_size, size_t parent[parent_size]){
    for(int i = 0; i < parent_size; i++){
        parent[i] = __SIZE_MAX__;
    }
}

void init_parent_test(size_t parent_size, size_t parent[parent_size]){
    size_t test_values[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    
}

size_t find_root(size_t parent_size, size_t parent[parent_size], size_t target){
    size_t target_parent = parent[target];
    
    if(target_parent == __SIZE_MAX__){
        return target;
    }

    // Climb up the tree
    return find_root(parent_size, &parent, target_parent);
}

