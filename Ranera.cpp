#include <iostream>
using namespace std;

// Class definition for MaxHeap
class MaxHeap {
private:
    int* heap; // Array to hold heap elements
    int capacity; // Maximum number of elements in the heap
    int size; // Current number of elements in the heap

    // Function to swap two elements
    void swap(int& x, int& y) {
        int temp = x;
        x = y;
        y = temp;
    }

    // Function to maintain the heap property after insertion
    void heapifyUp(int index) {
        while (index > 0 && heap[(index - 1) / 2] < heap[index]) {
            swap(heap[(index - 1) / 2], heap[index]); // Swap with parent
            index = (index - 1) / 2; // Move up to parent index
        }
    }

    // Function to maintain the heap property after deletion
    void heapifyDown(int index) {
        int largest = index; // Initialize largest as root
        int leftChild = 2 * index + 1; // Left child index
        int rightChild = 2 * index + 2; // Right child index

        // Check if left child exists and is greater than root
        if (leftChild < size && heap[leftChild] > heap[largest]) {
            largest = leftChild;
        }
        // Check if right child exists and is greater than largest so far
        if (rightChild < size && heap[rightChild] > heap[largest]) {
            largest = rightChild;
        }
        // If largest is not root, swap and continue heapifying down
        if (largest != index) {
            swap(heap[index], heap[largest]);
            heapifyDown(largest); // Recursively heapify affected subtree
        }
    }

public:
    // Constructor to initialize the MaxHeap with a given capacity
    MaxHeap(int cap) : capacity(cap), size(0) {
        heap = new int[capacity]; // Allocate memory for the heap array
    }

    // Destructor to free allocated memory
    ~MaxHeap() {
        delete[] heap; // Deallocate memory for the heap array
    }

    // Function to insert a new value into the Max-Heap
    void insert(int value) {
        if (size == capacity) { // Check if the heap is full
            cout << "⚠️ Heap is full! Cannot insert more artifacts!" << endl;
            return;
        }
        cout << "🚀 Inserting artifact with power level " << value << "..." << endl;
        heap[size] = value; // Insert new element at the end of the array
        size++; // Increase the size of the heap
        heapifyUp(size - 1); // Restore heap property by moving up
        cout << "✨ Current Heap: ";
        displayHeap(); // Display current state of the heap
    }

    // Function to delete the root element (max element) from the Max-Heap
    void deleteRoot() {
        if (size == 0) { // Check if the heap is empty
            cout << "⚠️ Heap is empty! No artifacts to delete!" << endl;
            return;
        }

        cout << "🛡️ Current root artifact with power level: " << heap[0] << endl;

        char confirm; // Variable to store user confirmation for deletion
        cout << "Do you want to delete this artifact? (y/n): ";
        cin >> confirm;

        if (confirm == 'y' || confirm == 'Y') { // If user confirms deletion
            cout << "🛡️ Deleting root artifact with power level " << heap[0] << "..." << endl;
            heap[0] = heap[size - 1]; // Replace root with last element in the array
            size--; // Decrease size of the heap
            heapifyDown(0); // Restore heap property by moving down from root
            cout << "✨ Updated Heap: ";
            displayHeap(); // Display updated state of the heap after deletion
        } else {
            cout << "❌ Deletion canceled." << endl; // Inform user that deletion was canceled
        }
    }

    // Function to display the current state of the Max-Heap
    void displayHeap() {
        for (int i = 0; i < size; i++) {
            cout << "[" << heap[i] << "] "; // Print each element in the heap array
        }
        cout << endl;
    }

    // Function to display final state of Max-Heap after all operations are done
    void displayHeapifiedArray() {
        cout << "🌌 Final Heapified Array of Artifacts: ";
        displayHeap();
    }
};

// Main function where execution starts
int main() {
    MaxHeap maxHeap(10); // Create a MaxHeap with a capacity of 10

    int numArtifacts, powerLevel;

    cout << "Enter the number of artifacts you want to insert: ";
    cin >> numArtifacts; // User inputs number of artifacts

    for (int i = 0; i < numArtifacts; i++) {
        cout << "Enter power level for artifact " << (i + 1) << ": ";
        cin >> powerLevel;

        maxHeap.insert(powerLevel); // Insert each artifact into the Max-Heap
    }

    char choice;
    cout << "\nDo you want to delete the root artifact? (y/n): ";
    cin >> choice;

    if (choice == 'y' || choice == 'Y') {
        maxHeap.deleteRoot();
    } else {
        cout << "No deletion performed." << endl;
    }

    cout << "\n🌌 Final Heapified Array of Artifacts: ";
    maxHeap.displayHeap();

    return 0;
}
