#OOPVector


## std::vector ir Vector spartos palyginimas

### push_back

Testuota iman 10 rezultatų vidurkį

| Optimizacijos flagas| Konteineris      |  100000 |  1000000 |  10000000 |  100000000 |
| ------------| ------------- |--------| --------|--------|--------|
| | std::vector      | 0.0029265 | 0.0390852 | 0.2297559 | 2.338244 |
| | Vector   | 0.0007439  |   0.0249711 | 0.0913853 | 0.7739419 |
| -O1 | std::vector     | 0.0029265 | 0.0390852 | 0.2297559 | 2.338244 |
| -O1 | Vector   | 0.0007439  |   0.0249711 | 0.0913853 | 0.7739419 |
| -O2 | std::vector     | 0.001856083 |0.0162709 |0.087655| 0.7186834 |
| -O2 | Vector   | 0  |   0.0034022 | 0.0231931  | 0.2186113 |
| -O3 | std::vector     |0.0020045 | 0.0086778  | 0.0929738 |  0.7105872|
| -O3 | Vector   | 0  |   0.0021608 | 0.0220126 | 0.1728694 |


### Studento programa

| Konteineris      |  100 |  1000 |  10000 |  100000 |
| ------------- |--------| --------|--------|--------|
| std::vector      | 0.0029265 | 0.0390852 | 0.2297559 | 2.338244 |
| Vector   | 0.0012008 | 0.026957 | 0.213356 | 2.749406 |

### Cool dalykai
```cpp
template<class T>
    T* Vector<T>::insert(const_iterator pos, InputIt first, InputIt last) {

        unsigned int count = last - first;

        if (cpt < sz + count) cpt *= 2;

        auto newelementai = new T[cpt];

        size_t k = 0;

        for (auto i = begin(); i != pos; ++i){
            newelementai[k] = (*i);
            k++;
        }

        for (auto  j = pos; j != pos+count; ++j) {
            newelementai[k]=*first;
            first++;
            k++;
        }
        for (auto i = pos; i != end(); ++i){
            newelementai[k]=(*i);
            k++;
        }
        sz += count;
        delete [] elem;
        elem = newelementai;

    }
```
