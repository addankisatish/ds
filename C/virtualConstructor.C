#include<iostream>
#include<memory>
using namespace std;

/*
 * Can we make a class constructor virtual in C++ to create polymorphic objects ?
 * 
 * NO, C++ being static typed language, compiler must be aware of the class type to
 * create the object. In other words, what type of object to be created is a compile
 * time decision from C++ compiler perspective.
 *
 * IF WE MAKE CONSTRUCTOR VIRTUAL, COIMPILER FLAGS AN ERROR.
 * IN FACT EXCEPT INLINE, NO OTHER KEYWORD IS ALLOWED IN THE DECLARATION OF THE CONSTRUCTOR.
 * 
 * Then how can we create required type of object at runtime ?
 *
 *             USE FACTORY DESIGN PATTERN
 */

class Pizza 
{
public:
    virtual int getPrice() const = 0;
    virtual ~Pizza() {};
};

class DeluxePizza : public Pizza
{
public:
    virtual int getPrice() const { return 250; }
    virtual ~DeluxePizza() {};
};

class MushroomPizza : public Pizza
{
public:
    virtual int getPrice() const { return 350; }
    virtual ~MushroomPizza() {};
};

class PizzaFactory
{
   public:
      enum PizzaType {
	  Mushroom,
          Deluxe
      };

      static unique_ptr<Pizza> createPizza(PizzaType pizzaType)
      {
          switch(pizzaType)
          {
	      case Mushroom:
		return unique_ptr<MushroomPizza>(new MushroomPizza);
                //return make_unique<Mushroom>();  // Support only C++14
	      case Deluxe:
		return unique_ptr<DeluxePizza>(new DeluxePizza);
		//return make_unique<Deluxe>(); //Support only C++14
	  }
      }
};


void pizza_information(PizzaFactory::PizzaType type)
{
    unique_ptr<Pizza> pizza = PizzaFactory::createPizza(type);
    cout << pizza->getPrice() << endl;
}
      
int main()
{
    pizza_information(PizzaFactory::Mushroom);
    pizza_information(PizzaFactory::Deluxe);
    return 0;
}

