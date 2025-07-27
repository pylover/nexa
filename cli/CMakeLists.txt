add_library(cli_listen OBJECT listen.c listen.h)
add_library(cli STATIC cli.c cli.h
  $<TARGET_OBJECTS:cli_listen>
)
target_link_libraries(cli PUBLIC nexa clog yacap caio)
