/*
** EPITECH PROJECT, 2024
** R-type
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#include "Buffer.hpp"
#include <iostream>

Buffer::Buffer(const std::size_t size, const std::string &startSentence, const std::string &endSentence)
{
    this->_size = size;
    this->_data.reserve(size);
    this->_readIndex = 0;
    this->_writeIndex = 0;
    this->_startSentence = startSentence;
    this->_endSentence = endSentence;
}

Buffer::Buffer(const Buffer &other)
{
    this->_size = other._size;
    this->_data = other._data;
    this->_readIndex = other._readIndex;
    this->_writeIndex = other._writeIndex;
    this->_startSentence = other._startSentence;
    this->_endSentence = other._endSentence;
}

std::string Buffer::getNext()
{
    std::string ret = "";
    size_t start = this->_data.find(this->_startSentence, this->_readIndex);
    size_t end = this->_data.find(this->_endSentence, this->_readIndex);

    if ((start == std::string::npos || end == std::string::npos)
        || (_writeIndex < _readIndex && start > _writeIndex)
        || (_readIndex < _writeIndex && start > _writeIndex))
        return "";
    start += this->_startSentence.size();
    if (start > _size)
        start = start - _size;
    end -= this->_endSentence.size();
    if (end < start)
        end += _size;
    ret = this->_data.substr(start, end - start + this->_endSentence.size());
    this->_readIndex = end + this->_endSentence.size();
    return ret;
}

void Buffer::reset()
{
    this->_readIndex = 0;
    this->_writeIndex = 0;
    this->_data.clear();
}

void Buffer::setSize(const std::size_t size)
{
    this->_size = size;
    this->_data.reserve(size);
    this->_writeIndex = 0;
    this->_readIndex = 0;
}

std::size_t Buffer::getSize() const
{
    return this->_size;
}

void Buffer::setStartSentence(const std::string &startSentence)
{
    this->_startSentence = startSentence;
}

std::string Buffer::getStartSentence() const
{
    return this->_startSentence;
}

void Buffer::setEndSentence(const std::string &endSentence)
{
    this->_endSentence = endSentence;
}

std::string Buffer::getEndSentence() const
{
    return this->_endSentence;
}

std::string Buffer::getData() const
{
    return this->_data;
}

bool Buffer::append(const std::string &data)
{
    if (_writeIndex < _readIndex && data.size() + _writeIndex >= _readIndex)
        return false;
    if (data.size() + _writeIndex > _size && data.size() + _writeIndex - _size >= _readIndex)
        return false;
    if (this->_writeIndex >= this->_size)
        this->_writeIndex = this->_writeIndex - this->_size;
    this->_data.replace(this->_writeIndex, data.size(), data);
    this->_writeIndex += data.size();
    return true;
}
