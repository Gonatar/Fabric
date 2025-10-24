#ifndef CUSTOMEXCEPTIONS_H
#define CUSTOMEXCEPTIONS_H

#include <stdexcept>
#include <string>

using namespace std;

class KeeperException : public runtime_error {
public:
    KeeperException(const string& message) : runtime_error("Keeper error: " + message) {}
};

class FileOperationException : public runtime_error {
public:
    FileOperationException(const string& message) : runtime_error("File operation error: " + message) {}
};

class InvalidInputException : public runtime_error {
public:
    InvalidInputException(const string& message) : runtime_error("Input error: " + message) {}
};

class MemoryException : public runtime_error {
public:
    MemoryException(const string& message) : runtime_error("Memory error: " + message) {}
};

class ItemNotFoundException : public runtime_error {
public:
    ItemNotFoundException(const string& message) : runtime_error("Item not found: " + message) {}
};

#endif