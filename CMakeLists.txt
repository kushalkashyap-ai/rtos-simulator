cmake_minimum_required(VERSION 3.16)
project(rtos_simulator)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#enable threading
find_package(Threads REQUIRED)

file(GLOB KERNEL_SOURCES "kernel/*.cpp")
file(GLOB KERNEL_HEADERS "kernel/*.hpp")

add_executable(rtos_sim 
	main.cpp
	${KERNEL_SOURCES}
)

target_include_directories(rtos_sim PRIVATE
	${CMAKE_SOURCE_DIR}
)

target_link_libraries(rtos_sim
	Threads::Threads
	rt		#POSIX real-time (mq_open, timers)
)
