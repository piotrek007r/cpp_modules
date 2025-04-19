#include "repertory.hpp"

	void Contact::setName(str name)
	{
		this->name = name;
	}
	void Contact::setSurname(str surname)
	{
		this->surname = surname;
	}
    void Contact::setNickname(str nickname)
	{
		this->nickname = nickname;
	}
	void Contact::setPhone(str phone_number)
	{
		this->phone_number = phone_number;
	}
	void Contact::setSecret(str darkest_secret)
	{
		this->darkest_secret = darkest_secret;
	}

    str Contact::getName()
	{
		return (this->name);
	}
    str Contact::getSurname()
	{
		return (this->surname);
	}
	str Contact::getNickname()
    {
        return (this->nickname);
    }
    str Contact::getPhone()
    {
        return (this->phone_number);
    }
    str Contact::getSecret()
	{
		return (this->darkest_secret);
	}