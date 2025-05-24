// Helper function to insert an element `top` into the correct position in a sorted stack
void insert(stack<int> &st, int top) {
    // If the stack is empty or the top element is less than or equal to the element to insert, just push it
    if (st.empty() || st.top() <= top) {
        st.push(top);
        return;
    }

    // Otherwise, pop the top element and insert recursively
    int top2 = st.top();
    st.pop();
    insert(st, top); // Recursively insert 'top' into the remaining stack
    st.push(top2);   // Push back the popped element after inserting
}

// Recursive function to sort the entire stack
void func(stack<int> &st) {
    // Base case: If stack is empty, return
    if (st.empty()) return;

    int top = st.top(); // Store the top element
    st.pop();           // Remove the top element
    func(st);           // Recursively sort the remaining stack
    insert(st, top);    // Insert the removed element back in sorted order
}

// Function to sort the stack `s` inside the SortedStack class
void SortedStack :: sort() {
    func(this->s); // Call the recursive sort function on the stack `s`
}
