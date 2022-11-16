/*!
 * @author  Syed Asad Amin
 * @date    Nov 16th, 2022
 * @file    App.h
 * @version v1.0.0 -- CHANGELOG
 * 
 * @note    A wrapper class for the main application
 * 
 * @details Boilerplate project
 * 
 */

#pragma once

//===== INCLUDE SECTION ======================================================//

// USER
// #include "IOHandler.h"

// OS
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

// ESP
#define LED_LEVEL_LOCAL ESP_LOG_VERBOSE
#include "esp_log.h"

class App final {
    public:
        /*!
         * @brief Constructor
         */
        App() {}

        /*!
         * @brief Destructor
         */
        ~App() {}

        /*!
         * @brief Initializer function for the main project/application
         * @param None
         * @return None
         */
        void init();

        /*!
         * @brief Main runner thread for the main project/application
         * @param None
         * @return None
         */
        void run();

    private:        
};
