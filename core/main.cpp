#include "App.h"

static App _app;

extern "C" void app_main(void) {
    _app.init();

    while(true) {

        _app.run();

    }
}
