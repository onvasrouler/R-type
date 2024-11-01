/*
** EPITECH PROJECT, 2024
** R-type-3
** File description:
** networkElem
*/

#pragma once


#include <string>
#include <thread>
#include <iostream>
#include <atomic>
#include "../game/game.hpp"

#if defined(_WIN32)
// To avoid conflicting windows.h symbols with raylib, some flags are defined
// WARNING: Those flags avoid inclusion of some Win32 headers that could be required
// by user at some point and won't be included...
//-------------------------------------------------------------------------------------

// If defined, the following flags inhibit definition of the indicated items.



#define NOSYSCOMMANDS     // SC_*
#define NORASTEROPS       // Binary and Tertiary raster ops
#define NOSHOWWINDOW      // SW_*
#define OEMRESOURCE       // OEM Resource values
#define NOCLIPBOARD       // Clipboard routines

#define NOCOLOR           // Screen colors
#define NOCTLMGR          // Control and Dialog routines
#define NODRAWTEXT        // DrawText() and DT_*
#define NOGDI             // All GDI defines and routines



#define NOKERNEL          // All KERNEL defines and routines
#define NOUSER            // All USER defines and routines
//#define NONLS             // All NLS defines and routines
#define NOMB              // MB_* and MessageBox()
#define NOMEMMGR          // GMEM_*, LMEM_*, GHND, LHND, associated routines
#define NOMETAFILE        // typedef METAFILEPICT
#define NOMINMAX          // Macros min(a,b) and max(a,b)
#define NOMSG             // typedef MSG and associated routines
#define NOOPENFILE        // OpenFile(), OemToAnsi, AnsiToOem, and OF_*
#define NOSCROLL          // SB_* and scrolling routines
#define NOSERVICE         // All Service Controller routines, SERVICE_ equates, etc.
#define NOSOUND           // Sound driver routines
#define NOTEXTMETRIC      // typedef TEXTMETRIC and associated routines
#define NOWH              // SetWindowsHook and WH_*
#define NOWINOFFSETS      // GWL_*, GCL_*, associated routines
#define NOCOMM            // COMM driver routines
#define NOKANJI           // Kanji support stuff.
#define NOHELP            // Help engine interface.
#define NOPROFILER        // Profiler interface.
#define NODEFERWINDOWPOS  // DeferWindowPos routines
#define NOMCX             // Modem Configuration Extensions

// Type required before windows.h inclusion
typedef struct tagMSG *LPMSG;

#include <boost/asio.hpp>

// Type required by some unused function...
typedef struct tagBITMAPINFOHEADER {
  DWORD biSize;
  LONG  biWidth;
  LONG  biHeight;
  WORD  biPlanes;
  WORD  biBitCount;
  DWORD biCompression;
  DWORD biSizeImage;
  LONG  biXPelsPerMeter;
  LONG  biYPelsPerMeter;
  DWORD biClrUsed;
  DWORD biClrImportant;
} BITMAPINFOHEADER, *PBITMAPINFOHEADER;

#include <objbase.h>
#include <mmreg.h>
#include <mmsystem.h>

// Some required types defined for MSVC/TinyC compiler
#if defined(_MSC_VER) || defined(__TINYC__)
    #include "propidl.h"
#endif
#endif

/**
 * @class NetworkElem
 * @brief Manages network operations for the client.
 *
 * This class handles the connection, disconnection, and communication with the server.
 * It uses Boost.Asio for asynchronous network operations.
 */
class NetworkElem {
public:

    enum class Status {
        DISCONNECTED,
        CONNECTED,
        CONNECTING,
        CONNECTION_FAILED
    };
/**
 * @enum NetworkElem::Status
 * @brief Represents the connection status.
 * 
 * - DISCONNECTED: The client is not connected to the server.
 * - CONNECTED: The client is connected to the server.
 * - CONNECTING: The client is in the process of connecting to the server.
 * - CONNECTION_FAILED: The client failed to connect to the server.
 */

    /**
     * @brief Constructs a new NetworkElem object with default or specified IP and port.
     * 
     * @param ip The IP address of the server (default is "1.1.1.1").
     * @param port The port number of the server (default is "1234").
     */
    NetworkElem(const std::shared_ptr<DebugLogger> debuglogger = nullptr, std::string ip = "1.1.1.1", const std::string port = "1234");

    /**
     * @brief Destroys the NetworkElem object and cleans up resources.
     */
    ~NetworkElem();

    /**
     * @brief Sets the IP address of the server.
     * 
     * @param ip The new IP address.
     */
    void setIp(std::string ip);

    /**
     * @brief Sets the port number of the server.
     * 
     * @param port The new port number.
     */
    void setPort(const std::string port);

    /**
     * @brief Sets both the IP address and port number of the server.
     * 
     * @param ip The new IP address.
     * @param port The new port number.
     */
    void setServerInfos(const std::string ip, const std::string port);

    /**
     * @brief Gets the current IP address of the server.
     * 
     * @return The current IP address.
     */
    std::string getIp() const;

    /**
     * @brief Gets the current port number of the server.
     * 
     * @return The current port number.
     */
    std::string getPort() const;

    /**
     * @brief Checks if the client is connected to the server.
     * 
     * @return True if connected, false otherwise.
     */
    bool isConnected() const;

    /**
     * @brief Gets the current connection status.
     * 
     * @return The current connection status.
     */
    Status getStatus() const;

    /**
     * @brief Initiates a connection to the server.
     */
    void connect();

    /**
     * @brief Starts asynchronous receiving of messages from the server.
     */
    void asyncReceive();

    /**
     * @brief Disconnects from the server.
     */
    void disconnect();

    /**
     * @brief Sends a message to the server.
     * 
     * @param message The message to send.
     */
    void send(const std::string message);

    void initConnection();

    void setGame(std::shared_ptr<Game> game);

    void setDebugLogger(std::shared_ptr<DebugLogger> debugLogger);

    void update();

    void handleInput(int key, int pressedOrReleased);


    private:
    
    std::shared_ptr<Game> _Game;
    std::shared_ptr<DebugLogger> _DebugLogger;

    std::string _Ip;
    std::string _Port;
    std::string _Username;

    bool _Connected;
    std::atomic<Status> _Status;
    boost::asio::io_service _Io_service;
    boost::asio::ip::udp::socket _Socket;
    boost::asio::ip::udp::endpoint _Endpoint;
    boost::asio::ip::udp::endpoint _Sender_endpoint;
    std::thread _Network_thread;
    std::string _Response;
    boost::asio::steady_timer _Timer;
    boost::asio::steady_timer _Timer2;
    std::array<char, 1024> _Buffer;

    bool _DownPressed;
    bool _UpPressed;
    bool _LeftPressed;
    bool _RightPressed;
    bool _SpacePressed;



};
