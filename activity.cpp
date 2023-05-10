#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
struct Activity
{
    int start, end;
};

bool compare_activities(Activity a, Activity b)
{
    return a.end < b.end;
}

int max_activities(vector<Activity> activities, vector<Activity> &selected_activities)
{

    sort(activities.begin(), activities.end(), compare_activities);

    int count = 1;
    int last_activity_end = activities[0].end;
    selected_activities.push_back(activities[0]);

    for (size_t i = 1; i < activities.size(); ++i)
    {
        if (activities[i].start >= last_activity_end)
        {
            count++;
            last_activity_end = activities[i].end;
            selected_activities.push_back(activities[i]);
        }
    }

    return count;
}

int main()
{
    vector<Activity> activities =   {{1,2},{3,4},{0,6},{5,7},{8,9},{5,9}};

  
    vector<Activity> selected_activities;
    int result = max_activities(activities, selected_activities);
    cout << "The maximum number of non-conflicting activities is: " << result << endl;

    cout << "The selected activities are:\n";
    for (const auto &activity : selected_activities)
    {
        cout << "Start time: " << activity.start << ", end time: " << activity.end << endl;
    }

    return 0;
}