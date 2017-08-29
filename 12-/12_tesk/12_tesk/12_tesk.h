#ifndef TESK12_H
#define TESK12_H



#include<vector>
#include<string>
#include<initializer_list>
#include<memory>
#include<exception>
#include<stdexcept>
#include<iostream>
#include<sstream>
#include<fstream>
#include<map>
#include<set>
using std::vector; using std::string;


/*-----------------------------------StrBlob 类-------------------------------------------------------------------------------*/

class StrBlobPtr;
class StrBlob {
public:
	using size_type = vector<string>::size_type;
	friend class StrBlobPtr;
	StrBlobPtr begin();
	StrBlobPtr end();

	StrBlob() :data(std::make_shared<vector<string>>()) { }
	StrBlob(std::initializer_list<string> il) :data(std::make_shared<vector<string>>(il)) { }


	size_type size() const { return data->size(); }
	bool empty()const { return data->empty(); }

	void push_back(const string &t) { data->push_back(t); }
	void pop_back() {
		check(0, "pop_back on empty StrBlob");
		data->pop_back();
	}
    
	std::string& front() {
		check(0, "front on empty StrBlob");
		return data->front();
	}

	std::string& back() {
		check(0, "back on empty StrBlob");
		return data->back();
	}

	const std::string& front() const {
		check(0, "front on empty StrBlob");
		return data->front();
	}
	const std::string& back() const {
		check(0, "back on empty StrBlob");
		return data->back();
	}

private:
	void check(size_type i, const string &msg)const {
		if (i >= data->size())throw std::out_of_range(msg);
	}
	std::shared_ptr<vector<string>> data;
};



/*--------------------------------------------------------connection 类----------------------------------*/


struct connection {
	string ip;
	int port;
	connection(string i,int p):ip(i),port(p){}
};
struct destination {
	string ip;
	int port;
	destination(string i, int p) :ip(i), port(p) {}
};
connection connect(destination* pDest)
{
	std::shared_ptr<connection> pConn(new connection(pDest->ip, pDest->port));
	std::cout << "creating connection(" << pConn.use_count() << ")" <<std:: endl;
	return *pConn;
}
void disconnect(connection pConn)
{
	std::cout << "connection close(" << pConn.ip << " :" << pConn.port << ")" << std::endl;
}
void end_connection(connection* pConn)
{
	disconnect(*pConn);
}
void f(destination &d)
{
	connection conn = connect(&d);
	std::shared_ptr<connection> p(&conn, [](connection* p) {disconnect(*p); });
	std::cout << "connecting now(" << p.use_count() << ")" << std:: endl;
}




/*------------------------------------------StrBlobPtr 类--------------------------------*/
class StrBlobPtr
{
public:
	StrBlobPtr() :curr(0) {}
	StrBlobPtr(StrBlob &a, size_t sz = 0) :wptr(a.data), curr(sz) {}
	bool operator!= (const StrBlobPtr& p) { return p.curr != curr; }
	string& deref()const
	{
		auto p = check(curr, "dereference past end");
		return (*p)[curr];
	}
	StrBlobPtr& incr()
	{
		check(curr, "increment past end of StrBlobPtr");
		++curr;
		return *this;
	}

private:
	std::shared_ptr <vector<string> > check (size_t i, const string &msg)const
	{
		auto ret = wptr.lock();
		if (!ret) throw std::runtime_error("unbound StrBlobPtr");
		if (i >= ret->size())throw std::out_of_range(msg);
		return ret;
	}
	std::weak_ptr<vector<string>>wptr;
	size_t curr;
};

StrBlobPtr StrBlob::begin()
{
	return StrBlobPtr(*this);
}
StrBlobPtr StrBlob::end()
{
	return StrBlobPtr(*this, data->size());
}


/*-------------------------------TEXTQUERY 类-------------------------------*/
class QueryResult;
class TextQuery
{
public:
	using line_no = vector<string>::size_type;
	TextQuery(std::ifstream&);
	QueryResult query(const string& s) const;

private:
	std::shared_ptr<vector<string>>file;
	std::map<string,std:: shared_ptr<std:: set <line_no>>>wm;

};
class QueryResult {
public:
	friend std::ostream& print(std::ostream&, const QueryResult&);
	QueryResult(string s, std::shared_ptr < std::set <TextQuery::line_no>>p,
		std::shared_ptr<vector<string>> f) :
		sought(s),lines(p),file(f){}
private:
	string sought;
	std::shared_ptr<std::set<TextQuery::line_no>> lines;
	std::shared_ptr<vector<string>> file;
};

std::ostream& print(std::ostream&, const QueryResult&);

TextQuery::TextQuery(std::ifstream& ifs) : file(new vector<string>)
{
	string text;
	while ( getline(ifs, text))
	{
		file->push_back(text);
		int n = file->size() - 1;
		std::istringstream line(text);
		string word;
		while (line >> word)
		{
			auto &lines = wm[word];
			if (!lines)
				lines.reset(new std:: set < line_no>);
			lines->insert(n);
		}
	}
}

QueryResult TextQuery::query(const string& s) const
{
	static std::shared_ptr<std::set<line_no>> nodata(new std::set<line_no>);
	auto loc = wm.find(s);
	if (loc == wm.end())
		return QueryResult(s, nodata, file);
	else
		return QueryResult(s, loc->second, file);
}
std::ostream& print(std::ostream& os, const QueryResult& qr)
{
	os << qr.sought << " occurs " << qr.lines->size() << " "
		<< "time" << (qr.lines->size() > 1 ? "s" : " ") <<std:: endl;
	for (auto num : *qr.lines)
		os << "\t(line" << num + 1 << ")" << *(qr.file->begin() + num) << std:: endl;
	return os;
}

#endif // !TESK12_H
