idf_component_register(
    SRCS
        screens/ui_Screen1.c
        ui.c
        components/ui_comp_hook.c
        ui_helpers.c
    INCLUDE_DIRS "."
    PRIV_REQUIRES lvgl
)