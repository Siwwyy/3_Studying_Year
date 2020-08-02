#include "Parser.h"

using namespace std;

Parser::Parser():
	counter(0),
	m_to_parse(""),
	to_return("")
{
	m_to_parse_iter = m_to_parse.begin();
}

Parser::Parser(const std::string & to_parse):
	counter(0),
	m_to_parse(to_parse),
	to_return("")
{
	m_to_parse_iter = m_to_parse.begin();
}

Parser::Parser(const Parser & Object)
{
	this->m_to_parse = Object.m_to_parse;
	this->m_to_parse_iter = Object.m_to_parse_iter;
}

const std::string & Parser::Parse_String()
{
	to_return = "";
	if (counter == amout_of_operations())
	{
		m_to_parse_iter = m_to_parse.begin();
		counter = 0;
	}
	counter++;
	for (m_to_parse_iter; m_to_parse_iter != m_to_parse.end(); ++m_to_parse_iter)
	{
		if (*m_to_parse_iter == ' ')
		{
			++m_to_parse_iter;
			return to_return;
		}
		else
		{
			to_return += *m_to_parse_iter;
		}
	}
	return to_return;
}

const int Parser::amout_of_operations()
{
	int operations = 0;
	if (*m_to_parse.rbegin() == ' ')
	{
		operations = 0;
	}
	else
	{
		operations++;
	}
	for (std::string::const_iterator m_to_parse_iterator = m_to_parse.begin(); m_to_parse_iterator != m_to_parse.end(); ++m_to_parse_iterator)
	{
		if (*m_to_parse_iterator == ' ')
		{
			operations++;
		}
		else
		{
			continue;
		}
	}
	return operations;
}

const std::string & Parser::get_m_to_parse(void) const
{
	return m_to_parse;
}

const std::string & Parser::get_to_return(void) const
{
	return to_return;
}

Parser & Parser::operator=(const Parser & Object)
{
	if (this != &Object)
	{
		this->m_to_parse = Object.m_to_parse;
		this->to_return = Object.to_return;
		this->counter = Object.counter;
	}
	return *this;
}

Parser::~Parser()
{
	m_to_parse = "";
	to_return = "";
	counter = 0;
}
