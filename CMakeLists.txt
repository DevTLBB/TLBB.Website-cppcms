cmake_minimum_required(VERSION 2.8 FATAL_ERROR)
#include(${CMAKE_CURRENT_SOURCE_DIR}/cppcms/CMakeLists.txt)
set(CMAKE_CONFIGURATION_TYPES "Debug;Release" CACHE STRING "limited configs" FORCE)

set(APP_NAME main)
project(${APP_NAME})

find_program(TMPLCC cppcms_tmpl_cc)

# Required Lib List
set(APP_REQUIRED_LIB
  cppcms
  booster
)

# List views template
set(VIEWS_TMPL
  ${CMAKE_CURRENT_SOURCE_DIR}/resources/views/home.tmpl
	${CMAKE_CURRENT_SOURCE_DIR}/resources/views/dashboard.tmpl

)

# Application Cpp file need to build
set(APP_SRC
  app/main.cpp
	app/core/router.cpp
	routes/web.cpp
	routes/api.cpp
	app/http/controllers/controller.cpp
)

# Views build
add_custom_command(
  OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/view.cpp
  COMMAND ${TMPLCC}
    -d views
    -o ${CMAKE_CURRENT_BINARY_DIR}/view.cpp 
	  ${VIEWS_TMPL}
	DEPENDS ${VIEWS_TMPL}
)
add_library(view SHARED ${CMAKE_CURRENT_BINARY_DIR}/view.cpp)
target_link_libraries(view ${BOOSTER} ${CPPCMS})

# Application build
add_executable(${APP_NAME} ${APP_SRC})
target_link_libraries(${APP_NAME} ${APP_REQUIRED_LIB})
