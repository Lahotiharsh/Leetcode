
class MinStack {
private:
    stack<int> s;
    stack<int> min_s;

public:
    MinStack() {}

    void push(int val) {
        s.push(val);
        if (min_s.empty()) {
            min_s.push(val);
        } else {
            min_s.push(min(val, min_s.top()));
        }
    }

    void pop() {
        s.pop();
        min_s.pop();
    }

    int top() {
        return s.top();
    }

    int getMin() {
        return min_s.top();
    }
};