cmake_minimum_required(VERSION 2.8 FATAL_ERROR)
#include(${CMAKE_CURRENT_SOURCE_DIR}/cppcms/CMakeLists.txt)
set(CMAKE_CONFIGURATION_TYPES "Debug;Release" CACHE STRING "limited configs" FORCE)

set(APP_NAME main)
project(${APP_NAME})

include(CheckCXXSourceCompiles)

find_program(EXE_TMPL_CC cppcms_tmpl_cc)

#############################################################################
#
# Required Lib List
#
#############################################################################

set(APP_REQUIRED_LIB
  cppcms
  booster
)

#############################################################################
#
# List views template
#
#############################################################################

set(VIEWS_TMPL
  ${CMAKE_CURRENT_SOURCE_DIR}/resources/views/layouts/app.tmpl
  ${CMAKE_CURRENT_SOURCE_DIR}/resources/views/layouts/app/home.tmpl
  ${CMAKE_CURRENT_SOURCE_DIR}/resources/views/layouts/app/dashboard.tmpl
  ${CMAKE_CURRENT_SOURCE_DIR}/resources/views/dashboard.tmpl
  ${CMAKE_CURRENT_SOURCE_DIR}/resources/views/home.tmpl

)

#############################################################################
#
# Application Cpp file need to build
#
#############################################################################

set(APP_SRC
  app/main.cpp
  app/core/router.cpp
  app/core/provider.cpp
  app/core/model.cpp
  app/core/view.cpp
  routes/web.cpp
  routes/api.cpp
  app/http/controllers/controller.cpp
  app/http/controllers/dashboard_controller.cpp
  app/http/controllers/home_controller.cpp

)

#############################################################################
#
# Setup various build flags for different supported compilers and systems
#
#############################################################################

if(CMAKE_COMPILER_IS_GNUCXX)
	check_cxx_source_compiles(
		"#if __GNUC__ < 4
		#error
		#endif
		int main() {}"
		GCC_IS_GCC4)

	set(CXX_FLAGS "-Wall -Wextra")
	set(C_FLAGS "-Wall -Wextra")

	if(CMAKE_SYSTEM_NAME STREQUAL "SunOS")
		set(CXX_FLAGS "${CXX_FLAGS} -pthreads")
	endif()

	if(NOT GCC_IS_GCC4)
		# Uninitalized checks are bogous under gcc-3.4
		set(CXX_FLAGS "${CXX_FLAGS} -Wno-uninitialized")
	endif()

	if(IS_WINDOWS)
		if(GCC_IS_GCC4) 
			# Very important, otherwise process would not start under cygwin
			set(CMAKE_CXX_LINK_FLAGS "${CMAKE_CXX_LINK_FLAGS} -Wl,--enable-auto-import")
		else()
			# gcc-3 does not have shared library for libstdc++ -- cause dll faitures with locale
			set(DISABLE_SHARED ON)
		endif()
	endif()

	if(CMAKE_SYSTEM_NAME STREQUAL "FreeBSD" OR CMAKE_SYSTEM_NAME STREQUAL "NetBSD")
		message("Addign rdynamic")
		set(CMAKE_CXX_LINK_FLAGS "${CMAKE_CXX_LINK_FLAGS} -rdynamic")
	endif()

elseif(CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
	set(CXX_FLAGS "-Wall -Wextra")
	if(CMAKE_SYSTEM_NAME STREQUAL "FreeBSD")
		set(CMAKE_CXX_LINK_FLAGS "${CMAKE_CXX_LINK_FLAGS} -rdynamic")
	endif()

elseif(CMAKE_CXX_COMPILER_ID STREQUAL "Intel")
	set(CXX_FLAGS "-Wall")
	set(C_FLAGS "-Wall")
elseif(MSVC)
	set(CXX_FLAGS "/EHsc /W3")
	set(C_FLAGS "/W3")
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "SunPro")
	#
	# We use STL port under Sun Studio, standard library is broken
	#
	
	set(CXX_FLAGS "-library=stlport4 -xannotate=no")

	if(CMAKE_SYSTEM_NAME STREQUAL "SunOS")
		set(CXX_FLAGS "${CXX_FLAGS} -mt")
	endif()
endif()

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${CXX_FLAGS}")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${C_FLAGS}")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)
#############################################################################
#
# Build project
#
#############################################################################

# Views build
set(VIEW_SKIN bootstrap_skin)
add_custom_command(
  OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/view.cpp
	COMMAND ${EXE_TMPL_CC}
    -d views
    -o ${CMAKE_CURRENT_BINARY_DIR}/view.cpp 
	  ${VIEWS_TMPL}
	DEPENDS ${VIEWS_TMPL}
)
add_library(${VIEW_SKIN} SHARED ${CMAKE_CURRENT_BINARY_DIR}/view.cpp)
target_link_libraries(${VIEW_SKIN} ${BOOSTER} ${CPPCMS})

# Application build
add_executable(${APP_NAME} ${APP_SRC})
target_link_libraries(${APP_NAME} ${APP_REQUIRED_LIB})
