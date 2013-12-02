#ifndef COMMANDQUEUE_H
#define COMMANDQUEUE_H

#include "command.h"

#include <queue>


class CommandQueue
{
public:
	void					push(const Command&);
	Command					pop();
	bool					isEmpty() const;


private:
	std::queue<Command>		mQueue;
};

#endif
