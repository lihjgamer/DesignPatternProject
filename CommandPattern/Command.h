#pragma once

class CCommand
{
public:
	CCommand();
	CCommand(int from,int to,int cmd);
	virtual ~CCommand();

	int Cmd() const { return cmd; }
	void Cmd(int val) { cmd = val; }

	int To() const { return to; }
	void To(int val) { to = val; }

		int From() const { return from; }
	void From(int val) { from = val; }
private:
	int from;

	int to;

	int cmd;

};