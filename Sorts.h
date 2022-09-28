/*
 * Name: Shaine O'Neal
 * Date Submitted:
 * Lab Section: 004
 * Assignment Name: Searching and Sorting
 */

#pragma once

#include <vector>
#include <cstdlib>
#include <iostream>

template <class T>
std::vector<T> mergeSort(std::vector<T> lst){
    if(lst.size() == 1 || lst.size() == 0) return lst;


    auto first = lst.begin(), //iterator to first element
        middle = lst.begin() + (lst.size() / 2), //iterator to middle element
        last = lst.begin() + lst.size(); //iterator to last element

    std::vector<T> leftVect(first, middle);
    std::vector<T> rightVect(middle, last);
    std::vector<T> combinedVect;

    leftVect = mergeSort(leftVect);
    rightVect = mergeSort(rightVect);

    while(!(leftVect.empty()) && !(rightVect.empty())) {
        if(leftVect.at(0) > rightVect.at(0)) {
            combinedVect.push_back(rightVect.at(0));
            rightVect.erase(rightVect.begin());
        }
        else {
            combinedVect.push_back(leftVect.at(0));
            leftVect.erase(leftVect.begin());
        }
    }
    while(!(leftVect.empty())) {
        combinedVect.push_back(leftVect.at(0));
        leftVect.erase(leftVect.begin());
    }
    while(!(rightVect.empty())) {
        combinedVect.push_back(rightVect.at(0));
        rightVect.erase(rightVect.begin());
    }

    return combinedVect;
}
template <class T>
void swap(T &value1, T &value2) {
    T temp = value1;
    value1 = value2;
    value2 = temp;
    return;
}

template <class T>
std::vector<T> quickSort(std::vector<T> lst){

    auto first = lst.begin(),
        last = lst.end();

    if(lst.begin() >= lst.end()) return lst;

    int pivotIndex = rand() % lst.size();  //create random pivot
    //int pivot = lst.at(pivotIndex);
    //move pivot to beginning of vector
    swap(lst[0], lst.at(pivotIndex));
    for(int i = 1; i < lst.size(); i++) {
        if(lst[i] < lst.at(pivotIndex)) {
                swap(lst.at(i), lst.at(pivotIndex));
                pivotIndex++;
            }
        }
        swap(lst[pivotIndex], lst[0]);
        return lst;
    }




