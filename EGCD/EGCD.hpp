#pragma once

class EGCD {
    struct DataField {

        friend void swap(DataField&, DataField&);

        long r;
        long q;
        long s;
        long t;

        DataField(const DataField&) =   default;

        DataField& operator=(const DataField&) = default;

        DataField(long r_, long q_, long s_, long t_)
            : r(r_)
            , q(q_)
            , s(s_)
            , t(t_) { return; }

    };

    friend void swap(DataField&, DataField&);

    DataField                           table_[2];

    public:

        long s;
        long t;
        long d;

        EGCD(long a, long b);
};
