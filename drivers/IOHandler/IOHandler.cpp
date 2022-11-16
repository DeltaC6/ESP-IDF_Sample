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

//===== INCLUDE SECTION ======================================================//
#include "IOHandler.h"
//============================================================================//

//===== DECLARATION AND DEFINITIONS ==========================================//
//============================================================================//

//===== CONSTANTS AND VARIABLES ==============================================//
//============================================================================//

//===== CLASS SECTION ========================================================//
namespace IO {

esp_err_t IOCommon::init(void) {
    return gpio_config(&m_gpioCfg);
}

esp_err_t OutputIO::init(void) {
    esp_err_t status(IOCommon::init());
    status |= resetIO();
    return status;
}

esp_err_t OutputIO::setIO(void) {
    m_ioState = true;
    return gpio_set_level(m_gpioPin, m_ioState);
}

esp_err_t OutputIO::resetIO(void) {
    m_ioState = false;
    return gpio_set_level(m_gpioPin, m_ioState);
}

esp_err_t OutputIO::toggleIO(void) {
    m_ioState = !m_ioState;
    return gpio_set_level(m_gpioPin, m_ioState);
}

esp_err_t OutputIO::setState(bool level) {
    m_ioState = level;
    return gpio_set_level(m_gpioPin, m_ioState);
}

bool OutputIO::getState(void) const {
    return m_ioState;
}

esp_err_t InputIO::init(void) {
    return IOCommon::init();
}

esp_err_t InputIO::enableIRQ() {
    return 0;
}

void InputIO::callbackIRQ(callbackFunc intr) {
    mHandle = intr;
}

bool InputIO::getState(void) const {
    return gpio_get_level(m_gpioPin);
}

} // namespace IO
//============================================================================//
