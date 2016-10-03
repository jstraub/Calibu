
find_path(
  CVars_INCLUDE_DIRS
  NAMES CVar.h cvars/CVar.h
  PATHS /usr/include /usr/local/include
)

find_library(
  CVars_LIBRARIES
  NAMES cvars libcvars
  PATHS /usr/lib /usr/local/lib
)

message("Cvars finding")
message(${CVars_LIBRARIES})
message(${CVars_INCLUDE_DIRS})


IF(CVars_INCLUDE_DIRS AND CVars_LIBRARIES)
   SET(CVars_FOUND TRUE)
ENDIF()

#SET( CVars_LIBRARIES  cvars CACHE INTERNAL "CVars libraries" FORCE )
#SET( CVars_INCLUDE_DIRS   CACHE INTERNAL "CVars include directories" FORCE )
SET( CVars_LIBRARY_DIRS  CACHE INTERNAL "CVars library directories" FORCE )

mark_as_advanced( CVars_LIBRARIES )
mark_as_advanced( CVars_LIBRARY_DIRS )
mark_as_advanced( CVars_INCLUDE_DIRS )
