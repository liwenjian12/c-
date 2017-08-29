
class Basked
{
public:
	// Baskedʹ�úϳɵ�Ĭ�Ϲ��캯���Ϳ������캯��
	void add_item(const std::shared_ptr<Quote> &sale)
	{
		items.insert(sale);
	}
	//��ӡÿ������ܼۺ͹���������������ܼ�
	double total_receipt(std::ostream) const;
private:
	//�ú������ڱȽ�shared_ptr��multiset��Ա���õ���
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
	double sum = 0.0;    // ����ʵʱ��������ܼ۸�
	// iterָ��ISBN��ͬ��һ��Ԫ���еĵ�һ��
	// upper_bound����һ�����������õ�����ָ������Ԫ�ص�β��λ��
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
	//���麯�����ص�ǰ��һ�ݶ�̬����Ŀ���
	//��Щ��Աʹ�õ������޶����μ�
	virtual Quote* clone() const & { return new Quote(*this); }
	virtual Quote* clone() &&
	{ return new Quote(std::move(*this)); }
	//������Ա��֮ǰ�İ汾һ��
};

