add_library(cli_listen OBJECT listen.c listen.h)
add_executable(nexamine main.c
  $<TARGET_OBJECTS:cli_listen>
)
target_link_libraries(nexamine PUBLIC nexa clog yacap caio)
