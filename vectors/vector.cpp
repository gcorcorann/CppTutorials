/*
 * constructing vectors
 */
#include <iostream>
#include <vector>

int main() {
    /*
     * 1) Empty Container Constructor (default constructor)
     *      constructs an empty container, i.e. no elements
     */
    std::vector<int> first;
    
    /*
     * 2) Fill Constructor
     *      constructs a container with `n` elementss, each element is
     *      a copy of `val`
     *
     *      `n` initial container size (i.e. number of elements in the
     *      container at construction), member type `size_type` is an
     *      unsigned integral type
     *
     *      `val` value to fill container with, each of the `n` elements
     *      in the container will be initialized to a copy of this value,
     *      member type `value_type` is the type of the elements in
     *      the container
     */
    std::vector<int> second (4, 100);

    /*
     * 3) Range Constructor
     *      constructs a container with as many elements as the range
     *      `(first, last)`, with each element constructed from its
     *      corresponding element in that range, in the same order
     *
     *      `first, last` input iterators to the initial and final
     *      positions in a range
     *      range used is (first, last), which includes all the elments
     *      between firs and last, including the element pointed to
     *      by `first` bo
     */
    std::vector<int> third(second.begin(), second.end());

    /*
     * 4) Copy Constructor
     *      constructs a container with a copy of each of the elements
     *      in `x`, in the same order
     */
    
}
