/*
** EPITECH PROJECT, 2024
** R-type
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#pragma once
#include <string>

/** @class Buffer
 *  @brief The Buffer class is used to store data and retrieve it in a specific way.
 *  The data is stored in a string and can be retrieved by getNext() method.
 */
class Buffer {
    public:
        /**
        * @brief Default constructor
        */
        Buffer() = default;

        /**
         * @brief Constructor with parameters
         *
         * @param size The size of the buffer
         * @param startSentence The start sentence of the buffer
         * @param endSentence The end sentence of the buffer
         */
        Buffer(const std::size_t size, const std::string &startSentence, const std::string &endSentence);

        /**
         * @brief Copy constructor
         *
         * @param other The buffer to copy
         */
        Buffer(const Buffer &other);

        /**
         * @brief Destructor
         */
        ~Buffer() = default;

        /**
         * @brief Get the next data from the buffer
         * @return The next data in the buffer that start with the correct start sentence and the correct end sentence
         * return empty string if no data is available
         * @note The data is removed from the buffer
         */
        std::string getNext();

        /**
         * @brief Reset the buffer
         */
        void reset();

        /**
         * @brief Set the size of the buffer
         * @param size The size of the buffer
         */
        void setSize(const std::size_t size);

        /**
         * @brief Get the size of the buffer
         * @return The size of the buffer
         */
        std::size_t getSize() const;

        /**
         * @brief Set the start sentence of the buffer
         * @param startSentence The start sentence of the buffer
         */
        void setStartSentence(const std::string &startSentence);

        /**
         * @brief Get the start sentence of the buffer
         * @return The start sentence of the buffer
         */
        std::string getStartSentence() const;

        /**
         * @brief Set the end sentence of the buffer
         * @param endSentence The end sentence of the buffer
         */
        void setEndSentence(const std::string &endSentence);

        /**
         * @brief Get the end sentence of the buffer
         * @return The end sentence of the buffer
         */
        std::string getEndSentence() const;

        /**
         * @brief Set the data of the buffer
         * @param data The data of the buffer
         */
        std::string getData() const;

        /**
         * @brief Add a data to the buffer if their is the place to store it
         * @return Return true if the data has been added, false otherwise
         */
        bool append(const std::string &data);
    private:

        size_t _size;                   // The size of the buffer
        size_t _readIndex;              // The read index of the buffer
        size_t _writeIndex;             // The write index of the buffer
        std::string _data;              // The data of the buffer
        std::string _startSentence;     // The start sentence of the buffer
        std::string _endSentence;       // The end sentence of the buffer
};
