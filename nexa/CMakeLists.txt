add_library(nexa_listen OBJECT listen.c listen.h)
add_library(nexa STATIC 
  $<TARGET_OBJECTS:nexa_listen>
)
