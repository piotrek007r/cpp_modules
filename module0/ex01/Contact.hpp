#include "repertory.hpp"

class Contact
{
  public:
  
	void setName(str name);
	void setSurname(str surname);
    void setNickname(str nickname);
	void setPhone(str phone_number);
	void setSecret(str darkest_secret);

	str getName();
    str getSurname();
	str getNickname();
    str getPhone();
    str getSecret();


  private:
	str name;
	str surname;
    str nickname;
	str phone_number;
	str darkest_secret;
};