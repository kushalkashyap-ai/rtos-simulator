cmake_minimum_required(VERSION 3.16)
project(rtos_simulator)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#enable threading
find_package(Threads REQUIRED)

add_executable(rtos_sim main.cpp)

target_link_libraries(rtos_sim
	Threads::Threads
	rt		#POSIX real-time (mq_open, timers)
)
