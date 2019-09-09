#include <iostream>
#include <algorithm>
#include<utility>//for make_apir
#include <vector>
#include<deque>
#include<list>
#include <iterator>
#include<stdio.h>
#include<string>
#include<forward_list>
#include "Box.h"
#include<map>
#include<iomanip>//for setw
#include<cctype>
#include<sstream>//for text
#include<tuple>
using namespace std;
/*
push_back( ) 成员函数在向量的末尾插入值，如果有必要会扩展向量的大小。
size( ) 函数显示向量的大小。
begin( ) 函数返回一个指向向量开头的迭代器。
end( ) 函数返回一个指向向量末尾的迭代器。
*/
void FuncVector1()
{
	// 创建一个向量存储 int
	vector<int> iVec;
	int i;

	// 显示 vec 的原始大小
	cout << "vector size = " << iVec.size() << endl;

	// 推入 5 个值到向量中
	for (i = 0; i < 5; i++) {
		iVec.push_back(i);
	}

	// 显示 vec 扩展后的大小
	cout << "extended vector size = " << iVec.size() << endl;

	// 访问向量中的 5 个值
	for (i = 0; i < 5; i++) {
		cout << "value of vec [" << i << "] = " << iVec[i] << endl;
	}

	// 使用迭代器 iterator 访问值
	vector<int>::iterator v = iVec.begin();
	while (v != iVec.end()) {
		cout << "value of v = " << *v << endl;
		v++;
	}
}
/*
C++ STL 之 vector 的 capacity 和 size 属性区别
size 是当前 vector 容器真实占用的大小，也就是容器当前拥有多少个容器。
capacity 是指在发生 realloc 前能允许的最大元素数，即预分配的内存空间。
当然，这两个属性分别对应两个方法：resize() 和 reserve()。
使用 resize() 容器内的对象内存空间是真正存在的。
使用 reserve() 仅仅只是修改了 capacity 的值，容器内的对象并没有真实的内存空间(空间是"野"的)。
此时切记使用[] 操作符访问容器内的对象，很可能出现数组越界的问题。
*/
void FuncVector2()
{
		vector<int> v;
		std::cout << "v.size() == " << v.size() << " v.capacity() = " << v.capacity() << std::endl;
		v.reserve(10);
		std::cout << "v.size() == " << v.size() << " v.capacity() = " << v.capacity() << std::endl;
		v.resize(10);
		v.push_back(0);
		std::cout << "v.size() == " << v.size() << " v.capacity() = " << v.capacity() << std::endl;
}
//区别vector容量大小和vector大小（capacity和size）
void FuncVector3()
{
	vector<int> iVector{ 10,11,12,13,14,15,16,17 };
	cout << "size = " << iVector.size() << endl;
	cout << "capacity = " << iVector.capacity() << endl;
	iVector.push_back(18);
	cout << "push_back(18)" << endl;
	cout << "size = " << iVector.size() << endl;
	cout << "capacity = " << iVector.capacity() << endl;

	iVector.reserve(20);
	cout << "iVector.reserve(20);" << endl;
	cout << "size = " << iVector.size() << endl;
	cout << "capacity = " << iVector.capacity() << endl;

	iVector.resize(30, 3);
	cout << "iVector.resize(30, 3);" << endl;
	cout << "size = " << iVector.size() << endl;
	cout << "capacity = " << iVector.capacity() << endl;
}
//resize
void FuncVector4()
{
	vector<int> iVec{ 1,2,3 };
	iVec.resize(5);
	vector<int>::iterator v = iVec.begin();
	cout << "after iVec.resize(5);" << endl;
	while (v != iVec.end()) {
		cout << "value of v = " << *v << endl;
		v++;
	}
	iVec.resize(7, 99);
	cout << "after iVec.resize(7, 99);" << endl;
	v = iVec.begin();
	while (v != iVec.end()) {
		cout << "value of v = " << *v << endl;
		v++;
	}
	iVec.resize(6);
	cout << "after iVec.resize(6);" << endl;
	v = iVec.begin();
	while (v != iVec.end()) {
		cout << "value of v = " << *v << endl;
		v++;
	}
}
//访问
void FuncVector5()
{
	vector<int> iVector{ 6,3,5,6,7 };
	cout << "front() = " << iVector.front() << endl;
	cout << "end() = " << iVector.back() << endl;

	iVector.front() = 77;//可以通过这个方式修改头值
	auto piVector = iVector.data();//获取元素存储数组
	for (int i = 0; i < iVector.size(); i++)
	{
		cout << "value is " << *piVector << endl;
		piVector++;
	}
}
//copy
void FuncVector6()
{
	vector<double> dVector{ 32.5, 30.1, 36.3, 40.0, 39.2 };
	cout << "Enter additional data values separated by spaces or Ctrl+Z to end:" << endl;
	//copy() 的头两个参数是两个迭代器，指定了复制元素的范围，第三个参数指定了这些元素存放的位置。
	copy(istream_iterator<double>(cin), istream_iterator<double>(), back_inserter(dVector));
	copy(begin(dVector), end(dVector), ostream_iterator<double>(cout, " "));
}
//emplace_back
void FuncVector7()
{
	std::vector<std::string> strVector;
	strVector.push_back(std::string("facetious")); // Calls string constructor & moves the string object 
	strVector.emplace_back("abstemious");// Calls string constructor to create element in place
	//emplace back() 比 push_back() 更有效率
	vector<string>::iterator v = strVector.begin();
	while (v != strVector.end()) {
		cout << "value of v = " << *v << endl;
		v++;
	}
	std::string str{ "alleged" };
	strVector.emplace_back(str, 2, 3);//构造函数会生成一个从索引 2 幵始、包含 str 中三个字符的子串。
	cout << "after strVector.emplace_back(str, 2, 3); " << endl;
	v = strVector.begin();
	while (v != strVector.end()) {
		cout << "value of v = " << *v << endl;
		v++;
	}
}
//emplace
void FuncVector8()
{
	std::vector<std::string> strVector{ "first", "second" };
	// Inserts string(5,'A') as 2nd element
	auto iter = strVector.emplace(++std::begin(strVector), 5, 'A');//位置，数量，内容（单）//返回结尾位置
	//Inserts string ("$$$$") as 3rd element
	strVector.emplace(++iter, "$$$$");//位置，内容（多）
	vector<string>::iterator v = strVector.begin();
	while (v != strVector.end()) {
		cout << "value of v = " << *v << endl;
		v++;
	}
}
//insert
void FuncVector9()
{
	vector<string> strVector{ "hello","world","welcome" };
	auto iter = strVector.insert(++begin(strVector), "ok");
	vector<string>::iterator v = strVector.begin();
	while (v != strVector.end())
	{
		cout << " value of v = " << *v << endl;
		v++;
	}
	//由2.3参数指定元素序列
	cout << "next insert" << endl;
	string more[]{ "five", "six", "seven" }; // Array elements to be inserted
	iter = strVector.insert(--end(strVector), begin(more), end(more));
	v = strVector.begin();
	while (v != strVector.end())
	{
		cout << " value of v = " << *v << endl;
		v++;
	}
	//一个元素
	cout << "next insert" << endl;
	iter = strVector.insert(end(strVector), "yes, done");
	v = strVector.begin();
	while (v != strVector.end())
	{
		cout << "value of v = " << *v << endl;
		v++;
	}
	//多个单元素
	cout << "next insert" << endl;
	iter = strVector.insert(--end(strVector), 3, "Rc");
	v = strVector.begin();
	while (v != strVector.end())
	{
		cout << "value of v = " << *v << endl;
		v++;
	}
	//初始化列表
	cout << "next insert" << endl;
	iter = strVector.insert(end(strVector), { string {"new1"}, string {"new2"} });
	v = strVector.begin();
	while (v != strVector.end())
	{
		cout << "value of v = " << *v << endl;
		v++;
	}
}
//swap
void FuncVector10()
{
	vector<int> iVector{1,2,3,4,5}; // Contains 100 elements initialized to 99
	swap(*iVector.begin(), *(iVector.end()-1));
	vector<int>::iterator v = iVector.begin();
	while (v != iVector.end())
	{
		cout << " value of v = " << *v << endl;
		v++;
	}
}
//erase
void FuncVector11()
{
	vector<int> iVector{ 1,2,3,4,5,6,7,8,9 };
	//删除单个
	auto iter = iVector.erase(begin(iVector)); //Delete the second element
	vector<int>::iterator v = iVector.begin();
	while (v != iVector.end())
	{
		cout << " value of v = " << *v << endl;
		v++;
	}
	//删除多个
	cout << "next erase" << endl;
	iter = iVector.erase(begin(iVector), begin(iVector)+3); //Delete the second element
	v = iVector.begin();
	while (v != iVector.end())
	{
		cout << " value of v = " << *v << endl;
		v++;
	}
	//删除特定值
	cout << "next erase" << endl;
	iter = iVector.erase(remove(begin(iVector), end(iVector), 8), end(iVector));
	v = iVector.begin();
	while (v != iVector.end())
	{
		cout << " value of v = " << *v << endl;
		v++;
	}
}
//assign
void FuncDeque1()
{
	//使用初始化列表
	deque<string> strDeque{ "one", "two", "three", "four" };
	auto init_list = { std::string{"seven"}, std::string{ "eight"}, std::string{"nine"} };
	strDeque.assign(init_list);
	deque<string>::iterator d = strDeque.begin();
	while (d != strDeque.end())
	{
		cout << "value of d = " << *d << endl;
		d++;
	}
	//多个相同元素
	cout << "next assign" << endl;
	strDeque.assign(5, "hello");
	d = strDeque.begin();
	while (d!=strDeque.end())
	{
		cout << "value of d = " << *d << endl;
		d++;
	}
}
//流
void FuncDeque2()
{
	deque<string> names;
    cout << "Enter first names separated by spaces. Enter Ctrl+Z on a new line to end:\n";
    copy(std::istream_iterator < string > {std::cin}, std::istream_iterator < string > {}, std::front_inserter(names));
    cout << "\nIn reverse order, the names you entered are:\n";
    copy(begin(names), end(names), std::ostream_iterator < string > {std::cout, "  "});
    cout << std::endl;
}
//push emplace
void FuncList1()
{
	//push
	std::list<std::string> strList{ "Jane", "Jim", "Jules", "Janet" };
	strList.push_front("Ian"); // Add string ("Ian") to the front of the list
	strList.push_back("Kitty"); // Append string ("Kitty") to the end of the list
	list<string>::iterator l = strList.begin();
	while (l!=strList.end())
	{
		cout << "value of l = " << *l << endl;
		l++;
	}
	//emplace
	cout << "after empalce" << endl;
	strList.emplace_front("Ian1");//Create string ("Ian") in place at the front of the list
	strList.emplace_back("Kitty1");// Create string ("Kitty") in place at the end of the list
	l = strList.begin();
	while (l != strList.end())
	{
		cout << "value of l = " << *l << endl;
		l++;
	}
}
//insert advance
void FuncList2()
{
	std::list<int> iList(10, 55); // List of 10 elements with value 55
	iList.insert(++begin(iList), 66); // Insert 66 as the second element
	list<int>::iterator l = iList.begin();
	while (l != iList.end())
	{
		cout << "value of l = " << *l << endl;
		l++;
	}

	cout << "next insert" << endl;
	auto iter = begin(iList);
	std::advance(iter, 9); // Increase iter by 9
	iList.insert(iter, 3, 88);// Insert 3 copies of 88 starting at the 10th
	l = iList.begin();
	while (l != iList.end())
	{
		cout << "value of l = " << *l << endl;
		l++;
	}
}
//http://c.biancheng.net/view/445.html
/////////////////////////////////////////////////////////////////2019 07 30
// Order strings by length when the initial letters are the same
class my_greater
{
public:
	bool operator () (const std::string s1, const std::string s2)
	{
		if (s1[0] == s2[0])
			return s1.length() > s2.length();
		else
			return s1 > s2;
	}
};
//sort
void FuncList3()
{
	std::list<std::string> strList{ "Jane", "Jim", "Jules", "Janet" };
	strList.sort(my_greater()); // Sort using my_greater
	list<string>::iterator l = strList.begin();
	while (l != strList.end())
	{
		cout << "value of l = " << *l << endl;
		l++;
	}
}
//基于范围循环
void FuncList4()
{
	std::list<std::string> names{ "Jane","Jim", "Jules", "Janet" };
	names.emplace_back("Ann");
	std::string name("Alan");
	names.emplace_back(std::move(name));
	names.emplace_front("Hugo");
	names.emplace(++begin(names), "Hannah");
	//
	for (const auto& name : names)
	{
		std::cout << name << std::endl;
	}
}
//模板
//merge 必须保证两个序列都是同类型且升序
void FuncList6()
{
	std::list<int> my_values{ 2, 4, 6, 14 };
	std::list<int> your_values{ -2, 1, 7, 10 };
	my_values.merge(your_values);//my_values contains: -2 1 2 4 6 7 10 14
	cout << "your_values is empty = " << your_values.empty() << endl; // Returns true
	list<int>::iterator v = begin(my_values);
	while (v!= end(my_values))
	{
		cout << "v = " << *v << endl;
		v++;
	}
}
//元素多少，distance
void FuncForwardList1()
{
	std::forward_list<std::string> my_words{ "three", "six", "eight" };
	auto count = std::distance(std::begin(my_words), std::end(my_words));
	cout << "number of element is " << count << endl;
	// Result is 3
}
//advance
void FuncForwardList2()
{
	std::forward_list<int> data{ 10, 21, 43, 87, 175, 351 };
	auto iter = std::begin(data);
	size_t n{ 3 };
	std::advance(iter, n);//后移三个，确定第四个元素
	std::cout << "The " << n + 1 << "th element is n " << *iter << std::endl;
	// Outputs 87
}
//before_begin
void FuncForwardList3()
{
	std::forward_list<std::string> my_words{ "three", "six", "eight" };
	std::forward_list<std::string> your_words{ "seven", "four", "nine" };
	//注意before_begin返回第二个元素
	//my_words.splice_after(my_words.before_begin(), your_words, ++std::begin(your_words));//1.0
	my_words.splice_after(my_words.before_begin(), your_words, std::begin(your_words), std::end(your_words));//1.1
	//my_words.splice_after(my_words.before_begin(), your_words);//2.0
	auto iter = begin(my_words);
	iter = begin(my_words);
	while (iter!=end(my_words))
	{
		cout << "worlds = " << *iter << endl;
		iter++;
	}
}

template<typename Iter>
void list_elements(Iter begin, Iter end)
{
	size_t perline{ 6 };                            // Maximum items per line
	size_t count{};                               // Item count
	while (begin != end)
	{
		std::cout << *begin++;
		if (++count % perline == 0)
		{
			std::cout << "\n";
		}
	}
	std::cout << std::endl;
}
void FuncForwardList4()
{
	std::forward_list<Box> cBox;
	std::copy(std::istream_iterator<Box>(std::cin), std::istream_iterator<Box>(), std::front_inserter(cBox));

	cBox.sort();                                    // Sort the boxes
	std::cout << "\nAfter sorting the sequence is:\n";
	// Just to show that we can with Box objects - use an ostream iterator
	std::copy(std::begin(cBox), std::end(cBox), std::ostream_iterator<Box>(std::cout, " "));
	std::cout << std::endl;

	// Insert more boxes
	std::forward_list<Box> more_boxes{ Box {3, 3, 3}, Box {5, 5, 5}, Box {4, 4, 4}, Box {2, 2, 2} };
	cBox.insert_after(cBox.before_begin(), std::begin(more_boxes), std::end(more_boxes));
	std::cout << "After inserting more boxes the sequence is:\n";
	list_elements(std::begin(cBox), std::end(cBox));

	cBox.sort();                                    // Sort the boxes
	std::cout << std::endl;
	std::cout << "The sorted sequence is now:\n";
	list_elements(std::begin(cBox), std::end(cBox));

	more_boxes.sort();
	cBox.merge(more_boxes);                         // Merge more_boxes
	std::cout << "After merging more_boxes the sequence is:\n";
	list_elements(std::begin(cBox), std::end(cBox));

	cBox.unique();
	std::cout << "After removing successive duplicates the sequence is:\n";
	list_elements(std::begin(cBox), std::end(cBox));

	// Eliminate the small ones
	const double max_v{ 30.0 };
	cBox.remove_if([max_v](const Box& box) { return box.volume() < max_v; });
	std::cout << "After removing those with volume less than 30 the sorted sequence is:\n";
	list_elements(std::begin(cBox), std::end(cBox));
}
/////////////////////////////////////////////////////////////////2019 07 31
//map
class Name
{
private:
	std::string firstname{}; std::string secondname{};
public:
	Name(std::string first, std::string second) : firstname{ first }, secondname{ second }{};
	Name() = default;
	bool operator<(const Name& name)
	{
		return secondname < name.secondname || ((secondname == name.secondname) && (firstname < name.firstname));
	}
};
//map创建
void FuncMap1()
{
	std::map<std::string, size_t> people{ {"Ann", 25}, {"Bill", 46},{"Jack", 32},{"Jill", 32} };//初始化列表
	std::map<std::string, size_t> people1{ std::make_pair("Ann",25),std::make_pair("Bill", 46),std::make_pair("Jack", 32),std::make_pair("Jill", 32) };//make_apir
	std::map<std::string, size_t> personnel{ people }; // Duplicate people map//定义了复制构造函数
	std::map<std::string, size_t> personnel1{ std::begin(people),std::end(people) };//可以用另一个容器的一段元素来创建一个 map
	std::map<std::string, size_t> personnel2{ ++std::begin(people),std::end(people) };//
}
//插入insert
void FuncMap2()
{
	std::map<std::string, size_t> people{ std::make_pair("Ann",25),std::make_pair("Bill",46) , std::make_pair("Jack",32), std::make_pair("Jill",32) };//创建
	auto pr = std::make_pair("Fred", 22); //Create a pair element and insert it//make_apir
	//auto pr = std::make_pair ("Fred",22) ; // pair<const char*, int>	显示转换
	auto ret_pr = people.insert(pr);//insert//隐式转换为容器元素类型
	std::cout << ret_pr.first->first << " " << ret_pr.first->second << " " << std::boolalpha << ret_pr.second << "\n"; // Fred 22 true
	ret_pr = people.insert(std::make_pair("Bill", 48));//bill已经存在，插入将会失败
	std::cout << ret_pr.first->first << " " << ret_pr.first->second << " " << std::boolalpha << ret_pr.second << "\n"; // Bill 46 false//插入失败
	//修改
	if (!ret_pr.second) // If the element is there change the age
	{
		ret_pr.first-> second = 48;
	}
	//输出
	for (const auto& p : people)
	{
		std::cout << std::setw(10) << std::left << p.first << " " << p.second << "\n";
	}
	//可以用 pair 构造函数生成的对象作为 insert() 的参数：
	//ret_pr = people.insert(std::pair<const std::string, size_t> {"Bill", 48});
	ret_pr = people.insert(std::make_pair("Jim", 48));
	people.insert(ret_pr.first, std::make_pair("Ian", 38));
	cout << endl;
	for (const auto& p : people)
	{
		std::cout << std::setw(10) << std::left << p.first << " " << p.second << "\n";
	}
	//更合理的处理方式
	if (!people.count("Cen"))
	{
		people.insert(ret_pr.first, std::make_pair("Cen", 38));
	}
	cout << endl;
	for (const auto& p : people)
	{
		std::cout << std::setw(10) << std::left << p.first << " " << p.second << "\n";
	}
}
//输出
void FuncMap3()
{
	std::map<std::string, size_t> people{ std::make_pair("Ann",25),std::make_pair("Bill",46) , std::make_pair("Jack",32), std::make_pair("Jill",32) };//创建
	std::map<std::string, size_t> crowd{ {"May", 55}, {"Pat",66}, {"Al", 22}, {"Ben", 44} };
	auto iter = std::begin(people);
	std::advance(iter, 2);  // begin iterator->Bill
	crowd.insert(++std::begin(people), iter); 
	for (const auto& p : crowd)
	{
		cout << p.first << " " << p.second << endl;
	}
}
/////////////////////////////////////////////////////////////////2019 08 01
void FuncMap4() {
	std::cout << "Enter some text and enter * to end:\n";
	string text_in{};
	std::getline(std::cin, text_in, '*');

	// Replace non-alphabetic characters by a space
	std::replace_if(std::begin(text_in), std::end(text_in), [](const char& ch) { return !isalpha(ch); }, ' ');//用空格替代所有非字母字符

	std::istringstream text(text_in);             // Text input string as a stream
	std::istream_iterator<string> begin(text);    // Stream iterator
	std::istream_iterator<string> end;            // End stream iterator

	std::map<string, size_t> words;               // Map to store words & word counts
	size_t max_len{};                            // Maximum word length

	// Get the words, store in the map, and find maximum length
	std::for_each(begin, end, [&max_len, &words](const string& word)
								{	words[word]++;//每个单词的关联值就是它在文本中累计出现的次数
									max_len = std::max(max_len, word.length());//保存最长字符串的长度
								});

	size_t per_line{ 4 }, count{};
	for (const auto& w : words)
	{
		std::cout << std::setw(max_len + 1) << w.first << std::setw(3) << std::right << w.second << endl;
	}
	std::cout << std::endl;
}
//find
void FuncMap5()
{
	std::map<std::string, size_t> people{ {"Fred", 45}, {"Joan", 33}, {"Jill", 22} };
	std::string name{ "Joan" };
	auto iter = people.find(name);//find
	if (iter == std::end(people))//如果没找到返回结束迭代器
		std::cout << "Not found.\n";
	else
		std::cout << name << " is "<< iter->second << std::endl;
}
//erase参数可以是键值也可以是迭代器
void FuncMap6()
{
	std::map<std::string, size_t> people{ { "Fred", 45}, {"Joan", 33},{"Jill", 22} };
	std::string name{ "Joan" };
	if (people.erase(name))//0 表明元素不在容器中,1表示移除成功
		std::cout << name << " was removed." << std::endl;
	else
		std::cout << name << " was not found" << std::endl;
}
//erase迭代器作参数
void FuncMap7()
{
	std::map<std::string, size_t> people{ { "Fred", 45}, {"Joan", 33},{"Jill", 22} };
	//auto iter = people.erase(std::begin(people));//迭代器
	auto iter = people.erase(++std::begin(people), --std::end(people));//Erase all except 1st & last//双参指定范围
	if (iter == std::end(people))
		std::cout << "The last element was removed." << std::endl;
	else
		std::cout << "The element preceding " << iter->first << " was removed." << std::endl;
}
//4 种不同的方式来创建pair对象 make_pair
void FuncMap8()
{
	std::string s1{ "test" }, s2{ "that" };
	std::pair<std::string, std::string> my_pair{ s1, s2 };//构造函数复制
	std::pair<std::string, std::string> your_pair{ std::string {"test"},std::string {"that"} };//移动参数值
	std::pair<std::string, std::string> his_pair{ "test", std::string {"that"} };
	std::pair<std::string, std::string> her_pair{ "test", "that" };//隐式转换
	//make_pair<T1，T2> 函数模板是一个辅助函数，可以生成并返回一个 pair<T1，T2> 对象
	my_pair = std::make_pair(s1, s2);
	your_pair = std::make_pair(std::string{ "test" }, std::string{ "that" });//前两条语句中的函数模板的类型参数由编译器推断
	his_pair = std::make_pair<std::string, std::string>("test", std::string{ "that" });
	her_pair = std::make_pair<std::string, std::string>("test", "that");//在最后两条语句中，类型是明确的
	//pair 对象也可以复制或移动构造它的成员变量
	std::pair<std::string, std::string> new_pair{ my_pair }; // Copy constructor
	std::pair<std::string, std::string> old_pair{ std::make_pair(std::string{"his"},std::string{"hers"}) };
	//pair 构造函数的第一个参数是一个定义在 utility 头文件中的 piecewise_construct 类型的实例，这是一个用来作为标签或标记的空类型。
	//这个 piecewise_constmct 参数唯一的作用是区分这个构造函数的调用和有两个 tuple 参数的构造函数调用之间的区别
	//后者的两个参数通常用来作为 pair 成员变量 first 和 second 的值。
	//构造函数的第二和第三个参数指定了构造 first 和 second 对象的参数集
	//forward_as_tuple() 是一个定义在 tuple 头文件中的函数模板。这里用它的转发参数生成了一个 tuple 引用。
	//不会经常用到这种 pair 的构造函数，但它为不支持拷贝或移动运算的 T1 和 T2 类型提供了在适当位置生成 pair<T1, T2> 对象的独特能力。
	std::pair<Name, Name> couple{ std::piecewise_construct, std::forward_as_tuple("Jack","Jones") , std::forward_as_tuple("Jill", "Smith") };
}
//pair对象具有完整运算符    ==、!=、<、<=、>、>=
void FuncMap9()
{
	std::pair<std::string, std::string> new_pair;
	new_pair.first = "his";
	new_pair.second = "hers";
	if (new_pair == std::pair<std::string, std::string> {"his", "hers"})
		std::cout << "Equality!\n";
	//比较大小先比first再比second
	std::pair<int, int> p1{ 10, 9 };
	std::pair<int, int> p2{ 10, 11 };
	std::pair<int, int> p3{ 11, 9 };
	std::cout << std::boolalpha << (p1 < p2) << " " << (p1 > p3) << " " << (p3 > p2) << std::endl;
	//pair 的成员函数 swap() 可以和作为参数传入的另一个 pair 对象交换其成员变量 first 和 second
	std::pair<int, int> p5{ 10, 11 };
	std::pair<int, int> p6{ 11, 9 };
	cout << "before swap" << p5.first << " " << p5.second << endl;
	p5.swap(p6); // p1={ll,9} p2={10/11}
	cout << "after swap" << p5.first << " " << p5.second << endl;
}
//tuple元组
void FuncMap10()
{
	auto my_tuple = std::make_tuple(Name{ "Pete","Piper" }, 42, std::string{ "914 626 7890" });//tuple<Name，int，string>
	//其他可能方式
	std::tuple<std::string, size_t> my_tl;//Default initialization//默认值初始化
	std::tuple<Name, std::string> my_t2{ Name {"Andy", "Capp"},std::string{"Programmer"}};
	std::tuple<Name, std::string> copy_my_t2{ my_t2 }; // Copy constructor
	std::tuple<std::string, std::string> my_t3{ "this", "that" };
	// Implicit conversion
	//使用pair
	auto the_pair = std::make_pair("these", "those");
	std::tuple<std::string, std::string> my_t4{ the_pair }; std::tuple<std::string, std::string> my_t5{ std::pair <std::string, std::string > { "this", "that"} };
	//比较：第一个不同的元素决定结果
	std::cout << std::boolalpha << (my_t4 < my_t5) << std::endl;
	//swap
	my_t4.swap(my_t5);

}
//get<>
void FuncMap11()
{
	auto my_tuple = std::make_tuple(Name{ "Peter","Piper" }, 42, std::string{ "914 626 7890" });
	std::cout << "age = " << std::get<1>(my_tuple) << " tel: " << std::get<2>(my_tuple) << std::endl;
}
//tie<>() 的模板类型参数是从函数参数中推导的
void FuncMap12()
{
	auto my_tuple = std::make_tuple(Name{ "Peter","Piper" }, 42, std::string{ "914 626 7890" });
	Name name{};
	size_t age{};
	std::string phone{};
	std::tie(name, age, phone) = my_tuple;
	//只保存 my_tuple 中 name 和 phone 的值   ignore
	std::tie(name, std::ignore, phone) = my_tuple;
}

int main()
{
	//FuncMap1();
	//FuncMap2();
	//FuncMap3();
	//FuncMap4();
	//FuncMap5();
	//FuncMap6();
	//FuncMap7();
	//FuncMap8();
	//FuncMap9();
	//FuncMap10();
	//FuncMap11();
	FuncMap12();


	//FuncVector1();
	//FuncVector2();
	//FuncVector3();
	//FuncVector4();
	//FuncVector5();
	//FuncVector6();
	//FuncVector7();
	//FuncVector8();
	//FuncVector9();
	//FuncVector10();
	//FuncVector11();
	
	//FuncDeque1();
	//FuncDeque2();

	//FuncList1();
	//FuncList2();
	//FuncList3();
	//FuncList4();
	//FuncList5();
	//FuncList6();

	//FuncForwardList1();
	//FuncForwardList2();
	//FuncForwardList3();
	//FuncForwardList4();


	return 0;
}