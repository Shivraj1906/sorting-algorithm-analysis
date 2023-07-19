#ifndef SORT_H
#define SORT_H

#include<functional>
#include<vector>
#include<iostream>

#include "./utils.h"

using namespace std;

class Sort {
    private:
    static void divide(int lower, int mid, int upper, vector<int>& nums, std::function<bool(int, int)> comparator) {
        int leftArrSize = mid - lower + 1;
        int rightArrSize = upper - mid;

        vector<int> leftArr(leftArrSize), rightArr(rightArrSize);
        for(int i = 0; i < leftArrSize; i++)
            leftArr[i] = nums[i + lower];
        for(int i = 0; i < rightArrSize; i++)
            rightArr[i] = nums[i + mid + 1];

        int leftIndex = 0, rightIndex = 0, arrIndex = lower;
        while(leftIndex < leftArrSize && rightIndex < rightArrSize) {
            if(comparator(leftArr[leftIndex], rightArr[rightIndex])) {
                nums[arrIndex] = leftArr[leftIndex];
                leftIndex++;
            } else {
                nums[arrIndex] = rightArr[rightIndex];
                rightIndex++;
            }
            arrIndex++;
        }

        while(leftIndex < leftArrSize) {
            nums[arrIndex] = leftArr[leftIndex];
            leftIndex++;
            arrIndex++;
        }

        while(rightIndex < rightArrSize) {
            nums[arrIndex] = rightArr[rightIndex];
            rightIndex++;
            arrIndex++;
        }
    }
    public:
    // returns the number of swaps
    static int insertionSort(std::vector<int>& nums, std::function<bool(int, int)> comparator) {
        int counter = 0;
        for(int j = 1; j < nums.size(); j++) {
            std::cout << "VALUE OF J: " << j << std::endl;
            int key = nums[j];
            int i = j - 1;
            while(i >= 0 && comparator(nums[i], key)) {
                counter++;
                nums[i + 1] = nums[i];
                i--;
            }
            nums[i + 1] = key;
            counter++;
        }
        return counter;
    }
    // returns the number of swaps
    static int bubbleSort(std::vector<int>& nums, std::function<bool(int, int)> comparator) {
        int counter = 0;
        for(int i = 0; i < nums.size() - 1; i++) {
            for(int j = i + 1; j < nums.size(); j++) {
                if(comparator(nums[i], nums[j])) {
                    counter++;
                    int temp = nums[i];
                    nums[i] = nums[j];
                    nums[j] = temp;
                }
            }
        }
        return counter;
    }
    // returns the number of swaps
    static int selectionSort(std::vector<int>& nums, std::function<bool(int, int)> comparator) {
        int counter = 0;
        for(int i = 0; i < nums.size() - 1; i++) {
            int element = i;
            for(int j = i + 1; j < nums.size(); j++) {
                if(comparator(nums[j], nums[element]))
                    element = j;
            }

            if(element != i) {
                counter++;
                int temp = nums[element];
                nums[element] = nums[i];
                nums[i] = temp;
            }
        }
        return counter;
    }

    static int mergeSort(vector<int>& nums, int lower, int upper, std::function<bool(int, int)> comparator) {
        if(lower >= upper)
            return 0;
        int midPoint = (lower + upper) / 2;
        mergeSort(nums, lower, midPoint, comparator);
        mergeSort(nums, midPoint + 1, upper, comparator);
        divide(lower, midPoint, upper, nums, comparator);
        return 0;
    }

    static void quickSort(vector<int>& nums, int lower, int upper, std::function<bool(int, int)> comparator, bool useRandom = false) {
        if(lower >= upper)
            return;
        int pivot;
        if(useRandom)
            pivot = Util::generateRandomInt(lower, upper);
        else
            pivot = upper;
        int  i = lower - 1;
        for(int j = lower; j < upper; j++) {
            // if(nums[j] < nums[pivot]) {
            if(comparator(nums[j], nums[pivot])) {
                i++;
                swap(nums[j], nums[i]);
            }
        }
        swap(nums[i + 1], nums[pivot]);
        pivot = i + 1;
        quickSort(nums, lower, pivot - 1, comparator);
        quickSort(nums, pivot + 1, upper, comparator);
    }
};

#endif