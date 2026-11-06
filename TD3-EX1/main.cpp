#include <iostream>
#include <vector>
#include <map>

using namespace std;

void countFrequencyBruteForce(const vector<int>& numbers) {
    int n = numbers.size();
    
    for (int i = 0; i < n; ++i) { 
        bool alreadyCounted = false;
        
        for (int j = 0; j < i; ++j) { 
            if (numbers[i] == numbers[j]) {
                alreadyCounted = true;
                break;
            }
        }
        
        if (!alreadyCounted) {
            int count = 1;
            
            for (int j = i + 1; j < n; ++j) {
                if (numbers[i] == numbers[j]) {
                    count++;
                }
            }
            cout << numbers[i] << ":" << count << " times" << endl; 
        }
    }
}

map<int, int> countFrequencyOptimal(const vector<int>& numbers) {
    map<int, int> freqMap;
    
    for (int num : numbers) {
        freqMap[num]++; 
    }
    
    return freqMap;
}

int main() {
    vector<int> numbers = {1, 2, 3, 2, 4, 1, 5, 5, 6};

    cout << "\nFrequency (Brute-Force): " << endl;
    countFrequencyBruteForce(numbers);

    cout << "\nFrequency (Optimal): " << endl;
    
    map<int, int> frequencyMapOptimal = countFrequencyOptimal(numbers);
    
    for (const auto& entry : frequencyMapOptimal) {
        cout << entry.first << ":" << entry.second << " times" << endl;
    }

    return 0;
}