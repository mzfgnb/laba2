#pragma once
#include <string>
#include "../Base/Entity.h"


class Mail : public Entity {
public:
	std::string sender;
	std::string destination;
	std::string body;
	std::string date;

    void print() const override {
        std::cout << "From: " << sender << "\n"
            << "To: " << destination << "\n"
            << "Body: " << body << "\n"
            << "Date: " << date << "\n";
    }

    bool less(const Entity& other) const override {
        const Mail& m = dynamic_cast<const Mail&>(other);
        return sender < m.sender;
    }

	void get_mails();
	void send_mail();
	void PrintInfo();
};
