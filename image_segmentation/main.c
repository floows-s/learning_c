/*

    Challenge 11 (Image segmentation)

    In addition to the C standard library, there are many other support libraries out there that provide very different features. 
    Among those are a lot that do image processing of some kind. 
    Try to find a suitable such image-processing library that is written in or interfaced to C and allows you to treat grayscale images as two-dimensional matrices of base type unsigned char. 
    
    The goal of this challenge is to perform a segmentation of such an image: to group the pixels (the unsigned char elements of the matrix) into connected regions that are “similar” in some sense or another. 
    Such a segmentation forms a partition of the set of pixels, much as we saw in challenge 4. 
    Therefore, you should use a Union-Find structure to represent regions, one per pixel at the start. 

    Can you implement a statistics function that computes a statistic for all regions? 
    This should be another array (the third array in the game) that for each root holds the number of pixels and the sum of all values. 
    
    Can you implement a merge criterion for regions? 
    Test whether the mean values of two regions are not too far apart: say, no more than five gray values. 

    Can you implement a line-by-line merge strategy that, for each pixel on a line of the image, tests whether its region should be merged to the left and/or to the top? 
    
    Can you iterate line by line until there are no more changes, such that the resulting regions/sets all test negatively with their respective neighboring regions? 
    
    Now that you have a complete function for image segmentation, try it on images with assorted subjects and sizes. 
    Vary your merge criterion with different values for the the mean distance instead of five.
*/

/*
    SKETCH/THOUGHTS BOOK

    Maybe fun extra: hook up camera to see the processing live.


    Line-by-line:
    "Can you implement a line-by-line merge strategy that, for each pixel on a line of the image, tests whether its region should be merged to the left and/or to the top?"
    
    I was thinking with the statistics array you can look at the one line above with there mean values and test if its region should merge to the top (and/or left)
    
    Union-Find structure:
    Tree structure.

    size_t array where value is the next node in the list.
    __SIZE_MAX__ means root of a tree.

    Structure i'm going to use:
    size_t array where value is the root of the region. Index is the index of the gray scale image matrice
*/

/*
    TODO's
    [] Get image lib
    [] Get in the image path via command args 
*/

#include <stdio.h>


int main(){

    return 0;
}

