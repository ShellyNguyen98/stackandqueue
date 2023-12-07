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
    void validPara(const std::string& symbols) {
        std::stack<char> s;
        for (char c : symbols) {
            if (c == '(' || c == '{' || c == '[') {
                s.push(c);
            }
            else if (c == ')' || c == '}' || c == ']') {
                if (s.empty() || !isMatching(s.top(), c)) {
                    std::cout << "invalid" << std::endl;
                    return;
                }
                s.pop();
            }
        }
        if (s.empty()) {
            std::cout << "The paranthesis are balanced, so it is valid" << std::endl;
        }
        else {
            std::cout << "The paranthesis are missing, so it is invalid" << std::endl;
        }
    }

    // Find the first index where actual error occurred
    int indexError(const std::string& symbols) {
    int lastOpen = -1;

    for (int i = 0; i < symbols.length(); ++i) {
        if (symbols[i] == '(') lastOpen = i;
        else if (symbols[i] == ')' && lastOpen == -1) return i;
        else if (symbols[i] == ')') lastOpen = -1;
    }

    return lastOpen;
}

    // Determine paranthessis are needed to make a string of code as a valid parenthesis string
    void minPara(const std::string& symbols) {
    int begin = 0;
    int end = 0;

    for (char c : symbols) {
        if (c == '(') {
           begin++;
        } else if (c == ')' && begin > 0) {
            begin--;
        } else if (c == ')') {
            end++;
        }
    }

    std::cout << begin + end << std::endl;
}


    // Calculate how many valid parentheses are presen in the given string
    void scorePara(const std::string& symbols) {
    int score = 0;
    std::stack<char> s;

    for (char c : symbols) {
        if (c == '(') {
            s.push(c);
        } else if (c == ')' && !s.empty()) {
            s.pop();
            score++;
        }
    }

    std::cout << score << std::endl;
}


private:
    // Check to see if parenthesis are matching
    bool isMatching(char open, char close) {
    if (open == '(' && close == ')') {
        return true;
    } else if (open == '{' && close == '}') {
        return true;
    } else if (open == '[' && close == ']') {
        return true;
    }
    return false;
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
