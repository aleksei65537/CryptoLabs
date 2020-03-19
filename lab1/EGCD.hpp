/**
 *  Класс EGCD имеет конструктор, принимающий на вход два числа a, b.
 *  В теле конструктора с помощью алгоритма Кнута находятся коэффициенты
 *  безу и НОД этих чисел. Этими значениями инициализируются члены класса.
 */

#pragma once

class EGCD {
    
     // Вспомогательная структура, представляющая собой таблицу.
     // Для всех подробостей гуглите алгоритм Кнута.
      
    struct DataField {

        friend void swap(DataField&, DataField&);

        long                            r;
        long                            q;
        long                            s;
        long                            t;

        DataField(const DataField&) =   default;

        DataField& operator=(const DataField&) = 
                                        default;
        
        DataField(long r_, long q_, long s_, long t_) 
            : r(r_)
            , q(q_)
            , s(s_)
            , t(t_) { return; }
        
    };

    friend void swap(DataField&, DataField&);

    DataField                           table_[2];
    
    public:

        long                            s;
        long                            t;
        long                            d;

        //  Тот самый конструктор. Определение вынесено в отдельный файл.

        EGCD(long a, long b);
};
