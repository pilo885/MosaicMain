
#include "pch.h"
#include "framework.h"
#include "ShortBreadLib.h"
#include <queue>
#include <algorithm>
#include <iostream>

// Helper function to check if two words are differerent by exactly one letter
bool AreDifferentByOneLetter(const std::string & word1, const std::string & word2)
{
    if (word1.length() != word2.length())
        return false;
    int difference = 0;
    for (size_t i = 0; i < word1.length(); ++i)
    {
        if (word1[i] != word2[i])
        {
            if (++difference > 1)
                return false;
        }
    }
    return difference == 1;
}

// Function that tries to find the shortest sequence of words from the starting word to the ending word. Difference between each word in sequence must be only one letter.
std::vector<std::string> FindShortestPath(const std::string & startWord, const std::string & endWord, const std::unordered_set<std::string> & wordList)
{
    std::queue<std::vector<std::string>> pathsQueue;
    pathsQueue.push({ startWord });

    // set of visited words to avoid repeated words
    std::unordered_set<std::string> visited;
    visited.insert(startWord);

    while (!pathsQueue.empty()) // Each cycle adds one word to the path till end word is found or no sequence is found
    {
        size_t pathsQueueCount = pathsQueue.size();

        for (int i = 0; i < pathsQueueCount; ++i)  // Cycle through each possible path
        {
            auto path = pathsQueue.front(); // Examine first element
            pathsQueue.pop();               // Remove first element. It will be inserted back if another word is found.
            std::string lastWord = path.back();

            // Try all words in the word list
            for (const auto & word : wordList)
            {
                if (visited.count(word))
                    continue; // Skip already visited words
                if (AreDifferentByOneLetter(lastWord, word))
                {
                    std::vector<std::string> newPath = path;
                    newPath.push_back(word);

                    // If we found the end word, return the path
                    if (word == endWord)
                        return newPath;

                    pathsQueue.push(newPath);
                    visited.insert(word);
                }
            }
        }
    }

    // When no sequence found, return an empty vector
    return {};
}
