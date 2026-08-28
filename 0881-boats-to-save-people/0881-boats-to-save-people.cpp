class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());

        int left = 0;
        int right = people.size() - 1;
        int boats = 0;

        while (left <= right) {

            // Try to put the lightest and heaviest
            // person in the same boat.
            if (people[left] + people[right] <= limit) {
                left++;
            }

            // Heaviest person always gets a boat.
            right--;
            boats++;
        }

        return boats;
    }
};