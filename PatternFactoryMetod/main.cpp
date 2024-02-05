#include <iostream>

using namespace std;

class Product abstract {
public:
	virtual void Set(string) {};
	virtual string Get() abstract;
	virtual void Operation() abstract;
};

class ConcreteProduct : Product {
private:
	string data;
public:
	ConcreteProduct(string data = "") : data(data) {};
	void Set(string data) { this->data = data; };
	string Get() { return data; }

	void Show(string msg) {
		cout << msg << "=>" << data << endl;
	}

	void Operation() override {
		cout << "ConcreteProduct::Operation() =>" << data << endl;
	}
};

class Creator abstract {
public:
	virtual Product* FactoryMethod(string) abstract;
};

class ConcreteCreator : Creator {
public:
	Product* FactoryMethod(string data) override {
		return (Product*) new ConcreteProduct(data);
	}
};

int main() 
{
	Product* product = nullptr;
	ConcreteCreator creator;

	product = creator.FactoryMethod("Air");

	product->Operation();
	
	((ConcreteProduct*)product)->Show("Product");

	if (product) delete product;

	return 0;
}