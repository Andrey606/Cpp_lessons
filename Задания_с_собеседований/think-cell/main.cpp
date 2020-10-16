#include <assert.h>
#include <map>
#include <limits>
#include <iostream>
#include <random>

using namespace std;
 
template<class K, class V>
class interval_map {
    friend void IntervalMapTest();
    V m_valBegin;
private:
    std::map<K, V> m_map;
 
public:
    // constructor associates whole range of K with val by inserting (K_min, val)
    // into the map
    interval_map(V const& val): m_valBegin(val)
    {
        /*std::cout <<  std::make_pair(std::numeric_limits<K>::lowest(), val).first;
        std::cout <<  std::make_pair(std::numeric_limits<K>::lowest(), val).second;
        std::cout <<   m_map.begin();*/
        m_map.insert(m_map.begin(), std::make_pair(std::numeric_limits<K>::lowest(), val));
    };
 
    // Assign value val to interval [keyBegin, keyEnd). 
    // Overwrite previous values in this interval. 
    // Do not change values outside this interval.
    // Conforming to the C++ Standard Library conventions, the interval 
    // includes keyBegin, but excludes keyEnd.
    // If !( keyBegin < keyEnd ), this designates an empty interval, 
    // and assign must do nothing.
    void assign(K const& keyBegin, K const& keyEnd, const V& val)
    {
        if (!(keyBegin < keyEnd))
            return;

        V valEnd;
        bool x = true;
        auto start = m_map.lower_bound(keyBegin); 
        auto delStart = start;
        if (start != m_map.end() && start->first == keyBegin) 
        {
            valEnd = start->second;
            start->second = val;
            ++delStart;
            if (delStart == m_map.end())
                x = false;
        }
        else 
        {
            auto prev = start;
            --prev;
            valEnd = prev->second;
            if (prev->second != val) 
            {
                auto it = m_map.insert(start, std::make_pair(keyBegin, val)); 
                start = it;
                delStart = ++it;
            }
        }

        auto end = m_map.lower_bound(keyEnd);
        auto delFinish = end;
        if (delFinish == delStart)
            x = false;
        if (end == m_map.end() || end->first != keyEnd) 
        {
            auto prev = end;
            --prev;
            if (prev != start)
                valEnd = prev->second;
            if (valEnd != val) 
            {
                auto it = m_map.insert(end, std::make_pair(keyEnd, valEnd));
                delFinish = it;
                if ((++it) != m_map.end() && it->second == valEnd)
                    m_map.erase(it);
            }
        }
        if (x && delStart != m_map.end() && delFinish != m_map.end() && delStart->first < delFinish->first)
            m_map.erase(delStart, delFinish); 
    }


    // look-up of the value associated with key
    // look-up of the value associated with key
	V const& operator[]( K const& key ) const {
		auto it=m_map.upper_bound(key);
		if(it==m_map.begin()) {
			return m_valBegin;
		} else {
			return (--it)->second;
		}
	}
};
 
void IntervalMapTest()
{
    interval_map<unsigned int, unsigned int> m(99);
    //interval_map<unsigned int, char> m(0);
    int A[10]{ 0 };
    //char A[10]{ 0 };
    //int count = 1 << 20;
    int count = 10;
    while (count--)
    {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(0, 9);
        int begin = dis(gen);
        int end = dis(gen);
        int value = dis(gen);
        
        //std::cout << begin << "-" << end << "=" << value << std::endl;
        //m.assign(begin, end, value);
        for (int i = begin; i < end; ++i)
            A[i] = value;
    }

    m.assign(0, 2, 2);
    m.assign(2, 10, 4);
    m.assign(0, 2, 1);

    

    

 
    for (auto i = 0; i < 11; ++i)
    {
        std::cout << "sd[" << i << "]: " << m[i] << std::endl;
        //std::cout << i << ' ' << A[i] << std::endl;
    }
    std::cout << std::endl;
    for (auto it = m.m_map.begin(); it != m.m_map.end(); ++it)
    {
        std::cout << it->first << ' ' << it->second << std::endl;
    }
}


int main(int argc, char* argv[])
{
    IntervalMapTest();
    return 0;
}