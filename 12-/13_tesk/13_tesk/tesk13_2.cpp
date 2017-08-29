#include"13_tesk.h"
#include<iostream>
#include<memory>

void swap(Message &lhs, Message &rhs)
{
	using std::swap;
	for(auto f:lhs.folders)
		f->remMsg(&lhs);
	for (auto f : rhs.folders)
		f->remMsg(&rhs);

	swap(rhs.folders, lhs.folders);
	swap(rhs.contents, lhs.contents);

	for (auto f : lhs.folders)
		f->addMsg(&lhs);
	for (auto f : lhs.folders)
		f->addMsg(&rhs);
}

void Message::save(Folder &f)
{
	folders.insert(&f);
	f.addMsg(this);
}

void Message::remove(Folder &f)
{
	folders.erase(&f);
	f.remMsg(this);
}

void Message::add_to_Folders(const Message &m)
{
	for (auto f : m.folders)
		f->addMsg(this);
}

Message::Message(const Message &m):contents(m.contents),folders(m.folders)
{
	add_to_Folders;
}

void Message::remove_from_Folder()
{
	for (auto f : folders)
		f->remMsg(this);
}

Message::~Message()
{
	remove_from_Folder();
}

Message& Message::operator=(const Message& rhs)
{
	remove_from_Folder();
	folders = rhs.folders;
	contents = rhs.contents;
	add_to_Folders(rhs);
	return *this;
}

void Message::print_debug()
{
	std::cout << contents << std::endl;
}

void swap(Folder& lhs, Folder& rhs)
{
	using std::swap;
	for (auto m : lhs.msgs)
		m->remFldr(&lhs);
	for (auto m : rhs.msgs)
		m->remFldr(&rhs);
	swap(lhs.msgs, rhs.msgs);

	for (auto m : lhs.msgs)
		m->addFldr(&lhs);
	for (auto m : rhs.msgs)
		m->addFldr(&rhs);

}

void Folder::add_to_Message(const Folder &f)
{
	for (auto m : f.msgs)
		m->addFldr(this);
}
Folder::Folder(const Folder &f) : msgs(f.msgs)
{
	add_to_Message(f);
}

void Folder::remove_to_Message()
{
	for (auto m : msgs)
		m->remFldr(this);
}

Folder::~Folder()
{
	remove_to_Message();
}
Folder& Folder::operator =(const Folder &rhs)
{
	remove_to_Message();
	msgs = rhs.msgs;
	add_to_Message(rhs);
	return *this;
}

void Folder::print_debug()
{
	for (auto m : msgs)
		std::cout << m->contents << " ";
	std::cout << std::endl;
}






/*----------------------------------strvec----------*/
void StrVec::push_back(const std::string &s)
{
	chk_n_alloc();
	alloc.construct(first_free++, s);
}

std::pair<std::string*, std::string*>
StrVec::alloc_n_copy(const std::string *b, const std::string *e)
{
	auto data = alloc.allocate(e - b);
	return{ data, std::uninitialized_copy(b, e, data) };
}

void StrVec::free()
{
	if (elements) {
		for (auto p = first_free; p != elements;)
			alloc.destroy(--p);
		alloc.deallocate(elements, cap - elements);
	}
}

StrVec::StrVec(const StrVec &rhs)
{
	auto newdata = alloc_n_copy(rhs.begin(), rhs.end());
	elements = newdata.first;
	first_free = cap = newdata.second;
}
void StrVec::range_initialize(const std::string *first, const std::string *last)
{
	auto newdata = alloc_n_copy(first, last);
	elements = newdata.first;
	first_free = cap = newdata.second;
}
StrVec::StrVec(const StrVec &rhs)
{
	range_initialize(rhs.begin(), rhs.end());
}

StrVec::StrVec(std::initializer_list<std::string>li)
{
	range_initialize(li.begin(), li.end());
}
StrVec::~StrVec()
{
	free();
}


StrVec& StrVec::operator = (const StrVec &rhs)
{
	auto data = alloc_n_copy(rhs.begin(), rhs.end());
	free();
	elements = data.first;
	first_free = cap = data.second;
	return *this;
}

void StrVec::alloc_n_move(size_t new_cap)
{
	auto newdata = alloc.allocate(new_cap);
	auto dest = newdata;
	auto elem = elements;
	for (size_t i = 0; i != size(); ++i)
		alloc.construct(dest++, std::move(*elem++));
	free();
	elements = newdata;
	first_free = dest;
	cap = elements + new_cap;
}

void StrVec::reallocate()
{
	auto newcapacity = size() ? 2 * size() : 1;
	alloc_n_move(newcapacity);
}

void StrVec::reserve(size_t new_cap)
{
	if (new_cap <= capacity()) return;
	alloc_n_move(new_cap);
}

void StrVec::resize(size_t count)
{
	resize(count, std::string());
}

void StrVec::resize(size_t count, const std::string &s)
{
	if (count > size()) {
		if (count > capacity()) reserve(count * 2);
		for (size_t i = size(); i != count; ++i)
			alloc.construct(first_free++, s);
	}
	else if (count < size()) {
		while (first_free != elements + count)
			alloc.destroy(--first_free);
	}
}