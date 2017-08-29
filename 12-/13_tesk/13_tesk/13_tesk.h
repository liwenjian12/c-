#ifndef TESK13_H
#define TESK13_H

#include<iostream>
#include<string>
#include<set>
#include<memory>
#include<initializer_list>
//class HasPtr {
//public:
//	HasPtr(const std::string &s = std::string()) :ps(new std::string(s)), i(0) {}
//	HasPtr(const HasPtr& hp) :ps(new std::string(*hp.ps)), i(hp.i) {}
//	HasPtr& operater= (const HasPtr& hp) {
//		std::string *new_ps = new std::string(*hp.ps);
//		delete ps;
//		ps = new_ps;
//		i = hp.i;
//		return *this;
//	}
//	~HasPtr() {
//		delete ps;
//	}
//private:
//	std::string *ps;
//	int i;
//
//};


/*----------------class numbered-------------*/

class numbered {
public:
	numbered() { mysn = unique++; }
	numbered(const numbered& n) { mysn = unique++; }

	int mysn;
	static int unique;
};
int numbered::unique = 10;

void f(numbered s) {
	std::cout << s.mysn << std::endl;
}

/*----------------Employee class-------------------------------*/

class Employee
{
public:
	Employee();
	Employee(const std::string& name);
	Employee(const Employee&) = delete;
	Employee& operater=( const Employee& ) = delete;//×èÖ¹¿½±´
	
	const int id() const { return id_; }

private:
	std::string name_;
	int id_;
	static int s_increment;
};
int Employee::s_increment = 0;
Employee::Employee()
{
	id_ = s_increment++;
}
Employee::Employee(const string& name)
{
	id_ = s_increment++;
	name_ = name;
}

class HasPtr

{
public:

	friend void swap(HasPtr&, HasPtr&);
	friend bool operator<(const HasPtr &lhs, const HasPtr &rhs);
    HasPtr(const std::string &s = std::string()) : ps(new std::string(s)), i(0),use(new size_t(1)) {}
	HasPtr(const HasPtr &hp) : ps(hp.ps), use(hp.use), i(hp.i) { ++*use; }
	HasPtr& operator=(const HasPtr &rhs)
	{
		++*rhs.use;
		if (--*use == 0)
		{
			delete ps;
			delete use;
		}
		ps = rhs.ps;
		i = rhs.i;
		use = rhs.use;
		return *this;
	}
	~HasPtr()
	{
		if (--*use == 0)
		{
			delete ps;
			delete use;
		}
	}
	void show() { std::cout << *ps << std::endl; }
private:
	std::string *ps;
	int i;
	size_t *use;
};

inline
void swap(HasPtr& lhs, HasPtr& rhs)
{
	using std::swap;
	swap(lhs.ps, rhs.ps);
	swap(lhs.i, rhs.i);
	swap(lhs.use, rhs.use);
	std::cout << "call swap(HasPtr& lhs,HasPtr& rhs)" << std::endl;
}
bool operator<(const HasPtr &lhs, const HasPtr &rhs)
{
	return *lhs.ps < *rhs.ps;
}

/*-----------------class Massage------------------------*/
class Folder;

class Message
{
	friend void swap(Message &, Message &);
	friend void swap(Folder &, Folder &);
	friend class Folder;
public:
	explicit Message(const std::string& s = "") :contents(s) {}
	Message(const Message&);
	Message& operator=(const Message&);
	~Message();
	void save(Folder&);
	void remove(Folder&);
	void print_debug();

private:
	std::string contents;
	std::set<Folder*> folders;

	void add_to_Folders(const Message&);
	void remove_from_Folder();

	void addFldr(Folder* f) { folders.insert(f); }
	void remFldr(Folder* f) { folders.erase(f); }
};

void swap(Message&, Message&);
class Folder
{
	friend void swap(Message&, Message&);
	friend void swap(Folder&, Folder&);
	friend class Message;
public:
	Folder() = default;
	Folder(const Folder&);
	Folder& operator=(const Folder&);
	~Folder();
	void print_debug();
	
private:
	std::set<Message*> msgs;
	void add_to_Message(const Folder&);
	void remove_to_Message();

	void addMsg(Message* m) { msgs.insert(m); }
	void remMsg(Message *m) { msgs.erase(m); }
};
void swap(Folder&, Folder&);


/*---------------class StrVec -------------------*/

class StrVec {
public:
	StrVec() :elements(nullptr), first_free(nullptr), cap(nullptr) {}
	StrVec(const StrVec&);
	StrVec(std::initializer_list<std::string>);
	StrVec& operator=(const StrVec&);
	~StrVec();

	void push_back(const std::string&);
	size_t size() const { return first_free - elements; }
	size_t capacity() const { return cap - elements; }
	std::string *begin() const { return elements; }
	std::string *end() const { return first_free; }

	void reserve(size_t new_cap);
	void resize(size_t count);
	void resize(size_t count,const std::string&);
private:
	std::pair<std::string*, std::string*> alloc_n_copy(const std::string*, const std::string*);
	void free();
	void chk_n_alloc() { if (size() == capacity()) reallocate(); }
	void reallocate();
	void alloc_n_move(size_t new_cap);
	void range_initialize(const std::string*, const std::string*);
private:
	std::string *elements;
	std::string *first_free;
	std::string *cap;
	std::allocator<std::string> alloc;
};
#endif 
