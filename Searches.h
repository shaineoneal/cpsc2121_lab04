/*
 * Name: Shaine O'Neal
 * Date Submitted:
 * Lab Section: 004
 * Assignment Name: Searching and Sorting
 */

#pragma once

#include <vector>
#include <iostream>

template <class T>
int linearSearch(std::vector<T> data, T target){
    //iteratre through the vector
    for(int i = 0; i < data.size(); i++){
        //if the target is found, return the index
        if(data[i] == target){
            return i;
        }
    }
    //otherwise, return -1
    return -1;
}


template <class T>
int binarySearch(std::vector<T> data, T target){
    //set the left and right bounds
    int left = 0;
    int right = data.size() - 1;
    //while the left bound is less than or equal to the right bound
    while(left <= right){
        //set the middle index
        int mid = (left + right) / 2;
        //if the target is found, return the index
        if(data[mid] == target){
            return mid;
        }
        //if the target is less than the middle index, set the right bound to the middle index - 1
        else if(target < data[mid]){
            right = mid - 1;
        }
        //if the target is greater than the middle index, set the left bound to the middle index + 1
        else{
            left = mid + 1;
        }
    }
    //otherwise, return -1
    return -1;
}
