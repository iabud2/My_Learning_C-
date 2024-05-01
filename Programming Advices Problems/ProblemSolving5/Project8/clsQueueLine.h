#pragma once
#include <iostream>
#include <queue>
#include <stack>
#include "clsDate.h"
using namespace std;

class clsQueueLine
{
private:

	int _TotalTickets = 0;
	string _Prefix;
	int _AverageServeTime = 0;

	class clsTicket
	{
	private:
		int _Number = 0;
		string _Prefix;
		string _TicketTime;
		int _WaitingClients = 0;
		int _AverageServeTime = 0;
		int _ExpectedServeTime = 0;

	public:

		clsTicket(int Number, string Prefix, int WaitingClients, int AverageServeTime)
		{
			_Number = Number;
			_Prefix = Prefix;
			_TicketTime = clsDate::GetSystemDateTimeString();
			_AverageServeTime = AverageServeTime;
			_WaitingClients = WaitingClients;
		}

		int TicketNumber()
		{
			return _Number;
		}

		string Prefix()
		{
			return _Prefix;
		}

		string TicketTime()
		{
			return _TicketTime;
		}

		int AverageServetime()
		{
			return _AverageServeTime;
		}

		int WaitingClients()
		{
			return _WaitingClients;
		}

		int ExpectedServeTime()
		{
			return _AverageServeTime * _WaitingClients;
		}

		string FullNumber()
		{
			return (_Prefix + to_string(_Number));
		}

		void Print()
		{
			cout << "\n\t\t\t  _______________________\n";
			cout << "\n\t\t\t\t" << FullNumber();
			cout << "\n\t\t\t" << TicketTime();
			cout << "\n\t\t\t    Waiting Clients : " << WaitingClients();
			cout << "\n\t\t\t      Serve Time In : ";
			cout << "\n\t\t\t       " << ExpectedServeTime() << " Minutes.";
			cout << "\n\t\t\t  _______________________\n";
		}
	};
	
public:

	queue <clsTicket> QueueLine;

	clsQueueLine(string Prefix, int AverageServeTime)
	{
		_Prefix = Prefix;
		_AverageServeTime = AverageServeTime;
		_TotalTickets = 0;
	}

	void IssueTicket()
	{
		_TotalTickets++;
		clsTicket Ticket(_TotalTickets, _Prefix, WaitingClients(), _AverageServeTime);
		QueueLine.push(Ticket);
	}

	int WaitingClients()
	{
		return QueueLine.size();
	}

	string WhoIsNext()
	{
		if (QueueLine.empty())
		{
			return "\nNo clients left.\n";
		}
		else
		{
			return QueueLine.front().FullNumber();
		}
	}

	bool ServeNextClient()
	{
		if (QueueLine.empty())
			return false;
		else
			QueueLine.pop();
		
		return true;
	}

	void PrintInfo()
	{
		cout << "\n\t\t\t _________________________\n";
		cout << "\n\t\t\t\tQueue Info";
		cout << "\n\t\t\t _________________________\n";
		cout << "\n\t\t\t    Prefix   = " << _Prefix;
		cout << "\n\t\t\t    Total Tickets   = " << _TotalTickets;
		cout << "\n\t\t\t    Served Clients  = " << ServedClients();
		cout << "\n\t\t\t    Wating Clients  = " << WaitingClients();
		;
		cout << "\n\t\t\t _________________________\n";
		cout << "\n";
	}

	int ServedClients()
	{
		return _TotalTickets - WaitingClients();
	}

	void PrintTicketsLineLTR()
	{
		if (QueueLine.empty())
		{
			cout << "\n\t\tTickets : No Tickets Available In Queeue.\n";
			return;
		}

		queue <clsTicket> TempQueue = QueueLine;
		stack <clsTicket> StackLine;
		while (!TempQueue.empty())
		{
			StackLine.push(TempQueue.front());
			TempQueue.pop();
		}
		
		cout << "\n\t\tTickets : ";
		while (!StackLine.empty())
		{
			clsTicket Ticket = StackLine.top();
			cout << " " << Ticket.FullNumber() << " -->";
			StackLine.pop();
		}
		cout << endl;
	}

	void PrintTicketsLineRTL()
	{
		if (QueueLine.empty())
		{
			cout << "\n\t\tTickets : No Tickets Available In Queeue.\n";
			return;
		}
		queue <clsTicket> TempQueueLine = QueueLine;
		cout << "\n\t\tTickets : ";
		while (!TempQueueLine.empty())
		{
			clsTicket Ticket = TempQueueLine.front();
			cout << " " << Ticket.FullNumber() << " -->";
			TempQueueLine.pop();
		}
		cout << "\n";		
	}

	void PrintAllTickets()
	{
		cout << "\n\n\t\t\t       ---Tickets---";
		if (QueueLine.empty())
		{
			cout << "\n\n\t\t\t     ---No Tickets---\n";
			return;
		}
		queue <clsTicket> TempTicketsQueue = QueueLine;

		while (!TempTicketsQueue.empty())
		{
			TempTicketsQueue.front().Print();
			TempTicketsQueue.pop();
		}
	}






};