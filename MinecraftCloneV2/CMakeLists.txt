cmake_minimum_required (VERSION 3.25)

if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("MinecraftCloneV2")

find_package(glfw3 CONFIG REQUIRED)
find_package(glew CONFIG REQUIRED)
find_package(glm CONFIG REQUIRED)
find_package(spdlog CONFIG REQUIRED)

file(GLOB_RECURSE HEADERS  "include/*.hpp")
file(GLOB_RECURSE SRC "src/*.cpp")

include_directories("include")

add_executable (MinecraftCloneV2 ${HEADERS} ${SRC})
target_link_libraries(MinecraftCloneV2 PRIVATE GLEW::GLEW glfw spdlog::spdlog spdlog::spdlog_header_only glm::glm)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET MinecraftCloneV2 PROPERTY CXX_STANDARD 20)
endif()

	