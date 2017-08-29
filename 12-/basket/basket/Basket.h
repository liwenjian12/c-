
class Basked
{
public:
	// Basked使用合成的默认构造函数和拷贝构造函数
	void add_item(const std::shared_ptr<Quote> &sale)
	{
		items.insert(sale);
	}
	//打印每本书的总价和购物篮中所有书的总价
	double total_receipt(std::ostream) const;
private:
	//该函数用于比较shared_ptr，multiset成员会用到它
	static bool compare(const std::shared_ptr<Quote> &lhs,
		const std::shared_ptr<Quote> &rhs)
	{
		return lhs->isbn() < rhs->isbn();
	}
	std::multiset<std::shared_ptr<Quote>, decltype(compare)*>
		items{ compare };


};

double Basket::total_receipt(ostream &os) const
{
	double sum = 0.0;    // 保存实时计算出的总价格
	// iter指向ISBN相同的一笔元素中的第一个
	// upper_bound返回一个迭代器，该迭代器指向这批元素的尾后位置
	for (auto iter = items.cbegin();
		      iter != items.cend();
		      iter = items.upper_bound(*iter))
	{
		sum += print_total(os, **iter, items.count(*iter));
	}
	os << "Total Sale: " << sum << endl;
	return sum;
}

class Quote
{
public:
	//改虚函数返回当前的一份动态分配的拷贝
	//这些成员使用的引用限定符参见
	virtual Quote* clone() const & { return new Quote(*this); }
	virtual Quote* clone() &&
	{ return new Quote(std::move(*this)); }
	//其他成员与之前的版本一致
};

