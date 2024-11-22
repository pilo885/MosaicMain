
#include <iostream>
#include <string>
#include <unordered_set>
#include <fstream>
#include "ShortBreadLib.h"

// Load word list from file
std::unordered_set<std::string> LoadWordList(const std::string& filePath)
{
    std::unordered_set<std::string> wordList;
    std::ifstream file(filePath);
    std::string word;
    while (file >> word) {
        wordList.insert(word);
    }
    return wordList;
}


int main()
{
    std::string startWord = "short";
    std::string endWord = "bread";
    std::string wordListFile = "C:\\Users\\grepon\\Dictionary.txt"; // Update the path if needed

    auto wordList = LoadWordList(wordListFile);

    // Find the shortest sequence of words
    auto result = FindShortestPath(startWord, endWord, wordList);

    // Print results
    if (!result.empty())
    {
        std::cout << "Shortest path:\n";
        for (const auto & word : result)
            std::cout << word << " ";

        std::cout << "\n";
    }
    else
    {
        std::cout << "No path found from " << startWord << " to " << endWord << ".\n";
    }

    return 0;
}
