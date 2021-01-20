/*
APMaxHeap: APMaxHeap Class Constructor
Input: void
Output: Void
*/
template <class T>
APMaxHeap<T>::APMaxHeap()
{
    std::cout << "APMaxHeap Default Constructor" << std::endl;
}

/*
APMaxHeap: APMaxHeap Class Copy Constructor
Input: input -> the class to be copied
Output: Void
*/
template <class T>
APMaxHeap<T>::APMaxHeap(const APMaxHeap<T>& input)
{
    std::cout << "APMaxHeap Copy Constructor" << std::endl;
    for (size_t i = 0; i < arr.size(); i++) // free up space by deleting current pointers
        delete arr[i];
    arr.clear(); // clear current vector
    for (size_t i = 0; i < input.arr.size(); i++) // copying new elemnts to vector
        arr.push_back(new T { *input.arr[i] });
}

/*
APMaxHeap: APMaxHeap Class Move Constructor
Input: input -> the class to be moved
Output: Void
*/
template <class T>
APMaxHeap<T>::APMaxHeap(APMaxHeap<T>&& input)
{
    std::cout << "APMaxHeap Move Constructor" << std::endl;
    for (size_t i = 0; i < arr.size(); i++) // free up space by deleting current pointers
        delete arr[i];
    arr.clear(); // clear current vector
    // moving new elemnts to vector
    arr = input.arr;
    for (size_t i = 0; i < input.arr.size(); i++)
        input.arr[i] = nullptr;
}

/*
~APMaxHeap: APMaxHeap Class Destructor
Input: void
Output: Void
*/
template <class T>
APMaxHeap<T>::~APMaxHeap()
{
    std::cout << "APMaxHeap Destructor" << std::endl;
    for (size_t i = 0; i < arr.size(); i++) // free up space by deleting pointers
        delete arr[i];
    arr.clear();
}

/*
push: Add an element to the MAX HEAP
Input:  input_element -> element to be added
Output: class refrence(for chain calling)
*/
template <class T>
APMaxHeap<T>& APMaxHeap<T>::push(T input_element)
{
    std::cout << "APMaxHeap Push" << std::endl;
    arr.push_back(new T { input_element }); // Push new elemnt to the vector
    //Re_order MAXHEAP
    if (arr.size() > 1) {
        size_t position { arr.size() };
        // Change child and parent position if child is greater(child is the added element)
        while (*arr[position - 1] > *arr[(position / 2) - 1]) {
            // Swap procedure
            T* temp = arr[position - 1];
            arr[position - 1] = arr[(position / 2) - 1];
            arr[(position / 2) - 1] = temp;
            position = position / 2;
            if (position <= 1)
                break;
        }
    }
    return *this;
}

/*
pop: Remove the Root Node in the Heap
Input:  void
Output: class refrence(for chain calling)
*/
template <class T>
APMaxHeap<T>& APMaxHeap<T>::pop()
{
    std::cout << "APMaxHeap Pop" << std::endl;
    arr[0] = arr[arr.size() - 1]; // Move the last node to the node
    arr.pop_back(); // Remove the last Node in the Heap
    size_t position { 1 };
    //Re_order MAXHEAP
    while ((arr[2 * position - 1] != nullptr && (*arr[2 * position - 1] > *arr[position - 1]))
        || (arr[2 * position] != nullptr && (*arr[2 * position] > *arr[position - 1]))) {
        // Change child and parent position if parent is smaller
        // Parent is the last node that moved to root
        if (*arr[2 * position - 1] > *arr[2 * position]) { // Left Child is greater
            // Swap procedure
            T* temp = arr[position - 1];
            arr[position - 1] = arr[2 * position - 1];
            arr[2 * position - 1] = temp;
            position = position * 2;
            if (position >= arr.size())
                break;
        } else { // Right Child is greater
            // Swap procedure
            T* temp = arr[position - 1];
            arr[position - 1] = arr[2 * position];
            arr[2 * position] = temp;
            position = (position * 2) + 1;
            if (position >= arr.size())
                break;
        }
    }
    return *this;
}

/*
show:  Show Heap elements
Input:  void
Output: Class Arr(Vector)(for calling show in the vector init)
*/
template <class T>
std::vector<T> APMaxHeap<T>::show() const
{
    std::vector<T> temp;
    std::cout << "APMaxHeap Show Function" << std::endl;
    std::cout << "APMaxHeap:" << std::endl;
    for (size_t i = 0; i < arr.size(); i++) {
        std::cout << *arr[i] << ", ";
        temp.push_back(*arr[i]);
    }
    std::cout << std::endl;
    return temp;
}

/*
Operator +:  Add an element to the MAX HEAP
Input:  input_element -> element to be added
Output: Copied Class
*/
template <class T>
APMaxHeap<T> APMaxHeap<T>::operator+(const T& added_item) const
{
    std::cout << "APMaxHeap operatr -> +" << std::endl;
    APMaxHeap<T> temp { *this }; // Making a copy of the class
    temp.push(added_item); // Add the new element to the copy class
    return temp; // return copy class
}

/*
Operator =:  Set heap to another heap(Copy version)
Input:  input -> Class to be copied
Output: Class refrence
*/
template <class T>
APMaxHeap<T>& APMaxHeap<T>::operator=(const APMaxHeap<T>& input)
{
    std::cout << "APMaxHeap operatr -> = (Copy version)" << std::endl;
    if (this == &input)
        return *this;
    for (size_t i = 0; i < arr.size(); i++) // free up space by deleting current pointers
        delete arr[i];
    arr.clear(); // clear current vector
    for (size_t i = 0; i < input.arr.size(); i++) // copying new elemnts to vector
        arr.push_back(new T { *input.arr[i] });
    return *this;
}

/*
Operator =:  Set heap to another heap(Move version)
Input:  input -> Class to be moved
Output: Class refrence
*/
template <class T>
APMaxHeap<T>& APMaxHeap<T>::operator=(APMaxHeap<T>&& input)
{
    std::cout << "APMaxHeap operatr -> = (Move version)" << std::endl;
    for (size_t i = 0; i < arr.size(); i++) // free up space by deleting current pointers
        delete arr[i];
    arr.clear(); // clear current vector
    // moving new elemnts to vector
    arr = input.arr;
    for (size_t i = 0; i < input.arr.size(); i++)
        input.arr[i] = nullptr;
    return *this;
}
