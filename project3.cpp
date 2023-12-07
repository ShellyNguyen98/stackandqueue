// Project3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>

class Stack {
public:
    // Check if all parentheses are balanced
    bool isValidPara(const std::string& expression) {
    std::stack<char> s;

    for (char c : expression) {
        if (c == '(' || c == '{' || c == '[') {
            s.push(c);
        } else if (!s.empty() && isMatching(s.top(), c)) {
            s.pop();
        } else {
            return false;
        }
    }

    return s.empty();
}

    // Find the index of the first unbalanced parenthesis
    int indexError(const std::string& expression) {
        std::stack<int> s;
        for (int i = 0; i < expression.length(); ++i) {
            if (expression[i] == '(') {
                s.push(i);
            }
            else if (expression[i] == ')') {
                if (!s.empty()) {
                    s.pop();
                }
                else {
                    return i;
                }
            }
        }
        return s.empty() ? -1 : s.top();
    }

    // Find how many parentheses are needed to make the string balanced
    void minPara(const std::string& expression) {
        int openCount = 0;
        int closeCount = 0;
        for (char c : expression) {
            if (c == '(') {
                openCount++;
            }
            else if (c == ')') {
                if (openCount > 0) {
                    openCount--;
                }
                else {
                    closeCount++;
                }
            }
        }
        std::cout << openCount + closeCount << std::endl;
    }

    // Calculate how many valid parentheses are present
    void scorePara(const std::string& expression) {
        int score = 0;
        std::stack<char> s;
        for (char c : expression) {
            if (c == '(') {
                s.push(c);
            }
            else if (c == ')' && !s.empty()) {
                s.pop();
                score++;
            }
        }
        std::cout << score << std::endl;
    }

private:
    // Helper function to check if parentheses are matching
    bool isMatching(char open, char close) {
        return (open == '(' && close == ')') ||
            (open == '{' && close == '}') ||
            (open == '[' && close == ']');
    }
};

class Queue {
private:
    std::vector<std::string> queue;

public:
    // Enqueue a chunk of 8 characters, reversing the characters
    void enqueue(const std::string& chunk) {
        std::string reversedChunk = chunk;
        std::reverse(reversedChunk.begin(), reversedChunk.end());
        queue.push_back(reversedChunk);
    }

    // Process the entire message by dequeuing and displaying the reversed chunks
    void processMsg() {
        while (!queue.empty()) {
            std::string chunk = queue.front();
            queue.erase(queue.begin());
            std::reverse(chunk.begin(), chunk.end());
            std::cout << chunk << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    Stack s1;
    s1.validPara("(([]))");
    s1.minPara("(([]))");
    s1.scorePara("(([]))");
    s1.validPara("(([])");
    std::cout << s1.indexError("(([))") << std::endl;
    s1.minPara("(([])");
    s1.validPara("(([{}))");
    std::cout << s1.indexError("(([[}])") << std::endl;
    s1.minPara("(([{}))");
    s1.scorePara("(([{}))");
    std::cout << s1.indexError("({}[]()[)") << std::endl;
    Queue q1;
    q1.enqueue("This is a secure message.");
    q1.processMsg();
    q1.enqueue("The product I received is damaged. What should I do?");
    q1.processMsg();
    q1.enqueue("I need assistance with setting up my new device");
    q1.processMsg();
    q1.enqueue("The website is not loading properly on my browser.");
    q1.processMsg();
  

    return 0;
}
