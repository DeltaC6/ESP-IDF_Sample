/*!
 * @author  Syed Asad Amin
 * @date    Nov 16th, 2022
 * @file    App.cpp
 * @version v1.0.0 -- CHANGELOG
 * 
 * @note    A wrapper class for the main application
 * 
 * @details Boilerplate project
 * 
 */

//===== INCLUDE SECTION ======================================================//
#include "App.h"

#include "IOHandler.h"
//============================================================================//

//===== DECLARATION AND DEFINITIONS ==========================================//
//============================================================================//

//===== CONSTANTS AND VARIABLES ==============================================//
static const char *TAG = "APP";

IO::OutputIO led(GPIO_NUM_2);
//============================================================================//

//===== ISR SECTION ==========================================================//
//============================================================================//

//===== EVENTS SECTION =======================================================//
//============================================================================//

//===== MAIN APPLICATION =====================================================//
void App::init() {
    ESP_LOGI(TAG, "Setting up the application");

    // Simple LED toggle
    led.init();
    led.resetIO();

    // TODO. All initialization components here.
    
    ESP_LOGI(TAG, "Application setup complete.");
}

void App::run() {
    led.toggleIO();
    vTaskDelay(pdMS_TO_TICKS(1000));
}
//============================================================================//
