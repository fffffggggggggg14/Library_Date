#pragma once
#pragma warning (disable : 4996)

#include <iostream>
#include <ctime>
#include <vector>
#include "clsStr.h"

using namespace std;


class clsData {

    private:
        int _day;
        int _month;
        int _year;

    public:

        clsData(void){
            time_t t = time(0);
            tm *p_t = localtime(&t);

            _year = p_t->tm_year + 1900;
            _month = p_t->tm_mon + 1;
            _day = p_t->tm_mday;
        }

        clsData(int day, int month, int year){
            _day = day;
            _month = month;
            _year = year;
        }
        
        clsData(string s){
            vector <string> v_s = clsStr::static_split(s, "/");
            _day = stoi(v_s[0]);
            _month = stoi(v_s[1]);
            _year = stoi(v_s[2]);
        }

        clsData(int days, int year){
            clsData d = add_days_to_the_date(clsData(1, 1, year), days - 1);
            
            _year = d._year;
            _month = d._month;
            _day = d._day;
        }

        void set_day(int day){
            _day = day;
        }

        int get_day(void){
            return _day;
        }

        void set_month(int month){
            _month = month;
        }

        int get_month(void){
            return _month;
        }

        void set_year(int year){
            _year = year;
        }

        int get_year(void){
            return _year;
        }

        static string print(clsData d){
            return to_string(d._day) + "/" + to_string(d._month) + "/" + to_string(d._year); 
        }

        string print(void){
            return print(*this);
        }


        static bool is_leap_year(int year){
            return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
        }

        bool is_leap_year(void){
            return is_leap_year(this->_year);
        }

        static int number_of_days_in_the_year(int year){
            return is_leap_year(year) ? 366 : 365;
        }
        
        int number_of_days_in_the_year(void){
            return number_of_days_in_the_year(this->_year);
        }

        static int number_of_hours_in_the_year(int year){
            return number_of_days_in_the_year(year) * 24;
        }

        int number_of_hours_in_the_year(void){
            return number_of_hours_in_the_year(this->_year);
        }

        static int number_of_minutes_in_the_year(int year){
            return number_of_hours_in_the_year(year) * 60;
        }

        int number_of_minutes_in_the_year(void){
            return number_of_minutes_in_the_year(this->_year);
        }

        static int number_of_seconds_in_the_year(int year){
            return number_of_minutes_in_the_year(year) * 60;
        }

        int number_of_seconds_in_the_year(void){
            return number_of_seconds_in_the_year(this->_year);
        }

        static int number_of_days_in_the_month(int year, int month){
            return month == 2 ? is_leap_year(year) ? 29 : 28 : month == 4 || month == 6 || month == 9 ||month == 11 ? 30 : 31;
        }

        int number_of_days_in_the_month(void){
            return number_of_days_in_the_month(this->_year, this->_month);
        }
    
        static int number_of_hours_in_the_month(int year, int month){
            return number_of_days_in_the_month(year, month) * 24;
        }

        int number_of_hours_in_the_month(void){
            return number_of_hours_in_the_month(this->_year, this->_month);
        }

        static int number_of_minutes_in_the_month(int year, int month){
            return number_of_hours_in_the_month(year, month) * 60;
        }

        int number_of_minutes_in_the_month(void){
            return number_of_minutes_in_the_month(this->_year, this->_month);
        }

        static int number_of_seconds_in_the_month(int year, int month){
            return number_of_minutes_in_the_month(year, month) * 60;
        }

        int number_of_seconds_in_the_month(void){
            return number_of_seconds_in_the_month(this->_year, this->_month);
        }

        static int order_day_in_the_week(clsData d){
            int a = (14 - d._month) / 12;
            int m = d._month + (12 * a) - 2;
            int y = d._year - a;

            return (d._day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
        }

        int order_day_in_the_week(void){
            return order_day_in_the_week(*this);
        }

        static string name_of_the_month(int month){
            string arr_month[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
            return arr_month[month - 1];
        }

        string name_of_the_month(void){
            return name_of_the_month(this->_month);
        }



        static void print_month_calender(int year, int month){
            cout << "________________________" << name_of_the_month(month).substr(0, 3) << "________________________" << endl;
            cout << "Sun\tMon\tTue\tWed\tThu\tFri\tSat" << endl;

            int count_day = number_of_days_in_the_month(year, month);
            int order_day = order_day_in_the_week(clsData(year, month, 1));

            for(int i = 0; i < order_day; i++){
                cout << "\t";
            }

            for(int i = 1; i <= count_day; i++){
                cout << i << "\t";
                if((i + order_day) % 7 == 0){
                    cout << endl;
                }
            }
            
            cout << endl;
        }

        void print_month_calender(void){
            print_month_calender(this->_year, this->_month);
        }
        

        static void print_year_calender(int year){
            cout << "___________________________________________________" << endl;
            cout << "\t\tCalendar - " << year << endl;
            cout << "___________________________________________________" << endl;
            for(int month = 1; month <= 12; month++){
                print_month_calender(year, month);
                cout << "___________________________________________________" << endl;
            }
        }

        void print_year_calender(void){
            print_year_calender(this->_year);
        }

        static int number_of_days_completed_in_the_year(clsData d){
            int count_day = 0;
            for(int i = 1; i < d._month; i++){
                count_day += number_of_days_in_the_month(d._year, i);
            }

            return count_day + d._day;
        }

        int number_of_days_completed_in_the_year(){
            return number_of_days_completed_in_the_year(*this);
        }

        static int number_of_days_remaining_in_the_year(clsData d){
            return number_of_days_in_the_year(d._year) - number_of_days_completed_in_the_year(d);
        }

        int number_of_days_remaining_in_the_year(void){
            return number_of_days_remaining_in_the_year(*this);
        }

        static clsData add_one_day(clsData d){
            d._day++;
            if(d._day > number_of_days_in_the_month(d._year, d._month)){
                d._day = 1;
                d._month++;
            }
            if(d._month > 12){
                d._month = 1;
                d._year++;
            }

            return d;
        }

        void add_one_day(void){
            clsData d = add_one_day(*this);
            _year = d._year;
            _month = d._month;
            _day = d._day;
        }

        static clsData add_one_week(clsData d){
            for(int i = 0; i < 7; i++){
                d = add_one_day(d);
            }
            return d;
        }

        void add_one_week(void){
            clsData d = add_one_week(*this);
            _year = d._year;
            _month = d._month;
            _day = d._day;
        }

        static clsData add_one_month(clsData d){
            d._month++;
            if(d._month > 12){
                d._month = 1;
                d._year++;
            }

            int count_day = number_of_days_in_the_month(d._year, d._month);
            if(d._day > count_day){
                d._day = count_day;
            }
            
            return d;
        }
        
        void add_one_month(void){
            clsData d = add_one_month(*this);

            _year = d._year;
            _month = d._month;
            _day = d._day;
        }
        
        static clsData add_one_year(clsData d){
            d._year++;

            int count_day = number_of_days_in_the_month(d._year, d._month);
            if(d._day > count_day){
                d._day = count_day;
            }

            return d;
        }
        
        void add_one_year(void){
            clsData d = add_one_year(*this);
            
            _year = d._year;
            _month = d._month;
            _day = d._day;
        }
        

        static clsData decrease_one_day(clsData d){
            d._day--;
            if(d._day < 1){
                d._month--;
                if(d._month < 1){
                    d._month = 12;
                    d._year;
                }
                d._day = number_of_days_in_the_month(d._year, d._month);
            }

            return d;
        }
        
        void decrease_one_day(void){
            clsData d = decrease_one_day(*this);
            
            _year = d._year;
            _month = d._month;
            _day = d._day;
        }

        static clsData decrease_one_week(clsData d){
            for(int i = 0; i < 7; i++){
                d = decrease_one_day(d);
            }

            return d;
        }

        void decrease_one_week(void){
            clsData d = decrease_one_week(*this);

            _year = d._year;
            _month = d._month;
            _day = d._day;
        }

        static clsData decrease_one_month(clsData d){
            d._month--;

            if(d._month < 1){
                d._month = 12;
                d._year--;
            }

            int count_day = number_of_days_in_the_month(d._year, d._month);
            if(d._day > count_day){
                d._day = count_day;
            }
            
            return d;
        }

        void decrease_one_month(void){
            clsData d = decrease_one_month(*this);

            _year = d._year;
            _month = d._month;
            _day = d._day;
        }

        static clsData decrease_one_year(clsData d){
            d._year--;

            int count_day = number_of_days_in_the_month(d._year, d._month);
            if(d._day > count_day){
                d._day = count_day;
            }

            return d;
        }

        void decrease_one_year(void){
            clsData d = decrease_one_year(*this);

            _year = d._year;
            _month = d._month;
            _day = d._day;
        }

        static clsData add_days_to_the_date(clsData d, int days){
            for(int i = 0; i < days; i++){
                d = add_one_day(d);
            }

            return d;
        }
        

        void add_days_to_the_date(int days){
            clsData d = add_days_to_the_date(*this, days);

            _year = d._year;
            _month = d._month;
            _day = d._day;
        }


        static bool is_data1_is_less_than_data2(clsData d1, clsData d2){
            if(d1._year < d2._year){
                return 1;
            }
            else{
                if(d1._year == d2._year){
                    if(d1._month < d2._month){
                        return 1;
                    }
                    else{
                        if(d1._month == d2._month){
                            if(d1._day < d2._day){
                                return 1;
                            }
                            else{
                                return 0;
                            }
                        }
                        else{
                            return 0;
                        }
                    }
                }
                else {
                    return 0;
                }
            }
            
        }

        bool is_data1_is_less_than_data2(clsData d){
            return is_data1_is_less_than_data2(*this, d);
        }

        static bool is_data1_is_equal_than_data2(clsData d1, clsData d2){
            return d1._year == d2._year && d1._month == d2._month && d1._day == d2._day ? 1 : 0;
        }

        bool is_data1_is_equal_than_data2(clsData d){
            return is_data1_is_equal_than_data2(*this, d);
        }

        static bool is_last_day_in_month(clsData d){
            return d._day == number_of_days_in_the_month(d._year, d._month);
        }

        bool is_last_day_in_month(void){
            return is_last_day_in_month(*this);
        }

        static void swap_date(clsData &d1, clsData &d2){
            // int temp = d1._year;
            // d1._year = d2._year;
            // d2._year = temp;

            // temp = d1._month;
            // d1._month = d2._month;
            // d2._month = temp;

            // temp = d1._day;
            // d1._day = d2._day;
            // d2._day = temp;
            
            clsData temp = d1;
            d1 = d2;
            d2 = temp;
        }

        static int difference_in_days_between_two_dates(clsData d1, clsData d2, bool flag1 = false){
            int count_days = 0;
            bool flag2 = false;

            if(is_data1_is_less_than_data2(d2, d1)){
                swap_date(d1, d2);
                flag2 = true;
            }

            while(is_data1_is_less_than_data2(d1, d2)){
                d1 = add_one_day(d1);
                count_days++;
            }

            if(flag1){
                ++count_days;
            }
            if(flag2){
                count_days *= -1;
            }
            
            return count_days;
        }

        int difference_in_days_between_two_dates(clsData d, bool flag = false){
            return difference_in_days_between_two_dates(*this, d, flag);
        }

        static int difference_in_days_from_the_date_until_now(clsData d){
            return difference_in_days_between_two_dates(d, clsData());
        }

        int difference_in_days_from_the_date_until_now(void){
            return difference_in_days_from_the_date_until_now(*this);
        }


        static bool is_end_week(clsData d){
            int order_day = order_day_in_the_week(d);
            return order_day == 6;
        }

        bool is_end_week(void){
            return is_end_week(*this);
        }
        
        static bool is_weekend(clsData d){
            int order_day = order_day_in_the_week(d);
            return order_day == 5 || order_day == 6;
        }

        bool is_weekend(void){
            return is_weekend(*this);
        }

        static bool is_business_day(clsData d){
            return !is_weekend(d);
        }

        bool is_business_day(void){
            return is_business_day(*this);
        }
        
        static int days_until_the_end_of_week(clsData d){
            return 6 - order_day_in_the_week(d);
        }

        int days_until_the_end_of_week(void){
            return days_until_the_end_of_week(*this);
        }

        static int days_until_the_end_of_month(clsData d){
            return (number_of_days_in_the_month(d._year, d._month) - d._day) + 1;
        }

        int days_until_the_end_of_month(void){
            return days_until_the_end_of_month(*this);
        }

        static int days_until_the_end_of_year(clsData d){
            return difference_in_days_between_two_dates(d, clsData(1, 1, d._year + 1));
        }

        int days_until_the_end_of_year(void){
            return days_until_the_end_of_year(*this);
        }

        static clsData date_back_from_vacation(clsData d, int days){
            while(days){
                if(is_business_day(d)){
                    days--;
                }
                d = add_one_day(d);
            }

            return d;
        }

        void date_back_from_vacation(int days){
            clsData d = date_back_from_vacation(*this, days);

            _year = d._year;
            _month = d._month;
            _day = d._day;
        }

        static int compare_dates(clsData d1, clsData d2){
            return is_data1_is_less_than_data2(d1, d2) ? -1 : is_data1_is_equal_than_data2(d1, d2) ? 0 : 1;
        }

        int compare_dates(clsData d){
            return compare_dates(*this, d);
        }

        static bool is_vaild(clsData d){
            if(d._month < 1 || d._month > 12){
                return 0;
            }
            if(d._day < 1 || d._day > number_of_days_in_the_month(d._year, d._month)){
                return 0;
            }
            
            return 1;
        }
        
        bool is_vaild(void){
            return is_vaild(*this);
        }
        
        static string format(clsData d, string f){
            f = clsStr::static_lower(f);
            f = clsStr::static_replace(f, "yyyy", to_string(d._year));
            f = clsStr::static_replace(f, "mm", to_string(d._month));
            f = clsStr::static_replace(f, "dd", to_string(d._day));

            return f;
        }

        string format(string f){
            return format(*this, f);
        }

};

