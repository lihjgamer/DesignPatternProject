#include "Command.h"


CCommand::CCommand()
{
	from = 0;
	to = 0;
	cmd = 0;
}

CCommand::CCommand(int from, int to, int cmd)
{
	this->from = from;
	this->to = to;
	this->cmd = cmd;
}

CCommand::~CCommand()
{

}
