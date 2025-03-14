#pragma once
#pragma warning(disable : 4996)

#include <iostream>
#include "fffggggg_clsString.h"
#include <ctime>
using namespace std;

class clsDate {
private:
int _Day;
int _Month;
int _Year;

public:

clsDate(int Day, int Month, int Year){
_Day = Day;
_Month = Month;
_Year = Year;
}

clsDate(void){
time_t Time = time(0);
tm* T = localtime(&Time);

_Day = T->tm_mday;
_Month = T->tm_mon + 1;
_Year = T->tm_year + 1900;
}


clsDate(string SDate){
vector <string> vString;
vString = clsString::SplitString(SDate, "/");

_Day = stoi(vString[0]);
_Month = stoi(vString[1]);
_Year = stoi(vString[2]);
}


clsDate(int CountDays, int Year){
clsDate D(1, 1, Year);

while(true){
if(CountDays == 0){break;}

D.AddOneDay();

CountDays--;

}

_Day = D._Day;
_Month = D._Month;
_Year = D._Year;
}


//-----------------------------------------------------------------------------------


void PrintDate(void){
cout << to_string(_Day) + "/" + to_string(_Month) + "/" + to_string(_Year) << endl;
}



//-----------------------------------------------------------------------------------


static bool IsLeapYear(int Year){
return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}


bool IsLeapYear(void){
return IsLeapYear(_Year);
}


//-----------------------------------------------------------------------------------


static int NumberOfDaysInYear(int Year){
return IsLeapYear(Year) ? 366 : 365;
}

int NumberOfDaysInYear(void){
return NumberOfDaysInYear(_Year);
}

static int NumberOfHoursInYear(int Year){
return NumberOfDaysInYear(Year) * 24;
}

int NumberOfHoursInYear(void){
return NumberOfHoursInYear(_Year);
}

static int NumberOfMinutesInYear(int Year){
return NumberOfHoursInYear(Year) * 60;
}

int NumberOfMinutesInYear(void){
return NumberOfMinutesInYear(_Year);
}

static int NumberOfSecondsInYear(int Year){
return NumberOfMinutesInYear(Year) * 60;
}

int NumberOfSecondsInYear(void){
return NumberOfSecondsInYear(_Year);
}


//-----------------------------------------------------------------------------------


static int NumberOfDaysInMonth(int Month, int Year){
if(Month == 2){return IsLeapYear(Year) ? 29 : 28;}
return Month == 4 || Month == 6 || Month == 9 || Month == 11 ? 30 : 31;
}

int NumberOfDaysInMonth(void){
return NumberOfDaysInMonth(_Month, _Year);
}

static int NumberOfHoursInMonth(int Month, int Year){
return NumberOfDaysInMonth(Month, Year) * 24;
}

int NumberOfHoursInMonth(void){
return NumberOfHoursInMonth(_Month, _Year);
}

static int NumberOfMinutesInMonth(int Month, int Year){
return NumberOfHoursInMonth(Month, Year) * 60;
}

int NumberOfMinutesInMonth(void){
return NumberOfMinutesInMonth(_Month, _Year);
}

static int NumberOfSecondsInMonth(int Month, int Year){
return NumberOfMinutesInMonth(Month, Year) * 60;
}

int NumberOfSecondsInMonth(void){
return NumberOfSecondsInMonth(_Month, _Year);
}


//---------------------------------------------------------------------------------

static short DayOfWeekOrder(int Day, int Month, int Year){
int a = (14 - Month) / 12;
int y = Year - a;
int m = Month + (12 * a) - 2;
 
return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
}

short DayOfWeekOrder(void){
return DayOfWeekOrder(_Day, _Month, _Year);
}


//-------------------------------------------------------------------------------


static string DayShortName(int DayOrder){
string DayName[] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};

for(int i = 0; i < 7; i++){
if(i == DayOrder){return DayName[i];}
}
}

string DayShortName(void){
int DayOrder = DayOfWeekOrder();
return DayShortName(DayOrder);
}


//----------------------------------------------------------------------------------

static string MonthShortName(int Month){
string MonthName[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
for(int i = 0; i < 12; i++){
if(i == Month - 1){return MonthName[i];}
}
////////////////////////////////////////////
}


string MonthShortName(void){
return MonthShortName(_Month);
}


static void PrintMonthCalendar(int Month, int Year){
cout << "\t________________________" << MonthShortName(Month) << "________________________" << endl;
cout << "\tSun\tMon\tTue\tWed\tThu\tFri\tSat" << endl;

int DayOrder = DayOfWeekOrder(1, Month, Year);
for(int i = 0; i < DayOrder; i++){
cout << "\t";
}

int Inter = DayOrder;
for(int i = 1; i <= NumberOfDaysInMonth(Month, Year); i++){
cout << "\t" << i;

Inter++;

if(Inter == 7){
cout << "\n";
Inter = 0;
}

}

cout << endl;
cout << "\t___________________________________________________" << endl;

}


void PrintMonthCalendar(void){
return PrintMonthCalendar(_Month, _Year);
}



//-----------------------------------------------------------------------------------


static void PrintYearCalendar(int Year){
cout << "\t___________________________________________________" << endl;
cout << "\t\t\tCalendar - " << Year << endl;
cout << "\t___________________________________________________" << endl;

for(int i = 1; i <= 12; i++){
PrintMonthCalendar(i, Year);
}

}


void PrintYearCalendar(void){
return PrintYearCalendar(_Year);
}


//---------------------------------------------------------------------------------------


static clsDate AddOneDay(clsDate &D){
D._Day++;
if(D._Day > NumberOfDaysInMonth(D._Month, D._Year)){
D._Day = 1;
D._Month++;

if(D._Month > 12){
D._Month = 1;
D._Year++;
}

}

return D;
}

clsDate AddOneDay(void){
return AddOneDay(*this);
}


static bool IsDate1EqualDate2(clsDate D1, clsDate D2){
return (D1._Year == D2._Year) && (D1._Month == D2._Month) && (D1._Day == D2._Day);
}

bool IsDate1EqualDate2(clsDate D2){
return IsDate1EqualDate2(*this, D2);
}


//--------------------------------------------------------------------------------------

static clsDate FristYear(clsDate &D1, clsDate D2){
D1._Day = 1;
D1._Month = 1;
D1._Year = D2._Year;
}

clsDate FristYear(clsDate D2){
return FristYear(*this, D2);
}


//---------------------------------------------------------------------------------------


static int NumberOfDaysFromTheBeginingOfTheYear(clsDate D){
clsDate FristYear;
FristYear.FristYear(D);

int CountDays = 0;

while(true){

if(FristYear.IsDate1EqualDate2(D)){break;}

FristYear.AddOneDay();

CountDays++;

}

return CountDays;
}


int NumberOfDaysFromTheBeginingOfTheYear(void){
return NumberOfDaysFromTheBeginingOfTheYear(*this);
}


//--------------------------------------------------------------------------------------

static clsDate GetDateFromDayOrderInYear(int CountDays, int Year){
clsDate D(1, 1, Year);

while(true){
if(CountDays == 0){break;}

D.AddOneDay();

CountDays--;

}

return D;
}


//---------------------------------------------------------------------------------------


static clsDate DateAddDays(clsDate &D, int CountDays){

while(true){
if(CountDays == 0){break;}

D.AddOneDay();

CountDays--;

}

return D;

}

clsDate DateAddDays(int CountDays){
return DateAddDays(*this, CountDays);
}


//----------------------------------------------------------------------------------------


static bool IsDateBeforeDate2(clsDate D1, clsDate D2){
return (D1._Year < D2._Year) ? 1 : (D1._Year == D2._Year) ?
(D1._Month < D2._Month) ? 1 : (D1._Month == D2._Month) ? (D1._Day < D2._Day) ? 1 : 0 : 0 : 0; 

}


bool IsDateBeforeDate2(clsDate D2){
return IsDateBeforeDate2(*this, D2);
}


//-----------------------------------------------------------------------------------------


static bool IsLastMonthInYear(clsDate D){
return (D._Month == 12);
}

bool IsLastMonthInYear(void){
return IsLastMonthInYear(*this);
}

//-------------------------------------------------------------------------------------------


static bool IsLastDayInMonth(clsDate D){
return (D._Day == D.NumberOfDaysInMonth());
}

bool IsLastDayInMonth(void){
return IsLastDayInMonth(*this);
}

//--------------------------------------------------------------------------------------------

static void SwapDate(clsDate &D1, clsDate &D2){
int TempDay = D1._Day;
int TempMonth = D1._Month;
int TempYear = D1._Year;

D1._Day = D2._Day;
D1._Month = D2._Month;
D1._Year = D2._Year;

D2._Day = TempDay;
D2._Month = TempMonth;
D2._Year = TempYear;
}

void SwapDate(clsDate D2){
return SwapDate(*this, D2);
}

//--------------------------------------------------------------------------------------------


static int GetDifferenceInDays(clsDate D1, clsDate D2, bool Flag = 0){
int CountDays = 0;

int Number = 1;

if(D1.Date1AfterDate2(D2)){
SwapDate(D1, D2);
Number = -1;
}

while(true){

if(D1.IsDate1EqualDate2(D2)){break;}


D1.AddOneDay();

CountDays++;

}


return Flag ? ++CountDays *= Number : CountDays *= Number;

}


int GetDifferenceInDays(clsDate D2, bool Flag = 0){
return GetDifferenceInDays(*this, D2, Flag);
}


//----------------------------------------------------------------------------------------------


static int NumberOfDaysToToday(clsDate D){
clsDate NowDate;

int CountDays = 0;

while(true){

if(D.IsDate1EqualDate2(NowDate)){break;}

D.AddOneDay();

CountDays++;

}

return CountDays;
}


int NumberOfDaysToToday(void){
return NumberOfDaysToToday(*this);
}


//--------------------------------------------------------------------------------------------


static bool Date1AfterDate2(clsDate D1, clsDate D2){
return (D1._Year > D2._Year) ? 1 : (D1._Year == D2._Year) ?
(D1._Month > D2._Month) ? 1 : (D1._Month == D2._Month) ? (D1._Day > D2._Day) ? 1 : 0 : 0 : 0;
}


bool Date1AfterDate2(clsDate D2){
return Date1AfterDate2(*this, D2);
}

//---------------------------------------------------------------------------------------------

static clsDate Add10Days(clsDate &D){
for(int i = 0; i < 10; i++){
D.AddOneDay();
}

return D;
}

clsDate Add10Days(void){
return Add10Days(*this);
}


static clsDate AddOneWeek(clsDate &D){
for(int i = 0; i < 7; i++){
D.AddOneDay();
}

return D;
}

clsDate AddOneWeek(void){
return AddOneWeek(*this); 
}

static clsDate Add10Weeks(clsDate &D){
for(int i = 0; i < 10; i++){
D.AddOneWeek();
}

return D;
}

clsDate Add10Weeks(void){
return Add10Weeks(*this);
}

static clsDate AddOneMonth(clsDate &D){

bool Flag = D.IsLastDayInMonth();

D._Month++;

if(D._Month > 12){
D._Month = 1;
D._Year++;
}

if(Flag){
D._Day = D.NumberOfDaysInMonth();
}

return D;
}

clsDate AddOneMonth(void){
return AddOneMonth(*this);
}

static clsDate Add6Months(clsDate &D){
for(int i = 0; i < 6; i++){
D.AddOneMonth();
}

return D;
}

clsDate Add6Months(void){
return Add6Months(*this);
}

static clsDate AddOneYear(clsDate &D){
D._Year++;

if(D._Month == 2){
D._Day = D.NumberOfDaysInMonth();
}


return D;
}

clsDate AddOneYear(void){
return AddOneYear(*this);
}

static clsDate AddOneDecade(clsDate &D){
D._Year += 10;

if(D._Month == 2){
D._Day = D.NumberOfDaysInMonth();
}


return D;
}

clsDate AddOneDecade(void){
return AddOneDecade(*this);
}


static clsDate AddOneCeuntury(clsDate &D){
D._Year += 100;

if(D._Month == 2){
D._Day = D.NumberOfDaysInMonth();
}


return D;
}

clsDate AddOneCeuntury(void){
return AddOneCeuntury(*this);
}


static clsDate AddOneMillennium(clsDate &D){
D._Year += 1000;

if(D._Month == 2){
D._Day = D.NumberOfDaysInMonth();
}


return D;
}

clsDate AddOneMillennium(void){
return AddOneMillennium(*this);
}


//-----------------------------------------------------------------------------------

static clsDate DecreaseOneDay(clsDate &D){
D._Day--;

if(D._Day < 1){
D._Day = D.NumberOfDaysInMonth();
D._Month--;

if(D._Month < 1){
D._Month = 1;
D._Year--;
}
}

return D;
}

clsDate DecreaseOneDay(void){
return DecreaseOneDay(*this);
}

static clsDate Decrease10Days(clsDate &D){
for(int i = 0; i < 10; i++){
D.DecreaseOneDay();
}

return D;
}

clsDate Decrease10Days(void){
return Decrease10Days(*this);
}


static clsDate DecreaseOneWeek(clsDate &D){
for(int i = 0; i < 7; i++){
D.DecreaseOneDay();
}

return D;
}

clsDate DecreaseOneWeek(void){
return DecreaseOneWeek(*this);
}

static clsDate Decrease10Weeks(clsDate &D){
for(int i = 0; i < 10; i++){
D.DecreaseOneWeek();
}

return D;
}

clsDate Decrease10Weeks(void){
return Decrease10Weeks(*this);
}


static clsDate DecreaseOneMonth(clsDate &D){

bool Flag = D.IsLastDayInMonth();

D._Month--;

if(D._Month < 1){
D._Month = 12;
D._Year--;
}

if(Flag){
D._Day = D.NumberOfDaysInMonth();
}

return D;
}

clsDate DecreaseOneMonth(void){
return DecreaseOneMonth(*this);
}

static clsDate Decrease6Month(clsDate &D){
for(int i = 0; i < 6; i++){
D.DecreaseOneMonth();
}

return D;
}

clsDate Decrease6Month(void){
return Decrease6Month(*this);
}


static clsDate DecreaseOneYear(clsDate &D){
D._Year--;

if(D._Month == 2){
D._Day = D.NumberOfDaysInMonth();
}


return D;
}

clsDate DecreaseOneYear(void){
return DecreaseOneYear(*this);
}


static clsDate DecreaseOneDecade(clsDate &D){
D._Year -= 10;

if(D._Month == 2){
D._Day = D.NumberOfDaysInMonth();
}


return D;
}

clsDate DecreaseOneDecade(void){
return DecreaseOneDecade(*this);
}


static clsDate DecreaseOneCentury(clsDate &D){
D._Year -= 100;
if(D._Month == 2){
D._Day = D.NumberOfDaysInMonth();
}

return D;
}

clsDate DecreaseOneCentury(void){
return DecreaseOneCentury(*this);
}


static clsDate DecreaseOneMillennium(clsDate &D){
D._Year -= 1000;

if(D._Month == 2){
D._Day = D.NumberOfDaysInMonth();
}

return D;
}

clsDate DecreaseOneMillennium(void){
return DecreaseOneMillennium(*this);
}


//-----------------------------------------------------------------------------------------

static bool IsEndOfWeek(clsDate D){
return D.DayOfWeekOrder() == 6;
}

bool IsEndOfWeek(void){
return IsEndOfWeek(*this);
}



static bool IsFirstWeek(clsDate D){
return D.DayOfWeekOrder() == 0;
}

bool IsFirstWeek(void){
return IsFirstWeek(*this);
}




//-----------------------------------------------------------------------------------------


static bool IsWeekEnd(clsDate D){
int OrderDay = D.DayOfWeekOrder();
return OrderDay == 5 || OrderDay == 6;
}


bool IsWeekEnd(void){
return IsWeekEnd(*this);
}

//------------------------------------------------------------------------------------------


static bool IsBusinessDay(clsDate D){
return D.IsWeekEnd() ? 0 : 1;
}

bool IsBusinessDay(void){
return IsBusinessDay(*this);
}


//-----------------------------------------------------------------------------------------


static int DaysUntilTheEndOfWeek(clsDate D){
return 6 - D.DayOfWeekOrder();
}

bool DaysUntilTheEndOfWeek(void){
return DaysUntilTheEndOfWeek(*this);
}

//------------------------------------------------------------------------------------------

static int DaysUntilTheEndOfMonth(clsDate D){
return D.NumberOfDaysInMonth() - D._Day;
}

int DaysUntilTheEndOfMonth(void){
return DaysUntilTheEndOfMonth(*this);
}


//------------------------------------------------------------------------------------------


static int DaysUntilTheEndOfYear(clsDate D){
return D.NumberOfDaysInYear() - D.NumberOfDaysFromTheBeginingOfTheYear();
}

int DaysUntilTheEndOfYear(void){
return DaysUntilTheEndOfYear(*this);
}

static int CalculateVacationDays(clsDate D1, clsDate D2){
int CountDays = 0;

while(true){

if(D1.IsDate1EqualDate2(D2)){return CountDays;}

D1.AddOneDay();

if(D1.IsBusinessDay()){CountDays++;}

}

}

int CalculateVacationDays(clsDate D2){
return CalculateVacationDays(*this, D2);
}


static clsDate CalculateVacationReturnDate(clsDate &D, int CountDays){
while(true){

D.AddOneDay();

if(CountDays == 0){return D;}

if(D.IsBusinessDay()){CountDays--;}

}

}

clsDate CalculateVacationReturnDate(int CountDays){
return CalculateVacationReturnDate(*this, CountDays);
}

//----------------------------------------------------------------------------------------------

static bool IsValidDate(clsDate D){
return D._Day <= D.NumberOfDaysInMonth() && D._Month <= 12;
}

bool IsValidDate(void){
return IsValidDate(*this);
}


//-----------------------------------------------------------------------------------------------


static string DateToString(clsDate D){
return to_string(D._Day) + "/" + to_string(D._Month) + "/" + to_string(D._Year);
}

string DateToString(void){
return DateToString(*this);
}

//------------------------------------------------------------------------------------------------

static string FormatToData(clsDate D, string S){
S = clsString::SwitchCharString(S, "dd", to_string(D._Day));
S = clsString::SwitchCharString(S, "mm", to_string(D._Month));
S = clsString::SwitchCharString(S, "yyyy", to_string(D._Year));

return S;
}

string FormatToData(string S){
return FormatToData(*this, S);
}


//---------------------------------------------------------------------------------------------------


static bool IsData1AfterData2(clsDate D1, clsDate D2){
return (D1._Year > D2._Year) ? 1 : (D1._Year == D2._Year) ?
(D1._Month > D2._Month) ? 1 : (D1._Month == D2._Month) ? (D1._Day > D2._Day) ? 1 : 0 : 0 : 0; 

}


bool IsData1AfterData2(clsDate D2){
return IsData1AfterData2(*this, D2);
}

//-----------------------------------------------------------------------------------------------------



static bool IsDataBetween(clsDate Date, clsDate FromDate, clsDate ToDate){
if(IsData1AfterData2(FromDate, ToDate)){SwapDate(FromDate, ToDate);}

return (IsDate1EqualDate2(Date, FromDate) || IsDate1EqualDate2(Date, ToDate)) || 
(IsDateBeforeDate2(FromDate, Date) && IsData1AfterData2(ToDate, Date));

}


bool IsDataBetween(clsDate FromDate, clsDate ToDate){
return IsDataBetween(*this, FromDate, ToDate);

}


static string TimeNow(void){
time_t Time = time(0);
tm* t = localtime(&Time);

short Hours = t->tm_hour;
short Minutes = t->tm_min;
short Seconds = t->tm_sec;

return clsDate::DateToString(clsDate()) + " - " + to_string(Hours) + ":" + to_string(Minutes) + ":" + to_string(Seconds);
}

static string TimeNow12(void){
time_t Time = time(0);
tm* t = localtime(&Time);

short Hours = t->tm_hour;
short Minutes = t->tm_min;
short Seconds = t->tm_sec;

short Hour = (Hours % 12 == 12) ? 12 : Hours % 12;
string Period = (Hours <= 12) ? "AM" : "PM";

return clsDate::DateToString(clsDate()) + " - " + to_string(Hour) + ":" + to_string(Minutes) + ":" + to_string(Seconds) + " " + Period;
}

};



// Mohamed Essam
// fffggggg