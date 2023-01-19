#include "Span.hpp"

Span::Span(void): _N(0), _table() {}
Span::Span(unsigned int N): _N(N), _table() {}
Span::~Span(void) {}
Span::Span(Span const &toCopy) {
	*this = toCopy;
}
Span const &Span::operator=(Span const &toCopy) {
	if (this == &toCopy)
		return *this;
	// Using assignment operator to copy one // vector to other
    _table = toCopy._table;
	return *this;
}

void	Span::addNumber(int const &nbr) {
	if (_table.size() < _N)
		_table.push_back(nbr);
	else
		throw Span::FullException();
}
void	Span::addMultipleNumbers(int const &nbr, int const &times) {
	if (_table.size() + times < _N)
		_table.insert(_table.end(), times, nbr);
	else
		throw Span::FullException();
}

unsigned int	Span::longestSpan(void) {
	if (_table.size() > 1) {
		std::vector<int>::iterator max = max_element(_table.begin(), _table.end());
		std::vector<int>::iterator min = min_element(_table.begin(), _table.end());
		return *max - *min;
	} else
		throw Span::SpanException();
}
unsigned int	Span::shortestSpan(void) {
	int sh;

	if (_table.size() > 1) {
		std::vector<int>::iterator it1;
		std::vector<int>::iterator it2;
		for (it1 = _table.begin(); it1 != _table.end(); it1++) {
			for (it2 = _table.begin(); it2 != _table.end(); it2++) {
				if (it1 != it2 && std::abs(*it1 - *it2) < sh )
					sh = std::abs(*it1 - *it2);
			}
		}
		return sh;
	} else
		throw Span::SpanException();
}

const char* Span::FullException::what() const throw() {
	return "Exception : table is full\n";
}

const char* Span::SpanException::what() const throw() {
	return "Exception : table has less than 2 elements, cannot find span\n";
}
