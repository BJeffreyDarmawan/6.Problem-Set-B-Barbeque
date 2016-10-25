#include<iostream>


using namespace std;

class Barbeque
{
	private:
		string my_Brand;
		string my_Model;
		bool coal=0, lightz=0;
	public:
		Barbeque(string, string);
		void loadCoals();
		void light();
		void cook();
		void reset();
		bool hasCoals();
		bool isLit();
		bool isCooking();
};

Barbeque::Barbeque(string brand, string model)
{
	this->my_Brand = brand;
	this->my_Model = model;
}

void Barbeque::loadCoals()
{
	cout << "Loading " << my_Brand << " " << my_Model << " with coals!" << endl;
	coal = true; //as what has been printed, it is already loaded with coals
}

void Barbeque::light()
{
	if(coal)
	{
		cout << "Lighting grill!!" << endl;
		lightz = true; //as what has been printed, the grill is lit!
	}
	else
		cout << "You need coal first!!" << endl;
		
}

void Barbeque::cook()
{
	if(lightz)
		cout << "Cooking! YAY!!" << endl;
	else
		cout << "You need to light it first!!" << endl;
}

void Barbeque::reset()
{
	coal = false;
	lightz = false;
}

bool Barbeque::hasCoals()
{
	return coal;
}

bool Barbeque::isLit()
{
	return lightz;
}

bool re_start();

int main()
{
	Barbeque bbq("Abc Grill", "Model Sexy");
	bool restart;
	do{
		restart = 0;
		cout << "=================================================="<<endl;
		bbq.loadCoals();
		if(bbq.hasCoals())
		{
			bbq.light();
			if(bbq.isLit())
			{
				bbq.cook();
				restart = re_start();
			}
			else
			{
				cout << "The grill should be lit, so this is an error!" << endl;
				bbq.reset();
				restart = 1;
			}	
		}
		else
		{
			cout << "The grill should have coals in it, so this is an error!" << endl;
			bbq.reset();
			restart = 1;
		}	
		
	} while (restart);
	
	cout << endl<< "Trial errors: " << endl;
	//trial
	bbq.loadCoals();
	bbq.light();
	bbq.cook(); //as procedure
	
	bbq.reset();
	
	bbq.light();
	bbq.loadCoals();
	bbq.cook();
	
	return 0;
}

bool re_start()
{
	string option, temp;
	cout << "Do you want to re-do the grill? "; cin >> option;
	for (int i = 0; i < option.length(); i++)
	{
		temp+=toupper(option[i]);
	}
	if(temp == "YES")
		return 1;
	else
		return 0;

}
