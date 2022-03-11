#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "List.h"

OList *list = new OList();
TEST_CASE("Test"){
	//The other methods are demonstrated when main is run.
	list->insert(1);	//Insert first element
	list->insert(0);//Insert at location 0
	list->insert(3);//Insert after last element
	list->insert(2);//Insert between 1 and 3
	
	//True
	CHECK (list->contains(1)  == 1);
	CHECK (list->contains(0)  == 1);
	CHECK (list->contains(3)  == 1);
	CHECK (list->contains(2)  == 1);
	
	//False
	CHECK (list->contains(-1)  == 0);
	CHECK (list->contains(5)  == 0);
	CHECK (list->contains(3000)  == 0);
	
	CHECK (list->get(0)  == 0);
	CHECK (list->get(1)  == 1);
	CHECK (list->get(2)  == 2);
	CHECK (list->get(3)  == 3);
	CHECK (list->get(4)  == -1);
}

