#ifndef SORT_H
#define SORT_H

#include<functional>
#include<vector>
#include<iostream>

class Sort {
    public:
    static void insertionSort(std::vector<int>& nums, std::function<bool(int, int)> comparator) {
        for(int j = 1; j < nums.size(); j++) {
            std::cout << "VALUE OF J: " << j << std::endl;
            int key = nums[j];
            int i = j - 1;
            while(i >= 0 && comparator(nums[i], key)) {
                nums[i + 1] = nums[i];
                i--;
            }
            nums[i + 1] = key;
        }
    }

    static void bubbleSort(std::vector<int>& nums, std::function<bool(int, int)> comparator) {
        for(int i = 0; i < nums.size() - 1; i++) {
            for(int j = i + 1; j < nums.size(); j++) {
                if(comparator(nums[i], nums[j])) {
                    int temp = nums[i];
                    nums[i] = nums[j];
                    nums[j] = temp;
                }
            }
        }
    }

    static void selectionSort(std::vector<int>& nums, std::function<bool(int, int)> comparator) {
        for(int i = 0; i < nums.size() - 1; i++) {
            int element = i;
            for(int j = i + 1; j < nums.size(); j++) {
                if(comparator(nums[j], nums[element]))
                    element = j;
            }

            if(element != i) {
                int temp = nums[element];
                nums[element] = nums[i];
                nums[i] = temp;
            }
        }
    }
};

#endif