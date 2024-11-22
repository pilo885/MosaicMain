#pragma once
#ifndef SHORT_BREAD_H
#define SHORT_BREAD_H

#include <string>
#include <vector>
#include <unordered_set>

std::vector<std::string> FindShortestPath(const std::string & startWord, const std::string & endWord, const std::unordered_set<std::string> & wordList);

#endif