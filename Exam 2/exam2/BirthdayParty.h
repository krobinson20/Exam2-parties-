#ifndef _BIRTHDAY_PARTY_H_
#define _BIRTHDAY_PARTY_H_

#include <iostream>
#include <list>
#include <vector>
#include <string>
#include "Party.h"
#include "BirthdayPartyTicket.h"

// FIXME 2: Create BirthdayParty and BirthdayPartyTicket to host birthday parties!
// FIXME 3: Update PartyFactory::factory() to allow it to be the ONLY method for creating a BirthdayParty
/**
* BirthdayParty is derived from Party
*/
class BirthdayParty : public Party
{
private:
	std::list<std::string> room;

	BirthdayParty() : Party() {}

	friend class PartyFactory;

public:


	PartyTicket * add(std::string name) {

		room.push_back(name);
		std::list<std::string>::iterator iter = room.begin();
		PartyTicket *birthdaypartyticket = new BirthdayPartyTicket(this, iter);
		return birthdaypartyticket;
	}

	void list()
	{

		std::list<std::string>::iterator ptr = room.begin();
		for (ptr; ptr != room.end(); ptr++)
		{
			std::cout << *ptr << std::endl;
		}
	}


	void remove(std::list<std::string>::iterator &it) {
		std::list<std::string>::iterator rmve = room.begin();
		for (rmve; rmve != room.end(); rmve++)
		{
		if (rmve == it)
		{
			room.erase(rmve);
			break;
		}

		}
	}
};

#endif