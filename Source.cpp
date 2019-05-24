//ADT Set – using a SLL
#include <iostream>
#include "ShortTest.h"
#include "ExtendedTest.h"
#include "Set.h"
#include <assert.h>

using namespace std;

int main() {
	std::cout << "Short tests for Set ADT..." << std::endl;
	testAll();
	std::cout << "Extended tests for Set ADT..." << std::endl;
	testAllExtended();
	std::cout << "Tests for the extra function..." << std::endl;
	Set s;
	assert(s.getRange()==-1);
	s.add(5);
	s.add(1);
	assert(s.getRange() == 4);
	s.add(10);
	s.add(-3);
	assert(s.getRange() == 13);
	std::cout << "Succes! All tests passed!";
	system("pause");
	return 0;
}