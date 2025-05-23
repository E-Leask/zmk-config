if(CONFIG_ZMK_MXT112S_POINTER)
    target_sources(app PRIVATE src/mxt112s/mxt112s_pointer.c)
    target_include_directories(app PRIVATE src/mxt112s)
endif()
