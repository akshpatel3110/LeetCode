/*
 * Fast set
 * Implement set with integers in range {1,2...N}.
 * The operations include add, remove, contains, clear, iterate
 * The add, remove, contains and clear operation should be O(1) time on average.
 * The iterate operation is o(number of elements).
 */


/*
 * Hash Set
 * Add, remove, contains, O(1)
 * Clear o(N)
 * template <class V, class K, class HF, class Ex, class Eq, class A>
 void hashtable<V, K, HF, Ex, Eq, A>::clear()
 {
 // Loop through each bucket.
 for (size_type i = 0; i < buckets.size(); ++i) {
 node* cur = buckets[i];
 // delete every node in the bucket list
 while (cur != 0) {
 node* next = cur->next;
 delete_node(cur);
 cur = next;
 }
 buckets[i] = 0; 	// Set bucket list to nullptr
 }
 num_elements = 0; 	//set number of elements to 0
 
 // Notice, the space for the bucket vector is not freed
 }
 
 *
 * Iterate O(N)
 */


/*
 * Sequential array of size N and an additional size variable
 * Add O(1)
 * Remove O(Number of elements)
 * Contains O(Number of elements)
 * clear O(1)
 * Iterate O(Number of elements)
 */


/* Given a number, bucket array stores the index of a number
 * in the sequential array
 *
 * Add 3, 1, 2
 *
 * Size   1
 * Seq    1  2  2  0  0  0
 * bucket 1  1  0  6  6  6
 * N = 6  0, 1, 2 ,3, 4, 5
 *
 * Implement remove?
 * Remove 3
 *
 * Size   2
 * Seq    2  1  2  0  0  0
 * bucket 1  0  0  6  6  6
 * N = 6  0, 1, 2 ,3, 4, 5
 *
 *
 *
 * Implement contains?
 *
 * Add 2, clear, Add 1
 *
 * Size   1
 * Seq    1  0  0  0  0  0
 * bucket 0  0  6  6  6  6
 * N = 6  0, 1, 2 ,3, 4, 5
 *
 */



#include <iostream>
#include <fstream>
#include <vector>
#include <assert.h>

using namespace std;
/*
 *
 */

template <size_t N>
class FastSet {
public:
    FastSet(): pos(0), size(0) {
        for (int i = 0; i < N; ++i) {
            seq[i] = 0; // Invalid number
            bucket[i] = N; // Invalid index
        }
        
    }
    
    void add(int p) {
        assert(p >= 1 && p <= N);
        seq[size] = p;
        bucket[p - 1] = size;
        ++size;
        pos = 0; // Invalidate the iterator pointer
    }
    
    void remove(int p) {
        assert(p >= 1 && p <= N);
        // assign seq
        seq[bucket[p - 1]] = seq[size - 1];
        // assign bucket for the number seq[size - 1]
        bucket[seq[size - 1] - 1] = bucket[p - 1];
        --size;
        pos = 0; // Invalidate the iterator pointer
    }
    
    bool contains(int p) {
        assert(p >= 1 && p <= N);
        if (bucket[p - 1] >= size) {
            return false;
        } else {
            return seq[bucket[p - 1]] == p;
        }
    }
    
    void clear() {
        size = 0;
        pos = 0; // Invalidate the iterator pointer
    }
    
    // iterate
    bool hasNext() {
        return pos < size;
    }
    
    int next() {
        return seq[pos++];
    }
    
private:
    int pos;
    int size;
    int seq[N];
    int bucket[N];
    
};


int main() {
    FastSet<6> fs;
    fs.add(3);
    fs.add(1);
    fs.add(2);
    //    cout << fs.contains(1) << endl;
    //    cout << fs.contains(5) << endl;
    //    while (fs.hasNext())
    //        cout << fs.next() << endl;
    
    fs.remove(1);
    fs.remove(2);
    fs.add(1);
    cout << fs.contains(1) << endl;
    cout << fs.contains(2) << endl;
    cout << fs.contains(3) << endl << endl;
    while (fs.hasNext())
        cout << fs.next() << endl;
    
}
