#include<iostream>
#include<vector>

#include "./timer.h"
#include "./sort.h"
#include "./utils.h"
#include "./file.h"

using namespace std;

int main() {
    int intervals = 200;
    int limit = 20000;

    File file("./csv/selection.csv");

    for(int i = 100; i < limit; i += intervals) {
        cout << "INPUT: " << i << " ";
        vector<int> random = Util::generate(i);
        vector<int> asc = Util::generate(i, ASC);
        vector<int> dsc = Util::generate(i, DSC);

        Timer t1, t2, t3;

        // Random
        t1.begin();
        int randomSwaps = Sort::selectionSort(random, [](int n1, int n2) { return n1 > n2; });
        t1.stop();
        
        // Ascending order input
        t2.begin();
        int ascSwaps = Sort::selectionSort(asc, [](int n1, int n2) { return n1 > n2; });
        t2.stop();

        // Descending order input
        t3.begin();
        int dscSwaps = Sort::selectionSort(dsc, [](int n1, int n2) { return n1 > n2; });
        t3.stop();

        // Adding record to the csv file
        file.addRecord(i, t1.getElapsedSeconds(), t2.getElapsedSeconds(), t3.getElapsedSeconds(), randomSwaps, ascSwaps, dscSwaps);

    }
    return 0;
}