//==============================================
// Name:           Pedro Vitor do Carmo Saraiva Teixeira	
// Student Number: 100036193
// Email:          pvdo-carmo-saraiva-t@myseneca.ca
// Section:        NEF
// Workshop:       2 (DIY)
//==============================================
#ifndef SDDS_GIFT_H
#define SDDS_GIFT_H

namespace sdds {
	const int MAX_DESC = 15;
	const double MAX_PRICE = 999.99;
	const int MAX_PATTERN = 20;

	struct Wrapping {
	public:
		char* pattern;
	};

	struct Gift {
	public:
		char g_description[MAX_DESC + 1];
		double g_price;
		int g_units;
		Wrapping *wrap;
		int wrap_layers;
		char* pattern;
	};

	void gifting(char*);
	void gifting(double&);
	void gifting(int&);
	void gifting(Gift&);
	void display(const Gift&);
	bool wrap(Gift&);
	bool unwrap(Gift&);


}

#endif // !SDDS_GIFT_H
