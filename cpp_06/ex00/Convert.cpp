#include "Convert.hpp"

Convert::Convert(void): _input("0") {
    setType(_input);
    convertAndPrint();
    return;
}
Convert::~Convert(void) {
    return;
}
Convert::Convert(std::string str): _input(str) {
	setType(_input);
	convertAndPrint();
    return;
}
Convert::Convert(Convert const &toCopy) {
    *this = toCopy;
    return;
}
Convert& Convert::operator=(Convert const &toCopy) {
    if (this == &toCopy)
        return *this;
    _input = toCopy._input;
    _type = toCopy._type;
    return *this;
}

void    Convert::setType(std::string const &str) {
    int i = 0;

    //check special values
    if (str == "-inf" || str == "inf" || str == "+inf" || str == "nan") {
        _type = T_DOUBLE;
        return;
    }
    if (str == "-inff" || str == "inff" || str == "+inff" || str == "nanf") {
        _type = T_FLOAT;
        return;
    }

    //check char
    if (str.size() == 1 && isprint(str[0]) && !isdigit(str[0])) {
        _type = T_CHAR;
        return;
    }

    //check int or float
    while (str[i] && (str[i] == '+' || str[i] == '-')) {
        i++;
    }
    while (str[i] && isdigit(str[i])) {
        i++;
    }
    if (!str[i]) {
        _type = T_INT;
        return;
    } else if (str[i] == 'f' && str[0] != 'f' && !str[i +1]) {
        _type = T_FLOAT;
        return;
    }

    //check double or float
    i = 0;
    while (str[i] && (str[i] == '+' || str[i] == '-')) {
        i++;
    }
    while (str[i] && isdigit(str[i])) {
        i++;
    }
    if (str[i] == '.')
        i++;
    else
        throw BadInputException();
    while (str[i] && isdigit(str[i]))
        i++;
    if (!str[i]) {
        _type = T_DOUBLE;
        return;
    } else if (str[i] == 'f' && !str[i +1]) {
        _type = T_FLOAT;
        return;
    }

    throw BadInputException();
}

void    Convert::convertAndPrint() {
    switch(_type) {
        case T_CHAR:
            castChar();
            break;
        case T_INT:
            castInt();
            break;
        case T_DOUBLE:
            castDouble();
            break;
        case T_FLOAT:
            castFloat();
            break;
        default:
            throw BadInputException();
    }
}

//setprecision : Sets the decimal precision to be used to format floating-point values on output operations.

// Casting and printing
void    Convert::castChar(void) {
	char c = _input[0];

    std::cout << "char :";
	if(!isprint(c))
		std::cout << "Non displayable" << std::endl;
	else {
		std::cout << c << std::endl;
		std::cout << "int : " << static_cast<int>(c) << std::endl;
		std::cout << "float : " << std::fixed << std::setprecision(3) << static_cast<float>(c) << "f" << std::endl;
		std::cout << "double : " << std::fixed << std::setprecision(3) << static_cast<double>(c) <<std::endl;
	}
}
void    Convert::castInt(void) {
    long int nbr = strtol(_input.c_str(), NULL, 10); //protection overflow
    if (nbr < INT_MIN || nbr > INT_MAX)
        return (impossibleConversion());

    std::cout << "char : ";
	if(nbr < CHAR_MIN || nbr > CHAR_MAX)
		std::cout << "impossible" << std::endl;
	else if(!isprint(nbr))
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << static_cast<char>(nbr) << std::endl;

    std::cout << "int : " << nbr << std::endl;
	std::cout << "float : " << std::fixed << std::setprecision(3) << static_cast<float>(nbr) << "f" << std::endl;
	std::cout << "double : " << std::fixed << std::setprecision(3) << static_cast<double>(nbr) <<std::endl;
}
void    Convert::castFloat(void) {
	float nbr = strtof(_input.c_str(), NULL); //protection overflow float
	if (errno)
		return (impossibleConversion());

	std::cout << "char : ";
	if(round(nbr) < CHAR_MIN || round(nbr) > CHAR_MAX || isnanf(nbr))
		std::cout << "impossible" << std::endl;
	else if(!isprint(static_cast<char>(nbr)))
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << static_cast<char>(nbr) << std::endl;

	std::cout << "int : ";
	if (round(nbr) < INT_MIN || round(nbr) > INT_MAX || isnanf(nbr))
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<int>(nbr) << std::endl;

	std::cout << "float : " << std::fixed << std::setprecision(3)<< nbr << "f" << std::endl;
	std::cout << "double : " << std::fixed << std::setprecision(3) << static_cast<double>(nbr) <<std::endl;
}
void    Convert::castDouble(void) {
	double nbr = strtod(_input.c_str(), NULL);
	if (errno)
		return (impossibleConversion());

	std::cout << "char : ";
	if(round(nbr) < CHAR_MIN || round(nbr) > CHAR_MAX || std::isnan(nbr))
		std::cout << "impossible" << std::endl;
	else if(!isprint(static_cast<char>(nbr)))
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << static_cast<char>(round(nbr)) << std::endl;

	std::cout << "int : ";
	if (round(nbr) < INT_MIN || round(nbr) > INT_MAX || std::isnan(nbr))
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<int>(nbr) << std::endl;

	std::cout << "float : ";
    if (_input == "inf" || _input == "+inf")
        std::cout << "inff" << std::endl;
    else if (_input == "-inf")
        std::cout << "inff" << std::endl;
    else if (round(nbr) > __FLT_MAX__ || round(nbr) < -__FLT_MAX__ )
		std::cout << "impossible" << std::endl;
	else
	 	std::cout << std::fixed << std::setprecision(3) << static_cast<float>(nbr)<< "f" << std::endl;

	std::cout << "double : " << std::fixed << std::setprecision(3) << (nbr) <<std::endl;
}

// Error handling and Exception
void Convert::impossibleConversion() {
	std::cout << "char : impossible" << std::endl;
	std::cout << "int : impossible" << std::endl;
	std::cout << "float : impossible" << std::endl;
	std::cout << "double : impossible" << std::endl;
}

const char *Convert::BadInputException::what() const throw() {
	return ("Invalid input\n");
}
