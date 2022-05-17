#include <iostream>
#include "Node.h"
#include "Dictionary.h"
#include "Person.h"
#include "Linked_List.h"
int main()
{
  std::cout << "Array Size: 10" << std::endl;
  std::cout << "\n";
  Dictionary *d = new Dictionary();
  Person *p = new Person("John", "Dew", 1);
  
  try{
	  //Check Insertions and Searches
	  d->insertPerson(p);
	  std::cout << "Retrieving Person: " << d->retrievePerson(p)->get_name() << std::endl;
	  std::cout << std::endl;
	  
	  p = new Person("Mark", "K.", 2);
	  d->insertPerson(p);
	  std::cout << "Retrieving Person: " << d->retrievePerson(p)->get_name() << std::endl;
	  std::cout << std::endl;
		 
	  p = new Person("Kronos", "Vlander", 3);
	  d->insertPerson(p);
	  std::cout << "Retrieving Person: " << d->retrievePerson(p)->get_name() << std::endl;
	  std::cout << std::endl;
		 
	  p = new Person("John", "Dex", 4);
	  d->insertPerson(p);
	  std::cout << "Retrieving Person: " << d->retrievePerson(p)->get_name() << std::endl;
	  std::cout << std::endl;
		 
	  p = new Person("John", "Dexx", 5);
	  d->insertPerson(p);
	  std::cout << "Retrieving Person: " << d->retrievePerson(p)->get_name() << std::endl;
	  std::cout << std::endl;

	  std::cout << "Getting keys: " << d->getKeys() << std::endl;
	  p = new Person("DNEXIST", ".", 6);
	  std::cout << "Retrieving Nonexisting Person: " << d->retrievePerson(p)->get_name() << std::endl; //nullptr
	  std::cout << std::endl;
	  d->runTests();
	  
} catch(...){
	std::cout << "Invalid Person identified (nullptr)\n";
}

	delete d;
	delete p;
  return 0;
}

