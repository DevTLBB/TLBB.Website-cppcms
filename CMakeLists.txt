cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

#include(${CMAKE_CURRENT_SOURCE_DIR}/cppcms/CMakeLists.txt)

set(CMAKE_CONFIGURATION_TYPES "Debug;Release" CACHE STRING "limited configs" FORCE)

set(APP_NAME main)

project(${APP_NAME})

set(APP_REQUIRED_LIB
  cppcms
  booster
)

set(APP_SRC
  app/main.cpp
	app/core/router.cpp
	routes/web.cpp
	routes/api.cpp
	app/http/controllers/controller.cpp
)

add_executable(${APP_NAME} ${APP_SRC})

target_link_libraries(${APP_NAME} ${APP_REQUIRED_LIB})
