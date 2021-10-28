#include <iostream>
#include <iterator>
#include <algorithm>
using namespace std;

template<typename T> class MvectorIterator : public iterator<random_access_iterator_tag, T> {
	T* p = nullptr;
public:
	MvectorIterator() = default;
	MvectorIterator(T* x) : p(x) {}
	MvectorIterator(const MvectorIterator& mit) = default;        // : p(mit.p) {}

	MvectorIterator& operator++() { ++p; return *this; }
	MvectorIterator operator++(int) { T* tmp = p; ++p; return tmp; }
	MvectorIterator& operator--() { --p; return *this; }
	MvectorIterator operator--(int) { T* tmp = p; --p; return tmp; }
	MvectorIterator operator-=(ptrdiff_t n) const { T* tmp = p - n; return tmp; }
	MvectorIterator operator+=(ptrdiff_t n) const { T* tmp = p + n; return tmp; }

	friend ptrdiff_t operator- (const MvectorIterator& l, const MvectorIterator& r) {return l.p - r.p;}
	friend MvectorIterator operator-(MvectorIterator const& l, ptrdiff_t n) {return MvectorIterator(l.p - n);}
	friend MvectorIterator operator+(MvectorIterator const& l, ptrdiff_t n) {return MvectorIterator(l.p + n);}
	friend MvectorIterator operator+(ptrdiff_t n, MvectorIterator const& r) {return MvectorIterator(n + r.p);}
	friend T& operator*(const MvectorIterator& r) { return *(r.p); }

	bool operator>(const MvectorIterator& r) const { return p > r.p; }
	bool operator<(const MvectorIterator& r) const { return p < r.p; }

	bool operator>=(const MvectorIterator& r) const { return p >= r.p; }
	bool operator<=(const MvectorIterator& r) const { return p <= r.p; }

	bool operator!=(const MvectorIterator& r) const { return p != r.p; }
	T& operator*() { return *p; }
	T& operator[](ptrdiff_t n) const { T* tmp = p + n; return *tmp; }



	bool operator== (const MvectorIterator& r) { return p == r.p; }
	bool operator!= (const MvectorIterator& r) { return p != r.p; }
};

template<typename T> class Mvector {
	T* p = nullptr;						 // Адрес памяти, выделенной под массив
	unsigned sz = 0;					 // и его размерность (количество элементов)
public:
	// Описание типа "итератор" внутри пространства имён класса - позволяет
	using iterator = MvectorIterator<T>; // использовать общепринятую форму записи итератора class_name::iterator,
										 // избежав указания на конкретную форму его релизации
	Mvector() = default;
	Mvector(unsigned n) : sz(n), p(new T[n]{ 0 }) {}		// Конструкторы по размерности и по списку инициализации
	Mvector(const initializer_list<T>& a) : Mvector(a.size()) { auto i = 0u; for (const auto& x : a) p[i++] = x; }

	Mvector(const Mvector&) = delete;					// Конструктор и оператор копирования запрещены
	Mvector& operator=(const Mvector&) = delete;

	~Mvector() { delete[] p; }							// Деструктор (необходим: объекты используют память кучи)

	friend std::istream& operator>>(std::istream& in, Mvector& b) {		// Доопределим операторы ввода/вывода
		for (auto& x : b) in >> x;
		return in;
	}
	friend std::ostream& operator<<(std::ostream& out, const Mvector<T>& b) {
		out << "(";
		for (const auto x : b) out << x << ' ';
		out << "\b)";
		return out;
	}
	Mvector::iterator begin() const {Mvector::iterator mit(p);  return mit; }	// Возвращает объект MvectorIterator<T> - итератор на начало
	Mvector::iterator end() const {Mvector::iterator mit(p + sz);  return mit; }	// и на конец данных
};

int main() {
	Mvector<int> a{ 1, 10, 2, 9 ,3, 8, 4, 7, 5, 6, 2, 2, 2 };				// Определение объекта
	for_each(a.begin(), a.end(), [](int i) { if (i % 2) cout << i << ' '; });	// Вывод нечётных элементов
	cout << endl;
	sort(a.begin(), a.end());											// Сортировка
	cout << a << endl;													//Используем запись типа итератора в таповой для STL форме
	pair<Mvector<int>::iterator, Mvector<int>::iterator> bounds;			// Границы участка равных значений
	bounds = equal_range(a.begin(), a.end(), 2);							// Поиск участка [) элементов равных 2
	cout << " bounds at positions " << distance(a.begin(), bounds.first);	// Вывод индексов 
	cout << " and " << (bounds.second - a.begin()) << endl;
}
