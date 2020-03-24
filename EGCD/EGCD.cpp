#include "EGCD.hpp"
#include <cstdlib>

void swap(EGCD::DataField& first, EGCD::DataField& second) {
    EGCD::DataField tmp = first;
    first = second;
    second = tmp;
}

EGCD::EGCD(long a, long b)
    : table_{[0] = {a, 0, 1, 0}, [1] = {b, 0, 0, 1}} {

    if (a == 0 || b == 0) {

        a == 0
        ? s = 0, t = 1, d = b
        : s = 1, t = 0, d = a;

        return;

    } else {
        long r = a % b;
        long q = a / b;
        long s = table_[0].s - q * table_[1].s;
        long t = table_[0].t - q * table_[1].t;

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
