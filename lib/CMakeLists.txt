add_library(ctlsock OBJECT ctlsock.c ctlsock.h)
add_library(nexa SHARED 
  $<TARGET_OBJECTS:ctlsock>
  nexamine.c
)
