#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Node.h"
#include "Dictionary.h"
#include "Linked_List.h"
#include "Person.h"

TEST_CASE("Testing Hash methods"){
	 Dictionary *d = new Dictionary();
	 Person *p = new Person("John", "Dew", 1);
	 
  	 d->insertPerson(p);
  	 CHECK(d->retrievePerson(p)->get_name() == "John, Dew");
  	 
  	 p = new Person("Mark", "K.", 2);
	 d->insertPerson(p);
    CHECK(d->retrievePerson(p)->get_name() == "Mark, K.");
	  
    p = new Person("Kronos", "Vlander", 3);
	 d->insertPerson(p);
	 CHECK(d->retrievePerson(p)->get_name() == "Kronos, Vlander");
	  
	  p = new Person("John", "Dex", 4);
	  d->insertPerson(p);
	  CHECK(d->retrievePerson(p)->get_name() == "John, Dex");
	  	
	  p = new Person("John", "Dexx", 5);
	  d->insertPerson(p);
	  CHECK(d->retrievePerson(p)->get_name() == "John, Dexx");
	  
	  /*
	  Exception message is displayed in ./main
	  	p = new Person("DNEXIST", ".", 6);
	 */
	 std::string s = "\nKronos, Vlander\nMark, K.\nJohn, Dew\nJohn, Dex\nJohn, Dexx\n";
	 CHECK(d->getKeys() == s);
	 
	 delete d;
	 delete p;
}
