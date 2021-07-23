
#include <iostream>
#include <vector>
#include <string>

using namespace std;

void ADD(vector<vector<string>>& months, int currMonth)
{
    int date;
    string actEvent;

    cin >> date >> actEvent;
    if (months[currMonth][date - 1] != "")
        months[currMonth][date - 1] += " ";
    months[currMonth][date - 1] += actEvent;
}

void NEXT(vector<vector<string>>& months, int& currMonth, const vector<int> days_count)
{
    int prevMonth = currMonth++;

    if (currMonth == 13)
        currMonth = 0;
    months[currMonth].assign(days_count[currMonth], "");
    if (days_count[currMonth] >= days_count[prevMonth])
        for (int i = 0; i < days_count[prevMonth]; i++)
            months[currMonth][i] = months[prevMonth][i];
    else
    {
        for (int i = 0; i < days_count[currMonth]; i++)
            months[currMonth][i] = months[prevMonth][i];
        for (int i = days_count[currMonth]; i < days_count[prevMonth]; i++)
        {
            if (months[currMonth][days_count[currMonth] - 1] != "")
                months[currMonth][days_count[currMonth] - 1] += " ";
            months[currMonth][days_count[currMonth] - 1] += months[prevMonth][i];
        }
    }
}

void DUMP(const vector<vector<string>>& months, int currMonth)
{
    int date;
    int number = 0;

    cin >> date;
    date--;
    if (months[currMonth][date] != "")
    {
        for (int i = 0; i < months[currMonth][date].length(); i++)
            if (months[currMonth][date][i] == ' ')
                number++;
        cout << number + 1 << months[currMonth][date] << endl;
    }
    else
        cout << "0" << endl;

}

int main()
{
    int Q;

    cin >> Q;
    int currMonth = 0;
    vector<vector<string>> months(12);
    const vector<int> days_count = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    months[currMonth].assign(days_count[currMonth], "");

    string comm;

    for (int j = 0; j < Q; j++)
    {
        comm = "";
        cin >> comm;
        if (comm == "ADD")
            ADD(months, currMonth);
        else if (comm == "NEXT")
        {
            NEXT(months, currMonth, days_count);
        }
        else if (comm == "DUMP")
        {
            DUMP(months, currMonth);
        }
    }


    return 0;
}
