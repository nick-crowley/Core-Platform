#############################################################################################
# Makefile                                                                                  #
#  _________                        __________.__          __    _____                      #
#  \_   ___ \  ___________   ____   \______   \  | _____ _/  |__/ ____\___________  _____   #
#  /    \  \/ /  _ \_  __ \_/ __ \   |     ___/  | \__  \\   __\   __\/  _ \_  __ \/     \  #
#  \     \___(  <_> )  | \/\  ___/   |    |   |  |__/ __ \|  |  |  | (  <_> )  | \/  Y Y  \ #
#   \______  /\____/|__|    \___  >  |____|   |____(____  /__|  |__|  \____/|__|  |__|_|  / #
#          \/                   \/                      \/                              \/  #
#############################################################################################
cmake_minimum_required (VERSION 3.8.2)

# Solution: CorePlatform
project (CorePlatform
	#DESCRIPTION "Simplifies development on Windows platform"
	LANGUAGES CXX)
message("solution: ${PROJECT_SOURCE_DIR}")

# Define base folder
set(BASE_FOLDER "${CMAKE_CURRENT_SOURCE_DIR}/")
set(OUTPUT_FOLDER "${BASE_FOLDER}build")

# Folders: Google.Test
#set(GTEST_INCLUDE_FOLDER "${BASE_FOLDER}3rdparty/google/include/")
#set(GTEST_SOURCE_FOLDER  "${BASE_FOLDER}3rdparty/google/src/")

# Folders: Project
set(PROJECT_EXTRA_FOLDER    "${BASE_FOLDER}extra/")
set(PROJECT_INCLUDE_FOLDER  "${BASE_FOLDER}include/")
set(PROJECT_SOURCE_FOLDER   "${BASE_FOLDER}src/")
set(PROJECT_RESOURCE_FOLDER "${BASE_FOLDER}res/")

# Folders: Test code
#set(PROJECT_TESTS_FOLDER         "${BASE_FOLDER}tests/")
#set(PROJECT_MOCKS_FOLDER         "${BASE_FOLDER}mocks/")
#set(PROJECT_SYSTEM_TESTS_FOLDER  "${BASE_FOLDER}stests/")

# Set Guideline Support Library contract violation behaviour
set(GSL_ASSERTION_BEHAVIOUR "GSL_THROW_ON_CONTRACT_VIOLATION")

# Set compiler options used by all modules
# /std:c++latest	: Preview ISO C++ 23 Standard
# /std:c17			: ISO C 17 Standard
# /Zc:preprocessor	: ISO C++20 Preprocessor
# /ZI				: PDBs for edit & continue
# /EHa				: Enable SEH and C++ exceptions
# /W4				: Warning level 4
# /wd4251			: Disable W4251: Classes containing fields of STL type (CRT compatibility warning)
# /wd4275			: Disable W4275: Classes containing bases of STL type (CRT compatibility warning)
# /wd4467           : Disable C4467: Usage of ATL attributes is deprecated
# /MTd				: Statically link against (debug) CRT
set(GLOBAL_COMPILER_OPTIONS "/std:c++latest /std:c17 /Zc:preprocessor /ZI /EHa /W4 /wd4251 /wd4275 /wd4467 /MTd")

# Set compiler options used by test modules
#set(GLOBAL_TEST_COMPILER_OPTIONS "${GLOBAL_COMPILER_OPTIONS} -DTEST_BUILD_CONTEXT -DGTEST_LINKED_AS_SHARED_LIBRARY=1")

# Set linker options used by all modules
set(GLOBAL_LINKER_OPTIONS "${GLOBAL_LINKER_OPTIONS} /SAFESEH:NO")

# Set global preprocessor directives:
# BOOST_CONFIG_SUPPRESS_OUTDATED_MESSAGE 	: Disable MSVC-2017 forward-compatibility warning
# _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS 	: Disable C++17 deprecation warnings
# _CRT_SECURE_NO_WARNINGS 					: Disable warnings about documented behaviour of CRT functions
# _SCL_SECURE_NO_WARNINGS					: Disable warnings about documented behaviour of C++ library functions
# GSL_ASSERTION_BEHAVIOUR 					: Globally set the contract-violation behaviour of GSL
# _UNICODE 									: Build everything in the UNICODE character set
add_definitions(
	-DBOOST_CONFIG_SUPPRESS_OUTDATED_MESSAGE 
	-D_SILENCE_ALL_CXX17_DEPRECATION_WARNINGS
	-D_CRT_SECURE_NO_WARNINGS
	-D_SCL_SECURE_NO_WARNINGS
	-D${GSL_ASSERTION_BEHAVIOUR}
	-D_UNICODE
	-DNOMINMAX)

# Set global include folders: 
# $ENV{BOOST_ROOT}	:	Boost headers
# $ENV{GSL_ROOT}	:	Guideline Support Library (GSL) headers
include_directories($ENV{BOOST_ROOT} $ENV{GSL_ROOT})

# Set global library folders:
# $ENV{BOOST_ROOT}/stage/lib	: Boost libraries
# ${OUTPUT_FOLDER}				: Solution output folder
link_directories($ENV{BOOST_ROOT}/stage/lib ${OUTPUT_FOLDER})
	
# Remove the 'RelWithDebInfo' and 'MinSizeRel' configurations
set(CMAKE_CONFIGURATION_TYPES Debug Release CACHE TYPE INTERNAL FORCE )
#set(CMAKE_CONFIGURATION_TYPES Debug CACHE TYPE INTERNAL FORCE )

# Source files
file(GLOB_RECURSE PROJECT_SOURCE_FILES
    "${PROJECT_SOURCE_FOLDER}*.h"
    "${PROJECT_SOURCE_FOLDER}*.cpp"
    )
	
# [OPTIMIZED] Source files to exclude by marking as header-only
file(GLOB_RECURSE PROJECT_SOURCE_IMPL_FILES
    "${PROJECT_SOURCE_FOLDER}*.cpp"
    )
set_source_files_properties(${PROJECT_SOURCE_IMPL_FILES} PROPERTIES 
    HEADER_FILE_ONLY ON
)

# Optimized-build files
file(GLOB_RECURSE PROJECT_SOURCE_CC_FILES
    "${PROJECT_SOURCE_FOLDER}*.cc"
    )
	
# Exported header files
file(GLOB_RECURSE PROJECT_INCLUDE_FILES
    "${PROJECT_INCLUDE_FOLDER}*.h"
    )

# Define macro controlling dllexport/import specifier
set(PROJECT_DLL_MACRO "BuildCorePlatformDLL")
set(PROJECT_LIB_MACRO "BuildCorePlatformStaticLib")

##############################################################################
#         _________ __          __  .__         .____    ._____.             #
#        /   _____//  |______ _/  |_|__| ____   |    |   |__\_ |__           #
#        \_____  \\   __\__  \\   __\  |/ ___\  |    |   |  || __ \          #
#        /        \|  |  / __ \|  | |  \  \___  |    |___|  || \_\ \         #
#       /_______  /|__| (____  /__| |__|\___  > |_______ \__||___  /         #
#               \/           \/             \/          \/       \/          #
##############################################################################
message("StaticLib: Generating project(s) from ${PROJECT_SOURCE_FOLDER} with ${PROJECT_INCLUDE_FOLDER}")

# Project: libCorePlatform
add_library(libCorePlatform STATIC 
	${PROJECT_SOURCE_FILES} 
	${PROJECT_SOURCE_CC_FILES} 
	${PROJECT_INCLUDE_FILES} 
    )
  
# Include folders
target_include_directories(libCorePlatform BEFORE
    PRIVATE
	${PROJECT_SOURCE_FOLDER} 
    PUBLIC
    ${PROJECT_INCLUDE_FOLDER}            
	)
	
# Differentiate the filename of the static library
set_target_properties(libCorePlatform PROPERTIES
					  #OUTPUT_NAME "libCorePlatform"
					  COMPILE_FLAGS "${GLOBAL_COMPILER_OPTIONS} -D${PROJECT_LIB_MACRO}")

#############################################################################
#  ________                              .__          .____    ._____.      #
#  \______ \ ___.__. ____ _____    _____ |__| ____    |    |   |__\_ |__    #
#   |    |  <   |  |/    \\__  \  /     \|  |/ ___\   |    |   |  || __ \   #
#   |    `   \___  |   |  \/ __ \|  Y Y  \  \  \___   |    |___|  || \_\ \  #
#  /_______  / ____|___|  (____  /__|_|  /__|\___  >  |_______ \__||___  /  #
#          \/\/         \/     \/      \/        \/           \/       \/   #
#############################################################################
message("DynamicLib: Generating project(s) from ${PROJECT_SOURCE_FOLDER} with ${PROJECT_INCLUDE_FOLDER}")

# Project: dllCorePlatform
add_library(dllCorePlatform SHARED 
	"${PROJECT_EXTRA_FOLDER}DllMain.cpp"
	${PROJECT_SOURCE_CC_FILES} 
    )
  
# Include folders
target_include_directories(dllCorePlatform BEFORE
    PRIVATE
	${PROJECT_SOURCE_FOLDER} 
    PUBLIC
    ${PROJECT_INCLUDE_FOLDER}            
	)
	
# Differentiate the filename of the static library
set_target_properties(dllCorePlatform PROPERTIES
					  OUTPUT_NAME "CorePlatform"
					  COMPILE_FLAGS "${GLOBAL_COMPILER_OPTIONS} -D${PROJECT_DLL_MACRO}")
					  
# Set project dependencies
#add_dependencies(dllCorePlatform
#	libCorePlatform
#)

##############################################################
#  ___________              __       _____                   #
#  \__    ___/___   _______/  |_    /  _  \ ______ ______    #
#    |    |_/ __ \ /  ___/\   __\  /  /_\  \\____ \\____ \   #
#    |    |\  ___/ \___ \  |  |   /    |    \  |_> >  |_> >  #
#    |____| \___  >____  > |__|   \____|__  /   __/|   __/   #
#               \/     \/                 \/|__|   |__|      #
##############################################################

# Project: appCorePlatform
add_executable(appCorePlatform
	"${PROJECT_EXTRA_FOLDER}main.cpp"
	#${PROJECT_RESOURCE_FILES}
    )

# Include folders
target_include_directories(appCorePlatform BEFORE
    PRIVATE
	${PROJECT_EXTRA_FOLDER} 
	${PROJECT_RESOURCE_FOLDER} 
    PUBLIC
    ${PROJECT_INCLUDE_FOLDER}            
	)
	
# Set linker dependencies
target_link_libraries(appCorePlatform
	dllCorePlatform
)

# Set compiler & linker flags
set_target_properties(appCorePlatform PROPERTIES
					  COMPILE_FLAGS "${GLOBAL_COMPILER_OPTIONS} -D${PROJECT_LIB_MACRO}"
					  LINK_FLAGS "${GLOBAL_LINKER_OPTIONS} /SUBSYSTEM:CONSOLE"
					  OUTPUT_NAME "appCorePlatform")

# Set project dependencies
add_dependencies(appCorePlatform
	dllCorePlatform
)

#################################################################################
#     ___________.__.__           .____                                __   
#     \_   _____/|__|  |   ____   |    |   _____  ___.__. ____  __ ___/  |_ 
#      |    __)  |  |  | _/ __ \  |    |   \__  \<   |  |/  _ \|  |  \   __\
#      |     \   |  |  |_\  ___/  |    |___ / __ \\___  (  <_> )  |  /|  |  
#      \___  /   |__|____/\___  > |_______ (____  / ____|\____/|____/ |__|  
#          \/                 \/          \/    \/\/                        
#################################################################################

# Extra files
file(GLOB_RECURSE PROJECT_EXTRA_FILES
    "${PROJECT_EXTRA_FOLDER}*.h"
    "${PROJECT_EXTRA_FOLDER}*.cpp"
    )
	
# Resource files
#file(GLOB_RECURSE PROJECT_RESOURCE_FILES
#	"${PROJECT_RESOURCE_FOLDER}*.*"
#    )

# Project file groups
source_group(TREE ${PROJECT_SOURCE_FOLDER}    PREFIX "Build Files"    FILES ${PROJECT_SOURCE_CC_FILES}})
source_group(TREE ${PROJECT_EXTRA_FOLDER}     PREFIX "Extra Files"    FILES ${PROJECT_EXTRA_FILES})
source_group(TREE ${PROJECT_INCLUDE_FOLDER}   PREFIX "Header Files"   FILES ${PROJECT_INCLUDE_FILES})
source_group(TREE ${PROJECT_SOURCE_FOLDER}    PREFIX "Source Files"   FILES ${PROJECT_SOURCE_FILES})
source_group(TREE ${PROJECT_RESOURCE_FOLDER}  PREFIX "Resource Files" FILES ${PROJECT_RESOURCE_FILES})

# unit-test file groups
#source_group(TREE ${PROJECT_TESTS_FOLDER}   PREFIX "Build Files"  FILES ${PROJECT_UNIT_TEST_CC_FILES})
#source_group(TREE ${PROJECT_TESTS_FOLDER}   PREFIX "Test Files"   FILES ${PROJECT_UNIT_TEST_FILES})
#source_group(TREE ${PROJECT_MOCKS_FOLDER}   PREFIX "Mock Files"   FILES ${PROJECT_MOCK_FILES})

# system-test file groups
#source_group(TREE ${PROJECT_SYSTEM_TESTS_FOLDER}   PREFIX "Build Files"  FILES ${PROJECT_SYSTEM_TEST_CC_FILES})
#source_group(TREE ${PROJECT_SYSTEM_TESTS_FOLDER}   PREFIX "Test Files"   FILES ${PROJECT_SYSTEM_TEST_FILES})
