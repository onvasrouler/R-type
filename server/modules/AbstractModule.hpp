/*
** EPITECH PROJECT, 2024
** R-type
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#pragma once

#include "MultiThread.hpp"

#define MODULE_PORT 8082

/** @class AbstractModule
 *  @brief The AbstractModule class is the base class for all modules.
 * It inherits from MultiThreadElement.
 * It is an abstract class.
 * It contains the start, run and stop methods.
 * It also contains the decodeInterCommunication and encodeInterCommunication methods.
 * It contains a boolean _Running.
 * The constructor takes a SOCKET or an int as parameter depend of the OS.
 * The decode method must be overrided.
 * The run method must be overrided.
 */
class AbstractModule : public MultiThreadElement {
    public:
        /** @brief Constructor of AbstractModule.
         */
        AbstractModule();
        /**
        * @brief Constructor of AbstractModule.
        * @param name The name of the module.
        */
        AbstractModule(const std::string name);
        /**
         * @brief Constructor of AbstractModule.
         * @param name The name of the module.
         * @param id The id of the module.
         */
        AbstractModule(const std::string name, const std::string id);
        /** @brief Destructor of AbstractModule.
         */
        ~AbstractModule();
        /**
         * @brief Start the module.
         */
        virtual void start();
        /**
         * @brief The main loop of the module
         */
        void run() override;
        /**
         * @brief Stop the module.
         */
        virtual void stop();
        /**
         * @brief Return the name of the module
         *
         * @return The name of the module
         */
        std::string getName() const;
        /**
         *@brief Add a communicate module
         *
         * @param module The module to communicate with
         */
        void addCommunicateModule(const std::string module);

        /**
         * @brief Get the communicates modules
         *
         * @return std::vector<std::string> The communicates modules
         */
        const std::vector<std::string> getCommunicatesModules() const;

        /**
         * @brief Get the id of the MultithreadElement
         *
         * @return std::string The id of the MultithreadElement
         */
        const std::string getId() const;
    protected:
        /**
         * @brief Decode the message received from the server.
         * @param message The message to decode.
         */
        virtual std::string decodeInterCommunication(const std::string message) override;
        /**
         * @brief Encode the message to send to the server.
         * @param message The message to encode.
         */
        virtual std::string encodeInterCommunication(const std::string message) override;
        bool _Running; /*!< The state of the module. */
        std::string _ModuleName; /*!< The name of the module. */
        std::vector<std::string> _communicatesModules; /*!< The modules to communicate with. */
        const std::string _id; /*!< The id of the module. */
};
