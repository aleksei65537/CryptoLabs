#pragma once

namespace ds {
    template <typename T>
    class EGCD {
        private:
    
            struct DataField {
                T r, q, s, t;
                DataField(const DataField&) =   default;
                DataField& operator=(const DataField&) = default;
                DataField(T r_, T q_, T s_, T t_) 
                    : r(r_), q(q_), s(s_), t(t_) { }
            };
    
            void swap(DataField&, DataField&);
            DataField table_[2];
    
        public:
            T s, t, d;
            EGCD(T a, T b);
    };
    
    template <typename T>
    void EGCD<T>::swap(DataField& first, DataField& second) {
        EGCD::DataField tmp = first;
        first = second;
        second = tmp;
    }
    
    template <typename T>
    EGCD<T>::EGCD(T a, T b) : table_{{a, 0, 1, 0}, {b, 0, 0, 1}} {
        if (a == 0 || b == 0) {
            a == 0 ? s = 0, t = 1, d = b : s = 1, t = 0, d = a;
            return;
        } 
    
        else {
            T r = a % b;
            T q = a / b;
            T s = table_[0].s - q * table_[1].s;
            T t = table_[0].t - q * table_[1].t;
    
            while (r != 0) {
                swap(table_[0], table_[1]);
                table_[1] = {r, q, s, t};
    
                r = table_[0].r % table_[1].r;
                q = table_[0].r / table_[1].r;
                s = table_[0].s - q * table_[1].s;
                t = table_[0].t - q * table_[1].t;
            }
    
            this->d = table_[1].r;
            this->s = table_[1].s;
            this->t = table_[1].t;
        }
    }
}
