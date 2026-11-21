#include "salt_tab_main.hpp"
#include "lv_demos.h"
#include "my_sleep.hpp"
#include "esp_log.h"

static bool salt_running = true;

/** callback for the label */
void my_clicky_event(lv_event_t *e)
{
    ESP_LOGI(TAG, "Clicky on the label");
}

/** setup the initial screen */
void salt_tab_setup()
{
    lv_obj_t *screen = lv_screen_active();
    lv_obj_set_style_bg_color(screen, lv_color_hex(0x003a57), 0);
    lv_obj_set_style_text_color(screen, lv_color_hex(0xffffff), 0);
    lv_obj_t *label = lv_label_create(screen);
    lv_obj_set_align(label, LV_ALIGN_CENTER);
    lv_label_set_text(label, "Welcome to SALT TAB, click on the blue in the corner for nothing to happen!!");

    lv_obj_t *button = lv_button_create(screen);
    lv_obj_set_align(button, LV_ALIGN_OUT_RIGHT_BOTTOM);
    lv_obj_add_event_cb(button, my_clicky_event, LV_EVENT_CLICKED, NULL);
}

/** All set, just go */
void salt_tab_run()
{
    /* Make LVGL periodically execute its tasks */
    while (salt_running)
    {
        /* Provide updates to currently-displayed Widgets here. */
        lv_timer_handler();

        my_sleep(5); /*Wait 5 milliseconds before processing LVGL timer again*/
    }
}

/** main entrypoint from main.c */
void salt_tab_main()
{
    salt_tab_setup();
    salt_tab_run();
}
