#ifndef TEXTQUERY_H_
#define TEXTQUERY_H_

class QueryResult
{
	friend ostream& print(ostream&, const QueryResult&);
public:
	QueryResult(string s, shared_ptr<set<line_no>>p,
		shared_ptr<vector<string>> f) :
		sought(s), lines(p), file(f) { }
private:
	string sought;
	shared_ptr<set<line_no>> lines;
	shared_ptr<vector<string>> file;

};
class TextQuery
{
public:
	using line_no = vector<string>::size_type;
	TextQuery(ifstream&);
	QueryResult query(const string&)const;
private:
	shared_ptr<vector<string>> file;
	map<string,
		shared_ptr<set<line_no>>> wm;
};




#endif // !TEXTQUERY_H_

