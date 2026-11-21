#include "salt_tab_main.hpp"
#include "lv_demos.h"
#include "my_sleep.hpp"

static bool salt_running = true;

void salt_tab_setup()
{
    lv_obj_t *screen = lv_screen_active();
    lv_obj_set_style_bg_color(screen, lv_color_hex(0x003a57), 0);
    lv_obj_set_style_text_color(screen, lv_color_hex(0xffffff), 0);
    lv_obj_t *label = lv_label_create(screen);
    lv_obj_set_align(label, LV_ALIGN_CENTER);
    lv_label_set_text(label, "Welcome to SALT TAB, case design by Hosea!!");
}

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

void salt_tab_main()
{
    salt_tab_setup();
    salt_tab_run();
}
