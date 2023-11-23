// задача решена с выдуманными типами данных для дат и времени

class DATE_FORMAT {
    int date;
public:
    bool operator==(DATE_FORMAT& obj) {
        return this->date == obj.date;
    }
    bool operator!=(DATE_FORMAT& obj) {
        return this->date != obj.date;
    }
    bool operator>(DATE_FORMAT& obj) {
        return this->date > obj.date;
    }
    bool operator>=(DATE_FORMAT& obj) {
        return this->date >= obj.date;
    }
    bool operator<(DATE_FORMAT& obj) {
        return this->date < obj.date;
    }
    bool operator<=(DATE_FORMAT& obj) {
        return this->date <= obj.date;
    }
};
class TIME_FORMAT {
    int time;
public:
    bool operator==(TIME_FORMAT& obj) {
        return this->time == obj.time;
    }
    bool operator!=(TIME_FORMAT& obj) {
        return this->time != obj.time;
    }
    bool operator>(TIME_FORMAT& obj) {
        return this->time > obj.time;
    }
    bool operator>=(TIME_FORMAT& obj) {
        return this->time >= obj.time;
    }
    bool operator<(TIME_FORMAT& obj) {
        return this->time < obj.time;
    }
    bool operator<=(TIME_FORMAT& obj) {
        return this->time <= obj.time;
    }
};

bool function(
    DATE_FORMAT dateFrom,
    TIME_FORMAT timeFrom,
    DATE_FORMAT dateTo, 
    TIME_FORMAT timeTo,
    DATE_FORMAT dateTest, 
    TIME_FORMAT timeTest 
    ) 
{
    if(dateFrom <= dateTest && dateTest <= dateTo) {
        if(dateFrom == dateTest && timeTest < timeTo) {
            // первый день и время ДО времени первого
            return false;
        }

        if(dateTo == dateTest && timeTo < timeTest) {
            // последний день и время ПОСЛЕ времени последнего
            return false; 
        }

        if(dateFrom == dateTo && !(timeFrom <= timeTest && timeTest <= timeTo)) {
            // дни начала и конца совпали и время вне заданных пределов
            return false;
        }

        return true;
    }

    return false;
}