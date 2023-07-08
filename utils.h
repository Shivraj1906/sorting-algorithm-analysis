#ifndef UTILS_H
#define UTILS_H

#include<random>
#include<iostream>

enum MODE {
    RANDOM, ASC, DSC
};

class Util {
    public:

    static std::vector<int> generate(int size, MODE mode = RANDOM, int range = __INT_MAX__) {
        std::vector<int> output;

        if(mode == RANDOM) {
            std::default_random_engine generator;
            std::uniform_int_distribution<int> distribution(1, range);

            for(int i = 0; i < size; i++)
                output.push_back(distribution(generator));
        } else if (mode == ASC) {
            for(int i = 0; i < size; i++)
                output.push_back(i);
        } else if(mode == DSC) {
            for(int i = 0; i < size; i++)
                output.push_back(size - i);
        }

        return output;
    }

    static void print(const std::vector<int>& nums) {
        for(auto num: nums)
            std::cout << num << " ";
        std::cout << std::endl;
    }
};

#endif