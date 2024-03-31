#pragma once
#include <functional>
#include <vector>
#include <thread>
#include <condition_variable>
#include <queue>

using Task = std::function<void()>;

class ThreadPool
{
public:
	explicit ThreadPool(const size_t& numThreads)
	{
		start(numThreads);
	}
	~ThreadPool()
	{
		stop();
	}
	void submit(Task task)
	{
		// Scope for locks
		std::unique_lock<std::mutex> lock{ m_EventMutex };
		m_TasksQueue.emplace(/*std::move*/(task));
		m_EventCV.notify_one();
	}

private:
	std::queue<Task> m_TasksQueue;
	std::vector<std::thread> m_Threads;
	std::condition_variable m_EventCV;
	std::mutex m_EventMutex;
	bool m_Finished = false;
	void start(const size_t& numThreads)
	{
		for (auto ii = 0u; ii < numThreads; ii++)
		{
			m_Threads.emplace_back([=]() {
				while (true)
				{
					Task task;
					{
						std::unique_lock<std::mutex> lock{ m_EventMutex };

						m_EventCV.wait(lock, [=] {return m_Finished || !m_TasksQueue.empty(); });

						if (m_Finished || m_TasksQueue.empty())
							break;

						task = std::move(m_TasksQueue.front());
						m_TasksQueue.pop();
					}

					// To keep the critical section as least as possible
					// we dont need the critical section for the task to be executed, 
					// we provided the scope above.
					task();
				}
				});
		}
	}
	void stop() noexcept
	{
		std::unique_lock<std::mutex> lock{ m_EventMutex };
		m_Finished = true;

		m_EventCV.notify_all();

		for (auto& thread : m_Threads)
		{
			thread.join();
		}
	}
};
