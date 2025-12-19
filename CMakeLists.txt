cmake_minimum_required(VERSION 3.20)
project(SearchEngine)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Fetch CURL
include(FetchContent)

FetchContent_Declare(
        curl
        GIT_REPOSITORY https://github.com/curl/curl.git
        GIT_TAG curl-8_5_0
)

# Configure CURL options
set(BUILD_SHARED_LIBS OFF CACHE BOOL "" FORCE)
set(CURL_STATICLIB ON CACHE BOOL "" FORCE)
set(BUILD_CURL_EXE OFF CACHE BOOL "" FORCE)
set(BUILD_TESTING OFF CACHE BOOL "" FORCE)
set(CURL_USE_SCHANNEL ON CACHE BOOL "" FORCE)
set(CURL_USE_LIBSSH2 OFF CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(curl)

# Create executable with just main.cpp
add_executable(SearchEngine main.cpp
        parser.cpp
        parser.hpp
        indexer.cpp
        indexer.hpp
        crawler.cpp
        crawler.hpp)

# Link CURL
target_link_libraries(SearchEngine PRIVATE CURL::libcurl)

# Windows-specific settings
if(WIN32)
    target_link_libraries(SearchEngine PRIVATE ws2_32 wldap32 crypt32 advapi32)
endif()