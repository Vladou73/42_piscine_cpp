#include "MutantStack.hpp"

int main()
{
	std::cout << std::endl << "******** MutantStack iterator tests ********" << std::endl;
	{
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout << "size="<< mstack.size() << std::endl<< std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		//[...]
		mstack.push(0);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
		std::cout << *it << std::endl;
		++it;
		}
		std::stack<int> s(mstack);
	}

	std::cout << std::endl << "******** Compare results with list iterators ********" << std::endl;
	{
		std::list<int> mstack;
		mstack.push_back(5);
		mstack.push_back(17);
		std::cout << mstack.back() << std::endl;
		mstack.pop_back();
		std::cout<< "size=" << mstack.size() << std::endl<< std::endl;
		mstack.push_back(3);
		mstack.push_back(5);
		mstack.push_back(737);
		//[...]
		mstack.push_back(0);
		std::list<int>::iterator it = mstack.begin();
		std::list<int>::iterator ite = mstack.end();
		++it;
		--it;
		std::cout<< "iterate through container"<< std::endl;
		while (it != ite)
		{
		std::cout << *it << std::endl;
		++it;
		}
		std::list<int> s(mstack);
	}

{
	std::cout << std::endl << std::endl<< std::endl << "******** change type to string ********" << std::endl;
	MutantStack<std::string> mstack;
	mstack.push("a");
	mstack.push("b");
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << "size=" << mstack.size() << std::endl<< std::endl;
	mstack.push("c");
	mstack.push("d");
	mstack.push("e");
	//[...]
	mstack.push("f");
	MutantStack<std::string>::iterator it = mstack.begin();
	MutantStack<std::string>::iterator ite = mstack.end();
	++it;
	--it;
	std::cout<< "iterate through container"<< std::endl;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}

	std::cout << std::endl << std::endl<< std::endl << "******** TEST COPY CONSTRUCTOR ********" << std::endl;
	MutantStack<std::string> s(mstack);
	MutantStack<std::string>::iterator it2 = s.begin();
	MutantStack<std::string>::iterator ite2 = s.end();
	std::cout<< "iterate through copy container"<< std::endl;
	while (it2 != ite2)
	{
		std::cout << *it2 << std::endl;
		++it2;
	}
}

}
