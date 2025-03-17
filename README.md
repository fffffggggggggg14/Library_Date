# clsDate Library 📅

A robust C++ date manipulation library for handling various date operations with ease.

## Features ✨
- **Date Initialization**: Multiple constructors (current date, string, day count in year).
- **Validations**: Leap year, weekend, business day checks.
- **Calculations**: Days between dates, day of the week, days remaining in month/year.
- **Manipulations**: Add/subtract days, weeks, months, years, decades, centuries.
- **Formats & Conversions**: Convert dates to strings, custom formatting.
- **Calendars**: Print monthly/yearly calendars.
- **Utilities**: Date comparisons, vacation day calculations, system time fetch.

## Installation 📥
1. Include `clsDate.h` in your project.
2. Ensure `fffggggg_clsString.h` is accessible (for string operations).
3. Disable warnings if needed (e.g., `#pragma warning(disable : 4996`).

## Quick Start 🚀
```cpp
#include "clsDate.h"

int main() {
    // Create dates
    clsDate today;                          // Current date
    clsDate customDate(25, 12, 2023);       // 25/12/2023
    clsDate fromString("31/01/2024");       // From string

    // Operations
    today.Add10Days();                      // Add 10 days
    customDate.PrintMonthCalendar();        // Print December 2023 calendar

    // Comparisons
    if (today.IsDateBeforeDate2(customDate)) {
        // Handle logic...
    }

    // Formatting
    string formatted = today.FormatToData("dd-mm-yyyy"); // "25-12-2023"
    
    return 0;
}

## Key Functions 🔑
| Category          | Methods                                      | Description                                  |
|--------------------|----------------------------------------------|----------------------------------------------|
| *Initialization* | clsDate(), clsDate(string), ...          | Construct dates from various inputs          |
| *Validation*     | IsLeapYear(), IsValidDate(), IsWeekEnd() | Check date properties                        |
| *Calculations*   | GetDifferenceInDays(), DaysUntilEndOfMonth() | Compute intervals & remaining days         |
| *Manipulation*   | AddOneMonth(), DecreaseOneDecade(), ...  | Modify dates by units                        |
| *Formatting*     | DateToString(), FormatToData()           | Convert dates to custom string formats       |
| *Calendars*      | PrintYearCalendar(), PrintMonthCalendar() | Display calendars in console                |

## Examples 📚
### Get Days Between Dates
clsDate projectStart(1, 1, 2024);
clsDate projectEnd(30, 6, 2024);
int days = projectStart.GetDifferenceInDays(projectEnd); // 181 days

### Check Business Days
clsDate deadline(15, 2, 2024);
if (deadline.IsBusinessDay()) {
    // Deadline is a workday
}

### Generate Calendar
clsDate::PrintYearCalendar(2024); // Prints 2024 calendar to console

## Contribution 🤝
Contributions are welcome! Please fork the repository and submit pull requests.

## License 📄
This project is open-source. Feel free to use it under the MIT License.

---

Developed with ❤️ by Mohamed Essam | [GitHub](https://github.com/yourusername)
```

This README provides:
- Clear structure with emojis for visual appeal 🎨
- Concise code examples for quick understanding 🧠
- Table summarizing key functions for easy reference 🔍
- Contribution and license sections for openness 🤝
- Direct links to relevant components of the library 🔗

Adjust the GitHub URL and license details as needed before publishing!
