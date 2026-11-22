#include "salt_tab_main.hpp"
#include "lv_demos.h"
#include "esp_log.h"

static const char *TAG = "salt_tab";

/** callback for the label */
extern "C" void my_clicky_event(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t * btn = lv_event_get_target_obj(e);
    if(code == LV_EVENT_CLICKED) {
        ESP_LOGI(TAG, "Clicky on the label");
        static uint8_t cnt = 0;
        /*Get the first child of the button which is the label and change its text*/
        lv_obj_t * label = lv_obj_get_child(btn, 0);

        if (cnt < 20) {
            cnt++;
            lv_label_set_text_fmt(label, "Button-click-me: %d", cnt);
        } else {
            lv_label_set_text_fmt(label, "That's enough: %d", cnt);
        }
    }
}

/** setup the initial screen */
void salt_tab_setup(void)
{
    // lv_obj_t *screen = lv_screen_active();
    // lv_obj_set_style_bg_color(screen, lv_color_hex(0x003a57), 0);
    // lv_obj_set_style_text_color(screen, lv_color_hex(0xffffff), 0);

    lv_obj_t * btn = lv_button_create(lv_screen_active());     /*Add a button the current screen*/
    lv_obj_set_pos(btn, 10, 10);                            /*Set its position*/
    lv_obj_set_size(btn, 300, 50);                          /*Set its size*/
    lv_obj_add_event_cb(btn, my_clicky_event, LV_EVENT_ALL, NULL);           /*Assign a callback to the button*/
    lv_obj_t * label = lv_label_create(btn);          /*Add a label to the button*/
    lv_label_set_text(label, "Button-click me");                     /*Set the labels text*/
    lv_obj_center(label);
}

/** main entrypoint from main.c */
void salt_tab_main(void)
{
    salt_tab_setup();
}

