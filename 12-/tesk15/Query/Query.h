#ifndef  QUERY_H
#define  QUERY_H
#include "StrBlob.h"
#include"queryresult.h"
#include<map>
#include<set>
#include<vector>
#include<string>
#include<memory>
#include<fstream>
#include<iostream>
#include<sstream>
#include<iterator>

class QueryResult;

	
class TextQuery
{
public:
	typedef StrBlob::size_type line_no;
	TextQuery(std::ifstream& fin);
	QueryResult query(const std::string&)const;

private:
	StrBlob file;
	std::map<std::string, std::shared_ptr <std::set<line_no>>>wordMap;
};
TextQuery::TextQuery(std::ifstream &fin) :
	file(StrBlob()), wordMap(std::map<std::string, std::shared_ptr<std::set<line_no>>>())
{
	std::string line;
	while (std::getline(fin, line))
	{
		file.push_back(line);
		int n = file.size() - 1;

		std::stringstream lineSteam(line);
		std::string word;
		while (lineSteam >> word)
		{
			std::shared_ptr<std::set<line_no>>&
				sp_lines = wordMap[word];
			if (!sp_lines)
			{
				sp_lines.reset(new std::set<line_no>);
			}
			sp_lines->insert(n);
		}
	}
}

QueryResult TextQuery::query(const std::string &sought) const
{
	static std::shared_ptr<std::set<line_no>> noData(new std::set<line_no>);

	auto iter = wordMap.find(sought);
	if (iter == wordMap.end())
		return QueryResult(sought, noData, file);
	else
		return QueryResult(sought, iter->second, file);
}






class Query_base
{
	friend class Query;
protected:
	using line_no = TextQuery::line_no;
	virtual ~Query_base() = default;
private:
	virtual QueryResult eval(const TextQuery&)const = 0;
	virtual std::string rep() const = 0;
};

class WordQuery :public Query_base
{
	friend class Query;
	WordQuery(const std::string& s) :
		query_word(s)
	{
		std::cout << "WordQuery::WordQuery(" + s + ")\n";
	}
	QueryResult eval(const TextQuery& t)const override
	{
		return t.query(query_word);
	}
	std::string rep()const override {
		std::cout << "WodQuery::rep()\n";
		return query_word;
	}
	std::string query_word;
};
class Query
{
	friend Query operator~(const Query&);
	friend Query operator|(const Query&, const Query&);
	friend Query operator&(const Query&, const Query&);
public:
	Query(const std::string& s) :q(new WordQuery(s))
	{
		std::cout << "Query::Query(const std::string& s)where s=" + s + "\n";

	}
	QueryResult eval(const TextQuery& t) const
	{
		return q->eval(t);
	}
	std::string rep()const
	{
		std::cout << "Query ::rep()\n";
		return q->rep();
	}
private:
	Query(std::shared_ptr<Query_base>query) :
		q(query)
	{
		std::cout << "Query::Query(std::shared_ptr<Query_base> query)\n";

	}
	std::shared_ptr<Query_base>q;
};
inline std::ostream&
operator<<(std::ostream& os, const Query& query)
{
	return os << query.rep();
}

class BinaryQuery :public Query_base
{
protected:
	BinaryQuery(const Query&l, const Query& r, std::string s) :
		lhs(l), rhs(r), opSym(s)
	{
		std::cout << "BinaryQuery::BinaryQuery() where s=" + s + "\n";
	}

	std::string rep() const override
	{
		std::cout << "BinaryQuery::rep()\n";
		return "(" + lhs.rep() + " " + opSym + " " + rhs.rep() + ")";
	}
	Query lhs, rhs;
	std::string opSym;
};

class AndQuery : public BinaryQuery
{
	friend Query operator&(const Query&, const Query&);
	AndQuery(const Query& left, const Query& right) :
		BinaryQuery(left, right, "&")
	{
		std::cout << "AndQuery::AndQuery()\n";
	}

	//! @note: inherits rep and define eval

	QueryResult eval(const TextQuery &) const override
	{
		// this is just a placeholder rather than the real definition
	}
};

inline Query operator& (const Query& lhs, const Query& rhs)
{
	return std::shared_ptr<Query_base>(new AndQuery(lhs, rhs));
}

class NotQuery : public Query_base
{
	friend Query operator~(const Query& operand);
	NotQuery(const Query& q) : query(q)
	{
		std::cout << "NotQuery::NotQuery()\n";
	}

	//! virtuals:
	std::string rep() const override
	{
		std::cout << "NotQuery::rep()\n";
		return "~(" + query.rep() + ")";
	}

	QueryResult eval(const TextQuery &) const override;

	Query query;
};

inline Query operator~(const Query& operand)
{
	return std::shared_ptr<Query_base>(new NotQuery(operand));
	//!    ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
	//! note : There is an imlplicit conversion here.
	//!        The Query constructor that takes shared_ptr is not
	//!        "explicit", thus the compiler allows this conversion.
}


#endif // ! QUERY_H

