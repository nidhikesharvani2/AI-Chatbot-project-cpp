#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// Function to convert a string to lowercase
string toLowercase(const string& str) {
    string result = str;
    transform(result.begin(), result.end(), result.begin(),:: tolower);
    return result;
}

// Rule-based function to generate responses
string generateResponse(const string& userInput) {
    string response;

    // Simple rules for greeting
    if (toLowercase(userInput).find("hello") != string::npos ||
        toLowercase(userInput).find("hi") != string::npos) {
        response = "Hello! How can I help you?";
    } else if (toLowercase(userInput).find("how are you") != string::npos) {
        response = "I'm just a computer program, but thanks for asking!";
    } else if (toLowercase(userInput).find("bye") != string::npos) {
        response = "Goodbye! Have a great day!";
    } else {
        // Default response for unrecognized input
        response = "I'm not sure how to respond to that. Please ask me something else.";
    }

    return response;
}

int main() {
    cout << "Chatbot: Hello! How can I assist you today?" << endl;

    while (true) {
        string userInput;
        cout << "User: ";
        getline(cin, userInput);

        if (toLowercase(userInput) == "exit" || toLowercase(userInput) == "bye") {
            cout << "Chatbot: Goodbye! Have a great day!" << endl;
            break;
        }

        // Generate a response based on user input
        string response = generateResponse(userInput);
        cout << "Chatbot: " << response << endl;
    }

    return 0;
}
