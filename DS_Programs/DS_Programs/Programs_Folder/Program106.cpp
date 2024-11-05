#include <iostream>
#include <map>
#include <string>

// Function to display the dictionary
void displayDictionary(const std::map<std::string, std::string>& dictionary) {
    std::cout << "\nCurrent Dictionary:\n";
    for (const auto& pair : dictionary) {
        std::cout << pair.first << " : " << pair.second << std::endl;
    }
}

// Function to add a word and its meaning to the dictionary
void createWord(std::map<std::string, std::string>& dictionary) {
    std::string word, meaning;
    std::cout << "Enter the word: ";
    std::cin.ignore();
    std::getline(std::cin, word);
    std::cout << "Enter its meaning: ";
    std::getline(std::cin, meaning);
    dictionary[word] = meaning;
    std::cout << "Word added successfully!\n";
}

// Function to delete a word from the dictionary
void deleteWord(std::map<std::string, std::string>& dictionary) {
    std::string word;
    std::cout << "Enter the word to delete: ";
    std::cin.ignore();
    std::getline(std::cin, word);
    if (dictionary.erase(word)) {
        std::cout << "Word deleted successfully!\n";
    } else {
        std::cout << "Word not found in the dictionary.\n";
    }
}

// Function to search for a word in the dictionary
void searchWord(const std::map<std::string, std::string>& dictionary) {
    std::string word;
    std::cout << "Enter the word to search: ";
    std::cin.ignore();
    std::getline(std::cin, word);
    auto it = dictionary.find(word);
    if (it != dictionary.end()) {
        std::cout << word << " : " << it->second << std::endl;
    } else {
        std::cout << "Word not found in the dictionary.\n";
    }
}

int main() {
    std::map<std::string, std::string> dictionary = {
        {"Aberration", "A departure from what is normal or expected"},
        {"Benevolent", "Well-meaning and kindly"},
        {"Cacophony", "A harsh, discordant mixture of sounds"},
        {"Diligent", "Showing care in one's work or duties"},
        {"Ebullient", "Cheerful and full of energy"},
        {"Fervent", "Having or displaying passionate intensity"},
        {"Garrulous", "Excessively talkative, especially on trivial matters"},
        {"Hapless", "Unfortunate or unlucky"},
        {"Incisive", "Clear and direct in thought or expression"},
        {"Judicious", "Having or showing good judgment"}
    };

    int choice;
    do {
        std::cout << "\nDictionary Operations:\n";
        std::cout << "1. Create (Add a new word)\n";
        std::cout << "2. Delete a word\n";
        std::cout << "3. Search for a word\n";
        std::cout << "4. Display all words\n";
        std::cout << "5. Exit\n";
        std::cout << "Choose an option: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                createWord(dictionary);
                break;
            case 2:
                deleteWord(dictionary);
                break;
            case 3:
                searchWord(dictionary);
                break;
            case 4:
                displayDictionary(dictionary);
                break;
            case 5:
                std::cout << "Exiting...\n";
                break;
            default:
                std::cout << "Invalid option. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}
