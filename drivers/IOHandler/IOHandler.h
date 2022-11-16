/*!
 * @author  Syed Asad Amin
 * @date    Nov 16th, 2022
 * @file    IOHandler.h
 * @version v1.0.0 -- CHANGELOG
 * @note    A library to deal with GPIO
 * @details This library is written in C++ using ESP-IDF framework.
 * 
 *          This library is explicitly breaking Inputs and Outputs IOs in its
 *          class. This will help remove any unnecessary overheads.
 */

#pragma once

//===== INCLUDE SECTION ======================================================//
#include <functional>
#include "driver/gpio.h"
//============================================================================//

//===== DECLARATION AND DEFINITIONS ==========================================//
//============================================================================//

//===== CONSTANTS AND VARIABLES ==============================================//
//============================================================================//

//===== CLASS SECTION ========================================================//
namespace IO {

typedef std::function<void(void)> callbackFunc;

class IOCommon {
    public:
        constexpr IOCommon(const gpio_num_t pin, const gpio_config_t &cfg) :
            m_gpioPin(pin), m_gpioCfg(cfg) {}

        esp_err_t init(void);

        virtual bool getState(void) const = 0;

    protected:
        const gpio_num_t m_gpioPin;
        const gpio_config_t m_gpioCfg;
        bool m_ioState = false;
};

class OutputIO : private IOCommon {
    public:
        constexpr OutputIO(const gpio_num_t pin) :
            IOCommon(
                pin,
                gpio_config_t {
                    .pin_bit_mask   = static_cast<uint64_t>(1) << pin,
                    .mode           = GPIO_MODE_OUTPUT,
                    .pull_up_en     = GPIO_PULLUP_DISABLE,
                    .pull_down_en   = GPIO_PULLDOWN_ENABLE,
                    .intr_type      = GPIO_INTR_DISABLE
                }
            )
        {}

        esp_err_t init(void);
        esp_err_t setIO(void);
        esp_err_t resetIO(void);
        esp_err_t toggleIO(void);
        esp_err_t setState(bool level);
        bool getState(void) const;

    private:
};

class InputIO : private IOCommon {
    public:
        InputIO(const gpio_num_t pin) :
            IOCommon(
                pin,
                gpio_config_t {
                    .pin_bit_mask   = static_cast<uint64_t>(1) << pin,
                    .mode           = GPIO_MODE_INPUT,
                    .pull_up_en     = GPIO_PULLUP_DISABLE,
                    .pull_down_en   = GPIO_PULLDOWN_DISABLE,
                    .intr_type      = GPIO_INTR_DISABLE
                }
            )
        {}

    private:
        esp_err_t init(void);
        esp_err_t enableIRQ(void);
        void callbackIRQ(callbackFunc intr);
        bool getState(void) const;

        callbackFunc mHandle;
};

} // namespace IO
//============================================================================//