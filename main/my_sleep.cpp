#include "my_sleep.hpp"

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

void my_sleep(int ms) {
    vTaskDelay(pdMS_TO_TICKS(ms));
}
