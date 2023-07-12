#ifndef SORT_H
#define SORT_H

#include<functional>
#include<vector>
#include<iostream>

class Sort {
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
};

#endif