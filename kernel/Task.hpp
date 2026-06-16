#pragma once
#include <functional>
#include <string>

class Task{

public:
	enum class TaskState{
		//e_new,
		e_Ready,
		e_Running,
		e_Blocked,
		//e_ready_suspended,
		//e_blocked_suspended,
		//e_exit,
		//e_preempted
	};

	Task(std::string taskname,int taskpriority,std::function<void()> taskFunc);
	std::string taskName() const;
	int taskPriority() const;
	TaskState taskState() const;

	void setTaskState(TaskState newState);
	void run();
	~Task();
private:
	std::string m_taskName;
	int m_taskPriority;
	TaskState m_taskState;
	std::function<void()> m_taskFunction;

};
