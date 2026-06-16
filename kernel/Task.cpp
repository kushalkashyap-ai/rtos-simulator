#include "Task.hpp"

Task::Task(std::string taskname,
		int taskpriority,
		std::function<void()>taskFunc):
	m_taskName(taskname),
	m_taskPriority(taskpriority),
	m_taskFunction(taskFunc),
	m_taskState(TaskState::e_Ready){
}

Task::~Task(){
    // Destructor implementation (if needed)
}
std::string Task::taskName()const {
	return m_taskName;
}

int Task::taskPriority() const{
	return m_taskPriority;
}

Task::TaskState Task::taskState() const{
	return m_taskState;
}

void Task::setTaskState(Task::TaskState newState){
	if(m_taskState!=newState){
		m_taskState = newState;
	}
}

void Task::run(){
	m_taskFunction();
}
