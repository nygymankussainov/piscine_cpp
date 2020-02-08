#ifndef CONTACTINFO_CLASS_HPP
# define CONTACTINFO_CLASS_HPP

class ContactInfo {

public:

	std::string firstName;
	std::string lastName;
	std::string nickname;
	std::string login;
	std::string postalAddress;
	std::string email;
	std::string phone;
	std::string birthday;
	std::string favMeal;
	std::string underwearColor;
	std::string darkestSecret;

	ContactInfo( void );
	~ContactInfo( void );

	void		setInfo( void );
	void		getInfo( void ) const;
};

#endif
