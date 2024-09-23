/*
** EPITECH PROJECT, 2024
** Plaza
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#pragma once
#include <string>

class Buffer {
    public:
        Buffer() = default;
        Buffer(const std::size_t size, const std::string &startSentence, const std::string &endSentence);
        Buffer(const Buffer &other);
        ~Buffer() = default;
        std::string getNext();
        void reset();
        void setSize(const std::size_t size);
        std::size_t getSize() const;
        void setStartSentence(const std::string &startSentence);
        std::string getStartSentence() const;
        void setEndSentence(const std::string &endSentence);
        std::string getEndSentence() const;
        std::string getData() const;
        bool append(const std::string &data);
    private:
        size_t _size;
        size_t _readIndex;
        size_t _writeIndex;
        std::string _data;
        std::string _startSentence;
        std::string _endSentence;
};
